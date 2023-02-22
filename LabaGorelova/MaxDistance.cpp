
#include <iostream>
#include <cstdlib>
#include "Point.h"
using namespace std;

void additem(Point** &array, int& size, Point* item)
{
    Point** newArray = new Point * [size + 1];
    for (int i = 0;i < size; i++)
    {
        newArray[i] = array[i];
    }
    newArray[size] = item;
    size++;
    delete[] array;
    array = newArray;
    
}

void PrintPoint(Point& p)
{
    cout << p.GetX() << ";" << p.Gety() << " ";
}

int main(int argc, char* argv[])
{
    setlocale(0, "");
    if (argc % 2 == 0||argc==1)
    {
        cout << "Некорректные параметры";
        return -1;
    }
    int n = (argc - 1) / 2;
    Point** quadrant2 = new Point * [0];
    Point** quadrant4 = new Point * [0];

    int size2 = 0, size4 = 0, x, y;
    for (int i = 0;i < n;i++)
    {
        x = atoi(argv[i * 2 + 1]);
        y = atoi(argv[i * 2 + 2]);

        if (x < 0 && y>0)
        {
            additem(quadrant2, size2, new Point(x, y));
        }
        if (x > 0 && y < 0)
        {
            additem(quadrant4, size4, new Point(x, y));
        }
    }
    Point* p2=quadrant2[0];
    Point* p4=quadrant4[0];
    double dist, maxdist = -1;
    for(int i=0;i<size2;i++)
     for (int j = 0;j < size4;j++)
     {
         dist = quadrant2[i]->GetDistance(*quadrant4[j]);
         if (maxdist < dist)
         {
             maxdist = dist;
             p2 = quadrant2[i];
             p4 = quadrant4[j];
         }
     }
    PrintPoint(*p2);
    PrintPoint(*p4);
    cout << maxdist << endl;
    for (int i = 0;quadrant2 != NULL;i++)
    {
        delete quadrant2[i];
    }
    delete[] quadrant2;
    for (int i = 0;quadrant4 != NULL;i++)
    {
        delete quadrant4[i];
    }
    delete[] quadrant2;
    system("pause");
    
}


