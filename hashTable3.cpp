#include<stdio.h>
#include<iostream>
#define MAX 17

int table[MAX];

using namespace std;

void insertKey(int);
int h(int); // h(k)
int hdash(int); // h'(k)
int DH(int, int);
void display();

// HASH TABLES USING DOUBLE HASHING

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
                cout<<"collision index: "<<index<<endl;
                index=DH(k, 0); // has to be defined
                cout<<"resolved index: "<<index<<endl<<endl;
                table[index]=k;
        }
        
        else
        {
                table[index]=k;
        }
        
}

int h(int k){return k%MAX;}
int hdash(int k){return ((k%7)+1);}

int DH(int k, int i)
{
        int index;
        for(; i<MAX; i++)
        {
                index=(h(k)+i*hdash(k))%MAX;
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
