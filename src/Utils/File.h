#pragma once

namespace revo {
	namespace utils {
		class File
		{
		public:
			File();
			~File();

			///<summary>
			///Read all text content from a file at determined path.
			///<summary>
			///<param name='path'>Indicates the path to read from</param>
			///<returns>File content in text format</returns>
			static std::string readAllText(std::string path);

			///<summary>
			///Read all bytes on the file
			///<summary>
			///<param name='path'>Indicates the path to read from</param>
			///<returns>File content in binary format</returns>
			static void* readAllBytes(std::string path);

			
			static void writeAllBytes(std::string path, const void * bytes, unsigned int length);
			

			///<summary>
			/// Test the existance of a file
			///<summary>
			///<param name='path'>Indicates the path of the file</param>
			///<returns>true if the file exists</returns>
			static bool exists(std::string path);
		};
	}
}


