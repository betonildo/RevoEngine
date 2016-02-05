#include "stdafx.h"
#include "common_headers.h"
#include "File.h"

namespace revo {
	namespace utils {
		File::File()
		{
		}


		File::~File()
		{
		}

		std::string File::readAllText(std::string path)
		{			
			std::string composedString = "";
			try {
				std::ifstream file(path, std::ios::in);
				std::string line;
				
				while (std::getline(file, line)) {
					composedString += "\n" + line;
				}

				file.close();
			}
			catch (std::exception& ex) {
				std::cout << "ERROR: " << ex.what() << std::endl;
				return std::string("");
			}


			return composedString;
		}

		void * File::readAllBytes(std::string path)
		{
			FILE* fileDescriptor = fopen(path.c_str(), "rb+");
			fseek(fileDescriptor, 0, SEEK_END);
			size_t length = ftell(fileDescriptor);
			fseek(fileDescriptor, 0, SEEK_SET);

			void* buffer = new unsigned char[length];

			fread(buffer, 1, length, fileDescriptor);

			fclose(fileDescriptor);

			return buffer;
		}

		void File::writeAllBytes(std::string path, const void * bytes, unsigned int length)
		{
			FILE* fileDescriptor = fopen(path.c_str(), "wb+");
			fwrite(bytes, 1, length, fileDescriptor);
			fclose(fileDescriptor);
		}

		bool File::exists(std::string path)
		{
			FILE* fd = fopen(path.c_str(), "r");
			if (fd != NULL) {
				fclose(fd);
				return true;
			}
			return false;
		}
	}
}