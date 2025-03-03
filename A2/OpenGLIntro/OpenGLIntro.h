// Ifndef (if not defined) preprocessor directive to avoid multiple inclusions of this header file
#ifndef OPENGLINTRO_H  
#define OPENGLINTRO_H

// Include the GLEW library for managing OpenGL extensions
#include <GL/glew.h>
// Include the GLFW library for creating windows and handling input
#include <GLFW/glfw3.h>
// Include the GLM library for mathematics (OpenGL Mathematics)
#include <glm/glm.hpp>

// Define the PyramidRenderer class
class PyramidRenderer
{
public:
	// Constructor for the PyramidRenderer class
	PyramidRenderer();

	// Getter for the VAO (Vertex Array Object)
	GLuint getVAO() const;
	// Getter for the VBO (Vertex Buffer Object)
	GLuint getVBO() const;
	// Getter for the EBO (Element Buffer Object)
	GLuint getEBO() const;
	// Getter for the shader program ID
	GLuint getShader() const;
	// Getter for the transformation matrix
	glm::mat4 getTransform() const;

	// Method to process keyboard input
	void processInput(GLFWwindow* window);
	// Method to create the pyramid geometry
	void createPyramid();
	// Method to compile and link the shaders
	void compileShaders();

private:
	// Declare global variables for storing OpenGL objects:
	// VAO (Vertex Array Object), VBO (Vertex Buffer Object), EBO (Element Buffer Object), and the shader program ID
	GLuint VAO, VBO, EBO, shader;
	// Initialize the transformation matrix to the identity matrix
	glm::mat4 transform;
	// Transformation constants
	// translation distance
	const float d;
	// scale factor
	const float s;
	// rotation angle in radians
	const float rotationAngle;

	// Method to add a shader to the shader program
	void addShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};

// End of the ifndef directive to avoid multiple inclusions
#endif