#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	int fd1[2], fd2[2];
	pid_t result;
	size_t size;
	char string1[] = "Hello, child!", string2[] = "Hello, parent";
	char resstring1[13], resstring2[14];
	if(pipe(fd1)<0)
	{
		printf("Can\'t create pipe()\n");
		exit(-1);
	}
	if(pipe(fd2)<0) 
        {
                printf("Can\'t create pipe()\n");
                exit(-1);
        }

	result = fork();
	if(result<0)
	{
		printf("Error fork()\n");
	}
	else if (result>0)
	{
		if (close(fd1[0])<0)
		{
			printf("Ошибка при закрытии pipe для чтения");
			exit(-1);
		}
		if (close(fd2[1])<0) 
                {
                        printf("Ошибка при закрытии pipe на запись");
                        exit(-1);
                }

		size = write(fd1[1], string1, 13);
		if(size!=13)
		{
			printf("Can\'t write all string\n");
			exit(-1);
		}
		printf("Процесс - родитель записал информацию в pipe\n");
		size = read(fd2[0], resstring2, 14);
		if(size!=14)
		{
			printf("Can\'t read string\n");
                        exit(-1);
                }
		printf("Информация от дочернего процесса: %s\n", resstring2);
		if(close(fd1[1])<0)
		{
			printf("Can\'t close output stream\n");
			exit(-1);
		}
		if(close(fd2[0])<0)
                {
                        printf("Can\'t close input stream\n");
                        exit(-1);
                }

	}
	else
	{
		if(close(fd1[1])<0)
                {
                        printf("Can\'t close output stream\n");
                        exit(-1);
                }
                if(close(fd2[0])<0)
                {
                        printf("Can\'t close input stream\n");
                        exit(-1);
                }

		size = read(fd1[0], resstring1, 13);
		if(size!=13)
		{
			printf("Can\'t read string\n");
			exit(-1);
		}
		printf("%s\n", resstring1);
		size = write(fd2[1], string2, 14);
		if(size != 14)
		{
			printf("Can\'t write string\n");
                        exit(-1);
		}
		printf("Процесс-ребенок записал информацию в pipe\n");
		if (close(fd1[0])<0)
		{
			printf("Can\'t close input stream\n");
		}
		if(close(fd2[1])<0)
		{
			printf("Can\'t close output stream\n");
			exit(-1);
		}
	}
	return 0;
}
