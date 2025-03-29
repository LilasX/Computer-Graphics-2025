// Include the header file "OpenGLIntro.h" that contains declarations for functions, classes, and variables that are used in this source file
#include "OpenGLIntro.h"

// Include the C++ standard output library
#include <iostream>
// Include the standard I/O library for printing output to the console
#include <stdio.h>
// Include the string library for string manipulation
#include <string.h>

// Include GLEW (OpenGL Extension Wrangler) for handling OpenGL extensions
#include <GL/glew.h>
// Include GLFW for creating windows and managing OpenGL context
#include <GLFW/glfw3.h>

// Include GLM (OpenGL Mathematics) for handling transformations and matrix operations
#include <glm/glm.hpp>
// For matrix transformations like rotation
#include <glm/gtc/matrix_transform.hpp>

// Declaration of the vertex shader source code as a constant string
static const char* vShader =
// Starting the GLSL (OpenGL Shading Language) source code using raw string literal syntax
R"glsl(
	// GLSL version declaration, specifies that this shader uses OpenGL version 330 core
	#version 330 core

	// Declares an input vertex attribute 'pos' that is a 3D vector (vec3) passed from the vertex buffer
	// The location = 0 specifies that this attribute will be bound to the 0th input location
	layout (location = 0) in vec3 pos;

	// Declares an input vertex attribute 'color' that is a 3D vector (vec3) passed from the vertex buffer
    // The location = 1 specifies that this attribute will be bound to the 1st input location
	layout (location = 1) in vec3 color;

	// Declares an output variable 'fragColor' to pass the color data to the fragment shader
	out vec3 fragColor;

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

		// Pass the color data to the fragment shader
		fragColor = color; 
	}

// Closing the GLSL source code raw string literal
)glsl";

// Declaration of the fragment shader source code as a constant string
static const char* fShader =
// Starting the GLSL (OpenGL Shading Language) source code using raw string literal syntax
R"glsl(
	// GLSL version declaration, specifies that this shader uses OpenGL version 330 core
	#version 330 core

	// Declare input variable 'fragColor' which receives color data from the vertex shader
	in vec3 fragColor;

	// Declares the output variable 'colour' that will hold the color value of the fragment
	// The type 'vec4' represents a 4D vector, which corresponds to a color with RGBA components
	// The 'out' keyword indicates that this variable will be written to as the shader's output
	out vec4 colour;

	// Main function: entry point for the fragment shader
	void main()
	{
		// The 'vec4' constructor takes four components: Red, Green, Blue, Alpha (opacity)
        // Set the fragment color to the interpolated color passed from the vertex shader
		colour = vec4(fragColor, 1.0);
	}

// Closing the GLSL source code raw string literal
)glsl";

// Constructor for the PyramidRenderer class
// Initializer list is used to initialize member variables
// VAO, VBO, EBO, shader are initialized to 0
// transform is initialized to the identity matrix
// d is initialized to 0.0001f
// s is initialized to 0.0001f
// rotationAngle is initialized to 30 degrees in radians
PyramidRenderer::PyramidRenderer() : VAO(0), VBO(0), EBO(0), shader(0), transform(glm::mat4(1.0f)), d(0.0001f), s(0.0001f), rotationAngle(glm::radians(30.0f))
{
	// Constructor body is empty
}

// Getter for the VAO (Vertex Array Object)
// Returns the value of the member variable VAO
GLuint PyramidRenderer::getVAO() const
{
	return VAO;
}

// Getter for the VBO (Vertex Buffer Object)
// Returns the value of the member variable VBO
GLuint PyramidRenderer::getVBO() const
{
	return VBO;
}

// Getter for the EBO (Element Buffer Object)
// Returns the value of the member variable EBO
GLuint PyramidRenderer::getEBO() const
{
	return EBO;
}

// Getter for the shader program
// Returns the value of the member variable shader
GLuint PyramidRenderer::getShader() const
{
	return shader;
}

// Getter for the transformation matrix
// Returns the value of the member variable transform
glm::mat4 PyramidRenderer::getTransform() const
{
	return transform;
}

// Process Keyboard Input for transformations
void PyramidRenderer::processInput(GLFWwindow* window)
{
	// Track if the Q key is pressed
	static bool isQPressed = false;
	// Track if the E key is pressed
	static bool isEPressed = false;

	// Check if the Escape key is pressed to close the window
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		// Close the GLFW window
		glfwSetWindowShouldClose(window, true);
	}

	// Check if the W key is pressed to translate the object up
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		// Translate up
		transform = glm::translate(transform, glm::vec3(0.0f, d, 0.0f));
	}

	// Check if the S key is pressed to translate the object down
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		// Translate down
		transform = glm::translate(transform, glm::vec3(0.0f, -d, 0.0f));
	}

	// Check if the A key is pressed to translate the object left
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		// Translate left
		transform = glm::translate(transform, glm::vec3(-d, 0.0f, 0.0f));
	}

	// Check if the D key is pressed to translate the object right
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		// Translate right
		transform = glm::translate(transform, glm::vec3(d, 0.0f, 0.0f));
	}

	// Check if the Q key is pressed to rotate the object counterclockwise
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		// Rotate only once per key press
		if (!isQPressed)
		{
			// Rotate counterclockwise
			transform = glm::rotate(transform, rotationAngle, glm::vec3(0.0f, 0.0f, 1.0f));
			// Mark Q key as pressed
			isQPressed = true;
		}
	}
	else
	{
		// Reset Q key press status when not pressed
		isQPressed = false;
	}

	// Check if the E key is pressed to rotate the object clockwise
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		// Rotate only once per key press
		if (!isEPressed)
		{
			// Rotate clockwise
			transform = glm::rotate(transform, -rotationAngle, glm::vec3(0.0f, 0.0f, 1.0f));
			// Mark E key as pressed
			isEPressed = true;
		}
	}
	else
	{
		// Reset E key press status when not pressed
		isEPressed = false;
	}

	// Check if the R key is pressed to scale the object up in the z direction
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		// Scale in +z direction
		transform = glm::scale(transform, glm::vec3(1.0f, 1.0f, 1.0f + s));
	}

	// Check if the F key is pressed to scale the object down in the z direction
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{
		// Scale in -z direction
		transform = glm::scale(transform, glm::vec3(1.0f, 1.0f, 1.0f - s));
	}
}

// Function to create a pyramid
void PyramidRenderer::createPyramid()
{
	// Center is default (0, 0, 0) (x, y, z)
	// Defines the vertices of the Pyramid in 3D space (x, y, z coordinates)

	GLfloat vertices[] =
	{
		// Positions and Colors (Each face has a unique color)
		// Base (square) vertices, Blue-Purple Dark Gradient
		// Bottom-left front (Index 0)
		-0.5f, -0.5f, 0.5f,
		// #1400ff
		0.08f, 0.0f, 1.0f,

		// Bottom-right front (Index 1)
		0.5f, -0.5f, 0.5f,
		// #00bfff
		0.0f, 0.75f, 1.0f,

		// Bottom-right back (Index 2)
		0.5f, -0.5f, -0.5f,
		// #6600ff
		0.4f, 0.0f, 1.0f,

		// Bottom-left back (Index 3)
		-0.5f, -0.5f, -0.5f,
		// 00b3ff
		0.0f, 0.7f, 1.0f,


		// Side 1 vertices, Ocean Blue Gradient
		// Bottom-left front (Index 4)
		-0.5f, -0.5f, 0.5f,
		// #2e3091
		0.18f, 0.19f, 0.57f,

		// Bottom-right front (Index 5)
		0.5f, -0.5f, 0.5f,
		// #2e3091
		0.18f, 0.19f, 0.57f,

		// Top-center (Index 6)
		0.0f,  0.5f, 0.0f,
		// #1cffff
		0.11f, 1.0f, 1.0f, 

		// Side 2 vertices, Blue-Green Gradient
		// Bottom-right front (Index 7)
		0.5f, -0.5f, 0.5f,
		// #0d75e6
		0.05f, 0.46f, 0.9f,

		// Bottom-right back (Index 8)
		0.5f, -0.5f, -0.5f,
		// #0d75e6
		0.05f, 0.46f, 0.9f,

		// Top-center (Index 9)
		0.0f,  0.5f, 0.0f,
		// #00ed6e
		0.0f, 0.93f, 0.43f,

		// Side 3 vertices, Blue-Purple Gradient
		// Bottom-right back (Index 10)
		0.5f, -0.5f, -0.5f,
		// #8712c2
		0.53f, 0.07f, 0.76f,

		// Bottom-left back (Index 11)
		-0.5f, -0.5f, -0.5f,
		// #8712c2
		0.53f, 0.07f, 0.76f,

		// Top-center (Index 12)
		0.0f,  0.5f, 0.0f,
		// #2473fc
		0.14f, 0.45f, 0.99f,

		// Side 4 vertices, Purple-Green Gradient
		// Bottom-left back (Index 13)
		-0.5f, -0.5f, -0.5f,
		// #42057d
		0.26f, 0.02f, 0.49f,

		// Bottom-left front (Index 14)
		-0.5f, -0.5f, 0.5f,
		// #42057d
		0.26f, 0.02f, 0.49f,

		// Top-center (Index 15)
		0.0f,  0.5f, 0.0f,
		// #08f59e
		0.03f, 0.96f, 0.62f
	};

	// Define the indices for the pyramid
	GLuint indices[] =
	{
		// Base of the pyramid (2 triangles to form the square)
		0, 1, 2,
		0, 2, 3,

		// Sides of the pyramid (4 triangles)
		// Side 1
		4, 5, 6,
		// Side 2
		7, 8, 9,
		// Side 3
		10, 11, 12,
		// Side 4
		13, 14, 15
	};

	// Generates a new Vertex Array Object (VAO). 
	// VAOs are used to store the state related to vertex inputs.
	// The '1' indicates we are generating one VAO, and &VAO is where the generated ID will be stored.
	glGenVertexArrays(1, &VAO);
	// Binds the generated VAO, so subsequent vertex attribute settings and buffer operations affect this VAO.
	glBindVertexArray(VAO);

	// Generates a new Vertex Buffer Object (VBO), used to store the vertex data in GPU memory.
	// The '1' indicates we are generating one VBO, and &VBO is where the generated ID will be stored.
	glGenBuffers(1, &VBO);

	// Generates a new Element Buffer Object (EBO), used to store element indices in GPU memory
	// The '1' indicates we are generating one EBO, and &EBO is where the generated ID will be stored
	glGenBuffers(1, &EBO);

	// Binds the VBO to the current array buffer, so data can be uploaded to it.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Uploads the vertex data into the VBO. 
	// `GL_STATIC_DRAW` suggests that the data will not change frequently.
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Bind and buffer the index data to the EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	// Upload the index data to the EBO. 
	// `sizeof(indices)` calculates the total size of the index data in bytes, 
	// `indices` is a pointer to the index data to be uploaded, and `GL_STATIC_DRAW` suggests that the data will not change frequently.
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	// Defines the layout of the vertex data
	// `0` refers to the attribute location (position), `3` is the number of elements per vertex (x, y, z), 
	// `GL_FLOAT` means the data is of type float, `GL_FALSE` indicates the data is not normalized,
	// `6 * sizeof(GLfloat)` is the stride (total size of the vertex data), and `0` is the offset to the data in the buffer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	// Enables the vertex attribute array at location `0`
	glEnableVertexAttribArray(0);

	// Color attribute
	// Defines the layout of the color data
	// `1` refers to the attribute location (color), `3` is the number of elements per vertex (r, g, b),
	// `GL_FLOAT` means the data is of type float, `GL_FALSE` indicates the data is not normalized,
	// `6 * sizeof(GLfloat)` is the stride (total size of the vertex data), and `3 * sizeof(GLfloat)` is the offset to the color data in the buffer
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	// Enables the vertex attribute array at location `1`
	glEnableVertexAttribArray(1);

	// Unbinds the VBO, so no further changes can be made until it is bound again.
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Unbinds the VAO after the configuration is done. 
	// This ensures subsequent rendering doesn't accidentally modify it.
	glBindVertexArray(0);
}

// Function to add shaders to the shader program
void PyramidRenderer::addShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
{
	// Creates a new shader object of the type specified by `shaderType`.
	// `shaderType` can be GL_VERTEX_SHADER or GL_FRAGMENT_SHADER.
	GLuint theShader = glCreateShader(shaderType);

	// Create an array of strings that holds the shader code.
	// In this case, we only have one shader source code string, so the array has one element
	const GLchar* theCode[1];
	// Assign the shader source code to the first element of the array
	theCode[0] = shaderCode;

	// Declare an array to hold the length of each shader source code string
	// Here we only have one string, so the array contains a single value
	GLint codeLength[1];
	// Set the length of the shader code (the number of characters in the string)
	codeLength[0] = strlen(shaderCode);

	// Attach the shader source code to the shader object (`theShader`)
	// `glShaderSource` takes the shader object, the number of strings, an array of strings, and the length of each string
	glShaderSource(theShader, 1, theCode, codeLength);
	// Compile the shader to translate the source code into machine code that the GPU can understand
	glCompileShader(theShader);

	// Declare variables to check the compilation result and store any error messages
	// Initialize `result` to 0 (failure)
	GLint result = 0;
	// Create a buffer to store the error message if compilation fails
	GLchar eLog[1024] = { 0 };

	// Query the shader for its compilation status
	// `glGetShaderiv` checks whether the shader compiled successfully or not
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	// If the compilation failed (`result == 0`), handle the error
	if (!result)
	{
		// If the shader failed to compile, retrieve the error log using `glGetShaderInfoLog`
		// The error message will be stored in `eLog`
		glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
		// Print the error message to the console, indicating which shader type failed (vertex or fragment)
		printf("Error Compiling the %d Shader: '%s'\n", shaderType, eLog);
		// Return early to stop further execution of the function since the shader failed to compile
		return;
	}

	// After successful compilation, attach the compiled shader to the shader program (`theProgram`)
	// This links the shader object to the shader program so it can be used during rendering
	glAttachShader(theProgram, theShader);
}

// Function to compile and link shaders into a shader program
void PyramidRenderer::compileShaders()
{
	// Create a new OpenGL shader program. 
	// This program will hold multiple shaders (vertex and fragment).
	shader = glCreateProgram();

	// Check if the shader program was successfully created.
	if (!shader)
	{
		// If the shader program creation failed, print an error message and exit the function.
		printf("Error Creating Shader Program!\n");
		// Return early as the program creation failed.
		return;
	}

	// Add the vertex shader to the program.
	// `vShader` is a string containing the vertex shader source code.
	// `GL_VERTEX_SHADER` specifies the type of shader being added (in this case, a vertex shader).
	addShader(shader, vShader, GL_VERTEX_SHADER);
	// Add the fragment shader to the program.
	// `fShader` is a string containing the fragment shader source code.
	// `GL_FRAGMENT_SHADER` specifies the type of shader being added (in this case, a fragment shader).
	addShader(shader, fShader, GL_FRAGMENT_SHADER);

	// Declare an integer to hold the result of the linking process (0 if unsuccessful, 1 if successful).
	GLint result = 0;
	// Declare a character array to store error logs if the program fails to link.
	GLchar eLog[1024] = { 0 };

	// Retrieve the linking status using glGetProgramiv(). 
	// It checks if the program linked successfully.
	// The result of the linking status is stored in the variable `result`.
	glLinkProgram(shader);
	// Check if the program was linked successfully.
	glGetProgramiv(shader, GL_LINK_STATUS, &result);
	// If the linking failed (result is 0), execute the following block.
	if (!result)
	{
		// If the program linking failed, retrieve and print the error message using glGetProgramInfoLog().
		// This gets the error message in `eLog`, and `sizeof(eLog)` ensures the log is of proper length.
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		// Print the error message, indicating which stage failed during the linking of the program.
		printf("Error Linking Program: '%s'\n", eLog);
		// Return early because the linking failed, and no further steps should be performed.
		return;
	}

	// After successful linking, validate the program using glValidateProgram().
	// This step checks whether the program can be executed on the GPU, verifying that all shaders and resources
	// are correctly set up and the program can run without errors.
	glValidateProgram(shader);
	// Retrieve the validation status of the program. The result will be stored in the `result` variable.
	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
	// If validation failed (result is 0), execute the following block.
	if (!result)
	{
		// If the program validation failed, retrieve and print the error message using glGetProgramInfoLog().
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		// Print the error message, indicating why the program validation failed.
		printf("Error Validating Program: '%s'\n", eLog);
		// Return early because the program failed validation, so it cannot be used for rendering.
		return;
	}
}

// Entry point for the program
int main()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		// If GLFW fails to initialize, print an error message
		printf("GLFW Initialisation Failed!\n");
		// Terminate GLFW to clean up resources
		glfwTerminate();
		// Return 1 indicating an error occurred
		return 1;
	}

	// Setup GLFW window properties
	// OpenGL version
	// Set the major version of OpenGL to 3 (i.e., OpenGL 3.x)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// Set the minor version of OpenGL to 3 (i.e., OpenGL 3.3)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Core Profile - No Backwards Compatibility
	// Set the OpenGL profile to 'Core', meaning legacy OpenGL features are not available.
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow Forward Compatibility
	// Enable forward compatibility, allowing the use of modern OpenGL features.
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create the GLFW window with a width of 800px, height of 600px, and title "OpenGL window"
	GLFWwindow* mainWindow = glfwCreateWindow(800, 600, "OpenGL window", NULL, NULL);
	// Check if the window creation failed
	if (!mainWindow)
	{
		// If the window creation fails, print an error message
		printf("GLFW Window Creation Failed!\n");
		// Terminate GLFW to clean up resources
		glfwTerminate();
		// Return 1 indicating an error occurred
		return 1;
	}

	// Get Buffer size information
	int bufferWidth, bufferHeight;
	// Retrieve the width and height of the framebuffer (the drawing surface) associated with the window
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context for GLEW to use
	// Make the OpenGL context of the 'mainWindow' the current context for OpenGL calls
	glfwMakeContextCurrent(mainWindow);

	// Allow modern extension features
	glewExperimental = GL_TRUE;
	// Initialize GLEW to manage OpenGL extensions 
	// and ensure the OpenGL function pointers are loaded correctly
	if (glewInit() != GLEW_OK)
	{
		// If GLEW initialization fails, print an error message
		printf("GLEW Initialisation Failed!\n");
		// Destroy the window created by GLFW
		glfwDestroyWindow(mainWindow);
		// Terminate GLFW to clean up resources
		glfwTerminate();
		// Return 1 indicating an error occurred
		return 1;
	}

	// Enable depth testing
	glEnable(GL_DEPTH_TEST);

	// Create the viewport for OpenGL rendering
	// Set the OpenGL viewport to match the size of the window's framebuffer
	glViewport(0, 0, bufferWidth, bufferHeight);

	// Create an instance of PyramidRenderer
	PyramidRenderer pyramid;

	// Create the pyramid geometry (by calling the function that sets up the vertices and buffers)
	pyramid.createPyramid();
	// Compile and link the shaders into a program
	pyramid.compileShaders();

	// Start the main rendering loop
	// Continue until the window should be closed (by the user, or other system events)
	while (!glfwWindowShouldClose(mainWindow))
	{
		// Get and Handle user input events
		// Poll for and process user input events (keyboard, mouse, etc.)
		glfwPollEvents();

		// Clear both color and depth buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Clear the screen with a grey color (RGBA: Red, Green, Blue, Alpha)
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		// Clear the color buffer (the part of memory that holds the pixel data for the window's content)
		glClear(GL_COLOR_BUFFER_BIT);

		// Use the compiled shader program for rendering
		glUseProgram(pyramid.getShader());

		// Process input events (keyboard)
		pyramid.processInput(mainWindow);

		// Get the location of the 'transform' uniform variable in the shader program
		GLuint transformLoc = glGetUniformLocation(pyramid.getShader(), "transform");

		// Pass the transformation matrix to the shader (used for transforming the pyramid's position)
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &pyramid.getTransform()[0][0]);

		// Bind the Vertex Array Object (VAO) to use it for rendering
		glBindVertexArray(pyramid.getVAO());

		// Draw the elements (triangles) defined in the EBO using the vertex data
		// - GL_TRIANGLES: Specifies that the mode of drawing is triangles. 
		// Each set of three indices will form a triangle.
		// - 18: The number of elements to be rendered. 
		// In this case, there are 18 indices (6 triangles * 3 vertices each = 18).
		// - GL_UNSIGNED_INT: Specifies the type of the indices in the EBO. 
		// Here, the indices are unsigned integers.
		// - 0: Specifies an offset in the EBO where the indices start. 
		// Here, the offset is 0, meaning it starts from the beginning of the EBO.
		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);

		// Unbind the VAO to avoid accidental modifications
		glBindVertexArray(0);

		// Unbind the shader program (set the current shader program to 0)
		glUseProgram(0);

		// Swap the front and back buffers (display the rendered content)
		// This is necessary for double buffering (avoiding flickering)
		glfwSwapBuffers(mainWindow);
	}

	// Return 0 indicating successful execution and the program will exit
	return 0;
}
