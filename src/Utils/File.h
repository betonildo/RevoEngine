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
		};
	}
}


