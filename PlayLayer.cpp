#include "pch.h"
bool __fastcall PlayLayer::hook(gd::PlayLayer* self, int, void* level) {
    auto director = cocos2d::CCDirector::sharedDirector();
    auto size = director->getWinSize();
    bool result = PlayLayer::init(self, level);
    auto children = self->getChildren();
    auto layer = dynamic_cast<CCLayer*>(children->objectAtIndex(3));
    auto layerChildren = layer->getChildren();
    auto attemptText = dynamic_cast<CCLabelBMFont*>(layerChildren->objectAtIndex(76));
    attemptText->setScaleY(1.0F);
    return result;
}
