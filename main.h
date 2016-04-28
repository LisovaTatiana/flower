#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

class flower
{
public:
    int time; //время
    int number; //уникальный номер
    char* name; //название
    int price; //цена
    int place;//сколько занимают ВСЕ посаженные цветы.
    class flower* next; //указатель на следующий цветок
    ~flower();
    flower(char* buf, int numbe, int pric, int tim, int plac);
    void pokaz();
};

void menu(flower* it, int* freeS, char* fname);//меню.
flower *add_flower(flower *z, int* freeS); //запись нового цветка
void udalenie (flower* catalog, int* freeS); //удаление цветка из каталога
void wfile(flower* it,char* fname, int* freeS); //сохранение каталога в файл
//void poisk (flower *catalog, int number, int podpoisk); //поиск  цветка
void poisk(flower* it); //НОВОЕ
void posadka(flower* catalog, int* freeS);// функция посадки
void sborka(flower* catalog, int* freeS);
flower* rfile(char* fname,int* freeS);

#endif // MAIN_H
