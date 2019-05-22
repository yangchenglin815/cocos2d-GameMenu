//
//  GameObjMap.cpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#include "GameObjMap.hpp"
#include "GameConst.h"
#include "GameObjStar.hpp"

GameObjMap::GameObjMap()
{
    
}

GameObjMap::~GameObjMap()
{
    
}

void GameObjMap::bg1Change()
{
    //运动出屏幕重设位置，运动
    auto bg = (Sprite *)this->getChildByTag(0);
    bg->setPosition(Vec2(480, 320));
    
    auto action = Sequence::create(MoveBy::create(20, Vec2(-960, 0)), CallFunc::create(this, callfunc_selector(GameObjMap::bg1Change)), NULL);
    bg->runAction(action);
  //  for (int i = 0; i < 5; i++)
        
}

void GameObjMap::bg2Change()
{
    //运动出屏幕重设位置，运动
    auto bg = (Sprite *)this->getChildByTag(1);
    bg->setPosition(Vec2(480, 320));
    
    auto action = Sequence::create(MoveBy::create(20, Vec2(-960, 0)), CallFunc::create(this, callfunc_selector(GameObjMap::bg2Change)), NULL);
    bg->runAction(action);
}

void GameObjMap::onExit()
{
    Node::onExit();
}

void GameObjMap::onEnter()
{
    Node::onEnter();
    
    auto size = Director::getInstance()->getWinSize();
    this->setContentSize(Size(960, 320));
    
    auto bg1 = Sprite::create("back_1.png");
    bg1->setScale(0.5f);
    bg1->setAnchorPoint(Vec2(0, 1));
    bg1->setPosition(Vec2(0, size.height));
    this->addChild(bg1, 0, 0);
    auto bgdi1 = Sprite::create("back_5.png");
    bgdi1->setAnchorPoint(Vec2(0,0));
    bgdi1->setPosition(Vec2(0,-124) );
    bg1->addChild(bgdi1,1);
    auto bg2 = Sprite::create("back_1.png");
    bg2->setScale(0.5);
    bg2->setAnchorPoint(Vec2(0,1));
    bg2->setPosition(Vec2(size.width, size.height) );
    this->addChild(bg2,0,1);
    auto bgdi2 = Sprite::create("back_5.png");
    bgdi2->setAnchorPoint(Vec2(0,0));
    bgdi2->setPosition(Vec2(0,-124) );
    bg2->addChild(bgdi2,1);
    auto action1 = Sequence::create(MoveBy::create(10, Vec2(-480, 0)), CallFunc::create(this, callfunc_selector(GameObjMap::bg1Change)), NULL);
    bg1->runAction(action1);
    auto action2 = Sequence::create(MoveBy::create(20, Vec2(-960, 0)), CallFunc::create(this, callfunc_selector(GameObjMap::bg2Change)), NULL);
    bg2->runAction(action2);
    
    
}
