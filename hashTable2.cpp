#include<iostream>
#include<stdio.h>
#define MAX 17

using namespace std;

int table[MAX];
// HASH TABLE USING QUADRATIC PROBING
/* Insert the following keys into an array of size 17:
94, 37, 29, 40, 84, 88, 102, 63, 67, 120, 122
*/
void insertKey(int);
int h(int);
int QP(int, int);
void display();


int main(void)
{
        
        int keys[]={94, 37, 29, 40, 84, 88, 102, 63, 67, 120, 122};
        for(int i=0; i<11; i++)
                insertKey(keys[i]);
        
        display();
        
        return 0;
}

void insertKey(int k)
{
        int index;
        index=h(k);
        if(table[index]!=0)
        {
                cout<<"collision index: "<<index<<"\n";
                index=QP(k, 0);
                if(index==-1)
                {
                        cout<<"\n\nTHE HASH TABLE IS FULL!!!!\n\n";
                        return;
                }
                cout<<"resolved index: "<<index<<"\n\n\n";
                table[index]=k;
        }
        
        else
        {
                table[index]=k;
        }
        
}

int h(int k){ return k%MAX;}

int QP(int k, int i)
{
        int index;
        for(; i<MAX; i++)
        {
                index=(h(k)+(i*i))%MAX;
                if(table[index]==0)
                        break;
        }
        
        if(table[index]!=0)
                return -1;
        return index;
}

void display()
{
        for(int i=0; i<MAX; i++)
                cout<<"["<<i<<"] "<<table[i]<<endl;
}
