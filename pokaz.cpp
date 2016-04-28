#include "main.h"

using namespace std;

void flower::pokaz()
{
    cout<<"Название цветка: "<<name<<endl;
    cout<<"Уникальный номер цветка: "<<number<<endl;
    cout<<"Цена цветка: "<<price<<endl;
    cout<<"Время роста цветка: "<<time<<endl;
    cout<<"Всего занимают места в теплице: "<<place<<endl<<endl;
}



void poisk(flower* it)
{
    int i,n;
    class flower*
            begin=it;
    cout<<"Введите уникальный номер цветка, который Вы хотите найти: "<<endl;
    cin>>n;
    while(1)
    {
        if(n==it->number)
        {
            cout<<"Название цветка: "<<it->name<<endl;
            cout<<"Уникальный номер цветка: "<<it->number<<endl;
            cout<<"Цена цветка: "<<it->price<<endl;
            cout<<"Время роста цветка: "<<it->time<<endl;
            cout<<"Всего занимают места в теплице: "<<it->place<<endl<<endl;
        }
        if(it->next!=NULL)
            it=it->next;
        else
        {
            if(n==0)
                cout<<"Не найдено"<<endl;
            it=begin;
            break;
        }

    }
}
