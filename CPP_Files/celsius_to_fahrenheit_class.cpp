

#include <iostream>
using namespace std;


class Ctemp
{
    private:
    float cel;
    public:
    Ctemp(){set(0);}
    Ctemp(float t){set(t);}
    
    void set(float t)
    {
        cel=(t>-273?t:0);
    }
    float getCtemp(){return cel;}
    
    void show()
    {
        cout<<"Celcius: "<<getCtemp()<<endl;
    }
    
};
class Ftemp
{
    private:
    float fer;
    public:
    Ftemp(){set(0);}
    Ftemp(float t){set(t);}
    
    void set(float t)
    {
        fer=(t>=32&&t<=212)?t:32;
    }
    float getFtemp(){return fer;}
    
    void show()
    {
        cout<<"fahrenheit: "<<getFtemp()<<endl;
    }
    
    Ftemp(Ctemp cel)
    {
        //c/5=f-32/9
        this->set(cel.getCtemp()*9/5+32);
    }
    //operator Ctemp()
    //{
        
   // }
    
};

int main()
{
    
    Ctemp c(20);
    Ftemp f(35);
    
    c.show();
    f.show();
    
    f=c;
    c.show;
    f.show;
    
    //f=c;
    return 0;
}
