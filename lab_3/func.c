#include <dirent.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
extern void func(const char path[]){
	DIR *dir = opendir(path);
	struct dirent *next_dir;
	int i=0;
	while((next_dir = readdir(dir))!= NULL){
		if( (*next_dir).d_type == DT_REG || (*next_dir).d_type == DT_DIR){
			printf("%s \n",(*next_dir).d_name);
		}
	}
	printf("DONE\n");
	closedir(dir);
}

