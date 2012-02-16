#include<iostream>

using namespace std;

void copyarray(int x[], int y[])
{    
    for(int w=1; w<10; w++)
    x[w]=y[w];
}

void copyarray2(int x[][10], int y[][10])
{    
    for(int w=1; w<10; w++)
    {
        for(int u=1; u<10; u++)
        {
            x[w][u]=y[w][u];
        }
    }
}

main()
{
    void copyarray(int[], int[]);
    int a[10][10], i, h=0, n=0, y, l=0, m=0, j, k, x, p, q, r, o[10][10][10], c, d, e, f=0, g, b[10];
    int z[10][10], z1[10][10], z2[10][10], z3[10][10], z4[10][10], z5[10][10], z6[10][10], z7[10][10], z8[10][10], z9[10][10];
    
    
//entering sudoku
    cout<<"\n"<<"Enter the sudoku to be solved. Enter the blank spaces as 0"<<"\n";
    
    for(i=1; i<10; i++)
    {
        for (j=1; j<10; j++)
        {
            m++;
            cin>>a[i][j];
        }
    }
    
//displaying entered sudoku
    cout<<"\n"<<"The sudoku you entered is : "<<"\n";
    
    for(i=1; i<10; i++)
    {
        for(j=1; j<10; j++)
        {
            m++;
            cout<<"   "<<a[i][j];
        }
        cout<<"\n";
    }
    
start:

//boxes
    int b1[10]={0,a[1][1], a[1][2], a[1][3], a[2][1], a[2][2], a[2][3], a[3][1], a[3][2], a[3][3]};
    int b2[10]={0,a[1][4], a[1][5], a[1][6], a[2][4], a[2][5], a[2][6], a[3][4], a[3][5], a[3][6]};
    int b3[10]={0,a[1][7], a[1][8], a[1][9], a[2][7], a[2][8], a[2][9], a[3][7], a[3][8], a[3][9]};
    int b4[10]={0,a[4][1], a[4][2], a[4][3], a[5][1], a[5][2], a[5][3], a[6][1], a[6][2], a[6][3]};
    int b5[10]={0,a[4][4], a[4][5], a[4][6], a[5][4], a[5][5], a[5][6], a[6][4], a[6][5], a[6][6]};
    int b6[10]={0,a[4][7], a[4][8], a[4][9], a[5][7], a[5][8], a[5][9], a[6][7], a[6][8], a[6][9]};
    int b7[10]={0,a[7][1], a[7][2], a[7][3], a[8][1], a[8][2], a[8][3], a[9][1], a[9][2], a[9][3]};
    int b8[10]={0,a[7][4], a[7][5], a[7][6], a[8][4], a[8][5], a[8][6], a[9][4], a[9][5], a[9][6]};
    int b9[10]={0,a[7][7], a[7][8], a[7][9], a[8][7], a[8][8], a[8][9], a[9][7], a[9][8], a[9][9]};



//initialising o - the array stuff
    for(c=1; c<10; c++)
    {
        for (d=1; d<10; d++)
        {
            for(e=1; e<10; e++)
            {
                m++;
                o[c][d][e]=0;
            }
        }
    }
    


//conditions and array making stuff
    for(i=1; i<10; i++)
    {

        for(j=1; j<10; j++)
        {

            
            if (a[i][j]==0)
            {

                                           
                for(k=1; k<10; k++)
                {
                    m++;
                    p=1;
                    q=1;
                    r=1;

                
                    //vertical
                    for(x=1; x<10&&p!=0; x++)
                    {

                        m++;
                        if (a[x][j]==k)
                        p=0;
                    }
                    

                    
                    //horizontal
                    
                    
                    for(x=1; x<10&&q!=0; x++)
                    {

                        m++;
                        if(a[i][x]==k)
                        q=0;                        
                    }
                    

                    
                    //box
                    //choosing the box to be checked
                    if (i<4)
                    {
                        if (j<4)
                        {
                            copyarray(b,b1);
                            
                        }
                        else 
                        { if (j>3&&j<7)
                          {
                                copyarray(b,b2);
                                
                            }
                        
                            
                          else
                          {
                                copyarray(b,b3);
                                
                            }
                        }
                    }
                    else
                    {
                        if (i>3&&i<7)
                        {
                           if (j<4)
                           {
                                copyarray(b,b4);
                                
                            }
                           else 
                           { if (j>3&&j<7)
                             {
                                    copyarray(b,b5);
                                    
                                }
                             else
                             {
                                    copyarray(b,b6);
                                    
                                }
                           }
                        }
                        else
                        {
                            if (j<4)
                            {
                                copyarray(b,b7);
                                
                            }
                            else 
                            { if (j>3&&j<7)
                            {
                                copyarray(b,b8);
                                
                            }
                            else
                            {
                                copyarray(b,b9);
                                
                            }
                            }
                        }
                    }
                    
                                       
                    //checking in the box
                    
                    for(x=1; x<10&&r!=0; x++)
                    {

                        m++;
                        if(b[x]==k)
                        r=0;
                    }
                    

                    //arraying the possible number               
                    
                    if (p*q*r==1)
                    o[i][j][k]=k;   
                    
                }
                
            }
        }
    }


//assgn 1
for(i=1; i<10; i++)
{
       for(k=1; k<10; k++)
       {
            f=0;
            for(j=1; j<10; j++)
            {
                m++;
                if (o[i][j][k]==k)
                f++;
            }
            
            if (f==1)
            {
                for(j=1; j<10; j++)
                {
                    if (o[i][j][k]==k)
                    {
                        m++;
                        a[i][j]=k;
                        l++;
                        goto start;
                    }
                }
            }
        }
    }


//assgn 2
for(j=1; j<10; j++)
{
       for(k=1; k<10; k++)
       {
            f=0;
            for(i=1; i<10; i++)
            {
                m++;
                if (o[i][j][k]==k)
                f++;
            }
            
            if (f==1)
            {
                for(i=1; i<10; i++)
                {
                    if (o[i][j][k]==k)
                    {
                        m++;
                        a[i][j]=k;
                        l++;
                        goto start;
                    }
                }
            }
        }
    }



//assgn 3

for(x=1; x<10; x++)
    {
        m++;
        z1[1][x]=o[1][1][x];
        z1[2][x]=o[1][2][x];
        z1[3][x]=o[1][3][x];
        z1[4][x]=o[2][1][x];
        z1[5][x]=o[2][2][x];
        z1[6][x]=o[2][3][x];
        z1[7][x]=o[3][1][x];
        z1[8][x]=o[3][2][x];
        z1[9][x]=o[3][3][x];
        z2[1][x]=o[1][4][x];
        z2[2][x]=o[1][5][x];
        z2[3][x]=o[1][6][x];
        z2[4][x]=o[2][4][x];
        z2[5][x]=o[2][5][x];
        z2[6][x]=o[2][6][x];
        z2[7][x]=o[3][4][x];
        z2[8][x]=o[3][5][x];
        z2[9][x]=o[3][6][x];
        z3[1][x]=o[1][7][x];
        z3[2][x]=o[1][8][x];
        z3[3][x]=o[1][9][x];
        z3[4][x]=o[2][7][x];
        z3[5][x]=o[2][8][x];
        z3[6][x]=o[2][9][x];
        z3[7][x]=o[3][7][x];
        z3[8][x]=o[3][8][x];
        z3[9][x]=o[3][9][x];
        z4[1][x]=o[4][1][x];
        z4[2][x]=o[4][2][x];
        z4[3][x]=o[4][3][x];
        z4[4][x]=o[5][1][x];
        z4[5][x]=o[5][2][x];
        z4[6][x]=o[5][3][x];
        z4[7][x]=o[6][1][x];
        z4[8][x]=o[6][2][x];
        z4[9][x]=o[6][3][x];
        z5[1][x]=o[4][4][x];
        z5[2][x]=o[4][5][x];
        z5[3][x]=o[4][6][x];
        z5[4][x]=o[5][4][x];
        z5[5][x]=o[5][5][x];
        z5[6][x]=o[5][6][x];
        z5[7][x]=o[6][4][x];
        z5[8][x]=o[6][5][x];
        z5[9][x]=o[6][6][x];
        z6[1][x]=o[4][7][x];
        z6[2][x]=o[4][8][x];
        z6[3][x]=o[4][9][x];
        z6[4][x]=o[5][7][x];
        z6[5][x]=o[5][8][x];
        z6[6][x]=o[5][9][x];
        z6[7][x]=o[6][7][x];
        z6[8][x]=o[6][8][x];
        z6[9][x]=o[6][9][x];
        z7[1][x]=o[7][1][x];
        z7[2][x]=o[7][2][x];
        z7[3][x]=o[7][3][x];
        z7[4][x]=o[8][1][x];
        z7[5][x]=o[8][2][x];
        z7[6][x]=o[8][3][x];
        z7[7][x]=o[9][1][x];
        z7[8][x]=o[9][2][x];
        z7[9][x]=o[9][3][x];
        z8[1][x]=o[7][4][x];
        z8[2][x]=o[7][5][x];
        z8[3][x]=o[7][6][x];
        z8[4][x]=o[8][4][x];
        z8[5][x]=o[8][5][x];
        z8[6][x]=o[8][6][x];
        z8[7][x]=o[9][4][x];
        z8[8][x]=o[9][5][x];
        z8[9][x]=o[9][6][x];
        z9[1][x]=o[7][7][x];
        z9[2][x]=o[7][8][x];
        z9[3][x]=o[7][9][x];
        z9[4][x]=o[8][7][x];
        z9[5][x]=o[8][8][x];
        z9[6][x]=o[8][9][x];
        z9[7][x]=o[9][7][x];
        z9[8][x]=o[9][8][x];
        z9[9][x]=o[9][9][x];
    }

for(i=1; i<10; i++)
{
    for(j=1; j<10; j++)
    {
        m++;
        if (i<4)
                    {
                        if (j<4)
                        {
                            copyarray2(z,z1);
                            
                        }
                        else 
                        { if (j>3&&j<7)
                          {
                                copyarray2(z,z2);
                                
                            }
                        
                            
                          else
                          {
                                copyarray2(z,z3);
                                
                            }
                        }
                    }
                    else
                    {
                        if (i>3&&i<7)
                        {
                           if (j<4)
                           {
                                copyarray2(z,z4);
                                
                            }
                           else 
                           { if (j>3&&j<7)
                             {
                                    copyarray2(z,z5);
                                    
                                }
                             else
                             {
                                    copyarray2(z,z6);
                                    
                                }
                           }
                        }
                        else
                        {
                            if (j<4)
                            {
                                copyarray2(z,z7);
                                
                            }
                            else 
                            { if (j>3&&j<7)
                            {
                                copyarray2(z,z8);
                                
                            }
                            else
                            {
                                copyarray2(z,z9);
                                
                            }
                            }
                        }
                    }
        for(k=1; k<10; k++)
        {
            f=0;
            for(x=1; x<10; x++)
            {
                m++;
                if(o[i][j][k]==z[x][k])
                f++;
            }
            
            if(f==1)
            {
                a[i][j]=k;
                l++;
                goto start;
            }
        }
    }
}

//assign 4


for(i=1; i<10; i++)
{
    for(j=1; j<10; j++)
    {
        if(a[i][j]==0)
        {
	    n=0;
            for(x=1; x<10; x++)
            {
                    
                m++;
                if (o[i][j][x]!=0)
                {
                        h=x;
                        n++;
                    }
                }
                    
                    if (n==1)
                    {
                        a[i][j]=h;
                        
                        goto start;
                    }
                
            }
        }
    }
 



//final output
    cout<<"The solved sudoku is : "<<"\n";
    for(i=1; i<10; i++)
    {
        for(j=1; j<10; j++)
        {
            cout<<"   "<<a[i][j];
        }
        cout<<"\n";
    }

cout<<" l = "<<l<<" m = "<<m<<"\n";


}

