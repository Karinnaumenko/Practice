//Подключение библиотек
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//Главная функция программы
int main(int argc, char *argv[], char *envp[]){
	int result1;
	pid_t procid, parentid;//индентификаторы процессов
        pid_t result;//результат системного вызова форк()
        int a = 0;//переменная для проверки работы процесса родителя и процесса ребенка
        result = fork();
	if (result < 0){
                printf("Ошибка при выполнении fork()\n");
                exit(-1);
        }
        else if (result == 0){
                a = a+1;
                procid = getpid();//получение индентификатора текущего процесса
		parentid = getppid();//получение индентификатора родительского процесса
                printf("Ид. процесса: %d, ид.родителя %d, значение переменной a: %d\n", procid, parentid, a);
		//Запускаем в дочернем процессе программу cat
		result1 = execle("/bin/cat", "/bin/cat", "otch.txt", 0, envp);
       		printf("Ошибка при выполнении системного вызова execle()\n");
		exit(-1);
        }
        else { 
                a = a+ 555;
                procid = getpid();
                parentid = getppid();
                printf("Ид. процесса: %d, ид.родителя %d, значение a: %d\n", procid, parentid, a);
	}
	return 0; //никогда не выполняется
}
