#include "main.h"
using namespace std;

flower::flower(char *buf, int numbe, int pric, int tim,int plac)
{
    number=numbe;
    price=pric;
    time=tim;
    place=plac;
    name=new char[strlen(buf)];
    strcpy(name,buf);
    next=NULL;
    delete buf;

}

flower::~flower()
{
    delete name;
}

void udalenie (flower* catalog, int* freeS)
{
    int n;
    flower* buf; //сюда запишем указатель, что бы поменять элементы местами
    int num,t,p,s,pl; // номер, время, цена, площадь, занимаемая площадь ( просто переменные, куда мы временно запишем информацию, а потом удалим
    char* nam;// имя ( временно)
    cout<<"Удаление цветка\n";
    cout<<"Введите уникальный номер цветка: ";
    cin>>n;
    if(n==catalog->number)
    {
        nam=new char[strlen(catalog->next->name)];
        strcpy(nam,catalog->next->name);
        num=catalog->next->number;
        t=catalog->next->time;
        p=catalog->next->price;
        pl=catalog->next->place;

        delete catalog->next->name;
        catalog->next->name=new char[strlen(catalog->name)];
        strcpy(catalog->next->name,catalog->name);
        catalog->next->number=catalog->number;
        catalog->next->time=catalog->time;
        catalog->next->price=catalog->price;
        catalog->next->place=catalog->place;

        delete catalog->name;
        catalog->name=new char[strlen(nam)];
        strcpy(catalog->name,nam);
        catalog->number=num;
        catalog->time=t;
        catalog->price=p;
        catalog->place=pl;

        buf=catalog->next;
        catalog->next=catalog->next->next;
        delete buf;
        cout<<"Выбранный цветок удален."<<endl;
        return;
    }
    while (1)
    {
        if(n==catalog->next->number)
        {
            buf=catalog->next;
            catalog->next=catalog->next->next;
            delete buf;
            cout<<"Выбранный цветок удален."<<endl;
            break;
        }
        if((n==catalog->next->number)&&(catalog->next->next)==NULL)
        {
            delete catalog->next;
            catalog->next=NULL;
            cout<<"Выбранный цветок удален."<<endl;
            break;
        }
        if(catalog->next!=NULL)
           catalog=catalog->next;
        else
           break;

    }
}





flower* add_flower(flower *z, int* freeS)//передаем указатель на начало списка.
{
    flower* begin;
    string name;
    char* buf;
    int price, number, time,place;
    begin=z;
    cout<<"-_-_-ДОБАВЛЕНИЕ НОВОГО ЦВЕТКА-_-_-\n";
    cout<<"Название цветка: ";
    cin.ignore();
    getline(cin,name);
    buf=new char[name.length()];
    strcpy(buf,name.c_str());//копирование стринга в буф.
    cout<<"Уникальный номер цветка: ";
    cin>>number;
    cout<<"Цена: ";
    cin>>price;
    cout<<"Время роста: ";
    cin>>time;
    if(z==NULL)
    {
        cout<<"Введите площадь теплицы: ";
        cin>>*freeS;
        begin=new class flower(buf,number, price,time,0);
    }
    else
    {

        while (1)
        {
            if(z->next==NULL)
                break;
            z=z->next;

        }
        z->next=new class flower(buf,number, price,time,0);
    }

    cout<<"-_-_-Запись добавлена-_-_-\n";
    return begin;
}



