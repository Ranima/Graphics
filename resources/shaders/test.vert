// Graphics\resources\shaders\test.vert
#version 450
layout(location = 0) in vec4 position;
layout(location = 2) in vec2 texCoord;

out vec2 vUV;

void main ()
{
	gl_Position = position;
	vUV = texCoord;
}