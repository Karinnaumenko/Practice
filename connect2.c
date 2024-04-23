#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//Библиотека управления файлами 
#include <fcntl.h>
int main() {
	int fd;
	size_t size;
//Инициализируем  массив символов, чтобы туда записать информацию из файла
	char string[17];
	if((fd = open("file1.txt", O_RDONLY))<0) {
		printf("Ошибка при открытии файла на чтение\n");
		exit(-1);
	}
//Чтение информации из файла
	size =read(fd, string, 17);
//Проверка количества прочитанных байт
	if (size !=17) {
		printf("Не удалось записать всю строку из файла\n");
		exit(-1);
	}
//Печать строки
	printf("%s\n", string);
//Закрытие файла
	if(close(fd) < 0) {
		printf("Не удалось закрыть файл\n");
		exit(-1);
	}
	return 0;
}
