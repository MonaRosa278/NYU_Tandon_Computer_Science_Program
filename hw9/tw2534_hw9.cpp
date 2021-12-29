#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

// classes
class Ant;
class Doodlebug;
class Organism
{
private:
      char type;
      int moveTimes;
      int x;
      int y;

public:
      Organism(char t, int nx, int ny)
      {
            type = t;
            x = nx;
            y = ny;
            moveTimes = 0;
      }
      virtual int move(char arr[20][20]) = 0;
      char getType()
      {
            return type;
      }
      int getX()
      {
            return x;
      }
      int getY()
      {
            return y;
      }
      int getMoveTimes()
      {
            return moveTimes;
      }
      void addMoveTimes()
      {
            moveTimes++;
      }
      void initMoveTimes()
      {
            moveTimes = 0;
      }
      void setX(int xx)
      {
            x = xx;
      }
      void setY(int yy)
      {
            y = yy;
      }
};
//ant class

class Ant : public Organism
{
public:
      Ant(int nx, int ny) : Organism('o', nx, ny)
      {
      }
      int move(char arr[20][20])
      {
            int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            int x = getX();
            int y = getY();
            int id = rand() % 4;
            int x1 = x + dir[id][0];
            int y1 = y + dir[id][1];
            if (x1 < 0 || x1 >= 20 || y1 < 0 || y1 >= 20)
            {
                  return 0;
            }
            if (arr[x1][y1] != '-')
            {
                  return 0;
            }
            arr[x1][y1] = getType();
            arr[x][y] = '-';
            setX(x1);
            setY(y1);
            return 0;
      }
};

//Doolebug class
class Doodlebug : public Organism
{
private:
      int food;

public:
      Doodlebug(int nx, int ny) : Organism('X', nx, ny)
      {
            food = 0;
      }
      int move(char arr[20][20])
      {
            int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            int x = getX();
            int y = getY();
            int id = rand() % 4;
            int x1 = x + dir[id][0];
            int y1 = y + dir[id][1];
            if (x1 < 0 || x1 >= 20 || y1 < 0 || y1 >= 20)
            {
                  return 0;
            }
            if (arr[x1][y1] == 'X')
            {
                  return 0;
            }
            arr[x1][y1] = getType();
            arr[x][y] = '-';
            setX(x1);
            setY(y1);
            return 0;
      }
      int getFood()
      {
            return food;
      }
      void setFood(int num)
      {
            food = num;
      }
};
class Map
{
private:
      vector<Ant> ants;
      vector<Doodlebug> doodlebugs;
      char arr[20][20];

public:
      int findAnt(int x, int y)
      {
            for (unsigned i = 0; i < ants.size(); i++)
            {
                  if (ants[i].getX() == x && ants[i].getY() == y)
                  {
                        return i;
                  }
            }
            return -1;
      }
      int findDoodlebug(int x, int y)
      {
            for (unsigned i = 0; i < doodlebugs.size(); i++)
            {
                  if (doodlebugs[i].getX() == x && doodlebugs[i].getY() == y)
                  {
                        return i;
                  }
            }
            return -1;
      }
      int addDoodlebug(int x, int y)
      {
            int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (int i = 0; i < 4; i++)
            {
                  int x1 = dir[i][0] + x;
                  int y1 = dir[i][1] + y;
                  if (x1 < 0 || x1 >= 20 || y1 < 0 || y1 >= 20)
                  {
                        continue;
                  }
                  if (findAnt(x1, y1) != -1 || findDoodlebug(x1, y1) != -1)
                  {
                        continue;
                  }
                  doodlebugs.push_back(Doodlebug(x1, y1));
                  return 1;
            }
            return 0;
      }
      int addAnt(int x, int y)
      {
            int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (int i = 0; i < 4; i++)
            {
                  int x1 = dir[i][0] + x;
                  int y1 = dir[i][1] + y;
                  if (x1 < 0 || x1 >= 20 || y1 < 0 || y1 >= 20)
                  {
                        continue;
                  }
                  if (findAnt(x1, y1) != -1 || findDoodlebug(x1, y1) != -1)
                  {
                        continue;
                  }
                  ants.push_back(Ant(x1, y1));
                  return 1;
            }
            return 0;
      }
      Map()
      {
            for (int i = 0; i < 5; i++)
            {
                  int x = rand() % 20;
                  int y = rand() % 20;
                  if (findDoodlebug(x, y) == -1)
                  {
                        doodlebugs.push_back(Doodlebug(x, y));
                  }
            }
            for (int i = 0; i < 100; i++)
            {
                  int x = rand() % 20;
                  int y = rand() % 20;
                  if (findDoodlebug(x, y) == -1 && findAnt(x, y) == -1)
                  {
                        ants.push_back(Ant(x, y));
                  }
            }
      }
      void initArr()
      {
            for (int i = 0; i < 20; i++)
            {
                  for (int j = 0; j < 20; j++)
                  {
                        arr[i][j] = '-';
                  }
            }
            for (unsigned i = 0; i < ants.size(); i++)
            {
                  arr[ants[i].getX()][ants[i].getY()] = ants[i].getType();
            }
            for (unsigned i = 0; i < doodlebugs.size(); i++)
            {
                  arr[doodlebugs[i].getX()][doodlebugs[i].getY()] = doodlebugs[i].getType();
            }
      }
      void DoodlebugRun()
      {
            for (unsigned i = 0; i < doodlebugs.size(); i++)
            {
                  doodlebugs[i].move(arr);
                  doodlebugs[i].addMoveTimes();
                  doodlebugs[i].setFood(doodlebugs[i].getFood() + 1);
                  int x = doodlebugs[i].getX();
                  int y = doodlebugs[i].getY();
                  int id = findAnt(x, y);
                  if (id != -1)
                  {
                        ants.erase(ants.begin() + id);
                        doodlebugs[i].setFood(0);
                  }
            }
            int num = 0;
            unsigned size = doodlebugs.size();
            for (unsigned i = 0; i < size; i++)
            {
                  if (doodlebugs[num].getMoveTimes() >= 8)
                  {
                        if (addDoodlebug(doodlebugs[num].getX(), doodlebugs[num].getY()) == 1)
                        {
                              doodlebugs[num].initMoveTimes();
                        }
                  }
                  if (doodlebugs[num].getFood() >= 3)
                  {
                        doodlebugs.erase(doodlebugs.begin() + num);
                  }
                  else
                  {
                        num++;
                  }
            }
      }
      void AntRun()
      {
            for (unsigned i = 0; i < ants.size(); i++)
            {
                  ants[i].move(arr);
                  ants[i].addMoveTimes();
            }
            int num = 0;
            unsigned size = ants.size();
            for (unsigned i = 0; i < size; i++)
            {
                  if (ants[num].getMoveTimes() >= 3)
                  {
                        if (addAnt(ants[num].getX(), ants[num].getY()) == 1)
                        {
                              ants[num].initMoveTimes();
                        }
                  }
                  num++;
            }
      }
      void Run()
      {
            initArr();
            printMap();
            cout << "Press Enter to initiate next time step: ";
            getchar();
            while (1)
            {
                  initArr();
                  DoodlebugRun();
                  AntRun();
                  printMap();
                  cout << "Press Enter to initiate next time step: ";
                  getchar();
            }
      }
      void printMap()
      {
            for (int i = 0; i < 20; i++)
            {
                  for (int j = 0; j < 20; j++)
                  {
                        cout << setw(2) << arr[i][j];
                  }
                  cout << endl;
            }
      }
};
int main()
{
      srand((unsigned)(time(NULL)));
      Map mp;
      mp.Run();
}
