#pragma once

namespace revo {
	class CoreService {
	public:
		///<summary>
		///Initialize the core service
		///</summary>
		virtual void initialize() = 0;

		///<summary>
		///Setup some special flag in some use case
		///</summary>
		virtual void setFlag(int* flagsArray, size_t flagsArraySize) = 0;

		///<summary>
		///Service is initialized?
		///</summary>
		///<returns>true if the service has being initialized</returns>
		virtual bool hasInitialized() = 0;

		///<summary>
		///Terminate the core service
		///</summary>
		virtual void terminate() = 0;
	};
}