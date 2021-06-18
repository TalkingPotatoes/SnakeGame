#ifndef __ITEM__
#define __ITEM__

#include <vector>
#include <time.h>
#include <random>
#include "Object.h"

using namespace std;

//-----------------------������ Ŭ����---------------- 
class Item
{
    protected:
        int height;
        int width;
    public:
        int numItem=0;
        vector <Object> it;

        Item(Object**& m, int h = 30, int w = 24): height(h), width(w) { }

        //�ʱ�ȭ �Լ�
        void Init(Object**& m)
        {
            while(numItem > 0) popItem(m);
        }
        // ������ ���� (�ð�����)
        void pushItem(Object**& m)
        {
             //���� y,x�� ���� (������̾���� ) ���ɸ��� ���⼭ while������ �׷���
            int randY, randX;
            do
            {
                srand((unsigned int)time(NULL));
                randY=rand()%(height-2)+1;
                randX=rand()%(width-2)+1;
            } while (m[randY][randX].getTN() != 1); // ������� ã�������� 
            
            //�� ���� ������� ����
			srand(time(NULL));
            int n = rand()%2; //50 %Ȯ��
            //�׸��� ������ ����
            Object item;
            if (n) {item = Apple(randY,randX);}
            else {item = Poison(randY,randX);}
            //���Ϳ� ����
            it.insert(it.begin(),item); 
            m[randY][randX] = item;
            numItem++;
        }
        // ���� ������ ������ ���� (�ð� �ʰ�, �������� Ŭ���� ��)
        void popItem(Object**& m)
        {
            Object item = it[numItem-1];
            it.pop_back();
            m[item.getY()][item.getX()]=Space(item.getY(),item.getX());
            numItem--;
        }
        // Ư�� ������ ����  (��� ���˽�)
        void eraseItem(int y,int x)
        {
            for (int i=0;i<numItem;i++)
            {
                if (it[i].getY()==y&&it[i].getX()==x)
                {
                    Object temp = it[i];
                    it.erase(it.begin()+i);
                    numItem--;
                }
            }
            
        }
};

#endif