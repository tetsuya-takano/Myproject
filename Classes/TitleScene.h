#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class Title : public cocos2d::CCLayerGradient
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

    void scenechangeCrossFadeCallback(CCObject* pSender);
    void scenechangeSplitRowsCallback(CCObject* pSender);
    void scenechangeFlipAngular(CCObject* pSender);
    void scenechangeFadeCallback(CCObject* pSender);
    void scenechangeJumpZoomCallback(CCObject* pSender);

    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    virtual void update(float delta);

    void playSound(const char *filepath);

private:
    CCSprite* pSprite;

    // implement the "static node()" method manually
    CREATE_FUNC(Title);

};

#endif // __HELLOWORLD_SCENE_H__
