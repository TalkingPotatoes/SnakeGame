#include <ncurses.h>
#include <string>
#include <iostream>
#include <vector>
#include <thread>

 
using namespace std;
// 각 오브젝트의 속성을 담는 부모 클래스
class Score
{
public:
    int stageNum;
    int scoreBodyLen;
    int scoreGateUse;
    int scoreTime;

    Score(int stageNum = 1, int scoreBodyLen = 0, int scoreGateUse = 0, int scoreTime = 0)
    :stageNum(stageNum), scoreBodyLen(scoreBodyLen), scoreGateUse(scoreGateUse), scoreTime(scoreTime){}

    bool LevelUp()
    {
        switch(stageNum)
        {
            case 1:
            if(scoreBodyLen >= 3 &&  scoreGateUse >= 0 && scoreTime > 0)
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
                return true;
            }
            case 2:
            if(scoreBodyLen >= 5 &&  scoreGateUse >= 0 && scoreTime > 0)
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
                return true;
            }
            case 3:
            if(scoreBodyLen >= 10 &&  scoreGateUse >= 0 && scoreTime > 0)
            {
                stageNum++;
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
                return true;
            }
            break;
        }
        return false;
    }
};

class Object
{
    protected:
        int x,y;
        int typeNum;
        
    public:
        string str;
        
        Object(int y=0, int x=0, int tn = 0,string str="ob"):x(x), y(y) ,str(str), typeNum(tn){}
        virtual ~Object(){}
        
        int getY() {return y;}
        int getX() {return x;}
        void setYX(int y,int x){this->y=y;this->x=x;}

        int getTN(){return typeNum;}
        void setTN(int typeNum) {this->typeNum = typeNum;}

};
// 빈 
class Space :public Object
{
    public:
        Space (int y, int x):Object(y,x,1,".."){}

        ~Space(){}
};
// 일반벽
class NormalWall : public Object
{
    public:
        NormalWall (int y, int x):Object(y,x,2,"NW"){}

        ~NormalWall(){}
};
// 딴딴벽
class ImmueWall : public Object
{
    public:
        ImmueWall (int y, int x):Object(y,x,3,"IW"){}

        ~ImmueWall(){}
};
// 뱀 몸통
class Body: public Object
{
    public:
        Body (int y, int x):Object(y,x,4,"BD"){}

        ~Body(){}
};
// 뱀 머리
class Head : public Object
{     
    public:
        Head (int y, int x):Object(y,x,5,"HD"){}

        ~Head(){}
};
// 독 
class Poison : public Object
{
    public:
        Poison (int y, int x):Object(y,x,6,"PS"){}

        ~Poison(){}
};
// 사과
class Apple : public Object
{
    public:
        Apple (int y, int x):Object(y,x,7,"AP"){}

        ~Apple(){}
};
//------------------------------ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ아이템클래스ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 아이템 ()
class Item
{
    protected:
        int height;
        int width;
    public:
        int numItem=0;
        vector <Object> it;

        Item(Object**& m, int h, int w): height(h), width(w) { }

        void Init(Object**& m)
        {
            while(numItem > 0) popItem(m);
        }

        // 아이템 생성 (시간마다)
        void pushItem(Object**& m)
        {
            //랜덤 y,x값 추출 (빈공간이어야함 ) 랙걸리면 여기서 while도느라 그런거
            int randY, randX;
            do
            {
                srand((unsigned int)time(NULL));
                randY=rand()%(height-2)+1;
                randX=rand()%(width-2)+1;
            } while (m[randY][randX].getTN() != 1); // 빈공간을 찾을때까지
            
            //독 일지 사과일지 정함
            srand(time(NULL));
            int n = rand()%2; //50 %확률
            //그리고 아이템 만들어서
            Object item;
            if (n) {item = Apple(randY,randX);}
            else {item = Poison(randY,randX);}
            //벡터에 삽입
            it.insert(it.begin(),item); 
            m[randY][randX] = item;
            numItem++;
        }
        // 가장 오래된 아이템 제거 (시간 초과, 스테이지 클리어 시)
        void popItem(Object**& m)
        {
            Object item = it[numItem-1];
            it.pop_back();
            m[item.getY()][item.getX()]=Space(item.getY(),item.getX());
            numItem--;
        }
        // 특정 아이템 제거  (뱀과 접촉시)
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
//------------------------------ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ뱀클래스ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 뱀
class Snake
{
    int toX=-1;
    int toY=0;
    int nextY, nextX;
    
    public:
        int numBody=2;
        int  tailY, tailX;
        vector <Object> s;
        
        Snake(Object**& m,int h,int w) : tailY(h/2), tailX(w/2)
        {
            //처음에 길이가 3인 뱀 생성
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

            s[0].setYX(10, 20);
            s[1].setYX(10, 21);
            s[2].setYX(10, 22);
        }

        void setToY(int y){toY=y;}
        void setToX(int x){toX=x;}
        //뱀 몸통 생성
        void pushBody(Object**& m)
        {
            //모서리에서 생성시 가끔 벽 뚫는 현상 해결해야함 **********************************여기서
            int chaiY = s[numBody-1].getY()-s[numBody-2].getY();
            int chaiX = s[numBody-1].getX()-s[numBody-2].getX();
            tailY += chaiY;
            tailX += chaiX;
            Body tail(tailY,tailX);
            m[tailY][tailX] = tail;

            s.push_back(tail);
            numBody++;
        }
        //뱀 몸통 제거
        void popBody(Object**& m)
        {
            m[s[numBody-1].getY()][s[numBody-1].getX()] = Space(s[numBody-1].getY(),s[numBody-1].getX());
            s.pop_back();
            numBody--;
            tailY = s[numBody-1].getY();
            tailX = s[numBody-1].getX();
        }
        
        // 뱀의 이동
        void move(Object**& m)
        {
            // 몸통이동
            for (int i=numBody-1; i>0; i--)
            {
                s[i].setYX(s[i-1].getY(),s[i-1].getX());
            }
            // 머리이동
            nextY = s[0].getY()+toY;
            nextX = s[0].getX()+toX;
            s[0].setYX(nextY,nextX);   

            // 꼬리는 빈공간으로
            m[tailY][tailX]= Space(tailY,tailX); 
            //그리고 꼬리 좌표 다시 
            tailY = s[numBody-1].getY();
            tailX = s[numBody-1].getX(); 

            for (int i=0;i<numBody;i++)
            {
                m[s[i].getY()][s[i].getX()]= s[i];
            }
        }
        //이동한 곳에 뭔가 있는 경우
        void afterMove(Object**& m,Item& item)
        {
            for (int i=0;i<item.numItem;i++)
            { 
                Object obj = item.it[i];
                if ((obj.getY()==s[0].getY())&&(obj.getX()==s[0].getX())) // 머리랑 좌표가 같으면,
                {   
                    // 벽에 닿았을 때의 경우도 만들어야함 **********************************************************************
                    if (obj.getTN()==6) //독먹으면 
                    {
                        popBody(m);
                        item.eraseItem(obj.getY(),obj.getX()); // 특정 아이템 제거
                    }
                    else if (obj.getTN()==7) // 사과먹으면
                    {
                        pushBody(m);
                        item.eraseItem(obj.getY(),obj.getX());
                    }
                }
            }
        }
};
//------------------------------ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ맵 클래스ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 맵
class Map
{
    int width;
    int height;
    int stageNum;
    
    friend class Snake;

    public:
        Object** m;

        Map(int w,int h, int sn=1): width(w), height(h), stageNum(sn)
        {
            // 좌표 형성
            m = new Object*[height];
            for (int i=0;i<height;i++){m[i]= new Object[width];}
            // 일단 벽과 빈공간으로 초기화
            for (int j=0;j<height;j++){
                for (int i=0;i<width;i++)
                {
                    if (j==0 || j==(height-1) ||i==0|| i==(width-1)) { m[j][i] =NormalWall(j,i);}
                    else {m[j][i] = Space(j,i);} 
                }
            }
            // 꼭지점은 딴딴벽으로 
            m[0][width-1]=ImmueWall(0,width-1);
            m[0][0] = ImmueWall(0,0);
            m[height-1][0] = ImmueWall(height-1,0);
            m[height-1][width-1] = ImmueWall(height-1,width-1);    
        }

        void makeHorizontal(int height)
        {
            for(int i = 3; i < width-3; i++)
            {
                m[height][i] = NormalWall(height, i);
            }
        }

        void makeVertical(int width)
        {
            for(int i = 3; i < height-3; i++)
            {
                m[i][width] = NormalWall(i, width);
            }
        }

        int getHeight(){return height;}
        int getWidth(){return width;}
        int getStageNum(){return stageNum;}

        // 초기화 잘됐는지 출력 (이젠 안씀)
        void print()
        {
            
            for (int j=0;j<height;j++)
            {
                for(int i=0;i<width;i++)
                {
                    cout<< m[j][i].str <<" ";
                }
                cout<<endl;
            }
            cout <<"stage : " << stageNum<<endl;
        }
};


//------------------------------ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ전역함수ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//맵 그래픽 생성
void mapUpdate(Object** m, int h, int w)
{
    for(int j = 0; j < h; j++)
    {
        for(int i = 0; i < w; i++)
        {
            int objType= m[j][i].getTN();
            switch(objType) //따져야할 조건이 많을 때는 switch가 if 보다 좋음
            {
                case 1: //빈공간
                    attrset(COLOR_PAIR(1));
                    mvprintw(j, i*2, "00");
                    break;
                
                case 2: // 일반벽
                    attrset(COLOR_PAIR(2));
                    mvprintw(j, i*2, "00");
                    break;

                case 3: // 딴딴벽
                    attrset(COLOR_PAIR(3));
                    mvprintw(j, i*2, "00");
                    break;

                case 4: // 뱀 몸통
                    attrset(COLOR_PAIR(4));
                    mvprintw(j, i*2, "00");
                    break;

                case 5: // 뱀 머리
                    attrset(COLOR_PAIR(5));
                    mvprintw(j, i*2, "00");
                    break;
                case 6: // 독
                    attrset(COLOR_PAIR(6));
                    mvprintw(j, i*2, "00");
                    break;
                case 7: //사과
                    attrset(COLOR_PAIR(7));
                    mvprintw(j, i*2, "00");
                    break;
                
            }
        }
    }
    refresh();
}

// 시간의 흐름 
// 레퍼런스 전달시 컴파일에러
void timeUpdate(Snake *s,Object** *m,Item *i,int height, int width, bool* play, Score *score, Map *map)
{
    for(int a = 0; a < 4; a++)
    {
        //상태창
        WINDOW *win;
        win = newwin(map->getHeight(),30,0,map->getWidth()*2);
        wbkgd(win, COLOR_PAIR(10));
        box(win, 0,0);

        wattron(win,A_BOLD); // 제목 강조
        mvwprintw(win, 1,2, "SNAKE GAME");
        wattroff(win,A_BOLD);
        mvwprintw(win, 4,2, "STATUS:");
        mvwprintw(win, 6,2, "STAGE: %d",score->stageNum);
        mvwprintw(win, 7,2, "SCORE: %d/20",s->numBody);
        mvwprintw(win, 8,2, "TIME: %d sec", 0);
        mvwprintw(win, 9,2, "num of items : %d     ",i->numItem);
        mvwprintw(win, 10,5, "- score");
        mvwprintw(win, 11,5, "+ score");
        wattron(win,COLOR_PAIR(6));
        mvwprintw(win, 10,2, "00");
        wattroff(win,COLOR_PAIR(6));
        wattron(win,COLOR_PAIR(7));
        mvwprintw(win, 11,2, "00");
        wattroff(win,COLOR_PAIR(7));
        
        double time =0;
        int tick= 100;  //몇초마다 화면 갱신 (뱀 이동 )할지 정함-  단위 ms 
        int initCD = 4000; // 아이템이 나오는 시간- 단위 ms
        double countdown = 0;

        if(a > 0)
        {
            s->Init(map->m);
            i->Init(map->m);
        }

        if(score->stageNum == 2) map->makeVertical(10);
        if(score->stageNum == 3) map->makeHorizontal(15);

        do {
            box(win, 0,0);

            wattron(win,A_BOLD); // 제목 강조
            mvwprintw(win, 1,2, "SNAKE GAME");
            wattroff(win,A_BOLD);
            mvwprintw(win, 4,2, "STATUS:");
            mvwprintw(win, 6,2, "STAGE: %d",score->stageNum);
            mvwprintw(win, 9,2, "num of items : %d     ",i->numItem);
            //countdown이 0이 될때마다 아이템 생성 
            if (countdown==0)  
            {
                if (time >=initCD*0.003 && i->numItem >=3) // 동시에 3개만 유지할수있도록. 근데 가끔씩 4개됨. 해결 필요 ****************************** 
                {
                    i->popItem(*m);
                }
                i->pushItem(*m);
                countdown=initCD;
            }
            
            // 점수업데이트
            if(score->stageNum == 1) mvwprintw(win, 7,2, "SCORE: %d/3     ",s->numBody-3);
            else if(score->stageNum == 2) mvwprintw(win, 7,2, "SCORE: %d/5     ",s->numBody-3);
            else if(score->stageNum == 3) mvwprintw(win, 7,2, "SCORE: %d/10     ",s->numBody-3);
            score->scoreTime = time;
            score->scoreBodyLen = s->numBody-3;

            // 시간 업데이트
            mvwprintw(win, 8,2, "TIME: %1.1f sec  ",time);
            mvwprintw(win, 9,2, "num of items : %d     ",i->numItem);

            time+=tick*0.001;
            wrefresh(win);

            // 뱀 움직임 업데이트
            s->move(*m);
            s->afterMove(*m,*i);
            mapUpdate(*m,24,30);
            // refresh();   
            wrefresh(stdscr);  //refresh쓸때보다 화면이 덜 깨짐 (기분탓일 수도 있음) ******************************

            napms(tick); //sleep과 같은 기능
            countdown-=tick;
            bool stageEnd = false;
            if(score->LevelUp() == true)
            {

                while(1)
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
        } while (*play=true);
    }
}
//------------------------------ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ메인함수ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//
int main()
{
    initscr(); 
    
    noecho(); // 입력을 자동으로 화면에 출력하지 않도록 합니다.
    curs_set(FALSE); // cursor를 보이지 않게 합니다. 
    start_color();

    int x = 4;
    int y = 10;

    int b = 33;
    mvprintw(12, b, "G");
    mvprintw(12, b+4, "A");
    mvprintw(12, b+8, "M");
    mvprintw(12, b+12, "E");

    init_color(14,1000,700,0 ); // 몸색 (노란색)
    init_color(15, 1000, 400,0); // 머리색 (오렌지)
    init_pair(4, 14, 14); //뱀 몸통 색
    init_pair(5,  15, 15); // 뱀 머리 색
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
    // 겜초기화
    while(1){
        int input = getch();
        if(input == 's') break;
    }

    clear();
    // 맵 초기화
    Map map(30,24,1);
    //아이템 리스트 초기화 
    Item item(map.m,map.getHeight(),map.getWidth());
    // 뱀 초기화
    Snake snake(map.m,map.getHeight(),map.getWidth());
    Score score;

    // attron(A_CHARTEXT);

    //팔레트
    //기본 색이 너무 칙칙해서 밝게 바꿨습니다.
    start_color();
    init_color(11,1000,1000,1000); //빈공간색 (흰색);
    init_color(12, 400, 400, 400); // 일반벽 색 (회색);
    init_color(13, 0,0,0);// 무적 벽(검은색);
    init_color(14,1000,700,0 ); // 몸색 (노란색)
    init_color(15, 1000, 400,0); // 머리색 (오렌지);
    // 만든 색상 적용
    init_pair(1, 11, 11); //빈공간 색
    init_pair(2,12,12);                     // 일반 벽 색
    init_pair(3, 13, 13); // 딴딴벽 색
    init_pair(4, 14, 14); //뱀 몸통 색
    init_pair(5,  15, 15); // 뱀 머리 색
    init_pair(6, COLOR_GREEN, COLOR_GREEN); // 독색
    init_pair(7, COLOR_RED, COLOR_RED); //사과색
    init_pair(10, COLOR_BLACK, COLOR_WHITE); //상태창 색
    // init_pair(10, COLOR_GREEN, COLOR_MAGENTA);

    //맵 그래픽 생성
    mapUpdate(map.m,map.getHeight(),map.getWidth());
    
    refresh();
    int time = 0;
    
    bool play=true; //게임 종료 플래그. 아직 작동 안됨 **********************************************************
    thread t(timeUpdate,&snake, &map.m, &item, map.getHeight(),map.getWidth(),&play,&score, &map); // 스레드 생성

    /////////////////////////////////////////////
    // 키입력 및 게임 메인 루프. 종료조건도 입력해야함******************************************************
    attrset(COLOR_PAIR(4));
    int input;
    keypad(stdscr, true); //특수키 입력받기 활성화
    while(true)
    {
        input=getch();
        switch(input)
        {
            case KEY_UP:
                // if(snake.direction == 4) endwin();
                snake.setToY(-1);
                snake.setToX(0);
                break;
            case KEY_DOWN:
                // if(snake.direction == 3) endwin();
                snake.setToY(1);
                snake.setToX(0);
                break;
            case KEY_LEFT:
                // if(snake.direction == 2) endwin();
                snake.setToY(0);
                snake.setToX(-1);
                break;
            case KEY_RIGHT:
                // if(snake.direction == 1) endwin();
                snake.setToY(0);
                snake.setToX(1);
                break;
        }


        //디버깅용 입력
	    // 한칸씩 이동
        if(input == 'm')
        {
            snake.move(map.m);
            snake.afterMove(map.m,item);
            //scoreUpdate(win,snake);// 점수변화
            refresh();
        }   
        // 몸통추가
        if (input == '1')
        {
            snake.pushBody(map.m);
        }
        //몸통감소 (몸통 2개일때 쓰면 에러남)
        if (input == '2')
        {
            snake.popBody(map.m);
        }
        //아이템추가
        if (input == 'i')
        {
            item.pushItem(map.m);
        }
        //아이템 삭제
        if (input == 'o')
        {
            item.popItem(map.m);
        }
        //종료
        if (input == 'q')
        {
            play = false;
        }
    }
    if(t.joinable()){t.join();} // 다른 스레드가 먼저 끝나기를 기다림. 
    endwin(); // 화면 끔


    
    

    // map.print();

    // while (true)
    // {
    //     char c;
    //     cin >>c;

    //     if (c=='a'){snake.setToY(0);snake.setToX(-1);snake.move(map.m);map.print();}
    //     else if(c=='d'){snake.setToY(0);snake.setToX(1);snake.move(map.m);map.print();}
    //     else if(c=='w'){snake.setToY(-1);snake.setToX(0);snake.move(map.m);map.print();}
    //     else if(c=='s'){snake.setToY(1);snake.setToX(0);snake.move(map.m);map.print();}

    //     else if(c=='1'){snake.popBody(map.m);map.print();}
    //     else if(c=='2'){snake.pushBody(map.m);map.print();}
    // }

    // snake.move(map.m);


    // map.print();
    // for(int i=0;i<3;i++)
    // {
    //     snake.move(map.m);
    //     map.print();
    //     cout << snake.tailY <<", "<<snake.tailX<< endl;
    // }
    
    // snake.popBody(map.m);   
    // cout << snake.tailY <<", "<<snake.tailX<< endl;
    // map.print();
    // cout << snake.tailY <<", "<<snake.tailX<< endl;
    // snake.move(map.m);
    // map.print();
    // cout << snake.tailY <<", "<<snake.tailX<< endl;
    
    // snake.move(map.m);
    // map.print();
    // cout << snake.tailY <<", "<<snake.tailX<< endl;

    // snake.pushBody(map.m);
    // map.print();
    // cout << snake.tailY <<", "<<snake.tailX<< endl;

    // snake.move(map.m);
    // map.print();
    // cout << snake.tailY <<", "<<snake.tailX<< endl;

    return 0;
}