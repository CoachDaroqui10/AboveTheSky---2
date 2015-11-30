#include "MainMenuScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();

	Label *_etiqueta;

	__String *text = __String::create("ABOVE THE SKY");
	_etiqueta = Label::createWithTTF(text->getCString(), "fonts/MArker Felt.ttf", 24);

	_etiqueta->setPosition(Vec2(visibleSize.width / 2, 3*(visibleSize.height) / 4));
	addChild(_etiqueta, 0);

	//Button

	auto button = MenuItemImage::create("CloseNormal.png",
		"CloseSelected.png", 
		CC_CALLBACK_1(MainMenuScene::goToGameScene, this));

	auto menu = Menu::create(button, NULL);

	menu->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));

	addChild(menu, 0);
    
    return true;
}

void MainMenuScene::goToGameScene(Ref *pSender){
	auto scene = GameScene::createScene();

	Director::getInstance()->replaceScene(scene);
}
