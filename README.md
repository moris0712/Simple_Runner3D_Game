# Simple_Runner3D_Game

사용엔진: Unreal Engine 4.27  
제작기간: 2주  

---

# 목차
+ 게임 설명
+ 게임 Stage Base
+ 게임 Stage 종류
+ 장애물 종류
---

## 게임설명
'테일즈런너'를 모티브로 하여 캐릭터가 장애물을 피하고, 낙하해서는 안되며, 뒤에 쫒아오는 벽에 닿기전에 앞으로 이동해야하는 간단한 달리기게임  
|Start|End|
|:-:|:-:|
|![Start](./ReadMeImg/start.gif)|![End](./ReadMeImg/end.gif)|

|Wall|
|:-:|
|![Wall](./ReadMeImg/Wall.gif)|

---
## Stage Base  

|||
|:-:|:---|
![normal](./ReadMeImg/Stage_Base.png)| Create Trigger - 캐릭터와 충돌 시 Spwan Location위치에 다음 랜덤 스테이지가 생성된다. <br/> Destroy Trigger - 캐릭터와 충돌 시 현재 스테이지를 삭제한다. 
---
## Stage 종류  
<br/>
1. Spike Obstacle  

|||
|:-:|:-:|
|![normal](./ReadMeImg/normal.gif)|![normal_Stage](./ReadMeImg/normal_Stage.PNG)|
|![Obstacle](./ReadMeImg/obstacle.PNG)|Spike에 닿았을 경우 체력이 1깍이고, WallSpike에 닿았을경우 게임 종료|

<br/>
2. xyz Move Floor Stage  

|||
|:-:|:---|
|![xyz_Move_Floor](./ReadMeImg/xyz_Move_Floor.gif)|![xyz_Move_Stage](./ReadMeImg/xyz_Move_Floor_Stage.PNG)|
|![move_Floor](./ReadMeImg/move_Floor.PNG) | 각각 x축, y축, z축으로 이동하고 속력이 다른 2개의 발판으로 이루어진 스테이지|

<br/>
3. xy Scale Floor Stage  

|||
|:-:|:---|
|![xy_Scale_Floor](./ReadMeImg/xy_Scale_Floor.gif)|![xy_Scale_Stage](./ReadMeImg/xy_Scale_Floor_Stage.PNG)|
|![scale_Floor](./ReadMeImg/scale_Floor.PNG) | x, y가 일정한 크기로 줄어들었다가 커지는 발판으로 이루어진 스테이지|

<br/>
4. z Move Pillar Stage  

|||
|:-:|:---|
|![z_Move_Pillar](./ReadMeImg/z_Move_Pillar.gif)|![z_Move_Pillar_Stage](./ReadMeImg/z_Move_Pillar_Stage.PNG)|
|![z_move_Pillar](./ReadMeImg/z_move_Pillar.PNG) | z축으로 상승, 하강하는 사각기둥으로 이루어진 스테이지|

<br/>
5. Disappear Floor Stage

|||
|:-:|:---|
|![disappear_Floor](./ReadMeImg/disappear_Floor.gif)|![disappear_Floor_Stage](./ReadMeImg/disappear_Floor_Stage.PNG)|
|![disapeear](./ReadMeImg/disapeear.PNG) | z축으로 상승, 하강하는 사각기둥으로 이루어진 스테이지|
