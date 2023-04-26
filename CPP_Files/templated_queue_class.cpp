#include <iostream>
using namespace std;

template <class itype = int>
class queue
{
private:
  itype * a;
  int front, rear, count, MAX;

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
    count = 0;
  }

  int full ()
  {

    return count == MAX;	//return 0 in normal case
  }

  int empty ()
  {
    return count == 0;		//return 1 when empty else 0
  }

  void addition (itype num)
  {
    if (full ())
      {
	printf ("Queue overflow");
	exit (123);
      }

    a[++rear] = num;
    count++;
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
    count--;
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
      std::cout<<"Add: "<<x<<std::endl;
      s.addition (x);
    }
  //s.addition(x); //overflow

  while (!s.empty ())
    {
      std::cout<<s.deletion()<<std::endl;
    }

  //printf("%d\n",s.deletion());//underflow


  return 0;
}


