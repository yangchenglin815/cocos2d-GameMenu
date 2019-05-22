//
//  GameObjStar.hpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#ifndef GameObjStar_hpp
#define GameObjStar_hpp

#include "cocos2d.h"

using namespace cocos2d;

class GameObjStar : public Node
{
public:
    GameObjStar(void);
    short m_state;
    virtual ~GameObjStar(void);
    virtual void onEnter();
    virtual void onExit();
    bool m_visable;
    void set_visable(bool var);
    bool get_visable();
};

#endif /* GameObjStar_hpp */
