#include "Floor.h"



Floor::Floor()
{
	std::cout << "Floor"<<std::endl;
	exposure = 0;
}


Floor::~Floor()
{
	
}


bool Floor::Initialise(float x, float y, float z, int W, int H)
{
	InitialiseMaterial();

	Texture::Instance()->LoadFile("Media/Textures/ground.png", "TILES",true);

	sprt.Fill(x, y, z, W, H, m_vertices,m_colors, m_UVs, m_indices, m_normals, true);

	LinkToShader();

	FillBuffers(m_vertices,m_colors, m_UVs, m_indices, m_normals);

	if (m_vertices.empty() || m_colors.empty() || m_UVs.empty() || m_normals.empty() || m_indices.empty()||!LinkToShader())
	{
		return false;
	}
	_w = W;

	return true;
}

void Floor::Draw(std::string TextureID)
{



		
	glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_model[0][0]);
	glUniform1fv(exposureFlagUniformID, 1, &exposure);

	glUniform1i(lightFlagUniformID, true);

	glUniform3fv(materialAmbientUniformID, 1, &m_ambient.r);
	glUniform3fv(materialDiffuseUniformID, 1, &m_diffuse.r);
	glUniform3fv(materialSpecularUniformID, 1, &m_specular.r);
	glUniform1f(materialShininessUniformID, shininess);

	glBindTexture(GL_TEXTURE_2D, Texture::Instance()->GetID(TextureID));
	glUniform1i(textureFlagUniformID, true);


	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, m_vertices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);


	glBindTexture(GL_TEXTURE_2D, 0);
		

	


	/*for (int c = 0; c < 2; c++)
	{
		for (int r = 0; r < 1; r++)
		{

			Reset();
			Translate(glm::vec3( -_w/2 + ((_w/2 * (c+1))+2.5), -15, -_w/2 +  (_w/2 * (r+1)+2.5)));

			Rotate(1, 0, 0, 90);
		
			glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_model[0][0]);
			glUniform1fv(exposureFlagUniformID, 1, &exposure);

			glUniform1i(lightFlagUniformID, true);

			glUniform3fv(materialAmbientUniformID, 1, &m_ambient.r);
			glUniform3fv(materialDiffuseUniformID, 1, &m_diffuse.r);
			glUniform3fv(materialSpecularUniformID, 1, &m_specular.r);
			glUniform1f(materialShininessUniformID, shininess);

			glBindTexture(GL_TEXTURE_2D, Texture::Instance()->GetID(TextureID));
			glUniform1i(textureFlagUniformID, true);


			glBindVertexArray(m_VAO);
			glDrawElements(GL_TRIANGLES, m_vertices.size(), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);


			glBindTexture(GL_TEXTURE_2D, 0);
		}

	}*/
}

void Floor::InitialiseMaterial()
{
	m_ambient = glm::vec3(0.025,0.025,1.0);

	m_diffuse = glm::vec3(0.00,0.00,1.0);

	m_specular = glm::vec3(0.0,0.0,1.0);
	
	shininess = 0.005;

}


void Floor::Update(double dt)

{
	Reset();
	Translate(glm::vec3( 0.0, -25,0.0));

	Rotate(1, 0, 0, 90);
}


