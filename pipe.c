#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	int fd[2];
	size_t size;
	char string[] = "Hello, world!";
	char resstring[14];
	if(pipe(fd)<0){
	//Если создать пайп не удалось, печатаем об этом
		printf("Can\'t create pipe\n");
		exit(-1);
	}
	//Пробуем запистаь в пайп 14 байт из нашего массива строку привет, мир
	size = write(fd[1], string, 14);
	if(size!=14){
	//если записалось меньшее количество байт, сообщит об оштбке
		printf("Can\'t write all string\n");
		exit(-1);
	}
	size = read(fd[0], resstring,14);
	if(size<0){
		printf("Can\'t read string\n");
		exit(-1);

	}
	//печатаем прочитанную строку
	printf("%s\n", resstring);
	//закрываем входной поток
	if(close(fd[0])<0){
		printf("Can\'t close input stream\n");
	}
	//закрываем выходнй поток
	if(close(fd[1])<0){
		printf("Can\'t close output stream\n");
	}
	return 0;
}
