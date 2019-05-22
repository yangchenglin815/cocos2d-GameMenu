//
//  GameObjMap.hpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#ifndef GameObjMap_hpp
#define GameObjMap_hpp

#include "cocos2d.h"

using namespace cocos2d;

class GameObjMap : public Node
{
public:
    GameObjMap(void);
    short m_state;
    virtual ~GameObjMap(void);
    virtual void onEnter();
    virtual void onExit();
    void bg1Change();
    void bg2Change();
    Vector<Node*> m_star1;
    Vector<Node*> m_star2;
};

#endif /* GameObjMap_hpp */
