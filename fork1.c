//программа для иллюстрации одинаковой работы процесса - родителя и процесса - ребенка
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	pid_t procid, parentid;//индентификаторы процессов
	pid_t result;//результат системного вызова форк()
	int a = 0;//переменная для проверки работы процесса родителя и процесса ребенка
	result = fork();
	a = a+1;
	procid = getpid();//получение индентификатора текущего процесса
	parentid = getppid();//получение индентификатора родительского процесса
	printf("Ид. процесса: %d, ид.родителя %d, значение переменной a: %d\n", procid, parentid, a);
	return 0;
}
