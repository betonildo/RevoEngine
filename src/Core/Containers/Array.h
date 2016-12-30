#pragma once
#include <definitions.h>

namespace revo {
	namespace core {
		namespace containers {

			template<class TYPE, uint numberOfElements>
			class Array {

			private:
				TYPE elements[numberOfElements];
				uint elementUsagePointer = 0;

			public:

				uint Count() { return numberOfElements; }
				void Clear() { memset(elements, 0, sizeof(elements)); }
				uint ByteSize() const { return sizeof(elements); }
				void Append(const TYPE other) { DASSERT(elementUsagePointer < numberOfElements); elements[elementUsagePointer++] = other; }
				void PopBack() { DASSERT(elementUsagePointer < numberOfElements); elements[elementUsagePointer--]; }

				// memset the entire array to a specific value
				void Memset(const char fill) { memset(elements, fill, numberOfElements * sizeof(*elements)); }
				void Memcopy(const void* data) { memcpy(elements, data, numberOfElements * sizeof(*elements)); }

				// array operators
				const TYPE & operator[](uint index) const { DASSERT(index < numberOfElements); return elements[index]; }
				TYPE & operator[](uint index) { DASSERT(index < numberOfElements); return elements[index]; }

				// returns a pointer to the list
				const TYPE * Elements() const { return elements; }
				TYPE * Elements() { return elements; }
			};
		}
	}
}


