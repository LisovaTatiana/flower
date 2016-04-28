#include "main.h"

using namespace std;

void wfile(flower* it,char* fname, int* freeS)
{
    char* buf;
    int i;
    flower* begin;
    begin=it;
    ofstream file;
    file.open(fname, ios_base::binary | ios_base::out);
    file.write((char*)freeS,sizeof(int));
    while(1)
    {
        i=strlen(it->name);
        file.write((char*)&i,sizeof(int));
        file.write(it->name,(sizeof(char)*i));
        //cout<<"строка"<<endl;
        i=it->number;
        file.write((char*)&i,sizeof(int));
        i=it->place;
        file.write((char*)&i,sizeof(int));
        i=it->time;
        file.write((char*)&i,sizeof(int));
        i=it->price;
        file.write((char*)&i,sizeof(int));
        //cout<<"или тут"<<endl;
        if(it->next!=NULL)
            it=it->next;
        else
        {
            file.close();
            break;
        }
    }
    cout<<"Записано."<<endl;
 }


flower* rfile(char* fname,int* freeS)
{
    flower* begin;
    flower* it;
    int num,price,time,place,i;
    char* name;
    bool c=0;
    ifstream file;
    file.open(fname,ios_base::binary | ios_base::in);
    file.read((char*)freeS,sizeof(int));
    while(1)
    {
        if(file.get()==EOF)
            return(begin);
        else
            file.unget();

        file.read((char*)&i,sizeof(int));
        name=new char[i];
        file.read(name,sizeof(char)*i);
        file.read((char*)&num,sizeof(int));
        file.read((char*)&place,sizeof(int));
        file.read((char*)&time,sizeof(int));
        file.read((char*)&price,sizeof(int));
        if(c==0)
        {
            it=new flower(name,num,price,time,place);
            c=1;
            begin=it;
            continue;
        }
        else
        {
            it->next=new flower(name,num,price,time,place);
            it=it->next;
        }

    }
    return (begin);
}
