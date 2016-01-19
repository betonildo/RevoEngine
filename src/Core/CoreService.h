#pragma once

namespace revo {
	class CoreService {
	public:
		virtual void initialize() = 0;
		virtual void terminate() = 0;
	};
}