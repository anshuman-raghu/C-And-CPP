#include<iostream>
using namespace std;

template < class itype = int >
class queue
{
private:
  itype * a;
  int front, rear, MAX;

public:
    queue (int max = 5)
  {
    MAX = max;
    a = new itype[MAX];
    initialize ();
  }

  void initialize ()
  {
    front = 0;
    rear = -1;
  }

  int full ()
  {
      if(rear+1==MAX)
      {
        if(front==0)
        {
            return 1;
        }
        else
        {
            int i;
            for(i=0;i<MAX;++i)
            {
                a[i]=a[front+i];
            }
            front=0;
            rear=i;
            return 0;
        }
      }
    else return 0;
  }

  int empty ()
  {
    return rear+1==front;		//return 1 when empty else 0
  }

  void addition (itype num)
  {
    if (full ())
      {
	printf ("Queue overflow");
	exit (123);
      }
    rear=(rear+1)%MAX;//
    a[rear] = num;

  }
  itype deletion ()
  {
    if (empty ())
      {
	printf ("Queue underflow");
	exit (321);
      }
    itype data;
    data = a[front++];

    return data;
  }


};


int main ()
{
  queue < int >s (5);
  int x;

  srand (time (0));
      x = rand () % 10;cout<<"Add: "<<x<<endl;s.addition (x);
      x = rand () % 10;cout<<"Add: "<<x<<endl;s.addition (x);
      x = rand () % 10;cout<<"Add: "<<x<<endl;s.addition (x);
      x = rand () % 10;cout<<"Add: "<<x<<endl;s.addition (x);
      x = rand () % 10;cout<<"Add: "<<x<<endl;s.addition (x);
      cout<<s.deletion()<<endl;
      cout<<s.deletion()<<endl;
      cout<<s.deletion()<<endl;
      x = rand () % 10;cout<<"Add: "<<x<<endl;s.addition (x);
      x = rand () % 10;cout<<"Add: "<<x<<endl;
      s.addition (x);
      x = rand () % 10;cout<<"Add: "<<x<<endl;
      s.addition (x);
      x = rand () % 10;cout<<"Add: "<<x<<endl;
      s.addition (x);
      
  //s.addition(x); //overflow

  /*while (!s.empty ())
    {
      cout<<s.deletion()<<endl;
    }
    */
  //printf("%d\n",s.deletion());//underflow


  return 0;
}

