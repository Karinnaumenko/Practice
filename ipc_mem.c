#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *array;
	int shmid;
	int new = 1;
	char pathname[] = "forftok.ipc";
	key_t key;
	if ((key = ftok(pathname,0)) < 0)
	{
		printf("Не удалось сгенерировать ipc-ключ\n");
		exit(-1);
	}
	if((shmid = shmget(key, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) <0)
	{
		if(errno !=EEXIST)
		{
			printf("Не удается создать область разделяемой памяти\n");
			exit(-1);
		}
		//Получение индентификатора области разделяемой памяти, если область уже существует
		else
		{
			if ((shmid = shmget(key, 3*sizeof(int), 0)) <0)
			{
				printf("Не удается найти область разделяеймо памяти\n");
				exit(-1);
			}
			new = 0; //Установка признака уже существующей области разделяемой памти
		}
	}
	if((array = (int*)shmat(shmid, NULL, 0)) == (int *)(-1))
	{
		printf("Не удалось добавить разделяемую память в адресное пространство процесса\n");
		exit(-1);
	}
	//Операции над вновь созданным массив
	if(new)
	{
		array[0] = 1;
		array[1] = 0;
		array[2] = 1;
	}
	//Операции над уже существющим массивом
	else
	{
		array[0] += 1;
		array[2] += 1;
	}
	printf("Программа 1 была запущена %d раз(а), программа 2 - %d раз(а), всего - %d\n", array[0], array[1], array[2]);
	//Исключение области разделяемой памяти из адресного пространства текущего процесса
	if(shmdt(array)<0)
	{
		printf("Не удается исключить разделяемую память из адресного процесса\n");
		exit(-1);
	}
	return 0;
}
