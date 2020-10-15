#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;

int board[45][45] = {{0}};

int index1, row, col, step;
string symbole;
int flag, flag2;


class block
{
public:
    int x1, x2, x3, x4, y1, y2, y3, y4;
    block(string shape)
    {
        if (shape == "T1")
        {
            x1 = 3; y1 = 1;
            x2 = 3; y2 = 2;
            x3 = 3; y3 = 3;
            x4 = 4; y4 = 2;
        }
        else if (shape == "T2")
        {
            x1 = 3; y1 = 1;
            x2 = 3; y2 = 2;
            x3 = 2; y3 = 2;
            x4 = 4; y4 = 2;
        }
        else if (shape == "T3")
        {
            x1 = 3; y1 = 2;
            x2 = 4; y2 = 1;
            x3 = 4; y3 = 2;
            x4 = 4; y4 = 3;
        }
        else if (shape == "T4")
        {
            x1 = 2; y1 = 1;
            x2 = 3; y2 = 1;
            x3 = 3; y3 = 2;
            x4 = 4; y4 = 1;
        }
        else if (shape == "L1")
        {
            x1 = 2; y1 = 1;
            x2 = 3; y2 = 1;
            x3 = 4; y3 = 1;
            x4 = 4; y4 = 2;
        }
        else if (shape == "L2")
        {
            x1 = 3; y1 = 1;
            x2 = 3; y2 = 2;
            x3 = 3; y3 = 3;
            x4 = 4; y4 = 1;
        }
        else if (shape == "L3")
        {
            x1 = 2; y1 = 1;
            x2 = 2; y2 = 2;
            x3 = 3; y3 = 2;
            x4 = 4; y4 = 2;
        }
        else if (shape == "L4")
        {
            x1 = 3; y1 = 3;
            x2 = 4; y2 = 1;
            x3 = 4; y3 = 2;
            x4 = 4; y4 = 3;
        }
        else if (shape == "J1")
        {
            x1 = 2; y1 = 2;
            x2 = 3; y2 = 2;
            x3 = 4; y3 = 1;
            x4 = 4; y4 = 2;
        }
        else if (shape == "J2")
        {
            x1 = 3; y1 = 1;
            x2 = 4; y2 = 1;
            x3 = 4; y3 = 2;
            x4 = 4; y4 = 3;
        }
        else if (shape == "J3")
        {
            x1 = 2; y1 = 1;
            x2 = 2; y2 = 2;
            x3 = 3; y3 = 1;
            x4 = 4; y4 = 1;
        }
        else if (shape == "J4")
        {
            x1 = 3; y1 = 1;
            x2 = 3; y2 = 2;
            x3 = 3; y3 = 3;
            x4 = 4; y4 = 3;
        }
        else if (shape == "S1")
        {
            x1 = 3; y1 = 2;
            x2 = 3; y2 = 3;
            x3 = 4; y3 = 1;
            x4 = 4; y4 = 2;
        }
        else if (shape == "S2")
        {
            x1 = 2; y1 = 1;
            x2 = 3; y2 = 1;
            x3 = 3; y3 = 2;
            x4 = 4; y4 = 2;
        }
        else if (shape == "Z1")
        {
            x1 = 3; y1 = 1;
            x2 = 3; y2 = 2;
            x3 = 4; y3 = 2;
            x4 = 4; y4 = 3;
        }
        else if (shape == "Z2")
        {
            x1 = 2; y1 = 2;
            x2 = 3; y2 = 1;
            x3 = 3; y3 = 2;
            x4 = 4; y4 = 1;
        }
        else if (shape == "I1")
        {
            x1 = 1; y1 = 1;
            x2 = 2; y2 = 1;
            x3 = 3; y3 = 1;
            x4 = 4; y4 = 1;
        }
        else if (shape == "I2")
        {
            x1 = 4; y1 = 1;
            x2 = 4; y2 = 2;
            x3 = 4; y3 = 3;
            x4 = 4; y4 = 4;
        }
        else if (shape == "O")
        {
            x1 = 3; y1 = 1;
            x2 = 3; y2 = 2;
            x3 = 4; y3 = 1;
            x4 = 4; y4 = 2;
        }
    }
};


void falling(block &shape);
int checkValidity( block &shape);
void shiftingPos(block &shape, int step);
void updateBoard(block &shape);




void falling(block& shape)
{
    if (flag)
    {
        for (int i = 4; i < row + 400; i++)
        {
            shape.x1 += 1;

            shape.x2 += 1;

            shape.x3 += 1;

            shape.x4 += 1;
            int num = checkValidity(shape);
            if( num==-1){
                shape.x1 -= 1;
                
                shape.x2 -= 1;
                
                shape.x3 -= 1;
                
                shape.x4 -= 1;
                break;
            }
            if(num==2){
                break;
            }
            
          }
    
        shiftingPos(shape, step);
        
        for (int i = 4; i < row + 400; i++)
               {
                   if(shape.x4 + 1 >= row+4){
                       break;
                   }
                   shape.x1 += 1;

                   shape.x2 += 1;

                   shape.x3 += 1;

                   shape.x4 += 1;
                   int num = checkValidity(shape);
                   if( num==-1){
                       shape.x1 -= 1;
                       
                       shape.x2 -= 1;
                       
                       shape.x3 -= 1;
                       
                       shape.x4 -= 1;
                       break;
                   }
                   if(num==2){
                       break;
                   }
                   
                 }
        updateBoard(shape);
       
    }
    
    
}

void updateBoard(block &shape)
{
    board[shape.x1][shape.y1] = 1;
    board[shape.x2][shape.y2] = 1;
    board[shape.x3][shape.y3] = 1;
    board[shape.x4][shape.y4] = 1;

    for (int i = 4; i < row + 4; i++)
    {
        flag2=1;
        for (int j = 0; j < col; j++)
        {

            if (board[i][j] == 0)
            {
                flag2 = 0;
                break;
            }
            
        }
        if (flag2 == 1)
        {
            for (int k = i; k > 3; k--)
            {
                for (int j = 0; j < col; j++)
                {
                    board[k][j] = 0;
                    board[k][j] = board[k-1][j];
                }
              
            }
        }
    }

    

}



int checkValidity(block &shape)
{

    if ((board[shape.x1][shape.y1] || board[shape.x2][shape.y2] || board[shape.x3][shape.y3] || board[shape.x4][shape.y4]))
    {

        return -1;
    }

    else if (shape.x1 ==row+3 || shape.x2==row+3 || shape.x3==row+3 || shape.x4 == row + 3)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

void shiftingPos(block &shape, int step)
{
    shape.y1 += step;
    shape.y2 += step;
    shape.y3 += step;
    shape.y4 += step;
}

int main(int argc, char *argv[])
{
    ifstream fin;
    fin.open(argv[1]);
    char N[10];
    flag = 1;
    flag2= 1;
    fin.getline(N, 10);
    stringstream ss(N);
    ss >> row >> col;
//    cin >> row >> col;
    // renew board
    for (int i = 0; i < row + 4; ++i)
        for (int j = 0; j < col; ++j)
            board[i][j] = 0;

    while (!fin.eof())
//    while(1)
    {
        char N[100];
        fin.getline(N, 20);
        stringstream ss(N);
        ss >> symbole;
        ss >> index1;
        ss >> step;
    
//        cin >> symbole;
        if (symbole == "End")
        {
            break;
        }
        else{

        
//            cin >> index1 >> step;
            index1--;
            block x(symbole);
            x.y1 += index1;
            x.y2 += index1;
            x.y3 += index1;
            x.y4 += index1;
            x.x1 -= 1;
            x.x2 -= 1;
            x.x3 -= 1;
            x.x4 -= 1;
            x.y1 -= 1;
            x.y2 -= 1;
            x.y3 -= 1;
            x.y4 -= 1;
            falling(x);
            
            
          
           
        }
    }

    // output
     ofstream cout("107062181_proj1.final");
            for (int i = 4; i < row + 4; ++i)
                      {
                          for (int j = 0; j < col; ++j)
                          {
                              cout << board[i][j] << " \n"[j == col - 1];
                          }
                          
                      }
     fin.close();
    return 0;
}
