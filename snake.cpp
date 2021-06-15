#include <ncurses.h>
// #include <string>
#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>

using namespace std;
void gameover()
{
    clear();
    WINDOW *gameover = subwin(stdscr, 5, 60, 10, 10);
    init_pair(21, COLOR_WHITE, COLOR_RED);
    box(gameover, 0,0);
    attron(COLOR_PAIR(21));
    wbkgd(gameover, COLOR_PAIR(21));

    init_pair(20, COLOR_WHITE, COLOR_RED);
    attron(COLOR_PAIR(20));
    mvprintw(11, 35, "YOU LOSE");
    attron(A_BLINK);
    attron(COLOR_PAIR(21));
    mvprintw(13, 19, "!!!!!!!!!!!!!!!!GAME OVER!!!!!!!!!!!!!!!!");
    refresh();
    
    sleep(2);
    endwin();
}
void GameClear()
{
    clear();
    init_pair(20, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(20));
    int x = 5; int y = 11;
    mvprintw(x, y+2, "00");
    mvprintw(x, y+4, "00");
    mvprintw(x, y+6, "00");
    mvprintw(x, y+8, "00");
    mvprintw(x+1, y, "00");
    mvprintw(x+2, y, "00");
    mvprintw(x+3, y, "00");
    mvprintw(x+4, y, "00");
    mvprintw(x+5, y, "00");
    mvprintw(x+6, y+2, "00");
    mvprintw(x+6, y+4, "00");
    mvprintw(x+6, y+6, "00");
    mvprintw(x+6, y+8, "00");

    mvprintw(x, y+12, "00");
    mvprintw(x+1, y+12, "00");
    mvprintw(x+2, y+12, "00");
    mvprintw(x+3, y+12, "00");
    mvprintw(x+4, y+12, "00");
    mvprintw(x+5, y+12, "00");
    mvprintw(x+6, y+12, "00");

    mvprintw(x+1, y+16, "00");
    mvprintw(x+2, y+16, "00");
    mvprintw(x+3, y+16, "00");
    mvprintw(x+4, y+16, "00");
    mvprintw(x+5, y+16, "00");
    mvprintw(x, y+18, "00");
    mvprintw(x, y+20, "00");
    mvprintw(x, y+22, "00");
    mvprintw(x, y+24, "00");
    mvprintw(x+3, y+18, "00");
    mvprintw(x+3, y+20, "00");
    mvprintw(x+3, y+22, "00");
    mvprintw(x+3, y+24, "00");
    mvprintw(x+6, y+18, "00");
    mvprintw(x+6, y+20, "00");
    mvprintw(x+6, y+22, "00");
    mvprintw(x+6, y+24, "00");
    mvprintw(x+5, y+26, "00");
    mvprintw(x+1, y+26, "00");
    mvprintw(x+2, y+26, "00");

    mvprintw(x+2, y+30, "00");
    mvprintw(x+3, y+30, "00");
    mvprintw(x+4, y+30, "00");
    mvprintw(x+1, y+32, "00");
    mvprintw(x+5, y+32, "00");
    mvprintw(x, y+34, "00");
    mvprintw(x, y+36, "00");
    mvprintw(x, y+38, "00");
    mvprintw(x+6, y+34, "00");
    mvprintw(x+6, y+36, "00");
    mvprintw(x+5, y+38, "00");
    mvprintw(x+4, y+40, "00");
    mvprintw(x+1, y+40, "00");
    mvprintw(x+2, y+42, "00");
    mvprintw(x+3, y+42, "00");
    mvprintw(x+4, y+42, "00");
    mvprintw(x+5, y+42, "00");
    mvprintw(x+6, y+44, "00");

    mvprintw(x, y+48, "00");
    mvprintw(x+1, y+48, "00");
    mvprintw(x+2, y+48, "00");
    mvprintw(x+3, y+48, "00");
    mvprintw(x+4, y+48, "00");
    mvprintw(x+5, y+48, "00");
    mvprintw(x+6, y+48, "00");
    mvprintw(x+2, y+50, "00");
    mvprintw(x+1, y+52, "00");
    mvprintw(x, y+54, "00");
    mvprintw(x, y+56, "00");

    WINDOW *startWin = subwin(stdscr, 5, 60, 15, 10);
    init_pair(1, COLOR_WHITE, COLOR_GREEN);
    box(startWin, 0,0);
    attron(COLOR_PAIR(1));
    wbkgd(startWin, COLOR_PAIR(1));
    refresh();

    attron(A_BLINK);
    mvprintw(17, 22, "Congratulations! cleared all stages");
    
    sleep(2);
    endwin();
}
bool play= true; //���� ���� �÷���
bool gameClear = false;
void fail(){play=false;} // ���� ���� �Լ�

int mapWidth;
int mapHeight;
int gateUse = 0;

class Score
{
public:
    int stageNum;
    int scoreBodyLen;
    int scoreGateUse;

    Score(int stageNum = 1, int scoreBodyLen = 0, int scoreGateUse = 0)
    :stageNum(stageNum), scoreBodyLen(scoreBodyLen), scoreGateUse(scoreGateUse){}

    bool LevelUp()
    {
        scoreGateUse = gateUse;
        switch(stageNum)
        {
            case 1:
            if(scoreBodyLen >= 3 &&  scoreGateUse >= 3) 
            {
                stageNum++;
                clear();
                WINDOW *loadingWin = subwin(stdscr, 5, 60, 10, 10);
                init_pair(21, COLOR_WHITE, COLOR_GREEN);
                box(loadingWin, 0,0);
                attron(COLOR_PAIR(21));
                wbkgd(loadingWin, COLOR_PAIR(21));
                refresh();

                init_pair(20, COLOR_RED, COLOR_GREEN);
                attron(COLOR_PAIR(20));
                mvprintw(11, 24, "Are you ready for the next stage?");
                attron(A_BLINK);
                attron(COLOR_PAIR(21));
                mvprintw(13, 32, "press 'r' key");
                gateUse = 0;
                return true;
            }
            case 2:
            if(scoreBodyLen >= 5 &&  scoreGateUse >= 3)
            {
                stageNum++;
                clear();
                WINDOW *loadingWin = subwin(stdscr, 5, 60, 10, 10);
                init_pair(21, COLOR_WHITE, COLOR_GREEN);
                box(loadingWin, 0,0);
                attron(COLOR_PAIR(21));
                wbkgd(loadingWin, COLOR_PAIR(21));
                refresh();

                init_pair(20, COLOR_RED, COLOR_GREEN);
                attron(COLOR_PAIR(20));
                mvprintw(11, 24, "Are you ready for the next stage?");
                attron(A_BLINK);
                attron(COLOR_PAIR(21));
                mvprintw(13, 32, "press 'r' key");
                gateUse = 0;
                return true;
            }
            case 3:
            if(scoreBodyLen >= 7 &&  scoreGateUse >= 3)
            {
                stageNum++;
                clear();
                WINDOW *loadingWin = subwin(stdscr, 5, 60, 10, 10);
                init_pair(21, COLOR_WHITE, COLOR_GREEN);
                box(loadingWin, 0,0);
                attron(COLOR_PAIR(21));
                wbkgd(loadingWin, COLOR_PAIR(21));
                refresh();

                init_pair(20, COLOR_RED, COLOR_GREEN);
                attron(COLOR_PAIR(20));
                mvprintw(11, 24, "Are you ready for the next stage?");
                attron(A_BLINK);
                attron(COLOR_PAIR(21));
                mvprintw(13, 32, "press 'r' key");
                gateUse = 0;
                return true;
            }
            case 4:
            if(scoreBodyLen >= 10 &&  scoreGateUse >= 3)
            {
                stageNum++;
                clear();

                gameClear = true;
                return true;
            }
            break;
        }
        return false;
    }
};


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
//--------------------------�� Ŭ���� ------------------------------
class Map
{
    int width;
    int height;
    
    friend class Snake;

    public:
        Object** m;

        Map(int w=30,int h=24): width(w), height(h)
        {
            // ��ǥ ����
            m = new Object*[height];
            for (int i=0;i<height;i++){m[i]= new Object[width];}
            // �ϴ� ���� ��������� �ʱ�ȭ
            for (int j=0;j<height;j++){
                for (int i=0;i<width;i++)
                {
                    if (j==0 || j==(height-1) ||i==0|| i==(width-1)) { m[j][i] =NormalWall(j,i);}
                    else {m[j][i] = Space(j,i);} 
                }
            }
            // �������� ���������� 
            m[0][width-1]=ImmueWall(0,width-1);
            m[0][0] = ImmueWall(0,0);
            m[height-1][0] = ImmueWall(height-1,0);
            m[height-1][width-1] = ImmueWall(height-1,width-1);
            
        }

        int getHeight(){return height;}
        int getWidth(){return width;}

        // ���� �� ����
        void makeHorizontal(int height)
        {
            for(int i = 4; i < width-4; i++)
            {
                if(m[height][i].getTN()==2) m[height][i] = ImmueWall(height, i);
                else m[height][i] = NormalWall(height, i);
            }
        }
        // ���� �� ���� 
        void makeVertical(int width)
        {
            for(int i = 4; i < height-4; i++)
            {
                if(m[i][width].getTN()==2) m[i][width] = ImmueWall(i, width);
                else m[i][width] = NormalWall(i, width);
            }
        }
};


//------------------------�����Լ�----------------------- 
//�� �׷��� ���� 
void mapUpdate(Object** m, int h, int w)
{
    clear();
    for(int j = 0; j < h; j++)
    {
        for(int i = 0; i < w; i++)
        {
            int objType= m[j][i].getTN();
            attrset(COLOR_PAIR(objType)); //Ÿ�Կ� �°� ��ĥ��
            mvprintw(j, i*2, "00");
        }
    }
    refresh();
}

// �ð��� �帧             // ���۷��� ���޽� �����Ͽ���
void timeUpdate(Score *score, Map *map,Snake *s,Item *i,GateNWall *g)
{
    for(int a=0;a <5; a++)
    {
        //����â (������������ ����â�� ���� ��)
        WINDOW *win;
        win = newwin(map->getHeight(),30,0,map->getWidth()*2);
        wbkgd(win, COLOR_PAIR(10));
        box(win, 0,0);

        wattron(win,A_BOLD); // ���� ����
        mvwprintw(win, 1,2, "SNAKE GAME");
        wattroff(win,A_BOLD);
        mvwprintw(win, 4,2, "STATUS:");
        mvwprintw(win, 6,2, "STAGE: %d",score->stageNum);
        mvwprintw(win, 11,5, "- score");
        mvwprintw(win, 12,5, "+ score");
        wattron(win,COLOR_PAIR(6));
        mvwprintw(win, 11,2, "00");
        wattroff(win,COLOR_PAIR(6));
        wattron(win,COLOR_PAIR(7));
        mvwprintw(win, 12,2, "00");
        wattroff(win,COLOR_PAIR(7));
        
        double time =0;
        int tick= 100;  //���ʸ��� ȭ�� ���� (�� �̵� )���� ����-  ���� ms 
        int initItemCD = 4000; // �������� ������ �ð�- ���� ms
        int initGateCD = 10000;
        double ItemCD = 0;
        double GateCD = 0;

        // �������� ���� �� ��ġ ����
        if(a > 0)
        {
            s->Init(map->m);
            i->Init(map->m);
        }
        if(score->stageNum == 2) {map->makeVertical(mapWidth/2  + 6); g->fillWalls(map->m);}
        else if(score->stageNum == 3) {map->makeHorizontal(mapHeight/2 - 6);g->fillWalls(map->m);}
        else if(score->stageNum == 4) {map->makeVertical(mapHeight/2 - 6);g->fillWalls(map->m);}
        //�ð� �帧 
        do {
            box(win, 0,0);

            wattron(win,A_BOLD); // ���� ����
            mvwprintw(win, 1,2, "SNAKE GAME");
            wattroff(win,A_BOLD);
            mvwprintw(win, 4,2, "STATUS:");
            mvwprintw(win, 6,2, "STAGE: %d",score->stageNum);
            mvwprintw(win, 10,2, "num of items : %d     ",i->numItem);
            // wclear(stdscr);

            //ItemCD�� 0�� �ɶ����� ������ ���� 
            if (ItemCD==0)  
            {
                if (time >=initItemCD*0.003 && i->numItem >=3) // ���ÿ� 3���� �����Ҽ��ֵ���. �ٵ� ������ 4����. �ذ� �ʿ� ****************************** 
                {
                    i->popItem(map->m);
                }
                i->pushItem(map->m);
                ItemCD=initItemCD;
            }
            // GateCD�� 0�� �ɶ����� ����Ʈ ����
            s->decreaseOnGate();
            if (GateCD==0)
            {
                if (s->onGate==0){g->selectGate(map->m);} //����Ʈ ����

                GateCD=initGateCD;

                // mvwprintw(win, 11,2, "(%d,%d)  ,  (%d,%d)   ",g->gate1.getY(),g->gate1.getX(),g->gate2.getY(),g->gate2.getX()); //������ ��Ż��ġ ���
            }
            
            // �� ������ ������Ʈ
            s->move(map->m,*i,*g);
            mapUpdate(map->m,mapHeight,mapWidth);

            // ����������Ʈ
            if(score->stageNum == 1) mvwprintw(win, 7,2, "SCORE: %d/3     ",s->numBody-3);
            else if(score->stageNum == 2) mvwprintw(win, 7,2, "SCORE: %d/5     ",s->numBody-3);
            else if(score->stageNum == 3) mvwprintw(win, 7,2, "SCORE: %d/7     ",s->numBody-3);
            else if(score->stageNum == 4) mvwprintw(win, 7,2, "SCORE: %d/10     ",s->numBody-3);
            mvwprintw(win, 8,2, "GateUse: %d/3     ",gateUse);
            score->scoreBodyLen = s->numBody-3;
            

            // �ð� ������Ʈ
            mvwprintw(win, 9,2, "TIME: %1.1f sec  ",time);
            mvwprintw(win, 10,2, "num of items : %d     ",i->numItem);
            time+=tick*0.001;
            wrefresh(win);

            napms(tick); //sleep�� ���� ���
            ItemCD-=tick;
            GateCD-=tick;

            bool stageEnd = false;
            if(score->LevelUp() == true)
            {
                while(play && !gameClear)
                {
                    int input = getch();
                    if(input == 'r')
                    {
                        stageEnd = true;
                        break;
                    } 
                }
            }
            if(stageEnd == true)
            {
                clear();
                break;
            }
        } while (play && !gameClear);
    }
    if(play==false) gameover();
    if(gameClear) GameClear();
}


//-----------------------���� �Լ�------------------------ 
int main()
{
    initscr();

    curs_set(FALSE); // cursor�� ������ �ʰ� �մϴ�. 
    start_color();
    noecho(); // �Է��� �ڵ����� ȭ�鿡 ������� �ʵ��� �մϴ�.
    
    mvprintw(3, 8, "select map size number and press number key");
    mvprintw(5, 8, "1: width 24 Height 18");
    mvprintw(6, 8, "2: width 30 Height 24");
    mvprintw(7, 8, "3: width 36 Height 30");

    while(1){
        int input = getch();
        if(input == '1')
        {
            mapWidth = 24;
            mapHeight = 18;
            break;
        }
        else if(input == '2')
        {
            mapWidth = 30;
            mapHeight = 24;
            break;
        }
        if(input == '3')
        {
            mapWidth = 36;
            mapHeight = 30;
            break;
        }
    }
    
    clear();

    // �ʱ�ȭ��
    int x = 4;
    int y = 10;

    int b = 33;
    mvprintw(12, b, "G");
    mvprintw(12, b+4, "A");
    mvprintw(12, b+8, "M");
    mvprintw(12, b+12, "E");

    init_color(14,1000,700,0 ); // ���� (�����)
    init_color(15, 1000, 400,0); // �Ӹ��� (������)
    init_pair(4, 14, 14); //�� ���� ��
    init_pair(5,  15, 15); // �� �Ӹ� ��
    //s
    attron(COLOR_PAIR(5));
    mvprintw(x+0, y+2, "00");
    mvprintw(x+0, y+4, "00");
    mvprintw(x+0, y+6, "00");
    mvprintw(x+1, y, "00");
    mvprintw(x+2, y, "00");
    mvprintw(x+3, y+2, "00");
    mvprintw(x+3, y+4, "00");
    mvprintw(x+3, y+6, "00");
    mvprintw(x+4, y+8, "00");
    mvprintw(x+5, y+8, "00");
    mvprintw(x+6, y+2, "00");
    mvprintw(x+6, y+4, "00");
    mvprintw(x+6, y+6, "00");
    //nake
    attron(COLOR_PAIR(4));
    mvprintw(x, y+12, "00");
    mvprintw(x+1, y+12, "00");
    mvprintw(x+2, y+12, "00");
    mvprintw(x+3, y+12, "00");
    mvprintw(x+4, y+12, "00");
    mvprintw(x+5, y+12, "00");
    mvprintw(x+6, y+12, "00");
    mvprintw(x+2, y+14, "00");
    mvprintw(x+3, y+16, "00");
    mvprintw(x+4, y+18, "00");
    mvprintw(x, y+20, "00");
    mvprintw(x+1, y+20, "00");
    mvprintw(x+2, y+20, "00");
    mvprintw(x+3, y+20, "00");
    mvprintw(x+4, y+20, "00");
    mvprintw(x+5, y+20, "00");
    mvprintw(x+6, y+20, "00");

    mvprintw(x+3, y+24, "00");
    mvprintw(x+4, y+24, "00");
    mvprintw(x+5, y+24, "00");
    mvprintw(x+6, y+24, "00");
    mvprintw(x+4, y+26, "00");
    mvprintw(x+4, y+28, "00");
    mvprintw(x+4, y+30, "00");
    mvprintw(x+3, y+32, "00");
    mvprintw(x+4, y+32, "00");
    mvprintw(x+5, y+32, "00");
    mvprintw(x+6, y+32, "00");
    mvprintw(x, y+28, "00");
    mvprintw(x+1, y+26, "00");
    mvprintw(x+2, y+26, "00");
    mvprintw(x+1, y+30, "00");
    mvprintw(x+2, y+30, "00");

    mvprintw(x, y+36, "00");
    mvprintw(x+1, y+36, "00");
    mvprintw(x+2, y+36, "00");
    mvprintw(x+3, y+36, "00");
    mvprintw(x+4, y+36, "00");
    mvprintw(x+5, y+36, "00");
    mvprintw(x+6, y+36, "00");
    mvprintw(x+3, y+38, "00");
    mvprintw(x+2, y+40, "00");
    mvprintw(x+4, y+40, "00");
    mvprintw(x+1, y+42, "00");
    mvprintw(x+5, y+42, "00");
    mvprintw(x, y+44, "00");
    mvprintw(x+6, y+44, "00");

    mvprintw(x, y+48, "00");
    mvprintw(x+1, y+48, "00");
    mvprintw(x+2, y+48, "00");
    mvprintw(x+3, y+48, "00");
    mvprintw(x+4, y+48, "00");
    mvprintw(x+5, y+48, "00");
    mvprintw(x+6, y+48, "00");
    mvprintw(x, y+50, "00");
    mvprintw(x, y+52, "00");
    mvprintw(x, y+54, "00");
    mvprintw(x, y+56, "00");
    mvprintw(x+3, y+50, "00");
    mvprintw(x+3, y+52, "00");
    mvprintw(x+3, y+54, "00");
    mvprintw(x+3, y+56, "00");
    mvprintw(x+6, y+50, "00");
    mvprintw(x+6, y+52, "00");
    mvprintw(x+6, y+54, "00");
    mvprintw(x+6, y+56, "00");
    

    WINDOW *startWin = subwin(stdscr, 5, 60, 15, 10);
    init_pair(1, COLOR_WHITE, COLOR_GREEN);
    box(startWin, 0,0);
    attron(COLOR_PAIR(1));
    wbkgd(startWin, COLOR_PAIR(1));
    refresh();

    attron(A_BLINK);
    mvprintw(17, 32, "press 's' key");


    // �� ����
    while(1){
        int input = getch();
        if(input == 's') break;
    }

    clear();

    // ���ʱ�ȭ
    
    // �� �ʱ�ȭ
    Map map(mapWidth,mapHeight);
    //������ ����Ʈ �ʱ�ȭ 
    Item item(map.m,map.getHeight(),map.getWidth());
    // �� �ʱ�ȭ
    Snake snake(map.m,map.getHeight(),map.getWidth());
    // ����Ʈ &�� �ʱ�ȭ
    GateNWall gnw(map.m,map.getHeight(),map.getWidth());
    //ȭ��  
    Score score;

    // attron(A_CHARTEXT);

    //�ȷ�Ʈ
    //�⺻ ���� �ʹ� ĢĢ�ؼ� ��� �ٲ���ϴ�.
    start_color();
    init_color(11,1000,1000,1000); //������� (���);
    init_color(12, 400, 400, 400); // �Ϲݺ� �� (ȸ��);
    init_color(13, 0,0,0);// ���� ��(������);
    init_color(14,1000,700,0 ); // ���� (�����)
    init_color(15, 1000, 400,0); // �Ӹ��� (������;
    init_color(18,1000,100,500); // ����Ʈ��(��ũ)
    // ���� ���� ����
    init_pair(1, 11, 11); //����� ��
    init_pair(2,12,12);                     // �Ϲ� �� ��
    init_pair(3, 13, 13); // ������ ��
    init_pair(4, 14, 14); //�� ���� ��
    init_pair(5,  15, 15); // �� �Ӹ� ��
    init_pair(6, COLOR_GREEN, COLOR_GREEN); // ����
    init_pair(7, COLOR_RED, COLOR_RED); //�����
    init_pair(8, 18,18); //����Ʈ��
    init_pair(10, COLOR_BLACK, COLOR_WHITE); //����â ��

    // int time = 0;
    
    thread t(timeUpdate,&score,&map, &snake, &item, &gnw) ; // ������ ����

    /////////////////////////////////////////////
    // Ű�Է� �� ���� ���� ����. �������ǵ� �Է��ؾ���******************************************************
    int input;
    keypad(stdscr, true); //Ư��Ű �Է¹ޱ� Ȱ��ȭ
    while(true)
    {
        input=getch();
        switch(input)
        {
            case KEY_UP:
                snake.setToY(-1);
                snake.setToX(0);
                break;

            case KEY_DOWN:
                snake.setToY(1);
                snake.setToX(0);
                break;
                
            case KEY_LEFT:
                snake.setToY(0);
                snake.setToX(-1);
                break;

            case KEY_RIGHT:
                snake.setToY(0);
                snake.setToX(1);
                break;
        }


        //������ �Է�

        // �����߰�
        if (input == '1')
        {
            snake.pushBody(map.m);
        }
        //���밨�� (���� 2���϶� ���� ������)
        if (input == '2')
        {
            snake.popBody(map.m);
        }
        //�������߰�
        if (input == 'i')
        {
            item.pushItem(map.m);
        }
        //������ ����
        if (input == 'o')
        {
            item.popItem(map.m);
        }
        //����
        if (input == 'q')
        {
            play = false;
        }
    }
    if(t.joinable()){t.join();} // �ٸ� �����尡 ���� �����⸦ ��ٸ�. 
    endwin(); // ȭ�� ��

    return 0;
}
