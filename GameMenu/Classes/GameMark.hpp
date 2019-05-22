//
//  GameMark.hpp
//  GameMenu
//
//  Created by 杨承霖 on 2019/5/15.
//

#ifndef GameMark_hpp
#define GameMark_hpp

#include "cocos2d.h"

using namespace cocos2d;

class GameMark : public Node
{
public:
    GameMark(void);
    virtual ~GameMark(void);
    virtual void onEnter();
    virtual void onExit();
    
    Array * m_bits;
    int m_mark;
    
    void addNumber(int var);
    Texture2D * m_ui;
};

#endif /* GameMark_hpp */
