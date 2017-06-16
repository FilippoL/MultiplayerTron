//vertex shader code 

#version 330 core 
 
in vec3 position; 
in vec3 colorIn; 
in vec2 textureIn;
in vec3 normalIn;


out vec2 textureOut; 
out vec3 colorOut; 
out vec3 normalOut;
out vec3 positionOut; 

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


 
void main(void) 
{    
	

	colorOut = colorIn;
	positionOut = position;
	normalOut = normalIn;

	textureOut = textureIn;  
	gl_Position = projection * view * model * vec4(position, 1.0); 
	// We read matrix multiplication from right to left, the above moltiplication is:
	//  Clip View = Projection Matrix * View Matrix * Model Matric * Vector Local Pos

} 