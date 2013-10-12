#include "TitleScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* Title::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Title *layer = Title::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Title::init()
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
    CCMenuItemImage *pCloseItem[5];

    pCloseItem[0] = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(Title::scenechangeCrossFadeCallback));
    pCloseItem[1] = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(Title::scenechangeFadeCallback));
    pCloseItem[2] = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(Title::scenechangeJumpZoomCallback));
    pCloseItem[3] = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(Title::scenechangeFlipAngular));
    pCloseItem[4] = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(Title::scenechangeSplitRowsCallback));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create();
    pMenu->setPosition(CCPointZero);
    for(int i = 0; i < 5; i++){
    	pCloseItem[i]->setPosition(ccp(origin.x + visibleSize.width/6 * (i+1),
                                    origin.y + visibleSize.height/2));
//    	pCloseItem[i]->setScale(1.0f);

    	pMenu->addChild(pCloseItem[i]);
    }
    CCLayerColor *color = CCLayerColor::create(ccc4(100,100,255,100));

    this->addChild(color,10);
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
    CCSprite* pSprite = CCSprite::create("Image/title.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    pSprite->setScaleX(visibleSize.width/480);
    pSprite->setScaleY(visibleSize.height/320);
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    return true;
}
void Title::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event){

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

void Title::update(float delta){

}


void Title::menuCloseCallback(CCObject* pSender)
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

void Title::scenechangeCrossFadeCallback(CCObject *pSender){
	CCScene *next = Title::scene();

	CCLog("Change:CrossFade");

	CCTransitionCrossFade *change = CCTransitionCrossFade::create(0.5f,next);

	CCDirector::sharedDirector()->replaceScene(change);
}
void Title::scenechangeSplitRowsCallback(CCObject *pSender){
	CCScene *next = Title::scene();

	CCLog("Change:RowsCallback");

	CCTransitionSplitRows *change = CCTransitionSplitRows::create(0.5f,next);

	CCDirector::sharedDirector()->replaceScene(change);
}
void Title::scenechangeFlipAngular(CCObject *pSender){
	CCScene *next = Title::scene();

	CCLog("Change:FlipAngular");

	CCTransitionFlipAngular *change = CCTransitionFlipAngular::create(3.0f,next);

	CCDirector::sharedDirector()->replaceScene(change);
}
void Title::scenechangeFadeCallback(CCObject *pSender){
	CCScene *next = Title::scene();

	CCLog("Change:FadeCallback");

	CCTransitionFade *change = CCTransitionFade::create(1.5f,next);

	CCDirector::sharedDirector()->replaceScene(change);
}

void Title::scenechangeJumpZoomCallback(CCObject *pSender){
	CCScene *next = Title::scene();

	CCLog("Change:JumpZoom");

	CCTransitionJumpZoom *change = CCTransitionJumpZoom::create(0.5f,next);

	CCDirector::sharedDirector()->replaceScene(change);
}
