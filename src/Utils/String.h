#pragma once
#include <vector>

namespace revo {

	namespace utils {

		class String : public std::string {

		private:

		public:

			String(const std::string& other);
			~String();

			std::vector<revo::utils::String> split(const wchar_t& delimiter);
			bool contains(const String& substring);
			bool contains(const char* substring);
			String copyUntilFind(std::vector<wchar_t> oneOfThem);
			String& operator=(const String& other);
		};
	}
}