#include<iostream>
#include<queue>
#include<vector>
#include<list>

using namespace std;

class Graph
{
private:
  int V;
  list<int> *adj;
public:
  Graph(int V)
  {
    this->V = V;
    adj = new list<int>[v];
  }
};

int main()
{
  return 0;
}
