
#include "glglew.h"
#include "Graphics\Draw.h"
#include "Graphics\RenderObjects.h"

void s0_draw(const Framebuffer &f,
	const Shader &s,
	const Geometry &g)
{
	glBindFramebuffer(GL_FRAMEBUFFER, f.handle);
	glUseProgram(s.handle);
	glBindVertexArray(g.handle);

	glViewport(0, 0, f.width, f.height);

	glDrawElements(GL_TRIANGLES, g.size, GL_UNSIGNED_INT, 0);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glUseProgram(0);
	glBindVertexArray(0);
}

void clearFramebuffer(const Framebuffer &f)
{
	glBindFramebuffer(GL_FRAMEBUFFER, f.handle);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void setUniform(const Shader &s, int location, float value)
{
	glProgramUniform1f(s.handle, location, value);
}

void setUniform(const Shader &s, int location, int value)
{
	glProgramUniform1i(s.handle, location, value);
};

void setUniform(const Shader &s, int location, double value)
{
	glProgramUniform1d(s.handle, location, value);
}