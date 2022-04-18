#include<iostream>
#include<stdlib.h>
#define MAX 17

int table[MAX];

using namespace std;

// HASH TABLE USING LINEAR PROBING
/* Insert the following keys into an array of size 17:
94, 37, 29, 40, 84, 88, 102, 63, 67, 120, 122
*/
void insertKey(int);
int h(int);
int LP(int, int);
void display();
int main(void)
{
        int keys[]={94, 37, 29, 40, 84, 88, 102, 63, 67, 120, 122};
        
        for(int i=0; i<11; i++)
        {
                insertKey(keys[i]);
        }
        
        display();
        
        return 0;
}

void insertKey(int key)
{
        int index;
        index=h(key);
        if(table[index]!=0)
        {
                cout<<"\n\ncollision at index: "<<index<<endl;
                index=LP(key, 0);
                cout<<"\n\nresolved index: "<<index<<endl;
                table[index]=key;
        }
        
        else
        {
                table[index]=key;
        }
        
}


int LP(int k, int i)
{
        int index;
        for(; i<MAX; i++)
        {
                index=(h(k)+i)%MAX;
                if(table[index]==0)
                        break;
        }
        
        if(table[index]!=0) // no index was empty!!!
                return -1;
        return index;
}

int h(int key)
{
        return key%MAX;
}

void display()
{
        for(int i=0; i<MAX; i++)
                cout<<"["<<i<<"] "<<table[i]<<"\n";
        
}
