/*
创建一个名为MyScene的场景
*/

#include "MyScene.h"

USING_NS_CC;

Scene* MyScene::createScene(){

	auto scene = Scene::create();

	auto layer = MyScene::create();

	scene->addChild(layer);

	return scene;

}
bool MyScene::init(){
	if (!Layer::init())
	{
		return false;
	}
	//获取可视屏幕大小
	Size size = Director::getInstance()->getVisibleSize();

	//分别创建3个颜色层，红、绿、蓝
	auto layer1 = LayerColor::create(ccc4(255, 0, 0, 255));

	auto layer2 = LayerColor::create(ccc4(0, 255, 0, 255));

	auto layer3 = LayerColor::create(ccc4(0, 0, 255, 255));

	//创建多层布景层，将3个颜色层添加进去
	layer = LayerMultiplex::create(layer1, layer2, layer3, NULL);

	this->addChild(layer);
	//创建一个label
	auto label = LabelTTF::create("Show Icon", "Courier", 40);

	this->addChild(label,1);
	//设置label的位置（参数在3.1之后改为一个二维矢量而不是之前的Point）
	label->setPosition(Vec2(size.width / 2 , size.height / 2+100.0f));

	//创建3个菜单
	auto item1 = MenuItemFont::create("Menu1",CC_CALLBACK_1(MyScene::menuCallback,this));

	auto item2 = MenuItemFont::create("Menu2",CC_CALLBACK_1(MyScene::menuCallback, this));

	auto item3 = MenuItemFont::create("Menu3",CC_CALLBACK_1(MyScene::menuCallback, this));

	//给菜单添加Tag，方便在回调函数中找到这3个菜单
	item1->setTag(0);

	item2->setTag(1);

	item3->setTag(2);

	//添加菜单至menu
	auto menu = Menu::create(item1, item2, item3, NULL);

	//设置菜单间的间隔
	menu->alignItemsHorizontallyWithPadding(10.0f);

	menu->setPosition(Vec2(size.width/2,20));

	//菜单层应处于颜色层的上面，否则将看不到菜单
	this->addChild(menu,1);

	//创建一个精灵
	auto icon = Sprite::create("icon.png");

	icon->setPosition(Vec2(size.width/2,size.height/2));

	this->addChild(icon,1);
	
	return true;
}
//菜单的回调方法
void MyScene::menuCallback(cocos2d::Ref* pSender){
	//获取颜色层Tag
	int i = ((MenuItemFont*)pSender)->getTag();
	//实现类似TableView的效果
	if (i !=curLayerPos)
	{
		layer->switchTo(i);
		//使用cocos2dx的log输出当前层
		log("You are on the layer%d",i+1);
		curLayerPos = i;
	}
}