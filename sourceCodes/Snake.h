//기여도 
// 김중현 20 %
// 구예진 60 %
// 김유진 20 %

#include <vector>
#include "Object.h"
#include "GateNWall.h"
#include "Item.h"

using namespace std;

extern int mapWidth;
extern int mapHeight;
extern int gateUse;
extern int plusScore;
extern int minusScore;
extern void fail();

//----------------------뱀 클래스------------------------------ 
class Snake 
{
    int toX=-1;
    int toY=0;
    int nextY, nextX;
    int mapHeight, mapWidth;
    
    public:
        int numBody=2;
        int onGate =0;
        int  tailY, tailX;
        vector <Object> s;
        
        //출구를 구하기 위한 변수들
        int nextTailPos[4][2] ={{-1,0},{0,1},{1,0},{0,-1}};
        int idxForFind=0;

        //생성자
        Snake(Object**& m,int h,int w); //@author 김유진(20203045)

        // 머리방향조절
        void setToY(int y){toY=y;}
        void setToX(int x){toX=x;}
        //머리 방향 값 얻기
        int getToY(){return toY;}
        int getToX(){return toX;}

        //게이트 통과중임을 나타내는 상태변수 조정
        //@author 김중현 
        void setOnGate(){onGate=numBody;} //게이트를 통과할 몸의 수를 
        void decreaseOnGate(){if(onGate){onGate--;}}

        //맵전환시 뱀의 위치 초기화
        void Init(Object**& m); //@author 김유진(20203045)

        //뱀 몸통 생성
        void pushBody(Object**& m); //@김중현 (20163199)
        //뱀 몸통 제거
        void popBody(Object**& m);  //@김중현 (20163199)
        // 뱀의 몸통 위치 설정(바로앞의 몸통의 위치로 이동함) (머리는 제외)     
        void setBodyPos();      //@author 구예진(20192004)
        //머리위치설정(next값을 설정하고 그 값으로 이동)        
        void setHeadPos();     //@author 구예진(20192004)
        // 뱀의 이동            
        void move(Object**& m,Item& item, GateNWall& gnw);  //@author 구예진(20192004)
        //이동한 곳에 뭔가 있는 경우        
        void afterMove(Object**& m,Item& item,GateNWall& gnw);      //@author 구예진(20192004), 김유진(20203045)
};