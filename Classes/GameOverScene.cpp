/*
 *  GameOverScene.cpp
 *  SimpleGame
 *
 *  Created by Clawoo on 8/10/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "GameOverScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

bool GameOverLayer::init()
{
	if (!CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)))
	{
		return false;
	}
	
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	this->_label = CCLabelTTF::labelWithString("", "Arial", 12);
	this->_label->retain();
	this->getLabel()->setColor(ccc3(0,0,0));
	this->getLabel()->setPosition(ccp(winSize.width/2, winSize.height/2));
	this->addChild(_label);
	
	this->runAction(CCSequence::actions(CCDelayTime::actionWithDuration(3),
										CCCallFunc::actionWithTarget(this, callfunc_selector(GameOverLayer::gameOverDone)),
										NULL));
	
	return true;
}

void GameOverLayer::gameOverDone()
{
	CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

GameOverLayer::~GameOverLayer()
{
	_label->release();
}

bool GameOverScene::init()
{
	if( CCScene::init() )
	{
		this->_layer = GameOverLayer::node();
		this->_layer->retain();
		this->addChild(_layer);
		
		return true;
	}
	else
	{
		return false;
	}
}

GameOverScene::~GameOverScene()
{
	if (_layer)
	{
		_layer->release();
		_layer = NULL;
	}
}