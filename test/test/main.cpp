#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;

int grid[45][45] = {{0}};

int ind, row, col, dir;
string symbole;
int flag, flag2;


class blocks
{
public:
    int x_1, x_2, x_3, x_4;
    int y_1, y_2, y_3, y_4;
    blocks(string block)
    {
        if (block == "T1")
        {
            x_1 = 3; y_1 = 1;
            x_2 = 3; y_2 = 2;
            x_3 = 3; y_3 = 3;
            x_4 = 4; y_4 = 2;
        }
        else if (block == "T2")
        {
            x_1 = 3; y_1 = 1;
            x_2 = 3; y_2 = 2;
            x_3 = 2; y_3 = 2;
            x_4 = 4; y_4 = 2;
        }
        else if (block == "T3")
        {
            x_1 = 3; y_1 = 2;
            x_2 = 4; y_2 = 1;
            x_3 = 4; y_3 = 2;
            x_4 = 4; y_4 = 3;
        }
        else if (block == "T4")
        {
            x_1 = 2; y_1 = 1;
            x_2 = 3; y_2 = 1;
            x_3 = 3; y_3 = 2;
            x_4 = 4; y_4 = 1;
        }
        else if (block == "L1")
        {
            x_1 = 2; y_1 = 1;
            x_2 = 3; y_2 = 1;
            x_3 = 4; y_3 = 1;
            x_4 = 4; y_4 = 2;
        }
        else if (block == "L2")
        {
            x_1 = 3; y_1 = 1;
            x_2 = 3; y_2 = 2;
            x_3 = 3; y_3 = 3;
            x_4 = 4; y_4 = 1;
        }
        else if (block == "L3")
        {
            x_1 = 2; y_1 = 1;
            x_2 = 2; y_2 = 2;
            x_3 = 3; y_3 = 2;
            x_4 = 4; y_4 = 2;
        }
        else if (block == "L4")
        {
            x_1 = 3; y_1 = 3;
            x_2 = 4; y_2 = 1;
            x_3 = 4; y_3 = 2;
            x_4 = 4; y_4 = 3;
        }
        else if (block == "J1")
        {
            x_1 = 2; y_1 = 2;
            x_2 = 3; y_2 = 2;
            x_3 = 4; y_3 = 1;
            x_4 = 4; y_4 = 2;
        }
        else if (block == "J2")
        {
            x_1 = 3; y_1 = 1;
            x_2 = 4; y_2 = 1;
            x_3 = 4; y_3 = 2;
            x_4 = 4; y_4 = 3;
        }
        else if (block == "J3")
        {
            x_1 = 2; y_1 = 1;
            x_2 = 2; y_2 = 2;
            x_3 = 3; y_3 = 1;
            x_4 = 4; y_4 = 1;
        }
        else if (block == "J4")
        {
            x_1 = 3; y_1 = 1;
            x_2 = 3; y_2 = 2;
            x_3 = 3; y_3 = 3;
            x_4 = 4; y_4 = 3;
        }
        else if (block == "S1")
        {
            x_1 = 3; y_1 = 2;
            x_2 = 3; y_2 = 3;
            x_3 = 4; y_3 = 1;
            x_4 = 4; y_4 = 2;
        }
        else if (block == "S2")
        {
            x_1 = 2; y_1 = 1;
            x_2 = 3; y_2 = 1;
            x_3 = 3; y_3 = 2;
            x_4 = 4; y_4 = 2;
        }
        else if (block == "Z1")
        {
            x_1 = 3; y_1 = 1;
            x_2 = 3; y_2 = 2;
            x_3 = 4; y_3 = 2;
            x_4 = 4; y_4 = 3;
        }
        else if (block == "Z2")
        {
            x_1 = 2; y_1 = 2;
            x_2 = 3; y_2 = 1;
            x_3 = 3; y_3 = 2;
            x_4 = 4; y_4 = 1;
        }
        else if (block == "I1")
        {
            x_1 = 1; y_1 = 1;
            x_2 = 2; y_2 = 1;
            x_3 = 3; y_3 = 1;
            x_4 = 4; y_4 = 1;
        }
        else if (block == "I2")
        {
            x_1 = 4; y_1 = 1;
            x_2 = 4; y_2 = 2;
            x_3 = 4; y_3 = 3;
            x_4 = 4; y_4 = 4;
        }
        else if (block == "O")
        {
            x_1 = 3; y_1 = 1;
            x_2 = 3; y_2 = 2;
            x_3 = 4; y_3 = 1;
            x_4 = 4; y_4 = 2;
        }
    }
};


void startFalling(blocks &block);
int checkValidity( blocks &block);
void shiftingPos(blocks &block, int dir);
void updateBoard(blocks &block);




void startFalling(blocks& block)
{
    if (flag)
    {
        for (int i = 4; i < row + 400; i++)
        {
            block.x_1 += 1;

            block.x_2 += 1;

            block.x_3 += 1;

            block.x_4 += 1;
            int num = checkValidity(block);
            if( num==-1){
                block.x_1 -= 1;
                
                block.x_2 -= 1;
                
                block.x_3 -= 1;
                
                block.x_4 -= 1;
                break;
            }
            if(num==2){
                break;
            }
            
          }
    
        shiftingPos(block, dir);
        
        for (int i = 4; i < row + 400; i++)
               {
                   if(block.x_4 + 1 >= row+4){
                       break;
                   }
                   block.x_1 += 1;

                   block.x_2 += 1;

                   block.x_3 += 1;

                   block.x_4 += 1;
                   int num = checkValidity(block);
                   if( num==-1){
                       block.x_1 -= 1;
                       
                       block.x_2 -= 1;
                       
                       block.x_3 -= 1;
                       
                       block.x_4 -= 1;
                       break;
                   }
                   if(num==2){
                       break;
                   }
                   
                 }
        updateBoard(block);
       
    }
    
    
}

void updateBoard(blocks &block)
{
    grid[block.x_1][block.y_1] = 1;
    grid[block.x_2][block.y_2] = 1;
    grid[block.x_3][block.y_3] = 1;
    grid[block.x_4][block.y_4] = 1;

    for (int i = 4; i < row + 4; i++)
    {
        flag2=1;
        for (int j = 0; j < col; j++)
        {

            if (grid[i][j] == 0)
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
                    grid[k][j] = 0;
                    grid[k][j] = grid[k-1][j];
                }
              
            }
        }
    }

    

}



int checkValidity(blocks &block)
{

    if ((grid[block.x_1][block.y_1] || grid[block.x_2][block.y_2] || grid[block.x_3][block.y_3] || grid[block.x_4][block.y_4]))
    {

        return -1;
    }

    else if (block.x_1 ==row+3 || block.x_2==row+3 || block.x_3==row+3 || block.x_4 == row + 3)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

void shiftingPos(blocks &block, int dir)
{
    block.y_1 += dir;
    block.y_2 += dir;
    block.y_3 += dir;
    block.y_4 += dir;
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
    
    int i_1 =0;
    while (i_1<row+4) {
        int j =0;
        while (j<col) {
            grid[i_1][j] = 0;
            ++j;
        }
        ++i_1;
    }
    


    while (!fin.eof())
//    while(1)
    {
        char N[100];
        fin.getline(N, 20);
        stringstream ss(N);
        ss >> symbole;
        ss >> ind;
        ss >> dir;
    
        cin >> symbole;
        if (symbole == "End")
        {
            break;
        }
        else{

        
//            cin >> ind >> dir;
            ind--;
            blocks x(symbole);
            x.y_1 = x.y_1 + ind;
            x.y_2 = x.y_2 + ind;
            x.y_3 = x.y_3 + ind;
            x.y_4 = x.y_4 + ind;
            x.x_1 = x.x_1 - 1;
            x.x_2 = x.x_2 - 1;
            x.x_3 = x.x_3 - 1;
            x.x_4 = x.x_4 - 1;
            x.y_1 = x.y_1 - 1;
            x.y_2 = x.y_2 - 1;
            x.y_3 = x.y_3 - 1;
            x.y_4 = x.y_4 - 1;
            startFalling(x);
            
            
          
           
        }
    }

   
     ofstream cout("107062181_proj1.final");
    int i=4;
       while (i<row+4) {
           int j=0;
           while (j<col) {
               cout << grid[i][j] << " \n"[j == col - 1];
               ++j;
           }
           ++i;
       }
            
     fin.close();
    return 0;
}
