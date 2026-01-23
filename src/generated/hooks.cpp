// Generated using 'generate.py'
#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include "../ScrewYou3Manager.hpp"
#include "../utils.hpp"

using namespace geode::prelude;

// Cursed macros but whatever, this isn't supposed to be the most readable thing after all

#define SCREWYOU3_MENULAYER_CUSTOM_INIT(className, ...) { \
        if (ScrewYou3Manager::get()->isKilled(className::CLASS_NAME) && Mod::get()->getSettingValue<bool>("enabled")) return true; \
        if (!className::init(__VA_ARGS__)) return false; \
        if (Mod::get()->getSavedValue<bool>("first-time-loading", true)) { \
            log::info("Showing popup"); \
            Mod::get()->setSavedValue<bool>("first-time-loading", false); \
            auto alert = FLAlertLayer::create( \
                "Before you continue", \
                "This mod CAN and WILL make your gd crash. Be sure to read this mod's description before continuing", \
                "Dismiss" \
            ); \
            alert->m_scene = this; \
            alert->show(); \
        } \
        return true; \
    } \
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
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(AccountLoginLayer)
SCREWYOU3_HOOK(bool init(gd::string username))
SCREWYOU3_HOOK_IMPL(AccountLoginLayer, init, username)
SCREWYOU3_HOOK_END("AccountLoginLayer::init")

#include <Geode/modify/AccountRegisterLayer.hpp>
bool AccountRegisterLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(AccountRegisterLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(AccountRegisterLayer, init, )
SCREWYOU3_HOOK_END("AccountRegisterLayer::init")

#include <Geode/modify/AchievementBar.hpp>
bool AchievementBar_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(AchievementBar)
SCREWYOU3_HOOK(bool init(char const* title, char const* desc, char const* icon, bool quest))
SCREWYOU3_HOOK_IMPL(AchievementBar, init, title, desc, icon, quest)
SCREWYOU3_HOOK_END("AchievementBar::init")

#include <Geode/modify/AchievementManager.hpp>
bool AchievementManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(AchievementManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(AchievementManager, init, )
SCREWYOU3_HOOK_END("AchievementManager::init")

#include <Geode/modify/AchievementNotifier.hpp>
bool AchievementNotifier_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(AchievementNotifier)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(AchievementNotifier, init, )
SCREWYOU3_HOOK_END("AchievementNotifier::init")

#include <Geode/modify/AnimatedGameObject.hpp>
bool AnimatedGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(AnimatedGameObject)
SCREWYOU3_HOOK(bool init(int id))
SCREWYOU3_HOOK_IMPL(AnimatedGameObject, init, id)
SCREWYOU3_HOOK_END("AnimatedGameObject::init")

#include <Geode/modify/ArtistCell.hpp>
bool ArtistCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ArtistCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ArtistCell, init, )
SCREWYOU3_HOOK_END("ArtistCell::init")

#include <Geode/modify/AudioAssetsBrowser.hpp>
bool AudioAssetsBrowser_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(AudioAssetsBrowser)
SCREWYOU3_HOOK(bool init(gd::vector<int>& songIds, gd::vector<int>& sfxIds))
SCREWYOU3_HOOK_IMPL(AudioAssetsBrowser, init, songIds, sfxIds)
SCREWYOU3_HOOK_END("AudioAssetsBrowser::init")

#include <Geode/modify/AudioEffectsLayer.hpp>
bool AudioEffectsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(AudioEffectsLayer)
SCREWYOU3_HOOK(bool init(gd::string audioString))
SCREWYOU3_HOOK_IMPL(AudioEffectsLayer, init, audioString)
SCREWYOU3_HOOK_END("AudioEffectsLayer::init")

#include <Geode/modify/AudioLineGuideGameObject.hpp>
bool AudioLineGuideGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(AudioLineGuideGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(AudioLineGuideGameObject, init, )
SCREWYOU3_HOOK_END("AudioLineGuideGameObject::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/BonusDropdown.hpp>
bool BonusDropdown_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(BonusDropdown)
SCREWYOU3_HOOK(bool init(gd::string text, int price))
SCREWYOU3_HOOK_IMPL(BonusDropdown, init, text, price)
SCREWYOU3_HOOK_END("BonusDropdown::init")
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/BoomListLayer.hpp>
bool BoomListLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(BoomListLayer)
SCREWYOU3_HOOK(bool init(BoomListView* listView, char const* title))
SCREWYOU3_HOOK_IMPL(BoomListLayer, init, listView, title)
SCREWYOU3_HOOK_END("BoomListLayer::init")
#endif

#include <Geode/modify/BoomListView.hpp>
bool BoomListView_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(BoomListView)
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* entries, TableViewCellDelegate* delegate, float height, float width, int page, BoomListType type, float y))
SCREWYOU3_HOOK_IMPL(BoomListView, init, entries, delegate, height, width, page, type, y)
SCREWYOU3_HOOK_END("BoomListView::init")

#include <Geode/modify/BoomScrollLayer.hpp>
bool BoomScrollLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(BoomScrollLayer)
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* pages, int offset, bool looped, cocos2d::CCArray* dynamicObjects, DynamicScrollDelegate* delegate))
SCREWYOU3_HOOK_IMPL(BoomScrollLayer, init, pages, offset, looped, dynamicObjects, delegate)
SCREWYOU3_HOOK_END("BoomScrollLayer::init")

#include <Geode/modify/BrowseSmartKeyLayer.hpp>
bool BrowseSmartKeyLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(BrowseSmartKeyLayer)
SCREWYOU3_HOOK(bool init(GJSmartTemplate* smartTemplate, gd::string prefabKey))
SCREWYOU3_HOOK_IMPL(BrowseSmartKeyLayer, init, smartTemplate, prefabKey)
SCREWYOU3_HOOK_END("BrowseSmartKeyLayer::init")

#include <Geode/modify/BrowseSmartTemplateLayer.hpp>
bool BrowseSmartTemplateLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(BrowseSmartTemplateLayer)
SCREWYOU3_HOOK(bool init(GJSmartTemplate* smartTemplate, SmartBrowseFilter browseFilter))
SCREWYOU3_HOOK_IMPL(BrowseSmartTemplateLayer, init, smartTemplate, browseFilter)
SCREWYOU3_HOOK_END("BrowseSmartTemplateLayer::init")

#include <Geode/modify/ButtonSprite.hpp>
bool ButtonSprite_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ButtonSprite)
SCREWYOU3_HOOK(bool init(cocos2d::CCSprite* topSprite, int width, int minWidth, float height, float scale, bool absolute, char const* bgSprite, bool noScaleSpriteForBG))
SCREWYOU3_HOOK_IMPL(ButtonSprite, init, topSprite, width, minWidth, height, scale, absolute, bgSprite, noScaleSpriteForBG)
SCREWYOU3_HOOK_END("ButtonSprite::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/CCAlertCircle.hpp>
bool CCAlertCircle_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CCAlertCircle)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCAlertCircle, init, )
SCREWYOU3_HOOK_END("CCAlertCircle::init")
#endif

#include <Geode/modify/CCBlockLayer.hpp>
bool CCBlockLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CCBlockLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCBlockLayer, init, )
SCREWYOU3_HOOK_END("CCBlockLayer::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/CCCircleAlert.hpp>
bool CCCircleAlert_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CCCircleAlert)
SCREWYOU3_HOOK(bool init(float duration, float startRadius, float endRadius))
SCREWYOU3_HOOK_IMPL(CCCircleAlert, init, duration, startRadius, endRadius)
SCREWYOU3_HOOK_END("CCCircleAlert::init")
#endif

#include <Geode/modify/CCCircleWave.hpp>
bool CCCircleWave_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CCCircleWave)
SCREWYOU3_HOOK(bool init(float startRadius, float endRadius, float duration, bool fadeIn, bool easeOut))
SCREWYOU3_HOOK_IMPL(CCCircleWave, init, startRadius, endRadius, duration, fadeIn, easeOut)
SCREWYOU3_HOOK_END("CCCircleWave::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/CCCountdown.hpp>
bool CCCountdown_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CCCountdown)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCCountdown, init, )
SCREWYOU3_HOOK_END("CCCountdown::init")
#endif

#include <Geode/modify/CCMenuItemSpriteExtra.hpp>
bool CCMenuItemSpriteExtra_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CCMenuItemSpriteExtra)
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* sprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback))
SCREWYOU3_HOOK_IMPL(CCMenuItemSpriteExtra, init, sprite, selectedSprite, target, callback)
SCREWYOU3_HOOK_END("CCMenuItemSpriteExtra::init")

#include <Geode/modify/CCNodeContainer.hpp>
bool CCNodeContainer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CCNodeContainer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCNodeContainer, init, )
SCREWYOU3_HOOK_END("CCNodeContainer::init")

#include <Geode/modify/CCTextInputNode.hpp>
bool CCTextInputNode_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CCTextInputNode)
SCREWYOU3_HOOK(bool init(float width, float height, char const* placeholder, char const* textFont, int fontSize, char const* labelFont))
SCREWYOU3_HOOK_IMPL(CCTextInputNode, init, width, height, placeholder, textFont, fontSize, labelFont)
SCREWYOU3_HOOK_END("CCTextInputNode::init")

#include <Geode/modify/ChallengeNode.hpp>
bool ChallengeNode_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ChallengeNode)
SCREWYOU3_HOOK(bool init(GJChallengeItem* challengeItem, ChallengesPage* challengesPage, bool isNew))
SCREWYOU3_HOOK_IMPL(ChallengeNode, init, challengeItem, challengesPage, isNew)
SCREWYOU3_HOOK_END("ChallengeNode::init")

#include <Geode/modify/ChallengesPage.hpp>
bool ChallengesPage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ChallengesPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ChallengesPage, init, )
SCREWYOU3_HOOK_END("ChallengesPage::init")

#include <Geode/modify/CharacterColorPage.hpp>
bool CharacterColorPage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CharacterColorPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CharacterColorPage, init, )
SCREWYOU3_HOOK_END("CharacterColorPage::init")

#include <Geode/modify/CheckpointGameObject.hpp>
bool CheckpointGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CheckpointGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CheckpointGameObject, init, )
SCREWYOU3_HOOK_END("CheckpointGameObject::init")

#include <Geode/modify/CheckpointObject.hpp>
bool CheckpointObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CheckpointObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CheckpointObject, init, )
SCREWYOU3_HOOK_END("CheckpointObject::init")

#include <Geode/modify/CollisionBlockPopup.hpp>
bool CollisionBlockPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CollisionBlockPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(CollisionBlockPopup, init, object, objects)
SCREWYOU3_HOOK_END("CollisionBlockPopup::init")

#include <Geode/modify/ColorActionSprite.hpp>
bool ColorActionSprite_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ColorActionSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ColorActionSprite, init, )
SCREWYOU3_HOOK_END("ColorActionSprite::init")

#include <Geode/modify/ColorChannelSprite.hpp>
bool ColorChannelSprite_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ColorChannelSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ColorChannelSprite, init, )
SCREWYOU3_HOOK_END("ColorChannelSprite::init")

#include <Geode/modify/ColorSelectLiveOverlay.hpp>
bool ColorSelectLiveOverlay_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ColorSelectLiveOverlay)
SCREWYOU3_HOOK(bool init(ColorAction* baseAction, ColorAction* detailAction, EffectGameObject* object))
SCREWYOU3_HOOK_IMPL(ColorSelectLiveOverlay, init, baseAction, detailAction, object)
SCREWYOU3_HOOK_END("ColorSelectLiveOverlay::init")

#include <Geode/modify/ColorSelectPopup.hpp>
bool ColorSelectPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ColorSelectPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, ColorAction* action))
SCREWYOU3_HOOK_IMPL(ColorSelectPopup, init, object, objects, action)
SCREWYOU3_HOOK_END("ColorSelectPopup::init")

#include <Geode/modify/CommentCell.hpp>
bool CommentCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CommentCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CommentCell, init, )
SCREWYOU3_HOOK_END("CommentCell::init")

#include <Geode/modify/CommunityCreditsPage.hpp>
bool CommunityCreditsPage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CommunityCreditsPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CommunityCreditsPage, init, )
SCREWYOU3_HOOK_END("CommunityCreditsPage::init")

#include <Geode/modify/ConfigureHSVWidget.hpp>
bool ConfigureHSVWidget_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ConfigureHSVWidget)
SCREWYOU3_HOOK(bool init(cocos2d::ccHSVValue hsv, bool noBackground, bool addInputs))
SCREWYOU3_HOOK_IMPL(ConfigureHSVWidget, init, hsv, noBackground, addInputs)
SCREWYOU3_HOOK_END("ConfigureHSVWidget::init")

#include <Geode/modify/ConfigureValuePopup.hpp>
bool ConfigureValuePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ConfigureValuePopup)
SCREWYOU3_HOOK(bool init(ConfigureValuePopupDelegate* delegate, float value, float minimum, float maximum, gd::string title, gd::string description))
SCREWYOU3_HOOK_IMPL(ConfigureValuePopup, init, delegate, value, minimum, maximum, title, description)
SCREWYOU3_HOOK_END("ConfigureValuePopup::init")

#include <Geode/modify/CreateGuidelinesLayer.hpp>
bool CreateGuidelinesLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CreateGuidelinesLayer)
SCREWYOU3_HOOK(bool init(CustomSongDelegate* delegate, AudioGuidelinesType type))
SCREWYOU3_HOOK_IMPL(CreateGuidelinesLayer, init, delegate, type)
SCREWYOU3_HOOK_END("CreateGuidelinesLayer::init")

#include <Geode/modify/CreateParticlePopup.hpp>
bool CreateParticlePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CreateParticlePopup)
SCREWYOU3_HOOK(bool init(ParticleGameObject* object, cocos2d::CCArray* objects, gd::string str))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, init, object, objects, str)
SCREWYOU3_HOOK_END("CreateParticlePopup::init")

#include <Geode/modify/CreatorLayer.hpp>
bool CreatorLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CreatorLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CreatorLayer, init, )
SCREWYOU3_HOOK_END("CreatorLayer::init")

#include <Geode/modify/CurrencyRewardLayer.hpp>
bool CurrencyRewardLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CurrencyRewardLayer)
SCREWYOU3_HOOK(bool init(int orbs, int stars, int moons, int diamonds, CurrencySpriteType demonKey, int keyCount, CurrencySpriteType shardType, int shardsCount, cocos2d::CCPoint position, CurrencyRewardType rewardType, float yOffset, float time))
SCREWYOU3_HOOK_IMPL(CurrencyRewardLayer, init, orbs, stars, moons, diamonds, demonKey, keyCount, shardType, shardsCount, position, rewardType, yOffset, time)
SCREWYOU3_HOOK_END("CurrencyRewardLayer::init")

#include <Geode/modify/CurrencySprite.hpp>
bool CurrencySprite_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CurrencySprite)
SCREWYOU3_HOOK(bool init(CurrencySpriteType type, bool burst))
SCREWYOU3_HOOK_IMPL(CurrencySprite, init, type, burst)
SCREWYOU3_HOOK_END("CurrencySprite::init")

#include <Geode/modify/CustomizeObjectLayer.hpp>
bool CustomizeObjectLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CustomizeObjectLayer)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(CustomizeObjectLayer, init, object, objects)
SCREWYOU3_HOOK_END("CustomizeObjectLayer::init")

#include <Geode/modify/CustomizeObjectSettingsPopup.hpp>
bool CustomizeObjectSettingsPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CustomizeObjectSettingsPopup)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects, CustomizeObjectLayer* layer))
SCREWYOU3_HOOK_IMPL(CustomizeObjectSettingsPopup, init, object, objects, layer)
SCREWYOU3_HOOK_END("CustomizeObjectSettingsPopup::init")

#include <Geode/modify/CustomSFXCell.hpp>
bool CustomSFXCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CustomSFXCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CustomSFXCell, init, )
SCREWYOU3_HOOK_END("CustomSFXCell::init")

#include <Geode/modify/CustomSFXWidget.hpp>
bool CustomSFXWidget_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CustomSFXWidget)
SCREWYOU3_HOOK(bool init(SFXInfoObject* object, CustomSFXDelegate* delegate, bool showDelete, bool showPlay, bool showDownload, bool noBackground, bool compactMode))
SCREWYOU3_HOOK_IMPL(CustomSFXWidget, init, object, delegate, showDelete, showPlay, showDownload, noBackground, compactMode)
SCREWYOU3_HOOK_END("CustomSFXWidget::init")

#include <Geode/modify/CustomSongCell.hpp>
bool CustomSongCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CustomSongCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CustomSongCell, init, )
SCREWYOU3_HOOK_END("CustomSongCell::init")

#include <Geode/modify/CustomSongLayer.hpp>
bool CustomSongLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CustomSongLayer)
SCREWYOU3_HOOK(bool init(CustomSongDelegate* delegate))
SCREWYOU3_HOOK_IMPL(CustomSongLayer, init, delegate)
SCREWYOU3_HOOK_END("CustomSongLayer::init")

#include <Geode/modify/CustomSongWidget.hpp>
bool CustomSongWidget_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(CustomSongWidget)
SCREWYOU3_HOOK(bool init(SongInfoObject* songInfo, CustomSongDelegate* songDelegate, bool showSongSelect, bool showPlayMusic, bool showDownload, bool isRobtopSong, bool unkBool, bool isMusicLibrary, int unk))
SCREWYOU3_HOOK_IMPL(CustomSongWidget, init, songInfo, songDelegate, showSongSelect, showPlayMusic, showDownload, isRobtopSong, unkBool, isMusicLibrary, unk)
SCREWYOU3_HOOK_END("CustomSongWidget::init")

#include <Geode/modify/DailyLevelNode.hpp>
bool DailyLevelNode_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(DailyLevelNode)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, DailyLevelPage* page, bool isNew))
SCREWYOU3_HOOK_IMPL(DailyLevelNode, init, level, page, isNew)
SCREWYOU3_HOOK_END("DailyLevelNode::init")

#include <Geode/modify/DailyLevelPage.hpp>
bool DailyLevelPage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(DailyLevelPage)
SCREWYOU3_HOOK(bool init(GJTimedLevelType type))
SCREWYOU3_HOOK_IMPL(DailyLevelPage, init, type)
SCREWYOU3_HOOK_END("DailyLevelPage::init")

#include <Geode/modify/DemonFilterSelectLayer.hpp>
bool DemonFilterSelectLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(DemonFilterSelectLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(DemonFilterSelectLayer, init, )
SCREWYOU3_HOOK_END("DemonFilterSelectLayer::init")

#include <Geode/modify/DemonInfoPopup.hpp>
bool DemonInfoPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(DemonInfoPopup)
SCREWYOU3_HOOK(bool init(int easyClassic, int mediumClassic, int hardClassic, int insaneClassic, int extremeClassic, int easyPlatformer, int mediumPlatformer, int hardPlatformer, int insanePlatformer, int extremePlatformer, int weekly, int gauntlet))
SCREWYOU3_HOOK_IMPL(DemonInfoPopup, init, easyClassic, mediumClassic, hardClassic, insaneClassic, extremeClassic, easyPlatformer, mediumPlatformer, hardPlatformer, insanePlatformer, extremePlatformer, weekly, gauntlet)
SCREWYOU3_HOOK_END("DemonInfoPopup::init")

#include <Geode/modify/DialogLayer.hpp>
bool DialogLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(DialogLayer)
SCREWYOU3_HOOK(bool init(DialogObject* object, cocos2d::CCArray* objects, int background))
SCREWYOU3_HOOK_IMPL(DialogLayer, init, object, objects, background)
SCREWYOU3_HOOK_END("DialogLayer::init")

#include <Geode/modify/DungeonBarsSprite.hpp>
bool DungeonBarsSprite_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(DungeonBarsSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(DungeonBarsSprite, init, )
SCREWYOU3_HOOK_END("DungeonBarsSprite::init")

#include <Geode/modify/EditGameObjectPopup.hpp>
bool EditGameObjectPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(EditGameObjectPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, bool platformer))
SCREWYOU3_HOOK_IMPL(EditGameObjectPopup, init, object, objects, platformer)
SCREWYOU3_HOOK_END("EditGameObjectPopup::init")

#include <Geode/modify/EditLevelLayer.hpp>
bool EditLevelLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(EditLevelLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(EditLevelLayer, init, level)
SCREWYOU3_HOOK_END("EditLevelLayer::init")

#include <Geode/modify/EditorOptionsLayer.hpp>
bool EditorOptionsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(EditorOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(EditorOptionsLayer, init, )
SCREWYOU3_HOOK_END("EditorOptionsLayer::init")

#include <Geode/modify/EditorPauseLayer.hpp>
bool EditorPauseLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(EditorPauseLayer)
SCREWYOU3_HOOK(bool init(LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(EditorPauseLayer, init, layer)
SCREWYOU3_HOOK_END("EditorPauseLayer::init")

#include <Geode/modify/EditorUI.hpp>
bool EditorUI_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(EditorUI)
SCREWYOU3_HOOK(bool init(LevelEditorLayer* editorLayer))
SCREWYOU3_HOOK_IMPL(EditorUI, init, editorLayer)
SCREWYOU3_HOOK_END("EditorUI::init")

#include <Geode/modify/EditTriggersPopup.hpp>
bool EditTriggersPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(EditTriggersPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(EditTriggersPopup, init, object, objects)
SCREWYOU3_HOOK_END("EditTriggersPopup::init")

#include <Geode/modify/EndPortalObject.hpp>
bool EndPortalObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(EndPortalObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(EndPortalObject, init, )
SCREWYOU3_HOOK_END("EndPortalObject::init")

#include <Geode/modify/EndTriggerGameObject.hpp>
bool EndTriggerGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(EndTriggerGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(EndTriggerGameObject, init, )
SCREWYOU3_HOOK_END("EndTriggerGameObject::init")

#include <Geode/modify/EnhancedGameObject.hpp>
bool EnhancedGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(EnhancedGameObject)
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, init, frame)
SCREWYOU3_HOOK_END("EnhancedGameObject::init")

#include <Geode/modify/EventLinkTrigger.hpp>
bool EventLinkTrigger_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(EventLinkTrigger)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(EventLinkTrigger, init, )
SCREWYOU3_HOOK_END("EventLinkTrigger::init")

#include <Geode/modify/ExplodeItemSprite.hpp>
bool ExplodeItemSprite_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ExplodeItemSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ExplodeItemSprite, init, )
SCREWYOU3_HOOK_END("ExplodeItemSprite::init")

#include <Geode/modify/ExtendedLayer.hpp>
bool ExtendedLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ExtendedLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ExtendedLayer, init, )
SCREWYOU3_HOOK_END("ExtendedLayer::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/FileSaveManager.hpp>
bool FileSaveManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(FileSaveManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(FileSaveManager, init, )
SCREWYOU3_HOOK_END("FileSaveManager::init")
#endif

#include <Geode/modify/FindObjectPopup.hpp>
bool FindObjectPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(FindObjectPopup)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(FindObjectPopup, init, )
SCREWYOU3_HOOK_END("FindObjectPopup::init")

#include <Geode/modify/FLAlertLayer.hpp>
bool FLAlertLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(FLAlertLayer)
SCREWYOU3_HOOK(bool init(int opacity))
SCREWYOU3_HOOK_IMPL(FLAlertLayer, init, opacity)
SCREWYOU3_HOOK_END("FLAlertLayer::init")

#include <Geode/modify/FMODLevelVisualizer.hpp>
bool FMODLevelVisualizer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(FMODLevelVisualizer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(FMODLevelVisualizer, init, )
SCREWYOU3_HOOK_END("FMODLevelVisualizer::init")

#include <Geode/modify/FollowRewardPage.hpp>
bool FollowRewardPage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(FollowRewardPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(FollowRewardPage, init, )
SCREWYOU3_HOOK_END("FollowRewardPage::init")

#include <Geode/modify/FRequestProfilePage.hpp>
bool FRequestProfilePage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(FRequestProfilePage)
SCREWYOU3_HOOK(bool init(bool sent))
SCREWYOU3_HOOK_IMPL(FRequestProfilePage, init, sent)
SCREWYOU3_HOOK_END("FRequestProfilePage::init")

#include <Geode/modify/FriendRequestPopup.hpp>
bool FriendRequestPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(FriendRequestPopup)
SCREWYOU3_HOOK(bool init(GJFriendRequest* request))
SCREWYOU3_HOOK_IMPL(FriendRequestPopup, init, request)
SCREWYOU3_HOOK_END("FriendRequestPopup::init")

#include <Geode/modify/FriendsProfilePage.hpp>
bool FriendsProfilePage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(FriendsProfilePage)
SCREWYOU3_HOOK(bool init(UserListType type))
SCREWYOU3_HOOK_IMPL(FriendsProfilePage, init, type)
SCREWYOU3_HOOK_END("FriendsProfilePage::init")

#include <Geode/modify/GameCell.hpp>
bool GameCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GameCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GameCell, init, )
SCREWYOU3_HOOK_END("GameCell::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GameEffectsManager.hpp>
bool GameEffectsManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GameEffectsManager)
SCREWYOU3_HOOK(bool init(PlayLayer* playLayer))
SCREWYOU3_HOOK_IMPL(GameEffectsManager, init, playLayer)
SCREWYOU3_HOOK_END("GameEffectsManager::init")
#endif

#include <Geode/modify/GameLevelManager.hpp>
bool GameLevelManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GameLevelManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GameLevelManager, init, )
SCREWYOU3_HOOK_END("GameLevelManager::init")

#include <Geode/modify/GameManager.hpp>
bool GameManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GameManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GameManager, init, )
SCREWYOU3_HOOK_END("GameManager::init")

#include <Geode/modify/GameStatsManager.hpp>
bool GameStatsManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GameStatsManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GameStatsManager, init, )
SCREWYOU3_HOOK_END("GameStatsManager::init")

#include <Geode/modify/GauntletLayer.hpp>
bool GauntletLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GauntletLayer)
SCREWYOU3_HOOK(bool init(GauntletType type))
SCREWYOU3_HOOK_IMPL(GauntletLayer, init, type)
SCREWYOU3_HOOK_END("GauntletLayer::init")

#include <Geode/modify/GauntletNode.hpp>
bool GauntletNode_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GauntletNode)
SCREWYOU3_HOOK(bool init(GJMapPack* gauntlet))
SCREWYOU3_HOOK_IMPL(GauntletNode, init, gauntlet)
SCREWYOU3_HOOK_END("GauntletNode::init")

#include <Geode/modify/GauntletSelectLayer.hpp>
bool GauntletSelectLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GauntletSelectLayer)
SCREWYOU3_HOOK(bool init(int unused))
SCREWYOU3_HOOK_IMPL(GauntletSelectLayer, init, unused)
SCREWYOU3_HOOK_END("GauntletSelectLayer::init")

#include <Geode/modify/GhostTrailEffect.hpp>
bool GhostTrailEffect_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GhostTrailEffect)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GhostTrailEffect, init, )
SCREWYOU3_HOOK_END("GhostTrailEffect::init")

#include <Geode/modify/GJAccountManager.hpp>
bool GJAccountManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJAccountManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJAccountManager, init, )
SCREWYOU3_HOOK_END("GJAccountManager::init")

#include <Geode/modify/GJAccountSettingsLayer.hpp>
bool GJAccountSettingsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJAccountSettingsLayer)
SCREWYOU3_HOOK(bool init(int accountID))
SCREWYOU3_HOOK_IMPL(GJAccountSettingsLayer, init, accountID)
SCREWYOU3_HOOK_END("GJAccountSettingsLayer::init")

#include <Geode/modify/GJActionManager.hpp>
bool GJActionManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJActionManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJActionManager, init, )
SCREWYOU3_HOOK_END("GJActionManager::init")

#include <Geode/modify/GJBaseGameLayer.hpp>
bool GJBaseGameLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJBaseGameLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, init, )
SCREWYOU3_HOOK_END("GJBaseGameLayer::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJBigSprite.hpp>
bool GJBigSprite_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJBigSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJBigSprite, init, )
SCREWYOU3_HOOK_END("GJBigSprite::init")
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJBigSpriteNode.hpp>
bool GJBigSpriteNode_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJBigSpriteNode)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJBigSpriteNode, init, )
SCREWYOU3_HOOK_END("GJBigSpriteNode::init")
#endif

#include <Geode/modify/GJColorSetupLayer.hpp>
bool GJColorSetupLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJColorSetupLayer)
SCREWYOU3_HOOK(bool init(LevelSettingsObject* object))
SCREWYOU3_HOOK_IMPL(GJColorSetupLayer, init, object)
SCREWYOU3_HOOK_END("GJColorSetupLayer::init")

#include <Geode/modify/GJComment.hpp>
bool GJComment_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJComment)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJComment, init, )
SCREWYOU3_HOOK_END("GJComment::init")

#include <Geode/modify/GJCommentListLayer.hpp>
bool GJCommentListLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJCommentListLayer)
SCREWYOU3_HOOK(bool init(BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, bool blueBorder))
SCREWYOU3_HOOK_IMPL(GJCommentListLayer, init, listView, title, color, width, height, blueBorder)
SCREWYOU3_HOOK_END("GJCommentListLayer::init")

#include <Geode/modify/GJDropDownLayer.hpp>
bool GJDropDownLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJDropDownLayer)
SCREWYOU3_HOOK(bool init(char const* title, float height, bool noBack))
SCREWYOU3_HOOK_IMPL(GJDropDownLayer, init, title, height, noBack)
SCREWYOU3_HOOK_END("GJDropDownLayer::init")

#include <Geode/modify/GJEffectManager.hpp>
bool GJEffectManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJEffectManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJEffectManager, init, )
SCREWYOU3_HOOK_END("GJEffectManager::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJFlyGroundLayer.hpp>
bool GJFlyGroundLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJFlyGroundLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJFlyGroundLayer, init, )
SCREWYOU3_HOOK_END("GJFlyGroundLayer::init")
#endif

#include <Geode/modify/GJFollowCommandLayer.hpp>
bool GJFollowCommandLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJFollowCommandLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(GJFollowCommandLayer, init, object, objects)
SCREWYOU3_HOOK_END("GJFollowCommandLayer::init")

#include <Geode/modify/GJFriendRequest.hpp>
bool GJFriendRequest_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJFriendRequest)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJFriendRequest, init, )
SCREWYOU3_HOOK_END("GJFriendRequest::init")

#include <Geode/modify/GJGameLevel.hpp>
bool GJGameLevel_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJGameLevel)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJGameLevel, init, )
SCREWYOU3_HOOK_END("GJGameLevel::init")

#include <Geode/modify/GJGarageLayer.hpp>
bool GJGarageLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJGarageLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJGarageLayer, init, )
SCREWYOU3_HOOK_END("GJGarageLayer::init")

#include <Geode/modify/GJGradientLayer.hpp>
bool GJGradientLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJGradientLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJGradientLayer, init, )
SCREWYOU3_HOOK_END("GJGradientLayer::init")

#include <Geode/modify/GJGroundLayer.hpp>
bool GJGroundLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJGroundLayer)
SCREWYOU3_HOOK(bool init(int groundID, int lineType))
SCREWYOU3_HOOK_IMPL(GJGroundLayer, init, groundID, lineType)
SCREWYOU3_HOOK_END("GJGroundLayer::init")

#include <Geode/modify/GJItemIcon.hpp>
bool GJItemIcon_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJItemIcon)
SCREWYOU3_HOOK(bool init(UnlockType type, int id, cocos2d::ccColor3B color1, cocos2d::ccColor3B color2, bool dark, bool unused, bool noLabel, cocos2d::ccColor3B unlockColor))
SCREWYOU3_HOOK_IMPL(GJItemIcon, init, type, id, color1, color2, dark, unused, noLabel, unlockColor)
SCREWYOU3_HOOK_END("GJItemIcon::init")

#include <Geode/modify/GJLevelList.hpp>
bool GJLevelList_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJLevelList)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJLevelList, init, )
SCREWYOU3_HOOK_END("GJLevelList::init")

#include <Geode/modify/GJLevelScoreCell.hpp>
bool GJLevelScoreCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJLevelScoreCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJLevelScoreCell, init, )
SCREWYOU3_HOOK_END("GJLevelScoreCell::init")

#include <Geode/modify/GJListLayer.hpp>
bool GJListLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJListLayer)
SCREWYOU3_HOOK(bool init(BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, int type))
SCREWYOU3_HOOK_IMPL(GJListLayer, init, listView, title, color, width, height, type)
SCREWYOU3_HOOK_END("GJListLayer::init")

#include <Geode/modify/GJLocalLevelScoreCell.hpp>
bool GJLocalLevelScoreCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJLocalLevelScoreCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJLocalLevelScoreCell, init, )
SCREWYOU3_HOOK_END("GJLocalLevelScoreCell::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJMapObject.hpp>
bool GJMapObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJMapObject)
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(GJMapObject, init, parent)
SCREWYOU3_HOOK_END("GJMapObject::init")
#endif

#include <Geode/modify/GJMapPack.hpp>
bool GJMapPack_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJMapPack)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJMapPack, init, )
SCREWYOU3_HOOK_END("GJMapPack::init")

#include <Geode/modify/GJMessageCell.hpp>
bool GJMessageCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJMessageCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJMessageCell, init, )
SCREWYOU3_HOOK_END("GJMessageCell::init")

#include <Geode/modify/GJMessagePopup.hpp>
bool GJMessagePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJMessagePopup)
SCREWYOU3_HOOK(bool init(GJUserMessage* message))
SCREWYOU3_HOOK_IMPL(GJMessagePopup, init, message)
SCREWYOU3_HOOK_END("GJMessagePopup::init")

#include <Geode/modify/GJMGLayer.hpp>
bool GJMGLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJMGLayer)
SCREWYOU3_HOOK(bool init(int index))
SCREWYOU3_HOOK_IMPL(GJMGLayer, init, index)
SCREWYOU3_HOOK_END("GJMGLayer::init")

#include <Geode/modify/GJMultiplayerManager.hpp>
bool GJMultiplayerManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJMultiplayerManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, init, )
SCREWYOU3_HOOK_END("GJMultiplayerManager::init")

#include <Geode/modify/GJObjectDecoder.hpp>
bool GJObjectDecoder_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJObjectDecoder)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJObjectDecoder, init, )
SCREWYOU3_HOOK_END("GJObjectDecoder::init")

#include <Geode/modify/GJOptionsLayer.hpp>
bool GJOptionsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJOptionsLayer)
SCREWYOU3_HOOK(bool init(int background))
SCREWYOU3_HOOK_IMPL(GJOptionsLayer, init, background)
SCREWYOU3_HOOK_END("GJOptionsLayer::init")

#include <Geode/modify/GJPathPage.hpp>
bool GJPathPage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJPathPage)
SCREWYOU3_HOOK(bool init(int path, GJPathsLayer* layer))
SCREWYOU3_HOOK_IMPL(GJPathPage, init, path, layer)
SCREWYOU3_HOOK_END("GJPathPage::init")

#include <Geode/modify/GJPathRewardPopup.hpp>
bool GJPathRewardPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJPathRewardPopup)
SCREWYOU3_HOOK(bool init(int path))
SCREWYOU3_HOOK_IMPL(GJPathRewardPopup, init, path)
SCREWYOU3_HOOK_END("GJPathRewardPopup::init")

#include <Geode/modify/GJPathsLayer.hpp>
bool GJPathsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJPathsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJPathsLayer, init, )
SCREWYOU3_HOOK_END("GJPathsLayer::init")

#include <Geode/modify/GJPFollowCommandLayer.hpp>
bool GJPFollowCommandLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJPFollowCommandLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(GJPFollowCommandLayer, init, object, objects)
SCREWYOU3_HOOK_END("GJPFollowCommandLayer::init")

#include <Geode/modify/GJPromoPopup.hpp>
bool GJPromoPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJPromoPopup)
SCREWYOU3_HOOK(bool init(gd::string filename))
SCREWYOU3_HOOK_IMPL(GJPromoPopup, init, filename)
SCREWYOU3_HOOK_END("GJPromoPopup::init")

#include <Geode/modify/GJRequestCell.hpp>
bool GJRequestCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJRequestCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJRequestCell, init, )
SCREWYOU3_HOOK_END("GJRequestCell::init")

#include <Geode/modify/GJRewardItem.hpp>
bool GJRewardItem_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJRewardItem)
SCREWYOU3_HOOK(bool init(int chestID, int timeRemaining, gd::string rewardStr))
SCREWYOU3_HOOK_IMPL(GJRewardItem, init, chestID, timeRemaining, rewardStr)
SCREWYOU3_HOOK_END("GJRewardItem::init")

#include <Geode/modify/GJRobotSprite.hpp>
bool GJRobotSprite_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJRobotSprite)
SCREWYOU3_HOOK(bool init(int frame, gd::string animName))
SCREWYOU3_HOOK_IMPL(GJRobotSprite, init, frame, animName)
SCREWYOU3_HOOK_END("GJRobotSprite::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJRotateCommandLayer.hpp>
bool GJRotateCommandLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJRotateCommandLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(GJRotateCommandLayer, init, object, objects)
SCREWYOU3_HOOK_END("GJRotateCommandLayer::init")
#endif

#include <Geode/modify/GJRotationControl.hpp>
bool GJRotationControl_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJRotationControl)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJRotationControl, init, )
SCREWYOU3_HOOK_END("GJRotationControl::init")

#include <Geode/modify/GJScaleControl.hpp>
bool GJScaleControl_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJScaleControl)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJScaleControl, init, )
SCREWYOU3_HOOK_END("GJScaleControl::init")

#include <Geode/modify/GJScoreCell.hpp>
bool GJScoreCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJScoreCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJScoreCell, init, )
SCREWYOU3_HOOK_END("GJScoreCell::init")

#include <Geode/modify/GJShopLayer.hpp>
bool GJShopLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJShopLayer)
SCREWYOU3_HOOK(bool init(ShopType type))
SCREWYOU3_HOOK_IMPL(GJShopLayer, init, type)
SCREWYOU3_HOOK_END("GJShopLayer::init")

#include <Geode/modify/GJSmartBlockPreviewSprite.hpp>
bool GJSmartBlockPreviewSprite_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJSmartBlockPreviewSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJSmartBlockPreviewSprite, init, )
SCREWYOU3_HOOK_END("GJSmartBlockPreviewSprite::init")

#include <Geode/modify/GJSongBrowser.hpp>
bool GJSongBrowser_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJSongBrowser)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJSongBrowser, init, )
SCREWYOU3_HOOK_END("GJSongBrowser::init")

#include <Geode/modify/GJSpecialColorSelect.hpp>
bool GJSpecialColorSelect_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJSpecialColorSelect)
SCREWYOU3_HOOK(bool init(int id, GJSpecialColorSelectDelegate* delegate, ColorSelectType type))
SCREWYOU3_HOOK_IMPL(GJSpecialColorSelect, init, id, delegate, type)
SCREWYOU3_HOOK_END("GJSpecialColorSelect::init")

#include <Geode/modify/GJTransformControl.hpp>
bool GJTransformControl_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJTransformControl)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJTransformControl, init, )
SCREWYOU3_HOOK_END("GJTransformControl::init")

#include <Geode/modify/GJUINode.hpp>
bool GJUINode_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJUINode)
SCREWYOU3_HOOK(bool init(UIButtonConfig& config))
SCREWYOU3_HOOK_IMPL(GJUINode, init, config)
SCREWYOU3_HOOK_END("GJUINode::init")

#include <Geode/modify/GJUserCell.hpp>
bool GJUserCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJUserCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJUserCell, init, )
SCREWYOU3_HOOK_END("GJUserCell::init")

#include <Geode/modify/GJUserMessage.hpp>
bool GJUserMessage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJUserMessage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJUserMessage, init, )
SCREWYOU3_HOOK_END("GJUserMessage::init")

#include <Geode/modify/GJUserScore.hpp>
bool GJUserScore_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJUserScore)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJUserScore, init, )
SCREWYOU3_HOOK_END("GJUserScore::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJWorldNode.hpp>
bool GJWorldNode_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJWorldNode)
SCREWYOU3_HOOK(bool init(int type, WorldSelectLayer* layer))
SCREWYOU3_HOOK_IMPL(GJWorldNode, init, type, layer)
SCREWYOU3_HOOK_END("GJWorldNode::init")
#endif

#include <Geode/modify/GJWriteMessagePopup.hpp>
bool GJWriteMessagePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GJWriteMessagePopup)
SCREWYOU3_HOOK(bool init(int accountID, int messageID))
SCREWYOU3_HOOK_IMPL(GJWriteMessagePopup, init, accountID, messageID)
SCREWYOU3_HOOK_END("GJWriteMessagePopup::init")

#include <Geode/modify/GManager.hpp>
bool GManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GManager, init, )
SCREWYOU3_HOOK_END("GManager::init")

#include <Geode/modify/GradientTriggerObject.hpp>
bool GradientTriggerObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GradientTriggerObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GradientTriggerObject, init, )
SCREWYOU3_HOOK_END("GradientTriggerObject::init")

#include <Geode/modify/GravityEffectSprite.hpp>
bool GravityEffectSprite_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(GravityEffectSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GravityEffectSprite, init, )
SCREWYOU3_HOOK_END("GravityEffectSprite::init")

#include <Geode/modify/HardStreak.hpp>
bool HardStreak_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(HardStreak)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(HardStreak, init, )
SCREWYOU3_HOOK_END("HardStreak::init")

#include <Geode/modify/HSVLiveOverlay.hpp>
bool HSVLiveOverlay_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(HSVLiveOverlay)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(HSVLiveOverlay, init, object, objects)
SCREWYOU3_HOOK_END("HSVLiveOverlay::init")

#include <Geode/modify/HSVWidgetPopup.hpp>
bool HSVWidgetPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(HSVWidgetPopup)
SCREWYOU3_HOOK(bool init(cocos2d::ccHSVValue hsv, HSVWidgetDelegate* delegate, gd::string title))
SCREWYOU3_HOOK_IMPL(HSVWidgetPopup, init, hsv, delegate, title)
SCREWYOU3_HOOK_END("HSVWidgetPopup::init")

#include <Geode/modify/InfoLayer.hpp>
bool InfoLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(InfoLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, GJUserScore* score, GJLevelList* list))
SCREWYOU3_HOOK_IMPL(InfoLayer, init, level, score, list)
SCREWYOU3_HOOK_END("InfoLayer::init")

#include <Geode/modify/ItemInfoPopup.hpp>
bool ItemInfoPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ItemInfoPopup)
SCREWYOU3_HOOK(bool init(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(ItemInfoPopup, init, id, type)
SCREWYOU3_HOOK_END("ItemInfoPopup::init")


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/KeybindingsLayer.hpp>
bool KeybindingsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(KeybindingsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(KeybindingsLayer, init, )
SCREWYOU3_HOOK_END("KeybindingsLayer::init")
#endif

#include <Geode/modify/KeyframeAnimTriggerObject.hpp>
bool KeyframeAnimTriggerObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(KeyframeAnimTriggerObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(KeyframeAnimTriggerObject, init, )
SCREWYOU3_HOOK_END("KeyframeAnimTriggerObject::init")

#include <Geode/modify/KeyframeGameObject.hpp>
bool KeyframeGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(KeyframeGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(KeyframeGameObject, init, )
SCREWYOU3_HOOK_END("KeyframeGameObject::init")

#include <Geode/modify/LabelGameObject.hpp>
bool LabelGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LabelGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LabelGameObject, init, )
SCREWYOU3_HOOK_END("LabelGameObject::init")

#include <Geode/modify/LeaderboardsLayer.hpp>
bool LeaderboardsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LeaderboardsLayer)
SCREWYOU3_HOOK(bool init(LeaderboardState state))
SCREWYOU3_HOOK_IMPL(LeaderboardsLayer, init, state)
SCREWYOU3_HOOK_END("LeaderboardsLayer::init")

#include <Geode/modify/LevelAreaInnerLayer.hpp>
bool LevelAreaInnerLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelAreaInnerLayer)
SCREWYOU3_HOOK(bool init(bool returning))
SCREWYOU3_HOOK_IMPL(LevelAreaInnerLayer, init, returning)
SCREWYOU3_HOOK_END("LevelAreaInnerLayer::init")

#include <Geode/modify/LevelAreaLayer.hpp>
bool LevelAreaLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelAreaLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LevelAreaLayer, init, )
SCREWYOU3_HOOK_END("LevelAreaLayer::init")

#include <Geode/modify/LevelBrowserLayer.hpp>
bool LevelBrowserLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelBrowserLayer)
SCREWYOU3_HOOK(bool init(GJSearchObject* object))
SCREWYOU3_HOOK_IMPL(LevelBrowserLayer, init, object)
SCREWYOU3_HOOK_END("LevelBrowserLayer::init")

#include <Geode/modify/LevelCell.hpp>
bool LevelCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LevelCell, init, )
SCREWYOU3_HOOK_END("LevelCell::init")

#include <Geode/modify/LevelEditorLayer.hpp>
bool LevelEditorLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelEditorLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, bool noUI))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, init, level, noUI)
SCREWYOU3_HOOK_END("LevelEditorLayer::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/LevelFeatureLayer.hpp>
bool LevelFeatureLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelFeatureLayer)
SCREWYOU3_HOOK(bool init(int levelID))
SCREWYOU3_HOOK_IMPL(LevelFeatureLayer, init, levelID)
SCREWYOU3_HOOK_END("LevelFeatureLayer::init")
#endif

#include <Geode/modify/LevelInfoLayer.hpp>
bool LevelInfoLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelInfoLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, bool challenge))
SCREWYOU3_HOOK_IMPL(LevelInfoLayer, init, level, challenge)
SCREWYOU3_HOOK_END("LevelInfoLayer::init")

#include <Geode/modify/LevelLeaderboard.hpp>
bool LevelLeaderboard_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelLeaderboard)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, LevelLeaderboardType type, LevelLeaderboardMode mode))
SCREWYOU3_HOOK_IMPL(LevelLeaderboard, init, level, type, mode)
SCREWYOU3_HOOK_END("LevelLeaderboard::init")

#include <Geode/modify/LevelListLayer.hpp>
bool LevelListLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelListLayer)
SCREWYOU3_HOOK(bool init(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(LevelListLayer, init, list)
SCREWYOU3_HOOK_END("LevelListLayer::init")

#include <Geode/modify/LevelOptionsLayer.hpp>
bool LevelOptionsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelOptionsLayer)
SCREWYOU3_HOOK(bool init(LevelSettingsObject* object))
SCREWYOU3_HOOK_IMPL(LevelOptionsLayer, init, object)
SCREWYOU3_HOOK_END("LevelOptionsLayer::init")

#include <Geode/modify/LevelPage.hpp>
bool LevelPage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelPage)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(LevelPage, init, level)
SCREWYOU3_HOOK_END("LevelPage::init")

#include <Geode/modify/LevelSearchLayer.hpp>
bool LevelSearchLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelSearchLayer)
SCREWYOU3_HOOK(bool init(int type))
SCREWYOU3_HOOK_IMPL(LevelSearchLayer, init, type)
SCREWYOU3_HOOK_END("LevelSearchLayer::init")

#include <Geode/modify/LevelSelectLayer.hpp>
bool LevelSelectLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelSelectLayer)
SCREWYOU3_HOOK(bool init(int page))
SCREWYOU3_HOOK_IMPL(LevelSelectLayer, init, page)
SCREWYOU3_HOOK_END("LevelSelectLayer::init")

#include <Geode/modify/LevelSettingsLayer.hpp>
bool LevelSettingsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelSettingsLayer)
SCREWYOU3_HOOK(bool init(LevelSettingsObject* object, LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(LevelSettingsLayer, init, object, layer)
SCREWYOU3_HOOK_END("LevelSettingsLayer::init")

#include <Geode/modify/LevelSettingsObject.hpp>
bool LevelSettingsObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LevelSettingsObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LevelSettingsObject, init, )
SCREWYOU3_HOOK_END("LevelSettingsObject::init")

#include <Geode/modify/LikeItemLayer.hpp>
bool LikeItemLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LikeItemLayer)
SCREWYOU3_HOOK(bool init(LikeItemType type, int id, int parentID))
SCREWYOU3_HOOK_IMPL(LikeItemLayer, init, type, id, parentID)
SCREWYOU3_HOOK_END("LikeItemLayer::init")

#include <Geode/modify/ListButtonBar.hpp>
bool ListButtonBar_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ListButtonBar)
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* items, cocos2d::CCPoint position, int columns, int rows, float columnOffset, float rowOffset, float offset, float arrowOffset, int arrowType))
SCREWYOU3_HOOK_IMPL(ListButtonBar, init, items, position, columns, rows, columnOffset, rowOffset, offset, arrowOffset, arrowType)
SCREWYOU3_HOOK_END("ListButtonBar::init")

#include <Geode/modify/LoadingCircle.hpp>
bool LoadingCircle_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LoadingCircle)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LoadingCircle, init, )
SCREWYOU3_HOOK_END("LoadingCircle::init")

#include <Geode/modify/LoadingLayer.hpp>
bool LoadingLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LoadingLayer)
SCREWYOU3_HOOK(bool init(bool refresh))
SCREWYOU3_HOOK_IMPL(LoadingLayer, init, refresh)
SCREWYOU3_HOOK_END("LoadingLayer::init")

#include <Geode/modify/LocalLevelManager.hpp>
bool LocalLevelManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(LocalLevelManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LocalLevelManager, init, )
SCREWYOU3_HOOK_END("LocalLevelManager::init")

#include <Geode/modify/MapPackCell.hpp>
bool MapPackCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MapPackCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MapPackCell, init, )
SCREWYOU3_HOOK_END("MapPackCell::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/MapSelectLayer.hpp>
bool MapSelectLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MapSelectLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MapSelectLayer, init, )
SCREWYOU3_HOOK_END("MapSelectLayer::init")
#endif

#include <Geode/modify/MenuGameLayer.hpp>
bool MenuGameLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MenuGameLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MenuGameLayer, init, )
SCREWYOU3_HOOK_END("MenuGameLayer::init")

#include <Geode/modify/MenuLayer.hpp>
bool MenuLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MenuLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MenuLayer, init, )
SCREWYOU3_HOOK_END("MenuLayer::init")

#include <Geode/modify/MessagesProfilePage.hpp>
bool MessagesProfilePage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MessagesProfilePage)
SCREWYOU3_HOOK(bool init(bool sent))
SCREWYOU3_HOOK_IMPL(MessagesProfilePage, init, sent)
SCREWYOU3_HOOK_END("MessagesProfilePage::init")

#include <Geode/modify/MoreOptionsLayer.hpp>
bool MoreOptionsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MoreOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MoreOptionsLayer, init, )
SCREWYOU3_HOOK_END("MoreOptionsLayer::init")

#include <Geode/modify/MoreSearchLayer.hpp>
bool MoreSearchLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MoreSearchLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MoreSearchLayer, init, )
SCREWYOU3_HOOK_END("MoreSearchLayer::init")

#include <Geode/modify/MoreVideoOptionsLayer.hpp>
bool MoreVideoOptionsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MoreVideoOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MoreVideoOptionsLayer, init, )
SCREWYOU3_HOOK_END("MoreVideoOptionsLayer::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/MPLobbyLayer.hpp>
bool MPLobbyLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MPLobbyLayer)
SCREWYOU3_HOOK(bool init(int type))
SCREWYOU3_HOOK_IMPL(MPLobbyLayer, init, type)
SCREWYOU3_HOOK_END("MPLobbyLayer::init")
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/MultiplayerLayer.hpp>
bool MultiplayerLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MultiplayerLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MultiplayerLayer, init, )
SCREWYOU3_HOOK_END("MultiplayerLayer::init")
#endif

#include <Geode/modify/MultiTriggerPopup.hpp>
bool MultiTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MultiTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(MultiTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("MultiTriggerPopup::init")

#include <Geode/modify/MusicBrowser.hpp>
bool MusicBrowser_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MusicBrowser)
SCREWYOU3_HOOK(bool init(int songID, GJSongType songType))
SCREWYOU3_HOOK_IMPL(MusicBrowser, init, songID, songType)
SCREWYOU3_HOOK_END("MusicBrowser::init")

#include <Geode/modify/MusicDownloadManager.hpp>
bool MusicDownloadManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(MusicDownloadManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, init, )
SCREWYOU3_HOOK_END("MusicDownloadManager::init")

#include <Geode/modify/NCSInfoLayer.hpp>
bool NCSInfoLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(NCSInfoLayer)
SCREWYOU3_HOOK(bool init(CustomSongLayer* layer))
SCREWYOU3_HOOK_IMPL(NCSInfoLayer, init, layer)
SCREWYOU3_HOOK_END("NCSInfoLayer::init")

#include <Geode/modify/NewgroundsInfoLayer.hpp>
bool NewgroundsInfoLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(NewgroundsInfoLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(NewgroundsInfoLayer, init, )
SCREWYOU3_HOOK_END("NewgroundsInfoLayer::init")

#include <Geode/modify/NumberInputLayer.hpp>
bool NumberInputLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(NumberInputLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(NumberInputLayer, init, )
SCREWYOU3_HOOK_END("NumberInputLayer::init")

#include <Geode/modify/ObjectControlGameObject.hpp>
bool ObjectControlGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ObjectControlGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ObjectControlGameObject, init, )
SCREWYOU3_HOOK_END("ObjectControlGameObject::init")

#include <Geode/modify/ObjectManager.hpp>
bool ObjectManager_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ObjectManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ObjectManager, init, )
SCREWYOU3_HOOK_END("ObjectManager::init")

#include <Geode/modify/ObjectToolbox.hpp>
bool ObjectToolbox_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ObjectToolbox)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ObjectToolbox, init, )
SCREWYOU3_HOOK_END("ObjectToolbox::init")

#include <Geode/modify/ParentalOptionsLayer.hpp>
bool ParentalOptionsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ParentalOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ParentalOptionsLayer, init, )
SCREWYOU3_HOOK_END("ParentalOptionsLayer::init")

#include <Geode/modify/ParticleGameObject.hpp>
bool ParticleGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ParticleGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ParticleGameObject, init, )
SCREWYOU3_HOOK_END("ParticleGameObject::init")

#include <Geode/modify/PlayerCheckpoint.hpp>
bool PlayerCheckpoint_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(PlayerCheckpoint)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(PlayerCheckpoint, init, )
SCREWYOU3_HOOK_END("PlayerCheckpoint::init")

#include <Geode/modify/PlayerControlGameObject.hpp>
bool PlayerControlGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(PlayerControlGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(PlayerControlGameObject, init, )
SCREWYOU3_HOOK_END("PlayerControlGameObject::init")

#include <Geode/modify/PlayerFireBoostSprite.hpp>
bool PlayerFireBoostSprite_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(PlayerFireBoostSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(PlayerFireBoostSprite, init, )
SCREWYOU3_HOOK_END("PlayerFireBoostSprite::init")

#include <Geode/modify/PlayerObject.hpp>
bool PlayerObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(PlayerObject)
SCREWYOU3_HOOK(bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer))
SCREWYOU3_HOOK_IMPL(PlayerObject, init, player, ship, gameLayer, layer, playLayer)
SCREWYOU3_HOOK_END("PlayerObject::init")

#include <Geode/modify/PlayLayer.hpp>
bool PlayLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(PlayLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects))
SCREWYOU3_HOOK_IMPL(PlayLayer, init, level, useReplay, dontCreateObjects)
SCREWYOU3_HOOK_END("PlayLayer::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/PriceLabel.hpp>
bool PriceLabel_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(PriceLabel)
SCREWYOU3_HOOK(bool init(int price))
SCREWYOU3_HOOK_IMPL(PriceLabel, init, price)
SCREWYOU3_HOOK_END("PriceLabel::init")
#endif

#include <Geode/modify/ProfilePage.hpp>
bool ProfilePage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ProfilePage)
SCREWYOU3_HOOK(bool init(int accountID, bool ownProfile))
SCREWYOU3_HOOK_IMPL(ProfilePage, init, accountID, ownProfile)
SCREWYOU3_HOOK_END("ProfilePage::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/PromoInterstitial.hpp>
bool PromoInterstitial_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(PromoInterstitial)
SCREWYOU3_HOOK(bool init(bool fullVersion))
SCREWYOU3_HOOK_IMPL(PromoInterstitial, init, fullVersion)
SCREWYOU3_HOOK_END("PromoInterstitial::init")
#endif

#include <Geode/modify/PurchaseItemPopup.hpp>
bool PurchaseItemPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(PurchaseItemPopup)
SCREWYOU3_HOOK(bool init(GJStoreItem* item))
SCREWYOU3_HOOK_IMPL(PurchaseItemPopup, init, item)
SCREWYOU3_HOOK_END("PurchaseItemPopup::init")

#include <Geode/modify/RandTriggerGameObject.hpp>
bool RandTriggerGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(RandTriggerGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(RandTriggerGameObject, init, )
SCREWYOU3_HOOK_END("RandTriggerGameObject::init")

#include <Geode/modify/RateDemonLayer.hpp>
bool RateDemonLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(RateDemonLayer)
SCREWYOU3_HOOK(bool init(int levelID))
SCREWYOU3_HOOK_IMPL(RateDemonLayer, init, levelID)
SCREWYOU3_HOOK_END("RateDemonLayer::init")

#include <Geode/modify/RateLevelLayer.hpp>
bool RateLevelLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(RateLevelLayer)
SCREWYOU3_HOOK(bool init(int levelID))
SCREWYOU3_HOOK_IMPL(RateLevelLayer, init, levelID)
SCREWYOU3_HOOK_END("RateLevelLayer::init")

#include <Geode/modify/RateStarsLayer.hpp>
bool RateStarsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(RateStarsLayer)
SCREWYOU3_HOOK(bool init(int levelID, bool platformer, bool moderator))
SCREWYOU3_HOOK_IMPL(RateStarsLayer, init, levelID, platformer, moderator)
SCREWYOU3_HOOK_END("RateStarsLayer::init")

#include <Geode/modify/RewardsPage.hpp>
bool RewardsPage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(RewardsPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(RewardsPage, init, )
SCREWYOU3_HOOK_END("RewardsPage::init")

#include <Geode/modify/RewardUnlockLayer.hpp>
bool RewardUnlockLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(RewardUnlockLayer)
SCREWYOU3_HOOK(bool init(int type, RewardsPage* page))
SCREWYOU3_HOOK_IMPL(RewardUnlockLayer, init, type, page)
SCREWYOU3_HOOK_END("RewardUnlockLayer::init")

#include <Geode/modify/RotateGameplayGameObject.hpp>
bool RotateGameplayGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(RotateGameplayGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(RotateGameplayGameObject, init, )
SCREWYOU3_HOOK_END("RotateGameplayGameObject::init")

#include <Geode/modify/SearchButton.hpp>
bool SearchButton_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SearchButton)
SCREWYOU3_HOOK(bool init(char const* background, char const* label, float scale, char const* icon))
SCREWYOU3_HOOK_IMPL(SearchButton, init, background, label, scale, icon)
SCREWYOU3_HOOK_END("SearchButton::init")

#include <Geode/modify/SearchSFXPopup.hpp>
bool SearchSFXPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SearchSFXPopup)
SCREWYOU3_HOOK(bool init(gd::string query))
SCREWYOU3_HOOK_IMPL(SearchSFXPopup, init, query)
SCREWYOU3_HOOK_END("SearchSFXPopup::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SecretGame01Layer.hpp>
bool SecretGame01Layer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SecretGame01Layer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretGame01Layer, init, )
SCREWYOU3_HOOK_END("SecretGame01Layer::init")
#endif

#include <Geode/modify/SecretLayer.hpp>
bool SecretLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SecretLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer, init, )
SCREWYOU3_HOOK_END("SecretLayer::init")

#include <Geode/modify/SecretLayer2.hpp>
bool SecretLayer2_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SecretLayer2)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer2, init, )
SCREWYOU3_HOOK_END("SecretLayer2::init")

#include <Geode/modify/SecretLayer3.hpp>
bool SecretLayer3_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SecretLayer3)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer3, init, )
SCREWYOU3_HOOK_END("SecretLayer3::init")

#include <Geode/modify/SecretLayer4.hpp>
bool SecretLayer4_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SecretLayer4)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer4, init, )
SCREWYOU3_HOOK_END("SecretLayer4::init")

#include <Geode/modify/SecretLayer5.hpp>
bool SecretLayer5_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SecretLayer5)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer5, init, )
SCREWYOU3_HOOK_END("SecretLayer5::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SecretLayer6.hpp>
bool SecretLayer6_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SecretLayer6)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer6, init, )
SCREWYOU3_HOOK_END("SecretLayer6::init")
#endif

#include <Geode/modify/SecretNumberLayer.hpp>
bool SecretNumberLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SecretNumberLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretNumberLayer, init, )
SCREWYOU3_HOOK_END("SecretNumberLayer::init")

#include <Geode/modify/SecretRewardsLayer.hpp>
bool SecretRewardsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SecretRewardsLayer)
SCREWYOU3_HOOK(bool init(bool fromShop))
SCREWYOU3_HOOK_IMPL(SecretRewardsLayer, init, fromShop)
SCREWYOU3_HOOK_END("SecretRewardsLayer::init")

#include <Geode/modify/SelectArtLayer.hpp>
bool SelectArtLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SelectArtLayer)
SCREWYOU3_HOOK(bool init(SelectArtType type, int index))
SCREWYOU3_HOOK_IMPL(SelectArtLayer, init, type, index)
SCREWYOU3_HOOK_END("SelectArtLayer::init")

#include <Geode/modify/SelectEventLayer.hpp>
bool SelectEventLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SelectEventLayer)
SCREWYOU3_HOOK(bool init(SetupEventLinkPopup* popup, gd::set<int>& eventIDs))
SCREWYOU3_HOOK_IMPL(SelectEventLayer, init, popup, eventIDs)
SCREWYOU3_HOOK_END("SelectEventLayer::init")

#include <Geode/modify/SelectFontLayer.hpp>
bool SelectFontLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SelectFontLayer)
SCREWYOU3_HOOK(bool init(LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(SelectFontLayer, init, layer)
SCREWYOU3_HOOK_END("SelectFontLayer::init")

#include <Geode/modify/SelectListIconLayer.hpp>
bool SelectListIconLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SelectListIconLayer)
SCREWYOU3_HOOK(bool init(int difficulty))
SCREWYOU3_HOOK_IMPL(SelectListIconLayer, init, difficulty)
SCREWYOU3_HOOK_END("SelectListIconLayer::init")

#include <Geode/modify/SelectPremadeLayer.hpp>
bool SelectPremadeLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SelectPremadeLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SelectPremadeLayer, init, )
SCREWYOU3_HOOK_END("SelectPremadeLayer::init")

#include <Geode/modify/SelectSettingLayer.hpp>
bool SelectSettingLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SelectSettingLayer)
SCREWYOU3_HOOK(bool init(SelectSettingType type, int value))
SCREWYOU3_HOOK_IMPL(SelectSettingLayer, init, type, value)
SCREWYOU3_HOOK_END("SelectSettingLayer::init")

#include <Geode/modify/SelectSFXSortLayer.hpp>
bool SelectSFXSortLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SelectSFXSortLayer)
SCREWYOU3_HOOK(bool init(AudioSortType sortType))
SCREWYOU3_HOOK_IMPL(SelectSFXSortLayer, init, sortType)
SCREWYOU3_HOOK_END("SelectSFXSortLayer::init")

#include <Geode/modify/SequenceTriggerGameObject.hpp>
bool SequenceTriggerGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SequenceTriggerGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SequenceTriggerGameObject, init, )
SCREWYOU3_HOOK_END("SequenceTriggerGameObject::init")

#include <Geode/modify/SetColorIDPopup.hpp>
bool SetColorIDPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetColorIDPopup)
SCREWYOU3_HOOK(bool init(int id))
SCREWYOU3_HOOK_IMPL(SetColorIDPopup, init, id)
SCREWYOU3_HOOK_END("SetColorIDPopup::init")

#include <Geode/modify/SetFolderPopup.hpp>
bool SetFolderPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetFolderPopup)
SCREWYOU3_HOOK(bool init(int value, bool isCreated, gd::string title))
SCREWYOU3_HOOK_IMPL(SetFolderPopup, init, value, isCreated, title)
SCREWYOU3_HOOK_END("SetFolderPopup::init")

#include <Geode/modify/SetGroupIDLayer.hpp>
bool SetGroupIDLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetGroupIDLayer)
SCREWYOU3_HOOK(bool init(GameObject* obj, cocos2d::CCArray* objs))
SCREWYOU3_HOOK_IMPL(SetGroupIDLayer, init, obj, objs)
SCREWYOU3_HOOK_END("SetGroupIDLayer::init")

#include <Geode/modify/SetIDPopup.hpp>
bool SetIDPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetIDPopup)
SCREWYOU3_HOOK(bool init(int current, int begin, int end, gd::string title, gd::string button, bool resetButton, int defaultValue, float offset, bool numberInput, bool arrows))
SCREWYOU3_HOOK_IMPL(SetIDPopup, init, current, begin, end, title, button, resetButton, defaultValue, offset, numberInput, arrows)
SCREWYOU3_HOOK_END("SetIDPopup::init")

#include <Geode/modify/SetItemIDLayer.hpp>
bool SetItemIDLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetItemIDLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetItemIDLayer, init, object, objects)
SCREWYOU3_HOOK_END("SetItemIDLayer::init")

#include <Geode/modify/SetLevelOrderPopup.hpp>
bool SetLevelOrderPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetLevelOrderPopup)
SCREWYOU3_HOOK(bool init(int levelID, int order, int amount))
SCREWYOU3_HOOK_IMPL(SetLevelOrderPopup, init, levelID, order, amount)
SCREWYOU3_HOOK_END("SetLevelOrderPopup::init")

#include <Geode/modify/SetTargetIDLayer.hpp>
bool SetTargetIDLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetTargetIDLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, gd::string title, gd::string label, int minimum, int maximum, int objectID))
SCREWYOU3_HOOK_IMPL(SetTargetIDLayer, init, object, objects, title, label, minimum, maximum, objectID)
SCREWYOU3_HOOK_END("SetTargetIDLayer::init")

#include <Geode/modify/SetTextPopup.hpp>
bool SetTextPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetTextPopup)
SCREWYOU3_HOOK(bool init(gd::string value, gd::string placeholder, int maxLength, gd::string title, gd::string okBtnText, bool showResetBtn, float offset))
SCREWYOU3_HOOK_IMPL(SetTextPopup, init, value, placeholder, maxLength, title, okBtnText, showResetBtn, offset)
SCREWYOU3_HOOK_END("SetTextPopup::init")

#include <Geode/modify/SetupAdvFollowEditPhysicsPopup.hpp>
bool SetupAdvFollowEditPhysicsPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAdvFollowEditPhysicsPopup)
SCREWYOU3_HOOK(bool init(AdvancedFollowEditObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAdvFollowEditPhysicsPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAdvFollowEditPhysicsPopup::init")

#include <Geode/modify/SetupAdvFollowPopup.hpp>
bool SetupAdvFollowPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAdvFollowPopup)
SCREWYOU3_HOOK(bool init(AdvancedFollowTriggerObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAdvFollowPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAdvFollowPopup::init")

#include <Geode/modify/SetupAdvFollowRetargetPopup.hpp>
bool SetupAdvFollowRetargetPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAdvFollowRetargetPopup)
SCREWYOU3_HOOK(bool init(AdvancedFollowEditObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAdvFollowRetargetPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAdvFollowRetargetPopup::init")

#include <Geode/modify/SetupAnimationPopup.hpp>
bool SetupAnimationPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAnimationPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAnimationPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAnimationPopup::init")

#include <Geode/modify/SetupAnimSettingsPopup.hpp>
bool SetupAnimSettingsPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAnimSettingsPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAnimSettingsPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAnimSettingsPopup::init")

#include <Geode/modify/SetupAreaAnimTriggerPopup.hpp>
bool SetupAreaAnimTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAreaAnimTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupAreaAnimTriggerPopup, init, object, objects, id)
SCREWYOU3_HOOK_END("SetupAreaAnimTriggerPopup::init")

#include <Geode/modify/SetupAreaFadeTriggerPopup.hpp>
bool SetupAreaFadeTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAreaFadeTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaFadeTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAreaFadeTriggerPopup::init")

#include <Geode/modify/SetupAreaMoveTriggerPopup.hpp>
bool SetupAreaMoveTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAreaMoveTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaMoveTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAreaMoveTriggerPopup::init")

#include <Geode/modify/SetupAreaRotateTriggerPopup.hpp>
bool SetupAreaRotateTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAreaRotateTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaRotateTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAreaRotateTriggerPopup::init")

#include <Geode/modify/SetupAreaTintTriggerPopup.hpp>
bool SetupAreaTintTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAreaTintTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaTintTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAreaTintTriggerPopup::init")

#include <Geode/modify/SetupAreaTransformTriggerPopup.hpp>
bool SetupAreaTransformTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAreaTransformTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaTransformTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAreaTransformTriggerPopup::init")

#include <Geode/modify/SetupAreaTriggerPopup.hpp>
bool SetupAreaTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAreaTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAreaTriggerPopup::init")

#include <Geode/modify/SetupArtSwitchPopup.hpp>
bool SetupArtSwitchPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupArtSwitchPopup)
SCREWYOU3_HOOK(bool init(ArtTriggerGameObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupArtSwitchPopup, init, object, objects, id)
SCREWYOU3_HOOK_END("SetupArtSwitchPopup::init")

#include <Geode/modify/SetupAudioLineGuidePopup.hpp>
bool SetupAudioLineGuidePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupAudioLineGuidePopup)
SCREWYOU3_HOOK(bool init(AudioLineGuideGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAudioLineGuidePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupAudioLineGuidePopup::init")

#include <Geode/modify/SetupBGSpeedTrigger.hpp>
bool SetupBGSpeedTrigger_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupBGSpeedTrigger)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupBGSpeedTrigger, init, object, objects, id)
SCREWYOU3_HOOK_END("SetupBGSpeedTrigger::init")

#include <Geode/modify/SetupCameraEdgePopup.hpp>
bool SetupCameraEdgePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupCameraEdgePopup)
SCREWYOU3_HOOK(bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraEdgePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCameraEdgePopup::init")

#include <Geode/modify/SetupCameraGuidePopup.hpp>
bool SetupCameraGuidePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupCameraGuidePopup)
SCREWYOU3_HOOK(bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraGuidePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCameraGuidePopup::init")

#include <Geode/modify/SetupCameraModePopup.hpp>
bool SetupCameraModePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupCameraModePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraModePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCameraModePopup::init")

#include <Geode/modify/SetupCameraOffsetTrigger.hpp>
bool SetupCameraOffsetTrigger_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupCameraOffsetTrigger)
SCREWYOU3_HOOK(bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraOffsetTrigger, init, object, objects)
SCREWYOU3_HOOK_END("SetupCameraOffsetTrigger::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupCameraRotatePopup.hpp>
bool SetupCameraRotatePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupCameraRotatePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraRotatePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCameraRotatePopup::init")
#endif

#include <Geode/modify/SetupCameraRotatePopup2.hpp>
bool SetupCameraRotatePopup2_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupCameraRotatePopup2)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraRotatePopup2, init, object, objects)
SCREWYOU3_HOOK_END("SetupCameraRotatePopup2::init")

#include <Geode/modify/SetupCheckpointPopup.hpp>
bool SetupCheckpointPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupCheckpointPopup)
SCREWYOU3_HOOK(bool init(CheckpointGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCheckpointPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCheckpointPopup::init")

#include <Geode/modify/SetupCoinLayer.hpp>
bool SetupCoinLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupCoinLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCoinLayer, init, object, objects)
SCREWYOU3_HOOK_END("SetupCoinLayer::init")

#include <Geode/modify/SetupCollisionStateTriggerPopup.hpp>
bool SetupCollisionStateTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupCollisionStateTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCollisionStateTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCollisionStateTriggerPopup::init")

#include <Geode/modify/SetupCollisionTriggerPopup.hpp>
bool SetupCollisionTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupCollisionTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCollisionTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCollisionTriggerPopup::init")

#include <Geode/modify/SetupCountTriggerPopup.hpp>
bool SetupCountTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupCountTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCountTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupCountTriggerPopup::init")

#include <Geode/modify/SetupDashRingPopup.hpp>
bool SetupDashRingPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupDashRingPopup)
SCREWYOU3_HOOK(bool init(DashRingObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupDashRingPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupDashRingPopup::init")

#include <Geode/modify/SetupEndPopup.hpp>
bool SetupEndPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupEndPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupEndPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupEndPopup::init")

#include <Geode/modify/SetupEnterEffectPopup.hpp>
bool SetupEnterEffectPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupEnterEffectPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupEnterEffectPopup, init, object, objects, id)
SCREWYOU3_HOOK_END("SetupEnterEffectPopup::init")

#include <Geode/modify/SetupEnterTriggerPopup.hpp>
bool SetupEnterTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupEnterTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupEnterTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupEnterTriggerPopup::init")

#include <Geode/modify/SetupEventLinkPopup.hpp>
bool SetupEventLinkPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupEventLinkPopup)
SCREWYOU3_HOOK(bool init(EventLinkTrigger* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupEventLinkPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupEventLinkPopup::init")

#include <Geode/modify/SetupForceBlockPopup.hpp>
bool SetupForceBlockPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupForceBlockPopup)
SCREWYOU3_HOOK(bool init(ForceBlockGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupForceBlockPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupForceBlockPopup::init")

#include <Geode/modify/SetupGameplayOffsetPopup.hpp>
bool SetupGameplayOffsetPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupGameplayOffsetPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupGameplayOffsetPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupGameplayOffsetPopup::init")

#include <Geode/modify/SetupGradientPopup.hpp>
bool SetupGradientPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupGradientPopup)
SCREWYOU3_HOOK(bool init(GradientTriggerObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupGradientPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupGradientPopup::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupGravityModPopup.hpp>
bool SetupGravityModPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupGravityModPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, bool gravityTrigger))
SCREWYOU3_HOOK_IMPL(SetupGravityModPopup, init, object, objects, gravityTrigger)
SCREWYOU3_HOOK_END("SetupGravityModPopup::init")
#endif

#include <Geode/modify/SetupGravityTriggerPopup.hpp>
bool SetupGravityTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupGravityTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupGravityTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupGravityTriggerPopup::init")

#include <Geode/modify/SetupInstantCollisionTriggerPopup.hpp>
bool SetupInstantCollisionTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupInstantCollisionTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupInstantCollisionTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupInstantCollisionTriggerPopup::init")

#include <Geode/modify/SetupInstantCountPopup.hpp>
bool SetupInstantCountPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupInstantCountPopup)
SCREWYOU3_HOOK(bool init(CountTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupInstantCountPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupInstantCountPopup::init")

#include <Geode/modify/SetupInteractObjectPopup.hpp>
bool SetupInteractObjectPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupInteractObjectPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupInteractObjectPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupInteractObjectPopup::init")

#include <Geode/modify/SetupItemCompareTriggerPopup.hpp>
bool SetupItemCompareTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupItemCompareTriggerPopup)
SCREWYOU3_HOOK(bool init(ItemTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupItemCompareTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupItemCompareTriggerPopup::init")

#include <Geode/modify/SetupItemEditTriggerPopup.hpp>
bool SetupItemEditTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupItemEditTriggerPopup)
SCREWYOU3_HOOK(bool init(ItemTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupItemEditTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupItemEditTriggerPopup::init")

#include <Geode/modify/SetupKeyframeAnimPopup.hpp>
bool SetupKeyframeAnimPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupKeyframeAnimPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupKeyframeAnimPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupKeyframeAnimPopup::init")

#include <Geode/modify/SetupKeyframePopup.hpp>
bool SetupKeyframePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupKeyframePopup)
SCREWYOU3_HOOK(bool init(KeyframeGameObject* object, cocos2d::CCArray* objects, LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(SetupKeyframePopup, init, object, objects, layer)
SCREWYOU3_HOOK_END("SetupKeyframePopup::init")

#include <Geode/modify/SetupMGTrigger.hpp>
bool SetupMGTrigger_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupMGTrigger)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupMGTrigger, init, object, objects)
SCREWYOU3_HOOK_END("SetupMGTrigger::init")

#include <Geode/modify/SetupMoveCommandPopup.hpp>
bool SetupMoveCommandPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupMoveCommandPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupMoveCommandPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupMoveCommandPopup::init")

#include <Geode/modify/SetupObjectControlPopup.hpp>
bool SetupObjectControlPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupObjectControlPopup)
SCREWYOU3_HOOK(bool init(ObjectControlGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupObjectControlPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupObjectControlPopup::init")

#include <Geode/modify/SetupObjectOptions2Popup.hpp>
bool SetupObjectOptions2Popup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupObjectOptions2Popup)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupObjectOptions2Popup, init, object, objects)
SCREWYOU3_HOOK_END("SetupObjectOptions2Popup::init")

#include <Geode/modify/SetupObjectOptionsPopup.hpp>
bool SetupObjectOptionsPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupObjectOptionsPopup)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects, SetGroupIDLayer* layer))
SCREWYOU3_HOOK_IMPL(SetupObjectOptionsPopup, init, object, objects, layer)
SCREWYOU3_HOOK_END("SetupObjectOptionsPopup::init")

#include <Geode/modify/SetupObjectTogglePopup.hpp>
bool SetupObjectTogglePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupObjectTogglePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, bool platformer))
SCREWYOU3_HOOK_IMPL(SetupObjectTogglePopup, init, object, objects, platformer)
SCREWYOU3_HOOK_END("SetupObjectTogglePopup::init")

#include <Geode/modify/SetupOpacityPopup.hpp>
bool SetupOpacityPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupOpacityPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupOpacityPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupOpacityPopup::init")

#include <Geode/modify/SetupOptionsTriggerPopup.hpp>
bool SetupOptionsTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupOptionsTriggerPopup)
SCREWYOU3_HOOK(bool init(GameOptionsTrigger* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupOptionsTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupOptionsTriggerPopup::init")

#include <Geode/modify/SetupPersistentItemTriggerPopup.hpp>
bool SetupPersistentItemTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupPersistentItemTriggerPopup)
SCREWYOU3_HOOK(bool init(ItemTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPersistentItemTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupPersistentItemTriggerPopup::init")

#include <Geode/modify/SetupPickupTriggerPopup.hpp>
bool SetupPickupTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupPickupTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPickupTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupPickupTriggerPopup::init")

#include <Geode/modify/SetupPlatformerEndPopup.hpp>
bool SetupPlatformerEndPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupPlatformerEndPopup)
SCREWYOU3_HOOK(bool init(EndTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPlatformerEndPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupPlatformerEndPopup::init")

#include <Geode/modify/SetupPlayerControlPopup.hpp>
bool SetupPlayerControlPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupPlayerControlPopup)
SCREWYOU3_HOOK(bool init(PlayerControlGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPlayerControlPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupPlayerControlPopup::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupPortalPopup.hpp>
bool SetupPortalPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupPortalPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPortalPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupPortalPopup::init")
#endif

#include <Geode/modify/SetupPulsePopup.hpp>
bool SetupPulsePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupPulsePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPulsePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupPulsePopup::init")

#include <Geode/modify/SetupRandAdvTriggerPopup.hpp>
bool SetupRandAdvTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupRandAdvTriggerPopup)
SCREWYOU3_HOOK(bool init(RandTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRandAdvTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupRandAdvTriggerPopup::init")

#include <Geode/modify/SetupRandTriggerPopup.hpp>
bool SetupRandTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupRandTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRandTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupRandTriggerPopup::init")

#include <Geode/modify/SetupResetTriggerPopup.hpp>
bool SetupResetTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupResetTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupResetTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupResetTriggerPopup::init")

#include <Geode/modify/SetupReverbPopup.hpp>
bool SetupReverbPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupReverbPopup)
SCREWYOU3_HOOK(bool init(SFXTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupReverbPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupReverbPopup::init")

#include <Geode/modify/SetupRotateCommandPopup.hpp>
bool SetupRotateCommandPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupRotateCommandPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRotateCommandPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupRotateCommandPopup::init")

#include <Geode/modify/SetupRotateGameplayPopup.hpp>
bool SetupRotateGameplayPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupRotateGameplayPopup)
SCREWYOU3_HOOK(bool init(RotateGameplayGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRotateGameplayPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupRotateGameplayPopup::init")

#include <Geode/modify/SetupRotatePopup.hpp>
bool SetupRotatePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupRotatePopup)
SCREWYOU3_HOOK(bool init(EnhancedGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRotatePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupRotatePopup::init")

#include <Geode/modify/SetupSequenceTriggerPopup.hpp>
bool SetupSequenceTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupSequenceTriggerPopup)
SCREWYOU3_HOOK(bool init(SequenceTriggerGameObject* object))
SCREWYOU3_HOOK_IMPL(SetupSequenceTriggerPopup, init, object)
SCREWYOU3_HOOK_END("SetupSequenceTriggerPopup::init")

#include <Geode/modify/SetupSFXEditPopup.hpp>
bool SetupSFXEditPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupSFXEditPopup)
SCREWYOU3_HOOK(bool init(SFXTriggerGameObject* object, cocos2d::CCArray* objects, bool songTrigger))
SCREWYOU3_HOOK_IMPL(SetupSFXEditPopup, init, object, objects, songTrigger)
SCREWYOU3_HOOK_END("SetupSFXEditPopup::init")

#include <Geode/modify/SetupSFXPopup.hpp>
bool SetupSFXPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupSFXPopup)
SCREWYOU3_HOOK(bool init(SFXTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSFXPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupSFXPopup::init")

#include <Geode/modify/SetupShaderEffectPopup.hpp>
bool SetupShaderEffectPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupShaderEffectPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupShaderEffectPopup, init, object, objects, id)
SCREWYOU3_HOOK_END("SetupShaderEffectPopup::init")

#include <Geode/modify/SetupShakePopup.hpp>
bool SetupShakePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupShakePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupShakePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupShakePopup::init")

#include <Geode/modify/SetupSmartBlockLayer.hpp>
bool SetupSmartBlockLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupSmartBlockLayer)
SCREWYOU3_HOOK(bool init(SmartGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSmartBlockLayer, init, object, objects)
SCREWYOU3_HOOK_END("SetupSmartBlockLayer::init")

#include <Geode/modify/SetupSmartTemplateLayer.hpp>
bool SetupSmartTemplateLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupSmartTemplateLayer)
SCREWYOU3_HOOK(bool init(GJSmartTemplate* smartTemplate))
SCREWYOU3_HOOK_IMPL(SetupSmartTemplateLayer, init, smartTemplate)
SCREWYOU3_HOOK_END("SetupSmartTemplateLayer::init")

#include <Geode/modify/SetupSongTriggerPopup.hpp>
bool SetupSongTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupSongTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSongTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupSongTriggerPopup::init")

#include <Geode/modify/SetupSpawnParticlePopup.hpp>
bool SetupSpawnParticlePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupSpawnParticlePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSpawnParticlePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupSpawnParticlePopup::init")

#include <Geode/modify/SetupSpawnPopup.hpp>
bool SetupSpawnPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupSpawnPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSpawnPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupSpawnPopup::init")

#include <Geode/modify/SetupStaticCameraPopup.hpp>
bool SetupStaticCameraPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupStaticCameraPopup)
SCREWYOU3_HOOK(bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupStaticCameraPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupStaticCameraPopup::init")

#include <Geode/modify/SetupStopTriggerPopup.hpp>
bool SetupStopTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupStopTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupStopTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupStopTriggerPopup::init")

#include <Geode/modify/SetupTeleportPopup.hpp>
bool SetupTeleportPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupTeleportPopup)
SCREWYOU3_HOOK(bool init(TeleportPortalObject* object, cocos2d::CCArray* objects, int id, bool platformer))
SCREWYOU3_HOOK_IMPL(SetupTeleportPopup, init, object, objects, id, platformer)
SCREWYOU3_HOOK_END("SetupTeleportPopup::init")

#include <Geode/modify/SetupTimerControlTriggerPopup.hpp>
bool SetupTimerControlTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupTimerControlTriggerPopup)
SCREWYOU3_HOOK(bool init(TimerTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTimerControlTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupTimerControlTriggerPopup::init")

#include <Geode/modify/SetupTimerEventTriggerPopup.hpp>
bool SetupTimerEventTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupTimerEventTriggerPopup)
SCREWYOU3_HOOK(bool init(TimerTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTimerEventTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupTimerEventTriggerPopup::init")

#include <Geode/modify/SetupTimerTriggerPopup.hpp>
bool SetupTimerTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupTimerTriggerPopup)
SCREWYOU3_HOOK(bool init(TimerTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTimerTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupTimerTriggerPopup::init")

#include <Geode/modify/SetupTimeWarpPopup.hpp>
bool SetupTimeWarpPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupTimeWarpPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTimeWarpPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupTimeWarpPopup::init")

#include <Geode/modify/SetupTouchTogglePopup.hpp>
bool SetupTouchTogglePopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupTouchTogglePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTouchTogglePopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupTouchTogglePopup::init")

#include <Geode/modify/SetupTransformPopup.hpp>
bool SetupTransformPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupTransformPopup)
SCREWYOU3_HOOK(bool init(TransformTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTransformPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupTransformPopup::init")

#include <Geode/modify/SetupTriggerPopup.hpp>
bool SetupTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* trigger, cocos2d::CCArray* triggers, float width, float height, int background))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, init, trigger, triggers, width, height, background)
SCREWYOU3_HOOK_END("SetupTriggerPopup::init")

#include <Geode/modify/SetupZoomTriggerPopup.hpp>
bool SetupZoomTriggerPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SetupZoomTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupZoomTriggerPopup, init, object, objects)
SCREWYOU3_HOOK_END("SetupZoomTriggerPopup::init")

#include <Geode/modify/SFXBrowser.hpp>
bool SFXBrowser_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SFXBrowser)
SCREWYOU3_HOOK(bool init(int id))
SCREWYOU3_HOOK_IMPL(SFXBrowser, init, id)
SCREWYOU3_HOOK_END("SFXBrowser::init")

#include <Geode/modify/ShaderLayer.hpp>
bool ShaderLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ShaderLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ShaderLayer, init, )
SCREWYOU3_HOOK_END("ShaderLayer::init")

#include <Geode/modify/ShardsPage.hpp>
bool ShardsPage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ShardsPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ShardsPage, init, )
SCREWYOU3_HOOK_END("ShardsPage::init")

#include <Geode/modify/ShareCommentLayer.hpp>
bool ShareCommentLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ShareCommentLayer)
SCREWYOU3_HOOK(bool init(gd::string title, int charLimit, CommentType type, int ID, gd::string desc))
SCREWYOU3_HOOK_IMPL(ShareCommentLayer, init, title, charLimit, type, ID, desc)
SCREWYOU3_HOOK_END("ShareCommentLayer::init")

#include <Geode/modify/ShareLevelLayer.hpp>
bool ShareLevelLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ShareLevelLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(ShareLevelLayer, init, level)
SCREWYOU3_HOOK_END("ShareLevelLayer::init")

#include <Geode/modify/ShareLevelSettingsLayer.hpp>
bool ShareLevelSettingsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ShareLevelSettingsLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(ShareLevelSettingsLayer, init, level)
SCREWYOU3_HOOK_END("ShareLevelSettingsLayer::init")

#include <Geode/modify/ShareListLayer.hpp>
bool ShareListLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(ShareListLayer)
SCREWYOU3_HOOK(bool init(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(ShareListLayer, init, list)
SCREWYOU3_HOOK_END("ShareListLayer::init")

#include <Geode/modify/SimplePlayer.hpp>
bool SimplePlayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SimplePlayer)
SCREWYOU3_HOOK(bool init(int id))
SCREWYOU3_HOOK_IMPL(SimplePlayer, init, id)
SCREWYOU3_HOOK_END("SimplePlayer::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SlideInLayer.hpp>
bool SlideInLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SlideInLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SlideInLayer, init, )
SCREWYOU3_HOOK_END("SlideInLayer::init")
#endif

#include <Geode/modify/Slider.hpp>
bool Slider_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(Slider)
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler, char const* bar, char const* groove, char const* thumb, char const* thumbSel, float scale))
SCREWYOU3_HOOK_IMPL(Slider, init, target, handler, bar, groove, thumb, thumbSel, scale)
SCREWYOU3_HOOK_END("Slider::init")

#include <Geode/modify/SmartTemplateCell.hpp>
bool SmartTemplateCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SmartTemplateCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SmartTemplateCell, init, )
SCREWYOU3_HOOK_END("SmartTemplateCell::init")

#include <Geode/modify/SongCell.hpp>
bool SongCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SongCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SongCell, init, )
SCREWYOU3_HOOK_END("SongCell::init")

#include <Geode/modify/SongInfoLayer.hpp>
bool SongInfoLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SongInfoLayer)
SCREWYOU3_HOOK(bool init(gd::string songName, gd::string artistName, gd::string songURL, gd::string newgroundsURL, gd::string youtubeURL, gd::string facebookURL, int songID, gd::string songTags, int nongType))
SCREWYOU3_HOOK_IMPL(SongInfoLayer, init, songName, artistName, songURL, newgroundsURL, youtubeURL, facebookURL, songID, songTags, nongType)
SCREWYOU3_HOOK_END("SongInfoLayer::init")

#include <Geode/modify/SongInfoObject.hpp>
bool SongInfoObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SongInfoObject)
SCREWYOU3_HOOK(bool init(int songID, gd::string songName, gd::string artistName, int artistID, float filesize, gd::string youtubeVideo, gd::string youtubeChannel, gd::string url, int nongType, gd::string extraArtistIDs, bool isNew, int libraryOrder, int priority))
SCREWYOU3_HOOK_IMPL(SongInfoObject, init, songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, nongType, extraArtistIDs, isNew, libraryOrder, priority)
SCREWYOU3_HOOK_END("SongInfoObject::init")

#include <Geode/modify/SongOptionsLayer.hpp>
bool SongOptionsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SongOptionsLayer)
SCREWYOU3_HOOK(bool init(CustomSongDelegate* delegate))
SCREWYOU3_HOOK_IMPL(SongOptionsLayer, init, delegate)
SCREWYOU3_HOOK_END("SongOptionsLayer::init")

#include <Geode/modify/SongSelectNode.hpp>
bool SongSelectNode_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SongSelectNode)
SCREWYOU3_HOOK(bool init(int id, bool customSong, LevelSettingsObject* settings, SongSelectType selectType, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCMenu* menu, bool noLabel))
SCREWYOU3_HOOK_IMPL(SongSelectNode, init, id, customSong, settings, selectType, position, parent, menu, noLabel)
SCREWYOU3_HOOK_END("SongSelectNode::init")

#include <Geode/modify/SpawnParticleGameObject.hpp>
bool SpawnParticleGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SpawnParticleGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SpawnParticleGameObject, init, )
SCREWYOU3_HOOK_END("SpawnParticleGameObject::init")

#include <Geode/modify/SpawnTriggerGameObject.hpp>
bool SpawnTriggerGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(SpawnTriggerGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SpawnTriggerGameObject, init, )
SCREWYOU3_HOOK_END("SpawnTriggerGameObject::init")

#include <Geode/modify/StarInfoPopup.hpp>
bool StarInfoPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(StarInfoPopup)
SCREWYOU3_HOOK(bool init(int autos, int easies, int normals, int hards, int harders, int insanes, int dailies, int gauntlets, int maps, bool platformer))
SCREWYOU3_HOOK_IMPL(StarInfoPopup, init, autos, easies, normals, hards, harders, insanes, dailies, gauntlets, maps, platformer)
SCREWYOU3_HOOK_END("StarInfoPopup::init")

#include <Geode/modify/StartPosObject.hpp>
bool StartPosObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(StartPosObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(StartPosObject, init, )
SCREWYOU3_HOOK_END("StartPosObject::init")

#include <Geode/modify/TextAlertPopup.hpp>
bool TextAlertPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(TextAlertPopup)
SCREWYOU3_HOOK(bool init(gd::string text, float delay, float scale, int opacity, gd::string font))
SCREWYOU3_HOOK_IMPL(TextAlertPopup, init, text, delay, scale, opacity, font)
SCREWYOU3_HOOK_END("TextAlertPopup::init")

#include <Geode/modify/TopArtistsLayer.hpp>
bool TopArtistsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(TopArtistsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(TopArtistsLayer, init, )
SCREWYOU3_HOOK_END("TopArtistsLayer::init")

#include <Geode/modify/TOSPopup.hpp>
bool TOSPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(TOSPopup)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(TOSPopup, init, )
SCREWYOU3_HOOK_END("TOSPopup::init")

#include <Geode/modify/TutorialLayer.hpp>
bool TutorialLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(TutorialLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(TutorialLayer, init, )
SCREWYOU3_HOOK_END("TutorialLayer::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/TutorialPopup.hpp>
bool TutorialPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(TutorialPopup)
SCREWYOU3_HOOK(bool init(gd::string frame))
SCREWYOU3_HOOK_IMPL(TutorialPopup, init, frame)
SCREWYOU3_HOOK_END("TutorialPopup::init")
#endif

#include <Geode/modify/UILayer.hpp>
bool UILayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(UILayer)
SCREWYOU3_HOOK(bool init(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(UILayer, init, layer)
SCREWYOU3_HOOK_END("UILayer::init")

#include <Geode/modify/UIObjectSettingsPopup.hpp>
bool UIObjectSettingsPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(UIObjectSettingsPopup)
SCREWYOU3_HOOK(bool init(UISettingsGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(UIObjectSettingsPopup, init, object, objects)
SCREWYOU3_HOOK_END("UIObjectSettingsPopup::init")

#include <Geode/modify/UIOptionsLayer.hpp>
bool UIOptionsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(UIOptionsLayer)
SCREWYOU3_HOOK(bool init(bool dual))
SCREWYOU3_HOOK_IMPL(UIOptionsLayer, init, dual)
SCREWYOU3_HOOK_END("UIOptionsLayer::init")

#include <Geode/modify/UIPOptionsLayer.hpp>
bool UIPOptionsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(UIPOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(UIPOptionsLayer, init, )
SCREWYOU3_HOOK_END("UIPOptionsLayer::init")

#include <Geode/modify/UISaveLoadLayer.hpp>
bool UISaveLoadLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(UISaveLoadLayer)
SCREWYOU3_HOOK(bool init(UIOptionsLayer* layer))
SCREWYOU3_HOOK_IMPL(UISaveLoadLayer, init, layer)
SCREWYOU3_HOOK_END("UISaveLoadLayer::init")

#include <Geode/modify/UISettingsGameObject.hpp>
bool UISettingsGameObject_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(UISettingsGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(UISettingsGameObject, init, )
SCREWYOU3_HOOK_END("UISettingsGameObject::init")

#include <Geode/modify/UpdateAccountSettingsPopup.hpp>
bool UpdateAccountSettingsPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(UpdateAccountSettingsPopup)
SCREWYOU3_HOOK(bool init(GJAccountSettingsLayer* settingsLayer, int messageStatus, int friendStatus, int commentStatus, gd::string youtubeURL, gd::string twitterURL, gd::string twitchURL))
SCREWYOU3_HOOK_IMPL(UpdateAccountSettingsPopup, init, settingsLayer, messageStatus, friendStatus, commentStatus, youtubeURL, twitterURL, twitchURL)
SCREWYOU3_HOOK_END("UpdateAccountSettingsPopup::init")

#include <Geode/modify/UploadActionPopup.hpp>
bool UploadActionPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(UploadActionPopup)
SCREWYOU3_HOOK(bool init(UploadPopupDelegate* delegate, gd::string str))
SCREWYOU3_HOOK_IMPL(UploadActionPopup, init, delegate, str)
SCREWYOU3_HOOK_END("UploadActionPopup::init")

#include <Geode/modify/UploadListPopup.hpp>
bool UploadListPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(UploadListPopup)
SCREWYOU3_HOOK(bool init(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(UploadListPopup, init, list)
SCREWYOU3_HOOK_END("UploadListPopup::init")

#include <Geode/modify/UploadPopup.hpp>
bool UploadPopup_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(UploadPopup)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(UploadPopup, init, level)
SCREWYOU3_HOOK_END("UploadPopup::init")

#include <Geode/modify/URLCell.hpp>
bool URLCell_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(URLCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(URLCell, init, )
SCREWYOU3_HOOK_END("URLCell::init")

#include <Geode/modify/VideoOptionsLayer.hpp>
bool VideoOptionsLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(VideoOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(VideoOptionsLayer, init, )
SCREWYOU3_HOOK_END("VideoOptionsLayer::init")


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/WorldLevelPage.hpp>
bool WorldLevelPage_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(WorldLevelPage)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, GJWorldNode* node))
SCREWYOU3_HOOK_IMPL(WorldLevelPage, init, level, node)
SCREWYOU3_HOOK_END("WorldLevelPage::init")
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/WorldSelectLayer.hpp>
bool WorldSelectLayer_init_override() {
if (modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("gibberish-data-chance")))
	return modUtils::chooseRandomNum(0, 1);
return  bool();
}

SCREWYOU3_HOOK_BEGIN(WorldSelectLayer)
SCREWYOU3_HOOK(bool init(int page))
SCREWYOU3_HOOK_IMPL(WorldSelectLayer, init, page)
SCREWYOU3_HOOK_END("WorldSelectLayer::init")
#endif

