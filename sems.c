#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int semid; //Индентификатор ipc дя массива семафоров
	char pathname[] = "forftok.ipc"; //Файл, используемый для генерации ipc - ключа
	key_t key; //ipc - ключ
	struct sembuf mybuf;
	if((key = ftok(pathname, 0)) <0)
	{
		printf("Не удалось сгенерирвоать ipc - ключ\n");
		exit(-1);
	}
	//Получение доступа к массиуву семафоров по ипс ключу
	if((semid = semget(key, 1, 0666 | IPC_CREAT)) <0)
	{
		printf("Не удалось получить доступ к массиву семафоров\n");
		exit(-1);
	}
	//Заполняем структуру майбаф
	mybuf.sem_op = -1;
	mybuf.sem_flg = 0;
	mybuf.sem_num = 0;
	if(semop(semid, &mybuf, 1) < 0) 
	{
		printf("Не удалось выполнить операцию над семафором 0\n");
		exit(-1);
	}
	printf("Условие установлено\n");
	return 0;
}
