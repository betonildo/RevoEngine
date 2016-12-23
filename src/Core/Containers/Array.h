#pragma once
#include "common_headers.h"
namespace revo {
	namespace core {
		namespace containers {

			template<class TYPE, uint numberOfElements>
			class Array
			{
			private:
				TYPE elements[numberOfElements];

			public:

				uint Count() { return numberOfElements; }
				void Clear() { memset(elements, 0, sizeof(elements)); }
				uint ByteSize() const { return sizeof(elements); }
				// memset the entire array to a specific value
				void Memset(const char fill) { memset(elements, fill, numberOfElements * sizeof(*ptr)); }

				// array operators
				const T_ &		operator[](int index) const { assert((unsigned)index < (unsigned)numberOfElements); return elements[index]; }
				T_ &			operator[](int index) { assert((unsigned)index < (unsigned)numberOfElements); return elements[index]; }

				// returns a pointer to the list
				const T_ *		Elements() const { return elements; }
				T_ *			Elements() { return elements; }
			};
		}
	}
}


