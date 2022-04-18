#include<iostream>
#include<stdio.h>
#define MAX 7

// BUCKET HASHING!!!!
using namespace std;

int table[MAX][3];

void bucketHash(int);
int H(int);
void display();

int main(void)
{
        int keys[]={4895, 6559, 5912, 4047, 6766, 4390, 4640, 4900, 4411};
        
        for(int i=0; i<9; i++)
                bucketHash(keys[i]);
        
        display();
        
        return 0;
}

void bucketHash(int k)
{
        int index;
        static int i=0, prevIndex=0;
        // prevIndex stores the previous value of index so that it can be used for comparision with the new value of index

        if(i==3)
                i=0;
        index=H(k);
        
        if(index==prevIndex)
        {
                i=0;
                while(table[index][i]!=0)
                        i++;
                
                table[index][i]=k;
                if(i==3)
                        i=0;
        }
        
        else
        {
                i=0;
                while(table[index][i]!=0)
                        i++;
                table[index][i]=k;
                if(i==3)
                        i=0;
        }
        
        prevIndex=index;
}
        
int H(int k){ return k%MAX; }
void display()
{
        for(int i=0; i<MAX; i++)
        {
                cout<<"["<<i<<"]::: \n";
                for(int j=0; j<3; j++)
                        cout<<table[i][j]<<endl;
                cout<<"---\n";
        }
}
