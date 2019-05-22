//
//  GameMainScene.cpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#include "GameMainScene.hpp"

USING_NS_CC;

Scene* GameMain::createScene()
{
    return GameMain::create();
}

bool GameMain::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto size = Director::getInstance()->getWinSize();
    m_map = new GameObjMap();
    m_map->setAnchorPoint(Vec2(0, 1));
    m_map->setPosition(Vec2(0, size.height));
    addChild(m_map, 0);
    
    m_gameover = Sprite::create("gameover.png");
    m_gameover->setAnchorPoint(Vec2(0.5,0.5));
    m_gameover->setPosition(Vec2(0,0));
    m_gameover->setPosition(Vec2(size.width/2,size.height/2 + 70));
    m_gameover->setVisible(false);
    m_gameover->setScale(0.5);
    addChild(m_gameover,5);

    
    scheduleUpdate();
    return true;
}

void GameMain::onEnter()
{
    Scene::onEnter();
}

void GameMain::onExit()
{
    Scene::onExit();
}

void GameMain::isHeroDrop()
{
    
}

void GameMain::setOver()
{
    
}

void GameMain::menuBackCallback(cocos2d::Ref *pSender)
{
    
}

void GameMain::update(float time)
{
    
}

void GameMain::onEnterTransitionDidFinish()
{
    Scene::onEnterTransitionDidFinish();
    Director::getInstance()->setDepthTest(false);
}

void GameMain::onExitTransitionDidStart()
{
    Scene::onExitTransitionDidStart();
}

bool GameMain::isCollion(Point p1, Point p2, int w1, int h1, int w2, int h2)
{
    return true;
}
