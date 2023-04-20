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
    return (rear==MAX-1);
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

    a[++rear] = num;

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
  while (!s.full ())
    {
      x = rand () % 10;
      cout<<"Add: "<<x<<endl;
      s.addition (x);
    }
  //s.addition(x); //overflow

  while (!s.empty ())
    {
      cout<<s.deletion()<<endl;
    }

  printf("%d\n",s.deletion());//underflow


  return 0;
}

