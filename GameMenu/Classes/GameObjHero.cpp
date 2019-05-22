//
//  GameObjHero.cpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#include "GameObjHero.hpp"

GameObjHero::GameObjHero()
{
    
}

GameObjHero::~GameObjHero()
{
    
}

void GameObjHero::setState(short var)
{
    
}

Rect GameObjHero::rect()
{
    auto s = Size(100 , 125);
    return Rect(-s.width / 2, -s.height / 2, s.width, s.height);
}

void GameObjHero::onEnter()
{
    
}

void GameObjHero::onExit()
{
    
}

void GameObjHero::jumpend()
{
    
}

void GameObjHero::hurtend()
{
    
}

bool GameObjHero::containsTouchLocation(Touch *touch)
{
    return rect().containsPoint(convertTouchToNodeSpaceAR(touch));
}

bool GameObjHero::onTouchBegin(Touch *touch, Event *event)
{
    return true;
}

void GameObjHero::onTouchEnded(Touch *touch, Event *event)
{
    
}

void GameObjHero::onTouchMoved(Touch *touch, Event *event)
{
    
}


