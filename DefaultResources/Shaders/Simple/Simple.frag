#version 330 core

out vec4 color;

uniform vec4 colorMult;

varying vec3 vertexPosition;

void main(){
	color = vec4(vertexPosition, 1) * colorMult;
}