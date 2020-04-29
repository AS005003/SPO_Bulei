#include <dirent.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(){
	void *handle;
 	char *error;
	char path[20];
	printf("Enter path(Example /home/evgeny/): ");
	scanf("%s",path);
	handle = dlopen("/home/evgeny/lab_sem_8/func.so", RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		return 0;
	}
	
	dlerror();
	void(*func)(char[]) = dlsym(handle,"func");

	if ((error = dlerror()) != NULL) {
 		fprintf(stderr, "%s\n", error);
 		return 0;
	}
	func(path);
        dlclose(handle);
        return 0;
}

