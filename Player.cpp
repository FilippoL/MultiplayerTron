#include <iostream>
#include <SDL.h>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <glew.h>
#include <windows.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include "TextureManager.h"
#include "Player.h"


Player::Player(bool isPlayer2)
{
	

	_second_p = isPlayer2;

	m_ambient = glm::vec3(0);

	m_diffuse = glm::vec3(0);

	m_specular = glm::vec3(0);

	curve_angle = glm::radians(0.0f);
	boost = 0;
	Speed = 0;
	boost_speed = 1;

	std::cout << "Object Player" << std::endl;
}

void Player::InitialiseMaterial()
{
	if (!_second_p)
	{
		m_ambient = glm::vec3(1,0.0,0.0);

		m_diffuse = glm::vec3(0.1,0.1,0.750);

		m_specular = glm::vec3(0.750,0.001,0.001);
	
		shininess = 1;
	}

	else
	{
		m_ambient = glm::vec3(0.0,0.0,1);

		m_diffuse = glm::vec3(0.750,0.1,0.1);

		m_specular = glm::vec3(0.001,0.001,0.750);
	
		shininess = 1;
	}

}

bool Player::Initialise(const char * Obj, std::string texture)
{
	if (_second_p)
	{
		position.z = -50;
		curve_angle = glm::radians(90.0f);
	}
	else
	{
		position.z = 50;
		curve_angle = glm::radians(-90.0f);
	}

	if (!Texture::Instance()->LoadFile(texture, (!_second_p) ? "PlayerTexture" : "Player2Texture")) { return false; }
	
	if (!LoadModel(Obj)) { return false; }

	if (!LinkToShader()){return false;	}

	InitialiseMesh(m_vertices,m_colors, m_UVs, m_indices, m_normals);
	
	FillBuffers(m_vertices,m_colors, m_UVs, m_indices, m_normals);

	InitialiseMaterial();


	return true;
}

void Player::Update(double dt)
{
	if (position.z > FIELD_SIZE)
	{
		position.z = FIELD_SIZE;
	}

	if (position.x > FIELD_SIZE)
	{
		position.x = FIELD_SIZE;

	}
	if (position.z < -FIELD_SIZE)
	{
		position.z = -FIELD_SIZE;

	}

	if (position.x < -FIELD_SIZE)
	{
		position.x = -FIELD_SIZE;

	}

	if ( Speed > MAX_SPEED)
		{
			Speed = MAX_SPEED;
		}

	Reset();




	if (inclination_angle < 0.0)
	{
		inclination_angle += 0.04;
		curve_angle -= 0.005;
	}
	if (inclination_angle > 0.0)
	{
		inclination_angle -= 0.04;
		curve_angle += 0.005;
	}

	_boost_bar.Update(dt);
	
	CheckInput();
	
	Speed += boost * dt;

	if (dt > 0.02)
	{
		dt = 0.02;
	}

	position.x += Speed  * sin(curve_angle*1.75);

	position.z += Speed  * (cos(curve_angle*1.75));
	
	m_model =  glm::translate(m_model, position);

	
	m_model = glm::rotate(m_model, curve_angle*1.75f, glm::vec3(0.0,1.0,0.0));
	m_model = glm::rotate(m_model, -inclination_angle, glm::vec3(0.0,0.0,1.0));
	

	m_model = glm::rotate(m_model, curve_up_angle*1.75f, glm::vec3(1.0,0.0,0.0));

	Scale(2.5, 2.5, 2.5);


}

void Player::StartRun()
{
	Speed = INITIAL_SPEED;
}

void Player::EndRun()
{
	Speed = 0;
}

glm::vec3 Player::GetRotation()
{
	glm::vec3 temp_angles;

	temp_angles.x = curve_up_angle;
	temp_angles.y = curve_angle * 1.75;


	return temp_angles;
}



void Player::Draw()
{
	glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_model[0][0]);
	
	glUniform3fv(materialAmbientUniformID, 1, &m_ambient.r);
	glUniform3fv(materialDiffuseUniformID, 1, &m_diffuse.r);
	glUniform3fv(materialSpecularUniformID, 1, &m_specular.r);
	glUniform1f(materialShininessUniformID, shininess);
	

	glUniform1i(lightFlagUniformID, true);
	glUniform1i(textureFlagUniformID, true);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture::Instance()->GetID((!_second_p) ? "PlayerTexture" : "Player2Texture"));
	

	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, m_vertices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);


	glBindTexture(GL_TEXTURE_2D, 0);
}


void Player::CreateScreenPointer(glm::vec3 pos)
{
	

}

glm::vec3 Player::GetPosition()
{	
	return position;
}

void Player::CheckInput()
{
	if (Input::Instance()->IsReturnPressed()) {
		StartRun();
	}


	if (!_second_p)
		
	{
		if (Input::Instance()->IsWPressed()) { 
		
			if (_boost_bar.CanBoost())
			{
				boost += boost_speed;
				if (boost > MAX_BOOST_SPEED)
				{
					boost = MAX_BOOST_SPEED;
				}
				_boost_bar.Boosting() = true;

			}
			}

		else
		{
			if (boost > 0)
			{
				boost -= 0.25;
			}

			if (Speed > INITIAL_SPEED)
			{
				Speed -= 0.0025;

			}

			if (boost < 0 )
			{
				boost = 0;
			}
			_boost_bar.Boosting() = false;

		}


		if (Input::Instance()->IsAPressed()) {

		
			if (inclination_angle < glm::radians(60.0f))
			{
				inclination_angle += 0.08;
			}
			else
			{
				inclination_angle += 0.04;
			}

		}

		if (Input::Instance()->IsDPressed()) { 


			if (inclination_angle > glm::radians(-60.0f))
			{
				inclination_angle -= 0.08;
			}
			else
			{
				inclination_angle -= 0.04;
			}
			
		}
	
	}

	else
	{

		if (Input::Instance()->IsUpPressed()) { 
		
				
			if (_boost_bar.CanBoost())
			{
				boost += boost_speed;
				if (boost > MAX_BOOST_SPEED)
				{
					boost = MAX_BOOST_SPEED;
				}
				_boost_bar.Boosting() = true;
			}

			}
		else
		{
			if (boost > 0)
			{
				boost -= 0.25;
			}

			
			if (Speed > 1.5)
			{
				Speed -= 0.0025;

			}


			if (boost < 0 )
			{
				boost = 0;
			}
		
			_boost_bar.Boosting() = false;

		}

	

		if (Input::Instance()->IsLeftPressed()) {

		
			if (inclination_angle < glm::radians(60.0f))
			{
				inclination_angle += 0.08;
			}
			else
			{
				inclination_angle += 0.04;
			}

		}

		if (Input::Instance()->IsRightPressed()) { 


			if (inclination_angle > glm::radians(-60.0f))
			{
				inclination_angle -= 0.08;
			}
			else
			{
				inclination_angle -= 0.04;
			}
			
		}
			
	}

}

void Player::SetBarPosition(float x, float y, float z)
{
	_boost_bar.Initialise(x, y, z, 15, 15);

}

void Player::DrawBoostBar()
{
	_boost_bar.Draw();
}

Player::~Player()
{

}

