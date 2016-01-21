#include "stdafx.h"
#include "ContextOpenGL.h"


namespace revo {
	namespace adapter {
		ContextOpenGL::ContextOpenGL()
		{
		}

		ContextOpenGL::~ContextOpenGL()
		{
		}

		std::vector<uint> ContextOpenGL::generateBuffers(uint howMany)
		{
			std::vector<uint> buffers;
			buffers.resize(howMany);
			glGenBuffers(howMany, &buffers[0]);

			return buffers;
		}

		uint ContextOpenGL::generateBuffer()
		{
			uint buffer;
			glGenBuffers(1, &buffer);
			return buffer;
		}

		void ContextOpenGL::deleteBuffers(std::vector<uint> buffers)
		{
			glDeleteBuffers(buffers.size(), &buffers[0]);
		}

		void ContextOpenGL::deleteBuffer(uint buffer)
		{
			glDeleteBuffers(1, &buffer);
		}

		void ContextOpenGL::enableVertexAttribArray(uint channel)
		{
			glEnableVertexAttribArray(channel);
		}

		void ContextOpenGL::bindBuffer(uint bufferType, uint bufferPtr)
		{
			glBindBuffer(bufferType, bufferPtr);
		}

		void ContextOpenGL::bufferData(uint type, uint size, void * data, uint drawType)
		{
			glBufferData(
				type, // type 
				size, // size in bytes
				data, // data array
				drawType // draw type. Default: GL_STATIC_DRAW
				);
		}

		void ContextOpenGL::vertexAttribPointer(uint attrib, uint size, uint type, uint normalized, uint stride, uint arrayBufferOffset)
		{
			glVertexAttribPointer(
				attrib,                  // attribute
				size,					 // size
				type,					 // Default: GL_FLOAT,           // type
				normalized,				 // Default: GL_FALSE,           // normalized?
				stride,					 // Default: 0,                  // stride
				(void*)arrayBufferOffset // Default (void*)0            // array buffer offset
				);
		}

		void ContextOpenGL::drawElements( uint mode, uint count, uint type, uint elementArrayBufferOffset)
		{
			mapGlDrawElements(count, mode, type, (void*)elementArrayBufferOffset);
			// Draw the triangles !
			//glDrawElements(
			//	mode, 		// mode
			//	count,	// count
			//	GL_UNSIGNED_SHORT,	// type
			//	(void*)0			// element array buffer offset
			//	);
		}

		void ContextOpenGL::disableVertexAttribArray(uint channel)
		{
			glDisableVertexAttribArray(channel);
		}


		
	}
}
