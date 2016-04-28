#include "main.h"

using namespace std;

void posadka(flower *catalog, int *freeS)
{
    int x;//площадь теплицы, которую хотим занять
    int n;
    flower* begin;
    begin=catalog;
    cout<<"Введите уникальный номер цветка, который вы хотите посадить: ";
    cin>>n;
    if(catalog==NULL)
    {
        cout<<"каталог пуст!"<<endl;
        return;
    }
    while (1)
    {
        if(n==catalog->number)
        {
            cout<<"Введите количество площади, которую вы хотите засадить даным цветком: ";
            cin>>x;
            if(x>*freeS)
            {
                cout<<"недостаточно места"<<endl;
                break;
            }
            else
            {
                *freeS-=x;
                catalog->place+=x;
                cout<<"Посажено."<<endl;
                break;
            }
        }
        if(catalog->next==NULL)
            break;
        catalog=catalog->next;

    }
    catalog=begin;


}




void sborka(flower* catalog, int* freeS)
{
    int x;//площадь теплицы, которую мы хотим освободить
    int n;
    flower* begin;
    begin=catalog;
    cout<<"введите уникальный номер цветка:";
    cin>>n;
    if(catalog==NULL)
    {
        cout<<"каталог пуст!"<<endl;
        return;
    }
    while (1)
    {
        if(n==catalog->number)
        {
            cout<<"Введите количество площади, которую вы хотите освободить: ";
            cin>>x;
            if(x>catalog->place)
            {
                cout<<"ВНИМАНИЕ! Вы ввели слишком большое число!"<<endl;
                break;
            }
            else
            {
                *freeS+=x;
                catalog->place-=x;
                cout<<"Собрано."<<endl;
                break;
            }

        }
        if(catalog->next==NULL)
            break;
        catalog=catalog->next;

     }
    catalog=begin;


}
