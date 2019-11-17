// C program for Consumer process illustrating 
// POSIX shared-memory API. 
#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/stat.h> 

int main() 
{ 
	const int SIZE = 4096; 
	const char* name = "OS"; 

	int shm_fd; 
	int* ptr; 

	shm_fd = shm_open(name, O_RDONLY, 0666); 
	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0); 
	
	shm_unlink(name); 
	return 0; 
} 
