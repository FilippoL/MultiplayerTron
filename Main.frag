//fragment shader code 

#version 330 core  

in vec3 colorOut; 
in vec2 textureOut;
in vec3 positionOut;
in vec3 normalOut;
uniform float exposure;

out vec4 pixelColor; 
 
uniform sampler2D textureImage;


uniform vec3 CameraPos;

uniform bool isTextured;
uniform bool isLighted;

uniform bool isFBO;


uniform mat4 model;

struct Light
{
 vec3 position;
 vec3 ambient;
 vec3 diffuse;
 vec3 specular;
};

struct Material 
{
 vec3 position;
 vec3 ambient;
 vec3 diffuse;
 vec3 specular;
 float shininess;
};



uniform Light light;
uniform Material material;


void main(void)
{     
	
	vec3 new_m_diffuse;
	vec3 new_m_specular;
	vec3 new_m_ambient;
	const float gamma = 2.2; //gamma correction
	vec3 result = vec3(0); //this is going to be our final rendered object
	

	if (isLighted)//light caculation could be done in a different shader
	{	

		if(exposure != 0)		
		{
			
			new_m_diffuse = material.diffuse;	//this is not real exposure, i just use the same value when cars accellerate
			new_m_specular = material.specular;
			new_m_ambient = material.ambient;
		}

		else{
			new_m_diffuse = material.diffuse;	
			new_m_specular = material.specular;	
			new_m_ambient = material.ambient;

		}


		vec3 ambientColor = light.ambient * new_m_ambient;

		//position of the world
		vec3 positionWorld = (model * vec4(positionOut, 1.0)).xyz;

		vec3 normalWorld = mat3(transpose(inverse(model)))* normalOut;
		
		//calculate the light direction based on light’s position and vertex position
		vec3 lightDirection = normalize(light.position - positionWorld);
		//calculate the light intensity value
		float lightIntensity = max(dot(lightDirection, normalWorld), 0.0);
		//calculate the diffuse color
		vec3 diffuseColor = light.diffuse * new_m_diffuse * lightIntensity;
		

		//calculate the view direction based on camera’s position and vertex position
		vec3 viewDirection = normalize(CameraPos - positionWorld);
		//calculate the reflection based on reversed light direction and normal vectors
		vec3 reflection = reflect(-lightDirection, normalWorld);
		//calculate the specular term using the reflection and view direction vectors
		float specularTerm = pow(max(dot(viewDirection, reflection), 0.0), material.shininess);
		//calculate the specular color
		vec3 specularColor = light.specular * new_m_specular * specularTerm;
	
		result =  vec3(ambientColor + diffuseColor + specularColor);

	 
		

		if(isTextured)
			{
				
				
					result = pow(result, vec3(1.0 / gamma));
					pixelColor = vec4(result, 1.0) * texture(textureImage, textureOut).rgb;
			}
		//otherwise simply calculate the final fragment color
		else
			{
					pixelColor = vec4( result, 1.0);
			}


	}
	/*******************************************************************///texture calculation && frame buffer handling (hdr)

	else{
			if(isFBO)
			{
			/*here, because we implemented frame buffer and enabled hdr by processing the texture's colors created out of the frame and take the normalized 
			values of the RGB to more than 1.0. */
			/* Reinhard algorithm for tone mapping still allow us to mantain some precision of the picture, 
			i wish i had more time and shading knowledge to improve a better effect..   */
																																							

				vec3 hdrColor = vec3(0);

				hdrColor = texture(textureImage, textureOut).rgb;


				result = vec3(1.0) - exp(-hdrColor * exposure);

				
				result = pow(result, vec3(1.0 / gamma));

				pixelColor = vec4(result, 1.0);


			}

			else {

				if(isTextured)
					{
						pixelColor = vec4(colorOut, 1.0) * texture(textureImage, textureOut.st);
					}
					//otherwise simply calculate the final fragment color
				else
					{
						 pixelColor = vec4(colorOut, 1.0);
					}
			}


		}

	
	
}