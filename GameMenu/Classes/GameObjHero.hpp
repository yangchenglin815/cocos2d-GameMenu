//
//  GameObjHero.hpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#ifndef GameObjHero_hpp
#define GameObjHero_hpp

#include "cocos2d.h"

using namespace cocos2d;

class GameObjHero : public Node
{
public:
    Sprite * m_mainSprite;
    Texture2D * m_hurt;
    Texture2D * m_jump;
    Point m_offset;
    short m_state;  //0: 正常 1: 跳跃  2：受伤
    bool m_isControl;
    
    GameObjHero(void);
    virtual ~GameObjHero(void);
    void setState(short var);
    Rect rect();
    virtual void onEnter();
    virtual void onExit();
    void jumpend();
    void hurtend();
    bool containsTouchLocation(Touch* touch);
    virtual bool onTouchBegin(Touch* touch, Event* event);
    virtual void onTouchMoved(Touch* touch, Event* event);
    virtual void onTouchEnded(Touch* touch, Event* event);
    
};

#endif /* GameObjHero_hpp */
