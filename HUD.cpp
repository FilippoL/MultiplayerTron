#include "HUD.h"

HUD::HUD()
{
	std::cout << "HUD"<<std::endl;
}



void HUD::InitialiseMaterial()
{
	m_ambient = glm::vec3(100.0,100.0,100.0);

	m_diffuse = glm::vec3(1.0,1.0,100.0);

	m_specular = glm::vec3(1.0,1.0,100.0);
	
	shininess = 1000;
}

void HUD::Update(double dt)
{

}

bool HUD::Initialise(float x, float y, float z, int W, int H)
{

	sprt.Fill(x, y, z, W, H, m_vertices,m_colors, m_UVs, m_indices);

	LinkToShader();

	FillBuffers(m_vertices,m_colors, m_UVs, m_indices);

	if (m_vertices.empty() || m_colors.empty() || m_UVs.empty() || m_indices.empty()||!LinkToShader())
	{
		return false;
	}
}

void HUD::Draw(std::string TextureID)
{
	glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_model[0][0]);


	glUniform1i(lightFlagUniformID, false);

	glUniform1i(textureFlagUniformID, true);

	glUniform1i(FBOFlagUniformID, false);


	glBindTexture(GL_TEXTURE_2D, Texture::Instance()->GetID(TextureID));

	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, m_vertices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	
	glBindTexture(GL_TEXTURE_2D, 0);
}

HUD::~HUD()
{

}
