#include "Buttons.h"
#include "InputManager.h"


Buttons::Buttons()
{
}

bool Buttons::Initialise(float x, float y, float z, int W, int H, std::string txt, int rows)
{



	_width = W;
	_height = H;
	_x = x;
	_y = y;
	_z = z;


	_sprt.Fill(_x, _y, _z, _width, _height, m_vertices, m_colors, m_UVs, m_indices);

	LinkToShader();

	FillBuffers(m_vertices,m_colors, m_UVs, m_indices);

	if (m_vertices.empty() || m_colors.empty() || m_UVs.empty() || m_indices.empty()||!LinkToShader())
	{
		return false;
	}
	
	_label.Write(_x, _y, _z, _width / txt.size(), _height / txt.size(), txt, rows);
	
	return true;
}


void Buttons::Update(double dt)
{
	_clicked = false;
	int _mouse_x;
	int _mouse_y;

	//_mouse_x = WIDTH - _mouse_x;
	SDL_GetMouseState(&_mouse_x, &_mouse_y);

	_mouse_y = HEIGHT - _mouse_y;


	if (_mouse_x > _x - _width/2 &&
		_mouse_x < _x + _width/2 &&
		_mouse_y > _y - _height/2 &&
		_mouse_y < _y + _height/2)
	{

		_on_it = true;

		if (Input::Instance()->MousePresed() && _on_it)
		{
			_on_it = false;
			_clicked = true;
		}
	}

	else
	{
		_on_it = false;
		_clicked = false;
	}


	

}

bool Buttons::IsClicked()
{
	return _clicked;

}


void Buttons::Draw()
{

	glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_model[0][0]);


	glUniform1i(lightFlagUniformID, false);

	glUniform1i(textureFlagUniformID, true);

	glUniform1i(FBOFlagUniformID, false);


	glBindTexture(GL_TEXTURE_2D, (_on_it) ? Texture::Instance()->GetID(  "BUTTON_CLICKEDSTATE") : Texture::Instance()->GetID(  "BUTTON_NSTATE"));
	
	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, m_vertices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	
	glBindTexture(GL_TEXTURE_2D, 0);

	_label.Draw();

}


Buttons::~Buttons()
{
	_clicked = false;
	
}
