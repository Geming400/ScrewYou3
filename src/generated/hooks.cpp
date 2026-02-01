// Generated using 'generate.py'
#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include "../ScrewYou3Manager.hpp"
#include "../utils.hpp"

using namespace geode::prelude;

// Cursed macros but whatever, this isn't supposed to be the most readable thing after all
// Also haii !!!
// :3

#define SCREWYOU3_MENULAYER_CUSTOM_INIT(className, funcName, ...) \
    if (ScrewYou3Manager::get()->isKilled(fmt::format("{}::{}", className::CLASS_NAME, #funcName)) && Mod::get()->getSettingValue<bool>("enabled")) \
        return className##_##funcName##_override(); \
    else \
		if (Mod::get()->getSavedValue<bool>("first-time-loading", true)) { \
			Mod::get()->setSavedValue<bool>("first-time-loading", false); \
			auto alert = FLAlertLayer::create( \
				"Before you continue", \
				"This mod CAN corrupt the game. Be sure to read this mod's description before continuing", \
				"Dismiss" \
			); \
			alert->m_scene = this; \
			alert->show(); \
		} \
        return className::funcName(__VA_ARGS__); \
};

#define SCREWYOU3_HOOK_BEGIN(className) class $modify(Screwd##className, className) {
// I'm putting the min value for an int32 for the hook priority
// I'm terribly sorry but I had no choice
// (It's for the funnies :33)
#define SCREWYOU3_HOOK_END(hookedFunction) \
    static void onModify(auto& self) { \
        if (!self.setHookPriority(hookedFunction, -2147483648)) { \
            geode::log::warn("hi"); \
        } \
    } \
};

#define SCREWYOU3_HOOK(funcSignature) funcSignature {
#define SCREWYOU3_HOOK_IMPL(className, funcName, ...) \
    if (ScrewYou3Manager::get()->isKilled(fmt::format("{}::{}", className::CLASS_NAME, #funcName)) && Mod::get()->getSettingValue<bool>("enabled")) \
        return className##_##funcName##_override(); \
    else \
        return className::funcName(__VA_ARGS__); \
};

// Hooking classes
// You might notice that the 'GEODE_IS_DEKSTOP' and 'GEODE_IS_MOBILE' macros aren't used, this is just because
// this file was automatically generated, so I just didn't want to bother with that, not like it was going
// to change a thing either way

#include <Geode/modify/AccountLoginLayer.hpp>

bool AccountLoginLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AccountLoginLayer)
SCREWYOU3_HOOK(bool init(gd::string username))
SCREWYOU3_HOOK_IMPL(AccountLoginLayer, init, username)
SCREWYOU3_HOOK_END("AccountLoginLayer::init")

#include <Geode/modify/AccountRegisterLayer.hpp>

bool AccountRegisterLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool AccountRegisterLayer_allowTextInput_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AccountRegisterLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(AccountRegisterLayer, init, )
SCREWYOU3_HOOK(bool allowTextInput(CCTextInputNode* node))
SCREWYOU3_HOOK_IMPL(AccountRegisterLayer, allowTextInput, node)
SCREWYOU3_HOOK_END("AccountRegisterLayer::init")

#include <Geode/modify/AchievementBar.hpp>

bool AchievementBar_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AchievementBar)
SCREWYOU3_HOOK(bool init(char const* title, char const* desc, char const* icon, bool quest))
SCREWYOU3_HOOK_IMPL(AchievementBar, init, title, desc, icon, quest)
SCREWYOU3_HOOK_END("AchievementBar::init")

#include <Geode/modify/AchievementManager.hpp>

bool AchievementManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string AchievementManager_achievementForUnlock_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool AchievementManager_isAchievementEarned_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int AchievementManager_percentForAchievement_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(AchievementManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(AchievementManager, init, )
SCREWYOU3_HOOK(gd::string achievementForUnlock(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(AchievementManager, achievementForUnlock, id, type)
SCREWYOU3_HOOK(bool isAchievementEarned(char const* ach))
SCREWYOU3_HOOK_IMPL(AchievementManager, isAchievementEarned, ach)
SCREWYOU3_HOOK(int percentForAchievement(char const* id))
SCREWYOU3_HOOK_IMPL(AchievementManager, percentForAchievement, id)
SCREWYOU3_HOOK_END("AchievementManager::init")

#include <Geode/modify/AchievementNotifier.hpp>

bool AchievementNotifier_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AchievementNotifier)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(AchievementNotifier, init, )
SCREWYOU3_HOOK_END("AchievementNotifier::init")

#include <Geode/modify/AdToolbox.hpp>

bool AdToolbox_hasCachedInterstitial_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool AdToolbox_hasCachedRewardedVideo_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool AdToolbox_isShowingAd_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AdToolbox)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool hasCachedInterstitial())
SCREWYOU3_HOOK_IMPL(AdToolbox, hasCachedInterstitial, )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool hasCachedRewardedVideo())
SCREWYOU3_HOOK_IMPL(AdToolbox, hasCachedRewardedVideo, )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool isShowingAd())
SCREWYOU3_HOOK_IMPL(AdToolbox, isShowingAd, )
#endif
SCREWYOU3_HOOK_END("AdToolbox::hasCachedInterstitial")

#include <Geode/modify/AdvancedFollowEditObject.hpp>

gd::string AdvancedFollowEditObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(AdvancedFollowEditObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(AdvancedFollowEditObject, getSaveString, layer)
SCREWYOU3_HOOK_END("AdvancedFollowEditObject::getSaveString")

#include <Geode/modify/AdvancedFollowTriggerObject.hpp>

gd::string AdvancedFollowTriggerObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(AdvancedFollowTriggerObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(AdvancedFollowTriggerObject, getSaveString, layer)
SCREWYOU3_HOOK_END("AdvancedFollowTriggerObject::getSaveString")

#include <Geode/modify/AnimatedGameObject.hpp>

gd::string AnimatedGameObject_animationForID_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool AnimatedGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AnimatedGameObject)
SCREWYOU3_HOOK(static gd::string animationForID(int type, int id))
SCREWYOU3_HOOK_IMPL(AnimatedGameObject, animationForID, type, id)
SCREWYOU3_HOOK(bool init(int id))
SCREWYOU3_HOOK_IMPL(AnimatedGameObject, init, id)
SCREWYOU3_HOOK_END("AnimatedGameObject::animationForID")

#include <Geode/modify/AppDelegate.hpp>

bool AppDelegate_applicationDidFinishLaunching_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool AppDelegate_musicTest_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AppDelegate)
SCREWYOU3_HOOK(bool applicationDidFinishLaunching())
SCREWYOU3_HOOK_IMPL(AppDelegate, applicationDidFinishLaunching, )
SCREWYOU3_HOOK(bool musicTest())
SCREWYOU3_HOOK_IMPL(AppDelegate, musicTest, )
SCREWYOU3_HOOK_END("AppDelegate::applicationDidFinishLaunching")

#include <Geode/modify/ArtistCell.hpp>

bool ArtistCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ArtistCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ArtistCell, init, )
SCREWYOU3_HOOK_END("ArtistCell::init")

#include <Geode/modify/ArtTriggerGameObject.hpp>

gd::string ArtTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(ArtTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(ArtTriggerGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("ArtTriggerGameObject::getSaveString")

#include <Geode/modify/AudioAssetsBrowser.hpp>

bool AudioAssetsBrowser_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AudioAssetsBrowser)
SCREWYOU3_HOOK(bool init(gd::vector<int>& songIds, gd::vector<int>& sfxIds))
SCREWYOU3_HOOK_IMPL(AudioAssetsBrowser, init, songIds, sfxIds)
SCREWYOU3_HOOK_END("AudioAssetsBrowser::init")

#include <Geode/modify/AudioEffectsLayer.hpp>

bool AudioEffectsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AudioEffectsLayer)
SCREWYOU3_HOOK(bool init(gd::string audioString))
SCREWYOU3_HOOK_IMPL(AudioEffectsLayer, init, audioString)
SCREWYOU3_HOOK_END("AudioEffectsLayer::init")

#include <Geode/modify/AudioLineGuideGameObject.hpp>

bool AudioLineGuideGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string AudioLineGuideGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(AudioLineGuideGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(AudioLineGuideGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(AudioLineGuideGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("AudioLineGuideGameObject::init")

#include <Geode/modify/BonusDropdown.hpp>

bool BonusDropdown_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(BonusDropdown)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(gd::string text, int price))
SCREWYOU3_HOOK_IMPL(BonusDropdown, init, text, price)
#endif
SCREWYOU3_HOOK_END("BonusDropdown::init")

#include <Geode/modify/BoomListLayer.hpp>

bool BoomListLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(BoomListLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(BoomListView* listView, char const* title))
SCREWYOU3_HOOK_IMPL(BoomListLayer, init, listView, title)
#endif
SCREWYOU3_HOOK_END("BoomListLayer::init")

#include <Geode/modify/BoomListView.hpp>

float BoomListView_cellHeightForRowAtIndexPath_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int BoomListView_numberOfRowsInSection_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool BoomListView_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(BoomListView)
SCREWYOU3_HOOK(float cellHeightForRowAtIndexPath(CCIndexPath& indexPath, TableView* tableView))
SCREWYOU3_HOOK_IMPL(BoomListView, cellHeightForRowAtIndexPath, indexPath, tableView)
SCREWYOU3_HOOK(int numberOfRowsInSection(unsigned int section, TableView* tableView))
SCREWYOU3_HOOK_IMPL(BoomListView, numberOfRowsInSection, section, tableView)
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* entries, TableViewCellDelegate* delegate, float height, float width, int page, BoomListType type, float y))
SCREWYOU3_HOOK_IMPL(BoomListView, init, entries, delegate, height, width, page, type, y)
SCREWYOU3_HOOK_END("BoomListView::cellHeightForRowAtIndexPath")

#include <Geode/modify/BoomScrollLayer.hpp>

bool BoomScrollLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool BoomScrollLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int BoomScrollLayer_pageNumberForPosition_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(BoomScrollLayer)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(BoomScrollLayer, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* pages, int offset, bool looped, cocos2d::CCArray* dynamicObjects, DynamicScrollDelegate* delegate))
SCREWYOU3_HOOK_IMPL(BoomScrollLayer, init, pages, offset, looped, dynamicObjects, delegate)
SCREWYOU3_HOOK(int pageNumberForPosition(cocos2d::CCPoint position))
SCREWYOU3_HOOK_IMPL(BoomScrollLayer, pageNumberForPosition, position)
SCREWYOU3_HOOK_END("BoomScrollLayer::ccTouchBegan")

#include <Geode/modify/BrowseSmartKeyLayer.hpp>

bool BrowseSmartKeyLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(BrowseSmartKeyLayer)
SCREWYOU3_HOOK(bool init(GJSmartTemplate* smartTemplate, gd::string prefabKey))
SCREWYOU3_HOOK_IMPL(BrowseSmartKeyLayer, init, smartTemplate, prefabKey)
SCREWYOU3_HOOK_END("BrowseSmartKeyLayer::init")

#include <Geode/modify/BrowseSmartTemplateLayer.hpp>

bool BrowseSmartTemplateLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(BrowseSmartTemplateLayer)
SCREWYOU3_HOOK(bool init(GJSmartTemplate* smartTemplate, SmartBrowseFilter browseFilter))
SCREWYOU3_HOOK_IMPL(BrowseSmartTemplateLayer, init, smartTemplate, browseFilter)
SCREWYOU3_HOOK_END("BrowseSmartTemplateLayer::init")

#include <Geode/modify/ButtonSprite.hpp>

bool ButtonSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ButtonSprite)
SCREWYOU3_HOOK(bool init(char const* caption, int width, int minWidth, float scale, bool absolute, char const* font, char const* bg, float height))
SCREWYOU3_HOOK_IMPL(ButtonSprite, init, caption, width, minWidth, scale, absolute, font, bg, height)
SCREWYOU3_HOOK(bool init(cocos2d::CCSprite* topSprite, int width, int minWidth, float height, float scale, bool absolute, char const* bgSprite, bool noScaleSpriteForBG))
SCREWYOU3_HOOK_IMPL(ButtonSprite, init, topSprite, width, minWidth, height, scale, absolute, bgSprite, noScaleSpriteForBG)
SCREWYOU3_HOOK_END("ButtonSprite::init")

#include <Geode/modify/CameraTriggerGameObject.hpp>

gd::string CameraTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(CameraTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(CameraTriggerGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("CameraTriggerGameObject::getSaveString")

#include <Geode/modify/CCAlertCircle.hpp>

bool CCAlertCircle_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCAlertCircle)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCAlertCircle, init, )
#endif
SCREWYOU3_HOOK_END("CCAlertCircle::init")

#include <Geode/modify/CCAnimatedSprite.hpp>

bool CCAnimatedSprite_initWithType_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCAnimatedSprite)
SCREWYOU3_HOOK(bool initWithType(char const* definition, cocos2d::CCTexture2D* texture, bool useTexture))
SCREWYOU3_HOOK_IMPL(CCAnimatedSprite, initWithType, definition, texture, useTexture)
SCREWYOU3_HOOK_END("CCAnimatedSprite::initWithType")

#include <Geode/modify/CCBlockLayer.hpp>

bool CCBlockLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCBlockLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCBlockLayer, init, )
SCREWYOU3_HOOK_END("CCBlockLayer::init")

#include <Geode/modify/CCCircleAlert.hpp>

bool CCCircleAlert_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCCircleAlert)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(float duration, float startRadius, float endRadius))
SCREWYOU3_HOOK_IMPL(CCCircleAlert, init, duration, startRadius, endRadius)
#endif
SCREWYOU3_HOOK_END("CCCircleAlert::init")

#include <Geode/modify/CCCircleWave.hpp>

bool CCCircleWave_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCCircleWave)
SCREWYOU3_HOOK(bool init(float startRadius, float endRadius, float duration, bool fadeIn, bool easeOut))
SCREWYOU3_HOOK_IMPL(CCCircleWave, init, startRadius, endRadius, duration, fadeIn, easeOut)
SCREWYOU3_HOOK_END("CCCircleWave::init")

#include <Geode/modify/CCCountdown.hpp>

bool CCCountdown_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCCountdown)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCCountdown, init, )
#endif
SCREWYOU3_HOOK_END("CCCountdown::init")

#include <Geode/modify/CCMenuItemSpriteExtra.hpp>

bool CCMenuItemSpriteExtra_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCMenuItemSpriteExtra)
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* sprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback))
SCREWYOU3_HOOK_IMPL(CCMenuItemSpriteExtra, init, sprite, selectedSprite, target, callback)
SCREWYOU3_HOOK_END("CCMenuItemSpriteExtra::init")

#include <Geode/modify/CCNodeContainer.hpp>

bool CCNodeContainer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCNodeContainer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCNodeContainer, init, )
SCREWYOU3_HOOK_END("CCNodeContainer::init")

#include <Geode/modify/CCPartAnimSprite.hpp>

bool CCPartAnimSprite_isFrameDisplayed_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CCPartAnimSprite_initWithAnimDesc_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCPartAnimSprite)
SCREWYOU3_HOOK(bool isFrameDisplayed(cocos2d::CCSpriteFrame* frame))
SCREWYOU3_HOOK_IMPL(CCPartAnimSprite, isFrameDisplayed, frame)
SCREWYOU3_HOOK(bool initWithAnimDesc(char const* definition, cocos2d::CCTexture2D* texture, bool useTexture))
SCREWYOU3_HOOK_IMPL(CCPartAnimSprite, initWithAnimDesc, definition, texture, useTexture)
SCREWYOU3_HOOK_END("CCPartAnimSprite::isFrameDisplayed")

#include <Geode/modify/CCScrollLayerExt.hpp>

bool CCScrollLayerExt_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCScrollLayerExt)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(CCScrollLayerExt, ccTouchBegan, touch, event)
SCREWYOU3_HOOK_END("CCScrollLayerExt::ccTouchBegan")

#include <Geode/modify/CCSpriteGrayscale.hpp>

gd::string CCSpriteGrayscale_getShaderName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* CCSpriteGrayscale_shaderBody_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(CCSpriteGrayscale)
SCREWYOU3_HOOK(gd::string getShaderName())
SCREWYOU3_HOOK_IMPL(CCSpriteGrayscale, getShaderName, )
SCREWYOU3_HOOK(const char* shaderBody())
SCREWYOU3_HOOK_IMPL(CCSpriteGrayscale, shaderBody, )
SCREWYOU3_HOOK_END("CCSpriteGrayscale::getShaderName")

#include <Geode/modify/CCSpritePlus.hpp>

bool CCSpritePlus_initWithTexture_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CCSpritePlus_initWithSpriteFrameName_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCSpritePlus)
SCREWYOU3_HOOK(bool initWithTexture(cocos2d::CCTexture2D* texture))
SCREWYOU3_HOOK_IMPL(CCSpritePlus, initWithTexture, texture)
SCREWYOU3_HOOK(bool initWithSpriteFrameName(char const* frameName))
SCREWYOU3_HOOK_IMPL(CCSpritePlus, initWithSpriteFrameName, frameName)
SCREWYOU3_HOOK_END("CCSpritePlus::initWithTexture")

#include <Geode/modify/CCSpriteWithHue.hpp>

bool CCSpriteWithHue_initWithTexture_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CCSpriteWithHue_initWithSpriteFrame_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string CCSpriteWithHue_getShaderName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* CCSpriteWithHue_shaderBody_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(CCSpriteWithHue)
SCREWYOU3_HOOK(bool initWithTexture(cocos2d::CCTexture2D* texture))
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, initWithTexture, texture)
SCREWYOU3_HOOK(bool initWithTexture(cocos2d::CCTexture2D* texture, cocos2d::CCRect const& rect))
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, initWithTexture, texture, rect)
SCREWYOU3_HOOK(bool initWithTexture(cocos2d::CCTexture2D* texture, cocos2d::CCRect const& rect, bool rotated))
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, initWithTexture, texture, rect, rotated)
SCREWYOU3_HOOK(bool initWithSpriteFrame(cocos2d::CCSpriteFrame* frame))
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, initWithSpriteFrame, frame)
SCREWYOU3_HOOK(gd::string getShaderName())
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, getShaderName, )
SCREWYOU3_HOOK(const char* shaderBody())
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, shaderBody, )
SCREWYOU3_HOOK_END("CCSpriteWithHue::initWithTexture")

#include <Geode/modify/CCTextInputNode.hpp>

bool CCTextInputNode_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CCTextInputNode_onTextFieldInsertText_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CCTextInputNode_onTextFieldAttachWithIME_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CCTextInputNode_onTextFieldDetachWithIME_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CCTextInputNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCTextInputNode)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(CCTextInputNode, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(bool onTextFieldInsertText(cocos2d::CCTextFieldTTF* pSender, char const* text, int nLen, cocos2d::enumKeyCodes keyCodes))
SCREWYOU3_HOOK_IMPL(CCTextInputNode, onTextFieldInsertText, pSender, text, nLen, keyCodes)
SCREWYOU3_HOOK(bool onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF* tField))
SCREWYOU3_HOOK_IMPL(CCTextInputNode, onTextFieldAttachWithIME, tField)
SCREWYOU3_HOOK(bool onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF* tField))
SCREWYOU3_HOOK_IMPL(CCTextInputNode, onTextFieldDetachWithIME, tField)
SCREWYOU3_HOOK(bool init(float width, float height, char const* placeholder, char const* textFont, int fontSize, char const* labelFont))
SCREWYOU3_HOOK_IMPL(CCTextInputNode, init, width, height, placeholder, textFont, fontSize, labelFont)
SCREWYOU3_HOOK_END("CCTextInputNode::ccTouchBegan")

#include <Geode/modify/ChallengeNode.hpp>

bool ChallengeNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ChallengeNode)
SCREWYOU3_HOOK(bool init(GJChallengeItem* challengeItem, ChallengesPage* challengesPage, bool isNew))
SCREWYOU3_HOOK_IMPL(ChallengeNode, init, challengeItem, challengesPage, isNew)
SCREWYOU3_HOOK_END("ChallengeNode::init")

#include <Geode/modify/ChallengesPage.hpp>

bool ChallengesPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ChallengesPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ChallengesPage, init, )
SCREWYOU3_HOOK_END("ChallengesPage::init")

#include <Geode/modify/CharacterColorPage.hpp>

bool CharacterColorPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int CharacterColorPage_activeColorForMode_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int CharacterColorPage_colorForIndex_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(CharacterColorPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CharacterColorPage, init, )
SCREWYOU3_HOOK(int activeColorForMode(int mode))
SCREWYOU3_HOOK_IMPL(CharacterColorPage, activeColorForMode, mode)
SCREWYOU3_HOOK(int colorForIndex(int index))
SCREWYOU3_HOOK_IMPL(CharacterColorPage, colorForIndex, index)
SCREWYOU3_HOOK_END("CharacterColorPage::init")

#include <Geode/modify/CheckpointGameObject.hpp>

bool CheckpointGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string CheckpointGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(CheckpointGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CheckpointGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(CheckpointGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("CheckpointGameObject::init")

#include <Geode/modify/CheckpointObject.hpp>

bool CheckpointObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CheckpointObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CheckpointObject, init, )
SCREWYOU3_HOOK_END("CheckpointObject::init")

#include <Geode/modify/CollisionBlockPopup.hpp>

bool CollisionBlockPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CollisionBlockPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(CollisionBlockPopup, init, object, objects)
SCREWYOU3_HOOK_END("CollisionBlockPopup::init")

#include <Geode/modify/ColorActionSprite.hpp>

bool ColorActionSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ColorActionSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ColorActionSprite, init, )
SCREWYOU3_HOOK_END("ColorActionSprite::init")

#include <Geode/modify/ColorChannelSprite.hpp>

bool ColorChannelSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ColorChannelSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ColorChannelSprite, init, )
SCREWYOU3_HOOK_END("ColorChannelSprite::init")

#include <Geode/modify/ColorSelectLiveOverlay.hpp>

bool ColorSelectLiveOverlay_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ColorSelectLiveOverlay)
SCREWYOU3_HOOK(bool init(ColorAction* baseAction, ColorAction* detailAction, EffectGameObject* object))
SCREWYOU3_HOOK_IMPL(ColorSelectLiveOverlay, init, baseAction, detailAction, object)
SCREWYOU3_HOOK_END("ColorSelectLiveOverlay::init")

#include <Geode/modify/ColorSelectPopup.hpp>

gd::string ColorSelectPopup_colorToHex_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool ColorSelectPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ColorSelectPopup)
SCREWYOU3_HOOK(static gd::string colorToHex(cocos2d::ccColor3B color))
SCREWYOU3_HOOK_IMPL(ColorSelectPopup, colorToHex, color)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, ColorAction* action))
SCREWYOU3_HOOK_IMPL(ColorSelectPopup, init, object, objects, action)
SCREWYOU3_HOOK_END("ColorSelectPopup::colorToHex")

#include <Geode/modify/CommentCell.hpp>

bool CommentCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CommentCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CommentCell, init, )
SCREWYOU3_HOOK_END("CommentCell::init")

#include <Geode/modify/CommunityCreditsPage.hpp>

bool CommunityCreditsPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CommunityCreditsPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CommunityCreditsPage, init, )
SCREWYOU3_HOOK_END("CommunityCreditsPage::init")

#include <Geode/modify/ConfigureHSVWidget.hpp>

bool ConfigureHSVWidget_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ConfigureHSVWidget)
SCREWYOU3_HOOK(bool init(cocos2d::ccHSVValue hsv, bool noBackground, bool addInputs))
SCREWYOU3_HOOK_IMPL(ConfigureHSVWidget, init, hsv, noBackground, addInputs)
SCREWYOU3_HOOK_END("ConfigureHSVWidget::init")

#include <Geode/modify/ConfigureValuePopup.hpp>

bool ConfigureValuePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ConfigureValuePopup)
SCREWYOU3_HOOK(bool init(ConfigureValuePopupDelegate* delegate, float value, float minimum, float maximum, gd::string title, gd::string description))
SCREWYOU3_HOOK_IMPL(ConfigureValuePopup, init, delegate, value, minimum, maximum, title, description)
SCREWYOU3_HOOK_END("ConfigureValuePopup::init")

#include <Geode/modify/CountTriggerGameObject.hpp>

gd::string CountTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(CountTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(CountTriggerGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("CountTriggerGameObject::getSaveString")

#include <Geode/modify/CreateGuidelinesLayer.hpp>

bool CreateGuidelinesLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string CreateGuidelinesLayer_getMergedRecordString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool CreateGuidelinesLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CreateGuidelinesLayer)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(CreateGuidelinesLayer, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(gd::string getMergedRecordString(gd::string str1, gd::string str2))
SCREWYOU3_HOOK_IMPL(CreateGuidelinesLayer, getMergedRecordString, str1, str2)
SCREWYOU3_HOOK(bool init(CustomSongDelegate* delegate, AudioGuidelinesType type))
SCREWYOU3_HOOK_IMPL(CreateGuidelinesLayer, init, delegate, type)
SCREWYOU3_HOOK_END("CreateGuidelinesLayer::ccTouchBegan")

#include <Geode/modify/CreateParticlePopup.hpp>

bool CreateParticlePopup_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CreateParticlePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float CreateParticlePopup_maxSliderValueForType_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float CreateParticlePopup_minSliderValueForType_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string CreateParticlePopup_titleForParticleValue_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float CreateParticlePopup_valueForParticleValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(CreateParticlePopup)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(bool init(ParticleGameObject* object, cocos2d::CCArray* objects, gd::string str))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, init, object, objects, str)
SCREWYOU3_HOOK(float maxSliderValueForType(gjParticleValue type))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, maxSliderValueForType, type)
SCREWYOU3_HOOK(float minSliderValueForType(gjParticleValue type))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, minSliderValueForType, type)
SCREWYOU3_HOOK(gd::string titleForParticleValue(gjParticleValue type))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, titleForParticleValue, type)
SCREWYOU3_HOOK(float valueForParticleValue(gjParticleValue type))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, valueForParticleValue, type)
SCREWYOU3_HOOK_END("CreateParticlePopup::ccTouchBegan")

#include <Geode/modify/CreatorLayer.hpp>

bool CreatorLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CreatorLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CreatorLayer, init, )
SCREWYOU3_HOOK_END("CreatorLayer::init")

#include <Geode/modify/CurrencyRewardLayer.hpp>

bool CurrencyRewardLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CurrencyRewardLayer)
SCREWYOU3_HOOK(bool init(int orbs, int stars, int moons, int diamonds, CurrencySpriteType demonKey, int keyCount, CurrencySpriteType shardType, int shardsCount, cocos2d::CCPoint position, CurrencyRewardType rewardType, float yOffset, float time))
SCREWYOU3_HOOK_IMPL(CurrencyRewardLayer, init, orbs, stars, moons, diamonds, demonKey, keyCount, shardType, shardsCount, position, rewardType, yOffset, time)
SCREWYOU3_HOOK_END("CurrencyRewardLayer::init")

#include <Geode/modify/CurrencySprite.hpp>

gd::string CurrencySprite_spriteTypeToStat_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool CurrencySprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CurrencySprite)
SCREWYOU3_HOOK(static gd::string spriteTypeToStat(CurrencySpriteType type))
SCREWYOU3_HOOK_IMPL(CurrencySprite, spriteTypeToStat, type)
SCREWYOU3_HOOK(bool init(CurrencySpriteType type, bool burst))
SCREWYOU3_HOOK_IMPL(CurrencySprite, init, type, burst)
SCREWYOU3_HOOK_END("CurrencySprite::spriteTypeToStat")

#include <Geode/modify/CustomizeObjectLayer.hpp>

int CustomizeObjectLayer_getActiveMode_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool CustomizeObjectLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CustomizeObjectLayer)
SCREWYOU3_HOOK(int getActiveMode(bool ignoreDefault))
SCREWYOU3_HOOK_IMPL(CustomizeObjectLayer, getActiveMode, ignoreDefault)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(CustomizeObjectLayer, init, object, objects)
SCREWYOU3_HOOK_END("CustomizeObjectLayer::getActiveMode")

#include <Geode/modify/CustomizeObjectSettingsPopup.hpp>

bool CustomizeObjectSettingsPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CustomizeObjectSettingsPopup)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects, CustomizeObjectLayer* layer))
SCREWYOU3_HOOK_IMPL(CustomizeObjectSettingsPopup, init, object, objects, layer)
SCREWYOU3_HOOK_END("CustomizeObjectSettingsPopup::init")

#include <Geode/modify/CustomListView.hpp>

float CustomListView_getCellHeight_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(CustomListView)
SCREWYOU3_HOOK(static float getCellHeight(BoomListType type))
SCREWYOU3_HOOK_IMPL(CustomListView, getCellHeight, type)
SCREWYOU3_HOOK_END("CustomListView::getCellHeight")

#include <Geode/modify/CustomSFXCell.hpp>

bool CustomSFXCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int CustomSFXCell_getActiveSFXID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(CustomSFXCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CustomSFXCell, init, )
SCREWYOU3_HOOK(int getActiveSFXID())
SCREWYOU3_HOOK_IMPL(CustomSFXCell, getActiveSFXID, )
SCREWYOU3_HOOK_END("CustomSFXCell::init")

#include <Geode/modify/CustomSFXWidget.hpp>

bool CustomSFXWidget_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CustomSFXWidget)
SCREWYOU3_HOOK(bool init(SFXInfoObject* object, CustomSFXDelegate* delegate, bool showDelete, bool showPlay, bool showDownload, bool noBackground, bool compactMode))
SCREWYOU3_HOOK_IMPL(CustomSFXWidget, init, object, delegate, showDelete, showPlay, showDownload, noBackground, compactMode)
SCREWYOU3_HOOK_END("CustomSFXWidget::init")

#include <Geode/modify/CustomSongCell.hpp>

bool CustomSongCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int CustomSongCell_getActiveSongID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string CustomSongCell_getSongFileName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(CustomSongCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CustomSongCell, init, )
SCREWYOU3_HOOK(int getActiveSongID())
SCREWYOU3_HOOK_IMPL(CustomSongCell, getActiveSongID, )
SCREWYOU3_HOOK(gd::string getSongFileName())
SCREWYOU3_HOOK_IMPL(CustomSongCell, getSongFileName, )
SCREWYOU3_HOOK_END("CustomSongCell::init")

#include <Geode/modify/CustomSongLayer.hpp>

bool CustomSongLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CustomSongLayer)
SCREWYOU3_HOOK(bool init(CustomSongDelegate* delegate))
SCREWYOU3_HOOK_IMPL(CustomSongLayer, init, delegate)
SCREWYOU3_HOOK_END("CustomSongLayer::init")

#include <Geode/modify/CustomSongWidget.hpp>

bool CustomSongWidget_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CustomSongWidget)
SCREWYOU3_HOOK(bool init(SongInfoObject* songInfo, CustomSongDelegate* songDelegate, bool showSongSelect, bool showPlayMusic, bool showDownload, bool isRobtopSong, bool unkBool, bool isMusicLibrary, int unk))
SCREWYOU3_HOOK_IMPL(CustomSongWidget, init, songInfo, songDelegate, showSongSelect, showPlayMusic, showDownload, isRobtopSong, unkBool, isMusicLibrary, unk)
SCREWYOU3_HOOK_END("CustomSongWidget::init")

#include <Geode/modify/DailyLevelNode.hpp>

bool DailyLevelNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DailyLevelNode)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, DailyLevelPage* page, bool isNew))
SCREWYOU3_HOOK_IMPL(DailyLevelNode, init, level, page, isNew)
SCREWYOU3_HOOK_END("DailyLevelNode::init")

#include <Geode/modify/DailyLevelPage.hpp>

gd::string DailyLevelPage_getDailyTimeString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool DailyLevelPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DailyLevelPage)
SCREWYOU3_HOOK(gd::string getDailyTimeString(int timeLeft))
SCREWYOU3_HOOK_IMPL(DailyLevelPage, getDailyTimeString, timeLeft)
SCREWYOU3_HOOK(bool init(GJTimedLevelType type))
SCREWYOU3_HOOK_IMPL(DailyLevelPage, init, type)
SCREWYOU3_HOOK_END("DailyLevelPage::getDailyTimeString")

#include <Geode/modify/DashRingObject.hpp>

gd::string DashRingObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(DashRingObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(DashRingObject, getSaveString, layer)
SCREWYOU3_HOOK_END("DashRingObject::getSaveString")

#include <Geode/modify/DemonFilterSelectLayer.hpp>

bool DemonFilterSelectLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DemonFilterSelectLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(DemonFilterSelectLayer, init, )
SCREWYOU3_HOOK_END("DemonFilterSelectLayer::init")

#include <Geode/modify/DemonInfoPopup.hpp>

bool DemonInfoPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DemonInfoPopup)
SCREWYOU3_HOOK(bool init(int easyClassic, int mediumClassic, int hardClassic, int insaneClassic, int extremeClassic, int easyPlatformer, int mediumPlatformer, int hardPlatformer, int insanePlatformer, int extremePlatformer, int weekly, int gauntlet))
SCREWYOU3_HOOK_IMPL(DemonInfoPopup, init, easyClassic, mediumClassic, hardClassic, insaneClassic, extremeClassic, easyPlatformer, mediumPlatformer, hardPlatformer, insanePlatformer, extremePlatformer, weekly, gauntlet)
SCREWYOU3_HOOK_END("DemonInfoPopup::init")

#include <Geode/modify/DialogLayer.hpp>

bool DialogLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool DialogLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DialogLayer)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(DialogLayer, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(bool init(DialogObject* object, cocos2d::CCArray* objects, int background))
SCREWYOU3_HOOK_IMPL(DialogLayer, init, object, objects, background)
SCREWYOU3_HOOK_END("DialogLayer::ccTouchBegan")

#include <Geode/modify/DungeonBarsSprite.hpp>

bool DungeonBarsSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DungeonBarsSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(DungeonBarsSprite, init, )
SCREWYOU3_HOOK_END("DungeonBarsSprite::init")

#include <Geode/modify/EditGameObjectPopup.hpp>

bool EditGameObjectPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EditGameObjectPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, bool platformer))
SCREWYOU3_HOOK_IMPL(EditGameObjectPopup, init, object, objects, platformer)
SCREWYOU3_HOOK_END("EditGameObjectPopup::init")

#include <Geode/modify/EditLevelLayer.hpp>

bool EditLevelLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EditLevelLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(EditLevelLayer, init, level)
SCREWYOU3_HOOK_END("EditLevelLayer::init")

#include <Geode/modify/EditorOptionsLayer.hpp>

bool EditorOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EditorOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(EditorOptionsLayer, init, )
SCREWYOU3_HOOK_END("EditorOptionsLayer::init")

#include <Geode/modify/EditorPauseLayer.hpp>

bool EditorPauseLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EditorPauseLayer)
SCREWYOU3_HOOK(bool init(LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(EditorPauseLayer, init, layer)
SCREWYOU3_HOOK_END("EditorPauseLayer::init")

#include <Geode/modify/EditorUI.hpp>

bool EditorUI_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_canSelectObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int EditorUI_convertKeyBasedOnNeighbors_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int EditorUI_convertToBaseKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string EditorUI_copyObjects_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool EditorUI_editButton2Usable_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_editButtonUsable_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int EditorUI_getRandomStartKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int EditorUI_getSmartObjectKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float EditorUI_getXMin_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool EditorUI_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_isSpecialSnapObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_onCreate_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_shouldDeleteObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int EditorUI_smartTypeForKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(EditorUI)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(EditorUI, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(bool canSelectObject(GameObject* object))
SCREWYOU3_HOOK_IMPL(EditorUI, canSelectObject, object)
SCREWYOU3_HOOK(int convertKeyBasedOnNeighbors(int smartKey, int objectID, cocos2d::CCPoint position, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(EditorUI, convertKeyBasedOnNeighbors, smartKey, objectID, position, objects)
SCREWYOU3_HOOK(int convertToBaseKey(int objectID))
SCREWYOU3_HOOK_IMPL(EditorUI, convertToBaseKey, objectID)
SCREWYOU3_HOOK(gd::string copyObjects(cocos2d::CCArray* objects, bool copyColors, bool sort))
SCREWYOU3_HOOK_IMPL(EditorUI, copyObjects, objects, copyColors, sort)
SCREWYOU3_HOOK(bool editButton2Usable())
SCREWYOU3_HOOK_IMPL(EditorUI, editButton2Usable, )
SCREWYOU3_HOOK(bool editButtonUsable())
SCREWYOU3_HOOK_IMPL(EditorUI, editButtonUsable, )
SCREWYOU3_HOOK(static int getRandomStartKey(int specialTemplate))
SCREWYOU3_HOOK_IMPL(EditorUI, getRandomStartKey, specialTemplate)
SCREWYOU3_HOOK(static int getSmartObjectKey(int key, GJSmartDirection direction))
SCREWYOU3_HOOK_IMPL(EditorUI, getSmartObjectKey, key, direction)
SCREWYOU3_HOOK(float getXMin(int offset))
SCREWYOU3_HOOK_IMPL(EditorUI, getXMin, offset)
SCREWYOU3_HOOK(bool init(LevelEditorLayer* editorLayer))
SCREWYOU3_HOOK_IMPL(EditorUI, init, editorLayer)
SCREWYOU3_HOOK(bool isSpecialSnapObject(int id))
SCREWYOU3_HOOK_IMPL(EditorUI, isSpecialSnapObject, id)
SCREWYOU3_HOOK(bool onCreate())
SCREWYOU3_HOOK_IMPL(EditorUI, onCreate, )
SCREWYOU3_HOOK(bool shouldDeleteObject(GameObject* object))
SCREWYOU3_HOOK_IMPL(EditorUI, shouldDeleteObject, object)
SCREWYOU3_HOOK(static int smartTypeForKey(int key))
SCREWYOU3_HOOK_IMPL(EditorUI, smartTypeForKey, key)
SCREWYOU3_HOOK_END("EditorUI::ccTouchBegan")

#include <Geode/modify/EditTriggersPopup.hpp>

bool EditTriggersPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EditTriggersPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(EditTriggersPopup, init, object, objects)
SCREWYOU3_HOOK_END("EditTriggersPopup::init")

#include <Geode/modify/EffectGameObject.hpp>

gd::string EffectGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float EffectGameObject_spawnXPosition_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool EffectGameObject_canReverse_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EffectGameObject_canBeOrdered_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EffectGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(EffectGameObject, getSaveString, layer)
SCREWYOU3_HOOK(float spawnXPosition())
SCREWYOU3_HOOK_IMPL(EffectGameObject, spawnXPosition, )
SCREWYOU3_HOOK(bool canReverse())
SCREWYOU3_HOOK_IMPL(EffectGameObject, canReverse, )
SCREWYOU3_HOOK(bool canBeOrdered())
SCREWYOU3_HOOK_IMPL(EffectGameObject, canBeOrdered, )
SCREWYOU3_HOOK_END("EffectGameObject::getSaveString")

#include <Geode/modify/EndLevelLayer.hpp>

gd::string EndLevelLayer_getCoinString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* EndLevelLayer_getEndText_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(EndLevelLayer)
SCREWYOU3_HOOK(gd::string getCoinString())
SCREWYOU3_HOOK_IMPL(EndLevelLayer, getCoinString, )
SCREWYOU3_HOOK(const char* getEndText())
SCREWYOU3_HOOK_IMPL(EndLevelLayer, getEndText, )
SCREWYOU3_HOOK_END("EndLevelLayer::getCoinString")

#include <Geode/modify/EndPortalObject.hpp>

bool EndPortalObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EndPortalObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(EndPortalObject, init, )
SCREWYOU3_HOOK_END("EndPortalObject::init")

#include <Geode/modify/EndTriggerGameObject.hpp>

bool EndTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string EndTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(EndTriggerGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(EndTriggerGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(EndTriggerGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("EndTriggerGameObject::init")

#include <Geode/modify/EnhancedGameObject.hpp>

gd::string EnhancedGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool EnhancedGameObject_hasBeenActivatedByPlayer_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EnhancedGameObject_hasBeenActivated_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EnhancedGameObject_canAllowMultiActivate_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EnhancedGameObject_getHasSyncedAnimation_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EnhancedGameObject_getHasRotateAction_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EnhancedGameObject_canMultiActivate_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EnhancedGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EnhancedGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, getSaveString, layer)
SCREWYOU3_HOOK(bool hasBeenActivatedByPlayer(PlayerObject* player))
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, hasBeenActivatedByPlayer, player)
SCREWYOU3_HOOK(bool hasBeenActivated())
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, hasBeenActivated, )
SCREWYOU3_HOOK(bool canAllowMultiActivate())
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, canAllowMultiActivate, )
SCREWYOU3_HOOK(bool getHasSyncedAnimation())
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, getHasSyncedAnimation, )
SCREWYOU3_HOOK(bool getHasRotateAction())
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, getHasRotateAction, )
SCREWYOU3_HOOK(bool canMultiActivate(bool multiActivate))
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, canMultiActivate, multiActivate)
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, init, frame)
SCREWYOU3_HOOK_END("EnhancedGameObject::getSaveString")

#include <Geode/modify/EnhancedTriggerObject.hpp>

gd::string EnhancedTriggerObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(EnhancedTriggerObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(EnhancedTriggerObject, getSaveString, layer)
SCREWYOU3_HOOK_END("EnhancedTriggerObject::getSaveString")

#include <Geode/modify/EnterEffectObject.hpp>

gd::string EnterEffectObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(EnterEffectObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(EnterEffectObject, getSaveString, layer)
SCREWYOU3_HOOK_END("EnterEffectObject::getSaveString")

#include <Geode/modify/EventLinkTrigger.hpp>

bool EventLinkTrigger_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string EventLinkTrigger_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(EventLinkTrigger)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(EventLinkTrigger, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(EventLinkTrigger, getSaveString, layer)
SCREWYOU3_HOOK_END("EventLinkTrigger::init")

#include <Geode/modify/ExplodeItemSprite.hpp>

bool ExplodeItemSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ExplodeItemSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ExplodeItemSprite, init, )
SCREWYOU3_HOOK_END("ExplodeItemSprite::init")

#include <Geode/modify/ExtendedLayer.hpp>

bool ExtendedLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ExtendedLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ExtendedLayer, init, )
SCREWYOU3_HOOK_END("ExtendedLayer::init")

#include <Geode/modify/FileOperation.hpp>

gd::string FileOperation_getFilePath_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(FileOperation)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string getFilePath())
SCREWYOU3_HOOK_IMPL(FileOperation, getFilePath, )
#endif
SCREWYOU3_HOOK_END("FileOperation::getFilePath")

#include <Geode/modify/FileSaveManager.hpp>

bool FileSaveManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FileSaveManager)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(FileSaveManager, init, )
#endif
SCREWYOU3_HOOK_END("FileSaveManager::init")

#include <Geode/modify/FindObjectPopup.hpp>

bool FindObjectPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FindObjectPopup)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(FindObjectPopup, init, )
SCREWYOU3_HOOK_END("FindObjectPopup::init")

#include <Geode/modify/FLAlertLayer.hpp>

bool FLAlertLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool FLAlertLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FLAlertLayer)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(FLAlertLayer, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(bool init(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2, float width, bool scroll, float height, float textScale))
SCREWYOU3_HOOK_IMPL(FLAlertLayer, init, delegate, title, desc, btn1, btn2, width, scroll, height, textScale)
SCREWYOU3_HOOK(bool init(int opacity))
SCREWYOU3_HOOK_IMPL(FLAlertLayer, init, opacity)
SCREWYOU3_HOOK_END("FLAlertLayer::ccTouchBegan")

#include <Geode/modify/FMODAudioEngine.hpp>

int FMODAudioEngine_channelIDForUniqueID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string FMODAudioEngine_getFMODStatus_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

unsigned int FMODAudioEngine_getMusicLengthMS_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

unsigned int FMODAudioEngine_getMusicTimeMS_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool FMODAudioEngine_isMusicPlaying_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool FMODAudioEngine_isPersistentMatchPlaying_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int FMODAudioEngine_lengthForSound_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float FMODAudioEngine_pitchForIdx_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_playEffect_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_playEffectAdvanced_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_queuePlayEffect_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_registerChannel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string FMODAudioEngine_reverbToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float FMODAudioEngine_stopAndGetFade_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(FMODAudioEngine)
SCREWYOU3_HOOK(int channelIDForUniqueID(int id))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, channelIDForUniqueID, id)
SCREWYOU3_HOOK(gd::string getFMODStatus(int unused))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getFMODStatus, unused)
SCREWYOU3_HOOK(unsigned int getMusicLengthMS(int channel))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getMusicLengthMS, channel)
SCREWYOU3_HOOK(unsigned int getMusicTimeMS(int channel))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getMusicTimeMS, channel)
SCREWYOU3_HOOK(bool isMusicPlaying(gd::string path, int musicID))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, isMusicPlaying, path, musicID)
SCREWYOU3_HOOK(bool isMusicPlaying(int musicID))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, isMusicPlaying, musicID)
SCREWYOU3_HOOK(bool isPersistentMatchPlaying(gd::string path, int musicID))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, isPersistentMatchPlaying, path, musicID)
SCREWYOU3_HOOK(int lengthForSound(gd::string path))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, lengthForSound, path)
SCREWYOU3_HOOK(static float pitchForIdx(int index))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, pitchForIdx, index)
SCREWYOU3_HOOK(int playEffect(gd::string path, float speed, float unknown, float volume))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, playEffect, path, speed, unknown, volume)
SCREWYOU3_HOOK(int playEffect(gd::string path))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, playEffect, path)
SCREWYOU3_HOOK(int playEffectAdvanced(gd::string path, float speed, float unknown, float volume, float pitch, bool fastFourierTransform, bool reverb, int startMillis, int endMillis, int fadeIn, int fadeOut, bool loopEnabled, int effectID, bool override, bool noPreload, int channelID, int uniqueID, float minInterval, int sfxGroup))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, playEffectAdvanced, path, speed, unknown, volume, pitch, fastFourierTransform, reverb, startMillis, endMillis, fadeIn, fadeOut, loopEnabled, effectID, override, noPreload, channelID, uniqueID, minInterval, sfxGroup)
SCREWYOU3_HOOK(int queuePlayEffect(gd::string audioFilename, float speed, float unknown, float volume, float pitch, bool fastFourierTransform, bool reverb, int start, int end, int fadeIn, int fadeOut, bool loop, int effectID, bool override, int uniqueID, float minInterval, int group))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, queuePlayEffect, audioFilename, speed, unknown, volume, pitch, fastFourierTransform, reverb, start, end, fadeIn, fadeOut, loop, effectID, override, uniqueID, minInterval, group)
SCREWYOU3_HOOK(int registerChannel(FMOD::Channel* channel, int channelID, int effectID))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, registerChannel, channel, channelID, effectID)
SCREWYOU3_HOOK(static gd::string reverbToString(FMODReverbPreset preset))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, reverbToString, preset)
SCREWYOU3_HOOK(float stopAndGetFade(FMOD::Channel* channel))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, stopAndGetFade, channel)
SCREWYOU3_HOOK_END("FMODAudioEngine::channelIDForUniqueID")

#include <Geode/modify/FMODLevelVisualizer.hpp>

bool FMODLevelVisualizer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FMODLevelVisualizer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(FMODLevelVisualizer, init, )
SCREWYOU3_HOOK_END("FMODLevelVisualizer::init")

#include <Geode/modify/FollowRewardPage.hpp>

bool FollowRewardPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FollowRewardPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(FollowRewardPage, init, )
SCREWYOU3_HOOK_END("FollowRewardPage::init")

#include <Geode/modify/ForceBlockGameObject.hpp>

gd::string ForceBlockGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(ForceBlockGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(ForceBlockGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("ForceBlockGameObject::getSaveString")

#include <Geode/modify/FRequestProfilePage.hpp>

bool FRequestProfilePage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool FRequestProfilePage_isCorrect_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FRequestProfilePage)
SCREWYOU3_HOOK(bool init(bool sent))
SCREWYOU3_HOOK_IMPL(FRequestProfilePage, init, sent)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(FRequestProfilePage, isCorrect, key)
SCREWYOU3_HOOK_END("FRequestProfilePage::init")

#include <Geode/modify/FriendRequestPopup.hpp>

bool FriendRequestPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FriendRequestPopup)
SCREWYOU3_HOOK(bool init(GJFriendRequest* request))
SCREWYOU3_HOOK_IMPL(FriendRequestPopup, init, request)
SCREWYOU3_HOOK_END("FriendRequestPopup::init")

#include <Geode/modify/FriendsProfilePage.hpp>

bool FriendsProfilePage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FriendsProfilePage)
SCREWYOU3_HOOK(bool init(UserListType type))
SCREWYOU3_HOOK_IMPL(FriendsProfilePage, init, type)
SCREWYOU3_HOOK_END("FriendsProfilePage::init")

#include <Geode/modify/GameCell.hpp>

bool GameCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GameCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GameCell, init, )
SCREWYOU3_HOOK_END("GameCell::init")

#include <Geode/modify/GameEffectsManager.hpp>

bool GameEffectsManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GameEffectsManager)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(PlayLayer* playLayer))
SCREWYOU3_HOOK_IMPL(GameEffectsManager, init, playLayer)
#endif
SCREWYOU3_HOOK_END("GameEffectsManager::init")

#include <Geode/modify/GameLevelManager.hpp>

bool GameLevelManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_acceptFriendRequest_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameLevelManager_accountIDForUserID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameLevelManager_blockUser_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_deleteFriendRequests_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_deleteUserMessages_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameLevelManager_getBasePostString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameLevelManager_getCompletedDailyLevels_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameLevelManager_getCompletedEventLevels_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameLevelManager_getCompletedWeeklyLevels_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameLevelManager_getDemonLevelsString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameLevelManager_getDifficultyStr_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameLevelManager_getFolderName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameLevelManager_getGJChallenges_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_getGJDailyLevelState_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_getGJRewards_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_getGJSecretReward_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameLevelManager_getLengthStr_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameLevelManager_getNextLevelName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getPageInfo_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameLevelManager_getSplitIntFromKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameLevelManager_getStarLevelsString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameLevelManager_getTimeLeft_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameLevelManager_hasDownloadedLevel_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_hasLikedAccountItem_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_hasLikedItem_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_hasLikedItemFullCheck_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_hasRatedDemon_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_hasRatedLevelStars_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_hasReportedLevel_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_isDLActive_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_isFollowingUser_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_isTimeValid_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_keyHasTimer_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameLevelManager_levelIDFromCommentKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameLevelManager_rateDemon_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_removeFriend_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_requestUserAccess_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameLevelManager_tryGetUsername_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameLevelManager_unblockUser_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_updateDescription_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_uploadFriendRequest_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameLevelManager_userNameForUserID_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameLevelManager_verifyContainerOnlyHasLevels_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameLevelManager_writeSpecialFilters_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GameLevelManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GameLevelManager, init, )
SCREWYOU3_HOOK(bool acceptFriendRequest(int accountID, int requestID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, acceptFriendRequest, accountID, requestID)
SCREWYOU3_HOOK(int accountIDForUserID(int userID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, accountIDForUserID, userID)
SCREWYOU3_HOOK(bool blockUser(int accountID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, blockUser, accountID)
SCREWYOU3_HOOK(bool deleteFriendRequests(int accountID, cocos2d::CCArray* accounts, bool sent))
SCREWYOU3_HOOK_IMPL(GameLevelManager, deleteFriendRequests, accountID, accounts, sent)
SCREWYOU3_HOOK(bool deleteUserMessages(GJUserMessage* message, cocos2d::CCArray* messages, bool isSender))
SCREWYOU3_HOOK_IMPL(GameLevelManager, deleteUserMessages, message, messages, isSender)
SCREWYOU3_HOOK(gd::string getBasePostString())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getBasePostString, )
SCREWYOU3_HOOK(int getCompletedDailyLevels())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getCompletedDailyLevels, )
SCREWYOU3_HOOK(int getCompletedEventLevels(int minStars, int maxStars))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getCompletedEventLevels, minStars, maxStars)
SCREWYOU3_HOOK(int getCompletedWeeklyLevels())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getCompletedWeeklyLevels, )
SCREWYOU3_HOOK(gd::string getDemonLevelsString())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getDemonLevelsString, )
SCREWYOU3_HOOK(gd::string getDifficultyStr(bool isNA, bool isEasy, bool isNormal, bool isHard, bool isHarder, bool isInsane, bool isDemon, bool isAuto))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getDifficultyStr, isNA, isEasy, isNormal, isHard, isHarder, isInsane, isDemon, isAuto)
SCREWYOU3_HOOK(gd::string getFolderName(int id, bool local))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getFolderName, id, local)
SCREWYOU3_HOOK(bool getGJChallenges())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getGJChallenges, )
SCREWYOU3_HOOK(bool getGJDailyLevelState(GJTimedLevelType type))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getGJDailyLevelState, type)
SCREWYOU3_HOOK(bool getGJRewards(int type))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getGJRewards, type)
SCREWYOU3_HOOK(bool getGJSecretReward(gd::string key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getGJSecretReward, key)
SCREWYOU3_HOOK(gd::string getLengthStr(bool isTiny, bool isShort, bool isMedium, bool isLong, bool isXL, bool isPlat))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getLengthStr, isTiny, isShort, isMedium, isLong, isXL, isPlat)
SCREWYOU3_HOOK(gd::string getNextLevelName(gd::string name))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getNextLevelName, name)
SCREWYOU3_HOOK(const char* getPageInfo(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getPageInfo, key)
SCREWYOU3_HOOK(int getSplitIntFromKey(char const* key, int index))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getSplitIntFromKey, key, index)
SCREWYOU3_HOOK(gd::string getStarLevelsString())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getStarLevelsString, )
SCREWYOU3_HOOK(int getTimeLeft(char const* key, float length))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getTimeLeft, key, length)
SCREWYOU3_HOOK(bool hasDownloadedLevel(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasDownloadedLevel, id)
SCREWYOU3_HOOK(bool hasLikedAccountItem(LikeItemType type, int id, bool liked, int parentID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasLikedAccountItem, type, id, liked, parentID)
SCREWYOU3_HOOK(bool hasLikedItem(LikeItemType type, int id, bool liked, int parentID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasLikedItem, type, id, liked, parentID)
SCREWYOU3_HOOK(bool hasLikedItemFullCheck(LikeItemType type, int id, bool liked, int parentID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasLikedItemFullCheck, type, id, liked, parentID)
SCREWYOU3_HOOK(bool hasRatedDemon(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasRatedDemon, id)
SCREWYOU3_HOOK(bool hasRatedLevelStars(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasRatedLevelStars, id)
SCREWYOU3_HOOK(bool hasReportedLevel(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasReportedLevel, id)
SCREWYOU3_HOOK(bool isDLActive(char const* tag))
SCREWYOU3_HOOK_IMPL(GameLevelManager, isDLActive, tag)
SCREWYOU3_HOOK(bool isFollowingUser(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, isFollowingUser, id)
SCREWYOU3_HOOK(bool isTimeValid(char const* key, float length))
SCREWYOU3_HOOK_IMPL(GameLevelManager, isTimeValid, key, length)
SCREWYOU3_HOOK(bool keyHasTimer(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, keyHasTimer, key)
SCREWYOU3_HOOK(int levelIDFromCommentKey(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, levelIDFromCommentKey, key)
SCREWYOU3_HOOK(bool rateDemon(int id, int diff, bool moderator))
SCREWYOU3_HOOK_IMPL(GameLevelManager, rateDemon, id, diff, moderator)
SCREWYOU3_HOOK(bool removeFriend(int accountID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, removeFriend, accountID)
SCREWYOU3_HOOK(bool requestUserAccess())
SCREWYOU3_HOOK_IMPL(GameLevelManager, requestUserAccess, )
SCREWYOU3_HOOK(gd::string tryGetUsername(int accountID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, tryGetUsername, accountID)
SCREWYOU3_HOOK(bool unblockUser(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, unblockUser, id)
SCREWYOU3_HOOK(bool updateDescription(int id, gd::string description))
SCREWYOU3_HOOK_IMPL(GameLevelManager, updateDescription, id, description)
SCREWYOU3_HOOK(bool uploadFriendRequest(int accountID, gd::string content))
SCREWYOU3_HOOK_IMPL(GameLevelManager, uploadFriendRequest, accountID, content)
SCREWYOU3_HOOK(gd::string userNameForUserID(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, userNameForUserID, id)
SCREWYOU3_HOOK(bool verifyContainerOnlyHasLevels(cocos2d::CCDictionary* dict))
SCREWYOU3_HOOK_IMPL(GameLevelManager, verifyContainerOnlyHasLevels, dict)
SCREWYOU3_HOOK(gd::string writeSpecialFilters(GJSearchObject* object))
SCREWYOU3_HOOK_IMPL(GameLevelManager, writeSpecialFilters, object)
SCREWYOU3_HOOK_END("GameLevelManager::init")

#include <Geode/modify/GameManager.hpp>

bool GameManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameManager_activeIconForType_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameManager_canShowRewardedVideo_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameManager_colorKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameManager_countForType_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameManager_dpadConfigToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameManager_generateSecretNumber_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameManager_getGameVariable_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameManager_getIntGameVariable_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameManager_getMenuMusicFile_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameManager_getUGV_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameManager_iconKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameManager_isColorUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameManager_isIconUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameManager_playSFXTrigger_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameManager_reorderKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameManager_safePopScene_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameManager_sheetNameForIcon_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameManager_stringForCustomObject_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameManager_toggleGameVariable_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GameManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GameManager, init, )
SCREWYOU3_HOOK(int activeIconForType(IconType type))
SCREWYOU3_HOOK_IMPL(GameManager, activeIconForType, type)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canShowRewardedVideo())
SCREWYOU3_HOOK_IMPL(GameManager, canShowRewardedVideo, )
#endif
SCREWYOU3_HOOK(gd::string colorKey(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GameManager, colorKey, id, type)
SCREWYOU3_HOOK(int countForType(IconType type))
SCREWYOU3_HOOK_IMPL(GameManager, countForType, type)
SCREWYOU3_HOOK(gd::string dpadConfigToString(UIButtonConfig& config))
SCREWYOU3_HOOK_IMPL(GameManager, dpadConfigToString, config)
SCREWYOU3_HOOK(int generateSecretNumber())
SCREWYOU3_HOOK_IMPL(GameManager, generateSecretNumber, )
SCREWYOU3_HOOK(bool getGameVariable(char const* key))
SCREWYOU3_HOOK_IMPL(GameManager, getGameVariable, key)
SCREWYOU3_HOOK(int getIntGameVariable(char const* key))
SCREWYOU3_HOOK_IMPL(GameManager, getIntGameVariable, key)
SCREWYOU3_HOOK(gd::string getMenuMusicFile())
SCREWYOU3_HOOK_IMPL(GameManager, getMenuMusicFile, )
SCREWYOU3_HOOK(bool getUGV(char const* key))
SCREWYOU3_HOOK_IMPL(GameManager, getUGV, key)
SCREWYOU3_HOOK(gd::string iconKey(int id, IconType type))
SCREWYOU3_HOOK_IMPL(GameManager, iconKey, id, type)
SCREWYOU3_HOOK(bool isColorUnlocked(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GameManager, isColorUnlocked, id, type)
SCREWYOU3_HOOK(bool isIconUnlocked(int id, IconType type))
SCREWYOU3_HOOK_IMPL(GameManager, isIconUnlocked, id, type)
SCREWYOU3_HOOK(int playSFXTrigger(SFXTriggerGameObject* object))
SCREWYOU3_HOOK_IMPL(GameManager, playSFXTrigger, object)
SCREWYOU3_HOOK(int reorderKey(int index, bool up))
SCREWYOU3_HOOK_IMPL(GameManager, reorderKey, index, up)
SCREWYOU3_HOOK(bool safePopScene())
SCREWYOU3_HOOK_IMPL(GameManager, safePopScene, )
SCREWYOU3_HOOK(gd::string sheetNameForIcon(int id, int type))
SCREWYOU3_HOOK_IMPL(GameManager, sheetNameForIcon, id, type)
SCREWYOU3_HOOK(gd::string stringForCustomObject(int customObjectID))
SCREWYOU3_HOOK_IMPL(GameManager, stringForCustomObject, customObjectID)
SCREWYOU3_HOOK(bool toggleGameVariable(char const* key))
SCREWYOU3_HOOK_IMPL(GameManager, toggleGameVariable, key)
SCREWYOU3_HOOK_END("GameManager::init")

#include <Geode/modify/GameObject.hpp>

bool GameObject_initWithTexture_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameObject_isFlipX_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isFlipY_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float GameObject_getRScaleX_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GameObject_getRScaleY_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GameObject_getObjectRotation_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameObject_addToGroup_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GameObject_spawnXPosition_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameObject_getColorFrame_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameObject_getColorKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameObject_getGlowFrame_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameObject_getObjectDirection_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameObject_getParentMode_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GameObject_groupOpacityMod_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameObject_ignoreEditorDuration_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isBasicTrigger_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isFacingDown_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isFacingLeft_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isSpawnableTrigger_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isSpecialObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isTrigger_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameObject_perspectiveColorFrame_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameObject_perspectiveFrame_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameObject_shouldBlendColor_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_shouldLockX_override() {
	return modUtils::chooseRandomNum(0, 1);
}

double GameObject_slopeYPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GameObject)
SCREWYOU3_HOOK(bool initWithTexture(cocos2d::CCTexture2D* texture))
SCREWYOU3_HOOK_IMPL(GameObject, initWithTexture, texture)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(GameObject, getSaveString, layer)
SCREWYOU3_HOOK(bool isFlipX())
SCREWYOU3_HOOK_IMPL(GameObject, isFlipX, )
SCREWYOU3_HOOK(bool isFlipY())
SCREWYOU3_HOOK_IMPL(GameObject, isFlipY, )
SCREWYOU3_HOOK(float getRScaleX())
SCREWYOU3_HOOK_IMPL(GameObject, getRScaleX, )
SCREWYOU3_HOOK(float getRScaleY())
SCREWYOU3_HOOK_IMPL(GameObject, getRScaleY, )
SCREWYOU3_HOOK(float getObjectRotation())
SCREWYOU3_HOOK_IMPL(GameObject, getObjectRotation, )
SCREWYOU3_HOOK(int addToGroup(int id))
SCREWYOU3_HOOK_IMPL(GameObject, addToGroup, id)
SCREWYOU3_HOOK(float spawnXPosition())
SCREWYOU3_HOOK_IMPL(GameObject, spawnXPosition, )
SCREWYOU3_HOOK(gd::string getColorFrame(gd::string frame))
SCREWYOU3_HOOK_IMPL(GameObject, getColorFrame, frame)
SCREWYOU3_HOOK(gd::string getColorKey(bool isMainColor, bool colorGroups))
SCREWYOU3_HOOK_IMPL(GameObject, getColorKey, isMainColor, colorGroups)
SCREWYOU3_HOOK(gd::string getGlowFrame(gd::string frame))
SCREWYOU3_HOOK_IMPL(GameObject, getGlowFrame, frame)
SCREWYOU3_HOOK(int getObjectDirection())
SCREWYOU3_HOOK_IMPL(GameObject, getObjectDirection, )
SCREWYOU3_HOOK(int getParentMode())
SCREWYOU3_HOOK_IMPL(GameObject, getParentMode, )
SCREWYOU3_HOOK(float groupOpacityMod())
SCREWYOU3_HOOK_IMPL(GameObject, groupOpacityMod, )
SCREWYOU3_HOOK(bool ignoreEditorDuration())
SCREWYOU3_HOOK_IMPL(GameObject, ignoreEditorDuration, )
SCREWYOU3_HOOK(bool isBasicTrigger())
SCREWYOU3_HOOK_IMPL(GameObject, isBasicTrigger, )
SCREWYOU3_HOOK(bool isFacingDown())
SCREWYOU3_HOOK_IMPL(GameObject, isFacingDown, )
SCREWYOU3_HOOK(bool isFacingLeft())
SCREWYOU3_HOOK_IMPL(GameObject, isFacingLeft, )
SCREWYOU3_HOOK(bool isSpawnableTrigger())
SCREWYOU3_HOOK_IMPL(GameObject, isSpawnableTrigger, )
SCREWYOU3_HOOK(bool isSpecialObject())
SCREWYOU3_HOOK_IMPL(GameObject, isSpecialObject, )
SCREWYOU3_HOOK(bool isTrigger())
SCREWYOU3_HOOK_IMPL(GameObject, isTrigger, )
SCREWYOU3_HOOK(gd::string perspectiveColorFrame(char const* prefix, int index))
SCREWYOU3_HOOK_IMPL(GameObject, perspectiveColorFrame, prefix, index)
SCREWYOU3_HOOK(gd::string perspectiveFrame(char const* prefix, int index))
SCREWYOU3_HOOK_IMPL(GameObject, perspectiveFrame, prefix, index)
SCREWYOU3_HOOK(bool shouldBlendColor(GJSpriteColor* color, bool mainColor))
SCREWYOU3_HOOK_IMPL(GameObject, shouldBlendColor, color, mainColor)
SCREWYOU3_HOOK(bool shouldLockX())
SCREWYOU3_HOOK_IMPL(GameObject, shouldLockX, )
SCREWYOU3_HOOK(double slopeYPos(float x))
SCREWYOU3_HOOK_IMPL(GameObject, slopeYPos, x)
SCREWYOU3_HOOK_END("GameObject::initWithTexture")

#include <Geode/modify/GameOptionsTrigger.hpp>

gd::string GameOptionsTrigger_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GameOptionsTrigger)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(GameOptionsTrigger, getSaveString, layer)
SCREWYOU3_HOOK_END("GameOptionsTrigger::getSaveString")

#include <Geode/modify/GameStatsManager.hpp>

bool GameStatsManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_awardSecretKey_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameStatsManager_getAwardedCurrencyForLevel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getAwardedDiamondsForLevel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getBaseCurrencyForLevel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getCollectedCoinsForLevel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameStatsManager_getGauntletRewardKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameStatsManager_getItemKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameStatsManager_getItemUnlockState_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getItemUnlockStateLite_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameStatsManager_getLevelKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameStatsManager_getNextVideoAdReward_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameStatsManager_getPathRewardKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameStatsManager_getRewardKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameStatsManager_getSpecialUnlockDescription_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameStatsManager_getStat_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getTotalCollectedCurrency_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getTotalCollectedDiamonds_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameStatsManager_hasClaimedListReward_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_hasCompletedChallenge_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_hasCompletedDailyLevel_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_hasCompletedGauntletLevel_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_hasCompletedLevel_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_hasCompletedMainLevel_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_hasCompletedMapPack_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_hasCompletedOnlineLevel_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_hasCompletedStarLevel_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_hasPendingUserCoin_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_hasRewardBeenCollected_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_hasSecretCoin_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_hasUserCoin_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isItemUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isSecretChestUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isSecretCoinValid_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isSpecialChestUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isStoreItemUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_purchaseItem_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GameStatsManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GameStatsManager, init, )
SCREWYOU3_HOOK(bool awardSecretKey())
SCREWYOU3_HOOK_IMPL(GameStatsManager, awardSecretKey, )
SCREWYOU3_HOOK(int getAwardedCurrencyForLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getAwardedCurrencyForLevel, level)
SCREWYOU3_HOOK(int getAwardedDiamondsForLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getAwardedDiamondsForLevel, level)
SCREWYOU3_HOOK(int getBaseCurrencyForLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getBaseCurrencyForLevel, level)
SCREWYOU3_HOOK(int getCollectedCoinsForLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getCollectedCoinsForLevel, level)
SCREWYOU3_HOOK(gd::string getGauntletRewardKey(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getGauntletRewardKey, id)
SCREWYOU3_HOOK(gd::string getItemKey(int id, int type))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getItemKey, id, type)
SCREWYOU3_HOOK(int getItemUnlockState(int itemID, UnlockType unlockType))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getItemUnlockState, itemID, unlockType)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getItemUnlockStateLite(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getItemUnlockStateLite, id, type)
#endif
SCREWYOU3_HOOK(gd::string getLevelKey(int levelID, bool isOnline, bool isDaily, bool isGauntlet, bool isEvent))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getLevelKey, levelID, isOnline, isDaily, isGauntlet, isEvent)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getNextVideoAdReward())
SCREWYOU3_HOOK_IMPL(GameStatsManager, getNextVideoAdReward, )
#endif
SCREWYOU3_HOOK(gd::string getPathRewardKey(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getPathRewardKey, id)
SCREWYOU3_HOOK(gd::string getRewardKey(GJRewardType type, int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getRewardKey, type, id)
SCREWYOU3_HOOK(gd::string getSpecialUnlockDescription(int id, UnlockType type, bool unused))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getSpecialUnlockDescription, id, type, unused)
SCREWYOU3_HOOK(int getStat(char const* key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getStat, key)
SCREWYOU3_HOOK(int getTotalCollectedCurrency())
SCREWYOU3_HOOK_IMPL(GameStatsManager, getTotalCollectedCurrency, )
SCREWYOU3_HOOK(int getTotalCollectedDiamonds())
SCREWYOU3_HOOK_IMPL(GameStatsManager, getTotalCollectedDiamonds, )
SCREWYOU3_HOOK(bool hasClaimedListReward(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasClaimedListReward, list)
SCREWYOU3_HOOK(bool hasCompletedChallenge(GJChallengeItem* item))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedChallenge, item)
SCREWYOU3_HOOK(bool hasCompletedDailyLevel(int dailyID))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedDailyLevel, dailyID)
SCREWYOU3_HOOK(bool hasCompletedGauntletLevel(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedGauntletLevel, id)
SCREWYOU3_HOOK(bool hasCompletedLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedLevel, level)
SCREWYOU3_HOOK(bool hasCompletedMainLevel(int levelID))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedMainLevel, levelID)
SCREWYOU3_HOOK(bool hasCompletedMapPack(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedMapPack, id)
SCREWYOU3_HOOK(bool hasCompletedOnlineLevel(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedOnlineLevel, id)
SCREWYOU3_HOOK(bool hasCompletedStarLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedStarLevel, level)
SCREWYOU3_HOOK(bool hasPendingUserCoin(char const* key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasPendingUserCoin, key)
SCREWYOU3_HOOK(bool hasRewardBeenCollected(GJRewardType type, int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasRewardBeenCollected, type, id)
SCREWYOU3_HOOK(bool hasSecretCoin(char const* key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasSecretCoin, key)
SCREWYOU3_HOOK(bool hasUserCoin(char const* key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasUserCoin, key)
SCREWYOU3_HOOK(bool isItemUnlocked(UnlockType type, int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isItemUnlocked, type, id)
SCREWYOU3_HOOK(bool isSecretChestUnlocked(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isSecretChestUnlocked, id)
SCREWYOU3_HOOK(bool isSecretCoinValid(gd::string key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isSecretCoinValid, key)
SCREWYOU3_HOOK(bool isSpecialChestUnlocked(gd::string key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isSpecialChestUnlocked, key)
SCREWYOU3_HOOK(bool isStoreItemUnlocked(int index))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isStoreItemUnlocked, index)
SCREWYOU3_HOOK(bool purchaseItem(int index))
SCREWYOU3_HOOK_IMPL(GameStatsManager, purchaseItem, index)
SCREWYOU3_HOOK_END("GameStatsManager::init")

#include <Geode/modify/GameToolbox.hpp>

float GameToolbox_bounceTime_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameToolbox_easeToText_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameToolbox_gen_random_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float GameToolbox_getEasedValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameToolbox_getResponse_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameToolbox_getTimeString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameToolbox_intToShortString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameToolbox_intToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameToolbox_msToTimeString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameToolbox_pointsToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameToolbox_saveParticleToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameToolbox_stringFromHSV_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameToolbox_timestampToHumanReadable_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GameToolbox)
SCREWYOU3_HOOK(static float bounceTime(float time))
SCREWYOU3_HOOK_IMPL(GameToolbox, bounceTime, time)
SCREWYOU3_HOOK(static gd::string easeToText(int easingType))
SCREWYOU3_HOOK_IMPL(GameToolbox, easeToText, easingType)
SCREWYOU3_HOOK(static gd::string gen_random(int length))
SCREWYOU3_HOOK_IMPL(GameToolbox, gen_random, length)
SCREWYOU3_HOOK(static float getEasedValue(float value, int easingType, float easingRate))
SCREWYOU3_HOOK_IMPL(GameToolbox, getEasedValue, value, easingType, easingRate)
SCREWYOU3_HOOK(static gd::string getResponse(cocos2d::extension::CCHttpResponse* response))
SCREWYOU3_HOOK_IMPL(GameToolbox, getResponse, response)
SCREWYOU3_HOOK(static gd::string getTimeString(int seconds, bool noSeconds))
SCREWYOU3_HOOK_IMPL(GameToolbox, getTimeString, seconds, noSeconds)
SCREWYOU3_HOOK(static gd::string intToShortString(int value))
SCREWYOU3_HOOK_IMPL(GameToolbox, intToShortString, value)
SCREWYOU3_HOOK(static gd::string intToString(int value))
SCREWYOU3_HOOK_IMPL(GameToolbox, intToString, value)
SCREWYOU3_HOOK(static gd::string msToTimeString(int milliseconds, int formattingMode))
SCREWYOU3_HOOK_IMPL(GameToolbox, msToTimeString, milliseconds, formattingMode)
SCREWYOU3_HOOK(static gd::string pointsToString(int points))
SCREWYOU3_HOOK_IMPL(GameToolbox, pointsToString, points)
SCREWYOU3_HOOK(static gd::string saveParticleToString(cocos2d::CCParticleSystemQuad* system))
SCREWYOU3_HOOK_IMPL(GameToolbox, saveParticleToString, system)
SCREWYOU3_HOOK(static gd::string stringFromHSV(cocos2d::ccHSVValue value, char const* separator))
SCREWYOU3_HOOK_IMPL(GameToolbox, stringFromHSV, value, separator)
SCREWYOU3_HOOK(static gd::string timestampToHumanReadable(time_t timestamp))
SCREWYOU3_HOOK_IMPL(GameToolbox, timestampToHumanReadable, timestamp)
SCREWYOU3_HOOK_END("GameToolbox::bounceTime")

#include <Geode/modify/GauntletLayer.hpp>

bool GauntletLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GauntletLayer)
SCREWYOU3_HOOK(bool init(GauntletType type))
SCREWYOU3_HOOK_IMPL(GauntletLayer, init, type)
SCREWYOU3_HOOK_END("GauntletLayer::init")

#include <Geode/modify/GauntletNode.hpp>

gd::string GauntletNode_frameForType_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GauntletNode_nameForType_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GauntletNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GauntletNode)
SCREWYOU3_HOOK(static gd::string frameForType(GauntletType type))
SCREWYOU3_HOOK_IMPL(GauntletNode, frameForType, type)
SCREWYOU3_HOOK(static gd::string nameForType(GauntletType type))
SCREWYOU3_HOOK_IMPL(GauntletNode, nameForType, type)
SCREWYOU3_HOOK(bool init(GJMapPack* gauntlet))
SCREWYOU3_HOOK_IMPL(GauntletNode, init, gauntlet)
SCREWYOU3_HOOK_END("GauntletNode::frameForType")

#include <Geode/modify/GauntletSelectLayer.hpp>

bool GauntletSelectLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GauntletSelectLayer)
SCREWYOU3_HOOK(bool init(int unused))
SCREWYOU3_HOOK_IMPL(GauntletSelectLayer, init, unused)
SCREWYOU3_HOOK_END("GauntletSelectLayer::init")

#include <Geode/modify/GhostTrailEffect.hpp>

bool GhostTrailEffect_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GhostTrailEffect)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GhostTrailEffect, init, )
SCREWYOU3_HOOK_END("GhostTrailEffect::init")

#include <Geode/modify/GJAccountManager.hpp>

bool GJAccountManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJAccountManager_backupAccount_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJAccountManager_getAccountBackupURL_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJAccountManager_getAccountSyncURL_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GJAccountManager_getShaPassword_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJAccountManager_syncAccount_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJAccountManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJAccountManager, init, )
SCREWYOU3_HOOK(bool backupAccount(gd::string url))
SCREWYOU3_HOOK_IMPL(GJAccountManager, backupAccount, url)
SCREWYOU3_HOOK(bool getAccountBackupURL())
SCREWYOU3_HOOK_IMPL(GJAccountManager, getAccountBackupURL, )
SCREWYOU3_HOOK(bool getAccountSyncURL())
SCREWYOU3_HOOK_IMPL(GJAccountManager, getAccountSyncURL, )
SCREWYOU3_HOOK(gd::string getShaPassword(gd::string password))
SCREWYOU3_HOOK_IMPL(GJAccountManager, getShaPassword, password)
SCREWYOU3_HOOK(bool syncAccount(gd::string url))
SCREWYOU3_HOOK_IMPL(GJAccountManager, syncAccount, url)
SCREWYOU3_HOOK_END("GJAccountManager::init")

#include <Geode/modify/GJAccountSettingsLayer.hpp>

bool GJAccountSettingsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJAccountSettingsLayer)
SCREWYOU3_HOOK(bool init(int accountID))
SCREWYOU3_HOOK_IMPL(GJAccountSettingsLayer, init, accountID)
SCREWYOU3_HOOK_END("GJAccountSettingsLayer::init")

#include <Geode/modify/GJActionManager.hpp>

bool GJActionManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJActionManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJActionManager, init, )
SCREWYOU3_HOOK_END("GJActionManager::init")

#include <Geode/modify/GJBaseGameLayer.hpp>

bool GJBaseGameLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float GJBaseGameLayer_opacityForObject_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJBaseGameLayer_addGuideArt_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_canBeActivatedByPlayer_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_canProcessSFX_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_checkCollision_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJBaseGameLayer_checkCollisions_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJBaseGameLayer_convertToClosestDirection_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJBaseGameLayer_gameEventToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GJBaseGameLayer_generateEnterEasingBuffer_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

double GJBaseGameLayer_getItemValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJBaseGameLayer_getMaxPortalY_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJBaseGameLayer_getMinDistance_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJBaseGameLayer_getMinPortalY_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJBaseGameLayer_getModifiedDelta_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJBaseGameLayer_getParticleKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJBaseGameLayer_getParticleKey2_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJBaseGameLayer_getRecordString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJBaseGameLayer_hasUniqueCoin_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJBaseGameLayer_maxZOrderForShaderZ_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJBaseGameLayer_minZOrderForShaderZ_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJBaseGameLayer_playerCircleCollision_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_processSongState_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_shouldExitHackedLevel_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float GJBaseGameLayer_volumeForProximityEffect_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GJBaseGameLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, init, )
SCREWYOU3_HOOK(float opacityForObject(GameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, opacityForObject, object)
SCREWYOU3_HOOK(bool addGuideArt(GameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, addGuideArt, object)
SCREWYOU3_HOOK(bool canBeActivatedByPlayer(PlayerObject* player, EffectGameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, canBeActivatedByPlayer, player, object)
SCREWYOU3_HOOK(bool canProcessSFX(SFXTriggerState& state, gd::unordered_map<int, int>& stateIndices, gd::unordered_map<int, float>& times, gd::vector<SFXTriggerState>& states))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, canProcessSFX, state, stateIndices, times, states)
SCREWYOU3_HOOK(bool checkCollision(int blockAID, int blockBID))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, checkCollision, blockAID, blockBID)
SCREWYOU3_HOOK(int checkCollisions(PlayerObject* object, float dt, bool ignoreDamage))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, checkCollisions, object, dt, ignoreDamage)
SCREWYOU3_HOOK(static float convertToClosestDirection(float angle, float bound))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, convertToClosestDirection, angle, bound)
SCREWYOU3_HOOK(static gd::string gameEventToString(GJGameEvent event))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, gameEventToString, event)
SCREWYOU3_HOOK(int generateEnterEasingBuffer(int easingType, float easingRate))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, generateEnterEasingBuffer, easingType, easingRate)
SCREWYOU3_HOOK(double getItemValue(int type, int id))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getItemValue, type, id)
SCREWYOU3_HOOK(float getMaxPortalY())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getMaxPortalY, )
SCREWYOU3_HOOK(float getMinDistance(cocos2d::CCPoint position, cocos2d::CCArray* objects, float minNear, int mode))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getMinDistance, position, objects, minNear, mode)
SCREWYOU3_HOOK(float getMinPortalY())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getMinPortalY, )
SCREWYOU3_HOOK(float getModifiedDelta(float dt))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getModifiedDelta, dt)
SCREWYOU3_HOOK(gd::string getParticleKey(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getParticleKey, objectType, plistName, tag, positionType)
SCREWYOU3_HOOK(gd::string getParticleKey2(gd::string key))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getParticleKey2, key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getRecordString())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getRecordString, )
#endif
SCREWYOU3_HOOK(bool hasUniqueCoin(EffectGameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, hasUniqueCoin, object)
SCREWYOU3_HOOK(int maxZOrderForShaderZ(int zLayer))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, maxZOrderForShaderZ, zLayer)
SCREWYOU3_HOOK(int minZOrderForShaderZ(int zLayer))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, minZOrderForShaderZ, zLayer)
SCREWYOU3_HOOK(bool playerCircleCollision(PlayerObject* player, GameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, playerCircleCollision, player, object)
SCREWYOU3_HOOK(bool processSongState(int musicID, float spawnDelay, float levelTime, int songOffset, float volume, float speed, gd::vector<SongTriggerState>* states, SongTriggerGameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, processSongState, musicID, spawnDelay, levelTime, songOffset, volume, speed, states, object)
SCREWYOU3_HOOK(bool shouldExitHackedLevel())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, shouldExitHackedLevel, )
SCREWYOU3_HOOK(float volumeForProximityEffect(SFXTriggerInstance& instance))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, volumeForProximityEffect, instance)
SCREWYOU3_HOOK_END("GJBaseGameLayer::init")

#include <Geode/modify/GJBigSprite.hpp>

bool GJBigSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJBigSprite)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJBigSprite, init, )
#endif
SCREWYOU3_HOOK_END("GJBigSprite::init")

#include <Geode/modify/GJBigSpriteNode.hpp>

bool GJBigSpriteNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJBigSpriteNode)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJBigSpriteNode, init, )
#endif
SCREWYOU3_HOOK_END("GJBigSpriteNode::init")

#include <Geode/modify/GJColorSetupLayer.hpp>

bool GJColorSetupLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJColorSetupLayer)
SCREWYOU3_HOOK(bool init(LevelSettingsObject* object))
SCREWYOU3_HOOK_IMPL(GJColorSetupLayer, init, object)
SCREWYOU3_HOOK_END("GJColorSetupLayer::init")

#include <Geode/modify/GJComment.hpp>

bool GJComment_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJComment)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJComment, init, )
SCREWYOU3_HOOK_END("GJComment::init")

#include <Geode/modify/GJCommentListLayer.hpp>

bool GJCommentListLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJCommentListLayer)
SCREWYOU3_HOOK(bool init(BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, bool blueBorder))
SCREWYOU3_HOOK_IMPL(GJCommentListLayer, init, listView, title, color, width, height, blueBorder)
SCREWYOU3_HOOK_END("GJCommentListLayer::init")

#include <Geode/modify/GJDifficultySprite.hpp>

gd::string GJDifficultySprite_getDifficultyFrame_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GJDifficultySprite)
SCREWYOU3_HOOK(static gd::string getDifficultyFrame(int difficulty, GJDifficultyName name))
SCREWYOU3_HOOK_IMPL(GJDifficultySprite, getDifficultyFrame, difficulty, name)
SCREWYOU3_HOOK_END("GJDifficultySprite::getDifficultyFrame")

#include <Geode/modify/GJDropDownLayer.hpp>

bool GJDropDownLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJDropDownLayer)
SCREWYOU3_HOOK(bool init(char const* title, float height, bool noBack))
SCREWYOU3_HOOK_IMPL(GJDropDownLayer, init, title, height, noBack)
SCREWYOU3_HOOK_END("GJDropDownLayer::init")

#include <Geode/modify/GJEffectManager.hpp>

bool GJEffectManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJEffectManager_countForItem_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJEffectManager_opacityModForGroup_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

double GJEffectManager_timeForItem_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJEffectManager_timerExists_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJEffectManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJEffectManager, init, )
SCREWYOU3_HOOK(int countForItem(int id))
SCREWYOU3_HOOK_IMPL(GJEffectManager, countForItem, id)
SCREWYOU3_HOOK(float opacityModForGroup(int id))
SCREWYOU3_HOOK_IMPL(GJEffectManager, opacityModForGroup, id)
SCREWYOU3_HOOK(double timeForItem(int id))
SCREWYOU3_HOOK_IMPL(GJEffectManager, timeForItem, id)
SCREWYOU3_HOOK(bool timerExists(int id))
SCREWYOU3_HOOK_IMPL(GJEffectManager, timerExists, id)
SCREWYOU3_HOOK_END("GJEffectManager::init")

#include <Geode/modify/GJFlyGroundLayer.hpp>

bool GJFlyGroundLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJFlyGroundLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJFlyGroundLayer, init, )
#endif
SCREWYOU3_HOOK_END("GJFlyGroundLayer::init")

#include <Geode/modify/GJFollowCommandLayer.hpp>

bool GJFollowCommandLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJFollowCommandLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(GJFollowCommandLayer, init, object, objects)
SCREWYOU3_HOOK_END("GJFollowCommandLayer::init")

#include <Geode/modify/GJFriendRequest.hpp>

bool GJFriendRequest_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJFriendRequest)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJFriendRequest, init, )
SCREWYOU3_HOOK_END("GJFriendRequest::init")

#include <Geode/modify/GJGameLevel.hpp>

gd::string GJGameLevel_lengthKeyToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJGameLevel_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJGameLevel_areCoinsVerified_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GJGameLevel_getAudioFileName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GJGameLevel_getAverageDifficulty_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJGameLevel_getLastBuildPageForTab_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJGameLevel_getSongName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJGameLevel_getUnpackedLevelDescription_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GJGameLevel)
SCREWYOU3_HOOK(static gd::string lengthKeyToString(int key))
SCREWYOU3_HOOK_IMPL(GJGameLevel, lengthKeyToString, key)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJGameLevel, init, )
SCREWYOU3_HOOK(bool areCoinsVerified())
SCREWYOU3_HOOK_IMPL(GJGameLevel, areCoinsVerified, )
SCREWYOU3_HOOK(gd::string getAudioFileName())
SCREWYOU3_HOOK_IMPL(GJGameLevel, getAudioFileName, )
SCREWYOU3_HOOK(int getAverageDifficulty())
SCREWYOU3_HOOK_IMPL(GJGameLevel, getAverageDifficulty, )
SCREWYOU3_HOOK(int getLastBuildPageForTab(int tab))
SCREWYOU3_HOOK_IMPL(GJGameLevel, getLastBuildPageForTab, tab)
SCREWYOU3_HOOK(gd::string getSongName())
SCREWYOU3_HOOK_IMPL(GJGameLevel, getSongName, )
SCREWYOU3_HOOK(gd::string getUnpackedLevelDescription())
SCREWYOU3_HOOK_IMPL(GJGameLevel, getUnpackedLevelDescription, )
SCREWYOU3_HOOK_END("GJGameLevel::lengthKeyToString")

#include <Geode/modify/GJGarageLayer.hpp>

bool GJGarageLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GJGarageLayer_descriptionForUnlock_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GJGarageLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJGarageLayer, init, )
SCREWYOU3_HOOK(static gd::string descriptionForUnlock(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GJGarageLayer, descriptionForUnlock, id, type)
SCREWYOU3_HOOK_END("GJGarageLayer::init")

#include <Geode/modify/GJGradientLayer.hpp>

bool GJGradientLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJGradientLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJGradientLayer, init, )
SCREWYOU3_HOOK_END("GJGradientLayer::init")

#include <Geode/modify/GJGroundLayer.hpp>

bool GJGroundLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float GJGroundLayer_scaleGround_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GJGroundLayer)
SCREWYOU3_HOOK(bool init(int groundID, int lineType))
SCREWYOU3_HOOK_IMPL(GJGroundLayer, init, groundID, lineType)
SCREWYOU3_HOOK(float scaleGround(float scale))
SCREWYOU3_HOOK_IMPL(GJGroundLayer, scaleGround, scale)
SCREWYOU3_HOOK_END("GJGroundLayer::init")

#include <Geode/modify/GJItemIcon.hpp>

float GJItemIcon_scaleForType_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJItemIcon_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJItemIcon)
SCREWYOU3_HOOK(static float scaleForType(UnlockType type))
SCREWYOU3_HOOK_IMPL(GJItemIcon, scaleForType, type)
SCREWYOU3_HOOK(bool init(UnlockType type, int id, cocos2d::ccColor3B color1, cocos2d::ccColor3B color2, bool dark, bool unused, bool noLabel, cocos2d::ccColor3B unlockColor))
SCREWYOU3_HOOK_IMPL(GJItemIcon, init, type, id, color1, color2, dark, unused, noLabel, unlockColor)
SCREWYOU3_HOOK_END("GJItemIcon::scaleForType")

#include <Geode/modify/GJLevelList.hpp>

bool GJLevelList_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJLevelList_completedLevels_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJLevelList_getUnpackedDescription_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJLevelList_hasMatchingLevels_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJLevelList)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJLevelList, init, )
SCREWYOU3_HOOK(int completedLevels())
SCREWYOU3_HOOK_IMPL(GJLevelList, completedLevels, )
SCREWYOU3_HOOK(gd::string getUnpackedDescription())
SCREWYOU3_HOOK_IMPL(GJLevelList, getUnpackedDescription, )
SCREWYOU3_HOOK(bool hasMatchingLevels(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(GJLevelList, hasMatchingLevels, list)
SCREWYOU3_HOOK_END("GJLevelList::init")

#include <Geode/modify/GJLevelScoreCell.hpp>

bool GJLevelScoreCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJLevelScoreCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJLevelScoreCell, init, )
SCREWYOU3_HOOK_END("GJLevelScoreCell::init")

#include <Geode/modify/GJListLayer.hpp>

bool GJListLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJListLayer)
SCREWYOU3_HOOK(bool init(BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, int type))
SCREWYOU3_HOOK_IMPL(GJListLayer, init, listView, title, color, width, height, type)
SCREWYOU3_HOOK_END("GJListLayer::init")

#include <Geode/modify/GJLocalLevelScoreCell.hpp>

bool GJLocalLevelScoreCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJLocalLevelScoreCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJLocalLevelScoreCell, init, )
SCREWYOU3_HOOK_END("GJLocalLevelScoreCell::init")

#include <Geode/modify/GJMapObject.hpp>

bool GJMapObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJMapObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(GJMapObject, init, parent)
#endif
SCREWYOU3_HOOK_END("GJMapObject::init")

#include <Geode/modify/GJMapPack.hpp>

bool GJMapPack_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJMapPack_completedMaps_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GJMapPack)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJMapPack, init, )
SCREWYOU3_HOOK(int completedMaps())
SCREWYOU3_HOOK_IMPL(GJMapPack, completedMaps, )
SCREWYOU3_HOOK_END("GJMapPack::init")

#include <Geode/modify/GJMessageCell.hpp>

bool GJMessageCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJMessageCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJMessageCell, init, )
SCREWYOU3_HOOK_END("GJMessageCell::init")

#include <Geode/modify/GJMessagePopup.hpp>

bool GJMessagePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJMessagePopup)
SCREWYOU3_HOOK(bool init(GJUserMessage* message))
SCREWYOU3_HOOK_IMPL(GJMessagePopup, init, message)
SCREWYOU3_HOOK_END("GJMessagePopup::init")

#include <Geode/modify/GJMGLayer.hpp>

bool GJMGLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJMGLayer)
SCREWYOU3_HOOK(bool init(int index))
SCREWYOU3_HOOK_IMPL(GJMGLayer, init, index)
SCREWYOU3_HOOK_END("GJMGLayer::init")

#include <Geode/modify/GJMultiplayerManager.hpp>

bool GJMultiplayerManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJMultiplayerManager_exitLobby_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GJMultiplayerManager_getBasePostString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJMultiplayerManager_joinLobby_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJMultiplayerManager_uploadComment_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJMultiplayerManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, init, )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool exitLobby(int id))
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, exitLobby, id)
#endif
SCREWYOU3_HOOK(gd::string getBasePostString())
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, getBasePostString, )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool joinLobby(int id))
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, joinLobby, id)
#endif
SCREWYOU3_HOOK(bool uploadComment(gd::string text, int lobbyID))
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, uploadComment, text, lobbyID)
SCREWYOU3_HOOK_END("GJMultiplayerManager::init")

#include <Geode/modify/GJObjectDecoder.hpp>

bool GJObjectDecoder_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJObjectDecoder)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJObjectDecoder, init, )
SCREWYOU3_HOOK_END("GJObjectDecoder::init")

#include <Geode/modify/GJOptionsLayer.hpp>

int GJOptionsLayer_countForPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJOptionsLayer)
SCREWYOU3_HOOK(int countForPage(int page))
SCREWYOU3_HOOK_IMPL(GJOptionsLayer, countForPage, page)
SCREWYOU3_HOOK(bool init(int background))
SCREWYOU3_HOOK_IMPL(GJOptionsLayer, init, background)
SCREWYOU3_HOOK_END("GJOptionsLayer::countForPage")

#include <Geode/modify/GJPathPage.hpp>

bool GJPathPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJPathPage)
SCREWYOU3_HOOK(bool init(int path, GJPathsLayer* layer))
SCREWYOU3_HOOK_IMPL(GJPathPage, init, path, layer)
SCREWYOU3_HOOK_END("GJPathPage::init")

#include <Geode/modify/GJPathRewardPopup.hpp>

bool GJPathRewardPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJPathRewardPopup)
SCREWYOU3_HOOK(bool init(int path))
SCREWYOU3_HOOK_IMPL(GJPathRewardPopup, init, path)
SCREWYOU3_HOOK_END("GJPathRewardPopup::init")

#include <Geode/modify/GJPathsLayer.hpp>

gd::string GJPathsLayer_nameForPath_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJPathsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJPathsLayer)
SCREWYOU3_HOOK(static gd::string nameForPath(int path))
SCREWYOU3_HOOK_IMPL(GJPathsLayer, nameForPath, path)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJPathsLayer, init, )
SCREWYOU3_HOOK_END("GJPathsLayer::nameForPath")

#include <Geode/modify/GJPFollowCommandLayer.hpp>

bool GJPFollowCommandLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJPFollowCommandLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(GJPFollowCommandLayer, init, object, objects)
SCREWYOU3_HOOK_END("GJPFollowCommandLayer::init")

#include <Geode/modify/GJPromoPopup.hpp>

bool GJPromoPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJPromoPopup)
SCREWYOU3_HOOK(bool init(gd::string filename))
SCREWYOU3_HOOK_IMPL(GJPromoPopup, init, filename)
SCREWYOU3_HOOK_END("GJPromoPopup::init")

#include <Geode/modify/GJRequestCell.hpp>

bool GJRequestCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJRequestCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJRequestCell, init, )
SCREWYOU3_HOOK_END("GJRequestCell::init")

#include <Geode/modify/GJRewardItem.hpp>

gd::string GJRewardItem_rewardItemToStat_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJRewardItem_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJRewardItem)
SCREWYOU3_HOOK(static gd::string rewardItemToStat(SpecialRewardItem rewardItem))
SCREWYOU3_HOOK_IMPL(GJRewardItem, rewardItemToStat, rewardItem)
SCREWYOU3_HOOK(bool init(int chestID, int timeRemaining, gd::string rewardStr))
SCREWYOU3_HOOK_IMPL(GJRewardItem, init, chestID, timeRemaining, rewardStr)
SCREWYOU3_HOOK_END("GJRewardItem::rewardItemToStat")

#include <Geode/modify/GJRobotSprite.hpp>

bool GJRobotSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJRobotSprite)
SCREWYOU3_HOOK(bool init(int frame, gd::string animName))
SCREWYOU3_HOOK_IMPL(GJRobotSprite, init, frame, animName)
SCREWYOU3_HOOK_END("GJRobotSprite::init")

#include <Geode/modify/GJRotateCommandLayer.hpp>

bool GJRotateCommandLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJRotateCommandLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(GJRotateCommandLayer, init, object, objects)
#endif
SCREWYOU3_HOOK_END("GJRotateCommandLayer::init")

#include <Geode/modify/GJRotationControl.hpp>

bool GJRotationControl_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJRotationControl_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJRotationControl)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJRotationControl, init, )
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(GJRotationControl, ccTouchBegan, touch, event)
SCREWYOU3_HOOK_END("GJRotationControl::init")

#include <Geode/modify/GJScaleControl.hpp>

bool GJScaleControl_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJScaleControl_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJScaleControl)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJScaleControl, init, )
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(GJScaleControl, ccTouchBegan, touch, event)
SCREWYOU3_HOOK_END("GJScaleControl::init")

#include <Geode/modify/GJScoreCell.hpp>

bool GJScoreCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJScoreCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJScoreCell, init, )
SCREWYOU3_HOOK_END("GJScoreCell::init")

#include <Geode/modify/GJSearchObject.hpp>

bool GJSearchObject_isLevelSearchObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJSearchObject)
SCREWYOU3_HOOK(bool isLevelSearchObject())
SCREWYOU3_HOOK_IMPL(GJSearchObject, isLevelSearchObject, )
SCREWYOU3_HOOK_END("GJSearchObject::isLevelSearchObject")

#include <Geode/modify/GJShopLayer.hpp>

bool GJShopLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJShopLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJShopLayer)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(GJShopLayer, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(bool init(ShopType type))
SCREWYOU3_HOOK_IMPL(GJShopLayer, init, type)
SCREWYOU3_HOOK_END("GJShopLayer::ccTouchBegan")

#include <Geode/modify/GJSmartBlockPreviewSprite.hpp>

bool GJSmartBlockPreviewSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJSmartBlockPreviewSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJSmartBlockPreviewSprite, init, )
SCREWYOU3_HOOK_END("GJSmartBlockPreviewSprite::init")

#include <Geode/modify/GJSmartTemplate.hpp>

gd::string GJSmartTemplate_flipKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJSmartTemplate_getNoCornerKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJSmartTemplate_getSimplifiedKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GJSmartTemplate_getTotalChanceForPrefab_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJSmartTemplate_getVerySimplifiedKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJSmartTemplate_isUnrequired_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GJSmartTemplate_keyFromNeighbors_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJSmartTemplate_logTemplateStatus_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJSmartTemplate_rotateKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GJSmartTemplate)
SCREWYOU3_HOOK(static gd::string flipKey(gd::string key, bool flipX, bool flipY))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, flipKey, key, flipX, flipY)
SCREWYOU3_HOOK(gd::string getNoCornerKey(gd::string key))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, getNoCornerKey, key)
SCREWYOU3_HOOK(static gd::string getSimplifiedKey(gd::string key))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, getSimplifiedKey, key)
SCREWYOU3_HOOK(int getTotalChanceForPrefab(gd::string key))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, getTotalChanceForPrefab, key)
SCREWYOU3_HOOK(static gd::string getVerySimplifiedKey(gd::string key))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, getVerySimplifiedKey, key)
SCREWYOU3_HOOK(bool isUnrequired(gd::string key))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, isUnrequired, key)
SCREWYOU3_HOOK(static gd::string keyFromNeighbors(cocos2d::CCPoint position, SmartGameObject* object, SmartGameObject* left, SmartGameObject* right, SmartGameObject* top, SmartGameObject* bottom, SmartGameObject* topLeft, SmartGameObject* topRight, SmartGameObject* bottomLeft, SmartGameObject* bottomRight))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, keyFromNeighbors, position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight)
SCREWYOU3_HOOK(gd::string logTemplateStatus(bool unused))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, logTemplateStatus, unused)
SCREWYOU3_HOOK(static gd::string rotateKey(gd::string key, int degrees))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, rotateKey, key, degrees)
SCREWYOU3_HOOK_END("GJSmartTemplate::flipKey")

#include <Geode/modify/GJSongBrowser.hpp>

bool GJSongBrowser_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJSongBrowser_cellPerformedAction_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJSongBrowser_getSelectedCellIdx_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GJSongBrowser)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJSongBrowser, init, )
SCREWYOU3_HOOK(bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(GJSongBrowser, cellPerformedAction, cell, listType, action, parent)
SCREWYOU3_HOOK(int getSelectedCellIdx())
SCREWYOU3_HOOK_IMPL(GJSongBrowser, getSelectedCellIdx, )
SCREWYOU3_HOOK_END("GJSongBrowser::init")

#include <Geode/modify/GJSpecialColorSelect.hpp>

const char* GJSpecialColorSelect_textForColorIdx_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJSpecialColorSelect_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJSpecialColorSelect)
SCREWYOU3_HOOK(static const char* textForColorIdx(int index))
SCREWYOU3_HOOK_IMPL(GJSpecialColorSelect, textForColorIdx, index)
SCREWYOU3_HOOK(bool init(int id, GJSpecialColorSelectDelegate* delegate, ColorSelectType type))
SCREWYOU3_HOOK_IMPL(GJSpecialColorSelect, init, id, delegate, type)
SCREWYOU3_HOOK_END("GJSpecialColorSelect::textForColorIdx")

#include <Geode/modify/GJTransformControl.hpp>

bool GJTransformControl_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJTransformControl_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJTransformControl)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJTransformControl, init, )
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(GJTransformControl, ccTouchBegan, touch, event)
SCREWYOU3_HOOK_END("GJTransformControl::init")

#include <Geode/modify/GJUINode.hpp>

int GJUINode_activeTouchTest_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJUINode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJUINode_touchTest_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GJUINode)
SCREWYOU3_HOOK(int activeTouchTest(cocos2d::CCPoint position))
SCREWYOU3_HOOK_IMPL(GJUINode, activeTouchTest, position)
SCREWYOU3_HOOK(bool init(UIButtonConfig& config))
SCREWYOU3_HOOK_IMPL(GJUINode, init, config)
SCREWYOU3_HOOK(int touchTest(cocos2d::CCPoint position))
SCREWYOU3_HOOK_IMPL(GJUINode, touchTest, position)
SCREWYOU3_HOOK_END("GJUINode::activeTouchTest")

#include <Geode/modify/GJUserCell.hpp>

bool GJUserCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJUserCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJUserCell, init, )
SCREWYOU3_HOOK_END("GJUserCell::init")

#include <Geode/modify/GJUserMessage.hpp>

bool GJUserMessage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJUserMessage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJUserMessage, init, )
SCREWYOU3_HOOK_END("GJUserMessage::init")

#include <Geode/modify/GJUserScore.hpp>

bool GJUserScore_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJUserScore_isCurrentUser_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJUserScore)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJUserScore, init, )
SCREWYOU3_HOOK(bool isCurrentUser())
SCREWYOU3_HOOK_IMPL(GJUserScore, isCurrentUser, )
SCREWYOU3_HOOK_END("GJUserScore::init")

#include <Geode/modify/GJWorldNode.hpp>

float GJWorldNode_addDotsToLevel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJWorldNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJWorldNode)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float addDotsToLevel(int levelID, bool animate))
SCREWYOU3_HOOK_IMPL(GJWorldNode, addDotsToLevel, levelID, animate)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int type, WorldSelectLayer* layer))
SCREWYOU3_HOOK_IMPL(GJWorldNode, init, type, layer)
#endif
SCREWYOU3_HOOK_END("GJWorldNode::addDotsToLevel")

#include <Geode/modify/GJWriteMessagePopup.hpp>

bool GJWriteMessagePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJWriteMessagePopup)
SCREWYOU3_HOOK(bool init(int accountID, int messageID))
SCREWYOU3_HOOK_IMPL(GJWriteMessagePopup, init, accountID, messageID)
SCREWYOU3_HOOK_END("GJWriteMessagePopup::init")

#include <Geode/modify/GManager.hpp>

bool GManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GManager_getCompressedSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GManager, init, )
SCREWYOU3_HOOK(gd::string getCompressedSaveString())
SCREWYOU3_HOOK_IMPL(GManager, getCompressedSaveString, )
SCREWYOU3_HOOK_END("GManager::init")

#include <Geode/modify/GradientTriggerObject.hpp>

bool GradientTriggerObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GradientTriggerObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GradientTriggerObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GradientTriggerObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(GradientTriggerObject, getSaveString, layer)
SCREWYOU3_HOOK_END("GradientTriggerObject::init")

#include <Geode/modify/GravityEffectSprite.hpp>

bool GravityEffectSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GravityEffectSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GravityEffectSprite, init, )
SCREWYOU3_HOOK_END("GravityEffectSprite::init")

#include <Geode/modify/HardStreak.hpp>

bool HardStreak_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(HardStreak)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(HardStreak, init, )
SCREWYOU3_HOOK_END("HardStreak::init")

#include <Geode/modify/HSVLiveOverlay.hpp>

bool HSVLiveOverlay_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(HSVLiveOverlay)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(HSVLiveOverlay, init, object, objects)
SCREWYOU3_HOOK_END("HSVLiveOverlay::init")

#include <Geode/modify/HSVWidgetPopup.hpp>

bool HSVWidgetPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(HSVWidgetPopup)
SCREWYOU3_HOOK(bool init(cocos2d::ccHSVValue hsv, HSVWidgetDelegate* delegate, gd::string title))
SCREWYOU3_HOOK_IMPL(HSVWidgetPopup, init, hsv, delegate, title)
SCREWYOU3_HOOK_END("HSVWidgetPopup::init")

#include <Geode/modify/InfoLayer.hpp>

bool InfoLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool InfoLayer_isCorrect_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(InfoLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, GJUserScore* score, GJLevelList* list))
SCREWYOU3_HOOK_IMPL(InfoLayer, init, level, score, list)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(InfoLayer, isCorrect, key)
SCREWYOU3_HOOK_END("InfoLayer::init")

#include <Geode/modify/ItemInfoPopup.hpp>

gd::string ItemInfoPopup_nameForUnlockType_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool ItemInfoPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ItemInfoPopup)
SCREWYOU3_HOOK(static gd::string nameForUnlockType(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(ItemInfoPopup, nameForUnlockType, id, type)
SCREWYOU3_HOOK(bool init(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(ItemInfoPopup, init, id, type)
SCREWYOU3_HOOK_END("ItemInfoPopup::nameForUnlockType")

#include <Geode/modify/ItemTriggerGameObject.hpp>

gd::string ItemTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(ItemTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(ItemTriggerGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("ItemTriggerGameObject::getSaveString")

#include <Geode/modify/KeybindingsLayer.hpp>

bool KeybindingsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int KeybindingsLayer_countForPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(KeybindingsLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(KeybindingsLayer, init, )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int countForPage(int page))
SCREWYOU3_HOOK_IMPL(KeybindingsLayer, countForPage, page)
#endif
SCREWYOU3_HOOK_END("KeybindingsLayer::init")

#include <Geode/modify/KeybindingsManager.hpp>

bool KeybindingsManager_commandForKey_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool KeybindingsManager_commandForKeyMods_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool KeybindingsManager_commandForKeyNoMods_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(KeybindingsManager)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool commandForKey(cocos2d::enumKeyCodes key, GJKeyGroup group, bool control, bool alt, bool shift))
SCREWYOU3_HOOK_IMPL(KeybindingsManager, commandForKey, key, group, control, alt, shift)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool commandForKeyMods(cocos2d::enumKeyCodes key, GJKeyGroup group))
SCREWYOU3_HOOK_IMPL(KeybindingsManager, commandForKeyMods, key, group)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool commandForKeyNoMods(cocos2d::enumKeyCodes key, GJKeyGroup group))
SCREWYOU3_HOOK_IMPL(KeybindingsManager, commandForKeyNoMods, key, group)
#endif
SCREWYOU3_HOOK_END("KeybindingsManager::commandForKey")

#include <Geode/modify/KeyframeAnimTriggerObject.hpp>

bool KeyframeAnimTriggerObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string KeyframeAnimTriggerObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(KeyframeAnimTriggerObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(KeyframeAnimTriggerObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(KeyframeAnimTriggerObject, getSaveString, layer)
SCREWYOU3_HOOK_END("KeyframeAnimTriggerObject::init")

#include <Geode/modify/KeyframeGameObject.hpp>

bool KeyframeGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string KeyframeGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(KeyframeGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(KeyframeGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(KeyframeGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("KeyframeGameObject::init")

#include <Geode/modify/LabelGameObject.hpp>

bool LabelGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string LabelGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int LabelGameObject_getTextKerning_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(LabelGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LabelGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(LabelGameObject, getSaveString, layer)
SCREWYOU3_HOOK(int getTextKerning())
SCREWYOU3_HOOK_IMPL(LabelGameObject, getTextKerning, )
SCREWYOU3_HOOK_END("LabelGameObject::init")

#include <Geode/modify/LeaderboardsLayer.hpp>

bool LeaderboardsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LeaderboardsLayer_isCorrect_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LeaderboardsLayer)
SCREWYOU3_HOOK(bool init(LeaderboardState state))
SCREWYOU3_HOOK_IMPL(LeaderboardsLayer, init, state)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(LeaderboardsLayer, isCorrect, key)
SCREWYOU3_HOOK_END("LeaderboardsLayer::init")

#include <Geode/modify/LevelAreaInnerLayer.hpp>

bool LevelAreaInnerLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelAreaInnerLayer_playStep1_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelAreaInnerLayer)
SCREWYOU3_HOOK(bool init(bool returning))
SCREWYOU3_HOOK_IMPL(LevelAreaInnerLayer, init, returning)
SCREWYOU3_HOOK(bool playStep1())
SCREWYOU3_HOOK_IMPL(LevelAreaInnerLayer, playStep1, )
SCREWYOU3_HOOK_END("LevelAreaInnerLayer::init")

#include <Geode/modify/LevelAreaLayer.hpp>

bool LevelAreaLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelAreaLayer_onEnterTower_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelAreaLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LevelAreaLayer, init, )
SCREWYOU3_HOOK(bool onEnterTower())
SCREWYOU3_HOOK_IMPL(LevelAreaLayer, onEnterTower, )
SCREWYOU3_HOOK_END("LevelAreaLayer::init")

#include <Geode/modify/LevelBrowserLayer.hpp>

bool LevelBrowserLayer_cellPerformedAction_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string LevelBrowserLayer_getSearchTitle_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool LevelBrowserLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelBrowserLayer_isCorrect_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelBrowserLayer)
SCREWYOU3_HOOK(bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(LevelBrowserLayer, cellPerformedAction, cell, listType, action, parent)
SCREWYOU3_HOOK(gd::string getSearchTitle())
SCREWYOU3_HOOK_IMPL(LevelBrowserLayer, getSearchTitle, )
SCREWYOU3_HOOK(bool init(GJSearchObject* object))
SCREWYOU3_HOOK_IMPL(LevelBrowserLayer, init, object)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(LevelBrowserLayer, isCorrect, key)
SCREWYOU3_HOOK_END("LevelBrowserLayer::cellPerformedAction")

#include <Geode/modify/LevelCell.hpp>

bool LevelCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LevelCell, init, )
SCREWYOU3_HOOK_END("LevelCell::init")

#include <Geode/modify/LevelEditorLayer.hpp>

float LevelEditorLayer_timeForPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool LevelEditorLayer_activateTriggerEffect_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float LevelEditorLayer_getLastObjectX_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string LevelEditorLayer_getLevelString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int LevelEditorLayer_getNextColorChannel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int LevelEditorLayer_getNextFreeAreaEffectID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int LevelEditorLayer_getNextFreeEditorLayer_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int LevelEditorLayer_getNextFreeEnterChannel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int LevelEditorLayer_getNextFreeGradientID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int LevelEditorLayer_getNextFreeGroupID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int LevelEditorLayer_getNextFreeItemID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int LevelEditorLayer_getNextFreeOrderChannel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string LevelEditorLayer_getSFXIDs_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string LevelEditorLayer_getSongIDs_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool LevelEditorLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float LevelEditorLayer_rotationForSlopeNearObject_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool LevelEditorLayer_shouldBlend_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelEditorLayer_tryUpdateSpeedObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelEditorLayer_typeExistsAtPosition_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelEditorLayer)
SCREWYOU3_HOOK(float timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, int id))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, timeForPos, position, order, channel, songTriggers, id)
SCREWYOU3_HOOK(bool activateTriggerEffect(EffectGameObject* object, float currentTime, float playTime, float boundTime, bool active))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, activateTriggerEffect, object, currentTime, playTime, boundTime, active)
SCREWYOU3_HOOK(float getLastObjectX())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getLastObjectX, )
SCREWYOU3_HOOK(gd::string getLevelString())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getLevelString, )
SCREWYOU3_HOOK(int getNextColorChannel())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextColorChannel, )
SCREWYOU3_HOOK(int getNextFreeAreaEffectID(cocos2d::CCArray* exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeAreaEffectID, exclude)
SCREWYOU3_HOOK(int getNextFreeEditorLayer(cocos2d::CCArray* exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeEditorLayer, exclude)
SCREWYOU3_HOOK(int getNextFreeEnterChannel(cocos2d::CCArray* exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeEnterChannel, exclude)
SCREWYOU3_HOOK(int getNextFreeGradientID(cocos2d::CCArray* exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeGradientID, exclude)
SCREWYOU3_HOOK(int getNextFreeGroupID(cocos2d::CCArray* exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeGroupID, exclude)
SCREWYOU3_HOOK(int getNextFreeItemID(cocos2d::CCArray* exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeItemID, exclude)
SCREWYOU3_HOOK(int getNextFreeOrderChannel(cocos2d::CCArray* exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeOrderChannel, exclude)
SCREWYOU3_HOOK(gd::string getSFXIDs())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getSFXIDs, )
SCREWYOU3_HOOK(gd::string getSongIDs(bool& multipleSongs))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getSongIDs, multipleSongs)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, bool noUI))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, init, level, noUI)
SCREWYOU3_HOOK(float rotationForSlopeNearObject(GameObject* object))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, rotationForSlopeNearObject, object)
SCREWYOU3_HOOK(bool shouldBlend(int colorID))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, shouldBlend, colorID)
SCREWYOU3_HOOK(bool tryUpdateSpeedObject(EffectGameObject* object, bool noPreview))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, tryUpdateSpeedObject, object, noPreview)
SCREWYOU3_HOOK(bool typeExistsAtPosition(int objectID, cocos2d::CCPoint position, bool flipX, bool flipY, float rotation))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, typeExistsAtPosition, objectID, position, flipX, flipY, rotation)
SCREWYOU3_HOOK_END("LevelEditorLayer::timeForPos")

#include <Geode/modify/LevelFeatureLayer.hpp>

bool LevelFeatureLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelFeatureLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int levelID))
SCREWYOU3_HOOK_IMPL(LevelFeatureLayer, init, levelID)
#endif
SCREWYOU3_HOOK_END("LevelFeatureLayer::init")

#include <Geode/modify/LevelInfoLayer.hpp>

bool LevelInfoLayer_cellPerformedAction_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelInfoLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelInfoLayer_shouldDownloadLevel_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelInfoLayer)
SCREWYOU3_HOOK(bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(LevelInfoLayer, cellPerformedAction, cell, listType, action, parent)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, bool challenge))
SCREWYOU3_HOOK_IMPL(LevelInfoLayer, init, level, challenge)
SCREWYOU3_HOOK(bool shouldDownloadLevel())
SCREWYOU3_HOOK_IMPL(LevelInfoLayer, shouldDownloadLevel, )
SCREWYOU3_HOOK_END("LevelInfoLayer::cellPerformedAction")

#include <Geode/modify/LevelLeaderboard.hpp>

bool LevelLeaderboard_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelLeaderboard_isCorrect_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelLeaderboard)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, LevelLeaderboardType type, LevelLeaderboardMode mode))
SCREWYOU3_HOOK_IMPL(LevelLeaderboard, init, level, type, mode)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(LevelLeaderboard, isCorrect, key)
SCREWYOU3_HOOK_END("LevelLeaderboard::init")

#include <Geode/modify/LevelListLayer.hpp>

bool LevelListLayer_cellPerformedAction_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelListLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelListLayer)
SCREWYOU3_HOOK(bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(LevelListLayer, cellPerformedAction, cell, listType, action, parent)
SCREWYOU3_HOOK(bool init(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(LevelListLayer, init, list)
SCREWYOU3_HOOK_END("LevelListLayer::cellPerformedAction")

#include <Geode/modify/LevelOptionsLayer.hpp>

float LevelOptionsLayer_getValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool LevelOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelOptionsLayer)
SCREWYOU3_HOOK(float getValue(int tag))
SCREWYOU3_HOOK_IMPL(LevelOptionsLayer, getValue, tag)
SCREWYOU3_HOOK(bool init(LevelSettingsObject* object))
SCREWYOU3_HOOK_IMPL(LevelOptionsLayer, init, object)
SCREWYOU3_HOOK_END("LevelOptionsLayer::getValue")

#include <Geode/modify/LevelPage.hpp>

bool LevelPage_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelPage)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(LevelPage, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(LevelPage, init, level)
SCREWYOU3_HOOK_END("LevelPage::ccTouchBegan")

#include <Geode/modify/LevelSearchLayer.hpp>

bool LevelSearchLayer_checkDiff_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelSearchLayer_checkTime_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelSearchLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelSearchLayer)
SCREWYOU3_HOOK(bool checkDiff(int diff))
SCREWYOU3_HOOK_IMPL(LevelSearchLayer, checkDiff, diff)
SCREWYOU3_HOOK(bool checkTime(int time))
SCREWYOU3_HOOK_IMPL(LevelSearchLayer, checkTime, time)
SCREWYOU3_HOOK(bool init(int type))
SCREWYOU3_HOOK_IMPL(LevelSearchLayer, init, type)
SCREWYOU3_HOOK_END("LevelSearchLayer::checkDiff")

#include <Geode/modify/LevelSelectLayer.hpp>

bool LevelSelectLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelSelectLayer)
SCREWYOU3_HOOK(bool init(int page))
SCREWYOU3_HOOK_IMPL(LevelSelectLayer, init, page)
SCREWYOU3_HOOK_END("LevelSelectLayer::init")

#include <Geode/modify/LevelSettingsLayer.hpp>

bool LevelSettingsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelSettingsLayer)
SCREWYOU3_HOOK(bool init(LevelSettingsObject* object, LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(LevelSettingsLayer, init, object, layer)
SCREWYOU3_HOOK_END("LevelSettingsLayer::init")

#include <Geode/modify/LevelSettingsObject.hpp>

bool LevelSettingsObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string LevelSettingsObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(LevelSettingsObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LevelSettingsObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString())
SCREWYOU3_HOOK_IMPL(LevelSettingsObject, getSaveString, )
SCREWYOU3_HOOK_END("LevelSettingsObject::init")

#include <Geode/modify/LevelTools.hpp>

int LevelTools_artistForAudio_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string LevelTools_fbURLForArtist_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string LevelTools_getAudioFileName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string LevelTools_getAudioString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string LevelTools_getAudioTitle_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string LevelTools_nameForArtist_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string LevelTools_ngURLForArtist_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float LevelTools_timeForPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string LevelTools_urlForAudio_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool LevelTools_verifyLevelIntegrity_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string LevelTools_ytURLForArtist_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(LevelTools)
SCREWYOU3_HOOK(static int artistForAudio(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, artistForAudio, id)
SCREWYOU3_HOOK(static gd::string fbURLForArtist(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, fbURLForArtist, id)
SCREWYOU3_HOOK(static gd::string getAudioFileName(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, getAudioFileName, id)
SCREWYOU3_HOOK(static gd::string getAudioString(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, getAudioString, id)
SCREWYOU3_HOOK(static gd::string getAudioTitle(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, getAudioTitle, id)
SCREWYOU3_HOOK(static gd::string nameForArtist(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, nameForArtist, id)
SCREWYOU3_HOOK(static gd::string ngURLForArtist(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, ngURLForArtist, id)
SCREWYOU3_HOOK(static float timeForPos(cocos2d::CCPoint position, cocos2d::CCArray* objects, int speed, int order, int channel, bool songTriggers, bool platformer, bool ignoreWarp, bool ignoreRotate, int id))
SCREWYOU3_HOOK_IMPL(LevelTools, timeForPos, position, objects, speed, order, channel, songTriggers, platformer, ignoreWarp, ignoreRotate, id)
SCREWYOU3_HOOK(static gd::string urlForAudio(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, urlForAudio, id)
SCREWYOU3_HOOK(static bool verifyLevelIntegrity(gd::string str, int id))
SCREWYOU3_HOOK_IMPL(LevelTools, verifyLevelIntegrity, str, id)
SCREWYOU3_HOOK(static gd::string ytURLForArtist(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, ytURLForArtist, id)
SCREWYOU3_HOOK_END("LevelTools::artistForAudio")

#include <Geode/modify/LikeItemLayer.hpp>

bool LikeItemLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LikeItemLayer)
SCREWYOU3_HOOK(bool init(LikeItemType type, int id, int parentID))
SCREWYOU3_HOOK_IMPL(LikeItemLayer, init, type, id, parentID)
SCREWYOU3_HOOK_END("LikeItemLayer::init")

#include <Geode/modify/ListButtonBar.hpp>

bool ListButtonBar_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ListButtonBar)
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* items, cocos2d::CCPoint position, int columns, int rows, float columnOffset, float rowOffset, float offset, float arrowOffset, int arrowType))
SCREWYOU3_HOOK_IMPL(ListButtonBar, init, items, position, columns, rows, columnOffset, rowOffset, offset, arrowOffset, arrowType)
SCREWYOU3_HOOK_END("ListButtonBar::init")

#include <Geode/modify/LoadingCircle.hpp>

bool LoadingCircle_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LoadingCircle)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LoadingCircle, init, )
SCREWYOU3_HOOK_END("LoadingCircle::init")

#include <Geode/modify/LoadingLayer.hpp>

const char* LoadingLayer_getLoadingString_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool LoadingLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LoadingLayer)
SCREWYOU3_HOOK(const char* getLoadingString())
SCREWYOU3_HOOK_IMPL(LoadingLayer, getLoadingString, )
SCREWYOU3_HOOK(bool init(bool refresh))
SCREWYOU3_HOOK_IMPL(LoadingLayer, init, refresh)
SCREWYOU3_HOOK_END("LoadingLayer::getLoadingString")

#include <Geode/modify/LocalLevelManager.hpp>

bool LocalLevelManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string LocalLevelManager_getMainLevelString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int LocalLevelManager_updateLevelOrder_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(LocalLevelManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LocalLevelManager, init, )
SCREWYOU3_HOOK(gd::string getMainLevelString(int id))
SCREWYOU3_HOOK_IMPL(LocalLevelManager, getMainLevelString, id)
SCREWYOU3_HOOK(int updateLevelOrder())
SCREWYOU3_HOOK_IMPL(LocalLevelManager, updateLevelOrder, )
SCREWYOU3_HOOK_END("LocalLevelManager::init")

#include <Geode/modify/MapPackCell.hpp>

bool MapPackCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MapPackCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MapPackCell, init, )
SCREWYOU3_HOOK_END("MapPackCell::init")

#include <Geode/modify/MapSelectLayer.hpp>

bool MapSelectLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MapSelectLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MapSelectLayer_checkTouchMonster_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MapSelectLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MapSelectLayer, init, )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(MapSelectLayer, ccTouchBegan, touch, event)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool checkTouchMonster(cocos2d::CCPoint position))
SCREWYOU3_HOOK_IMPL(MapSelectLayer, checkTouchMonster, position)
#endif
SCREWYOU3_HOOK_END("MapSelectLayer::init")

#include <Geode/modify/MenuGameLayer.hpp>

bool MenuGameLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MenuGameLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MenuGameLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MenuGameLayer, init, )
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(MenuGameLayer, ccTouchBegan, touch, event)
SCREWYOU3_HOOK_END("MenuGameLayer::init")

#include <Geode/modify/MenuLayer.hpp>

bool MenuLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MenuLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_MENULAYER_CUSTOM_INIT(MenuLayer, init, )
SCREWYOU3_HOOK_END("MenuLayer::init")

#include <Geode/modify/MessagesProfilePage.hpp>

bool MessagesProfilePage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MessagesProfilePage_isCorrect_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MessagesProfilePage)
SCREWYOU3_HOOK(bool init(bool sent))
SCREWYOU3_HOOK_IMPL(MessagesProfilePage, init, sent)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(MessagesProfilePage, isCorrect, key)
SCREWYOU3_HOOK_END("MessagesProfilePage::init")

#include <Geode/modify/MoreOptionsLayer.hpp>

bool MoreOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int MoreOptionsLayer_countForPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(MoreOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MoreOptionsLayer, init, )
SCREWYOU3_HOOK(int countForPage(int page))
SCREWYOU3_HOOK_IMPL(MoreOptionsLayer, countForPage, page)
SCREWYOU3_HOOK_END("MoreOptionsLayer::init")

#include <Geode/modify/MoreSearchLayer.hpp>

bool MoreSearchLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MoreSearchLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MoreSearchLayer, init, )
SCREWYOU3_HOOK_END("MoreSearchLayer::init")

#include <Geode/modify/MoreVideoOptionsLayer.hpp>

bool MoreVideoOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int MoreVideoOptionsLayer_countForPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(MoreVideoOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MoreVideoOptionsLayer, init, )
SCREWYOU3_HOOK(int countForPage(int page))
SCREWYOU3_HOOK_IMPL(MoreVideoOptionsLayer, countForPage, page)
SCREWYOU3_HOOK_END("MoreVideoOptionsLayer::init")

#include <Geode/modify/MPLobbyLayer.hpp>

bool MPLobbyLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MPLobbyLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int type))
SCREWYOU3_HOOK_IMPL(MPLobbyLayer, init, type)
#endif
SCREWYOU3_HOOK_END("MPLobbyLayer::init")

#include <Geode/modify/MultilineBitmapFont.hpp>

bool MultilineBitmapFont_initWithFont_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string MultilineBitmapFont_readColorInfo_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string MultilineBitmapFont_stringWithMaxWidth_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(MultilineBitmapFont)
SCREWYOU3_HOOK(bool initWithFont(char const* font, gd::string text, float scale, float width, cocos2d::CCPoint anchor, int height, bool disableColor))
SCREWYOU3_HOOK_IMPL(MultilineBitmapFont, initWithFont, font, text, scale, width, anchor, height, disableColor)
SCREWYOU3_HOOK(gd::string readColorInfo(gd::string text))
SCREWYOU3_HOOK_IMPL(MultilineBitmapFont, readColorInfo, text)
SCREWYOU3_HOOK(gd::string stringWithMaxWidth(gd::string text, float width, float scale))
SCREWYOU3_HOOK_IMPL(MultilineBitmapFont, stringWithMaxWidth, text, width, scale)
SCREWYOU3_HOOK_END("MultilineBitmapFont::initWithFont")

#include <Geode/modify/MultiplayerLayer.hpp>

bool MultiplayerLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MultiplayerLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MultiplayerLayer, init, )
#endif
SCREWYOU3_HOOK_END("MultiplayerLayer::init")

#include <Geode/modify/MultiTriggerPopup.hpp>

bool MultiTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MultiTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(MultiTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("MultiTriggerPopup::init")

#include <Geode/modify/MusicBrowser.hpp>

bool MusicBrowser_cellPerformedAction_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int MusicBrowser_getSelectedCellIdx_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool MusicBrowser_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MusicBrowser)
SCREWYOU3_HOOK(bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(MusicBrowser, cellPerformedAction, cell, listType, action, parent)
SCREWYOU3_HOOK(int getSelectedCellIdx())
SCREWYOU3_HOOK_IMPL(MusicBrowser, getSelectedCellIdx, )
SCREWYOU3_HOOK(bool init(int songID, GJSongType songType))
SCREWYOU3_HOOK_IMPL(MusicBrowser, init, songID, songType)
SCREWYOU3_HOOK_END("MusicBrowser::cellPerformedAction")

#include <Geode/modify/MusicDownloadManager.hpp>

bool MusicDownloadManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string MusicDownloadManager_generateCustomContentURL_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string MusicDownloadManager_getSFXFolderPathForID_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool MusicDownloadManager_isRunningActionForSongID_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MusicDownloadManager_isSFXDownloaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MusicDownloadManager_isSongDownloaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string MusicDownloadManager_pathForSFX_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string MusicDownloadManager_pathForSFXFolder_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string MusicDownloadManager_pathForSong_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string MusicDownloadManager_pathForSongFolder_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(MusicDownloadManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, init, )
SCREWYOU3_HOOK(gd::string generateCustomContentURL(gd::string path))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, generateCustomContentURL, path)
SCREWYOU3_HOOK(gd::string getSFXFolderPathForID(int id, bool nextFolder))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, getSFXFolderPathForID, id, nextFolder)
SCREWYOU3_HOOK(bool isRunningActionForSongID(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, isRunningActionForSongID, id)
SCREWYOU3_HOOK(bool isSFXDownloaded(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, isSFXDownloaded, id)
SCREWYOU3_HOOK(bool isSongDownloaded(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, isSongDownloaded, id)
SCREWYOU3_HOOK(gd::string pathForSFX(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, pathForSFX, id)
SCREWYOU3_HOOK(gd::string pathForSFXFolder(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, pathForSFXFolder, id)
SCREWYOU3_HOOK(gd::string pathForSong(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, pathForSong, id)
SCREWYOU3_HOOK(gd::string pathForSongFolder(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, pathForSongFolder, id)
SCREWYOU3_HOOK_END("MusicDownloadManager::init")

#include <Geode/modify/NCSInfoLayer.hpp>

bool NCSInfoLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(NCSInfoLayer)
SCREWYOU3_HOOK(bool init(CustomSongLayer* layer))
SCREWYOU3_HOOK_IMPL(NCSInfoLayer, init, layer)
SCREWYOU3_HOOK_END("NCSInfoLayer::init")

#include <Geode/modify/NewgroundsInfoLayer.hpp>

bool NewgroundsInfoLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(NewgroundsInfoLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(NewgroundsInfoLayer, init, )
SCREWYOU3_HOOK_END("NewgroundsInfoLayer::init")

#include <Geode/modify/NumberInputLayer.hpp>

bool NumberInputLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(NumberInputLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(NumberInputLayer, init, )
SCREWYOU3_HOOK_END("NumberInputLayer::init")

#include <Geode/modify/OBB2D.hpp>

bool OBB2D_overlaps1Way_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(OBB2D)
SCREWYOU3_HOOK(bool overlaps1Way(OBB2D* other))
SCREWYOU3_HOOK_IMPL(OBB2D, overlaps1Way, other)
SCREWYOU3_HOOK_END("OBB2D::overlaps1Way")

#include <Geode/modify/ObjectControlGameObject.hpp>

bool ObjectControlGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string ObjectControlGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(ObjectControlGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ObjectControlGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(ObjectControlGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("ObjectControlGameObject::init")

#include <Geode/modify/ObjectManager.hpp>

bool ObjectManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ObjectManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ObjectManager, init, )
SCREWYOU3_HOOK_END("ObjectManager::init")

#include <Geode/modify/ObjectToolbox.hpp>

bool ObjectToolbox_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float ObjectToolbox_gridNodeSizeForKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

const char* ObjectToolbox_intKeyToFrame_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* ObjectToolbox_perspectiveBlockFrame_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(ObjectToolbox)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ObjectToolbox, init, )
SCREWYOU3_HOOK(float gridNodeSizeForKey(int key))
SCREWYOU3_HOOK_IMPL(ObjectToolbox, gridNodeSizeForKey, key)
SCREWYOU3_HOOK(const char* intKeyToFrame(int key))
SCREWYOU3_HOOK_IMPL(ObjectToolbox, intKeyToFrame, key)
SCREWYOU3_HOOK(const char* perspectiveBlockFrame(int key))
SCREWYOU3_HOOK_IMPL(ObjectToolbox, perspectiveBlockFrame, key)
SCREWYOU3_HOOK_END("ObjectToolbox::init")

#include <Geode/modify/OptionsScrollLayer.hpp>

bool OptionsScrollLayer_cellPerformedAction_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(OptionsScrollLayer)
SCREWYOU3_HOOK(bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(OptionsScrollLayer, cellPerformedAction, cell, listType, action, parent)
SCREWYOU3_HOOK_END("OptionsScrollLayer::cellPerformedAction")

#include <Geode/modify/ParentalOptionsLayer.hpp>

bool ParentalOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int ParentalOptionsLayer_countForPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(ParentalOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ParentalOptionsLayer, init, )
SCREWYOU3_HOOK(int countForPage(int page))
SCREWYOU3_HOOK_IMPL(ParentalOptionsLayer, countForPage, page)
SCREWYOU3_HOOK_END("ParentalOptionsLayer::init")

#include <Geode/modify/ParticleGameObject.hpp>

bool ParticleGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string ParticleGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(ParticleGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ParticleGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(ParticleGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("ParticleGameObject::init")

#include <Geode/modify/PlatformToolbox.hpp>

bool PlatformToolbox_copyToClipboard_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string PlatformToolbox_getUniqueUserID_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(PlatformToolbox)
SCREWYOU3_HOOK(static bool copyToClipboard(gd::string str))
SCREWYOU3_HOOK_IMPL(PlatformToolbox, copyToClipboard, str)
SCREWYOU3_HOOK(static gd::string getUniqueUserID())
SCREWYOU3_HOOK_IMPL(PlatformToolbox, getUniqueUserID, )
SCREWYOU3_HOOK_END("PlatformToolbox::copyToClipboard")

#include <Geode/modify/PlayerCheckpoint.hpp>

bool PlayerCheckpoint_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PlayerCheckpoint)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(PlayerCheckpoint, init, )
SCREWYOU3_HOOK_END("PlayerCheckpoint::init")

#include <Geode/modify/PlayerControlGameObject.hpp>

bool PlayerControlGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string PlayerControlGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(PlayerControlGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(PlayerControlGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(PlayerControlGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("PlayerControlGameObject::init")

#include <Geode/modify/PlayerFireBoostSprite.hpp>

bool PlayerFireBoostSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PlayerFireBoostSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(PlayerFireBoostSprite, init, )
SCREWYOU3_HOOK_END("PlayerFireBoostSprite::init")

#include <Geode/modify/PlayerObject.hpp>

float PlayerObject_getObjectRotation_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool PlayerObject_collidedWithObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_collidedWithObjectInternal_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float PlayerObject_convertToClosestRotation_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool PlayerObject_handleRotatedCollisionInternal_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_levelFlipping_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_playerIsFallingBugged_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_preSlopeCollision_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_pushButton_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_releaseButton_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_switchedDirTo_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PlayerObject)
SCREWYOU3_HOOK(float getObjectRotation())
SCREWYOU3_HOOK_IMPL(PlayerObject, getObjectRotation, )
SCREWYOU3_HOOK(bool collidedWithObject(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck))
SCREWYOU3_HOOK_IMPL(PlayerObject, collidedWithObject, dt, object, rect, skipCheck)
SCREWYOU3_HOOK(bool collidedWithObjectInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck))
SCREWYOU3_HOOK_IMPL(PlayerObject, collidedWithObjectInternal, dt, object, rect, skipCheck)
SCREWYOU3_HOOK(float convertToClosestRotation(float rotation))
SCREWYOU3_HOOK_IMPL(PlayerObject, convertToClosestRotation, rotation)
SCREWYOU3_HOOK(bool handleRotatedCollisionInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck, bool skipPre, bool slope))
SCREWYOU3_HOOK_IMPL(PlayerObject, handleRotatedCollisionInternal, dt, object, rect, skipCheck, skipPre, slope)
SCREWYOU3_HOOK(bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer))
SCREWYOU3_HOOK_IMPL(PlayerObject, init, player, ship, gameLayer, layer, playLayer)
SCREWYOU3_HOOK(bool levelFlipping())
SCREWYOU3_HOOK_IMPL(PlayerObject, levelFlipping, )
SCREWYOU3_HOOK(bool playerIsFallingBugged())
SCREWYOU3_HOOK_IMPL(PlayerObject, playerIsFallingBugged, )
SCREWYOU3_HOOK(bool preSlopeCollision(float dt, GameObject* object))
SCREWYOU3_HOOK_IMPL(PlayerObject, preSlopeCollision, dt, object)
SCREWYOU3_HOOK(bool pushButton(PlayerButton button))
SCREWYOU3_HOOK_IMPL(PlayerObject, pushButton, button)
SCREWYOU3_HOOK(bool releaseButton(PlayerButton button))
SCREWYOU3_HOOK_IMPL(PlayerObject, releaseButton, button)
SCREWYOU3_HOOK(bool switchedDirTo(PlayerButton button))
SCREWYOU3_HOOK_IMPL(PlayerObject, switchedDirTo, button)
SCREWYOU3_HOOK_END("PlayerObject::getObjectRotation")

#include <Geode/modify/PlayLayer.hpp>

float PlayLayer_opacityForObject_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float PlayLayer_timeForPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float PlayLayer_getCurrentPercent_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool PlayLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PlayLayer)
SCREWYOU3_HOOK(float opacityForObject(GameObject* object))
SCREWYOU3_HOOK_IMPL(PlayLayer, opacityForObject, object)
SCREWYOU3_HOOK(float timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, int id))
SCREWYOU3_HOOK_IMPL(PlayLayer, timeForPos, position, order, channel, songTriggers, id)
SCREWYOU3_HOOK(float getCurrentPercent())
SCREWYOU3_HOOK_IMPL(PlayLayer, getCurrentPercent, )
SCREWYOU3_HOOK(bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects))
SCREWYOU3_HOOK_IMPL(PlayLayer, init, level, useReplay, dontCreateObjects)
SCREWYOU3_HOOK_END("PlayLayer::opacityForObject")

#include <Geode/modify/PriceLabel.hpp>

bool PriceLabel_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PriceLabel)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int price))
SCREWYOU3_HOOK_IMPL(PriceLabel, init, price)
#endif
SCREWYOU3_HOOK_END("PriceLabel::init")

#include <Geode/modify/ProfilePage.hpp>

bool ProfilePage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool ProfilePage_isCorrect_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ProfilePage)
SCREWYOU3_HOOK(bool init(int accountID, bool ownProfile))
SCREWYOU3_HOOK_IMPL(ProfilePage, init, accountID, ownProfile)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(ProfilePage, isCorrect, key)
SCREWYOU3_HOOK_END("ProfilePage::init")

#include <Geode/modify/PromoInterstitial.hpp>

bool PromoInterstitial_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PromoInterstitial_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PromoInterstitial)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(PromoInterstitial, ccTouchBegan, touch, event)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(bool fullVersion))
SCREWYOU3_HOOK_IMPL(PromoInterstitial, init, fullVersion)
#endif
SCREWYOU3_HOOK_END("PromoInterstitial::ccTouchBegan")

#include <Geode/modify/PurchaseItemPopup.hpp>

bool PurchaseItemPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PurchaseItemPopup)
SCREWYOU3_HOOK(bool init(GJStoreItem* item))
SCREWYOU3_HOOK_IMPL(PurchaseItemPopup, init, item)
SCREWYOU3_HOOK_END("PurchaseItemPopup::init")

#include <Geode/modify/RandTriggerGameObject.hpp>

bool RandTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string RandTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(RandTriggerGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(RandTriggerGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(RandTriggerGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("RandTriggerGameObject::init")

#include <Geode/modify/RateDemonLayer.hpp>

bool RateDemonLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(RateDemonLayer)
SCREWYOU3_HOOK(bool init(int levelID))
SCREWYOU3_HOOK_IMPL(RateDemonLayer, init, levelID)
SCREWYOU3_HOOK_END("RateDemonLayer::init")

#include <Geode/modify/RateLevelLayer.hpp>

bool RateLevelLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(RateLevelLayer)
SCREWYOU3_HOOK(bool init(int levelID))
SCREWYOU3_HOOK_IMPL(RateLevelLayer, init, levelID)
SCREWYOU3_HOOK_END("RateLevelLayer::init")

#include <Geode/modify/RateStarsLayer.hpp>

bool RateStarsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(RateStarsLayer)
SCREWYOU3_HOOK(bool init(int levelID, bool platformer, bool moderator))
SCREWYOU3_HOOK_IMPL(RateStarsLayer, init, levelID, platformer, moderator)
SCREWYOU3_HOOK_END("RateStarsLayer::init")

#include <Geode/modify/RewardsPage.hpp>

bool RewardsPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(RewardsPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(RewardsPage, init, )
SCREWYOU3_HOOK_END("RewardsPage::init")

#include <Geode/modify/RewardUnlockLayer.hpp>

bool RewardUnlockLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool RewardUnlockLayer_showCollectReward_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(RewardUnlockLayer)
SCREWYOU3_HOOK(bool init(int type, RewardsPage* page))
SCREWYOU3_HOOK_IMPL(RewardUnlockLayer, init, type, page)
SCREWYOU3_HOOK(bool showCollectReward(GJRewardItem* item))
SCREWYOU3_HOOK_IMPL(RewardUnlockLayer, showCollectReward, item)
SCREWYOU3_HOOK_END("RewardUnlockLayer::init")

#include <Geode/modify/RingObject.hpp>

gd::string RingObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool RingObject_shouldDrawEditorHitbox_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(RingObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(RingObject, getSaveString, layer)
SCREWYOU3_HOOK(bool shouldDrawEditorHitbox())
SCREWYOU3_HOOK_IMPL(RingObject, shouldDrawEditorHitbox, )
SCREWYOU3_HOOK_END("RingObject::getSaveString")

#include <Geode/modify/RotateGameplayGameObject.hpp>

bool RotateGameplayGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string RotateGameplayGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(RotateGameplayGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(RotateGameplayGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(RotateGameplayGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("RotateGameplayGameObject::init")

#include <Geode/modify/ScrollingLayer.hpp>

bool ScrollingLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ScrollingLayer)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(ScrollingLayer, ccTouchBegan, touch, event)
SCREWYOU3_HOOK_END("ScrollingLayer::ccTouchBegan")

#include <Geode/modify/SearchButton.hpp>

bool SearchButton_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SearchButton)
SCREWYOU3_HOOK(bool init(char const* background, char const* label, float scale, char const* icon))
SCREWYOU3_HOOK_IMPL(SearchButton, init, background, label, scale, icon)
SCREWYOU3_HOOK_END("SearchButton::init")

#include <Geode/modify/SearchSFXPopup.hpp>

bool SearchSFXPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SearchSFXPopup)
SCREWYOU3_HOOK(bool init(gd::string query))
SCREWYOU3_HOOK_IMPL(SearchSFXPopup, init, query)
SCREWYOU3_HOOK_END("SearchSFXPopup::init")

#include <Geode/modify/SecretGame01Layer.hpp>

bool SecretGame01Layer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int SecretGame01Layer_getCountForDifficulty_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string SecretGame01Layer_getFrameForDifficulty_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int SecretGame01Layer_getRowsForDifficulty_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int SecretGame01Layer_getTimeForDifficulty_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(SecretGame01Layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretGame01Layer, init, )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getCountForDifficulty(int difficulty))
SCREWYOU3_HOOK_IMPL(SecretGame01Layer, getCountForDifficulty, difficulty)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getFrameForDifficulty(int difficulty))
SCREWYOU3_HOOK_IMPL(SecretGame01Layer, getFrameForDifficulty, difficulty)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getRowsForDifficulty(int difficulty))
SCREWYOU3_HOOK_IMPL(SecretGame01Layer, getRowsForDifficulty, difficulty)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getTimeForDifficulty(int difficulty))
SCREWYOU3_HOOK_IMPL(SecretGame01Layer, getTimeForDifficulty, difficulty)
#endif
SCREWYOU3_HOOK_END("SecretGame01Layer::init")

#include <Geode/modify/SecretLayer.hpp>

bool SecretLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string SecretLayer_getBasicMessage_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string SecretLayer_getMessage_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string SecretLayer_getThreadMessage_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SecretLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer, init, )
SCREWYOU3_HOOK(gd::string getBasicMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer, getBasicMessage, )
SCREWYOU3_HOOK(gd::string getMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer, getMessage, )
SCREWYOU3_HOOK(gd::string getThreadMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer, getThreadMessage, )
SCREWYOU3_HOOK_END("SecretLayer::init")

#include <Geode/modify/SecretLayer2.hpp>

bool SecretLayer2_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string SecretLayer2_getBasicMessage_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string SecretLayer2_getErrorMessage_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string SecretLayer2_getMessage_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string SecretLayer2_getThreadMessage_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SecretLayer2)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer2, init, )
SCREWYOU3_HOOK(gd::string getBasicMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer2, getBasicMessage, )
SCREWYOU3_HOOK(gd::string getErrorMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer2, getErrorMessage, )
SCREWYOU3_HOOK(gd::string getMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer2, getMessage, )
SCREWYOU3_HOOK(gd::string getThreadMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer2, getThreadMessage, )
SCREWYOU3_HOOK_END("SecretLayer2::init")

#include <Geode/modify/SecretLayer3.hpp>

bool SecretLayer3_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SecretLayer3)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer3, init, )
SCREWYOU3_HOOK_END("SecretLayer3::init")

#include <Geode/modify/SecretLayer4.hpp>

bool SecretLayer4_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string SecretLayer4_getBasicMessage_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string SecretLayer4_getErrorMessage_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string SecretLayer4_getMessage_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string SecretLayer4_getThreadMessage_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SecretLayer4)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer4, init, )
SCREWYOU3_HOOK(gd::string getBasicMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer4, getBasicMessage, )
SCREWYOU3_HOOK(gd::string getErrorMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer4, getErrorMessage, )
SCREWYOU3_HOOK(gd::string getMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer4, getMessage, )
SCREWYOU3_HOOK(gd::string getThreadMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer4, getThreadMessage, )
SCREWYOU3_HOOK_END("SecretLayer4::init")

#include <Geode/modify/SecretLayer5.hpp>

bool SecretLayer5_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SecretLayer5)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer5, init, )
SCREWYOU3_HOOK_END("SecretLayer5::init")

#include <Geode/modify/SecretLayer6.hpp>

bool SecretLayer6_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SecretLayer6)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer6, init, )
#endif
SCREWYOU3_HOOK_END("SecretLayer6::init")

#include <Geode/modify/SecretNumberLayer.hpp>

bool SecretNumberLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SecretNumberLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretNumberLayer, init, )
SCREWYOU3_HOOK_END("SecretNumberLayer::init")

#include <Geode/modify/SecretRewardsLayer.hpp>

bool SecretRewardsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SecretRewardsLayer)
SCREWYOU3_HOOK(bool init(bool fromShop))
SCREWYOU3_HOOK_IMPL(SecretRewardsLayer, init, fromShop)
SCREWYOU3_HOOK_END("SecretRewardsLayer::init")

#include <Geode/modify/SelectArtLayer.hpp>

bool SelectArtLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectArtLayer)
SCREWYOU3_HOOK(bool init(SelectArtType type, int index))
SCREWYOU3_HOOK_IMPL(SelectArtLayer, init, type, index)
SCREWYOU3_HOOK_END("SelectArtLayer::init")

#include <Geode/modify/SelectEventLayer.hpp>

bool SelectEventLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectEventLayer)
SCREWYOU3_HOOK(bool init(SetupEventLinkPopup* popup, gd::set<int>& eventIDs))
SCREWYOU3_HOOK_IMPL(SelectEventLayer, init, popup, eventIDs)
SCREWYOU3_HOOK_END("SelectEventLayer::init")

#include <Geode/modify/SelectFontLayer.hpp>

bool SelectFontLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectFontLayer)
SCREWYOU3_HOOK(bool init(LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(SelectFontLayer, init, layer)
SCREWYOU3_HOOK_END("SelectFontLayer::init")

#include <Geode/modify/SelectListIconLayer.hpp>

bool SelectListIconLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectListIconLayer)
SCREWYOU3_HOOK(bool init(int difficulty))
SCREWYOU3_HOOK_IMPL(SelectListIconLayer, init, difficulty)
SCREWYOU3_HOOK_END("SelectListIconLayer::init")

#include <Geode/modify/SelectPremadeLayer.hpp>

bool SelectPremadeLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectPremadeLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SelectPremadeLayer, init, )
SCREWYOU3_HOOK_END("SelectPremadeLayer::init")

#include <Geode/modify/SelectSettingLayer.hpp>

gd::string SelectSettingLayer_frameForItem_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool SelectSettingLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectSettingLayer)
SCREWYOU3_HOOK(static gd::string frameForItem(SelectSettingType type, int index))
SCREWYOU3_HOOK_IMPL(SelectSettingLayer, frameForItem, type, index)
SCREWYOU3_HOOK(bool init(SelectSettingType type, int value))
SCREWYOU3_HOOK_IMPL(SelectSettingLayer, init, type, value)
SCREWYOU3_HOOK_END("SelectSettingLayer::frameForItem")

#include <Geode/modify/SelectSFXSortLayer.hpp>

bool SelectSFXSortLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectSFXSortLayer)
SCREWYOU3_HOOK(bool init(AudioSortType sortType))
SCREWYOU3_HOOK_IMPL(SelectSFXSortLayer, init, sortType)
SCREWYOU3_HOOK_END("SelectSFXSortLayer::init")

#include <Geode/modify/SequenceTriggerGameObject.hpp>

bool SequenceTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string SequenceTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SequenceTriggerGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SequenceTriggerGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SequenceTriggerGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("SequenceTriggerGameObject::init")

#include <Geode/modify/SetColorIDPopup.hpp>

bool SetColorIDPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetColorIDPopup)
SCREWYOU3_HOOK(bool init(int id))
SCREWYOU3_HOOK_IMPL(SetColorIDPopup, init, id)
SCREWYOU3_HOOK_END("SetColorIDPopup::init")

#include <Geode/modify/SetFolderPopup.hpp>

bool SetFolderPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetFolderPopup)
SCREWYOU3_HOOK(bool init(int value, bool isCreated, gd::string title))
SCREWYOU3_HOOK_IMPL(SetFolderPopup, init, value, isCreated, title)
SCREWYOU3_HOOK_END("SetFolderPopup::init")

#include <Geode/modify/SetGroupIDLayer.hpp>

bool SetGroupIDLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetGroupIDLayer)
SCREWYOU3_HOOK(bool init(GameObject* obj, cocos2d::CCArray* objs))
SCREWYOU3_HOOK_IMPL(SetGroupIDLayer, init, obj, objs)
SCREWYOU3_HOOK_END("SetGroupIDLayer::init")

#include <Geode/modify/SetIDPopup.hpp>

bool SetIDPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetIDPopup)
SCREWYOU3_HOOK(bool init(int current, int begin, int end, gd::string title, gd::string button, bool resetButton, int defaultValue, float offset, bool numberInput, bool arrows))
SCREWYOU3_HOOK_IMPL(SetIDPopup, init, current, begin, end, title, button, resetButton, defaultValue, offset, numberInput, arrows)
SCREWYOU3_HOOK_END("SetIDPopup::init")

#include <Geode/modify/SetItemIDLayer.hpp>

bool SetItemIDLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetItemIDLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetItemIDLayer, init, object, objects)
SCREWYOU3_HOOK_END("SetItemIDLayer::init")

#include <Geode/modify/SetLevelOrderPopup.hpp>

bool SetLevelOrderPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetLevelOrderPopup)
SCREWYOU3_HOOK(bool init(int levelID, int order, int amount))
SCREWYOU3_HOOK_IMPL(SetLevelOrderPopup, init, levelID, order, amount)
SCREWYOU3_HOOK_END("SetLevelOrderPopup::init")

#include <Geode/modify/SetTargetIDLayer.hpp>

bool SetTargetIDLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetTargetIDLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, gd::string title, gd::string label, int minimum, int maximum, int objectID))
SCREWYOU3_HOOK_IMPL(SetTargetIDLayer, init, object, objects, title, label, minimum, maximum, objectID)
SCREWYOU3_HOOK_END("SetTargetIDLayer::init")

#include <Geode/modify/SetTextPopup.hpp>

bool SetTextPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetTextPopup)
SCREWYOU3_HOOK(bool init(gd::string value, gd::string placeholder, int maxLength, gd::string title, gd::string okBtnText, bool showResetBtn, float offset))
SCREWYOU3_HOOK_IMPL(SetTextPopup, init, value, placeholder, maxLength, title, okBtnText, showResetBtn, offset)
SCREWYOU3_HOOK_END("SetTextPopup::init")

#include <Geode/modify/SetupAdvFollowEditPhysicsPopup.hpp>

bool SetupAdvFollowEditPhysicsPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAdvFollowEditPhysicsPopup)
SCREWYOU3_HOOK(bool init(AdvancedFollowEditObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAdvFollowEditPhysicsPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAdvFollowEditPhysicsPopup::init")

#include <Geode/modify/SetupAdvFollowPopup.hpp>

bool SetupAdvFollowPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAdvFollowPopup)
SCREWYOU3_HOOK(bool init(AdvancedFollowTriggerObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAdvFollowPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAdvFollowPopup::init")

#include <Geode/modify/SetupAdvFollowRetargetPopup.hpp>

bool SetupAdvFollowRetargetPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAdvFollowRetargetPopup)
SCREWYOU3_HOOK(bool init(AdvancedFollowEditObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAdvFollowRetargetPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAdvFollowRetargetPopup::init")

#include <Geode/modify/SetupAnimationPopup.hpp>

bool SetupAnimationPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAnimationPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAnimationPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAnimationPopup::init")

#include <Geode/modify/SetupAnimSettingsPopup.hpp>

bool SetupAnimSettingsPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAnimSettingsPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAnimSettingsPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAnimSettingsPopup::init")

#include <Geode/modify/SetupAreaAnimTriggerPopup.hpp>

bool SetupAreaAnimTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaAnimTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupAreaAnimTriggerPopup, init, object, objects, id)
SCREWYOU3_HOOK_END("SetupAreaAnimTriggerPopup::init")

#include <Geode/modify/SetupAreaFadeTriggerPopup.hpp>

bool SetupAreaFadeTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaFadeTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaFadeTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAreaFadeTriggerPopup::init")

#include <Geode/modify/SetupAreaMoveTriggerPopup.hpp>

float SetupAreaMoveTriggerPopup_triggerValueFromSliderValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupAreaMoveTriggerPopup_triggerSliderValueFromValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SetupAreaMoveTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaMoveTriggerPopup)
SCREWYOU3_HOOK(float triggerValueFromSliderValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupAreaMoveTriggerPopup, triggerValueFromSliderValue, tag, value)
SCREWYOU3_HOOK(float triggerSliderValueFromValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupAreaMoveTriggerPopup, triggerSliderValueFromValue, tag, value)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaMoveTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAreaMoveTriggerPopup::triggerValueFromSliderValue")

#include <Geode/modify/SetupAreaRotateTriggerPopup.hpp>

bool SetupAreaRotateTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaRotateTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaRotateTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAreaRotateTriggerPopup::init")

#include <Geode/modify/SetupAreaTintTriggerPopup.hpp>

bool SetupAreaTintTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaTintTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaTintTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAreaTintTriggerPopup::init")

#include <Geode/modify/SetupAreaTransformTriggerPopup.hpp>

bool SetupAreaTransformTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaTransformTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaTransformTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAreaTransformTriggerPopup::init")

#include <Geode/modify/SetupAreaTriggerPopup.hpp>

bool SetupAreaTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAreaTriggerPopup::init")

#include <Geode/modify/SetupArtSwitchPopup.hpp>

bool SetupArtSwitchPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupArtSwitchPopup)
SCREWYOU3_HOOK(bool init(ArtTriggerGameObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupArtSwitchPopup, init, object, objects, id)
SCREWYOU3_HOOK_END("SetupArtSwitchPopup::init")

#include <Geode/modify/SetupAudioLineGuidePopup.hpp>

bool SetupAudioLineGuidePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAudioLineGuidePopup)
SCREWYOU3_HOOK(bool init(AudioLineGuideGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAudioLineGuidePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAudioLineGuidePopup::init")

#include <Geode/modify/SetupBGSpeedTrigger.hpp>

bool SetupBGSpeedTrigger_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupBGSpeedTrigger)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupBGSpeedTrigger, init, object, objects, id)
SCREWYOU3_HOOK_END("SetupBGSpeedTrigger::init")

#include <Geode/modify/SetupCameraEdgePopup.hpp>

bool SetupCameraEdgePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCameraEdgePopup)
SCREWYOU3_HOOK(bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraEdgePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCameraEdgePopup::init")

#include <Geode/modify/SetupCameraGuidePopup.hpp>

bool SetupCameraGuidePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCameraGuidePopup)
SCREWYOU3_HOOK(bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraGuidePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCameraGuidePopup::init")

#include <Geode/modify/SetupCameraModePopup.hpp>

bool SetupCameraModePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCameraModePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraModePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCameraModePopup::init")

#include <Geode/modify/SetupCameraOffsetTrigger.hpp>

bool SetupCameraOffsetTrigger_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCameraOffsetTrigger)
SCREWYOU3_HOOK(bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraOffsetTrigger, init, object, objects)
SCREWYOU3_HOOK_END("SetupCameraOffsetTrigger::init")

#include <Geode/modify/SetupCameraRotatePopup.hpp>

bool SetupCameraRotatePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCameraRotatePopup)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraRotatePopup, init, object, objects)
#endif
SCREWYOU3_HOOK_END("SetupCameraRotatePopup::init")

#include <Geode/modify/SetupCameraRotatePopup2.hpp>

bool SetupCameraRotatePopup2_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCameraRotatePopup2)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraRotatePopup2, init, object, objects)
SCREWYOU3_HOOK_END("SetupCameraRotatePopup2::init")

#include <Geode/modify/SetupCheckpointPopup.hpp>

bool SetupCheckpointPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCheckpointPopup)
SCREWYOU3_HOOK(bool init(CheckpointGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCheckpointPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCheckpointPopup::init")

#include <Geode/modify/SetupCoinLayer.hpp>

bool SetupCoinLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCoinLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCoinLayer, init, object, objects)
SCREWYOU3_HOOK_END("SetupCoinLayer::init")

#include <Geode/modify/SetupCollisionStateTriggerPopup.hpp>

bool SetupCollisionStateTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCollisionStateTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCollisionStateTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCollisionStateTriggerPopup::init")

#include <Geode/modify/SetupCollisionTriggerPopup.hpp>

bool SetupCollisionTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCollisionTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCollisionTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCollisionTriggerPopup::init")

#include <Geode/modify/SetupCountTriggerPopup.hpp>

bool SetupCountTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCountTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCountTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCountTriggerPopup::init")

#include <Geode/modify/SetupDashRingPopup.hpp>

bool SetupDashRingPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupDashRingPopup)
SCREWYOU3_HOOK(bool init(DashRingObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupDashRingPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupDashRingPopup::init")

#include <Geode/modify/SetupEndPopup.hpp>

bool SetupEndPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupEndPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupEndPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupEndPopup::init")

#include <Geode/modify/SetupEnterEffectPopup.hpp>

float SetupEnterEffectPopup_triggerValueFromSliderValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupEnterEffectPopup_triggerSliderValueFromValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SetupEnterEffectPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupEnterEffectPopup)
SCREWYOU3_HOOK(float triggerValueFromSliderValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupEnterEffectPopup, triggerValueFromSliderValue, tag, value)
SCREWYOU3_HOOK(float triggerSliderValueFromValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupEnterEffectPopup, triggerSliderValueFromValue, tag, value)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupEnterEffectPopup, init, object, objects, id)
SCREWYOU3_HOOK_END("SetupEnterEffectPopup::triggerValueFromSliderValue")

#include <Geode/modify/SetupEnterTriggerPopup.hpp>

bool SetupEnterTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupEnterTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupEnterTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupEnterTriggerPopup::init")

#include <Geode/modify/SetupEventLinkPopup.hpp>

bool SetupEventLinkPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupEventLinkPopup)
SCREWYOU3_HOOK(bool init(EventLinkTrigger* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupEventLinkPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupEventLinkPopup::init")

#include <Geode/modify/SetupForceBlockPopup.hpp>

bool SetupForceBlockPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupForceBlockPopup)
SCREWYOU3_HOOK(bool init(ForceBlockGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupForceBlockPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupForceBlockPopup::init")

#include <Geode/modify/SetupGameplayOffsetPopup.hpp>

float SetupGameplayOffsetPopup_triggerValueFromSliderValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupGameplayOffsetPopup_triggerSliderValueFromValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SetupGameplayOffsetPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupGameplayOffsetPopup)
SCREWYOU3_HOOK(float triggerValueFromSliderValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupGameplayOffsetPopup, triggerValueFromSliderValue, tag, value)
SCREWYOU3_HOOK(float triggerSliderValueFromValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupGameplayOffsetPopup, triggerSliderValueFromValue, tag, value)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupGameplayOffsetPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupGameplayOffsetPopup::triggerValueFromSliderValue")

#include <Geode/modify/SetupGradientPopup.hpp>

bool SetupGradientPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupGradientPopup)
SCREWYOU3_HOOK(bool init(GradientTriggerObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupGradientPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupGradientPopup::init")

#include <Geode/modify/SetupGravityModPopup.hpp>

bool SetupGravityModPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupGravityModPopup)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, bool gravityTrigger))
SCREWYOU3_HOOK_IMPL(SetupGravityModPopup, init, object, objects, gravityTrigger)
#endif
SCREWYOU3_HOOK_END("SetupGravityModPopup::init")

#include <Geode/modify/SetupGravityTriggerPopup.hpp>

bool SetupGravityTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupGravityTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupGravityTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupGravityTriggerPopup::init")

#include <Geode/modify/SetupInstantCollisionTriggerPopup.hpp>

bool SetupInstantCollisionTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupInstantCollisionTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupInstantCollisionTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupInstantCollisionTriggerPopup::init")

#include <Geode/modify/SetupInstantCountPopup.hpp>

bool SetupInstantCountPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupInstantCountPopup)
SCREWYOU3_HOOK(bool init(CountTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupInstantCountPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupInstantCountPopup::init")

#include <Geode/modify/SetupInteractObjectPopup.hpp>

bool SetupInteractObjectPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupInteractObjectPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupInteractObjectPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupInteractObjectPopup::init")

#include <Geode/modify/SetupItemCompareTriggerPopup.hpp>

bool SetupItemCompareTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupItemCompareTriggerPopup)
SCREWYOU3_HOOK(bool init(ItemTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupItemCompareTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupItemCompareTriggerPopup::init")

#include <Geode/modify/SetupItemEditTriggerPopup.hpp>

bool SetupItemEditTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupItemEditTriggerPopup)
SCREWYOU3_HOOK(bool init(ItemTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupItemEditTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupItemEditTriggerPopup::init")

#include <Geode/modify/SetupKeyframeAnimPopup.hpp>

bool SetupKeyframeAnimPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupKeyframeAnimPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupKeyframeAnimPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupKeyframeAnimPopup::init")

#include <Geode/modify/SetupKeyframePopup.hpp>

bool SetupKeyframePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupKeyframePopup)
SCREWYOU3_HOOK(bool init(KeyframeGameObject* object, cocos2d::CCArray* objects, LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(SetupKeyframePopup, init, object, objects, layer)
SCREWYOU3_HOOK_END("SetupKeyframePopup::init")

#include <Geode/modify/SetupMGTrigger.hpp>

bool SetupMGTrigger_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupMGTrigger)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupMGTrigger, init, object, objects)
SCREWYOU3_HOOK_END("SetupMGTrigger::init")

#include <Geode/modify/SetupMoveCommandPopup.hpp>

float SetupMoveCommandPopup_triggerValueFromSliderValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupMoveCommandPopup_triggerSliderValueFromValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SetupMoveCommandPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupMoveCommandPopup)
SCREWYOU3_HOOK(float triggerValueFromSliderValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupMoveCommandPopup, triggerValueFromSliderValue, tag, value)
SCREWYOU3_HOOK(float triggerSliderValueFromValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupMoveCommandPopup, triggerSliderValueFromValue, tag, value)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupMoveCommandPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupMoveCommandPopup::triggerValueFromSliderValue")

#include <Geode/modify/SetupObjectControlPopup.hpp>

bool SetupObjectControlPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupObjectControlPopup)
SCREWYOU3_HOOK(bool init(ObjectControlGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupObjectControlPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupObjectControlPopup::init")

#include <Geode/modify/SetupObjectOptions2Popup.hpp>

bool SetupObjectOptions2Popup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupObjectOptions2Popup)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupObjectOptions2Popup, init, object, objects)
SCREWYOU3_HOOK_END("SetupObjectOptions2Popup::init")

#include <Geode/modify/SetupObjectOptionsPopup.hpp>

bool SetupObjectOptionsPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupObjectOptionsPopup)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects, SetGroupIDLayer* layer))
SCREWYOU3_HOOK_IMPL(SetupObjectOptionsPopup, init, object, objects, layer)
SCREWYOU3_HOOK_END("SetupObjectOptionsPopup::init")

#include <Geode/modify/SetupObjectTogglePopup.hpp>

bool SetupObjectTogglePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupObjectTogglePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, bool platformer))
SCREWYOU3_HOOK_IMPL(SetupObjectTogglePopup, init, object, objects, platformer)
SCREWYOU3_HOOK_END("SetupObjectTogglePopup::init")

#include <Geode/modify/SetupOpacityPopup.hpp>

bool SetupOpacityPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupOpacityPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupOpacityPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupOpacityPopup::init")

#include <Geode/modify/SetupOptionsTriggerPopup.hpp>

bool SetupOptionsTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupOptionsTriggerPopup)
SCREWYOU3_HOOK(bool init(GameOptionsTrigger* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupOptionsTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupOptionsTriggerPopup::init")

#include <Geode/modify/SetupPersistentItemTriggerPopup.hpp>

bool SetupPersistentItemTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupPersistentItemTriggerPopup)
SCREWYOU3_HOOK(bool init(ItemTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPersistentItemTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupPersistentItemTriggerPopup::init")

#include <Geode/modify/SetupPickupTriggerPopup.hpp>

bool SetupPickupTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupPickupTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPickupTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupPickupTriggerPopup::init")

#include <Geode/modify/SetupPlatformerEndPopup.hpp>

bool SetupPlatformerEndPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupPlatformerEndPopup)
SCREWYOU3_HOOK(bool init(EndTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPlatformerEndPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupPlatformerEndPopup::init")

#include <Geode/modify/SetupPlayerControlPopup.hpp>

bool SetupPlayerControlPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupPlayerControlPopup)
SCREWYOU3_HOOK(bool init(PlayerControlGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPlayerControlPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupPlayerControlPopup::init")

#include <Geode/modify/SetupPortalPopup.hpp>

bool SetupPortalPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupPortalPopup)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPortalPopup, init, object, objects)
#endif
SCREWYOU3_HOOK_END("SetupPortalPopup::init")

#include <Geode/modify/SetupPulsePopup.hpp>

bool SetupPulsePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupPulsePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPulsePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupPulsePopup::init")

#include <Geode/modify/SetupRandAdvTriggerPopup.hpp>

bool SetupRandAdvTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupRandAdvTriggerPopup)
SCREWYOU3_HOOK(bool init(RandTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRandAdvTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupRandAdvTriggerPopup::init")

#include <Geode/modify/SetupRandTriggerPopup.hpp>

bool SetupRandTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupRandTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRandTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupRandTriggerPopup::init")

#include <Geode/modify/SetupResetTriggerPopup.hpp>

bool SetupResetTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupResetTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupResetTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupResetTriggerPopup::init")

#include <Geode/modify/SetupReverbPopup.hpp>

bool SetupReverbPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupReverbPopup)
SCREWYOU3_HOOK(bool init(SFXTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupReverbPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupReverbPopup::init")

#include <Geode/modify/SetupRotateCommandPopup.hpp>

float SetupRotateCommandPopup_triggerValueFromSliderValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupRotateCommandPopup_triggerSliderValueFromValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SetupRotateCommandPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupRotateCommandPopup)
SCREWYOU3_HOOK(float triggerValueFromSliderValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupRotateCommandPopup, triggerValueFromSliderValue, tag, value)
SCREWYOU3_HOOK(float triggerSliderValueFromValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupRotateCommandPopup, triggerSliderValueFromValue, tag, value)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRotateCommandPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupRotateCommandPopup::triggerValueFromSliderValue")

#include <Geode/modify/SetupRotateGameplayPopup.hpp>

bool SetupRotateGameplayPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupRotateGameplayPopup)
SCREWYOU3_HOOK(bool init(RotateGameplayGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRotateGameplayPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupRotateGameplayPopup::init")

#include <Geode/modify/SetupRotatePopup.hpp>

bool SetupRotatePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupRotatePopup)
SCREWYOU3_HOOK(bool init(EnhancedGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRotatePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupRotatePopup::init")

#include <Geode/modify/SetupSequenceTriggerPopup.hpp>

bool SetupSequenceTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSequenceTriggerPopup)
SCREWYOU3_HOOK(bool init(SequenceTriggerGameObject* object))
SCREWYOU3_HOOK_IMPL(SetupSequenceTriggerPopup, init, object)
SCREWYOU3_HOOK_END("SetupSequenceTriggerPopup::init")

#include <Geode/modify/SetupSFXEditPopup.hpp>

bool SetupSFXEditPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSFXEditPopup)
SCREWYOU3_HOOK(bool init(SFXTriggerGameObject* object, cocos2d::CCArray* objects, bool songTrigger))
SCREWYOU3_HOOK_IMPL(SetupSFXEditPopup, init, object, objects, songTrigger)
SCREWYOU3_HOOK_END("SetupSFXEditPopup::init")

#include <Geode/modify/SetupSFXPopup.hpp>

int SetupSFXPopup_getActiveSFXID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SetupSFXPopup_overridePlaySFX_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool SetupSFXPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSFXPopup)
SCREWYOU3_HOOK(int getActiveSFXID())
SCREWYOU3_HOOK_IMPL(SetupSFXPopup, getActiveSFXID, )
SCREWYOU3_HOOK(bool overridePlaySFX(SFXInfoObject* object))
SCREWYOU3_HOOK_IMPL(SetupSFXPopup, overridePlaySFX, object)
SCREWYOU3_HOOK(bool init(SFXTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSFXPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupSFXPopup::getActiveSFXID")

#include <Geode/modify/SetupShaderEffectPopup.hpp>

bool SetupShaderEffectPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string SetupShaderEffectPopup_zLayerToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SetupShaderEffectPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupShaderEffectPopup, init, object, objects, id)
SCREWYOU3_HOOK(gd::string zLayerToString(int zLayer))
SCREWYOU3_HOOK_IMPL(SetupShaderEffectPopup, zLayerToString, zLayer)
SCREWYOU3_HOOK_END("SetupShaderEffectPopup::init")

#include <Geode/modify/SetupShakePopup.hpp>

bool SetupShakePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupShakePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupShakePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupShakePopup::init")

#include <Geode/modify/SetupSmartBlockLayer.hpp>

bool SetupSmartBlockLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSmartBlockLayer)
SCREWYOU3_HOOK(bool init(SmartGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSmartBlockLayer, init, object, objects)
SCREWYOU3_HOOK_END("SetupSmartBlockLayer::init")

#include <Geode/modify/SetupSmartTemplateLayer.hpp>

bool SetupSmartTemplateLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSmartTemplateLayer)
SCREWYOU3_HOOK(bool init(GJSmartTemplate* smartTemplate))
SCREWYOU3_HOOK_IMPL(SetupSmartTemplateLayer, init, smartTemplate)
SCREWYOU3_HOOK_END("SetupSmartTemplateLayer::init")

#include <Geode/modify/SetupSongTriggerPopup.hpp>

bool SetupSongTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSongTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSongTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupSongTriggerPopup::init")

#include <Geode/modify/SetupSpawnParticlePopup.hpp>

bool SetupSpawnParticlePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSpawnParticlePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSpawnParticlePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupSpawnParticlePopup::init")

#include <Geode/modify/SetupSpawnPopup.hpp>

bool SetupSpawnPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSpawnPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSpawnPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupSpawnPopup::init")

#include <Geode/modify/SetupStaticCameraPopup.hpp>

bool SetupStaticCameraPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupStaticCameraPopup)
SCREWYOU3_HOOK(bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupStaticCameraPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupStaticCameraPopup::init")

#include <Geode/modify/SetupStopTriggerPopup.hpp>

bool SetupStopTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupStopTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupStopTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupStopTriggerPopup::init")

#include <Geode/modify/SetupTeleportPopup.hpp>

bool SetupTeleportPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTeleportPopup)
SCREWYOU3_HOOK(bool init(TeleportPortalObject* object, cocos2d::CCArray* objects, int id, bool platformer))
SCREWYOU3_HOOK_IMPL(SetupTeleportPopup, init, object, objects, id, platformer)
SCREWYOU3_HOOK_END("SetupTeleportPopup::init")

#include <Geode/modify/SetupTimerControlTriggerPopup.hpp>

bool SetupTimerControlTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTimerControlTriggerPopup)
SCREWYOU3_HOOK(bool init(TimerTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTimerControlTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupTimerControlTriggerPopup::init")

#include <Geode/modify/SetupTimerEventTriggerPopup.hpp>

bool SetupTimerEventTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTimerEventTriggerPopup)
SCREWYOU3_HOOK(bool init(TimerTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTimerEventTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupTimerEventTriggerPopup::init")

#include <Geode/modify/SetupTimerTriggerPopup.hpp>

bool SetupTimerTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTimerTriggerPopup)
SCREWYOU3_HOOK(bool init(TimerTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTimerTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupTimerTriggerPopup::init")

#include <Geode/modify/SetupTimeWarpPopup.hpp>

bool SetupTimeWarpPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTimeWarpPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTimeWarpPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupTimeWarpPopup::init")

#include <Geode/modify/SetupTouchTogglePopup.hpp>

bool SetupTouchTogglePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTouchTogglePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTouchTogglePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupTouchTogglePopup::init")

#include <Geode/modify/SetupTransformPopup.hpp>

bool SetupTransformPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTransformPopup)
SCREWYOU3_HOOK(bool init(TransformTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTransformPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupTransformPopup::init")

#include <Geode/modify/SetupTriggerPopup.hpp>

bool SetupTriggerPopup_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float SetupTriggerPopup_getValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupTriggerPopup_triggerValueFromSliderValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupTriggerPopup_triggerSliderValueFromValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupTriggerPopup_getTriggerValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SetupTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTriggerPopup)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(float getValue(int tag))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, getValue, tag)
SCREWYOU3_HOOK(float triggerValueFromSliderValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, triggerValueFromSliderValue, tag, value)
SCREWYOU3_HOOK(float triggerSliderValueFromValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, triggerSliderValueFromValue, tag, value)
SCREWYOU3_HOOK(float getTriggerValue(int property, GameObject* object))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, getTriggerValue, property, object)
SCREWYOU3_HOOK(bool init(EffectGameObject* trigger, cocos2d::CCArray* triggers, float width, float height, int background))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, init, trigger, triggers, width, height, background)
SCREWYOU3_HOOK_END("SetupTriggerPopup::ccTouchBegan")

#include <Geode/modify/SetupZoomTriggerPopup.hpp>

bool SetupZoomTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupZoomTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupZoomTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupZoomTriggerPopup::init")

#include <Geode/modify/SFXBrowser.hpp>

bool SFXBrowser_cellPerformedAction_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int SFXBrowser_getSelectedCellIdx_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SFXBrowser_shouldSnapToSelected_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool SFXBrowser_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SFXBrowser)
SCREWYOU3_HOOK(bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(SFXBrowser, cellPerformedAction, cell, listType, action, parent)
SCREWYOU3_HOOK(int getSelectedCellIdx())
SCREWYOU3_HOOK_IMPL(SFXBrowser, getSelectedCellIdx, )
SCREWYOU3_HOOK(bool shouldSnapToSelected())
SCREWYOU3_HOOK_IMPL(SFXBrowser, shouldSnapToSelected, )
SCREWYOU3_HOOK(bool init(int id))
SCREWYOU3_HOOK_IMPL(SFXBrowser, init, id)
SCREWYOU3_HOOK_END("SFXBrowser::cellPerformedAction")

#include <Geode/modify/SFXSearchResult.hpp>

int SFXSearchResult_getSelectedPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(SFXSearchResult)
SCREWYOU3_HOOK(int getSelectedPage(int id, int count))
SCREWYOU3_HOOK_IMPL(SFXSearchResult, getSelectedPage, id, count)
SCREWYOU3_HOOK_END("SFXSearchResult::getSelectedPage")

#include <Geode/modify/SFXTriggerGameObject.hpp>

gd::string SFXTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SFXTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SFXTriggerGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("SFXTriggerGameObject::getSaveString")

#include <Geode/modify/ShaderGameObject.hpp>

gd::string ShaderGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(ShaderGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(ShaderGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("ShaderGameObject::getSaveString")

#include <Geode/modify/ShaderLayer.hpp>

bool ShaderLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool ShaderLayer_resetAllShaders_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool ShaderLayer_updateZLayer_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ShaderLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ShaderLayer, init, )
SCREWYOU3_HOOK(bool resetAllShaders())
SCREWYOU3_HOOK_IMPL(ShaderLayer, resetAllShaders, )
SCREWYOU3_HOOK(bool updateZLayer(int minLayer, int maxLayer, bool noParticles))
SCREWYOU3_HOOK_IMPL(ShaderLayer, updateZLayer, minLayer, maxLayer, noParticles)
SCREWYOU3_HOOK_END("ShaderLayer::init")

#include <Geode/modify/ShardsPage.hpp>

bool ShardsPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ShardsPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ShardsPage, init, )
SCREWYOU3_HOOK_END("ShardsPage::init")

#include <Geode/modify/ShareCommentLayer.hpp>

bool ShareCommentLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ShareCommentLayer)
SCREWYOU3_HOOK(bool init(gd::string title, int charLimit, CommentType type, int ID, gd::string desc))
SCREWYOU3_HOOK_IMPL(ShareCommentLayer, init, title, charLimit, type, ID, desc)
SCREWYOU3_HOOK_END("ShareCommentLayer::init")

#include <Geode/modify/ShareLevelLayer.hpp>

bool ShareLevelLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ShareLevelLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(ShareLevelLayer, init, level)
SCREWYOU3_HOOK_END("ShareLevelLayer::init")

#include <Geode/modify/ShareLevelSettingsLayer.hpp>

bool ShareLevelSettingsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ShareLevelSettingsLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(ShareLevelSettingsLayer, init, level)
SCREWYOU3_HOOK_END("ShareLevelSettingsLayer::init")

#include <Geode/modify/ShareListLayer.hpp>

bool ShareListLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ShareListLayer)
SCREWYOU3_HOOK(bool init(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(ShareListLayer, init, list)
SCREWYOU3_HOOK_END("ShareListLayer::init")

#include <Geode/modify/SimplePlayer.hpp>

bool SimplePlayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SimplePlayer)
SCREWYOU3_HOOK(bool init(int id))
SCREWYOU3_HOOK_IMPL(SimplePlayer, init, id)
SCREWYOU3_HOOK_END("SimplePlayer::init")

#include <Geode/modify/SlideInLayer.hpp>

bool SlideInLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool SlideInLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SlideInLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SlideInLayer, init, )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(SlideInLayer, ccTouchBegan, touch, event)
#endif
SCREWYOU3_HOOK_END("SlideInLayer::init")

#include <Geode/modify/Slider.hpp>

bool Slider_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool Slider_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(Slider)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(Slider, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler, char const* bar, char const* groove, char const* thumb, char const* thumbSel, float scale))
SCREWYOU3_HOOK_IMPL(Slider, init, target, handler, bar, groove, thumb, thumbSel, scale)
SCREWYOU3_HOOK_END("Slider::ccTouchBegan")

#include <Geode/modify/SliderThumb.hpp>

float SliderThumb_getValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(SliderThumb)
SCREWYOU3_HOOK(float getValue())
SCREWYOU3_HOOK_IMPL(SliderThumb, getValue, )
SCREWYOU3_HOOK_END("SliderThumb::getValue")

#include <Geode/modify/SliderTouchLogic.hpp>

bool SliderTouchLogic_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SliderTouchLogic)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(SliderTouchLogic, ccTouchBegan, touch, event)
SCREWYOU3_HOOK_END("SliderTouchLogic::ccTouchBegan")

#include <Geode/modify/SmartGameObject.hpp>

gd::string SmartGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SmartGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SmartGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("SmartGameObject::getSaveString")

#include <Geode/modify/SmartTemplateCell.hpp>

bool SmartTemplateCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SmartTemplateCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SmartTemplateCell, init, )
SCREWYOU3_HOOK_END("SmartTemplateCell::init")

#include <Geode/modify/SongCell.hpp>

bool SongCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SongCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SongCell, init, )
SCREWYOU3_HOOK_END("SongCell::init")

#include <Geode/modify/SongInfoLayer.hpp>

bool SongInfoLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SongInfoLayer)
SCREWYOU3_HOOK(bool init(gd::string songName, gd::string artistName, gd::string songURL, gd::string newgroundsURL, gd::string youtubeURL, gd::string facebookURL, int songID, gd::string songTags, int nongType))
SCREWYOU3_HOOK_IMPL(SongInfoLayer, init, songName, artistName, songURL, newgroundsURL, youtubeURL, facebookURL, songID, songTags, nongType)
SCREWYOU3_HOOK_END("SongInfoLayer::init")

#include <Geode/modify/SongInfoObject.hpp>

gd::string SongInfoObject_getArtistNames_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string SongInfoObject_getTagsString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool SongInfoObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SongInfoObject)
SCREWYOU3_HOOK(gd::string getArtistNames(int unused))
SCREWYOU3_HOOK_IMPL(SongInfoObject, getArtistNames, unused)
SCREWYOU3_HOOK(gd::string getTagsString(bool shortTags))
SCREWYOU3_HOOK_IMPL(SongInfoObject, getTagsString, shortTags)
SCREWYOU3_HOOK(bool init(int songID, gd::string songName, gd::string artistName, int artistID, float filesize, gd::string youtubeVideo, gd::string youtubeChannel, gd::string url, int nongType, gd::string extraArtistIDs, bool isNew, int libraryOrder, int priority))
SCREWYOU3_HOOK_IMPL(SongInfoObject, init, songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, nongType, extraArtistIDs, isNew, libraryOrder, priority)
SCREWYOU3_HOOK_END("SongInfoObject::getArtistNames")

#include <Geode/modify/SongOptionsLayer.hpp>

bool SongOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SongOptionsLayer)
SCREWYOU3_HOOK(bool init(CustomSongDelegate* delegate))
SCREWYOU3_HOOK_IMPL(SongOptionsLayer, init, delegate)
SCREWYOU3_HOOK_END("SongOptionsLayer::init")

#include <Geode/modify/SongSelectNode.hpp>

int SongSelectNode_getActiveSongID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string SongSelectNode_getSongFileName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool SongSelectNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SongSelectNode)
SCREWYOU3_HOOK(int getActiveSongID())
SCREWYOU3_HOOK_IMPL(SongSelectNode, getActiveSongID, )
SCREWYOU3_HOOK(gd::string getSongFileName())
SCREWYOU3_HOOK_IMPL(SongSelectNode, getSongFileName, )
SCREWYOU3_HOOK(bool init(int id, bool customSong, LevelSettingsObject* settings, SongSelectType selectType, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCMenu* menu, bool noLabel))
SCREWYOU3_HOOK_IMPL(SongSelectNode, init, id, customSong, settings, selectType, position, parent, menu, noLabel)
SCREWYOU3_HOOK_END("SongSelectNode::getActiveSongID")

#include <Geode/modify/SongTriggerGameObject.hpp>

gd::string SongTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SongTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SongTriggerGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("SongTriggerGameObject::getSaveString")

#include <Geode/modify/SpawnParticleGameObject.hpp>

bool SpawnParticleGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string SpawnParticleGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SpawnParticleGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SpawnParticleGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SpawnParticleGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("SpawnParticleGameObject::init")

#include <Geode/modify/SpawnTriggerGameObject.hpp>

bool SpawnTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string SpawnTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SpawnTriggerGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SpawnTriggerGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SpawnTriggerGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("SpawnTriggerGameObject::init")

#include <Geode/modify/SpecialAnimGameObject.hpp>

gd::string SpecialAnimGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SpecialAnimGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SpecialAnimGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("SpecialAnimGameObject::getSaveString")

#include <Geode/modify/SpriteAnimationManager.hpp>

int SpriteAnimationManager_getPrio_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SpriteAnimationManager_initWithOwner_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SpriteAnimationManager)
SCREWYOU3_HOOK(int getPrio(gd::string animation))
SCREWYOU3_HOOK_IMPL(SpriteAnimationManager, getPrio, animation)
SCREWYOU3_HOOK(bool initWithOwner(CCAnimatedSprite* sprite, gd::string definition))
SCREWYOU3_HOOK_IMPL(SpriteAnimationManager, initWithOwner, sprite, definition)
SCREWYOU3_HOOK_END("SpriteAnimationManager::getPrio")

#include <Geode/modify/SpriteDescription.hpp>

bool SpriteDescription_initDescription_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SpriteDescription)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool initDescription(DS_Dictionary* dict))
SCREWYOU3_HOOK_IMPL(SpriteDescription, initDescription, dict)
#endif
SCREWYOU3_HOOK_END("SpriteDescription::initDescription")

#include <Geode/modify/StarInfoPopup.hpp>

bool StarInfoPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(StarInfoPopup)
SCREWYOU3_HOOK(bool init(int autos, int easies, int normals, int hards, int harders, int insanes, int dailies, int gauntlets, int maps, bool platformer))
SCREWYOU3_HOOK_IMPL(StarInfoPopup, init, autos, easies, normals, hards, harders, insanes, dailies, gauntlets, maps, platformer)
SCREWYOU3_HOOK_END("StarInfoPopup::init")

#include <Geode/modify/StartPosObject.hpp>

bool StartPosObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string StartPosObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(StartPosObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(StartPosObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(StartPosObject, getSaveString, layer)
SCREWYOU3_HOOK_END("StartPosObject::init")

#include <Geode/modify/StatsCell.hpp>

const char* StatsCell_getTitleFromKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(StatsCell)
SCREWYOU3_HOOK(const char* getTitleFromKey(char const* key))
SCREWYOU3_HOOK_IMPL(StatsCell, getTitleFromKey, key)
SCREWYOU3_HOOK_END("StatsCell::getTitleFromKey")

#include <Geode/modify/TableView.hpp>

bool TableView_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int TableView_checkBoundaryOfCell_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool TableView_isDuplicateIndexPath_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool TableView_isDuplicateInVisibleCellArray_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TableView)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(TableView, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(int checkBoundaryOfCell(cocos2d::CCPoint& position, float height))
SCREWYOU3_HOOK_IMPL(TableView, checkBoundaryOfCell, position, height)
SCREWYOU3_HOOK(int checkBoundaryOfCell(TableViewCell* cell))
SCREWYOU3_HOOK_IMPL(TableView, checkBoundaryOfCell, cell)
SCREWYOU3_HOOK(bool isDuplicateIndexPath(CCIndexPath& path))
SCREWYOU3_HOOK_IMPL(TableView, isDuplicateIndexPath, path)
SCREWYOU3_HOOK(bool isDuplicateInVisibleCellArray(CCIndexPath* path))
SCREWYOU3_HOOK_IMPL(TableView, isDuplicateInVisibleCellArray, path)
SCREWYOU3_HOOK_END("TableView::ccTouchBegan")

#include <Geode/modify/TeleportPortalObject.hpp>

gd::string TeleportPortalObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int TeleportPortalObject_addToGroup_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float TeleportPortalObject_getTeleportXOff_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(TeleportPortalObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(TeleportPortalObject, getSaveString, layer)
SCREWYOU3_HOOK(int addToGroup(int id))
SCREWYOU3_HOOK_IMPL(TeleportPortalObject, addToGroup, id)
SCREWYOU3_HOOK(float getTeleportXOff(cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(TeleportPortalObject, getTeleportXOff, parent)
SCREWYOU3_HOOK_END("TeleportPortalObject::getSaveString")

#include <Geode/modify/TextAlertPopup.hpp>

bool TextAlertPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TextAlertPopup)
SCREWYOU3_HOOK(bool init(gd::string text, float delay, float scale, int opacity, gd::string font))
SCREWYOU3_HOOK_IMPL(TextAlertPopup, init, text, delay, scale, opacity, font)
SCREWYOU3_HOOK_END("TextAlertPopup::init")

#include <Geode/modify/TextArea.hpp>

float TextArea_fadeInCharacters_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(TextArea)
SCREWYOU3_HOOK(float fadeInCharacters(float duration, float charDuration, bool fadeOut, TextFadeInStyle style))
SCREWYOU3_HOOK_IMPL(TextArea, fadeInCharacters, duration, charDuration, fadeOut, style)
SCREWYOU3_HOOK_END("TextArea::fadeInCharacters")

#include <Geode/modify/TextGameObject.hpp>

gd::string TextGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int TextGameObject_getTextKerning_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(TextGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(TextGameObject, getSaveString, layer)
SCREWYOU3_HOOK(int getTextKerning())
SCREWYOU3_HOOK_IMPL(TextGameObject, getTextKerning, )
SCREWYOU3_HOOK_END("TextGameObject::getSaveString")

#include <Geode/modify/TimerTriggerGameObject.hpp>

gd::string TimerTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(TimerTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(TimerTriggerGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("TimerTriggerGameObject::getSaveString")

#include <Geode/modify/TopArtistsLayer.hpp>

bool TopArtistsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TopArtistsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(TopArtistsLayer, init, )
SCREWYOU3_HOOK_END("TopArtistsLayer::init")

#include <Geode/modify/TOSPopup.hpp>

bool TOSPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TOSPopup)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(TOSPopup, init, )
SCREWYOU3_HOOK_END("TOSPopup::init")

#include <Geode/modify/TransformTriggerGameObject.hpp>

gd::string TransformTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(TransformTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(TransformTriggerGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("TransformTriggerGameObject::getSaveString")

#include <Geode/modify/TriggerControlGameObject.hpp>

gd::string TriggerControlGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(TriggerControlGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(TriggerControlGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("TriggerControlGameObject::getSaveString")

#include <Geode/modify/TutorialLayer.hpp>

bool TutorialLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TutorialLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(TutorialLayer, init, )
SCREWYOU3_HOOK_END("TutorialLayer::init")

#include <Geode/modify/TutorialPopup.hpp>

bool TutorialPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TutorialPopup)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(gd::string frame))
SCREWYOU3_HOOK_IMPL(TutorialPopup, init, frame)
#endif
SCREWYOU3_HOOK_END("TutorialPopup::init")

#include <Geode/modify/UILayer.hpp>

bool UILayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool UILayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool UILayer_processUINodesTouch_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool UILayer_processUINodeTouch_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UILayer)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(UILayer, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(bool init(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(UILayer, init, layer)
SCREWYOU3_HOOK(bool processUINodesTouch(GJUITouchEvent event, cocos2d::CCTouch* touch))
SCREWYOU3_HOOK_IMPL(UILayer, processUINodesTouch, event, touch)
SCREWYOU3_HOOK(bool processUINodeTouch(GJUITouchEvent event, int touchID, cocos2d::CCPoint position, GJUINode* node))
SCREWYOU3_HOOK_IMPL(UILayer, processUINodeTouch, event, touchID, position, node)
SCREWYOU3_HOOK_END("UILayer::ccTouchBegan")

#include <Geode/modify/UIObjectSettingsPopup.hpp>

bool UIObjectSettingsPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UIObjectSettingsPopup)
SCREWYOU3_HOOK(bool init(UISettingsGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(UIObjectSettingsPopup, init, object, objects)
SCREWYOU3_HOOK_END("UIObjectSettingsPopup::init")

#include <Geode/modify/UIOptionsLayer.hpp>

bool UIOptionsLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float UIOptionsLayer_getValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool UIOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UIOptionsLayer)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(UIOptionsLayer, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(float getValue(int tag))
SCREWYOU3_HOOK_IMPL(UIOptionsLayer, getValue, tag)
SCREWYOU3_HOOK(bool init(bool dual))
SCREWYOU3_HOOK_IMPL(UIOptionsLayer, init, dual)
SCREWYOU3_HOOK_END("UIOptionsLayer::ccTouchBegan")

#include <Geode/modify/UIPOptionsLayer.hpp>

bool UIPOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool UIPOptionsLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float UIPOptionsLayer_getValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(UIPOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(UIPOptionsLayer, init, )
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(UIPOptionsLayer, ccTouchBegan, touch, event)
SCREWYOU3_HOOK(float getValue(int tag))
SCREWYOU3_HOOK_IMPL(UIPOptionsLayer, getValue, tag)
SCREWYOU3_HOOK_END("UIPOptionsLayer::init")

#include <Geode/modify/UISaveLoadLayer.hpp>

bool UISaveLoadLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UISaveLoadLayer)
SCREWYOU3_HOOK(bool init(UIOptionsLayer* layer))
SCREWYOU3_HOOK_IMPL(UISaveLoadLayer, init, layer)
SCREWYOU3_HOOK_END("UISaveLoadLayer::init")

#include <Geode/modify/UISettingsGameObject.hpp>

bool UISettingsGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string UISettingsGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(UISettingsGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(UISettingsGameObject, init, )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(UISettingsGameObject, getSaveString, layer)
SCREWYOU3_HOOK_END("UISettingsGameObject::init")

#include <Geode/modify/UpdateAccountSettingsPopup.hpp>

bool UpdateAccountSettingsPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UpdateAccountSettingsPopup)
SCREWYOU3_HOOK(bool init(GJAccountSettingsLayer* settingsLayer, int messageStatus, int friendStatus, int commentStatus, gd::string youtubeURL, gd::string twitterURL, gd::string twitchURL))
SCREWYOU3_HOOK_IMPL(UpdateAccountSettingsPopup, init, settingsLayer, messageStatus, friendStatus, commentStatus, youtubeURL, twitterURL, twitchURL)
SCREWYOU3_HOOK_END("UpdateAccountSettingsPopup::init")

#include <Geode/modify/UploadActionPopup.hpp>

bool UploadActionPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UploadActionPopup)
SCREWYOU3_HOOK(bool init(UploadPopupDelegate* delegate, gd::string str))
SCREWYOU3_HOOK_IMPL(UploadActionPopup, init, delegate, str)
SCREWYOU3_HOOK_END("UploadActionPopup::init")

#include <Geode/modify/UploadListPopup.hpp>

bool UploadListPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UploadListPopup)
SCREWYOU3_HOOK(bool init(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(UploadListPopup, init, list)
SCREWYOU3_HOOK_END("UploadListPopup::init")

#include <Geode/modify/UploadPopup.hpp>

bool UploadPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UploadPopup)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(UploadPopup, init, level)
SCREWYOU3_HOOK_END("UploadPopup::init")

#include <Geode/modify/URLCell.hpp>

bool URLCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(URLCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(URLCell, init, )
SCREWYOU3_HOOK_END("URLCell::init")

#include <Geode/modify/VideoOptionsLayer.hpp>

bool VideoOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(VideoOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(VideoOptionsLayer, init, )
SCREWYOU3_HOOK_END("VideoOptionsLayer::init")

#include <Geode/modify/WorldLevelPage.hpp>

bool WorldLevelPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(WorldLevelPage)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(GJGameLevel* level, GJWorldNode* node))
SCREWYOU3_HOOK_IMPL(WorldLevelPage, init, level, node)
#endif
SCREWYOU3_HOOK_END("WorldLevelPage::init")

#include <Geode/modify/WorldSelectLayer.hpp>

bool WorldSelectLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(WorldSelectLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int page))
SCREWYOU3_HOOK_IMPL(WorldSelectLayer, init, page)
#endif
SCREWYOU3_HOOK_END("WorldSelectLayer::init")

