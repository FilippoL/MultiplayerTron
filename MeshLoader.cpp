#include "MeshLoader.h"
#include <postprocess.h>
#include <cimport.h>
#include <scene.h>

const aiScene * scene;

MeshLoader::MeshLoader()
{
	
}

bool MeshLoader::LoadModel(const char* Path_to_File)
{
	scene = aiImportFile(Path_to_File, aiProcess_Triangulate | aiProcess_FixInfacingNormals| aiProcess_CalcTangentSpace|
						 aiProcess_FlipUVs | aiProcess_FindInvalidData| aiProcess_OptimizeMeshes| aiProcess_OptimizeGraph|
						 aiProcess_ValidateDataStructure );

		
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) 
    {
        std::cout << "ERROR::ASSIMP::" << aiGetErrorString() << std::endl;
		return false;
    }


	return true;
}

void MeshLoader::InitialiseMesh(std::vector<GLfloat>  &vertices,std::vector<GLfloat>  &colors,std::vector<GLfloat>   &UVs,std::vector<GLuint>   &indices, std::vector<GLfloat>   &normals)
{
	
	for (GLuint i = 0; i < scene->mNumMeshes; i++)
	{

		for (GLuint z = 0; z < scene->mMeshes[i]->mNumVertices; z++)
		{
			vertices.push_back(scene->mMeshes[i]->mVertices[z].x);
			vertices.push_back(scene->mMeshes[i]->mVertices[z].y);
			vertices.push_back(scene->mMeshes[i]->mVertices[z].z);

			if (scene->mMeshes[i]->HasTextureCoords(0)) {
				UVs.push_back(scene->mMeshes[i]->mTextureCoords[0][z].x);
				UVs.push_back(scene->mMeshes[i]->mTextureCoords[0][z].y);
			}

			if (scene->mMeshes[i]->HasNormals()) {
				normals.push_back(scene->mMeshes[i]->mNormals[z].x);
				normals.push_back(scene->mMeshes[i]->mNormals[z].y);
				normals.push_back(scene->mMeshes[i]->mNormals[z].z);
			}


			colors.push_back(1);
			colors.push_back(1);
			colors.push_back(1);

		}

		for (GLuint k = 0; k < scene->mMeshes[i]->mNumFaces; k++)
		{
			for (GLuint g = 0; g < scene->mMeshes[i]->mFaces[k].mNumIndices; g++)
			{
				indices.push_back(scene->mMeshes[i]->mFaces[k].mIndices[g]);
			}

		}
	}

}


MeshLoader::~MeshLoader()
{


}
