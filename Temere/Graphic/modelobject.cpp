#include "modelobject.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "..\Utility\helper.h"
#include <GLM\glm.hpp>
using namespace Temere::Graphic;

ModelObject::ModelObject() : GraphicObject()
{	
}

ModelObject::ModelObject(const ModelObject& ref) : GraphicObject(ref)
{
}

ModelObject::~ModelObject()
{
}

const ModelObject& ModelObject::operator=(const ModelObject& ref)
{
	if(this != &ref)
	{
		GraphicObject::operator=(ref);
	}
	return *this;
}

void ModelObject::test()
{

}

bool ModelObject::loadObj(const std::string& path)
{
	/*std::vector<glm::vec3> vTempVertices;
	std::vector<glm::vec2> vTempUv;
	std::vector<glm::vec3> vTempNorm;
	std::vector<unsigned int> vertexIndices;
	std::vector<unsigned int> uvIndices;
	std::vector<unsigned int> normalIndices;

	std::ifstream reader(path, std::ios_base::in);
	std::string sLine;
	std::vector<int> intVector;
	std::vector<float> floatVector;
	while(!reader.eof())
	{
		std::getline(reader, sLine);
		if ( sLine[0] == 'v' && sLine[1] == ' ')
		//if (sLine.find("v ", 0) != std::string::npos)
		{
			Temere::Utility::Helper::getInstance()->parseValues(sLine, floatVector);
			vTempVertices.push_back(glm::vec3(floatVector.data()));
		}
		else if ( sLine[0] == 'v' && sLine[1] == 't')
		//else if(sLine.find("vt ", 0) != std::string::npos)
		{
			Temere::Utility::Helper::getInstance()->parseValues(sLine, floatVector);
			vTempUv.push_back(glm::vec2(floatVector[0], -floatVector[1]));
		}
		else if ( sLine[0] == 'v' && sLine[1] == 'n')
		//else if(sLine.find("vn ", 0) != std::string::npos)
		{
			Temere::Utility::Helper::getInstance()->parseValues(sLine, floatVector);
			vTempNorm.push_back(glm::vec3(floatVector.data()));
		}
		else if ( sLine[0] == 'f' && sLine[1] == ' ')
		//else if(sLine.find("f ", 0) != std::string::npos)
		{
			Temere::Utility::Helper::getInstance()->parseValues(sLine, intVector);
			vertexIndices.push_back(intVector[0]);
			vertexIndices.push_back(intVector[3]);
			vertexIndices.push_back(intVector[6]);
			uvIndices.push_back(intVector[1]);
			uvIndices.push_back(intVector[4]);
			uvIndices.push_back(intVector[7]);
			normalIndices.push_back(intVector[2]);
			normalIndices.push_back(intVector[5]);
			normalIndices.push_back(intVector[8]);
		}
	}
	reader.close();
	for(unsigned int n = 0; n <= vertexIndices.size() - 3; n += 3)
	{
		mVertices.push_back(vTempVertices[vertexIndices[n] - 1]);
		mVertices.push_back(vTempVertices[vertexIndices[n + 2] - 1]);
		mVertices.push_back(vTempVertices[vertexIndices[n + 1] - 1]);

		mUv.push_back(vTempUv[uvIndices[n] - 1]);
		mUv.push_back(vTempUv[uvIndices[n + 2] - 1]);
		mUv.push_back(vTempUv[uvIndices[n + 1] - 1]);

		mNormals.push_back(vTempNorm[normalIndices[n] - 1]);
		mNormals.push_back(vTempNorm[normalIndices[n + 2] - 1]);
		mNormals.push_back(vTempNorm[normalIndices[n + 1] - 1]);
	}*/

	/*FILE *file;
	fopen_s(&file, path.c_str(), "r");

	if(file == NULL)
	{
		return false;
	}
	int result;
	char line[100];

	while(1)
	{
		result = fscanf_s(file, "%s", line, sizeof(line));

		if(result == EOF)
		{
			break;
		}
		
		if( strcmp(line, "v") == 0)
		{
			Sv11Vector3f tempVertex = Sv11Vector3f(0.0f, 0.0f, 0.0f);
			fscanf(file, "%f %f %f\n", &tempVertex.x(), &tempVertex.y(), &tempVertex.z());
			vTempVertices.push_back(tempVertex);
		}
		else if(strcmp(line, "vt") == 0)
		{
			Sv11Vector2f tempVt;
			fscanf(file, "%f %f\n", &tempVt.x(), &tempVt.y());
			tempVt.y() *= -1.0f;
			vTempUv.push_back(tempVt);
		}
		else if(strcmp(line, "vn") == 0)
		{
			Sv11Vector3f tempNormal;
			fscanf(file, "%f %f %f\n", &tempNormal.x(), &tempNormal.y(), &tempNormal.z());
			vTempNorm.push_back(tempNormal);
		}
		else if( strcmp(line, "f") == 0)
		{
			unsigned int vertexIndex[3];
			unsigned int uvIndex[3];
			unsigned int normalIndex[3];

			result = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], 
																  &vertexIndex[1], &uvIndex[1], &normalIndex[1],
																  &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if(result != 9)
			{
				return false;
			}

			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);

			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);

			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);

		}
		else
		{
			char tempBuffer[1000];
			fgets(tempBuffer, 1000, file);
		}

	}
	fclose(file);
	unsigned int currentVertexIndex;
	unsigned int currentUvIndex;
	unsigned int currentNormalIndex;

	Sv11Vector3f tempVertex;
	Sv11Vector2f tempUv;
	Sv11Vector3f tempNormal;
	
	for(unsigned int n = 0; n <= vertexIndices.size() - 3; n += 3)
	{
		mVertices.push_back(vTempVertices[vertexIndices[n] - 1]);
		mVertices.push_back(vTempVertices[vertexIndices[n + 2] - 1]);
		mVertices.push_back(vTempVertices[vertexIndices[n + 1] - 1]);

		mUv.push_back(vTempUv[uvIndices[n] - 1]);
		mUv.push_back(vTempUv[uvIndices[n + 2] - 1]);
		mUv.push_back(vTempUv[uvIndices[n + 1] - 1]);

		mNormals.push_back(vTempNorm[normalIndices[n] - 1]);
		mNormals.push_back(vTempNorm[normalIndices[n + 2] - 1]);
		mNormals.push_back(vTempNorm[normalIndices[n + 1] - 1]);
	}*/
	
	//init();
	return true;
}