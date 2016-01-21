#include <functional>
#include <RevoEngine.h>

int main(int argc, char** argv) {

	CRevoEngine* revo = new CRevoEngine();


	revo->initSystem();
	revo->handleUpdate([]() {

	});


	return revo->run();
}