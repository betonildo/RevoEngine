 #version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

uniform float r = 1;
uniform float g = 1;
uniform float b = 1;

out vec3 vertColor;

varying vec3 vertexPosition; 

void main(){
	vertexPosition = vertexPosition_modelspace;
	vertColor = vec3(r,g,b);
	gl_Position.xyz = vertexPosition_modelspace;
	gl_Position.w = 1.0;
}