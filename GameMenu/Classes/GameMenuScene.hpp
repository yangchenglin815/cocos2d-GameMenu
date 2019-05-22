//
//  GameMenuScene.hpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#ifndef GameMenuScene_hpp
#define GameMenuScene_hpp

#include "cocos2d.h"

using namespace cocos2d;

class GameMenu : public cocos2d::Scene
{
public:
    bool m_isSound;
    
    MenuItemImage *m_soundItem;
    
    virtual bool init();
    
    virtual void onEnter();
    
    virtual void onExit();
    
    void menuEnter();
    
    static cocos2d::Scene* createScene();
    
    void menuNewGameCallback(cocos2d::Ref* pSender);
    
    void menuContinueCallback(cocos2d::Ref* pSender);
    
    void menuAboutCallback(cocos2d::Ref* pSender);
    
    void menuSoundCallback(cocos2d::Ref* pSender);
    
    void onEnterTransitionDidFinish();
    
    void onExitTransitionDidStart();
    
    CREATE_FUNC(GameMenu);
};

#endif /* GameMenuScene_hpp */
