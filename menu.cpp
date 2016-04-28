#include "main.h"

using namespace std;

void menu(flower* it, int* freeS, char* fname)
{
    int x;
    flower* begin=NULL;
    fstream file;
    file.open(fname, ios_base::binary | ios_base::in);
    if(file==NULL)
    {
        cout<<"База данных пуста. Начинаем заполнение:"<<endl;
        begin=add_flower(begin,freeS);
        it=begin;
        //wfile(begin,fname,freeS);
    }
    else
    {
        cout<<"***База Данных подключена***";
        begin=rfile(fname,freeS);
    }

    cout<<"-*-*-*-Меню-*-*-*-"<<endl;
    while(1)
    {
        cout<<"1-добавить цветок; 2-удалить цветок; 3-посадить цветок; 4-собрать цветы; 5-просмотр; 6-поиск; 7-выход."<<endl;
        cin>>x;
        switch (x)
        {
        case 1:
            it=add_flower(begin,freeS);
            it=begin;
            //wfile(begin,fname,freeS);
            continue;
        case 2:
            udalenie(begin,freeS);
            //wfile(begin,fname,freeS);
            continue;
        case 3:
            posadka(begin,freeS);//посадка!!!
            wfile(begin,fname,freeS);
            continue;
        case 4:
            sborka(begin,freeS);//сборка!!!
            wfile(begin,fname,freeS);
            continue;
        case 5:
            it=begin;
            if(it==NULL)
            {
                cout<<"Список пуст.";
                continue;
            }
            while(1)
            {
                it->pokaz();
                if(it->next==NULL)
                    break;
                it=it->next;
            }
            cout<<"Свободное место: "<<*freeS<<endl;
            it=begin;
            continue;
        case 6:
            poisk(begin); //поиск!!!
            continue;
        case 7:
            wfile(begin,fname,freeS);
            exit (1);
        default:
            cout<<"Нет такого пункта."<<endl;
            continue;
        }
    }

}
