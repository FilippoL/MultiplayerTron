#include <vector>
#include "Sprite.h"




Sprite::Sprite()
{
	std::cout << "\nSprite Created";
}


Sprite::~Sprite()
{
	flipped = false;
}


bool Sprite::Fill(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat h, 
				  std::vector<GLfloat> &v, std::vector<GLfloat> &c, std::vector<GLfloat> &uv, 
				  std::vector<GLuint> &ind, std::vector<GLfloat> &norm, bool Lighted)
{
	//all vertices for 2D quad (we will keep the depth at 0)
	v.push_back(x - w/2); v.push_back(y - h/2); v.push_back(z); 
	v.push_back(x - w/2); v.push_back(y + h/2); v.push_back(z); 
	v.push_back(x + w/2); v.push_back(y + h/2); v.push_back(z); 
	v.push_back(x + w/2); v.push_back(y - h/2); v.push_back(z); 

	//all colors for 2D quad
	if (_color != glm::vec3(0))
	{
		c.push_back(_color.r); c.push_back(_color.g); c.push_back(_color.b);
		c.push_back(_color.r); c.push_back(_color.g); c.push_back(_color.b);
		c.push_back(_color.r); c.push_back(_color.g); c.push_back(_color.b);
		c.push_back(_color.r); c.push_back(_color.g); c.push_back(_color.b);
	}
	else
	{
		c.push_back(1.0f); c.push_back(1.0f); c.push_back(1.0f);
		c.push_back(1.0f); c.push_back(1.0f); c.push_back(1.0f);
		c.push_back(1.0f); c.push_back(1.0f); c.push_back(1.0f);
		c.push_back(1.0f); c.push_back(1.0f); c.push_back(1.0f);
	}

	if (flipped)
	{
			//all texture coordinates for 2D quad
		uv.push_back(0.0f); uv.push_back(-1.0f);
		uv.push_back(0.0f); uv.push_back(-0.0f);
		uv.push_back(1.0f); uv.push_back(-0.0f); 
		uv.push_back(1.0f); uv.push_back(-1.0f);

	}
	else
	{
		//all texture coordinates for 2D quad
		uv.push_back(0.0f); uv.push_back(1.0f);
		uv.push_back(0.0f); uv.push_back(0.0f);
		uv.push_back(1.0f); uv.push_back(0.0f); 
		uv.push_back(1.0f); uv.push_back(1.0f);

	}

	//all index buffer values for 2D quad
	ind.push_back(0); ind.push_back(1); ind.push_back(3);
	ind.push_back(1); ind.push_back(2); ind.push_back(3);
	
	
	if (Lighted)
	{
		//all normals buffer values for 2D quad
		norm.push_back(0.0f); norm.push_back(0.0f); norm.push_back(-1.0f);
		norm.push_back(0.0f); norm.push_back(0.0f); norm.push_back(-1.0f);
		norm.push_back(0.0f); norm.push_back(0.0f); norm.push_back(-1.0f);
		norm.push_back(0.0f); norm.push_back(0.0f); norm.push_back(-1.0f);
	
		/*norm.push_back(0.0f); norm.push_back(0.0f); norm.push_back(1.0f);
		norm.push_back(0.0f); norm.push_back(0.0f); norm.push_back(1.0f);
		norm.push_back(0.0f); norm.push_back(0.0f); norm.push_back(1.0f);
		norm.push_back(0.0f); norm.push_back(0.0f); norm.push_back(1.0f);*/
	}

	
	return true;
}

void Sprite::SetColor(glm::vec3 color)
{
	_color = color;
}


void Sprite::Flip()
{
	flipped = true;
}