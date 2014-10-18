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
uniform vec2 st_offset;
uniform float rowNums;
uniform float colNums;
void main()
{
	// Output position of the vertex, in clip space : MVP * position
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_Position, 1.0);
	UV = vec2 (1.0 - (in_Position + 1.0) * 0.5);
	UV = vec2 (UV.s / rowNums + st_offset.s, UV.t / colNums - st_offset.t);
}
