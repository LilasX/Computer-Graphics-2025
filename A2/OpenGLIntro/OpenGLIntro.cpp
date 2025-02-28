#include <stdio.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>



// Declaration of the vertex shader source code as a constant string
static const char* vShader = 
// Starting the GLSL (OpenGL Shading Language) source code using raw string literal syntax
R"glsl(
	// GLSL version declaration, specifies that this shader uses OpenGL version 330 core
	#version 330 core

	// Declares an input vertex attribute 'pos' that is a 3D vector (vec3) passed from the vertex buffer
	// The location = 0 specifies that this attribute will be bound to the 0th input location
	layout (location = 0) in vec3 pos;

	// Declares a uniform variable 'transform' that is a 4x4 matrix (mat4).
	// This matrix will be used for transforming the vertex positions, like scaling, rotating, or translating.
	// The uniform keyword means this value remains constant across all vertices in one draw call.
	uniform mat4 transform;

	// Main function, which is the entry point for the vertex shader
	void main()
	{
		// gl_Position is a built-in variable in GLSL that determines the final position of the vertex.
		// The position is calculated by multiplying the input vertex position (pos) by the transformation matrix (transform).
		// This transforms the vertex position to a new position in the clip space.
		gl_Position = transform * vec4(pos, 1.0);
	}

// Closing the GLSL source code raw string literal
)glsl";

// Declaration of the fragment shader source code as a constant string
static const char* fShader = 
// Starting the GLSL (OpenGL Shading Language) source code using raw string literal syntax
R"glsl(
	// GLSL version declaration, specifies that this shader uses OpenGL version 330 core
	#version 330 core

	// Declares the output variable 'colour' that will hold the color value of the fragment
	// The type 'vec4' represents a 4D vector, which corresponds to a color with RGBA components
	// The 'out' keyword indicates that this variable will be written to as the shader's output
	out vec4 colour;

	// Main function: entry point for the fragment shader
	void main()
	{
		// The 'vec4' constructor takes four components: Red, Green, Blue, Alpha (opacity)
		// Set the fragment color to white (1.0, 1.0, 1.0) with full opacity (1.0) (for now)
		colour = vec4(1.0, 1.0, 1.0, 1.0);
	}

// Closing the GLSL source code raw string literal
)glsl";


int main()
{

	return 0;
}
