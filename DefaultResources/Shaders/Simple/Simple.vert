 #version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

uniform float r = 1;
uniform float g = 1;
uniform float b = 1;

out vec3 vertColor;

//matrices
//uniform mat4 ProjectionMatrix;
//uniform mat4 ModelMatrix;
//uniform mat4 ViewMatrix;
//uniform mat4 ModelViewMatrix;
uniform mat4 ModelViewProjectionMatrix;

void main(){
	vertColor = vec3(r,g,b);
	// transform vertex to world position
	gl_Position = ModelViewProjectionMatrix * vec4(vertexPosition_modelspace, 1.0);	
}