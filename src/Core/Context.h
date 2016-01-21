#pragma once
#include <GL\glew.h>
#include "definitions.h"
#include <vector>


namespace revo {
	class Context {
	public:

		///<summary>
		/// Generate a list of buffers
		///</summary>
		///<param name='howMany'>Indicates how many buffers want to create.</param>
		///<returns>a vector containing buffers to be used</returns>
		virtual std::vector<uint> generateBuffers(uint howMany) = 0;

		///<summary>
		/// Generate a single buffer
		///</summary>
		///<returns>a single buffer</returns>
		virtual uint generateBuffer() = 0;

		///<summary>
		/// Delete a list of buffers
		///</summary>
		///<param name='buffers'>Hold the list of buffers to be deleted</param>
		virtual void deleteBuffers(std::vector<uint> buffers) = 0;

		///<summary>
		/// Delete a single buffer.
		///</summary>
		///<param name='buffer'>Delete a single buffer</param>
		virtual void deleteBuffer(uint buffer) = 0;


		///<summary>
		///Enables a vertex shader channel on the pipeline
		///</summary>
		///<param name='channel'>The channel to be enabled</param>
		virtual void enableVertexAttribArray(uint channel) = 0;

		///<summary>
		///Bind a buffer VAO created to the pipeline
		///</summary>
		///<param name='bufferType'>Binds a buffer type, it can be {GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER}</param>		
		virtual void bindBuffer(uint bufferType, uint bufferPtr) = 0;

		///<summary>
		///Upload binded buffer data to the GPU.
		///</summary>
		///<param name='type'>Type of binding {GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER}</param>		
		///<param name='size'>Size in bytes of the buffer</param>
		///<param name='data'>Buffer data pointer</param>
		///<param name='drawType'>Type of draw{GL_STATIC_DRAW, GL_DYNAMIC_DRAW}</param>
		virtual void bufferData(uint type, uint size, void* data, uint drawType = GL_STATIC_DRAW) = 0;

		///<summary>
		///Set the attributes for the vertex pointer to the GPU.
		///</summary>
		///<param name='attrib'>An attribute for the array on vertex shader</param>
		///<param name='size'>Size of each attributes</param>
		///<param name='type'>Type of the attributes</param>
		///<param name='normalized'>The attributes are normalized</param>
		///<param name='stride'>The distance from the beginning of one entity, to the begginging of the following one</param>
		///<param name='arrayBufferOffset'>the offset to the next part of the vertex attrib array</param>
		virtual void vertexAttribPointer(uint attrib, uint size, uint type = GL_FLOAT, uint normalized = GL_FALSE, uint stride = 0, uint arrayBufferOffset = 0) = 0;

		///<summary>
		///Start Drawing the elements based on mode, count, type and if it has a offset between elements.
		///</summary>
		///<param name='mode'>Mode of the Draw { GL_TRIANGLES, GL_LINES, GL_STRIDE, etc...}</param>
		///<param name='count'>How many elements going to be drawn</param>
		///<param name='type'>Type of each element to be drawn</param>
		///<param name='elementArrayBufferOffset'>Some kind o offset between elements.</param>
		virtual void drawElements(uint mode, uint count, uint type = GL_UNSIGNED_SHORT, uint elementArrayBufferOffset = 0) = 0;

		///<summary>
		/// Disable channel being used.
		///</summary>
		///<param name='channel'>The channel</param>
		virtual void disableVertexAttribArray(uint channel) = 0;
	};
}