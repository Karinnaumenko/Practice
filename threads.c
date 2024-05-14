#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int a = 0;//Инициализация глобальной статической переменной, доступной из каждого thread'а
//Функция, выполняющаяся в рамках второго thread'a
void *mythread(void *dummy)
{
	pthread_t mythid; //Индетификатора thred'a - для каждого имеет своё значение
	mythid = pthread_self();
	a = a+1;
	printf("Thread %ld, Результат вычисления a = %d\n", mythid, a); //Печать идентификатора текущего thred'a и значения глобальной переменной
	return NULL;
}

int main()
{
	pthread_t thid, mythid;
	int result;
	result = pthread_create(&thid, (pthread_attr_t *)NULL, mythread, NULL); //Создание нового thred'a при помощи вызова функции mythread()
	if(result !=0) 
	{
		printf("Ошибка при создании новго thread\'a, возвращенное значение = %d\n", result);
		exit(-1);
	}
	printf("Thread создан, thid = %ld\n", thid);
	mythid = pthread_self(); //Сохраняем в переменной mythid идентификатор главного thread'a
	a = a+1;
	printf("Thread создан %ld, Результат вычисления a = %d\n", mythid, a);
	pthread_join(thid, (void **)NULL); //Ожидание завершения порожденного thread'a
	return 0;
}
