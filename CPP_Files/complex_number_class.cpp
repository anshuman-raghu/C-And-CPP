#include <iostream>
using namespace std;

class Complex{
    private:
        int real,img;
    public:
        Complex(int r=0,int i=0)//ctor
        {
            set(r,i);
        }
        
        void setreal(int r)
        {
            this->real=r;
        }
        
        int getreal() const {return real;}
        
        void setimg(int i)
        {
            this->img=i;
        }
        
        int getimg() const { return img;}
        
        void set(int r,int i)
        {
            setreal(r);setimg(i);
        }
        
        void show()
        {
            cout<<"Real part: "<<getreal()<<"\t Img part: "<<getimg()<<" i"<<endl;
        }
        
        Complex operator+(Complex c)//overloding + operator
        {
            Complex result;
            result.set(this->getreal()+c.getreal(),this->getimg()+c.getimg());
            return result;
        }
        
        
};
Complex operator-(Complex c1,Complex c2)//overloding - operator as non member
{
    Complex result;
    result.set(c1.getreal()-c2.getreal(),c1.getimg()-c2.getimg());
    return result;
}




int main(){
    Complex c1(10,20), c2, c3, c4;
    c2.set(100, 200);
    c3 = c1 + c2; //overload + operator as member function to add c1 and c2 and return the sum in c3
    c3.show();  
    c4 = c1-c2; 
   
    c4.show();
    return 0; 
}
