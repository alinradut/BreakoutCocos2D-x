#ifndef _GAME_OVER_SCENE_H_
#define _GAME_OVER_SCENE_H_

#include "cocos2d.h"

class GameOverLayer : public cocos2d::CCLayerColor
{
public:
    LAYER_NODE_FUNC(GameOverLayer);
    CC_SYNTHESIZE_READONLY(cocos2d::CCLabelTTF*, _label, Label);
	
    virtual ~GameOverLayer();
    bool init();
    void gameOverDone();
	
};

class GameOverScene : public cocos2d::CCScene
{
public:
    SCENE_NODE_FUNC(GameOverScene);
    CC_SYNTHESIZE_READONLY(GameOverLayer*, _layer, Layer);

    ~GameOverScene();
    bool init();
};

#endif // _GAME_OVER_SCENE_H_
