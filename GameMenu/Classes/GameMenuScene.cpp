//
//  GameMenuScene.cpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#include "GameMenuScene.hpp"
#include "SimpleAudioEngine.h"
#include "GameMainScene.hpp"
#include "GameAboutScene.hpp"

using namespace cocos2d;
using namespace CocosDenshion;

USING_NS_CC;

Scene* GameMenu::createScene()
{
    return GameMenu::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool GameMenu::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto size = Director::getInstance()->getWinSize();
    
    //菜单背景
    auto bg = Sprite::create("MainMenu.png");
    if ( bg == nullptr )
    {
        problemLoading("'MainMenu.png'");
    }
    else
    {
        bg->setScale(0.5f);
        bg->setPosition(Vec2(size.width / 2, size.height / 2));
        this->addChild(bg, 0, 0);
    }
    
    //按钮
    auto newGameItem = MenuItemImage::create(
                                             "newgameA.png",
                                             "newgameB.png",
                                             CC_CALLBACK_1(GameMenu::menuNewGameCallback, this));
    if ( newGameItem == nullptr ||
        newGameItem->getContentSize().width <= 0 ||
        newGameItem->getContentSize().height <= 0 )
    {
        problemLoading("'newgameA.png' and 'newgameB.png'");
    }
    else
    {
        newGameItem->setScale(0.5f);
        newGameItem->setPosition(Vec2(size.width / 2 + 40, size.height / 2 - 20));
        newGameItem->setEnabled(false);
    }
    
    auto continueItem = MenuItemImage::create(
                                              "continueA.png",
                                              "continueB.png",
                                              CC_CALLBACK_1(GameMenu::menuContinueCallback, this));
    if ( continueItem == nullptr ||
        continueItem->getContentSize().width <= 0 ||
        continueItem->getContentSize().height <= 0 )
    {
        problemLoading("'continueA.png' and 'continueB.png'");
    }
    else
    {
        continueItem->setScale(0.5f);
        continueItem->setPosition(Vec2(size.width / 2 + 40, size.height / 2 - 60));
        continueItem->setEnabled(false);
    }
    
    auto aboutItem = MenuItemImage::create(
                                              "aboutA.png",
                                              "aboutB.png",
                                              CC_CALLBACK_1(GameMenu::menuAboutCallback, this));
    if ( aboutItem == nullptr ||
        aboutItem->getContentSize().width <= 0 ||
        aboutItem->getContentSize().height <= 0 )
    {
        problemLoading("'aboutA.png' and 'aboutB.png'");
    }
    else
    {
        aboutItem->setScale(0.5f);
        aboutItem->setPosition(Vec2(size.width / 2 + 40, size.height / 2 - 100));
        aboutItem->setEnabled(false);
    }
    
    m_soundItem = MenuItemImage::create(
                                           "sound-on-A.png",
                                           "sound-on-B.png",
                                           CC_CALLBACK_1(GameMenu::menuSoundCallback, this));
    if ( m_soundItem == nullptr ||
        m_soundItem->getContentSize().width <= 0 ||
        m_soundItem->getContentSize().height <= 0 )
    {
        problemLoading("'sound-on-A.png' and 'sound-on-B.png'");
    }
    else
    {
        m_soundItem->setScale(0.5f);
        m_soundItem->setPosition(Vec2(40, 40));
        m_soundItem->setEnabled(false);
    }
    
    auto mainMenu = Menu::create(newGameItem, continueItem, aboutItem, m_soundItem, NULL);
    mainMenu->setPosition(Vec2(0, 0));
    this->addChild(mainMenu, 1, 3);
    
    //初始化声音
    m_isSound = true;
    std::string path = FileUtils::getInstance()->fullPathForFilename("background.mp3");
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(path.c_str());
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5f);
    SimpleAudioEngine::getInstance()->playBackgroundMusic(path.c_str(), true);
    
    return true;
}

void GameMenu::menuNewGameCallback(Ref* pSender)
{
    Director::getInstance()->setDepthTest(true);
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5, GameMain::createScene(), false));
}

void GameMenu::menuContinueCallback(Ref* pSender)
{
    Director::getInstance()->setDepthTest(true);
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5, GameMain::createScene(), false));
}

void GameMenu::menuAboutCallback(cocos2d::Ref *pSender)
{
    Director::getInstance()->setDepthTest(true);
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5, GameAbout::createScene(), false));
}

void GameMenu::menuSoundCallback(cocos2d::Ref *pSender)
{
    if ( !m_isSound )
    {
        m_soundItem->setNormalImage(Sprite::create("sound-on-A.png"));
        m_soundItem->setDisabledImage(Sprite::create("sound-on-B.png"));
        std::string path = FileUtils::getInstance()->fullPathForFilename("background.mp3");
        SimpleAudioEngine::getInstance()->playBackgroundMusic(path.c_str(), true);
        m_isSound = true;
    }
    else
    {
        m_soundItem->setNormalImage(Sprite::create("sound-off-A.png"));
        m_soundItem->setDisabledImage(Sprite::create("sound-off-B.png"));
        SimpleAudioEngine::getInstance()->stopBackgroundMusic();
        m_isSound = false;
    }
}

void GameMenu::onEnter()
{
    Scene::onEnter();
    
    //入场动作
    auto size = Director::getInstance()->getWinSize();
    auto mainMenu = this->getChildByTag(3);
    mainMenu->setScale(0);
    auto action = Sequence::create(ScaleTo::create(0.5, 1), CallFunc::create(this, callfunc_selector(GameMenu::menuEnter)), NULL);
    mainMenu->runAction(action);
}

void GameMenu::onExit()
{
    Scene::onExit();
}

void GameMenu::menuEnter()
{
    auto mainMenu = this->getChildByTag(3);
    auto temp = mainMenu->getChildren();
    for (int i = 0; i < (int)(temp.size()); ++i)
        ((MenuItemImage *)temp.at(i))->setEnabled(true);
}

void GameMenu::onEnterTransitionDidFinish()
{
    Scene::onEnterTransitionDidFinish();
    Director::getInstance()->setDepthTest(false);
}

void GameMenu::onExitTransitionDidStart()
{
    Scene::onExitTransitionDidStart();
}
