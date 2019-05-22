//
//  GameAboutScene.hpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#ifndef GameAboutScene_hpp
#define GameAboutScene_hpp

#include "cocos2d.h"

using namespace cocos2d;

class GameAbout : public cocos2d::Scene
{
public:
    virtual bool init();
    
    virtual void onEnter();
    
    virtual void onExit();
    
    static cocos2d::Scene* createScene();
    
    void menuBackCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(GameAbout);
    
    void onEnterTransitionDidFinish();
    
    void onExitTransitionDidStart();
};

#endif /* GameAboutScene_hpp */
