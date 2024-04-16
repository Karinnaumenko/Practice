#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]){
	int result;
	result = execle("/bin/cat", "/bin/cat", "otch.txt", 0, envp);
	printf("Ошибка при выполнении системного вызова execle()\n");
	exit(-1);
	return 0;
}
