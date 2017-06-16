#include "Grid.h"



Grid::Grid()
{
	
	std::cout << "Grid"<<std::endl;

}

bool Grid::Initialise(int size)
{
	for (int i = 0; i < size; i++)
	{
		/**********************  X  **************************/
		//Negative first vertex
		m_vertices.push_back((GLfloat)(-size + i));
		m_vertices.push_back(0.0f);
		m_vertices.push_back((GLfloat)size);
		//Negative second vertex
		m_vertices.push_back((GLfloat)(-size + i));
		m_vertices.push_back(0.0f);
		m_vertices.push_back((GLfloat)-size);


		//Positive first vertex
		m_vertices.push_back((GLfloat)(size - i));
		m_vertices.push_back(0.0f);
		m_vertices.push_back((GLfloat)-size);
		//Positive second vertex
		m_vertices.push_back((GLfloat)(size - i));
		m_vertices.push_back(0.0f);
		m_vertices.push_back((GLfloat)size);



		//Negative first vertex
		m_vertices.push_back((GLfloat)size);
		m_vertices.push_back(0.0f);
		m_vertices.push_back((GLfloat)(-size + i));
		//Negative second vertex
		m_vertices.push_back((GLfloat)-size);
		m_vertices.push_back(0.0f);
		m_vertices.push_back((GLfloat)(-size + i));


		//Positive first vertex
		m_vertices.push_back((GLfloat)-size);
		m_vertices.push_back(0.0f);
		m_vertices.push_back((GLfloat)(size - i));

		m_vertices.push_back((GLfloat)size);
		m_vertices.push_back(0.0f);
		m_vertices.push_back((GLfloat)(size - i));


		/**************************** Y **************************************/
		//Negative first vertex
		m_vertices.push_back((GLfloat)(-size + i));
		m_vertices.push_back((GLfloat)size);
		m_vertices.push_back(0.0f);

		//Negative second vertex
		m_vertices.push_back((GLfloat)(-size + i));
		m_vertices.push_back((GLfloat)-size);
		m_vertices.push_back(0.0f);



		//Positive first vertex
		m_vertices.push_back((GLfloat)(size - i));
		m_vertices.push_back((GLfloat)-size);
		m_vertices.push_back(0.0f);

		//Positive second vertex
		m_vertices.push_back((GLfloat)(size - i));
		m_vertices.push_back((GLfloat)size);
		m_vertices.push_back(0.0f);




		//Negative first vertex
		m_vertices.push_back((GLfloat)size);
		m_vertices.push_back((GLfloat)(-size + i));
		m_vertices.push_back(0.0f);

		//Negative second vertex
		m_vertices.push_back((GLfloat)-size);
		m_vertices.push_back((GLfloat)(-size + i));
		m_vertices.push_back(0.0f);



		//Positive first vertex
		m_vertices.push_back((GLfloat)-size);
		m_vertices.push_back((GLfloat)(size - i));
		m_vertices.push_back(0.0f);


		m_vertices.push_back((GLfloat)size);
		m_vertices.push_back((GLfloat)(size - i));
		m_vertices.push_back(0.0f);


		/*******************************************************************/
		//color for both axes
	
		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);

		m_colors.push_back(0.75f); m_colors.push_back(0.75f); m_colors.push_back(0.75f);
		
		
	}
	LinkToShader();


	InitialiseMaterial();
	FillBuffers(m_vertices, m_colors);
	return true;
}


void Grid::Draw()
{
	glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_model[0][0]);
	
	glUniform1i(lightFlagUniformID, false);
	
	glUniform1i(textureFlagUniformID, false);
	
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_LINES, 0, m_vertices.size());
	glBindVertexArray(0);
	
}


Grid::~Grid()
{
	
}


