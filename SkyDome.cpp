#include "SkyDome.h"



SkyDome::SkyDome()
{
	Translate(glm::vec3(0.0,-250,0.0));

	Scale(20,35,20);
}

void SkyDome::InitialiseMaterial()
{
	m_ambient = glm::vec3(1.0,1.0,1.0);

	m_diffuse = glm::vec3(1.0,1.0,1.0);

	m_specular = glm::vec3(1.0,1.0,1.0);
	
	shininess = 100;
}

bool SkyDome::Initialise(const char * Obj, std::string texture)
{
	InitialiseMaterial();

	if (!Texture::Instance()->LoadFile(texture, "Enviroment_texture",true)) { return false; }

	if (!LoadModel(Obj)) { return false; }

	if (!LinkToShader()) { return false; }

	InitialiseMesh(m_vertices, m_colors, m_UVs, m_indices, m_normals);

	FillBuffers(m_vertices, m_colors, m_UVs, m_indices, m_normals);


	return true;
}


void SkyDome::Spin(float dt)
{

	Rotate(0.0, 1.0, 0.0, 4 * dt);

}

void SkyDome::Draw()
{
	glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_model[0][0]);
	
	glUniform1i(lightFlagUniformID, true);
	glUniform3fv(materialAmbientUniformID, 1, &m_ambient.r);
	glUniform3fv(materialDiffuseUniformID, 1, &m_diffuse.r);
	glUniform3fv(materialSpecularUniformID, 1, &m_specular.r);
	glUniform1f(materialShininessUniformID, shininess);


	glUniform1i(lightFlagUniformID, true);
	glUniform1i(textureFlagUniformID, true);

	glBindTexture(GL_TEXTURE_2D, Texture::Instance()->GetID("Enviroment_texture"));
	

	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, m_vertices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);


	glBindTexture(GL_TEXTURE_2D, 0);

}

SkyDome::~SkyDome()
{
}
