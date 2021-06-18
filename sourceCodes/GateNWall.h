#ifndef __GATE__
#define __GATE__

#include <vector>
#include "Object.h"

using namespace std;

//---------����Ʈ Ŭ����------------ 
class GateNWall
{
    protected:
        int height;
        int width;
        
    public:
        Object gate1;
        Object gate2;
        bool gateOpen=false; 

        //�ⱸ�� ���ϱ� ���� ������
        int exitOfGate[4][2] ={{-1,0},{0,1},{1,0},{0,-1}};
        int idxForFind=0;

        vector <Object> walls; //���� ��� ���� 

        //������
        GateNWall(Object**& m ,int h=30, int w= 24):height(h),width(w)
        {
            fillWalls(m);
            selectGate(m);
            // debugging(m);
        }
        // walls ���͸� �ʿ��� �Ϲ� ���� ������Ʈ�� ä��
        void fillWalls(Object**& m)
        {
            walls.clear();
            
            for (int j=0;j<height;j++){
                for (int i=0;i<width;i++)
                {
                    if (m[j][i].getTN()==2){walls.push_back(m[j][i]);}
                }
            }
        }
        // //for debugging
        // void debugging(Object**& m)
        // {
        //     gate1 = Gate(0,5);
        //     gate2 = Gate(0,6);
        //     m[0][5]=gate1;
        //     m[0][6]=gate2;
        // }
        //����Ʈ ����
        void selectGate(Object** & m)
        {
            //���� ���� ����Ʈ�� ������ ����
            restore(m);
             // ����Ʈ�� �ε��� �̱� (2��)
            int randIdx1,randIdx2;
            do
            {
                srand((unsigned int)time(NULL));
                randIdx1=rand()%(walls.size());
                srand((unsigned int)time(NULL)*-1);
                randIdx2=rand()%(walls.size());
            } 
            while (randIdx1==randIdx2);
            
            Object temp1 = walls[randIdx1];
            Object temp2 = walls[randIdx2];

            m[temp1.getY()][temp1.getX()] = Gate(temp1.getY(),temp1.getX());
            m[temp2.getY()][temp2.getX()] = Gate(temp2.getY(),temp2.getX());

            gate1 = m[temp1.getY()][temp1.getX()];
            gate2 = m[temp2.getY()][temp2.getX()];

            gateOpen=true;

            // walls[randIdx1]= 
        }
        //����Ʈ �ǵ�����
        void restore(Object**& m)
        {
            if (gateOpen)
            {
                m[gate1.getY()][gate1.getX()] = NormalWall(gate1.getY(),gate1.getX());
                m[gate2.getY()][gate2.getX()] = NormalWall(gate2.getY(),gate2.getX());
            }
        }
        //����Ʈ �ⱸ ��ǥ���ϱ�
        void setExit(Object**& m,Object& g,int& toY,int& toX)
        {
            int tempY;
            int tempX;
            // ���� ����Ʈ�� ���� �ε��� ���ϱ�
            for(int i=0;i<4;i++)
            {
                if (exitOfGate[i][0]== false && exitOfGate[i][1]) {idxForFind=i;break;} 
            }

             //�ð�������� Ž��
            for (int i=0;i<4;i++)
            {
                tempY= g.getY()+exitOfGate[idxForFind][0],  
                tempX= g.getX()+exitOfGate[idxForFind][1]; // ���� ����Ʈ�� ��ġ���� �ð�������� ã��
				// �ش���ǥ�� ������̶��, ����Ʈ�� �ⱸ��
                if (0<=tempY &&tempY<height&& 0<tempX &&tempX< width) // �ð�������� Ȯ���ϴ� ��ǥ�� �� ���� �ƴϾ����
                {
                    if (m[tempY][tempX].getTN()==1){break;}   //���� �ⱸ����Ʈ�� ����� ������ ���������� ����
                }
                ++idxForFind%=4;
            }
            int retToY = exitOfGate[idxForFind][0];
            int retToX = exitOfGate[idxForFind][1];

            toY=retToY;
            toX=retToX;
        }

};

#endif