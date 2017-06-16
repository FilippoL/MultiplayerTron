#include "BoostBar.h"
#define MAX_BOOST 52


BoostBar::BoostBar()
{
	exposure = 0;
}

void BoostBar::InitialiseMaterial()
{
	m_ambient = glm::vec3(100.0,0.0,0.0);

	m_diffuse = glm::vec3(1.0,0.0,0.0);

	m_specular = glm::vec3(1.0,0.0,0.0);
	
	_canboost = true;
	
	shininess = 1;

}

bool &BoostBar::Boosting()
{
	if (_canboost)
	{
		_boost -= 0.15;
	}
	return isboosting;
}

bool BoostBar::CanBoost()
{
	return _canboost;
}

void BoostBar::Update(double dt)
{
	_canboost = false;

	if (_boost < 2)
	{
		_boost = 2;
	}


	if (_boost < MAX_BOOST && !isboosting || isboosting  && _boost <= 2 )
	{
		_boost += 0.025;
		_canboost = false;
	}
	else
	{
		_canboost = true;
	}

	if (_boost >= MAX_BOOST)
	{
		_boost = MAX_BOOST;
	}


	isboosting = false;	
}

bool BoostBar::Initialise(float x, float y, float z, int W, int H)
{
	m_position = glm::vec3(x, y, z);
	_width = W;
	_height = H;


	sprt.SetColor(glm::vec3(1, 0, 0));
	sprt.Fill(m_position.x, m_position.y, m_position.z, W, H, m_vertices, m_colors, m_UVs, m_indices);



	LinkToShader();

	FillBuffers(m_vertices,m_colors, m_UVs, m_indices);

	if (m_vertices.empty() || m_colors.empty() || m_UVs.empty() || m_indices.empty()||!LinkToShader())
	{
		return false;
	}

	return true;
}

void BoostBar::Draw()
{
	for (int i = 0; i < _boost; i++)
	{
		Reset();
		Translate(glm::vec3(_width * (i+1),0.0,-1.0));

		glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_model[0][0]);
		glUniform1fv(exposureFlagUniformID, 1, &exposure);

		glUniform1i(lightFlagUniformID, false);

		glUniform3fv(materialAmbientUniformID, 1, &m_ambient.r);
		glUniform3fv(materialDiffuseUniformID, 1, &m_diffuse.r);
		glUniform3fv(materialSpecularUniformID, 1, &m_specular.r);
		glUniform1f(materialShininessUniformID, shininess);

		glUniform1i(textureFlagUniformID, false);


		glBindVertexArray(m_VAO);
		glDrawElements(GL_TRIANGLES, m_vertices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

	}


}


BoostBar::~BoostBar()
{
}
