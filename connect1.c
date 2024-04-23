#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
//Подключение библиотеки для управления файлами
int main() {
	int fd;//Файловый дескриптор
	size_t size;//Размер строки в байтах
	char string[]="Group 3.120.2.21";
//Открытие файла на запись, если  файла не существует; то он будет создан с правами доступа 0666
	if((fd = open("file1.txt", O_WRONLY|O_CREAT, 0666))<0) {
		printf("Ошибка при открытии файла на запись\n");
		exit(-1);
	}
//Чтение из файла в строку string
	size =write(fd, string, 17);
	if (size !=17) {
		printf("Не удалось записать всю строку в файл\n");
		exit(-1);
	}
//Закрытие файла
	if(close(fd) < 0) {
		printf("Не удалось закрыть файл\n");
		exit(-1);
	}
	return 0;
}
