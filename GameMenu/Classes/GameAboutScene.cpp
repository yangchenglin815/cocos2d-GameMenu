//
//  GameAboutScene.cpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#include "GameAboutScene.hpp"

Scene* GameAbout::createScene()
{
    return GameAbout::create();
}

bool GameAbout::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    return true;
}

void GameAbout::onEnter()
{
    
}

void GameAbout::onExit()
{
    
}

void GameAbout::menuBackCallback(Ref* pSender)
{
    
}

void GameAbout::onEnterTransitionDidFinish()
{
    
}

void GameAbout::onExitTransitionDidStart()
{
    
}
