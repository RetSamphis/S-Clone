#include "IndexBuffer.h"

namespace sparky {
	namespace graphics {

		IndexBuffer::IndexBuffer(GLfloat* data, GLsizei count) : m_Count(count) {

			glGenBuffers(1, &m_IndexBufferID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLshort), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		}

		void IndexBuffer::bind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
		}
		void IndexBuffer::unbind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}


	}
}