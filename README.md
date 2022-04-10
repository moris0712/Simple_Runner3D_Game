# Simple_Runner3D_Game

사용엔진: Unreal Engine 4.27  
제작기간: 2주 (2021.11.15 ~ 2021.11.30)  
게임플레이 영상: https://youtu.be/UtTcCEvRuSE  
게임다운: http://naver.me/FnnNiUCI

---

# 목차
+ 게임 설명
+ 게임 Stage Base
+ 게임 Stage 종류
+ 프로젝트 후
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
  
+ ### 1. Spike Obstacle  

  |||
  |:-:|:-:|
  |![normal](./ReadMeImg/normal.gif)|![normal_Stage](./ReadMeImg/normal_Stage.PNG)|
  |![Obstacle](./ReadMeImg/obstacle.PNG)|Spike에 닿았을 경우 체력이 1깍이고, WallSpike에 닿았을경우 게임 종료|


+ ### 2. xyz Move Floor Stage  

  |||
  |:-:|:---|
  |![xyz_Move_Floor](./ReadMeImg/xyz_Move_Floor.gif)|![xyz_Move_Stage](./ReadMeImg/xyz_Move_Floor_Stage.PNG)|
  |![move_Floor](./ReadMeImg/move_Floor.PNG) | 각각 x축, y축, z축으로 이동하고 속력이 다른 2개의 발판으로 이루어진 스테이지|


* ### 3. xy Scale Floor Stage  

  |||
  |:-:|:---|
  |![xy_Scale_Floor](./ReadMeImg/xy_Scale_Floor.gif)|![xy_Scale_Stage](./ReadMeImg/xy_Scale_Floor_Stage.PNG)|
  |![scale_Floor](./ReadMeImg/scale_Floor.PNG) | x, y가 일정한 크기로 줄어들었다가 커지는 발판으로 이루어진 스테이지|


* ### 4. z Move Pillar Stage  

  |||
  |:-:|:---|
  |![z_Move_Pillar](./ReadMeImg/z_Move_Pillar.gif)|![z_Move_Pillar_Stage](./ReadMeImg/z_Move_Pillar_Stage.PNG)|
  |![z_move_Pillar](./ReadMeImg/z_move_Pillar.PNG) | z축으로 상승, 하강하는 사각기둥으로 이루어진 스테이지|


* ### 5. Disappear Floor Stage

  |||
  |:-:|:---|
  |![disappear_Floor](./ReadMeImg/disappear_Floor.gif)|![disappear_Floor_Stage](./ReadMeImg/disappear_Floor_Stage.PNG)|
  |![disapeear](./ReadMeImg/disapeear.PNG) | 밟았을때 1초후에 사라지는 발판으로 이루어진 스테이지 <br/> 밟았을때를 인식하기위해 발판보다 살짝 작은 Collider를 발판위에 부착|

---

## 프로젝트 후

* ### 소감 
  기획했던 첫번째 프로젝트를 엎은채 C++클래스를 추가한두번째 게임 프로젝트다.  블루프린트만 사용한 프로젝트에서 C++클래스까지 추가하니 상당히 난이도가 올라갔다.  개발했었을때만 해도  인스펙터에서 오브젝트를 대입하는 방법조차 모르고 진행했어서 당시에 GetAllActorsOfClass함수를 사용해 가져왔었던것이 생각난다.  본래 외국인 유튜버분의 강의영상인 2D로 만든 게임을 카메라 위치를 바꾸어서 3D로 만들어보았고 그 외에 바닥 장애물을 생각한대로 추가하는것에만 했는데, 2주나 걸렸었다.  이번 첫 프로젝트는 본래있던 아이디어를 따라해서 덧붙였지만 다음 프로젝트는 손수 내 힘으로 개발 기획을 해 볼 예정이다.
  
* ### 보완할점  
  |||
  |---|---|
  |![SpwanActor](./ReadMeImg/SpawnActor.PNG)|오브젝트 풀 (Object Pool)이라는 개념자체를 몰랐었는데, 같은 오브젝트를 계속 사용하고 반환하는 구조 상 오브젝트 풀을 구현하였으면 프레임드랍이 나타나지 않았을 것이다.|
  |![WallSpike](https://user-images.githubusercontent.com/22339727/162586627-839969c7-af7a-4584-9dd3-4bbf86d43177.PNG)|뒤에 쫒아오는 벽이 카메라 보다 앞에있을 떄 시야가 방해되어 플레이어가 정상적으로 게임할 수 없었다. 벽의 투명도를 얕게하는 조취를 취했으면 좋았을 것 같다.|
  |![Collier](https://user-images.githubusercontent.com/22339727/162587087-70887c88-eee9-4a43-9ba5-c8e2050da36c.gif)|캐릭터 콜라이더에 의존하여 바닥과의 충돌을 고려하지않아서 지면이 줄어들었다가 다시 늘어날때 제대로 처리하지 못하였다. 캐릭터의 보행가능 경사도 조절을 해야할것같다.|
  |![hp](./ReadMeImg/normal.gif)| 장애물에 닿을 시 캐릭터 체력이 깎이지만 플레이어의 시점이 캐릭터에 가있어서 체력바를 일일히 확인하기 힘들것이여서 눈에 잘 띄지않는다. 장애물과 충돌할때 캐릭터의 피격 모션이라던지 빨간색으로 색깔이 바뀌는걸 표현했으면 알아보기 쉬웠을것같다.
