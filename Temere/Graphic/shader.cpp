#include "shader.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

using namespace Temere::Graphic;

Shader::Shader()
{
	mShaderId = 0;
	mInit = false;
	mInUse = false;
}

Shader::Shader(const Shader& ref)
{
	TEMERE_UREF(ref)
}

Shader::~Shader()
{
	glDetachShader(mShaderId, mFragmentShaderId);
	glDetachShader(mShaderId, mVertexShaderId);
    
	glDeleteShader(mFragmentShaderId);
	glDeleteShader(mVertexShaderId);
	glDeleteProgram(mShaderId);
	
	LOG(INFO) << "Shader destructor" << std::endl;
}

const Shader& Shader::operator=(const Shader& ref)
{
	TEMERE_UREF(ref)
	return *this;
}

bool Shader::loadShader(std::string vertexShader_path, std::string fragmentShader_path)
{
	if(mInit)
	{
		return true;
	}
	mVertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	mFragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	
	std::string vertexCode;
	std::ifstream vertexStream(vertexShader_path, std::ios::in);
	std::string tempLine = "";
	if ( !vertexStream.is_open() )
	{
		LOG(ERROR) << "Failed to load VertexShaderCode." << std::endl;
		std::cerr  << "Failed to load VertexShaderCode." << std::endl;
		return false;	
	}
	else
	{
		while(std::getline(vertexStream, tempLine))
		{
			vertexCode += "\n" + tempLine;
		}
		vertexStream.close();
	}
	tempLine.clear();
	
	std::string fragmentCode;
	std::ifstream fragmentStream(fragmentShader_path, std::ios::in);

	if( !fragmentStream.is_open() )
	{
		LOG(ERROR) << "Failed to load FragmentShaderCode." << std::endl;
		std::cerr  << "Failed to load FragmentShaderCode." << std::endl;
		return false;
	}
	else
	{
		while(std::getline(fragmentStream, tempLine))
		{
			fragmentCode += "\n" + tempLine;
		}
		fragmentStream.close();
	}

	GLint result = GL_FALSE;
	int logLength;

	//VertexShader
	LOG(INFO) << "Compiling Shader: " << vertexShader_path << std::endl;
	const char* vertexSourcePtr = vertexCode.c_str();
	glShaderSource(mVertexShaderId, 1, &vertexSourcePtr, NULL);
	glCompileShader(mVertexShaderId);

	glGetShaderiv(mVertexShaderId, GL_COMPILE_STATUS, &result);
	glGetShaderiv(mVertexShaderId, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> vertexShaderErrorMsg(logLength);

	glGetShaderInfoLog(mVertexShaderId, logLength, NULL, &vertexShaderErrorMsg[0]);
	LOG(ERROR) << vertexShaderErrorMsg[0] << std::endl;

	//FragmentShader
	LOG(INFO) << "Compiling Shader: " << fragmentShader_path << std::endl;
	const char* fragmentShaderPtr = fragmentCode.c_str();
	glShaderSource(mFragmentShaderId, 1, &fragmentShaderPtr, NULL);
	glCompileShader(mFragmentShaderId);

	glGetShaderiv(mFragmentShaderId, GL_COMPILE_STATUS, &result);
	glGetShaderiv(mFragmentShaderId, GL_INFO_LOG_LENGTH, &logLength);

	std::vector<char> fragmentShaderErrorMsg(logLength);
	glGetShaderInfoLog(mFragmentShaderId, logLength, NULL, &fragmentShaderErrorMsg[0]);
	LOG(ERROR) << fragmentShaderErrorMsg[0] << std::endl;

	//Link Program
	LOG(INFO) << "Linking program. " << std::endl;
	mShaderId = glCreateProgram();
	glAttachShader(mShaderId, mVertexShaderId);
	glAttachShader(mShaderId, mFragmentShaderId);

	glBindAttribLocation(mShaderId, 0, "in_Position"); // Bind a constant attribute location for positions of vertices
	glBindAttribLocation(mShaderId, 1, "in_Color"); // Bind another constant attribute location, this time for color

	glLinkProgram(mShaderId);

	//Check the program
	glGetProgramiv(mShaderId, GL_LINK_STATUS, &result);
	glGetProgramiv(mShaderId, GL_INFO_LOG_LENGTH, &logLength);
	//std::vector<char> programErrorMsg(std::max(logLength, int(1)));
	std::vector<char> programErrorMsg(logLength);
	glGetProgramInfoLog(mShaderId, logLength, NULL, &programErrorMsg[0]);
	LOG(ERROR) << programErrorMsg[0] << std::endl;

	//glDeleteShader(vertexShaderId);
	//glDeleteShader(fragmentShaderId);
	LOG(INFO) << "Shader compiling done." << std::endl;
	mInit = true;
	return true;
}

 void Shader::bindShader()
 {
	 glUseProgram(mShaderId);
	 mInUse = true;
 }

 void Shader::unbindShader()
 {
	glUseProgram(0);
	mInUse = false;
 }

 void Shader::setSpriteUV(const GLfloat s, const GLfloat t, const GLint uvLocation, const GLfloat rowNums, const GLfloat colNums, const GLint rowLoc, const GLint colLoc)
 {
	 glUseProgram(mShaderId);
	 glUniform1f(rowLoc, rowNums);
	 glUniform1f(colLoc, colNums);
	 glUniform2f(uvLocation, s, t);
 }

 
bool Shader::getInUse()
{
	return mInUse;
}
