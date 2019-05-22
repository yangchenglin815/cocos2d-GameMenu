//
//  GameMainScene.hpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#ifndef GameMainScene_hpp
#define GameMainScene_hpp

#include "cocos2d.h"
#include "GameObjMap.hpp"
#include "GameObjHero.hpp"
#include "GameMark.hpp"

class GameMain : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    
    void isHeroDrop();
    void setOver();
    void update(float time);
    
    void menuBackCallback(cocos2d::Ref* pSender);
    void onEnterTransitionDidFinish();
    void onExitTransitionDidStart();
    bool isCollion(Point p1, Point p2, int w1, int h1, int w2, int h2);
    
    bool m_isover;
    GameObjMap * m_map;
    GameObjHero * m_hero;
    GameMark * m_gamemark;
    Sprite * m_gameover;
    
    CREATE_FUNC(GameMain);
};

#endif /* GameMainScene_hpp */
