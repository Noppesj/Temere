#version 150 core

// Input vertex data, different for all executions of this shader.
in vec3 in_Position;
in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
out vec2 UV;

// Values that stay constant for the whole mesh.
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

void main()
{
	// Output position of the vertex, in clip space : MVP * position
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_Position, 1.0);
	
	// UV of the vertex. No special space for this one.
	UV = vertexUV;
}
