#include "Wake.h"
#include "MeshLoader.h"
#include "TextureManager.h"
#include <gtx\compatibility.hpp>



Wake::Wake()
{
	std::cout << "Wake"<<std::endl;
	m_positions.resize(1);
	rotation.resize(1);
}

bool Wake::Initialise()
{
	if (!Texture::Instance()->LoadFile( "Media/Textures/cube2.jpg", "WAKE")) { return false; }
	
	if (!LoadModel("Media/Scia/_Shia.obj")) { return false; }

	if (!LinkToShader()){return false;	}

	InitialiseMesh(m_vertices,m_colors, m_UVs, m_indices, m_normals);
	
	FillBuffers(m_vertices,m_colors, m_UVs, m_indices, m_normals);

	InitialiseMaterial();

	return true;
}

void Wake::InitialiseMaterial()
{
	m_ambient = glm::vec3(10.0,0,0.0);

	m_diffuse = glm::vec3(1,0.25,0.5);

	m_specular = glm::vec3(1,0.25,0.5);
	
	shininess = 100;

}

void Wake::Update(glm::vec3 posIn, glm::vec3 rotatio)
{
	posIn = posIn + glm::vec3(0.0,0.0,0.0) ;

	
	if (glm::distance(posIn, m_positions.back()) > 1 && !m_positions.empty())
	{
		rotation.push_back(rotatio);
		m_positions.push_back(posIn);
	}
	
	exposure += glm::distance(posIn.z, m_positions[0].z);

	


	for (int i = 0; i < m_positions.size(); i++)
	{

		Reset();


		Translate(m_positions[i]);


		Rotate(0, 1, 0, glm::degrees(rotation[i].y));


		Scale(1, 1,1);

		Draw();

	}

	


	if (m_positions.size() > 30)
	{
		m_positions.pop_front();
		rotation.pop_front();
	}

}

bool Wake::CollisionHappening(glm:: vec3 pos)
{

	for (int i = 0; i < m_positions.size(); i++) //FOR ALL THE ELEMENTS IN THE LIST
	{
		if (glm::distance(pos, m_positions[i]) < 5.00)

		{
			return true;
		}
	
	}


	return false;
}


void Wake::Draw()
{
	glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_model[0][0]);
	
	glUniform3fv(materialAmbientUniformID, 1, &m_ambient.r);
	glUniform3fv(materialDiffuseUniformID, 1, &m_diffuse.r);
	glUniform3fv(materialSpecularUniformID, 1, &m_specular.r);
	glUniform1f(materialShininessUniformID, shininess);
	

	glUniform1i(lightFlagUniformID, true);
	glUniform1i(textureFlagUniformID, true);

	glBindTexture(GL_TEXTURE_2D, Texture::Instance()->GetID("WAKE"));
	

	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, m_vertices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);


	glBindTexture(GL_TEXTURE_2D, 0);
}



Wake::~Wake()
{
	m_positions.clear();
	rotation.clear();
}
