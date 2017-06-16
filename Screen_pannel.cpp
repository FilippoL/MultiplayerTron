#include "Screen_pannel.h"



Screen_pannel::Screen_pannel()
{
	exposure = 50;
}

void Screen_pannel::InitialiseMaterial()
{


}

void Screen_pannel::Update(double dt)
{
}

bool Screen_pannel::Initialise(float x, float y, float z, int W, int H)
{
	sprt.Flip();

	sprt.Fill(x, y, z, W, H, m_vertices,m_colors, m_UVs, m_indices);

	LinkToShader();

	FillBuffers(m_vertices,m_colors, m_UVs, m_indices);

	if (m_vertices.empty() || m_colors.empty() || m_UVs.empty() || m_indices.empty()||!LinkToShader())
	{
		return false;
	}
	return true;
}

void Screen_pannel::Draw(GLuint texture)
{
	glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_model[0][0]);


	glUniform1i(lightFlagUniformID, false);

	glUniform1i(textureFlagUniformID, true);

	glUniform1i(FBOFlagUniformID, true);

	glUniform1fv(exposureFlagUniformID, 1, &exposure);

	glBindTexture(GL_TEXTURE_2D, texture);

	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, m_vertices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


Screen_pannel::~Screen_pannel()
{
}
