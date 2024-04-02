//Подключеие библиотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//Главная функция программы
int main() {
//Объявление переменных
        pid_t process;
        pid_t parent;
//Системный вызов
        process = getpid();
//Системный вызов 
        parent =getppid();
        printf("Ид. процесса: %d\n", process); //Вызов функции
        printf("Ид. родителя: %d\n", parent);
        return 0;
}
