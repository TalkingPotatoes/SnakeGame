#include <vector>
#include "Object.h"
#include "GateNWall.h"
#include "Item.h"

using namespace std;

extern int mapWidth;
extern int mapHeight;
extern int gateUse;
extern void fail();

//----------------------�� Ŭ����------------------------------ 
class Snake
{
    int toX=-1;
    int toY=0;
    int nextY, nextX;
    
    public:
        int numBody=2;
        int onGate =0;
        int  tailY, tailX;
        vector <Object> s;
        
        Snake(Object**& m,int h=30,int w=24) : tailY(h/2), tailX(w/2)
        {
            //ó���� ���̰� 3�� �� ����
            Head head(tailY,tailX);
            m[tailY][tailX]= head;
            s.push_back(head);
            Body body(tailY,++tailX);
            m[tailY][tailX]= body;
            s.push_back(body);

            pushBody(m);
        }

        void Init(Object**& m)
        {
            while(numBody > 3) popBody(m);
            m[s[0].getY()][s[0].getX()].setTN(1);
            m[s[1].getY()][s[1].getX()].setTN(1);
            m[s[2].getY()][s[2].getX()].setTN(1);

            toY=0;
            toX=-1;

            s[0].setYX(mapWidth/2, mapHeight/2);
            s[1].setYX(mapWidth/2, mapHeight/2 + 1);
            s[2].setYX(mapWidth/2, mapHeight/2 + 1);
        }

        void setToY(int y){toY=y;}
        void setToX(int x){toX=x;}

        //����Ʈ ��������� ��Ÿ���� ���º��� ����
        void setOnGate(){onGate=numBody;}
        void decreaseOnGate(){if(onGate){onGate--;}}
        
        int getToY(){return toY;}
        int getToX(){return toX;}
        //�� ���� ����
        void pushBody(Object**& m)
        {
            //�𼭸����� ������ ���� �� �մ� ���� �ذ��ؾ��� **********************************���⼭
            int chaiY = s[numBody-1].getY()-s[numBody-2].getY();
            int chaiX = s[numBody-1].getX()-s[numBody-2].getX();
            tailY += chaiY;
            tailX += chaiX;
            Body tail(tailY,tailX);
            m[tailY][tailX] = tail;

            s.push_back(tail);
            numBody++;
        }
        //�� ���� ����
        void popBody(Object**& m)
        {
            m[s[numBody-1].getY()][s[numBody-1].getX()] = Space(s[numBody-1].getY(),s[numBody-1].getX());
            s.pop_back();
            numBody--;
            tailY = s[numBody-1].getY();
            tailX = s[numBody-1].getX();
        }
        // ���� ���� ��ġ ����(�ٷξ��� ������ ��ġ�� �̵���) (�Ӹ��� ����)
        void setBodyPos()
        {
            for (int i=numBody-1; i>0; i--)
            {
                s[i].setYX(s[i-1].getY(),s[i-1].getX());
            }
        }
        //�Ӹ���ġ����(next���� �����ϰ� �� ������ �̵�)
        void setHeadPos()
        {
            nextY = s[0].getY()+toY;
            nextX = s[0].getX()+toX;
            s[0].setYX(nextY,nextX);   
        }
        // ���� �̵�
        void move(Object**& m,Item& item, GateNWall& gnw)
        {
            setBodyPos();
            setHeadPos();
            
            // ������ ���������
            m[tailY][tailX]= Space(tailY,tailX); 
            //�׸��� ���� ��ǥ �ٽ�
            tailY = s[numBody-1].getY();
            tailX = s[numBody-1].getX();    
            
            // ������ ���� ���� ������,
            afterMove(m,item,gnw);            
            
            //��ȭ ����
            for (int i=0;i<numBody;i++)
            {
                m[s[i].getY()][s[i].getX()]= s[i];
            }
        }
        //�̵��� ���� ���� �ִ� ���
        void afterMove(Object**& m,Item& item,GateNWall& gnw)
        {
             //������
            for (int i=0;i<item.numItem;i++)
            { 
                Object obj = item.it[i];
                if ((obj.getY()==s[0].getY())&&(obj.getX()==s[0].getX())) // �Ӹ��� ��ǥ�� ������,
                {   
                     // ���� ����� ���� ��쵵 �������� **********************************************************************
                    if (obj.getTN()==6)  //�������� 
                    {
                        popBody(m);
                        item.eraseItem(obj.getY(),obj.getX()); // Ư�� ������ ����

                        // ���� ���̰� 2�̸� ����
                        if (s.size() == 2){
                            fail();
                        }

                    }
                    else if (obj.getTN()==7)  // ���������
                    {
                        pushBody(m);
                        item.eraseItem(obj.getY(),obj.getX());
                    }
                }
            }
            // �������� �ƴѰ�� 
            Object obj = m[s[0].getY()][s[0].getX()];//�� �Ӹ��� ���� ��ġ�� �ִ� ������Ʈ
            if (obj.getTN()==8) // ������Ʈ�� ����Ʈ��� 
            {
                setOnGate(); 

                if (obj.getY() == gnw.gate1.getY() && obj.getX() == gnw.gate1.getX()) //������Ʈ�� ����Ʈ1 �϶�  ����Ʈ 2�γ���
                {
                    gateUse++;
                    gnw.setExit(m,gnw.gate2,toY,toX);
                    s[0].setYX(gnw.gate2.getY()+toY,gnw.gate2.getX()+toX);
                }
                else //������Ʈ�� ����Ʈ 2�϶�
                {
                    gateUse++;
                    gnw.setExit(m,gnw.gate1,toY,toX);
                    s[0].setYX(gnw.gate1.getY()+toY,gnw.gate1.getX()+toX);
                }
            }
            else if (obj.getTN()==2 ||obj.getTN()==4) // ���� ��ų� ���뿡 ����� �� ����
            {
                fail();
            }
        }
};