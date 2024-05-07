#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	int fd[2];
	pid_t result;
	size_t size;
	char string[] = "Hello, world!";
	char resstring[14];
	if(pipe(fd)<0){
	//Если создать пайп не удалось, печатаем об этом
		printf("Can\'t create pipe\n");
		exit(-1);
	}
	result = fork();
	if(result<0)
	{
		printf("Error fork()\n");
	}
	else if (result>0)
	{
		if (close(fd[0]<0))
		{
			printf("Ошибка при закрытии pipe для чтения");
			exit(-1);
		}
		size = write(fd[1], string, 14);
		if(size!=14)
		{
			printf("Can\'t write all string\n");
			exit(-1);
		}
		printf("Процесс - родитель записал информацию в pipe и заканчивает работу\n");
		if(close(fd[1])<0)
		{
			printf("Can\'t close output stream\n");
			exit(-1);
		}
	}
	else
	{
		size = read(fd[0], resstring, 14);
		if(size!=14)
		{
			printf("Can\'t read string\n");
			exit(-1);
		}
		printf("%s\n", resstring);
		if (close(fd[0]<0))
		{
			printf("Can\'t close input stream\n");
		}
		if(close(fd[1])<0)
		{
			printf("Can\'t close output stream\n");
			exit(-1);
		}
	}
	return 0;
}
