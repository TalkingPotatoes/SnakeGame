#ifndef __OBJ__
#define __OBJ__

// �� ������Ʈ�� �Ӽ��� ��� �θ� Ŭ���� (ȭ�鿡 ǥ�õ� ���簢�� �ϳ��ϳ��� ������Ʈ��)
class Object
{
    protected:
        int x,y;
        int typeNum;
        
    public:
        
        Object(int y=0, int x=0, int tn = 0):x(x), y(y) , typeNum(tn){}
        virtual ~Object(){}
        
        int getY() {return y;}
        int getX() {return x;}
        void setYX(int y,int x){this->y=y;this->x=x;}

        int getTN(){return typeNum;}

        void setTN(int typeNum) {this->typeNum = typeNum;}

};
// �����
class Space :public Object
{
    public:
        Space (int y, int x):Object(y,x,1){}

        ~Space(){}
};
// �Ϲݺ�
class NormalWall : public Object
{
    public:
        bool isGate=false;
        NormalWall (int y, int x):Object(y,x,2){}

        ~NormalWall(){}

};
// ������
class ImmueWall : public Object
{
    public:
        ImmueWall (int y, int x):Object(y,x,3){}

        ~ImmueWall(){}
};
// �� ����
class Body: public Object
{
    public:
        Body (int y, int x):Object(y,x,4){}

        ~Body(){}
};
// �� �Ӹ�
class Head : public Object
{     
    public:
        Head (int y, int x):Object(y,x,5){}

        ~Head(){}
};
// ��
class Poison : public Object
{
    public:
        Poison (int y, int x):Object(y,x,6){}

        ~Poison(){}
};
// ���
class Apple : public Object
{
    public:
        Apple (int y, int x):Object(y,x,7){}

        ~Apple(){}
};
//����Ʈ
class Gate: public Object
{
    public:
        Gate (int y, int x):Object(y,x,8){}

        ~Gate(){}
};

#endif