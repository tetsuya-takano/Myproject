#include "HelloWorldScene.h"
#include "TitleScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    setTouchEnabled(true);
    CCLog("touchEnabled");
    setKeypadEnabled(true);
    CCLog("padEnabled");
    this->scheduleUpdate();
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::sceneChangeCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width/2 ,
                                origin.y + visibleSize.height/2));
	pCloseItem->setScale(3.0f);
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);

    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    CCSprite* testSprite = CCSprite::create("Image/canser.png");
    testSprite->setAnchorPoint(ccp(0.5f,0.5f));
    testSprite->setScale(3.0f);
    testSprite->setPosition(ccp(visibleSize.width/3,visibleSize.height/2));

    CCMoveTo* move = CCMoveTo::create(1.0f,ccp(visibleSize.width,visibleSize.height));
    testSprite->runAction(move);
    this->addChild(testSprite,2);


    return true;
}
void HelloWorld::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event){

	CCSetIterator it;
	CCTouch* touch;
	CCLog("Touch");
	for(it = touches->begin(); it != touches->end(); it++){
			touch = (CCTouch*)(*it);
			if(!touch){
				break;
			}

			CCPoint location = touch->getLocationInView();
			location = CCDirector::sharedDirector()->convertToGL(location);

			CCLog("touchEnded = {%f,%f}",location.x,location.y);
	}
}

void HelloWorld::update(float delta){
	CCLog("frame:%f",delta);
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

void HelloWorld::sceneChangeCallback(CCObject *pSender){
	CCScene *next = Title::scene();

	CCTransitionShrinkGrow *change = CCTransitionShrinkGrow::create(0.5f,next);

	CCDirector::sharedDirector()->replaceScene(change);

}
