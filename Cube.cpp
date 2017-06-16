#include "Cube.h"



Cube::Cube()
{
	std::cout << "Cube"<<std::endl;
}



void Cube::InitialiseMaterial()
{
	//0.25	0.20725	0.20725	1	0.829	0.829	0.296648	0.296648	0.296648	0.088
	m_ambient = glm::vec3(0.25, 0.20725, 0.20725);

	m_diffuse = glm::vec3(1, 0.829,	0.829);

	m_specular = glm::vec3(0.296648, 0.296648,	0.296648);
	
	shininess = 0.088;

}


bool Cube::Initialise()
{
	Texture::Instance()->LoadFile("Media/Textures/Cube1.jpg", "CUBE1");
	Texture::Instance()->LoadFile("Media/Textures/Cube2.jpg", "CUBE2");



	//----------------------------------------------------------All vertex points for 3D cube
	m_vertices = { 
		-1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, //front face
		1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, //back face
		-1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, //left face
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, -1.0f,
		1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, //right face
		-1.0f, 1.0f, 1.0f, -1.0f, 1.0f, -1.0f,
		1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, //top face
		-1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f }; //bottom face

 //----------------------------------------------------------Data for colours in the cube
	 m_UVs = { 
		0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, //front face
		0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, //back face
		0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, //left face
		0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, //right face
		0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, //top face
		0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, }; //top face

//----------------------------------------------------------Data for textures
	 m_colors = {
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, //front face
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, //back face
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, //left face
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, //right face
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, //top face
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f }; //bottom face


//----------------------------------------------------------Data for the indices
	 m_indices = { 
		0, 1, 3, 3, 1, 2,//front face
		4, 5, 7, 7, 5, 6, //back face
		8, 9, 11, 11, 9, 10, //left face
		12, 13, 15, 15, 13, 14, //right face
		16, 17, 19, 19, 17, 18, //top face
		20, 21, 23, 23, 21, 22 }; //bottom face

	 //all normals buffer values for 2D quad
	m_normals.push_back(0.0f); m_normals.push_back(0.0f); m_normals.push_back(1.0f);//front face
	m_normals.push_back(0.0f); m_normals.push_back(0.0f); m_normals.push_back(1.0f);
	m_normals.push_back(0.0f); m_normals.push_back(0.0f); m_normals.push_back(1.0f);
	m_normals.push_back(0.0f); m_normals.push_back(0.0f); m_normals.push_back(1.0f);
	
	m_normals.push_back(0.0f); m_normals.push_back(0.0f); m_normals.push_back(-1.0f);//back face
	m_normals.push_back(0.0f); m_normals.push_back(0.0f); m_normals.push_back(-1.0f);
	m_normals.push_back(0.0f); m_normals.push_back(0.0f); m_normals.push_back(-1.0f);
	m_normals.push_back(0.0f); m_normals.push_back(0.0f); m_normals.push_back(-1.0f);

	m_normals.push_back(-1.0f); m_normals.push_back(0.0f); m_normals.push_back(0.0f);//left face
	m_normals.push_back(-1.0f); m_normals.push_back(0.0f); m_normals.push_back(0.0f);
	m_normals.push_back(-1.0f); m_normals.push_back(0.0f); m_normals.push_back(0.0f);
	m_normals.push_back(-1.0f); m_normals.push_back(0.0f); m_normals.push_back(0.0f);
	
	m_normals.push_back(1.0f); m_normals.push_back(0.0f); m_normals.push_back(0.0f);//right face
	m_normals.push_back(1.0f); m_normals.push_back(0.0f); m_normals.push_back(0.0f);
	m_normals.push_back(1.0f); m_normals.push_back(0.0f); m_normals.push_back(0.0f);
	m_normals.push_back(1.0f); m_normals.push_back(0.0f); m_normals.push_back(0.0f);

	m_normals.push_back(0.0f); m_normals.push_back(1.0f); m_normals.push_back(0.0f);//top face
	m_normals.push_back(0.0f); m_normals.push_back(1.0f); m_normals.push_back(0.0f);
	m_normals.push_back(0.0f); m_normals.push_back(1.0f); m_normals.push_back(0.0f);
	m_normals.push_back(0.0f); m_normals.push_back(1.0f); m_normals.push_back(0.0f);
	
	m_normals.push_back(0.0f); m_normals.push_back(-1.0f); m_normals.push_back(0.0f);//bottom face
	m_normals.push_back(0.0f); m_normals.push_back(-1.0f); m_normals.push_back(0.0f);
	m_normals.push_back(0.0f); m_normals.push_back(-1.0f); m_normals.push_back(0.0f);
	m_normals.push_back(0.0f); m_normals.push_back(-1.0f); m_normals.push_back(0.0f);


	FillBuffers(m_vertices,m_colors, m_UVs, m_indices, m_normals);

	InitialiseMaterial();

	LinkToShader();
	return true;
}

void Cube::Update(double dt)
{



}

void Cube::Draw()
{
	glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_model[0][0]);
	
	glUniform1i(lightFlagUniformID, true);
	glUniform3fv(materialAmbientUniformID, 1, &m_ambient.r);
	glUniform3fv(materialDiffuseUniformID, 1, &m_diffuse.r);
	glUniform3fv(materialSpecularUniformID, 1, &m_specular.r);
	glUniform1f(materialShininessUniformID, shininess);
	

	glBindTexture(GL_TEXTURE_2D, Texture::Instance()->GetID("CUBE1"));
	glUniform1i(textureFlagUniformID, true);
	

	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, m_vertices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);


	glBindTexture(GL_TEXTURE_2D, 0);
}

Cube::~Cube()
{

}

