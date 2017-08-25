#pragma once


struct Geometry;
struct Shader;
struct Framebuffer;



void s0_draw(const Framebuffer &f,
	const Shader &s,
	const Geometry &g);

void clearFramebuffer(const Framebuffer &f);

void setUniform(const Shader&s, int location, float value);
void setUniform(const Shader&s, int location, int value);
void setUniform(const Shader&s, int location, double value);

void setUniform(const Shader&s, int location, const Texture &value, unsigned slot)
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, value.handle);

	glProgramUniform1i(s.handle, location, slot);
}