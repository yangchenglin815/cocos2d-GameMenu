//
//  GameObjStar.cpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#include "GameObjStar.hpp"

GameObjStar::GameObjStar()
{
    
}

GameObjStar::~GameObjStar()
{
    
}

void GameObjStar::onEnter()
{
    Node::onEnter();
    
    //初始化星星
    this->setContentSize(Size(36.5, 36.5));
    auto star = Sprite::create("star.png");
    star->setScale(0.5f);
    m_visable = true;
    addChild(star, 1);
}

void GameObjStar::onExit()
{
    Node::onExit();
}

void GameObjStar::set_visable(bool var)
{
    m_visable = var;
    this->setVisible(var);
}

bool GameObjStar::get_visable()
{
    return m_visable;
}
