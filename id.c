//Подключеие библиотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//Главная функция программы
int main() {
	uid_t userid;
	gid_t groupid;
//Системный вызов getuid()
	userid = getuid();
//Системный вызов getgid()
	groupid = getgid();
	printf("Ид. пользователя: %d\n", userid); //Вызов функции
	printf("Ид. группы пользователя: %d\n", groupid);
	return 0;
}
