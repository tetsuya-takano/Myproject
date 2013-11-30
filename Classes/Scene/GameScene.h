#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "../Character/Player.h"
#include "../Character/Enemy.h"

using namespace cocos2d;

class Game : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    // Layer


    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    void buttonPushCallback(CCObject* pSender);

    virtual bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
    virtual void ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent);

    virtual void update(float delta);

    void playSound(const char *filepath);
    CCSprite* getPackageSprite(const char* fileName);
private:
    Player* pPlayer;
    Enemy*	pEnemy;

    CCLabelBMFont* pFont;
    CCSpriteBatchNode* batchNode;
    CCDrawNode* dot;

    CCPoint mTouchStartPos;
    CCPoint mTouchMovePos;
    CCPoint mDelta;
    CCPoint mPlayerDefPos;


    int count;
    // implement the "static node()" method manually
    CREATE_FUNC(Game);

};




#endif
