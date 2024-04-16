//Подключение библиотек
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//Главная функция программы
int main(int argc, char *argv[], char *envp[]){
	int result;
	//Запуск программы cat с аргументом otch.txt
	result = execle("/bin/cat", "/bin/cat", "otch.txt", 0, envp);
	//printf() выполняется только в случае ошибки вызова execle()
	printf("Ошибка при выполнении системного вызова execle()\n");
	exit(-1);
	return 0; //никогда не выполняется
}
