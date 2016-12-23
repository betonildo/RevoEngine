#version 330 core

out vec3 color;

in vec3 vertColor;

varying vec3 vertexPosition;

void main(){
	color = vertexPosition + vec3(1,1,1);
}