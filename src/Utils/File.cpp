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
	}
}