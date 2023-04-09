#include<iostream>

using namespace std;

class Distance
{
    private:
    int feet;float inches;
    
    public:
    Distance(){set(0,0);}
    Distance(int f,float i){set(f,i);}
    
    void setFeet(int f)
    {feet=(0<=f)?f:0;}
    int getFeet() const {return feet;}

    void setInches(float i)
    {inches=(0<=i && i<12)?i:0;}
    float getInches() const {return inches;}

    void set(int f, float i)
    {setFeet(f); setInches(i);}
    void show() const
    {cout<<"Feet: "<<getFeet()<<" Inches: "<<getInches()<<endl;}

    //conversion
    operator float()
    {
        float m;
        m=(getFeet()+getInches()/12)/3.28;
    
    return m;
    }
    Distance(float m)
    {
        float f= m*3.28;
        int feet=(int)f;
        float inch= (f-feet)*12;
        set(feet,inch);
    }
};
int main()
{
    Distance d1(5,10);
    
    d1.show();
    
    float m;
    m=d1;
    cout<<m<<endl;
    
    m=5;
    d1=m;
    d1.show();
    
    
}