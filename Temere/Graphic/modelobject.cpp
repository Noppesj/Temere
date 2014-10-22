#include "modelobject.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "..\Utility\helper.h"
#include "graphicmanager.h"
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

glm::vec3 ModelObject::splitVec3(char* line)
{
	char * pch;
	char * pch2;
	glm::vec3 tempVertex;
	pch = strtok_s(line, " ", &pch2);
	tempVertex.x = (float)atof(strtok_s(NULL, " ", &pch2));
	tempVertex.y = (float)atof(strtok_s(NULL, " ", &pch2));
	tempVertex.z = (float)atof(strtok_s(NULL, " ", &pch2));
	return tempVertex;
}

glm::vec2 ModelObject::splitVec2(char *line)
{
	char * pch;
	char * pch2;
	glm::vec2 tempVertex;
	pch = strtok_s(line, " ", &pch2);
	tempVertex.x = (float)atof(strtok_s(NULL, " ", &pch2));
	tempVertex.y = (float)atof(strtok_s(NULL, " ", &pch2));
	return tempVertex;
}

bool ModelObject::loadObj(const std::string& path)
{
	mBufferResource = GraphicManager::getInstance()->getBufferResource(path);
	if (mBufferResource == nullptr)
	{
		std::vector<glm::vec3> vTempVertices;
		std::vector<glm::vec2> vTempUv;
		std::vector<glm::vec3> vTempNorm;
		std::vector<unsigned int> vertexIndices;
		std::vector<unsigned int> uvIndices;
		std::vector<unsigned int> normalIndices;

		std::string sLine;
		std::vector<int> intVector;
		std::vector<float> floatVector;

		FILE *file;
		fopen_s(&file, path.c_str(), "r");

		if (file == NULL)
		{
			return false;
		}
		int result;
		char line[125];
		while ((fgets(line, 125, file)) != NULL)
		{

			if (line[0] == 'v' && line[1] == ' ')
			{
				glm::vec3 tempVertex = splitVec3(line);
				vTempVertices.push_back(tempVertex);
			}
			else if (line[0] == 'v' && line[1] == 't' && line[2] == ' ')
			{
				glm::vec2 tempVt = splitVec2(line);
				tempVt.y *= -1.0f;
				vTempUv.push_back(tempVt);
			}
			else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
			{
				glm::vec3 tempNormal = splitVec3(line);;
				vTempNorm.push_back(tempNormal);
			}
			else if (line[0] == 'f' && line[1] == ' ')
			{
				unsigned int vertexIndex[3];
				unsigned int uvIndex[3];
				unsigned int normalIndex[3];

				result = sscanf_s(line, "f %d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0],
					&vertexIndex[1], &uvIndex[1], &normalIndex[1],
					&vertexIndex[2], &uvIndex[2], &normalIndex[2]);
				if (result != 9)
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
		}
		fclose(file);
		
		std::vector<Vertex*> Vertices;

		for (unsigned int n = 0; n <= vertexIndices.size() - 3; n += 3)
		{
			Vertex tempVertex = Vertex(vTempVertices[vertexIndices[n] - 1],
										   vTempUv[uvIndices[n] - 1],
										   vTempNorm[normalIndices[n] - 1]);
			
			Vertices.push_back(&tempVertex);

			Vertex tempVertex2 = Vertex(vTempVertices[vertexIndices[n + 2] - 1],
				vTempUv[uvIndices[n + 2] - 1],
				vTempNorm[normalIndices[n + 2] - 1]);

			Vertices.push_back(&tempVertex2);

			Vertex tempVertex3 = Vertex(vTempVertices[vertexIndices[n + 1] - 1],
				vTempUv[uvIndices[n + 1] - 1],
				vTempNorm[normalIndices[n + 1] - 1]);

			Vertices.push_back(&tempVertex3);
		}
		mBufferResource = GraphicManager::getInstance()->loadBufferResource(Vertices, path);
	}

	return true;
}

void ModelObject::Draw(const glm::mat4 &projMatrix, const glm::mat4 &viewMatrix)
{
	GraphicManager::getInstance()->UseShader(mpShader);
	int projectionMatrixLocation = glGetUniformLocation(mpShader->getShaderId(), "projectionMatrix"); // Get the location of our projection matrix in the shader
	int viewMatrixLocation = glGetUniformLocation(mpShader->getShaderId(), "viewMatrix"); // Get the location of our view matrix in the shader
	int modelMatrixLocation = glGetUniformLocation(mpShader->getShaderId(), "modelMatrix"); // Get the location of our model matrix in the shader
	int TextureID = glGetUniformLocation(mpShader->getShaderId(), "myTextureSampler");

	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projMatrix[0][0]); // Send our projection matrix to the shader
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // Send our view matrix to the shader
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &getModelMatrix()[0][0]); // Send our model matrix to the shader

	GraphicManager::getInstance()->UseTexture(mpTexture);
	glBindVertexArray(mBufferResource->getVertexArrayObject());
	glDrawArrays(GL_TRIANGLES, 0, mBufferResource->getNumIndices() * 3);
	//glDrawElementsBaseVertex(GL_TRIANGLES, mBufferResource->getNumIndices(), GL_UNSIGNED_INT, 0, 0);
	glBindVertexArray(0);
}