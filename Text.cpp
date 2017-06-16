#include "Text.h"



Text::Text()
{
	std::cout << "Some text" << std::endl;

		
	endline = 0;
	distance_y = 0;
	total = 0;
	
	start_line = 0;
}

void Text::Write(GLfloat x,GLfloat y,GLfloat z, GLfloat w,GLfloat h, std::string Number, int rows)
{


	if (rows != 1)
	{
		for (int i = 0; i < rows; i++)
		{

			start_line =  total;

			endline = Number.find(">", start_line+1);

			endline = endline - start_line;

			if (i == 0)
			{
				lines.push_back(Number.substr(start_line, endline));
			}
			else
			{
				lines.push_back(Number.substr(start_line, endline));
			}
			
			total += lines[i].size() + 1;
		}
	}
	else
	{
		lines.push_back(Number);
	}
	
	
	for (int k = 0; k < lines.size(); k++)
	{
		GLfloat TxtSize = w / 2 * (lines[k].size()-1);


		 for (int i = 0; i < lines[k].size(); i++)
		 {

				 distance_y = h / 2 ;
			 
				int charValue = lines[k].at(i);

				glm::vec2 Textcoord = glm::vec2(charValue % 16 , charValue/16 );
				glm::vec2 Position = glm::vec2(Textcoord.x * oneOverDimension.x, Textcoord.y * oneOverDimension.y);

				//all texture coordinates for 2D quad
				m_UVs.push_back(Position.x - (oneOverDimension.x /2)+ (oneOverDimension.x/2));  m_UVs.push_back(Position.y + (oneOverDimension.y/2) + (oneOverDimension.y/2));
				m_UVs.push_back(Position.x - (oneOverDimension.x /2)+ (oneOverDimension.x/2));  m_UVs.push_back(Position.y - (oneOverDimension.y/2) + (oneOverDimension.y/2));
				m_UVs.push_back(Position.x + (oneOverDimension.x /2)+ (oneOverDimension.x/2));  m_UVs.push_back(Position.y - (oneOverDimension.y/2) + (oneOverDimension.y/2)); 
				m_UVs.push_back(Position.x + (oneOverDimension.x /2)+ (oneOverDimension.x/2));  m_UVs.push_back(Position.y + (oneOverDimension.y/2) + (oneOverDimension.y/2));

				//all m_vertices for 2D quad (we will keep the depth at 0)
				m_vertices.push_back(((x+i*w/2) - w / 2)-TxtSize/2);  m_vertices.push_back((y - h / 2 + oneOverDimension.y)- distance_y * k);  m_vertices.push_back(z);
				m_vertices.push_back(((x+i*w/2) - w / 2)-TxtSize/2);  m_vertices.push_back((y + h / 2 + oneOverDimension.y)- distance_y * k);  m_vertices.push_back(z);
				m_vertices.push_back(((x+i*w/2) + w / 2)-TxtSize/2);  m_vertices.push_back((y + h / 2 + oneOverDimension.y)- distance_y * k);  m_vertices.push_back(z);
				m_vertices.push_back(((x+i*w/2) + w / 2)-TxtSize/2);  m_vertices.push_back((y - h / 2 + oneOverDimension.y)- distance_y * k);  m_vertices.push_back(z);

				//all m_colors for 2D quad
				m_colors.push_back(1.0f);  m_colors.push_back(1.0f);  m_colors.push_back(1.0f);
				m_colors.push_back(1.0f);  m_colors.push_back(1.0f);  m_colors.push_back(1.0f);
				m_colors.push_back(1.0f);  m_colors.push_back(1.0f);  m_colors.push_back(1.0f);
				m_colors.push_back(1.0f);  m_colors.push_back(1.0f);  m_colors.push_back(1.0f);

				//all index buffer values for 2D quad
				m_indices.push_back(0 + 4 * i);  m_indices.push_back(1 + 4 * i);  m_indices.push_back(3 + 4 * i);
				m_indices.push_back(1 + 4 * i);  m_indices.push_back(2 + 4 * i);  m_indices.push_back(3 + 4 * i);

		
		 }

	}

	//Texture::Instance()->LoadFile("Media/Font/Calibri.png", "Calibri");

	 //std::string strNumber(Number);

	 //GLfloat TxtSize = w / 2 * (strNumber.size()-1);

	 //for (size_t i = 0; i < strNumber.size(); i++)
	 //{
		// int charValue = strNumber[i];

		// glm::vec2 Textcoord = glm::vec2(charValue % 16 , charValue/16 );
		// glm::vec2 Position = glm::vec2(Textcoord.x * oneOverDimension.x, Textcoord.y * oneOverDimension.y);

		// //all texture coordinates for 2D quad
		// m_UVs.push_back(Position.x);  m_UVs.push_back(Position.y + (oneOverDimension.y/2) + (oneOverDimension.y/2));
		// m_UVs.push_back(Position.x - (oneOverDimension.x /2)+ (oneOverDimension.x/2));  m_UVs.push_back(Position.y - (oneOverDimension.y/2) + (oneOverDimension.y/2));
		// m_UVs.push_back(Position.x + (oneOverDimension.x /2)+ (oneOverDimension.x/2));  m_UVs.push_back(Position.y - (oneOverDimension.y/2) + (oneOverDimension.y/2)); 
		// m_UVs.push_back(Position.x + (oneOverDimension.x /2)+ (oneOverDimension.x/2));  m_UVs.push_back(Position.y + (oneOverDimension.y/2) + (oneOverDimension.y/2));

		//// m_UVs.push_back(Position.x);  m_UVs.push_back(Position.y);
		//// m_UVs.push_back(Position.x + (oneOverDimension.x));  m_UVs.push_back(Position.y);
		//// m_UVs.push_back(Position.x + (oneOverDimension.x));  m_UVs.push_back(Position.y + (oneOverDimension.y)); 
		//// m_UVs.push_back(Position.x );  m_UVs.push_back(Position.y + (oneOverDimension.y));


		// //all m_vertices for 2D quad (we will keep the depth at 0)
		// m_vertices.push_back(((x+i*w/2) - w / 2)-TxtSize/2);  m_vertices.push_back((y - h / 2 + oneOverDimension.y));  m_vertices.push_back(z);
		// m_vertices.push_back(((x+i*w/2) - w / 2)-TxtSize/2);  m_vertices.push_back((y + h / 2 + oneOverDimension.y));  m_vertices.push_back(z);
		// m_vertices.push_back(((x+i*w/2) + w / 2)-TxtSize/2);  m_vertices.push_back((y + h / 2 + oneOverDimension.y));  m_vertices.push_back(z);
		// m_vertices.push_back(((x+i*w/2) + w / 2)-TxtSize/2);  m_vertices.push_back((y - h / 2 + oneOverDimension.y));  m_vertices.push_back(z);

		////all m_colors for 2D quad
		// m_colors.push_back(1.0f);  m_colors.push_back(1.0f);  m_colors.push_back(1.0f);
		// m_colors.push_back(1.0f);  m_colors.push_back(1.0f);  m_colors.push_back(1.0f);
		// m_colors.push_back(1.0f);  m_colors.push_back(1.0f);  m_colors.push_back(1.0f);
		// m_colors.push_back(1.0f);  m_colors.push_back(1.0f);  m_colors.push_back(1.0f);

		////all index buffer values for 2D quad
		// m_indices.push_back(0 + 4 * i);  m_indices.push_back(1 + 4 * i);  m_indices.push_back(3 + 4 * i);
		// m_indices.push_back(1 + 4 * i);  m_indices.push_back(2 + 4 * i);  m_indices.push_back(3 + 4 * i);

	 //}



	LinkToShader();

	FillBuffers(m_vertices, m_colors, m_UVs, m_indices);

}

void Text::Draw()
{
	glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_model[0][0]);


	glUniform1i(lightFlagUniformID, false);

	glUniform1i(FBOFlagUniformID, false);


	glUniform1i(textureFlagUniformID, true);


	glUniform1i(FBOFlagUniformID, false);

	glBindTexture(GL_TEXTURE_2D, Texture::Instance()->GetID("CALIBRI"));

	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, m_vertices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	
	glBindTexture(GL_TEXTURE_2D, 0);

}

void Text::Update(double dt)
{


}

Text::~Text()
{
	lines.clear();
}