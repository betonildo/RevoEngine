#pragma once
#include <GL\glew.h>
#include <src\Core\Context.h>

namespace revo {
	namespace adapter {
		class ContextOpenGL : public Context
		{
		public:
			ContextOpenGL();
			~ContextOpenGL();

			// Inherited via Context
			virtual std::vector<uint> generateBuffers(uint howMany) override;
			virtual uint generateBuffer() override;
			virtual void deleteBuffers(std::vector<uint> buffers) override;
			virtual void deleteBuffer(uint buffer) override;
			virtual void enableVertexAttribArray(uint channel) override;
			virtual void bindBuffer(uint bufferType, uint bufferPtr) override;
			virtual void bufferData(uint type, uint size, void * data, uint drawType = GL_STATIC_DRAW) override;
			virtual void vertexAttribPointer(uint attrib, uint size, uint type = GL_FLOAT, uint normalized = GL_FALSE, uint stride = 0, uint arrayBufferOffset = 0) override;
			virtual void drawElements(uint mode, uint count, uint type = GL_UNSIGNED_SHORT, uint elementArrayBufferOffset = 0) override;
			virtual void disableVertexAttribArray(uint channel) override;

		};
	}
}


