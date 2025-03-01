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



// Declare global variables for storing OpenGL objects:
// VAO (Vertex Array Object), VBO (Vertex Buffer Object), and the shader program ID
GLuint VAO, VBO, shader;

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

// Function to create a triangle (for now)
void createTriangle()
{
	// Center is default (0, 0, 0) (x, y, z)
	// Defines the vertices of the triangle in 3D space (x, y, z coordinates)
	GLfloat vertices[] =
	{
		// First vertex (bottom-left)
		-0.5f, -0.5f, 0.0f,
		// Second vertex (bottom-right)
		0.5f, -0.5f, 0.0f,
		// Third vertex (top-center)
		0.0f, 0.5f, 0.0f
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
	// Binds the VBO to the current array buffer, so data can be uploaded to it.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Uploads the vertex data into the VBO. `GL_STATIC_DRAW` suggests that the data will not change frequently.
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Defines the layout of the vertex data. 
	// `0` refers to the attribute location (position), `3` is the number of elements per vertex (x, y, z), 
	// `GL_FLOAT` means the data is of type float, `GL_FALSE` indicates the data is not normalized, `0` means no padding between elements, 
	// and `0` is the offset to the data in the buffer.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	// Enables the vertex attribute array at location `0`, meaning it tells OpenGL to use the vertex data.
	glEnableVertexAttribArray(0);

	// Unbinds the VBO, so no further changes can be made until it is bound again.
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Unbinds the VAO after the configuration is done. This ensures subsequent rendering doesn't accidentally modify it.
	glBindVertexArray(0);
}

// Function to add shaders to the shader program
void addShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
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
void compileShaders()
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

	// If everything is set up successfully, print this message
	std::cout << "Everything set!\n";

	// Create the viewport for OpenGL rendering
	// Set the OpenGL viewport to match the size of the window's framebuffer
	glViewport(0, 0, bufferWidth, bufferHeight);

	// Create the triangle geometry (by calling the function that sets up the vertices and buffers)
	createTriangle();
	// Compile and link the shaders into a program
	compileShaders();

	// Start the main rendering loop
	// Continue until the window should be closed (by the user, or other system events)
	while (!glfwWindowShouldClose(mainWindow))
	{
		// Get and Handle user input events
		// Poll for and process user input events (keyboard, mouse, etc.)
		glfwPollEvents();

		// Clear the screen with a black color (RGBA: Red, Green, Blue, Alpha)
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		// Clear the color buffer (the part of memory that holds the pixel data for the window's content)
		glClear(GL_COLOR_BUFFER_BIT);

		// Use the compiled shader program for rendering
		glUseProgram(shader);

		// In your main loop, before drawing the triangle:
		// Create an identity matrix (no transformation)
		glm::mat4 transform = glm::mat4(1.0f);
		// Apply rotation to the transformation matrix (no rotation in this case)
		transform = glm::rotate(transform, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f)); // Rotate the triangle

		// Get the location of the 'transform' uniform variable in the shader program
		GLuint transformLoc = glGetUniformLocation(shader, "transform");

		// Pass the transformation matrix to the shader (used for transforming the triangle's position)
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &transform[0][0]);

		// Bind the Vertex Array Object (VAO) to use it for rendering
		glBindVertexArray(VAO);
		// Draw the triangle by using the vertex data (starting from vertex 0, drawing 3 vertices)
		glDrawArrays(GL_TRIANGLES, 0, 3);
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
