#include "stdafx.h"
#include "String.h"

namespace revo {

	namespace utils {
		
		String::String(const std::string & other) {

			this->clear();
			this->append(other);
		}

		String::~String() {

			std::string::~basic_string();
		}

		std::vector<revo::utils::String> String::split(const wchar_t & delimiter) {

			std::vector<revo::utils::String> fields;

			size_t stringLength = this->size();
			String currentField("");
			bool hadChars = false;

			for (size_t i = 0; i < stringLength; i++) {

				wchar_t c = this->at(i);

				if (c == delimiter) {
					fields.push_back(currentField);
					currentField.clear();
					hadChars = false;
				}
				else {
					currentField += c;
					hadChars = true;
				}					
			}
			
			if (hadChars) fields.push_back(currentField);

			return fields;
		}

		bool String::contains(const String & substring) {
			return find(substring) != std::string::npos;
		}

		bool String::contains(const char * substring) {
			return find(substring) != std::string::npos;
		}

		String String::copyUntilFind(std::vector<wchar_t> oneOfThem)	{

			String substring("");
			wchar_t c = 0;
			bool foundOneOfThem = false;

			for (size_t i = 0; i < this->length(); i++) {
			
				c = this->at(i);

				for (size_t j = 0; j < oneOfThem.size(); j++) {

					if (c == oneOfThem[j]) {
						foundOneOfThem = true;
						break;
					}
				}

				if (foundOneOfThem) break;
				else substring += c;
			}

			return substring;
		}

		String & String::operator=(const String & other) {
			
			this->clear();
			this->append(other);
			return (*this);
		}
	}
}

