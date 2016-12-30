#pragma once
#include <map>

namespace revo {
	namespace containers {

		template<class KeyType, class ValueType>
		class Map {

		private:
			std::map<KeyType, ValueType> internalMap;

		public:
			ValueType& operator[](const KeyType& key) {
				return *internalMap.at(key);
			}
		};
	}
}
