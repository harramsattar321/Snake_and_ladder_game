#
#include<iostream>

#include<windows.h>

using namespace std;

#include<conio.h>
#include<fstream>



void gotoRowCol(int rpos, int cpos)

{

int xpos=cpos, ypos = rpos;

COORD scrn;

HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

scrn.X = cpos;

scrn.Y = rpos;

SetConsoleCursorPosition(hOuput, scrn);

}
void init(int i_rows,char & player1,char & player2)
{

    gotoRowCol(8,42);
    cout<<"WELCOME TO SNAKE LADDER GAME";
    gotoRowCol(13,20);
    cout<<"Player1 : "<<player1<<"        Player2 : " <<player2;
    gotoRowCol(i_rows,115);
    cout<<"THERE ARE 2 SNAKES IN THIS GAME";
    gotoRowCol(i_rows+1,120);
    cout<<"1. From 98 to 09";
    gotoRowCol(i_rows+2,120);
    cout<<"2. From 56 to 33";
    gotoRowCol(i_rows+3,115);
    cout<<"THERE ARE 2 LADDERS IN THIS GAME";
    gotoRowCol(i_rows+4,120);
    cout<<"1. From 23 to 81";
    gotoRowCol(i_rows+5,120);
    cout<<"2. From 44 to 68";
     gotoRowCol(i_rows+25,120);
    cout<<"Press A for exit";
    gotoRowCol(21,36);
    cout<<"S_S1"<<endl;
    gotoRowCol(85,28);
    cout<<"E_S1"<<endl;
    gotoRowCol(49,52);
    cout<<"S_S2"<<endl;
    gotoRowCol(63,76);
    cout<<"E_S2"<<endl;
    gotoRowCol(70,76);
    cout<<"S_L1"<<endl;
    gotoRowCol(28,93);
    cout<<"E_L1"<<endl;
    gotoRowCol(56,68);
    cout<<"S_L2"<<endl;
    gotoRowCol(42,36);
    cout<<"E_L2"<<endl;


}

void sleep(int m)

{

for(int j=0;j<m*21000;j++)

{

}

}
int rolldice()
{

    int d;
    while(!kbhit())
    {
        gotoRowCol(31,120);
     d=(rand() % 6)+1;
     cout<<d;

    }
    getch();
    return d;
}
void draw_horizontal(int rows,int cols,int c_dim,char ch)
{
    for(int i=cols;i<c_dim;i++)
    {
        gotoRowCol(rows,i);
        cout<<ch;
    }
}
void draw_vertical(int rows,int r_dim,int cols,char ch)
{
    for(int i=rows;i<r_dim;i++)
    {
        gotoRowCol(i,cols);
        cout<<ch;
    }
}
void print_square(int rows,int cols,int r_dim,int c_dim,char ch)
{
    draw_horizontal(rows,cols,c_dim,ch);
    draw_vertical(rows,r_dim,c_dim,ch);
    draw_horizontal(r_dim,cols,c_dim,ch);
    draw_vertical(rows,r_dim,cols,ch);

}
void   print_cols(int rows,int cols,int r_dim,int c_dim,char ch)
{
    int d=cols+c_dim;
    int e=c_dim+c_dim;
    for(int j=1;j<11;j++)
      {
        d=d+c_dim-1;
        e=e+c_dim-1;
        print_square(rows,d,r_dim,e,ch);
      }

}
void print_cols_in(int i_rows,int i_cols,int r_dim,int c_dim,int n)
{
     for(int j=1;j<11;j++)
      {
        gotoRowCol(i_rows,i_cols);
        cout<<n;
        n --;
        i_cols=i_cols+8;
      }
}
void   print_box(int rows,int cols,int r_dim,int c_dim,char ch)
{
    int f=rows+r_dim;
    int g=r_dim+r_dim;
    for(int j=1;j<11;j++)
      {
        f=f+r_dim-1;
        g=g+r_dim-1;
        print_cols(f,cols,g,c_dim,ch);
      }

}
void print_box_in(int i_rows,int i_cols,int r_dim,int c_dim,int n)
{
     for(int i=1;i<=10;i++)
    {
        gotoRowCol(i_rows,i_cols);
        print_cols_in(i_rows,i_cols,r_dim, c_dim, n);
        n=n-10;
        i_rows=i_rows+7;
    }
}
void print_board(int rows,int cols,int  r_dim,int c_dim,char ch,int i_rows,int i_cols,int n,char & player1,char &  player2)
{

    init(i_rows,player1,player2);
    print_box(rows,cols, r_dim, c_dim, ch);
    print_box_in(i_rows,i_cols,r_dim, c_dim, n);

}
int set_value(int  a)
{
    if(a>=74 && a<=81)
    {
        return 80;
    }
    if(a>=66 && a<=73)
    {
        return 72;
    }
    if(a>=58 && a<=65)
    {
        return 64;
    }
    if(a>=50 && a<=57)
    {
        return 56;
    }
    if(a>=42 && a<=49)
    {
        return 48;
    }
    if(a>=34 && a<=41)
    {
        return 40;
    }
    if(a>=26 && a<=33)
    {
        return 32;
    }
    if(a>=17 && a<=25)
    {
        return 24;
    }
    if(a>=74 && a<=81)
    {
        return 88;
    }
    if(a>=74 && a<=81)
    {
        return 97;
    }
}
void player_1(int & t1,int c_dim,int & x1,int & y1,char & p1,int & sum,int & e)
{
    int h=0,h1=0,n=0,m=0,c=x1,p=y1,score1=sum;
    if(t1==1)
       {
           gotoRowCol(30,120);
           cout<<"Player one turn"<<endl;
           gotoRowCol(31,120);
           h=rolldice();
           int z=getch();
           if(z=='A')
           {
               exit(2);
           }
           if(h==6)
           {

              t1 ++;
              h=0;
              h1=0;
              sleep(10000);
              do
              {
                    h1=h+h1;
                    if(h1==18)
                    {
                        break;
                    }
                    gotoRowCol(30,120);
                    cout<<"Player one turn"<<endl;
                    gotoRowCol(31,120);
                    h=rolldice();
                    int z=getch();
                    if(z=='A')
                    {
                        exit(2);
                    }
                    sleep(10000);
              }
              while(h==6);
              h1=h+h1;
              sum=sum+h1;
               n=0,m=0;
              if(h1<18)
              {
                  int z=y1-(h1*c_dim);
                  int l=set_value(z);
                  if(l<24)
                  {
                      while(h1!=0)
                      {
                          y1=y1-c_dim;
                          if(y1<24)
                          {
                              y1=97;
                              x1-=7;
                              h1--;
                              n++;
                          }

                          h1--;
                          m++;
                      }
                      y1=set_value(y1);
                    }

                  else
                  {

                      while(h1!=0)
                      {
                          y1=y1-c_dim;
                          h1--;
                      }
                      y1=set_value(y1);

                  }
              }
              else
              {
                    gotoRowCol(31,120);
                    cout<<"3 times six comes"<<endl;
                    gotoRowCol(32,120);
                    cout<<"so,0 scores"<<endl;
                    sleep(5000);
                    gotoRowCol(31,120);
                    cout<<"                  "<<endl;
                    gotoRowCol(32,120);
                    cout<<"           "<<endl;
              }
              if(x1==17&&y1==40)
              {
                  gotoRowCol(80,32);
                  x1=80;
                  y1=32;
                  sum=9;
                  cout<<p1;
              }
              else if(x1==45&&y1==56)
              {
                  gotoRowCol(59,80);
                  x1=59;
                  y1=80;
                  sum=33;
                  cout<<p1;
              }
              else if(x1==66&&y1==80)
              {
                  gotoRowCol(24,97);
                  x1=24;
                  y1=97;
                  sum=81;
                  cout<<p1;
              }
              else if(x1==52&&y1==72)
              {
                  gotoRowCol(38,40);
                  x1=38;
                  y1=40;
                  sum=68;
                  cout<<p1;
              }
              else if(x1>=17)
              {
                  gotoRowCol(x1,y1);
                  cout<<p1;
              }
              else if(x1<17)
              {
                  x1=c;
                  y1=p;
                  gotoRowCol(x1,y1);
                  e ++;
                  cout<<p1;

              }



           }


       }
       else
       {
                do
              {
                    h1=h+h1;
                    if(h1==18)
                    {
                        break;
                    }
                    gotoRowCol(30,120);
                    cout<<"Player one turn"<<endl;
                    gotoRowCol(31,120);
                    h=rolldice();
                    int z=getch();
                    if(z=='A')
                    {
                        exit(2);
                    }
                    sleep(10000);
              }
              while(h==6);
              h1=h+h1;
              sum=sum+h1;
              n=0,m=0;
              if(h1<18)
              {
                  int z=y1-(h1*c_dim);
                  int l=set_value(z);
                  if(l<24)
                  {
                      while(h1!=0)
                      {
                          y1=y1-c_dim;
                          if(y1<24)
                          {
                              y1=97;
                              x1-=7;
                              h1--;
                              n++;
                          }

                          h1--;
                          m++;
                      }
                    y1=set_value(y1);
                  }


                  else
                  {
                      while(h1!=0)
                      {
                          y1=y1-c_dim;
                          h1--;
                      }
                        y1=set_value(y1);

                  }
              }
              else
              {
                    gotoRowCol(31,120);
                    cout<<"3 times six comes"<<endl;
                    gotoRowCol(32,120);
                    cout<<"so,0 scores"<<endl;
                    sleep(5000);
                    gotoRowCol(31,120);
                    cout<<"                  "<<endl;
                    gotoRowCol(32,120);
                    cout<<"           "<<endl;
              }
              if(x1==17&&y1==40)
              {
                  gotoRowCol(80,32);
                  x1=80;
                  y1=32;
                  sum=9;
                  cout<<p1;
              }
              else if(x1==45&&y1==56)
              {
                  gotoRowCol(59,80);
                  x1=59;
                  y1=80;
                  sum=33;
                  cout<<p1;
              }
              else if(x1==66&&y1==80)
              {
                  gotoRowCol(24,97);
                  x1=24;
                  y1=97;
                  sum=81;
                  cout<<p1;
              }
              else if(x1==52&&y1==72)
              {
                  gotoRowCol(38,40);
                  x1=38;
                  y1=40;
                  sum=68;
                  cout<<p1;
              }
              else if(x1>=17)
              {
                  gotoRowCol(x1,y1);
                  cout<<p1;
              }
              else if(x1<17)
              {
                  x1=c;
                  y1=p;
                  gotoRowCol(x1,y1);
                  e ++;
                  cout<<p1;

              }



           }

if(sum>100)
{
    sum=score1;
}
        gotoRowCol(35,120);
        cout<<"Player 1 position:"<<sum;
        if(x1==17 && y1==24)
        {
            //exit(2);
        }
       if(y1==24)
       {
           x1-=7;
           y1=106;
       }




    }
void player_2(int & t2,int c_dim,int & x2,int & y2,char & p2,int & sum2,int & f)
{
    int q=0,q1=0,n1=0,m1=0,c1=x2,p1=y2,score=sum2;
    if(t2==1)
       {
           gotoRowCol(30,120);
           cout<<"Player two turn"<<endl;
           gotoRowCol(31,120);
           q=rolldice();
           int z=getch();
           if(z=='A')
           {
               exit(2);
           }
           if(q==6)
           {
              t2 ++;
              q=0;
              q1=0;
              sleep(10000);
              do
              {
                    q1=q+q1;
                    if(q1==18)
                    {
                        break;
                    }
                    gotoRowCol(30,120);
                    cout<<"Player two turn"<<endl;
                    gotoRowCol(31,120);
                    q=rolldice();
                    int z=getch();
           if(z=='A')
           {
               exit(2);
           }
                    sleep(10000);
              }
              while(q==6);
              q1=q+q1;
              sum2=q1+sum2;
               n1=0,m1=0;
              if(q1<18)
              {
                  int z1=y2-(q1*c_dim);
                  int l1=set_value(z1);
                  if(l1<24)
                  {
                      while(q1!=0)
                      {
                          y2=y2-c_dim;
                          if(y2<24)
                          {
                              y2=97;
                              x2-=7;
                              q1--;
                              n1++;
                          }

                          q1--;
                          m1++;
                      }
                      y2=set_value(y2);
                    }

                  else
                  {

                      while(q1!=0)
                      {
                          y2=y2-c_dim;
                          q1--;
                      }
                      y2=set_value(y2);

                  }
              }
              else
              {
                    gotoRowCol(31,120);
                    cout<<"3 times six comes"<<endl;
                    gotoRowCol(32,120);
                    cout<<"so,0 scores"<<endl;
                    sleep(5000);
                    gotoRowCol(31,120);
                    cout<<"                  "<<endl;
                    gotoRowCol(32,120);
                    cout<<"           "<<endl;
              }
              if(x2==17&&y2==40)
              {
                  gotoRowCol(80,32-1);
                  x2=80;
                  y2=32;
                  sum2=9;
                  cout<<p2;
              }
              else if(x2==45&&y2==56)
              {
                  gotoRowCol(59,80-1);
                  x2=59;
                  y2=80;
                  sum2=33;
                  cout<<p2;
              }
              else if(x2==66&&y2==80)
              {
                  gotoRowCol(24,97-1);
                  x2=24;
                  y2=97;
                  sum2=81;
                  cout<<p2;
              }
              else if(x2==52&&y2==72)
              {
                  gotoRowCol(38,40-1);
                  x2=38;
                  y2=40;
                  sum2=68;
                  cout<<p2;
              }
              else if(x2>=17)
              {
                  gotoRowCol(x2,y2-1);
                  cout<<p2;
              }
              else if(x2<17)
              {
                  x2=c1;
                  y2=p1;
                  gotoRowCol(x2,y2-1);
                  f ++;
                  cout<<p2;

              }



           }


       }
       else
       {
                do
              {
                    q1=q+q1;
                    if(q1==18)
                    {
                        break;
                    }
                    gotoRowCol(30,120);
                    cout<<"Player two turn"<<endl;
                    gotoRowCol(31,120);
                    q=rolldice();
                    int z=getch();
           if(z=='A')
           {
               exit(2);
           }
                    sleep(10000);
              }
              while(q==6);
              q1=q+q1;
              sum2=sum2+q1;
              n1=0,m1=0;
              if(q1<18)
              {
                  int z1=y2-(q1*c_dim);
                  int l1=set_value(z1);
                  if(l1<24)
                  {
                      while(q1!=0)
                      {
                          y2=y2-c_dim;
                          if(y2<24)
                          {
                              y2=97;
                              x2-=7;
                              q1--;
                              n1++;
                          }

                          q1--;
                          m1++;
                      }
                    y2=set_value(y2);
                  }


                  else
                  {
                      while(q1!=0)
                      {
                          y2=y2-c_dim;
                          q1--;
                      }
                        y2=set_value(y2);

                  }
              }
              else
              {
                    gotoRowCol(31,120);
                    cout<<"3 times six comes"<<endl;
                    gotoRowCol(32,120);
                    cout<<"so,0 scores"<<endl;
                    sleep(5000);
                    gotoRowCol(31,120);
                    cout<<"                  "<<endl;
                    gotoRowCol(32,120);
                    cout<<"           "<<endl;
              }
              if(x2==17&&y2==40)
              {
                  gotoRowCol(80,32-1);
                  x2=80;
                  y2=32;
                  sum2=9;
                  cout<<p2;
              }
              else if(x2==45&&y2==56)
              {
                  gotoRowCol(59,80-1);
                  x2=59;
                  y2=80;
                  sum2=33;
                  cout<<p2;
              }
              else if(x2==66&&y2==80)
              {
                  gotoRowCol(24,97-1);
                  x2=24;
                  y2=97;
                  sum2=81;
                  cout<<p2;
              }
              else if(x2==52&&y2==72)
              {
                  gotoRowCol(38,40-1);
                  x2=38;
                  y2=40;
                  sum2=68;
                  cout<<p2;
              }
              else if(x2>=17)
              {
                  gotoRowCol(x2,y2-1);
                  cout<<p2;
              }
              else if(x2<17)
              {
                  x2=c1;
                  y2=p1;
                  gotoRowCol(x2,y2-1);
                  f ++;
                  cout<<p2;

              }



           }

if(sum2>100)
{
    sum2=score;
}
  gotoRowCol(36,120);
        cout<<"Player 2 position:"<<sum2;
        if(x2==17 && y2==24)
        {
            //exit(2);
        }
       if(y2==24)
       {
           x2-=7;
           y2=106;
       }





}

void change_turn(int & turn)
{
    if(turn==1)
    {
        turn=2;
    }
    else
    {
        turn=1;
    }
}
void erase_position(int turn,int x1,int y1,int x2,int y2,int & e,int & f)
{
    if(turn==1)
    {
        if(e==0)
        {
             if(y1==106)
            {
            x1+=7;
            y1=24;
            }
            gotoRowCol(x1,y1);
            cout<<" ";

        }
        else
        {
            e --;
        }

    }
    else
    {
        if(f==0)
        {
            if(y2==106)
        {
            x2+=7;
            y2=24;
        }
        gotoRowCol(x2,y2-1);
        cout<<" ";

        }
        else
        {
            f --;
        }

    }
}
void update_position(int & t1,int c_dim,int & x1,int & y1,char p1,int & t2,int & x2,int&  y2,char p2,int & turn,int & sum,int &sum2,int & e,int & f)
{
    if(turn==1)
    {
        player_1(t1,c_dim,x1,y1,p1,sum,e);
    }
    if(turn==2)
    {
        player_2(t2,c_dim,x2,y2,p2,sum2,f);
    }
}
void write(int & turn,int & x1,int & y1 ,int & x2,int & y2,int & t1,int & t2,int & sum,int & sum2)
{
    ofstream WW("game1_file.txt");
    WW<<turn<<endl;
    WW<<x1<<endl;
    WW<<y1<<endl;
    WW<<sum<<endl;
    WW<<t1<<endl;
    WW<<x2<<endl;
    WW<<y2<<endl;
    WW<<sum2<<endl;
    WW<<t2<<endl;


    WW.close();

}
void read(int & turn,int & x1,int & y1,int & sum,int & t1,int & x2,int & y2,int & sum2,int & t2)
{
    ifstream rr("game1_file.txt");
    rr>>turn;
    rr>>x1;
    rr>>y1;
    rr>>sum;
    rr>>t1;
    rr>>x2;
    rr>>y2;
    rr>>sum2;
    rr>>t2;

}
int main ()
{
    char a1,player1='@',player2='#';
    int turn,x1,y1,x2,y2,t1,t2,sum,sum2;
    cout<<"Press Any Key for new game except L/l"<<endl;
    cout<<"Press L/l for load game"<<endl;
    cin>>a1;
    system("CLS");
    if(a1=='L' || a1=='l')
    {
        turn,x1,y1,sum,t1,x2,y2,sum2,t2;
        read(turn,x1,y1,sum,t1,x2,y2,sum2,t2);
    }
    else
    {
        t1=1,x1=80,y1=106,t2=1,x2=80,y2=106,turn=1,sum=0,sum2=0;

    }
    int rows=0,cols=0,r_dim=8,c_dim=9,i_rows=r_dim/2+15,i_cols=c_dim/2+17,n1=100,e=0,f=0;
    char ch=219;
    print_board(rows,cols, r_dim, c_dim, ch,i_rows,i_cols,n1,player1,player2);
    do
    {
        int b_x1=x1,b_y1=y1,b_x2=x2,b_y2=y2;
        update_position(t1,c_dim,x1,y1,player1,t2,x2,y2,player2,turn,sum,sum2,e,f);
        sleep(10000);
        write(turn,x1,y1,x2,y2,t1,t2,sum,sum2);
        erase_position(turn,b_x1,b_y1,b_x2,b_y2,e,f);
        change_turn(turn);

        if(sum==100)
        {
            gotoRowCol(40,120);
            cout<<"player 1 wins";
            getch();
            break;
        }
        if(sum2==100)
        {
            gotoRowCol(40,120);
            cout<<"player 2 wins";
            getch();
            break;
        }
    }
    while(true);
    gotoRowCol(88,100);

}












