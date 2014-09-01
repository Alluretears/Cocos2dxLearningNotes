#ifndef __MY_SCENE_H__
#define __MY_SCENE_H__

#include "cocos2d.h"

class MyScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	cocos2d::LayerMultiplex* layer;

	CREATE_FUNC(MyScene);
	/*
	#define CREATE_FUNC(__TYPE__) \
	static __TYPE__* create() \
	{ \
	__TYPE__ *pRet = new __TYPE__(); \
	if (pRet && pRet->init()) \
	{ \
	pRet->autorelease(); \
	return pRet; \
	} \
	else \
	{ \
	delete pRet; \
	pRet = NULL; \
	return NULL; \
	} \
	}
	
	通过CREATE_FUNC()宏实现了cocos2dx中的对象的内存管理，使开发者不需要在开发的时候担心内存问题。
	该宏里面首先new一个对象，执行autorelease()方法，在该对象的引用计数为0时，delete这个对象，彻底释放内存。
	
	*/

	//菜单回调方法
	void menuCallback(cocos2d::Ref* pSender);
	//标记当前层的位置
	int curLayerPos = 0;

};
#endif