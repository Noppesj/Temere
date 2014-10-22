#include "bufferresource.h"

using namespace Temere::Graphic;

BufferResource::BufferResource()
{
	mNumIndices = 0;
	mFileName = "Unknown";
}

BufferResource::BufferResource(const std::vector<Vertex*> &vertices, const std::vector<GLuint> &indices, const std::string &fileName)
{
	mFileName = fileName;
	init(vertices, indices);
}

BufferResource::BufferResource(const std::vector<Vertex*> &vertices, const std::string &fileName)
{
	mFileName = fileName;
	init(vertices);
}

BufferResource::~BufferResource()
{
	glDeleteBuffers(NUM_BUFFERS, mVertexBufferObject);
	glDeleteVertexArrays(1, &mVertexArrayObject);
}

BufferResource::BufferResource(const BufferResource& ref)
{
	this->mFileName = ref.mFileName;
	this->mVertexArrayObject = ref.mVertexArrayObject;
	*this->mVertexBufferObject = *ref.mVertexBufferObject;
	this->mNumIndices = ref.mNumIndices;
}

const BufferResource& BufferResource::operator=(const BufferResource& ref)
{
	TEMERE_UREF(ref)
	return *this;
}

void BufferResource::init(const std::vector<Vertex*> &vertices, const std::vector<GLuint> &indices)
{
	std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;
    std::vector<glm::vec3> normals;
	mNumIndices = indices.size();

	for(unsigned int i = 0; i < vertices.size(); i++)
	{
		positions.push_back(vertices[i]->GetPos());
		texCoords.push_back(vertices[i]->GetTexCoord());
		normals.push_back(vertices[i]->GetNormal());
	}

	glGenVertexArrays(1, &mVertexArrayObject);
	glBindVertexArray(mVertexArrayObject);

	glGenBuffers(NUM_BUFFERS, mVertexBufferObject);

	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(glm::vec3), &positions[0], GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); 

	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject[TEXCOORD_VB]); // Bind our second Vertex Buffer Object
	glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(glm::vec2), &texCoords[0], GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)1, 2, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mVertexBufferObject[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1); // Enable the second vertex attribute array
	glBindVertexArray(0);
}

void BufferResource::init(const std::vector<Vertex*> &vertices)
{
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	mNumIndices = vertices.size();

	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		positions.push_back(vertices[i]->GetPos());
		texCoords.push_back(vertices[i]->GetTexCoord());
		normals.push_back(vertices[i]->GetNormal());
	}

	glGenVertexArrays(1, &mVertexArrayObject);
	glBindVertexArray(mVertexArrayObject);

	glGenBuffers(2, mVertexBufferObject);

	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(glm::vec3), &positions[0], GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject[TEXCOORD_VB]); // Bind our second Vertex Buffer Object
	glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(glm::vec2), &texCoords[0], GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)1, 2, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1); // Enable the second vertex attribute array
	glBindVertexArray(0);
}