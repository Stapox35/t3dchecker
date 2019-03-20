#include <iostream>
#include <fstream>
using namespace std;

unsigned long  i=0;


class T3dmodel
{
    public:
    string parent,type,name,wiresize,opacity,map,maxdistance,mindistance,numvertex;
    float ambient[3], diffuse[3], specular[3];
    bool selgillum,wire,anim;

};

void t3danalizefromfile(string namefile)
{
string line;
 fstream t3d_in;
    t3d_in.open(namefile, ios::in);
    bool setsubmodel=false;
    int oper=0;
    while(t3d_in.good())
    {
        t3d_in>>line;

        if(line != "")
        {
                if(line[0] == '/' && line[1] == '/')
            {
                setsubmodel=1;
            }
            if(setsubmodel)
            {
                if(oper == 0)
                {
                if(line == "Parent:")oper = 1;
                if(line == "Type:")oper = 2;
                if(line == "Name:")oper = 3;
                }
                else if(oper == 1)
                {
                    string parent = line;
                    oper=0;
                }
                else if(oper == 2)
                {
                    string type = line;
                    oper=0;
                }
                else if(oper == 3)
                {
                string name = line;
                string* nameobject =& name;
                   // T3dmodel  *nameobject;
                }
            }
        }
    }
 t3d_in.close();
}

int main()
{
    string t3d_name;
    cin>> t3d_name;
    t3d_name = t3d_name+".t3d";

     t3danalizefromfile(t3d_name);

    //cout << i << endl;

    return 0;
}
