#include "main.h"

using namespace std;



int main(int argc, char *argv[])
{
    //class flower* it;
    class flower* begin;
    //it=NULL;
    begin=NULL;
    int freeS=0;
    if(argc!=2)
    {
        cout<<"Проверьте подключен ли файл."<<endl;
        exit(1);
    }
    menu(begin, &freeS,argv[1]); //вместо 0 потом поставить argv[1] имя файла
    return 0;
}
