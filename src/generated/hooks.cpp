// Generated using 'generate.py'
#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include "../ScrewYou3Manager.hpp"
#include "../utils.hpp"

using namespace geode::prelude;

// Cursed macros but whatever, this isn't supposed to be the most readable thing after all
// Also haii !!!
// :3

#define SCREWYOU3_MENULAYER_CUSTOM_INIT(className, funcName, platforms, ...) \
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
#define SCREWYOU3_HOOK_IMPL(className, funcName, platforms, ...) \
    if (Mod::get()->getSettingValue<bool>("log-more")) \
        log::info("{}::{}({}) got called :3 (platforms = {})", className::CLASS_NAME, #funcName, #__VA_ARGS__, platforms); \
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
SCREWYOU3_HOOK_IMPL(AccountLoginLayer, init, "m1 android imac win ios", username)
SCREWYOU3_HOOK_END("AccountLoginLayer::init")

#include <Geode/modify/AccountRegisterLayer.hpp>

bool AccountRegisterLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool AccountRegisterLayer_allowTextInput_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool AccountRegisterLayer_validEmail_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool AccountRegisterLayer_validPassword_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool AccountRegisterLayer_validUser_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AccountRegisterLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(AccountRegisterLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool allowTextInput(CCTextInputNode* node))
SCREWYOU3_HOOK_IMPL(AccountRegisterLayer, allowTextInput, "m1 android imac win ios", node)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool validEmail(gd::string email))
SCREWYOU3_HOOK_IMPL(AccountRegisterLayer, validEmail, "m1 android imac win", email)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool validPassword(gd::string password))
SCREWYOU3_HOOK_IMPL(AccountRegisterLayer, validPassword, " m1 android imac", password)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool validUser(gd::string username))
SCREWYOU3_HOOK_IMPL(AccountRegisterLayer, validUser, " m1 android imac", username)
#endif
SCREWYOU3_HOOK_END("AccountRegisterLayer::init")

#include <Geode/modify/AchievementBar.hpp>

bool AchievementBar_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AchievementBar)
SCREWYOU3_HOOK(bool init(char const* title, char const* desc, char const* icon, bool quest))
SCREWYOU3_HOOK_IMPL(AchievementBar, init, "m1 android imac win ios", title, desc, icon, quest)
SCREWYOU3_HOOK_END("AchievementBar::init")

#include <Geode/modify/AchievementCell.hpp>

bool AchievementCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AchievementCell)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(AchievementCell, init, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("AchievementCell::init")

#include <Geode/modify/AchievementManager.hpp>

bool AchievementManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string AchievementManager_achievementForUnlock_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool AchievementManager_areAchievementsEarned_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool AchievementManager_isAchievementAvailable_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool AchievementManager_isAchievementEarned_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int AchievementManager_limitForAchievement_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int AchievementManager_percentageForCount_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int AchievementManager_percentForAchievement_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(AchievementManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(AchievementManager, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string achievementForUnlock(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(AchievementManager, achievementForUnlock, "m1 android imac win ios", id, type)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool areAchievementsEarned(cocos2d::CCArray* achievements))
SCREWYOU3_HOOK_IMPL(AchievementManager, areAchievementsEarned, " m1 android imac", achievements)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isAchievementAvailable(gd::string id))
SCREWYOU3_HOOK_IMPL(AchievementManager, isAchievementAvailable, " m1 android imac", id)
#endif
SCREWYOU3_HOOK(bool isAchievementEarned(char const* ach))
SCREWYOU3_HOOK_IMPL(AchievementManager, isAchievementEarned, "m1 android imac win ios", ach)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int limitForAchievement(gd::string id))
SCREWYOU3_HOOK_IMPL(AchievementManager, limitForAchievement, " m1 android imac ios", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int percentageForCount(int count, int total))
SCREWYOU3_HOOK_IMPL(AchievementManager, percentageForCount, " m1 android imac", count, total)
#endif
SCREWYOU3_HOOK(int percentForAchievement(char const* id))
SCREWYOU3_HOOK_IMPL(AchievementManager, percentForAchievement, "m1 android imac win ios", id)
SCREWYOU3_HOOK_END("AchievementManager::init")

#include <Geode/modify/AchievementNotifier.hpp>

bool AchievementNotifier_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AchievementNotifier)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(AchievementNotifier, init, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(AdToolbox, hasCachedInterstitial, "m1 imac android", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool hasCachedRewardedVideo())
SCREWYOU3_HOOK_IMPL(AdToolbox, hasCachedRewardedVideo, "m1 imac android", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool isShowingAd())
SCREWYOU3_HOOK_IMPL(AdToolbox, isShowingAd, "m1 imac android", )
#endif
SCREWYOU3_HOOK_END("AdToolbox::hasCachedInterstitial")

#include <Geode/modify/AdvancedFollowEditObject.hpp>

gd::string AdvancedFollowEditObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool AdvancedFollowEditObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AdvancedFollowEditObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(AdvancedFollowEditObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(AdvancedFollowEditObject, init, " m1 android imac", frame)
#endif
SCREWYOU3_HOOK_END("AdvancedFollowEditObject::getSaveString")

#include <Geode/modify/AdvancedFollowTriggerObject.hpp>

gd::string AdvancedFollowTriggerObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int AdvancedFollowTriggerObject_getAdvancedFollowID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool AdvancedFollowTriggerObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AdvancedFollowTriggerObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(AdvancedFollowTriggerObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getAdvancedFollowID())
SCREWYOU3_HOOK_IMPL(AdvancedFollowTriggerObject, getAdvancedFollowID, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(AdvancedFollowTriggerObject, init, " m1 android imac", frame)
#endif
SCREWYOU3_HOOK_END("AdvancedFollowTriggerObject::getSaveString")

#include <Geode/modify/AnimatedGameObject.hpp>

gd::string AnimatedGameObject_animationForID_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float AnimatedGameObject_getTweenTime_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool AnimatedGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AnimatedGameObject)
SCREWYOU3_HOOK(static gd::string animationForID(int type, int id))
SCREWYOU3_HOOK_IMPL(AnimatedGameObject, animationForID, "m1 android imac win ios", type, id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static float getTweenTime(int type, int id))
SCREWYOU3_HOOK_IMPL(AnimatedGameObject, getTweenTime, " m1 android imac", type, id)
#endif
SCREWYOU3_HOOK(bool init(int id))
SCREWYOU3_HOOK_IMPL(AnimatedGameObject, init, "m1 android imac win ios", id)
SCREWYOU3_HOOK_END("AnimatedGameObject::animationForID")

#include <Geode/modify/AnimatedShopKeeper.hpp>

bool AnimatedShopKeeper_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AnimatedShopKeeper)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(ShopType type))
SCREWYOU3_HOOK_IMPL(AnimatedShopKeeper, init, " m1 android imac ios", type)
#endif
SCREWYOU3_HOOK_END("AnimatedShopKeeper::init")

#include <Geode/modify/AppDelegate.hpp>

bool AppDelegate_applicationDidFinishLaunching_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float AppDelegate_bgScale_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool AppDelegate_musicTest_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AppDelegate)
SCREWYOU3_HOOK(bool applicationDidFinishLaunching())
SCREWYOU3_HOOK_IMPL(AppDelegate, applicationDidFinishLaunching, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float bgScale())
SCREWYOU3_HOOK_IMPL(AppDelegate, bgScale, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool musicTest())
SCREWYOU3_HOOK_IMPL(AppDelegate, musicTest, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("AppDelegate::applicationDidFinishLaunching")

#include <Geode/modify/ArtistCell.hpp>

bool ArtistCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ArtistCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ArtistCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("ArtistCell::init")

#include <Geode/modify/ArtTriggerGameObject.hpp>

gd::string ArtTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool ArtTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ArtTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(ArtTriggerGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(ArtTriggerGameObject, init, " m1 android imac", frame)
#endif
SCREWYOU3_HOOK_END("ArtTriggerGameObject::getSaveString")

#include <Geode/modify/AudioAssetsBrowser.hpp>

bool AudioAssetsBrowser_cellPerformedAction_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int AudioAssetsBrowser_getSelectedCellIdx_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int AudioAssetsBrowser_getCellDelegateType_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool AudioAssetsBrowser_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AudioAssetsBrowser)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(AudioAssetsBrowser, cellPerformedAction, " m1 android imac ios", cell, listType, action, parent)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getSelectedCellIdx())
SCREWYOU3_HOOK_IMPL(AudioAssetsBrowser, getSelectedCellIdx, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getCellDelegateType())
SCREWYOU3_HOOK_IMPL(AudioAssetsBrowser, getCellDelegateType, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool init(gd::vector<int>& songIds, gd::vector<int>& sfxIds))
SCREWYOU3_HOOK_IMPL(AudioAssetsBrowser, init, "m1 android imac win ios", songIds, sfxIds)
SCREWYOU3_HOOK_END("AudioAssetsBrowser::cellPerformedAction")

#include <Geode/modify/AudioEffectsLayer.hpp>

bool AudioEffectsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(AudioEffectsLayer)
SCREWYOU3_HOOK(bool init(gd::string audioString))
SCREWYOU3_HOOK_IMPL(AudioEffectsLayer, init, "m1 android imac win ios", audioString)
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
SCREWYOU3_HOOK_IMPL(AudioLineGuideGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(AudioLineGuideGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("AudioLineGuideGameObject::init")

#include <Geode/modify/BitmapFontCache.hpp>

bool BitmapFontCache_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(BitmapFontCache)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(BitmapFontCache, init, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("BitmapFontCache::init")

#include <Geode/modify/BonusDropdown.hpp>

bool BonusDropdown_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(BonusDropdown)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(gd::string text, int price))
SCREWYOU3_HOOK_IMPL(BonusDropdown, init, "m1 imac android", text, price)
#endif
SCREWYOU3_HOOK_END("BonusDropdown::init")

#include <Geode/modify/BoomListLayer.hpp>

bool BoomListLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(BoomListLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(BoomListView* listView, char const* title))
SCREWYOU3_HOOK_IMPL(BoomListLayer, init, "m1 imac android", listView, title)
#endif
SCREWYOU3_HOOK_END("BoomListLayer::init")

#include <Geode/modify/BoomListView.hpp>

float BoomListView_cellHeightForRowAtIndexPath_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int BoomListView_numberOfRowsInSection_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

unsigned int BoomListView_numberOfSectionsInTableView_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool BoomListView_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(BoomListView)
SCREWYOU3_HOOK(float cellHeightForRowAtIndexPath(CCIndexPath& indexPath, TableView* tableView))
SCREWYOU3_HOOK_IMPL(BoomListView, cellHeightForRowAtIndexPath, "m1 android imac win ios", indexPath, tableView)
SCREWYOU3_HOOK(int numberOfRowsInSection(unsigned int section, TableView* tableView))
SCREWYOU3_HOOK_IMPL(BoomListView, numberOfRowsInSection, "m1 android imac win ios", section, tableView)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(unsigned int numberOfSectionsInTableView(TableView* tableView))
SCREWYOU3_HOOK_IMPL(BoomListView, numberOfSectionsInTableView, " m1 android imac ios", tableView)
#endif
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* entries, TableViewCellDelegate* delegate, float height, float width, int page, BoomListType type, float y))
SCREWYOU3_HOOK_IMPL(BoomListView, init, "m1 android imac win ios", entries, delegate, height, width, page, type, y)
SCREWYOU3_HOOK_END("BoomListView::cellHeightForRowAtIndexPath")

#include <Geode/modify/BoomScrollLayer.hpp>

bool BoomScrollLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int BoomScrollLayer_getRelativePageForNum_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int BoomScrollLayer_getTotalPages_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool BoomScrollLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int BoomScrollLayer_pageNumberForPosition_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(BoomScrollLayer)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(BoomScrollLayer, ccTouchBegan, "m1 android imac win ios", touch, event)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getRelativePageForNum(int page))
SCREWYOU3_HOOK_IMPL(BoomScrollLayer, getRelativePageForNum, " m1 android imac ios", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getTotalPages())
SCREWYOU3_HOOK_IMPL(BoomScrollLayer, getTotalPages, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* pages, int offset, bool looped, cocos2d::CCArray* dynamicObjects, DynamicScrollDelegate* delegate))
SCREWYOU3_HOOK_IMPL(BoomScrollLayer, init, "m1 android imac win ios", pages, offset, looped, dynamicObjects, delegate)
SCREWYOU3_HOOK(int pageNumberForPosition(cocos2d::CCPoint position))
SCREWYOU3_HOOK_IMPL(BoomScrollLayer, pageNumberForPosition, "m1 android imac win ios", position)
SCREWYOU3_HOOK_END("BoomScrollLayer::ccTouchBegan")

#include <Geode/modify/BrowseSmartKeyLayer.hpp>

bool BrowseSmartKeyLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(BrowseSmartKeyLayer)
SCREWYOU3_HOOK(bool init(GJSmartTemplate* smartTemplate, gd::string prefabKey))
SCREWYOU3_HOOK_IMPL(BrowseSmartKeyLayer, init, "m1 android imac win ios", smartTemplate, prefabKey)
SCREWYOU3_HOOK_END("BrowseSmartKeyLayer::init")

#include <Geode/modify/BrowseSmartTemplateLayer.hpp>

bool BrowseSmartTemplateLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(BrowseSmartTemplateLayer)
SCREWYOU3_HOOK(bool init(GJSmartTemplate* smartTemplate, SmartBrowseFilter browseFilter))
SCREWYOU3_HOOK_IMPL(BrowseSmartTemplateLayer, init, "m1 android imac win ios", smartTemplate, browseFilter)
SCREWYOU3_HOOK_END("BrowseSmartTemplateLayer::init")

#include <Geode/modify/ButtonPage.hpp>

bool ButtonPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ButtonPage)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* objects, cocos2d::CCPoint position, int rows, float spacing))
SCREWYOU3_HOOK_IMPL(ButtonPage, init, " m1 android imac ios", objects, position, rows, spacing)
#endif
SCREWYOU3_HOOK_END("ButtonPage::init")

#include <Geode/modify/ButtonSprite.hpp>

bool ButtonSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ButtonSprite)
SCREWYOU3_HOOK(bool init(char const* caption, int width, int minWidth, float scale, bool absolute, char const* font, char const* bg, float height))
SCREWYOU3_HOOK_IMPL(ButtonSprite, init, "m1 android imac win ios", caption, width, minWidth, scale, absolute, font, bg, height)
SCREWYOU3_HOOK(bool init(cocos2d::CCSprite* topSprite, int width, int minWidth, float height, float scale, bool absolute, char const* bgSprite, bool noScaleSpriteForBG))
SCREWYOU3_HOOK_IMPL(ButtonSprite, init, "m1 android imac win ios", topSprite, width, minWidth, height, scale, absolute, bgSprite, noScaleSpriteForBG)
SCREWYOU3_HOOK_END("ButtonSprite::init")

#include <Geode/modify/CameraTriggerGameObject.hpp>

gd::string CameraTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool CameraTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CameraTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(CameraTriggerGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(CameraTriggerGameObject, init, " m1 android imac", frame)
#endif
SCREWYOU3_HOOK_END("CameraTriggerGameObject::getSaveString")

#include <Geode/modify/CCAlertCircle.hpp>

bool CCAlertCircle_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCAlertCircle)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCAlertCircle, init, "m1 imac android", )
#endif
SCREWYOU3_HOOK_END("CCAlertCircle::init")

#include <Geode/modify/CCAnimatedSprite.hpp>

bool CCAnimatedSprite_initWithType_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCAnimatedSprite)
SCREWYOU3_HOOK(bool initWithType(char const* definition, cocos2d::CCTexture2D* texture, bool useTexture))
SCREWYOU3_HOOK_IMPL(CCAnimatedSprite, initWithType, "m1 android imac win ios", definition, texture, useTexture)
SCREWYOU3_HOOK_END("CCAnimatedSprite::initWithType")

#include <Geode/modify/CCAnimateFrameCache.hpp>

bool CCAnimateFrameCache_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCAnimateFrameCache)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCAnimateFrameCache, init, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("CCAnimateFrameCache::init")

#include <Geode/modify/CCBlockLayer.hpp>

bool CCBlockLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CCBlockLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCBlockLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCBlockLayer, init, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(CCBlockLayer, ccTouchBegan, " m1 android imac ios", touch, event)
#endif
SCREWYOU3_HOOK_END("CCBlockLayer::init")

#include <Geode/modify/CCCircleAlert.hpp>

bool CCCircleAlert_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCCircleAlert)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(float duration, float startRadius, float endRadius))
SCREWYOU3_HOOK_IMPL(CCCircleAlert, init, "m1 imac android", duration, startRadius, endRadius)
#endif
SCREWYOU3_HOOK_END("CCCircleAlert::init")

#include <Geode/modify/CCCircleWave.hpp>

bool CCCircleWave_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCCircleWave)
SCREWYOU3_HOOK(bool init(float startRadius, float endRadius, float duration, bool fadeIn, bool easeOut))
SCREWYOU3_HOOK_IMPL(CCCircleWave, init, "m1 android imac win ios", startRadius, endRadius, duration, fadeIn, easeOut)
SCREWYOU3_HOOK_END("CCCircleWave::init")

#include <Geode/modify/CCCountdown.hpp>

bool CCCountdown_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCCountdown)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCCountdown, init, "m1 imac android", )
#endif
SCREWYOU3_HOOK_END("CCCountdown::init")

#include <Geode/modify/CCCounterLabel.hpp>

int CCCounterLabel_getTargetCount_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool CCCounterLabel_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCCounterLabel)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getTargetCount())
SCREWYOU3_HOOK_IMPL(CCCounterLabel, getTargetCount, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int count, char const* font, FormatterType type))
SCREWYOU3_HOOK_IMPL(CCCounterLabel, init, " m1 android imac ios", count, font, type)
#endif
SCREWYOU3_HOOK_END("CCCounterLabel::getTargetCount")

#include <Geode/modify/CCLightFlash.hpp>

bool CCLightFlash_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCLightFlash)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCLightFlash, init, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("CCLightFlash::init")

#include <Geode/modify/CCLightStrip.hpp>

bool CCLightStrip_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCLightStrip)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(float width, float toWidth, float toHeight, float duration, float delay))
SCREWYOU3_HOOK_IMPL(CCLightStrip, init, " m1 android imac ios", width, toWidth, toHeight, duration, delay)
#endif
SCREWYOU3_HOOK_END("CCLightStrip::init")

#include <Geode/modify/CCMenuItemSpriteExtra.hpp>

bool CCMenuItemSpriteExtra_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCMenuItemSpriteExtra)
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* sprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback))
SCREWYOU3_HOOK_IMPL(CCMenuItemSpriteExtra, init, "m1 android imac win ios", sprite, selectedSprite, target, callback)
SCREWYOU3_HOOK_END("CCMenuItemSpriteExtra::init")

#include <Geode/modify/CCMenuItemToggler.hpp>

bool CCMenuItemToggler_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCMenuItemToggler)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* off, cocos2d::CCNode* on, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback))
SCREWYOU3_HOOK_IMPL(CCMenuItemToggler, init, " m1 android imac ios", off, on, target, callback)
#endif
SCREWYOU3_HOOK_END("CCMenuItemToggler::init")

#include <Geode/modify/CCMoveCNode.hpp>

bool CCMoveCNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCMoveCNode)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCMoveCNode, init, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("CCMoveCNode::init")

#include <Geode/modify/CCNodeContainer.hpp>

bool CCNodeContainer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCNodeContainer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CCNodeContainer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("CCNodeContainer::init")

#include <Geode/modify/CCPartAnimSprite.hpp>

bool CCPartAnimSprite_isFrameDisplayed_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int CCPartAnimSprite_countParts_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool CCPartAnimSprite_initWithAnimDesc_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCPartAnimSprite)
SCREWYOU3_HOOK(bool isFrameDisplayed(cocos2d::CCSpriteFrame* frame))
SCREWYOU3_HOOK_IMPL(CCPartAnimSprite, isFrameDisplayed, "m1 android imac win ios", frame)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int countParts())
SCREWYOU3_HOOK_IMPL(CCPartAnimSprite, countParts, " m1 android imac", )
#endif
SCREWYOU3_HOOK(bool initWithAnimDesc(char const* definition, cocos2d::CCTexture2D* texture, bool useTexture))
SCREWYOU3_HOOK_IMPL(CCPartAnimSprite, initWithAnimDesc, "m1 android imac win ios", definition, texture, useTexture)
SCREWYOU3_HOOK_END("CCPartAnimSprite::isFrameDisplayed")

#include <Geode/modify/CCScrollLayerExt.hpp>

bool CCScrollLayerExt_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float CCScrollLayerExt_getMaxY_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float CCScrollLayerExt_getMinY_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(CCScrollLayerExt)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(CCScrollLayerExt, ccTouchBegan, "m1 android imac win ios", touch, event)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getMaxY())
SCREWYOU3_HOOK_IMPL(CCScrollLayerExt, getMaxY, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getMinY())
SCREWYOU3_HOOK_IMPL(CCScrollLayerExt, getMinY, " m1 android imac", )
#endif
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
SCREWYOU3_HOOK_IMPL(CCSpriteGrayscale, getShaderName, "m1 android imac win ios", )
SCREWYOU3_HOOK(const char* shaderBody())
SCREWYOU3_HOOK_IMPL(CCSpriteGrayscale, shaderBody, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("CCSpriteGrayscale::getShaderName")

#include <Geode/modify/CCSpritePart.hpp>

bool CCSpritePart_getBeingUsed_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCSpritePart)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool getBeingUsed())
SCREWYOU3_HOOK_IMPL(CCSpritePart, getBeingUsed, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("CCSpritePart::getBeingUsed")

#include <Geode/modify/CCSpritePlus.hpp>

bool CCSpritePlus_initWithTexture_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CCSpritePlus_initWithSpriteFrameName_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCSpritePlus)
SCREWYOU3_HOOK(bool initWithTexture(cocos2d::CCTexture2D* texture))
SCREWYOU3_HOOK_IMPL(CCSpritePlus, initWithTexture, "m1 android imac win ios", texture)
SCREWYOU3_HOOK(bool initWithSpriteFrameName(char const* frameName))
SCREWYOU3_HOOK_IMPL(CCSpritePlus, initWithSpriteFrameName, "m1 android imac win ios", frameName)
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

float CCSpriteWithHue_getAlpha_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float CCSpriteWithHue_getHue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(CCSpriteWithHue)
SCREWYOU3_HOOK(bool initWithTexture(cocos2d::CCTexture2D* texture))
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, initWithTexture, "m1 android imac win ios", texture)
SCREWYOU3_HOOK(bool initWithTexture(cocos2d::CCTexture2D* texture, cocos2d::CCRect const& rect))
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, initWithTexture, "m1 android imac win ios", texture, rect)
SCREWYOU3_HOOK(bool initWithTexture(cocos2d::CCTexture2D* texture, cocos2d::CCRect const& rect, bool rotated))
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, initWithTexture, "m1 android imac win ios", texture, rect, rotated)
SCREWYOU3_HOOK(bool initWithSpriteFrame(cocos2d::CCSpriteFrame* frame))
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, initWithSpriteFrame, "m1 android imac win ios", frame)
SCREWYOU3_HOOK(gd::string getShaderName())
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, getShaderName, "m1 android imac win ios", )
SCREWYOU3_HOOK(const char* shaderBody())
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, shaderBody, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getAlpha())
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, getAlpha, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getHue())
SCREWYOU3_HOOK_IMPL(CCSpriteWithHue, getHue, " m1 android imac", )
#endif
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

gd::string CCTextInputNode_getString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool CCTextInputNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCTextInputNode)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(CCTextInputNode, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK(bool onTextFieldInsertText(cocos2d::CCTextFieldTTF* pSender, char const* text, int nLen, cocos2d::enumKeyCodes keyCodes))
SCREWYOU3_HOOK_IMPL(CCTextInputNode, onTextFieldInsertText, "m1 android imac win ios", pSender, text, nLen, keyCodes)
SCREWYOU3_HOOK(bool onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF* tField))
SCREWYOU3_HOOK_IMPL(CCTextInputNode, onTextFieldAttachWithIME, "m1 android imac win ios", tField)
SCREWYOU3_HOOK(bool onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF* tField))
SCREWYOU3_HOOK_IMPL(CCTextInputNode, onTextFieldDetachWithIME, "m1 android imac win ios", tField)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getString())
SCREWYOU3_HOOK_IMPL(CCTextInputNode, getString, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool init(float width, float height, char const* placeholder, char const* textFont, int fontSize, char const* labelFont))
SCREWYOU3_HOOK_IMPL(CCTextInputNode, init, "m1 android imac win ios", width, height, placeholder, textFont, fontSize, labelFont)
SCREWYOU3_HOOK_END("CCTextInputNode::ccTouchBegan")

#include <Geode/modify/CCURLObject.hpp>

bool CCURLObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CCURLObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(gd::string name, gd::string url))
SCREWYOU3_HOOK_IMPL(CCURLObject, init, " m1 android imac", name, url)
#endif
SCREWYOU3_HOOK_END("CCURLObject::init")

#include <Geode/modify/ChallengeNode.hpp>

bool ChallengeNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ChallengeNode)
SCREWYOU3_HOOK(bool init(GJChallengeItem* challengeItem, ChallengesPage* challengesPage, bool isNew))
SCREWYOU3_HOOK_IMPL(ChallengeNode, init, "m1 android imac win ios", challengeItem, challengesPage, isNew)
SCREWYOU3_HOOK_END("ChallengeNode::init")

#include <Geode/modify/ChallengesPage.hpp>

bool ChallengesPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ChallengesPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ChallengesPage, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("ChallengesPage::init")

#include <Geode/modify/ChanceTriggerGameObject.hpp>

bool ChanceTriggerGameObject_containsTargetID_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool ChanceTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ChanceTriggerGameObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool containsTargetID(int id))
SCREWYOU3_HOOK_IMPL(ChanceTriggerGameObject, containsTargetID, " m1 android imac", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(ChanceTriggerGameObject, init, " m1 android imac", frame)
#endif
SCREWYOU3_HOOK_END("ChanceTriggerGameObject::containsTargetID")

#include <Geode/modify/CharacterColorPage.hpp>

bool CharacterColorPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int CharacterColorPage_activeColorForMode_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool CharacterColorPage_checkColor_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int CharacterColorPage_colorForIndex_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(CharacterColorPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CharacterColorPage, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(int activeColorForMode(int mode))
SCREWYOU3_HOOK_IMPL(CharacterColorPage, activeColorForMode, "m1 android imac win ios", mode)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool checkColor(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(CharacterColorPage, checkColor, " m1 android imac ios", id, type)
#endif
SCREWYOU3_HOOK(int colorForIndex(int index))
SCREWYOU3_HOOK_IMPL(CharacterColorPage, colorForIndex, "m1 android imac win ios", index)
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
SCREWYOU3_HOOK_IMPL(CheckpointGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(CheckpointGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("CheckpointGameObject::init")

#include <Geode/modify/CheckpointObject.hpp>

bool CheckpointObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CheckpointObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CheckpointObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("CheckpointObject::init")

#include <Geode/modify/CollisionBlockPopup.hpp>

bool CollisionBlockPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CollisionBlockPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(CollisionBlockPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("CollisionBlockPopup::init")

#include <Geode/modify/ColorAction.hpp>

bool ColorAction_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool ColorAction_isInUse_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ColorAction)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::ccColor3B fromColor, cocos2d::ccColor3B toColor, float duration, double unused, bool blending, int playerColor, float fromOpacity, float toOpacity))
SCREWYOU3_HOOK_IMPL(ColorAction, init, " m1 android imac", fromColor, toColor, duration, unused, blending, playerColor, fromOpacity, toOpacity)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isInUse())
SCREWYOU3_HOOK_IMPL(ColorAction, isInUse, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("ColorAction::init")

#include <Geode/modify/ColorActionSprite.hpp>

bool ColorActionSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ColorActionSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ColorActionSprite, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("ColorActionSprite::init")

#include <Geode/modify/ColorChannelSprite.hpp>

bool ColorChannelSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ColorChannelSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ColorChannelSprite, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("ColorChannelSprite::init")

#include <Geode/modify/ColorSelectLiveOverlay.hpp>

bool ColorSelectLiveOverlay_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ColorSelectLiveOverlay)
SCREWYOU3_HOOK(bool init(ColorAction* baseAction, ColorAction* detailAction, EffectGameObject* object))
SCREWYOU3_HOOK_IMPL(ColorSelectLiveOverlay, init, "m1 android imac win ios", baseAction, detailAction, object)
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
SCREWYOU3_HOOK_IMPL(ColorSelectPopup, colorToHex, "m1 android imac win ios", color)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, ColorAction* action))
SCREWYOU3_HOOK_IMPL(ColorSelectPopup, init, "m1 android imac win ios", object, objects, action)
SCREWYOU3_HOOK_END("ColorSelectPopup::colorToHex")

#include <Geode/modify/CommentCell.hpp>

bool CommentCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CommentCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CommentCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("CommentCell::init")

#include <Geode/modify/CommunityCreditNode.hpp>

bool CommunityCreditNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CommunityCreditNode)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int unlockType, int iconID, int unknown, gd::string author))
SCREWYOU3_HOOK_IMPL(CommunityCreditNode, init, " m1 android imac", unlockType, iconID, unknown, author)
#endif
SCREWYOU3_HOOK_END("CommunityCreditNode::init")

#include <Geode/modify/CommunityCreditsPage.hpp>

bool CommunityCreditsPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CommunityCreditsPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CommunityCreditsPage, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("CommunityCreditsPage::init")

#include <Geode/modify/ConfigureHSVWidget.hpp>

bool ConfigureHSVWidget_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ConfigureHSVWidget)
SCREWYOU3_HOOK(bool init(cocos2d::ccHSVValue hsv, bool noBackground, bool addInputs))
SCREWYOU3_HOOK_IMPL(ConfigureHSVWidget, init, "m1 android imac win ios", hsv, noBackground, addInputs)
SCREWYOU3_HOOK_END("ConfigureHSVWidget::init")

#include <Geode/modify/ConfigureValuePopup.hpp>

bool ConfigureValuePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ConfigureValuePopup)
SCREWYOU3_HOOK(bool init(ConfigureValuePopupDelegate* delegate, float value, float minimum, float maximum, gd::string title, gd::string description, int type))
SCREWYOU3_HOOK_IMPL(ConfigureValuePopup, init, "m1 android imac win ios", delegate, value, minimum, maximum, title, description, type)
SCREWYOU3_HOOK_END("ConfigureValuePopup::init")

#include <Geode/modify/CountTriggerGameObject.hpp>

gd::string CountTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool CountTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CountTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(CountTriggerGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(CountTriggerGameObject, init, " m1 android imac", frame)
#endif
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
SCREWYOU3_HOOK_IMPL(CreateGuidelinesLayer, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK(gd::string getMergedRecordString(gd::string str1, gd::string str2))
SCREWYOU3_HOOK_IMPL(CreateGuidelinesLayer, getMergedRecordString, "m1 android imac win ios", str1, str2)
SCREWYOU3_HOOK(bool init(CustomSongDelegate* delegate, AudioGuidelinesType type))
SCREWYOU3_HOOK_IMPL(CreateGuidelinesLayer, init, "m1 android imac win ios", delegate, type)
SCREWYOU3_HOOK_END("CreateGuidelinesLayer::ccTouchBegan")

#include <Geode/modify/CreateMenuItem.hpp>

bool CreateMenuItem_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CreateMenuItem)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* normal, cocos2d::CCNode* selected, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector))
SCREWYOU3_HOOK_IMPL(CreateMenuItem, init, " m1 android imac", normal, selected, target, selector)
#endif
SCREWYOU3_HOOK_END("CreateMenuItem::init")

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

bool CreateParticlePopup_particleValueIsInt_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string CreateParticlePopup_titleForParticleValue_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float CreateParticlePopup_valueForParticleValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(CreateParticlePopup)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK(bool init(ParticleGameObject* object, cocos2d::CCArray* objects, gd::string str))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, init, "m1 android imac win ios", object, objects, str)
SCREWYOU3_HOOK(float maxSliderValueForType(gjParticleValue type))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, maxSliderValueForType, "m1 android imac win ios", type)
SCREWYOU3_HOOK(float minSliderValueForType(gjParticleValue type))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, minSliderValueForType, "m1 android imac win ios", type)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool particleValueIsInt(gjParticleValue type))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, particleValueIsInt, "m1 android imac win", type)
#endif
SCREWYOU3_HOOK(gd::string titleForParticleValue(gjParticleValue type))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, titleForParticleValue, "m1 android imac win ios", type)
SCREWYOU3_HOOK(float valueForParticleValue(gjParticleValue type))
SCREWYOU3_HOOK_IMPL(CreateParticlePopup, valueForParticleValue, "m1 android imac win ios", type)
SCREWYOU3_HOOK_END("CreateParticlePopup::ccTouchBegan")

#include <Geode/modify/CreatorLayer.hpp>

bool CreatorLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CreatorLayer_canPlayOnlineLevels_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CreatorLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CreatorLayer, init, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canPlayOnlineLevels())
SCREWYOU3_HOOK_IMPL(CreatorLayer, canPlayOnlineLevels, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("CreatorLayer::init")

#include <Geode/modify/CurrencyRewardLayer.hpp>

bool CurrencyRewardLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CurrencyRewardLayer)
SCREWYOU3_HOOK(bool init(int orbs, int stars, int moons, int diamonds, CurrencySpriteType demonKey, int keyCount, CurrencySpriteType shardType, int shardsCount, cocos2d::CCPoint position, CurrencyRewardType rewardType, float yOffset, float time))
SCREWYOU3_HOOK_IMPL(CurrencyRewardLayer, init, "m1 android imac win ios", orbs, stars, moons, diamonds, demonKey, keyCount, shardType, shardsCount, position, rewardType, yOffset, time)
SCREWYOU3_HOOK_END("CurrencyRewardLayer::init")

#include <Geode/modify/CurrencySprite.hpp>

gd::string CurrencySprite_spriteTypeToStat_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool CurrencySprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CurrencySprite_initWithSprite_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CurrencySprite)
SCREWYOU3_HOOK(static gd::string spriteTypeToStat(CurrencySpriteType type))
SCREWYOU3_HOOK_IMPL(CurrencySprite, spriteTypeToStat, "m1 android imac win ios", type)
SCREWYOU3_HOOK(bool init(CurrencySpriteType type, bool burst))
SCREWYOU3_HOOK_IMPL(CurrencySprite, init, "m1 android imac win ios", type, burst)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool initWithSprite(cocos2d::CCSprite* sprite))
SCREWYOU3_HOOK_IMPL(CurrencySprite, initWithSprite, " m1 android imac ios", sprite)
#endif
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
SCREWYOU3_HOOK_IMPL(CustomizeObjectLayer, getActiveMode, "m1 android imac win ios", ignoreDefault)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(CustomizeObjectLayer, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("CustomizeObjectLayer::getActiveMode")

#include <Geode/modify/CustomizeObjectSettingsPopup.hpp>

bool CustomizeObjectSettingsPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CustomizeObjectSettingsPopup)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects, CustomizeObjectLayer* layer))
SCREWYOU3_HOOK_IMPL(CustomizeObjectSettingsPopup, init, "m1 android imac win ios", object, objects, layer)
SCREWYOU3_HOOK_END("CustomizeObjectSettingsPopup::init")

#include <Geode/modify/CustomListView.hpp>

float CustomListView_getCellHeight_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(CustomListView)
SCREWYOU3_HOOK(static float getCellHeight(BoomListType type))
SCREWYOU3_HOOK_IMPL(CustomListView, getCellHeight, "m1 android imac win ios", type)
SCREWYOU3_HOOK_END("CustomListView::getCellHeight")

#include <Geode/modify/CustomSFXCell.hpp>

bool CustomSFXCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int CustomSFXCell_getActiveSFXID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool CustomSFXCell_shouldReload_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CustomSFXCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CustomSFXCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(int getActiveSFXID())
SCREWYOU3_HOOK_IMPL(CustomSFXCell, getActiveSFXID, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldReload())
SCREWYOU3_HOOK_IMPL(CustomSFXCell, shouldReload, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("CustomSFXCell::init")

#include <Geode/modify/CustomSFXWidget.hpp>

bool CustomSFXWidget_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CustomSFXWidget_verifySFXID_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CustomSFXWidget)
SCREWYOU3_HOOK(bool init(SFXInfoObject* object, CustomSFXDelegate* delegate, bool showDelete, bool showPlay, bool showDownload, bool noBackground, bool compactMode))
SCREWYOU3_HOOK_IMPL(CustomSFXWidget, init, "m1 android imac win ios", object, delegate, showDelete, showPlay, showDownload, noBackground, compactMode)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool verifySFXID(int id))
SCREWYOU3_HOOK_IMPL(CustomSFXWidget, verifySFXID, " m1 android imac", id)
#endif
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

bool CustomSongCell_shouldReload_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CustomSongCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(CustomSongCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(int getActiveSongID())
SCREWYOU3_HOOK_IMPL(CustomSongCell, getActiveSongID, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSongFileName())
SCREWYOU3_HOOK_IMPL(CustomSongCell, getSongFileName, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldReload())
SCREWYOU3_HOOK_IMPL(CustomSongCell, shouldReload, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("CustomSongCell::init")

#include <Geode/modify/CustomSongLayer.hpp>

bool CustomSongLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CustomSongLayer)
SCREWYOU3_HOOK(bool init(CustomSongDelegate* delegate))
SCREWYOU3_HOOK_IMPL(CustomSongLayer, init, "m1 android imac win ios", delegate)
SCREWYOU3_HOOK_END("CustomSongLayer::init")

#include <Geode/modify/CustomSongWidget.hpp>

bool CustomSongWidget_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool CustomSongWidget_verifySongID_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(CustomSongWidget)
SCREWYOU3_HOOK(bool init(SongInfoObject* songInfo, CustomSongDelegate* songDelegate, bool showSongSelect, bool showPlayMusic, bool showDownload, bool isRobtopSong, bool unkBool, bool isMusicLibrary, int unk))
SCREWYOU3_HOOK_IMPL(CustomSongWidget, init, "m1 android imac win ios", songInfo, songDelegate, showSongSelect, showPlayMusic, showDownload, isRobtopSong, unkBool, isMusicLibrary, unk)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool verifySongID(int id))
SCREWYOU3_HOOK_IMPL(CustomSongWidget, verifySongID, " m1 android imac", id)
#endif
SCREWYOU3_HOOK_END("CustomSongWidget::init")

#include <Geode/modify/DailyLevelNode.hpp>

bool DailyLevelNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DailyLevelNode)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, DailyLevelPage* page, bool isNew))
SCREWYOU3_HOOK_IMPL(DailyLevelNode, init, "m1 android imac win ios", level, page, isNew)
SCREWYOU3_HOOK_END("DailyLevelNode::init")

#include <Geode/modify/DailyLevelPage.hpp>

int DailyLevelPage_getDailyTime_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string DailyLevelPage_getDailyTimeString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool DailyLevelPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DailyLevelPage)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getDailyTime())
SCREWYOU3_HOOK_IMPL(DailyLevelPage, getDailyTime, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(gd::string getDailyTimeString(int timeLeft))
SCREWYOU3_HOOK_IMPL(DailyLevelPage, getDailyTimeString, "m1 android imac win ios", timeLeft)
SCREWYOU3_HOOK(bool init(GJTimedLevelType type))
SCREWYOU3_HOOK_IMPL(DailyLevelPage, init, "m1 android imac win ios", type)
SCREWYOU3_HOOK_END("DailyLevelPage::getDailyTime")

#include <Geode/modify/DashRingObject.hpp>

gd::string DashRingObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool DashRingObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DashRingObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(DashRingObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(DashRingObject, init, " m1 android imac", frame)
#endif
SCREWYOU3_HOOK_END("DashRingObject::getSaveString")

#include <Geode/modify/DemonFilterSelectLayer.hpp>

bool DemonFilterSelectLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DemonFilterSelectLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(DemonFilterSelectLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("DemonFilterSelectLayer::init")

#include <Geode/modify/DemonInfoPopup.hpp>

bool DemonInfoPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DemonInfoPopup)
SCREWYOU3_HOOK(bool init(int easyClassic, int mediumClassic, int hardClassic, int insaneClassic, int extremeClassic, int easyPlatformer, int mediumPlatformer, int hardPlatformer, int insanePlatformer, int extremePlatformer, int weekly, int gauntlet))
SCREWYOU3_HOOK_IMPL(DemonInfoPopup, init, "m1 android imac win ios", easyClassic, mediumClassic, hardClassic, insaneClassic, extremeClassic, easyPlatformer, mediumPlatformer, hardPlatformer, insanePlatformer, extremePlatformer, weekly, gauntlet)
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
SCREWYOU3_HOOK_IMPL(DialogLayer, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK(bool init(DialogObject* object, cocos2d::CCArray* objects, int background))
SCREWYOU3_HOOK_IMPL(DialogLayer, init, "m1 android imac win ios", object, objects, background)
SCREWYOU3_HOOK_END("DialogLayer::ccTouchBegan")

#include <Geode/modify/DialogObject.hpp>

bool DialogObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DialogObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(gd::string character, gd::string text, int characterFrame, float textScale, bool unskippable, cocos2d::ccColor3B nameColor))
SCREWYOU3_HOOK_IMPL(DialogObject, init, " m1 android imac", character, text, characterFrame, textScale, unskippable, nameColor)
#endif
SCREWYOU3_HOOK_END("DialogObject::init")

#include <Geode/modify/DrawGridLayer.hpp>

bool DrawGridLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float DrawGridLayer_timeForPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(DrawGridLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* parent, LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(DrawGridLayer, init, " m1 android imac ios", parent, layer)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, bool ignoreWarp, bool ignoreRotate, int id))
SCREWYOU3_HOOK_IMPL(DrawGridLayer, timeForPos, " m1 android imac ios", position, order, channel, songTriggers, ignoreWarp, ignoreRotate, id)
#endif
SCREWYOU3_HOOK_END("DrawGridLayer::init")

#include <Geode/modify/DungeonBarsSprite.hpp>

bool DungeonBarsSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(DungeonBarsSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(DungeonBarsSprite, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("DungeonBarsSprite::init")

#include <Geode/modify/EditButtonBar.hpp>

int EditButtonBar_getPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool EditButtonBar_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EditButtonBar)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getPage())
SCREWYOU3_HOOK_IMPL(EditButtonBar, getPage, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* objects, cocos2d::CCPoint position, int tab, bool hasCreateItems, int columns, int rows))
SCREWYOU3_HOOK_IMPL(EditButtonBar, init, " m1 android imac ios", objects, position, tab, hasCreateItems, columns, rows)
#endif
SCREWYOU3_HOOK_END("EditButtonBar::getPage")

#include <Geode/modify/EditGameObjectPopup.hpp>

bool EditGameObjectPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EditGameObjectPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, bool platformer))
SCREWYOU3_HOOK_IMPL(EditGameObjectPopup, init, "m1 android imac win ios", object, objects, platformer)
SCREWYOU3_HOOK_END("EditGameObjectPopup::init")

#include <Geode/modify/EditLevelLayer.hpp>

bool EditLevelLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EditLevelLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(EditLevelLayer, init, "m1 android imac win ios", level)
SCREWYOU3_HOOK_END("EditLevelLayer::init")

#include <Geode/modify/EditorOptionsLayer.hpp>

bool EditorOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EditorOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(EditorOptionsLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("EditorOptionsLayer::init")

#include <Geode/modify/EditorPauseLayer.hpp>

bool EditorPauseLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EditorPauseLayer)
SCREWYOU3_HOOK(bool init(LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(EditorPauseLayer, init, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("EditorPauseLayer::init")

#include <Geode/modify/EditorUI.hpp>

int EditorUI_getRandomStartKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int EditorUI_getSmartObjectKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int EditorUI_smartTypeForKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool EditorUI_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_arrayContainsClass_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_canAllowMultiActivate_override() {
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

gd::string EditorUI_copyObjectsDetailed_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int EditorUI_edgeForObject_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool EditorUI_editButton2Usable_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_editButtonUsable_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_editColorButtonUsable_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int EditorUI_editorLayerForArray_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float EditorUI_getSnapAngle_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float EditorUI_getXMin_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool EditorUI_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_isLiveColorSelectTrigger_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_isSpecialSnapObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_liveEditColorUsable_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_onCreate_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_positionIsInSnapped_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float EditorUI_rotationforCommand_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool EditorUI_shouldDeleteObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EditorUI_shouldSnap_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float EditorUI_valueFromXPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float EditorUI_xPosFromValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(EditorUI)
SCREWYOU3_HOOK(static int getRandomStartKey(int specialTemplate))
SCREWYOU3_HOOK_IMPL(EditorUI, getRandomStartKey, "m1 android imac win ios", specialTemplate)
SCREWYOU3_HOOK(static int getSmartObjectKey(int key, GJSmartDirection direction))
SCREWYOU3_HOOK_IMPL(EditorUI, getSmartObjectKey, "m1 android imac win ios", key, direction)
SCREWYOU3_HOOK(static int smartTypeForKey(int key))
SCREWYOU3_HOOK_IMPL(EditorUI, smartTypeForKey, "m1 android imac win ios", key)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(EditorUI, ccTouchBegan, "m1 android imac win ios", touch, event)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool arrayContainsClass(cocos2d::CCArray* objects, int classType))
SCREWYOU3_HOOK_IMPL(EditorUI, arrayContainsClass, " m1 android imac ios", objects, classType)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canAllowMultiActivate(GameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(EditorUI, canAllowMultiActivate, " m1 android imac ios", object, objects)
#endif
SCREWYOU3_HOOK(bool canSelectObject(GameObject* object))
SCREWYOU3_HOOK_IMPL(EditorUI, canSelectObject, "m1 android imac win ios", object)
SCREWYOU3_HOOK(int convertKeyBasedOnNeighbors(int smartKey, int objectID, cocos2d::CCPoint position, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(EditorUI, convertKeyBasedOnNeighbors, "m1 android imac win ios", smartKey, objectID, position, objects)
SCREWYOU3_HOOK(int convertToBaseKey(int objectID))
SCREWYOU3_HOOK_IMPL(EditorUI, convertToBaseKey, "m1 android imac win ios", objectID)
SCREWYOU3_HOOK(gd::string copyObjects(cocos2d::CCArray* objects, bool copyColors, bool sort))
SCREWYOU3_HOOK_IMPL(EditorUI, copyObjects, "m1 android imac win ios", objects, copyColors, sort)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string copyObjectsDetailed(cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(EditorUI, copyObjectsDetailed, " m1 android imac ios", objects)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int edgeForObject(int id, int type))
SCREWYOU3_HOOK_IMPL(EditorUI, edgeForObject, " m1 android imac ios", id, type)
#endif
SCREWYOU3_HOOK(bool editButton2Usable())
SCREWYOU3_HOOK_IMPL(EditorUI, editButton2Usable, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool editButtonUsable())
SCREWYOU3_HOOK_IMPL(EditorUI, editButtonUsable, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool editColorButtonUsable())
SCREWYOU3_HOOK_IMPL(EditorUI, editColorButtonUsable, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int editorLayerForArray(cocos2d::CCArray* objects, bool layer2))
SCREWYOU3_HOOK_IMPL(EditorUI, editorLayerForArray, " m1 android imac ios", objects, layer2)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getSnapAngle(GameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(EditorUI, getSnapAngle, " m1 android imac ios", object, objects)
#endif
SCREWYOU3_HOOK(float getXMin(int offset))
SCREWYOU3_HOOK_IMPL(EditorUI, getXMin, "m1 android imac win ios", offset)
SCREWYOU3_HOOK(bool init(LevelEditorLayer* editorLayer))
SCREWYOU3_HOOK_IMPL(EditorUI, init, "m1 android imac win ios", editorLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isLiveColorSelectTrigger(GameObject* object))
SCREWYOU3_HOOK_IMPL(EditorUI, isLiveColorSelectTrigger, " m1 android imac", object)
#endif
SCREWYOU3_HOOK(bool isSpecialSnapObject(int id))
SCREWYOU3_HOOK_IMPL(EditorUI, isSpecialSnapObject, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool liveEditColorUsable())
SCREWYOU3_HOOK_IMPL(EditorUI, liveEditColorUsable, " m1 android imac", )
#endif
SCREWYOU3_HOOK(bool onCreate())
SCREWYOU3_HOOK_IMPL(EditorUI, onCreate, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool positionIsInSnapped(cocos2d::CCPoint position))
SCREWYOU3_HOOK_IMPL(EditorUI, positionIsInSnapped, " m1 android imac ios", position)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float rotationforCommand(EditCommand command))
SCREWYOU3_HOOK_IMPL(EditorUI, rotationforCommand, " m1 android imac", command)
#endif
SCREWYOU3_HOOK(bool shouldDeleteObject(GameObject* object))
SCREWYOU3_HOOK_IMPL(EditorUI, shouldDeleteObject, "m1 android imac win ios", object)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldSnap(GameObject* object))
SCREWYOU3_HOOK_IMPL(EditorUI, shouldSnap, " m1 android imac", object)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float valueFromXPos(float xPos))
SCREWYOU3_HOOK_IMPL(EditorUI, valueFromXPos, " m1 android imac ios", xPos)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float xPosFromValue(float value))
SCREWYOU3_HOOK_IMPL(EditorUI, xPosFromValue, " m1 android imac ios", value)
#endif
SCREWYOU3_HOOK_END("EditorUI::getRandomStartKey")

#include <Geode/modify/EditTriggersPopup.hpp>

bool EditTriggersPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EditTriggersPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(EditTriggersPopup, init, "m1 android imac win ios", object, objects)
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

bool EffectGameObject_isSpecialSpawnObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EffectGameObject_canBeOrdered_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EffectGameObject_canSpawnTriggers_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int EffectGameObject_getTargetColorIndex_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool EffectGameObject_hasSpawnTargetID_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool EffectGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EffectGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(EffectGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK(float spawnXPosition())
SCREWYOU3_HOOK_IMPL(EffectGameObject, spawnXPosition, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool canReverse())
SCREWYOU3_HOOK_IMPL(EffectGameObject, canReverse, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isSpecialSpawnObject())
SCREWYOU3_HOOK_IMPL(EffectGameObject, isSpecialSpawnObject, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool canBeOrdered())
SCREWYOU3_HOOK_IMPL(EffectGameObject, canBeOrdered, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool canSpawnTriggers())
SCREWYOU3_HOOK_IMPL(EffectGameObject, canSpawnTriggers, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getTargetColorIndex())
SCREWYOU3_HOOK_IMPL(EffectGameObject, getTargetColorIndex, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool hasSpawnTargetID(int id))
SCREWYOU3_HOOK_IMPL(EffectGameObject, hasSpawnTargetID, "m1 imac android", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(EffectGameObject, init, "m1 android imac win", frame)
#endif
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

bool EndLevelLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EndLevelLayer)
SCREWYOU3_HOOK(gd::string getCoinString())
SCREWYOU3_HOOK_IMPL(EndLevelLayer, getCoinString, "m1 android imac win ios", )
SCREWYOU3_HOOK(const char* getEndText())
SCREWYOU3_HOOK_IMPL(EndLevelLayer, getEndText, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(PlayLayer* playLayer))
SCREWYOU3_HOOK_IMPL(EndLevelLayer, init, " m1 android imac", playLayer)
#endif
SCREWYOU3_HOOK_END("EndLevelLayer::getCoinString")

#include <Geode/modify/EndPortalObject.hpp>

bool EndPortalObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EndPortalObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(EndPortalObject, init, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(EndTriggerGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(EndTriggerGameObject, getSaveString, "m1 android imac win ios", layer)
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
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK(bool hasBeenActivatedByPlayer(PlayerObject* player))
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, hasBeenActivatedByPlayer, "m1 android imac win ios", player)
SCREWYOU3_HOOK(bool hasBeenActivated())
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, hasBeenActivated, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool canAllowMultiActivate())
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, canAllowMultiActivate, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool getHasSyncedAnimation())
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, getHasSyncedAnimation, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool getHasRotateAction())
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, getHasRotateAction, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool canMultiActivate(bool multiActivate))
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, canMultiActivate, "m1 android imac win ios", multiActivate)
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(EnhancedGameObject, init, "m1 android imac win ios", frame)
SCREWYOU3_HOOK_END("EnhancedGameObject::getSaveString")

#include <Geode/modify/EnhancedTriggerObject.hpp>

gd::string EnhancedTriggerObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool EnhancedTriggerObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EnhancedTriggerObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(EnhancedTriggerObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(EnhancedTriggerObject, init, " m1 android imac", frame)
#endif
SCREWYOU3_HOOK_END("EnhancedTriggerObject::getSaveString")

#include <Geode/modify/EnterEffectInstance.hpp>

float EnterEffectInstance_getValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(EnterEffectInstance)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getValue(int key))
SCREWYOU3_HOOK_IMPL(EnterEffectInstance, getValue, " m1 android imac", key)
#endif
SCREWYOU3_HOOK_END("EnterEffectInstance::getValue")

#include <Geode/modify/EnterEffectObject.hpp>

gd::string EnterEffectObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool EnterEffectObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(EnterEffectObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(EnterEffectObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(EnterEffectObject, init, " m1 android imac", frame)
#endif
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
SCREWYOU3_HOOK_IMPL(EventLinkTrigger, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(EventLinkTrigger, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("EventLinkTrigger::init")

#include <Geode/modify/ExplodeItemNode.hpp>

bool ExplodeItemNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ExplodeItemNode)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCRenderTexture* texture))
SCREWYOU3_HOOK_IMPL(ExplodeItemNode, init, " m1 android imac ios", texture)
#endif
SCREWYOU3_HOOK_END("ExplodeItemNode::init")

#include <Geode/modify/ExplodeItemSprite.hpp>

bool ExplodeItemSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ExplodeItemSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ExplodeItemSprite, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("ExplodeItemSprite::init")

#include <Geode/modify/ExtendedLayer.hpp>

bool ExtendedLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ExtendedLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ExtendedLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("ExtendedLayer::init")

#include <Geode/modify/FileOperation.hpp>

gd::string FileOperation_getFilePath_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(FileOperation)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string getFilePath())
SCREWYOU3_HOOK_IMPL(FileOperation, getFilePath, "m1 imac android", )
#endif
SCREWYOU3_HOOK_END("FileOperation::getFilePath")

#include <Geode/modify/FileSaveManager.hpp>

bool FileSaveManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FileSaveManager)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(FileSaveManager, init, "m1 imac android", )
#endif
SCREWYOU3_HOOK_END("FileSaveManager::init")

#include <Geode/modify/FindBPMLayer.hpp>

bool FindBPMLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FindBPMLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int songID))
SCREWYOU3_HOOK_IMPL(FindBPMLayer, init, " m1 android imac ios", songID)
#endif
SCREWYOU3_HOOK_END("FindBPMLayer::init")

#include <Geode/modify/FindObjectPopup.hpp>

bool FindObjectPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FindObjectPopup)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(FindObjectPopup, init, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(FLAlertLayer, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK(bool init(int opacity))
SCREWYOU3_HOOK_IMPL(FLAlertLayer, init, "m1 android imac win ios", opacity)
SCREWYOU3_HOOK(bool init(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2, float width, bool scroll, float height, float textScale))
SCREWYOU3_HOOK_IMPL(FLAlertLayer, init, "m1 android imac win ios", delegate, title, desc, btn1, btn2, width, scroll, height, textScale)
SCREWYOU3_HOOK_END("FLAlertLayer::ccTouchBegan")

#include <Geode/modify/FMODAudioEngine.hpp>

float FMODAudioEngine_pitchForIdx_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string FMODAudioEngine_reverbToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int FMODAudioEngine_channelIDForUniqueID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_countActiveEffects_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_countActiveMusic_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string FMODAudioEngine_getActiveMusic_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float FMODAudioEngine_getBackgroundMusicVolume_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float FMODAudioEngine_getEffectsVolume_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string FMODAudioEngine_getFMODStatus_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float FMODAudioEngine_getMeteringValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_getMusicChannelID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

unsigned int FMODAudioEngine_getMusicLengthMS_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float FMODAudioEngine_getMusicTime_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

unsigned int FMODAudioEngine_getMusicTimeMS_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_getNextChannelID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool FMODAudioEngine_isAnyPersistentPlaying_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool FMODAudioEngine_isChannelStopping_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool FMODAudioEngine_isEffectLoaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool FMODAudioEngine_isMusicPlaying_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool FMODAudioEngine_isPersistentMatchPlaying_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool FMODAudioEngine_isSoundReady_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int FMODAudioEngine_lengthForSound_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_playEffect_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_playEffectAdvanced_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_playEffectAsync_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_queuePlayEffect_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int FMODAudioEngine_registerChannel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float FMODAudioEngine_stopAndGetFade_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(FMODAudioEngine)
SCREWYOU3_HOOK(static float pitchForIdx(int index))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, pitchForIdx, "m1 android imac win ios", index)
SCREWYOU3_HOOK(static gd::string reverbToString(FMODReverbPreset preset))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, reverbToString, "m1 android imac win ios", preset)
SCREWYOU3_HOOK(int channelIDForUniqueID(int id))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, channelIDForUniqueID, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int countActiveEffects())
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, countActiveEffects, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int countActiveMusic())
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, countActiveMusic, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getActiveMusic(int id))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getActiveMusic, " m1 android imac ios", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getBackgroundMusicVolume())
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getBackgroundMusicVolume, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getEffectsVolume())
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getEffectsVolume, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(gd::string getFMODStatus(int unused))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getFMODStatus, "m1 android imac win ios", unused)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getMeteringValue())
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getMeteringValue, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getMusicChannelID(int musicID))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getMusicChannelID, " m1 android imac ios", musicID)
#endif
SCREWYOU3_HOOK(unsigned int getMusicLengthMS(int channel))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getMusicLengthMS, "m1 android imac win ios", channel)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getMusicTime(int channel))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getMusicTime, " m1 android imac ios", channel)
#endif
SCREWYOU3_HOOK(unsigned int getMusicTimeMS(int channel))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getMusicTimeMS, "m1 android imac win ios", channel)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getNextChannelID())
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, getNextChannelID, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isAnyPersistentPlaying())
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, isAnyPersistentPlaying, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isChannelStopping(int channel))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, isChannelStopping, " m1 android imac", channel)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isEffectLoaded(gd::string path))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, isEffectLoaded, " m1 android imac", path)
#endif
SCREWYOU3_HOOK(bool isMusicPlaying(int musicID))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, isMusicPlaying, "m1 android imac win ios", musicID)
SCREWYOU3_HOOK(bool isMusicPlaying(gd::string path, int musicID))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, isMusicPlaying, "m1 android imac win ios", path, musicID)
SCREWYOU3_HOOK(bool isPersistentMatchPlaying(gd::string path, int musicID))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, isPersistentMatchPlaying, "m1 android imac win ios", path, musicID)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isSoundReady(FMOD::Sound* sound))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, isSoundReady, " m1 android imac", sound)
#endif
SCREWYOU3_HOOK(int lengthForSound(gd::string path))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, lengthForSound, "m1 android imac win ios", path)
SCREWYOU3_HOOK(int playEffect(gd::string path))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, playEffect, "m1 android imac win ios", path)
SCREWYOU3_HOOK(int playEffect(gd::string path, float speed, float unknown, float volume))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, playEffect, "m1 android imac win ios", path, speed, unknown, volume)
SCREWYOU3_HOOK(int playEffectAdvanced(gd::string path, float speed, float unknown, float volume, float pitch, bool fastFourierTransform, bool reverb, int startMillis, int endMillis, int fadeIn, int fadeOut, bool loopEnabled, int effectID, bool override, bool noPreload, int channelID, int uniqueID, float minInterval, int sfxGroup))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, playEffectAdvanced, "m1 android imac win ios", path, speed, unknown, volume, pitch, fastFourierTransform, reverb, startMillis, endMillis, fadeIn, fadeOut, loopEnabled, effectID, override, noPreload, channelID, uniqueID, minInterval, sfxGroup)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int playEffectAsync(gd::string path))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, playEffectAsync, " m1 android imac ios", path)
#endif
SCREWYOU3_HOOK(int queuePlayEffect(gd::string audioFilename, float speed, float unknown, float volume, float pitch, bool fastFourierTransform, bool reverb, int start, int end, int fadeIn, int fadeOut, bool loop, int effectID, bool override, int uniqueID, float minInterval, int group))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, queuePlayEffect, "m1 android imac win ios", audioFilename, speed, unknown, volume, pitch, fastFourierTransform, reverb, start, end, fadeIn, fadeOut, loop, effectID, override, uniqueID, minInterval, group)
SCREWYOU3_HOOK(int registerChannel(FMOD::Channel* channel, int channelID, int effectID))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, registerChannel, "m1 android imac win ios", channel, channelID, effectID)
SCREWYOU3_HOOK(float stopAndGetFade(FMOD::Channel* channel))
SCREWYOU3_HOOK_IMPL(FMODAudioEngine, stopAndGetFade, "m1 android imac win ios", channel)
SCREWYOU3_HOOK_END("FMODAudioEngine::pitchForIdx")

#include <Geode/modify/FMODLevelVisualizer.hpp>

bool FMODLevelVisualizer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FMODLevelVisualizer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(FMODLevelVisualizer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("FMODLevelVisualizer::init")

#include <Geode/modify/FollowRewardPage.hpp>

bool FollowRewardPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FollowRewardPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(FollowRewardPage, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("FollowRewardPage::init")

#include <Geode/modify/FontObject.hpp>

int FontObject_getFontWidth_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool FontObject_initWithConfigFile_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FontObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getFontWidth(int character))
SCREWYOU3_HOOK_IMPL(FontObject, getFontWidth, " m1 android imac ios", character)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool initWithConfigFile(char const* font, float scale))
SCREWYOU3_HOOK_IMPL(FontObject, initWithConfigFile, " m1 android imac", font, scale)
#endif
SCREWYOU3_HOOK_END("FontObject::getFontWidth")

#include <Geode/modify/ForceBlockGameObject.hpp>

gd::string ForceBlockGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool ForceBlockGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ForceBlockGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(ForceBlockGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(ForceBlockGameObject, init, " m1 android imac", frame)
#endif
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
SCREWYOU3_HOOK_IMPL(FRequestProfilePage, init, "m1 android imac win ios", sent)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(FRequestProfilePage, isCorrect, "m1 android imac win ios", key)
SCREWYOU3_HOOK_END("FRequestProfilePage::init")

#include <Geode/modify/FriendRequestPopup.hpp>

bool FriendRequestPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FriendRequestPopup)
SCREWYOU3_HOOK(bool init(GJFriendRequest* request))
SCREWYOU3_HOOK_IMPL(FriendRequestPopup, init, "m1 android imac win ios", request)
SCREWYOU3_HOOK_END("FriendRequestPopup::init")

#include <Geode/modify/FriendsProfilePage.hpp>

bool FriendsProfilePage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(FriendsProfilePage)
SCREWYOU3_HOOK(bool init(UserListType type))
SCREWYOU3_HOOK_IMPL(FriendsProfilePage, init, "m1 android imac win ios", type)
SCREWYOU3_HOOK_END("FriendsProfilePage::init")

#include <Geode/modify/GameCell.hpp>

bool GameCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GameCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GameCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GameCell::init")

#include <Geode/modify/GameEffectsManager.hpp>

bool GameEffectsManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GameEffectsManager)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(PlayLayer* playLayer))
SCREWYOU3_HOOK_IMPL(GameEffectsManager, init, "m1 imac android", playLayer)
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

bool GameLevelManager_areGauntletsLoaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_blockUser_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameLevelManager_createPageInfo_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameLevelManager_deleteFriendRequests_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_deleteSentFriendRequest_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_deleteUserMessages_override() {
	return modUtils::chooseRandomNum(0, 1);
}

const char* GameLevelManager_getAccountCommentKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameLevelManager_getActiveDailyID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameLevelManager_getBasePostString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameLevelManager_getBoolForKey_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameLevelManager_getCommentKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameLevelManager_getCompletedDailyLevels_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameLevelManager_getCompletedEventLevels_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameLevelManager_getCompletedGauntletDemons_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameLevelManager_getCompletedGauntletLevels_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameLevelManager_getCompletedWeeklyLevels_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameLevelManager_getDailyID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameLevelManager_getDailyTimer_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

const char* GameLevelManager_getDeleteCommentKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getDeleteMessageKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameLevelManager_getDemonLevelsString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getDescKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameLevelManager_getDifficultyStr_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getDiffKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameLevelManager_getDiffVal_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameLevelManager_getFolderName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getFriendRequestKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getGauntletKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameLevelManager_getGauntletSearchKey_override() {
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

int GameLevelManager_getHighestLevelOrder_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameLevelManager_getIntForKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameLevelManager_getLeaderboardKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameLevelManager_getLengthStr_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getLenKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameLevelManager_getLenVal_override() {
	return modUtils::chooseRandomNum(0, 1);
}

const char* GameLevelManager_getLevelDownloadKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getLevelKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getLevelLeaderboardKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getLevelListKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getLikeAccountItemKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getLikeItemKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameLevelManager_getLowestLevelOrder_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

const char* GameLevelManager_getMapPackKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getMessageKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getMessagesKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameLevelManager_getNextFreeTemplateID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameLevelManager_getNextLevelName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getPageInfo_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getPostCommentKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getRateStarsKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getReportKey_override() {

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

const char* GameLevelManager_getTopArtistsKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getUploadMessageKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameLevelManager_getUserInfoKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameLevelManager_hasDailyStateBeenLoaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_hasDownloadedLevel_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_hasDownloadedList_override() {
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

bool GameLevelManager_isUpdateValid_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameLevelManager_itemIDFromLikeKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameLevelManager_keyHasTimer_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameLevelManager_levelIDFromCommentKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameLevelManager_levelIDFromPostCommentKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameLevelManager_likeFromLikeKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameLevelManager_pageFromCommentKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameLevelManager_rateDemon_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_rateLevelAdmin_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_removeFriend_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_requestUserAccess_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_setLevelStars_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameLevelManager_specialFromLikeKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameLevelManager_tryGetUsername_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameLevelManager_unblockUser_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_unrateLevelAdmin_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_updateDescription_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_updateLevelRankAdmin_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameLevelManager_uploadFriendRequest_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameLevelManager_userIDForAccountID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
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
SCREWYOU3_HOOK_IMPL(GameLevelManager, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool acceptFriendRequest(int accountID, int requestID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, acceptFriendRequest, "m1 android imac win ios", accountID, requestID)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int accountIDForUserID(int userID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, accountIDForUserID, " m1 android imac ios", userID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool areGauntletsLoaded())
SCREWYOU3_HOOK_IMPL(GameLevelManager, areGauntletsLoaded, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool blockUser(int accountID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, blockUser, "m1 android imac win ios", accountID)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string createPageInfo(int total, int start, int count))
SCREWYOU3_HOOK_IMPL(GameLevelManager, createPageInfo, " m1 android imac ios", total, start, count)
#endif
SCREWYOU3_HOOK(bool deleteFriendRequests(int accountID, cocos2d::CCArray* accounts, bool sent))
SCREWYOU3_HOOK_IMPL(GameLevelManager, deleteFriendRequests, "m1 android imac win ios", accountID, accounts, sent)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool deleteSentFriendRequest(int accountID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, deleteSentFriendRequest, " m1 android imac ios", accountID)
#endif
SCREWYOU3_HOOK(bool deleteUserMessages(GJUserMessage* message, cocos2d::CCArray* messages, bool isSender))
SCREWYOU3_HOOK_IMPL(GameLevelManager, deleteUserMessages, "m1 android imac win ios", message, messages, isSender)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getAccountCommentKey(int accountID, int page))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getAccountCommentKey, " m1 android imac ios", accountID, page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getActiveDailyID(GJTimedLevelType type))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getActiveDailyID, " m1 android imac ios", type)
#endif
SCREWYOU3_HOOK(gd::string getBasePostString())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getBasePostString, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool getBoolForKey(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getBoolForKey, " m1 android imac ios", key)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getCommentKey(int ID, int page, int mode, CommentKeyType keytype))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getCommentKey, " m1 android imac ios", ID, page, mode, keytype)
#endif
SCREWYOU3_HOOK(int getCompletedDailyLevels())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getCompletedDailyLevels, "m1 android imac win ios", )
SCREWYOU3_HOOK(int getCompletedEventLevels(int minStars, int maxStars))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getCompletedEventLevels, "m1 android imac win ios", minStars, maxStars)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getCompletedGauntletDemons())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getCompletedGauntletDemons, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getCompletedGauntletLevels())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getCompletedGauntletLevels, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(int getCompletedWeeklyLevels())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getCompletedWeeklyLevels, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getDailyID(GJTimedLevelType type))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getDailyID, " m1 android imac ios", type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getDailyTimer(GJTimedLevelType type))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getDailyTimer, " m1 android imac ios", type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getDeleteCommentKey(int parentID, int id, int type))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getDeleteCommentKey, " m1 android imac", parentID, id, type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getDeleteMessageKey(int id, bool sent))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getDeleteMessageKey, " m1 android imac", id, sent)
#endif
SCREWYOU3_HOOK(gd::string getDemonLevelsString())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getDemonLevelsString, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getDescKey(int levelID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getDescKey, " m1 android imac", levelID)
#endif
SCREWYOU3_HOOK(gd::string getDifficultyStr(bool isNA, bool isEasy, bool isNormal, bool isHard, bool isHarder, bool isInsane, bool isDemon, bool isAuto))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getDifficultyStr, "m1 android imac win ios", isNA, isEasy, isNormal, isHard, isHarder, isInsane, isDemon, isAuto)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getDiffKey(int diff))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getDiffKey, " m1 android imac", diff)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool getDiffVal(int diff))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getDiffVal, " m1 android imac ios", diff)
#endif
SCREWYOU3_HOOK(gd::string getFolderName(int id, bool local))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getFolderName, "m1 android imac win ios", id, local)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getFriendRequestKey(bool sent, int page))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getFriendRequestKey, " m1 android imac ios", sent, page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getGauntletKey(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getGauntletKey, " m1 android imac", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getGauntletSearchKey(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getGauntletSearchKey, " m1 android imac ios", id)
#endif
SCREWYOU3_HOOK(bool getGJChallenges())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getGJChallenges, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool getGJDailyLevelState(GJTimedLevelType type))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getGJDailyLevelState, "m1 android imac win ios", type)
SCREWYOU3_HOOK(bool getGJRewards(int type))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getGJRewards, "m1 android imac win ios", type)
SCREWYOU3_HOOK(bool getGJSecretReward(gd::string key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getGJSecretReward, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getHighestLevelOrder())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getHighestLevelOrder, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getIntForKey(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getIntForKey, " m1 android imac ios", key)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getLeaderboardKey(LeaderboardType type, LeaderboardStat stat))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getLeaderboardKey, " m1 android imac ios", type, stat)
#endif
SCREWYOU3_HOOK(gd::string getLengthStr(bool isTiny, bool isShort, bool isMedium, bool isLong, bool isXL, bool isPlat))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getLengthStr, "m1 android imac win ios", isTiny, isShort, isMedium, isLong, isXL, isPlat)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getLenKey(int len))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getLenKey, " m1 android imac", len)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool getLenVal(int len))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getLenVal, " m1 android imac ios", len)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getLevelDownloadKey(int levelID, bool isGauntlet, int dailyID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getLevelDownloadKey, " m1 android imac", levelID, isGauntlet, dailyID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getLevelKey(int levelID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getLevelKey, " m1 android imac", levelID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getLevelLeaderboardKey(int levelID, LevelLeaderboardType type, LevelLeaderboardMode mode))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getLevelLeaderboardKey, " m1 android imac ios", levelID, type, mode)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getLevelListKey(int listID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getLevelListKey, " m1 android imac", listID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getLikeAccountItemKey(LikeItemType type, int id, bool liked, int parentID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getLikeAccountItemKey, " m1 android imac", type, id, liked, parentID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getLikeItemKey(LikeItemType type, int id, bool liked, int parentID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getLikeItemKey, " m1 android imac", type, id, liked, parentID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getLowestLevelOrder())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getLowestLevelOrder, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getMapPackKey(int pack))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getMapPackKey, " m1 android imac", pack)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getMessageKey(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getMessageKey, " m1 android imac", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getMessagesKey(bool sent, int page))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getMessagesKey, " m1 android imac ios", sent, page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getNextFreeTemplateID())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getNextFreeTemplateID, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(gd::string getNextLevelName(gd::string name))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getNextLevelName, "m1 android imac win ios", name)
SCREWYOU3_HOOK(const char* getPageInfo(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getPageInfo, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getPostCommentKey(int parentID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getPostCommentKey, " m1 android imac ios", parentID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getRateStarsKey(int levelID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getRateStarsKey, " m1 android imac", levelID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getReportKey(int levelID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getReportKey, " m1 android imac", levelID)
#endif
SCREWYOU3_HOOK(int getSplitIntFromKey(char const* key, int index))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getSplitIntFromKey, "m1 android imac win ios", key, index)
SCREWYOU3_HOOK(gd::string getStarLevelsString())
SCREWYOU3_HOOK_IMPL(GameLevelManager, getStarLevelsString, "m1 android imac win ios", )
SCREWYOU3_HOOK(int getTimeLeft(char const* key, float length))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getTimeLeft, "m1 android imac win ios", key, length)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getTopArtistsKey(int page))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getTopArtistsKey, " m1 android imac ios", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getUploadMessageKey(int accountID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getUploadMessageKey, " m1 android imac", accountID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getUserInfoKey(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, getUserInfoKey, " m1 android imac", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool hasDailyStateBeenLoaded(GJTimedLevelType type))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasDailyStateBeenLoaded, " m1 android imac ios", type)
#endif
SCREWYOU3_HOOK(bool hasDownloadedLevel(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasDownloadedLevel, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool hasDownloadedList(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasDownloadedList, " m1 android imac", id)
#endif
SCREWYOU3_HOOK(bool hasLikedAccountItem(LikeItemType type, int id, bool liked, int parentID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasLikedAccountItem, "m1 android imac win ios", type, id, liked, parentID)
SCREWYOU3_HOOK(bool hasLikedItem(LikeItemType type, int id, bool liked, int parentID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasLikedItem, "m1 android imac win ios", type, id, liked, parentID)
SCREWYOU3_HOOK(bool hasLikedItemFullCheck(LikeItemType type, int id, bool liked, int parentID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasLikedItemFullCheck, "m1 android imac win ios", type, id, liked, parentID)
SCREWYOU3_HOOK(bool hasRatedDemon(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasRatedDemon, "m1 android imac win ios", id)
SCREWYOU3_HOOK(bool hasRatedLevelStars(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasRatedLevelStars, "m1 android imac win ios", id)
SCREWYOU3_HOOK(bool hasReportedLevel(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, hasReportedLevel, "m1 android imac win ios", id)
SCREWYOU3_HOOK(bool isDLActive(char const* tag))
SCREWYOU3_HOOK_IMPL(GameLevelManager, isDLActive, "m1 android imac win ios", tag)
SCREWYOU3_HOOK(bool isFollowingUser(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, isFollowingUser, "m1 android imac win ios", id)
SCREWYOU3_HOOK(bool isTimeValid(char const* key, float length))
SCREWYOU3_HOOK_IMPL(GameLevelManager, isTimeValid, "m1 android imac win ios", key, length)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isUpdateValid(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, isUpdateValid, " m1 android imac ios", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int itemIDFromLikeKey(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, itemIDFromLikeKey, " m1 android imac ios", key)
#endif
SCREWYOU3_HOOK(bool keyHasTimer(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, keyHasTimer, "m1 android imac win ios", key)
SCREWYOU3_HOOK(int levelIDFromCommentKey(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, levelIDFromCommentKey, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int levelIDFromPostCommentKey(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, levelIDFromPostCommentKey, " m1 android imac ios", key)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int likeFromLikeKey(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, likeFromLikeKey, " m1 android imac ios", key)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int pageFromCommentKey(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, pageFromCommentKey, " m1 android imac ios", key)
#endif
SCREWYOU3_HOOK(bool rateDemon(int id, int diff, bool moderator))
SCREWYOU3_HOOK_IMPL(GameLevelManager, rateDemon, "m1 android imac win ios", id, diff, moderator)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool rateLevelAdmin(int id, int stars, int feature, int rank, bool coins, bool updateRank))
SCREWYOU3_HOOK_IMPL(GameLevelManager, rateLevelAdmin, " m1 android imac", id, stars, feature, rank, coins, updateRank)
#endif
SCREWYOU3_HOOK(bool removeFriend(int accountID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, removeFriend, "m1 android imac win ios", accountID)
SCREWYOU3_HOOK(bool requestUserAccess())
SCREWYOU3_HOOK_IMPL(GameLevelManager, requestUserAccess, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool setLevelStars(int id, int stars, bool coins))
SCREWYOU3_HOOK_IMPL(GameLevelManager, setLevelStars, " m1 android imac", id, stars, coins)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int specialFromLikeKey(char const* key))
SCREWYOU3_HOOK_IMPL(GameLevelManager, specialFromLikeKey, " m1 android imac", key)
#endif
SCREWYOU3_HOOK(gd::string tryGetUsername(int accountID))
SCREWYOU3_HOOK_IMPL(GameLevelManager, tryGetUsername, "m1 android imac win ios", accountID)
SCREWYOU3_HOOK(bool unblockUser(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, unblockUser, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool unrateLevelAdmin(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, unrateLevelAdmin, " m1 android imac ios", id)
#endif
SCREWYOU3_HOOK(bool updateDescription(int id, gd::string description))
SCREWYOU3_HOOK_IMPL(GameLevelManager, updateDescription, "m1 android imac win ios", id, description)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool updateLevelRankAdmin(int id, int rank))
SCREWYOU3_HOOK_IMPL(GameLevelManager, updateLevelRankAdmin, " m1 android imac ios", id, rank)
#endif
SCREWYOU3_HOOK(bool uploadFriendRequest(int accountID, gd::string content))
SCREWYOU3_HOOK_IMPL(GameLevelManager, uploadFriendRequest, "m1 android imac win ios", accountID, content)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int userIDForAccountID(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, userIDForAccountID, " m1 android imac ios", id)
#endif
SCREWYOU3_HOOK(gd::string userNameForUserID(int id))
SCREWYOU3_HOOK_IMPL(GameLevelManager, userNameForUserID, "m1 android imac win ios", id)
SCREWYOU3_HOOK(bool verifyContainerOnlyHasLevels(cocos2d::CCDictionary* dict))
SCREWYOU3_HOOK_IMPL(GameLevelManager, verifyContainerOnlyHasLevels, "m1 android imac win ios", dict)
SCREWYOU3_HOOK(gd::string writeSpecialFilters(GJSearchObject* object))
SCREWYOU3_HOOK_IMPL(GameLevelManager, writeSpecialFilters, "m1 android imac win ios", object)
SCREWYOU3_HOOK_END("GameLevelManager::init")

#include <Geode/modify/GameLevelOptionsLayer.hpp>

bool GameLevelOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GameLevelOptionsLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameLevelOptionsLayer, init, " m1 android imac ios", level)
#endif
SCREWYOU3_HOOK_END("GameLevelOptionsLayer::init")

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

int GameManager_colorForPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameManager_colorKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameManager_countForType_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameManager_defaultFrameForAnimation_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameManager_dpadConfigToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameManager_framesForAnimation_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GameManager_frameTimeForAnimation_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameManager_generateSecretNumber_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

const char* GameManager_getBGTexture_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameManager_getFontFile_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameManager_getFontTexture_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameManager_getGameVariable_override() {
	return modUtils::chooseRandomNum(0, 1);
}

const char* GameManager_getGTexture_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameManager_getIconRequestID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameManager_getIntGameVariable_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameManager_getMenuMusicFile_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameManager_getMGTexture_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameManager_getNextUniqueObjectKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameManager_getNextUsedKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameManager_getPracticeMusicFile_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameManager_getUGV_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameManager_groundHasSecondaryColor_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameManager_iconKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameManager_isColorUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameManager_isIconLoaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameManager_isIconUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameManager_keyForIcon_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameManager_levelIsPremium_override() {
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

bool GameManager_shouldShowInterstitial_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameManager_showInterstitial_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameManager_showInterstitialForced_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameManager_showMainMenuAd_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameManager_stringForCustomObject_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameManager_toggleGameVariable_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GameManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GameManager, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(int activeIconForType(IconType type))
SCREWYOU3_HOOK_IMPL(GameManager, activeIconForType, "m1 android imac win ios", type)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canShowRewardedVideo())
SCREWYOU3_HOOK_IMPL(GameManager, canShowRewardedVideo, "m1 imac android", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int colorForPos(int pos))
SCREWYOU3_HOOK_IMPL(GameManager, colorForPos, " m1 android imac", pos)
#endif
SCREWYOU3_HOOK(gd::string colorKey(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GameManager, colorKey, "m1 android imac win ios", id, type)
SCREWYOU3_HOOK(int countForType(IconType type))
SCREWYOU3_HOOK_IMPL(GameManager, countForType, "m1 android imac win ios", type)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int defaultFrameForAnimation(int objectID))
SCREWYOU3_HOOK_IMPL(GameManager, defaultFrameForAnimation, " m1 android imac", objectID)
#endif
SCREWYOU3_HOOK(gd::string dpadConfigToString(UIButtonConfig& config))
SCREWYOU3_HOOK_IMPL(GameManager, dpadConfigToString, "m1 android imac win ios", config)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int framesForAnimation(int objectID))
SCREWYOU3_HOOK_IMPL(GameManager, framesForAnimation, " m1 android imac", objectID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float frameTimeForAnimation(int objectID))
SCREWYOU3_HOOK_IMPL(GameManager, frameTimeForAnimation, " m1 android imac", objectID)
#endif
SCREWYOU3_HOOK(int generateSecretNumber())
SCREWYOU3_HOOK_IMPL(GameManager, generateSecretNumber, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getBGTexture(int index))
SCREWYOU3_HOOK_IMPL(GameManager, getBGTexture, " m1 android imac ios", index)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getFontFile(int index))
SCREWYOU3_HOOK_IMPL(GameManager, getFontFile, " m1 android imac ios", index)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getFontTexture(int index))
SCREWYOU3_HOOK_IMPL(GameManager, getFontTexture, " m1 android imac ios", index)
#endif
SCREWYOU3_HOOK(bool getGameVariable(char const* key))
SCREWYOU3_HOOK_IMPL(GameManager, getGameVariable, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getGTexture(int index))
SCREWYOU3_HOOK_IMPL(GameManager, getGTexture, " m1 android imac ios", index)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getIconRequestID())
SCREWYOU3_HOOK_IMPL(GameManager, getIconRequestID, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(int getIntGameVariable(char const* key))
SCREWYOU3_HOOK_IMPL(GameManager, getIntGameVariable, "m1 android imac win ios", key)
SCREWYOU3_HOOK(gd::string getMenuMusicFile())
SCREWYOU3_HOOK_IMPL(GameManager, getMenuMusicFile, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getMGTexture(int index))
SCREWYOU3_HOOK_IMPL(GameManager, getMGTexture, " m1 android imac ios", index)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getNextUniqueObjectKey())
SCREWYOU3_HOOK_IMPL(GameManager, getNextUniqueObjectKey, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getNextUsedKey(int index, bool up))
SCREWYOU3_HOOK_IMPL(GameManager, getNextUsedKey, " m1 android imac ios", index, up)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getPracticeMusicFile())
SCREWYOU3_HOOK_IMPL(GameManager, getPracticeMusicFile, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool getUGV(char const* key))
SCREWYOU3_HOOK_IMPL(GameManager, getUGV, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool groundHasSecondaryColor(int index))
SCREWYOU3_HOOK_IMPL(GameManager, groundHasSecondaryColor, " m1 android imac", index)
#endif
SCREWYOU3_HOOK(gd::string iconKey(int id, IconType type))
SCREWYOU3_HOOK_IMPL(GameManager, iconKey, "m1 android imac win ios", id, type)
SCREWYOU3_HOOK(bool isColorUnlocked(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GameManager, isColorUnlocked, "m1 android imac win ios", id, type)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isIconLoaded(int id, int type))
SCREWYOU3_HOOK_IMPL(GameManager, isIconLoaded, " m1 android imac ios", id, type)
#endif
SCREWYOU3_HOOK(bool isIconUnlocked(int id, IconType type))
SCREWYOU3_HOOK_IMPL(GameManager, isIconUnlocked, "m1 android imac win ios", id, type)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int keyForIcon(int id, int type))
SCREWYOU3_HOOK_IMPL(GameManager, keyForIcon, " m1 android imac", id, type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool levelIsPremium(int unk1, int unk2))
SCREWYOU3_HOOK_IMPL(GameManager, levelIsPremium, " m1 android imac", unk1, unk2)
#endif
SCREWYOU3_HOOK(int playSFXTrigger(SFXTriggerGameObject* object))
SCREWYOU3_HOOK_IMPL(GameManager, playSFXTrigger, "m1 android imac win ios", object)
SCREWYOU3_HOOK(int reorderKey(int index, bool up))
SCREWYOU3_HOOK_IMPL(GameManager, reorderKey, "m1 android imac win ios", index, up)
SCREWYOU3_HOOK(bool safePopScene())
SCREWYOU3_HOOK_IMPL(GameManager, safePopScene, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string sheetNameForIcon(int id, int type))
SCREWYOU3_HOOK_IMPL(GameManager, sheetNameForIcon, "m1 android imac win ios", id, type)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldShowInterstitial(int unk1, int unk2, int unk3))
SCREWYOU3_HOOK_IMPL(GameManager, shouldShowInterstitial, " m1 android imac", unk1, unk2, unk3)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool showInterstitial())
SCREWYOU3_HOOK_IMPL(GameManager, showInterstitial, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool showInterstitialForced())
SCREWYOU3_HOOK_IMPL(GameManager, showInterstitialForced, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool showMainMenuAd())
SCREWYOU3_HOOK_IMPL(GameManager, showMainMenuAd, " m1 android imac", )
#endif
SCREWYOU3_HOOK(gd::string stringForCustomObject(int customObjectID))
SCREWYOU3_HOOK_IMPL(GameManager, stringForCustomObject, "m1 android imac win ios", customObjectID)
SCREWYOU3_HOOK(bool toggleGameVariable(char const* key))
SCREWYOU3_HOOK_IMPL(GameManager, toggleGameVariable, "m1 android imac win ios", key)
SCREWYOU3_HOOK_END("GameManager::init")

#include <Geode/modify/GameObject.hpp>

bool GameObject_isBasicEnterEffect_override() {
	return modUtils::chooseRandomNum(0, 1);
}

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

bool GameObject_shouldDrawEditorHitbox_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_belongsToGroup_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_canChangeCustomColor_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_canChangeMainColor_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_canChangeSecondaryColor_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_canRotateFree_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_didScaleXChange_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_didScaleYChange_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_dontCountTowardsLimit_override() {
	return modUtils::chooseRandomNum(0, 1);
}

const char* GameObject_getBallFrame_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameObject_getColorFrame_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameObject_getColorIndex_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameObject_getColorKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameObject_getGlowFrame_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameObject_getGroupDisabled_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameObject_getGroupID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameObject_getGroupString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameObject_getMainColorMode_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameObject_getObjectDirection_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GameObject_getObjectRadius_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameObject_getObjectZOrder_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameObject_getParentMode_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameObject_getSecondaryColorMode_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GameObject_getSlopeAngle_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GameObject_groupOpacityMod_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameObject_hasSecondaryColor_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_ignoreEditorDuration_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_ignoreEnter_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_ignoreFade_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isBasicTrigger_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isColorObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isColorTrigger_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isConfigurablePortal_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isEditorSpawnableTrigger_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isFacingDown_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isFacingLeft_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isSettingsObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isSpawnableTrigger_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isSpecialObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isSpeedObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isStoppableTrigger_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_isTrigger_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float GameObject_opacityModForMode_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
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

bool GameObject_shouldNotHideAnimFreeze_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_shouldShowPickupEffects_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_slopeFloorTop_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_slopeWallLeft_override() {
	return modUtils::chooseRandomNum(0, 1);
}

double GameObject_slopeYPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameObject_usesFreezeAnimation_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameObject_usesSpecialAnimation_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GameObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool isBasicEnterEffect(int id))
SCREWYOU3_HOOK_IMPL(GameObject, isBasicEnterEffect, " m1 android imac ios", id)
#endif
SCREWYOU3_HOOK(bool initWithTexture(cocos2d::CCTexture2D* texture))
SCREWYOU3_HOOK_IMPL(GameObject, initWithTexture, "m1 android imac win ios", texture)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(GameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK(bool isFlipX())
SCREWYOU3_HOOK_IMPL(GameObject, isFlipX, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool isFlipY())
SCREWYOU3_HOOK_IMPL(GameObject, isFlipY, "m1 android imac win ios", )
SCREWYOU3_HOOK(float getRScaleX())
SCREWYOU3_HOOK_IMPL(GameObject, getRScaleX, "m1 android imac win ios", )
SCREWYOU3_HOOK(float getRScaleY())
SCREWYOU3_HOOK_IMPL(GameObject, getRScaleY, "m1 android imac win ios", )
SCREWYOU3_HOOK(float getObjectRotation())
SCREWYOU3_HOOK_IMPL(GameObject, getObjectRotation, "m1 android imac win ios", )
SCREWYOU3_HOOK(int addToGroup(int id))
SCREWYOU3_HOOK_IMPL(GameObject, addToGroup, "m1 android imac win ios", id)
SCREWYOU3_HOOK(float spawnXPosition())
SCREWYOU3_HOOK_IMPL(GameObject, spawnXPosition, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldDrawEditorHitbox())
SCREWYOU3_HOOK_IMPL(GameObject, shouldDrawEditorHitbox, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool belongsToGroup(int group))
SCREWYOU3_HOOK_IMPL(GameObject, belongsToGroup, " m1 android imac ios", group)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canChangeCustomColor())
SCREWYOU3_HOOK_IMPL(GameObject, canChangeCustomColor, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canChangeMainColor())
SCREWYOU3_HOOK_IMPL(GameObject, canChangeMainColor, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canChangeSecondaryColor())
SCREWYOU3_HOOK_IMPL(GameObject, canChangeSecondaryColor, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canRotateFree())
SCREWYOU3_HOOK_IMPL(GameObject, canRotateFree, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool didScaleXChange())
SCREWYOU3_HOOK_IMPL(GameObject, didScaleXChange, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool didScaleYChange())
SCREWYOU3_HOOK_IMPL(GameObject, didScaleYChange, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool dontCountTowardsLimit())
SCREWYOU3_HOOK_IMPL(GameObject, dontCountTowardsLimit, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getBallFrame(int index))
SCREWYOU3_HOOK_IMPL(GameObject, getBallFrame, " m1 android imac ios", index)
#endif
SCREWYOU3_HOOK(gd::string getColorFrame(gd::string frame))
SCREWYOU3_HOOK_IMPL(GameObject, getColorFrame, "m1 android imac win ios", frame)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getColorIndex())
SCREWYOU3_HOOK_IMPL(GameObject, getColorIndex, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(gd::string getColorKey(bool isMainColor, bool colorGroups))
SCREWYOU3_HOOK_IMPL(GameObject, getColorKey, "m1 android imac win ios", isMainColor, colorGroups)
SCREWYOU3_HOOK(gd::string getGlowFrame(gd::string frame))
SCREWYOU3_HOOK_IMPL(GameObject, getGlowFrame, "m1 android imac win ios", frame)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool getGroupDisabled())
SCREWYOU3_HOOK_IMPL(GameObject, getGroupDisabled, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getGroupID(int index))
SCREWYOU3_HOOK_IMPL(GameObject, getGroupID, " m1 android imac ios", index)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getGroupString())
SCREWYOU3_HOOK_IMPL(GameObject, getGroupString, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getMainColorMode())
SCREWYOU3_HOOK_IMPL(GameObject, getMainColorMode, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(int getObjectDirection())
SCREWYOU3_HOOK_IMPL(GameObject, getObjectDirection, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getObjectRadius())
SCREWYOU3_HOOK_IMPL(GameObject, getObjectRadius, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getObjectZOrder())
SCREWYOU3_HOOK_IMPL(GameObject, getObjectZOrder, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(int getParentMode())
SCREWYOU3_HOOK_IMPL(GameObject, getParentMode, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getSecondaryColorMode())
SCREWYOU3_HOOK_IMPL(GameObject, getSecondaryColorMode, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getSlopeAngle())
SCREWYOU3_HOOK_IMPL(GameObject, getSlopeAngle, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(float groupOpacityMod())
SCREWYOU3_HOOK_IMPL(GameObject, groupOpacityMod, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool hasSecondaryColor())
SCREWYOU3_HOOK_IMPL(GameObject, hasSecondaryColor, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool ignoreEditorDuration())
SCREWYOU3_HOOK_IMPL(GameObject, ignoreEditorDuration, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool ignoreEnter())
SCREWYOU3_HOOK_IMPL(GameObject, ignoreEnter, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool ignoreFade())
SCREWYOU3_HOOK_IMPL(GameObject, ignoreFade, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(GameObject, init, " m1 android imac ios", frame)
#endif
SCREWYOU3_HOOK(bool isBasicTrigger())
SCREWYOU3_HOOK_IMPL(GameObject, isBasicTrigger, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isColorObject())
SCREWYOU3_HOOK_IMPL(GameObject, isColorObject, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isColorTrigger())
SCREWYOU3_HOOK_IMPL(GameObject, isColorTrigger, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isConfigurablePortal())
SCREWYOU3_HOOK_IMPL(GameObject, isConfigurablePortal, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isEditorSpawnableTrigger())
SCREWYOU3_HOOK_IMPL(GameObject, isEditorSpawnableTrigger, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool isFacingDown())
SCREWYOU3_HOOK_IMPL(GameObject, isFacingDown, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool isFacingLeft())
SCREWYOU3_HOOK_IMPL(GameObject, isFacingLeft, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isSettingsObject())
SCREWYOU3_HOOK_IMPL(GameObject, isSettingsObject, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool isSpawnableTrigger())
SCREWYOU3_HOOK_IMPL(GameObject, isSpawnableTrigger, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool isSpecialObject())
SCREWYOU3_HOOK_IMPL(GameObject, isSpecialObject, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isSpeedObject())
SCREWYOU3_HOOK_IMPL(GameObject, isSpeedObject, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isStoppableTrigger())
SCREWYOU3_HOOK_IMPL(GameObject, isStoppableTrigger, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool isTrigger())
SCREWYOU3_HOOK_IMPL(GameObject, isTrigger, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float opacityModForMode(int id, bool mainColor))
SCREWYOU3_HOOK_IMPL(GameObject, opacityModForMode, " m1 android imac ios", id, mainColor)
#endif
SCREWYOU3_HOOK(gd::string perspectiveColorFrame(char const* prefix, int index))
SCREWYOU3_HOOK_IMPL(GameObject, perspectiveColorFrame, "m1 android imac win ios", prefix, index)
SCREWYOU3_HOOK(gd::string perspectiveFrame(char const* prefix, int index))
SCREWYOU3_HOOK_IMPL(GameObject, perspectiveFrame, "m1 android imac win ios", prefix, index)
SCREWYOU3_HOOK(bool shouldBlendColor(GJSpriteColor* color, bool mainColor))
SCREWYOU3_HOOK_IMPL(GameObject, shouldBlendColor, "m1 android imac win ios", color, mainColor)
SCREWYOU3_HOOK(bool shouldLockX())
SCREWYOU3_HOOK_IMPL(GameObject, shouldLockX, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldNotHideAnimFreeze())
SCREWYOU3_HOOK_IMPL(GameObject, shouldNotHideAnimFreeze, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldShowPickupEffects())
SCREWYOU3_HOOK_IMPL(GameObject, shouldShowPickupEffects, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool slopeFloorTop())
SCREWYOU3_HOOK_IMPL(GameObject, slopeFloorTop, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool slopeWallLeft())
SCREWYOU3_HOOK_IMPL(GameObject, slopeWallLeft, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(double slopeYPos(GameObject* object))
SCREWYOU3_HOOK_IMPL(GameObject, slopeYPos, " m1 android imac", object)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(double slopeYPos(cocos2d::CCRect rect))
SCREWYOU3_HOOK_IMPL(GameObject, slopeYPos, " m1 android imac ios", rect)
#endif
SCREWYOU3_HOOK(double slopeYPos(float x))
SCREWYOU3_HOOK_IMPL(GameObject, slopeYPos, "m1 android imac win ios", x)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool usesFreezeAnimation())
SCREWYOU3_HOOK_IMPL(GameObject, usesFreezeAnimation, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool usesSpecialAnimation())
SCREWYOU3_HOOK_IMPL(GameObject, usesSpecialAnimation, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("GameObject::isBasicEnterEffect")

#include <Geode/modify/GameObjectCopy.hpp>

bool GameObjectCopy_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GameObjectCopy)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(GameObject* object))
SCREWYOU3_HOOK_IMPL(GameObjectCopy, init, " m1 android imac ios", object)
#endif
SCREWYOU3_HOOK_END("GameObjectCopy::init")

#include <Geode/modify/GameOptionsLayer.hpp>

bool GameOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GameOptionsLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(GJBaseGameLayer* baseGameLayer))
SCREWYOU3_HOOK_IMPL(GameOptionsLayer, init, " m1 android imac ios", baseGameLayer)
#endif
SCREWYOU3_HOOK_END("GameOptionsLayer::init")

#include <Geode/modify/GameOptionsTrigger.hpp>

gd::string GameOptionsTrigger_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameOptionsTrigger_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GameOptionsTrigger)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(GameOptionsTrigger, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(GameOptionsTrigger, init, " m1 android imac", frame)
#endif
SCREWYOU3_HOOK_END("GameOptionsTrigger::getSaveString")

#include <Geode/modify/GameStatsManager.hpp>

bool GameStatsManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameStatsManager_accountIDForIcon_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameStatsManager_areChallengesLoaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_areRewardsLoaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_awardSecretKey_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_canItemBeUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_claimListReward_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameStatsManager_countSecretChests_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_countUnlockedSecretChests_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getAwardedCurrencyForLevel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getAwardedDiamondsForLevel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getBaseCurrency_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getBaseCurrencyForLevel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getBaseDiamonds_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getBonusDiamonds_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameStatsManager_getChallengeKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameStatsManager_getCollectedCoinsForLevel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameStatsManager_getCurrencyKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameStatsManager_getDailyLevelKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameStatsManager_getDemonLevelKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameStatsManager_getEventRewardKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
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

gd::string GameStatsManager_getListRewardKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GameStatsManager_getMapPackKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameStatsManager_getNextGoldChestID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
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

int GameStatsManager_getSecretChestForItem_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

const char* GameStatsManager_getSecretCoinKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameStatsManager_getSecretOnlineRewardKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameStatsManager_getSpecialRewardDescription_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameStatsManager_getSpecialUnlockDescription_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GameStatsManager_getStat_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameStatsManager_getStatFromKey_override() {
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

bool GameStatsManager_hasCompletedDemonLevel_override() {
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

bool GameStatsManager_isGauntletChestUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isGauntletUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isItemEnabled_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isItemUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isPathChestUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isPathUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isSecretChestUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isSecretCoin_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isSecretCoinValid_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isSpecialChestLiteUnlockable_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isSpecialChestUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_isStoreItemUnlocked_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameStatsManager_keyCostForSecretChest_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GameStatsManager_purchaseItem_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameStatsManager_shouldAwardSecretKey_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GameStatsManager_starsForMapPack_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameStatsManager_usernameForAccountID_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GameStatsManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GameStatsManager, init, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int accountIDForIcon(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GameStatsManager, accountIDForIcon, " m1 android imac ios", id, type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool areChallengesLoaded())
SCREWYOU3_HOOK_IMPL(GameStatsManager, areChallengesLoaded, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool areRewardsLoaded())
SCREWYOU3_HOOK_IMPL(GameStatsManager, areRewardsLoaded, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool awardSecretKey())
SCREWYOU3_HOOK_IMPL(GameStatsManager, awardSecretKey, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canItemBeUnlocked(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GameStatsManager, canItemBeUnlocked, " m1 android imac", id, type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool claimListReward(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(GameStatsManager, claimListReward, " m1 android imac ios", list)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int countSecretChests(GJRewardType rewardType))
SCREWYOU3_HOOK_IMPL(GameStatsManager, countSecretChests, " m1 android imac ios", rewardType)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int countUnlockedSecretChests(GJRewardType rewardType))
SCREWYOU3_HOOK_IMPL(GameStatsManager, countUnlockedSecretChests, " m1 android imac ios", rewardType)
#endif
SCREWYOU3_HOOK(int getAwardedCurrencyForLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getAwardedCurrencyForLevel, "m1 android imac win ios", level)
SCREWYOU3_HOOK(int getAwardedDiamondsForLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getAwardedDiamondsForLevel, "m1 android imac win ios", level)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getBaseCurrency(int stars, bool mainLevel, int levelID))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getBaseCurrency, " m1 android imac ios", stars, mainLevel, levelID)
#endif
SCREWYOU3_HOOK(int getBaseCurrencyForLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getBaseCurrencyForLevel, "m1 android imac win ios", level)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getBaseDiamonds(int stars))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getBaseDiamonds, " m1 android imac ios", stars)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getBonusDiamonds(int stars))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getBonusDiamonds, " m1 android imac ios", stars)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getChallengeKey(GJChallengeItem* chal))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getChallengeKey, " m1 android imac ios", chal)
#endif
SCREWYOU3_HOOK(int getCollectedCoinsForLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getCollectedCoinsForLevel, "m1 android imac win ios", level)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getCurrencyKey(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getCurrencyKey, " m1 android imac ios", level)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getDailyLevelKey(int dailyID))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getDailyLevelKey, " m1 android imac ios", dailyID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getDemonLevelKey(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getDemonLevelKey, " m1 android imac ios", level)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getEventRewardKey(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getEventRewardKey, " m1 android imac", id)
#endif
SCREWYOU3_HOOK(gd::string getGauntletRewardKey(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getGauntletRewardKey, "m1 android imac win ios", id)
SCREWYOU3_HOOK(gd::string getItemKey(int id, int type))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getItemKey, "m1 android imac win ios", id, type)
SCREWYOU3_HOOK(int getItemUnlockState(int itemID, UnlockType unlockType))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getItemUnlockState, "m1 android imac win ios", itemID, unlockType)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getItemUnlockStateLite(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getItemUnlockStateLite, "m1 imac android", id, type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getLevelKey(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getLevelKey, " m1 android imac ios", level)
#endif
SCREWYOU3_HOOK(gd::string getLevelKey(int levelID, bool isOnline, bool isDaily, bool isGauntlet, bool isEvent))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getLevelKey, "m1 android imac win ios", levelID, isOnline, isDaily, isGauntlet, isEvent)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getListRewardKey(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getListRewardKey, " m1 android imac ios", list)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getMapPackKey(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getMapPackKey, " m1 android imac", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getNextGoldChestID())
SCREWYOU3_HOOK_IMPL(GameStatsManager, getNextGoldChestID, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getNextVideoAdReward())
SCREWYOU3_HOOK_IMPL(GameStatsManager, getNextVideoAdReward, "m1 imac android", )
#endif
SCREWYOU3_HOOK(gd::string getPathRewardKey(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getPathRewardKey, "m1 android imac win ios", id)
SCREWYOU3_HOOK(gd::string getRewardKey(GJRewardType type, int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getRewardKey, "m1 android imac win ios", type, id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getSecretChestForItem(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getSecretChestForItem, " m1 android imac ios", id, type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getSecretCoinKey(char const* key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getSecretCoinKey, " m1 android imac", key)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getSecretOnlineRewardKey(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getSecretOnlineRewardKey, " m1 android imac ios", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getSpecialRewardDescription(gd::string key, bool unused))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getSpecialRewardDescription, " m1 android imac ios", key, unused)
#endif
SCREWYOU3_HOOK(gd::string getSpecialUnlockDescription(int id, UnlockType type, bool unused))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getSpecialUnlockDescription, "m1 android imac win ios", id, type, unused)
SCREWYOU3_HOOK(int getStat(char const* key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getStat, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getStatFromKey(StatKey key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, getStatFromKey, " m1 android imac ios", key)
#endif
SCREWYOU3_HOOK(int getTotalCollectedCurrency())
SCREWYOU3_HOOK_IMPL(GameStatsManager, getTotalCollectedCurrency, "m1 android imac win ios", )
SCREWYOU3_HOOK(int getTotalCollectedDiamonds())
SCREWYOU3_HOOK_IMPL(GameStatsManager, getTotalCollectedDiamonds, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool hasClaimedListReward(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasClaimedListReward, "m1 android imac win ios", list)
SCREWYOU3_HOOK(bool hasCompletedChallenge(GJChallengeItem* item))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedChallenge, "m1 android imac win ios", item)
SCREWYOU3_HOOK(bool hasCompletedDailyLevel(int dailyID))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedDailyLevel, "m1 android imac win ios", dailyID)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool hasCompletedDemonLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedDemonLevel, " m1 android imac ios", level)
#endif
SCREWYOU3_HOOK(bool hasCompletedGauntletLevel(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedGauntletLevel, "m1 android imac win ios", id)
SCREWYOU3_HOOK(bool hasCompletedLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedLevel, "m1 android imac win ios", level)
SCREWYOU3_HOOK(bool hasCompletedMainLevel(int levelID))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedMainLevel, "m1 android imac win ios", levelID)
SCREWYOU3_HOOK(bool hasCompletedMapPack(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedMapPack, "m1 android imac win ios", id)
SCREWYOU3_HOOK(bool hasCompletedOnlineLevel(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedOnlineLevel, "m1 android imac win ios", id)
SCREWYOU3_HOOK(bool hasCompletedStarLevel(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasCompletedStarLevel, "m1 android imac win ios", level)
SCREWYOU3_HOOK(bool hasPendingUserCoin(char const* key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasPendingUserCoin, "m1 android imac win ios", key)
SCREWYOU3_HOOK(bool hasRewardBeenCollected(GJRewardType type, int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasRewardBeenCollected, "m1 android imac win ios", type, id)
SCREWYOU3_HOOK(bool hasSecretCoin(char const* key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasSecretCoin, "m1 android imac win ios", key)
SCREWYOU3_HOOK(bool hasUserCoin(char const* key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, hasUserCoin, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isGauntletChestUnlocked(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isGauntletChestUnlocked, " m1 android imac ios", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isGauntletUnlocked(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isGauntletUnlocked, " m1 android imac ios", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isItemEnabled(UnlockType type, int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isItemEnabled, " m1 android imac ios", type, id)
#endif
SCREWYOU3_HOOK(bool isItemUnlocked(UnlockType type, int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isItemUnlocked, "m1 android imac win ios", type, id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isPathChestUnlocked(int path))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isPathChestUnlocked, " m1 android imac ios", path)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isPathUnlocked(StatKey key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isPathUnlocked, " m1 android imac", key)
#endif
SCREWYOU3_HOOK(bool isSecretChestUnlocked(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isSecretChestUnlocked, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isSecretCoin(gd::string key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isSecretCoin, " m1 android imac", key)
#endif
SCREWYOU3_HOOK(bool isSecretCoinValid(gd::string key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isSecretCoinValid, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isSpecialChestLiteUnlockable(gd::string key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isSpecialChestLiteUnlockable, " m1 android imac", key)
#endif
SCREWYOU3_HOOK(bool isSpecialChestUnlocked(gd::string key))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isSpecialChestUnlocked, "m1 android imac win ios", key)
SCREWYOU3_HOOK(bool isStoreItemUnlocked(int index))
SCREWYOU3_HOOK_IMPL(GameStatsManager, isStoreItemUnlocked, "m1 android imac win ios", index)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int keyCostForSecretChest(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, keyCostForSecretChest, " m1 android imac ios", id)
#endif
SCREWYOU3_HOOK(bool purchaseItem(int index))
SCREWYOU3_HOOK_IMPL(GameStatsManager, purchaseItem, "m1 android imac win ios", index)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldAwardSecretKey())
SCREWYOU3_HOOK_IMPL(GameStatsManager, shouldAwardSecretKey, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int starsForMapPack(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, starsForMapPack, " m1 android imac ios", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string usernameForAccountID(int id))
SCREWYOU3_HOOK_IMPL(GameStatsManager, usernameForAccountID, " m1 android imac ios", id)
#endif
SCREWYOU3_HOOK_END("GameStatsManager::init")

#include <Geode/modify/GameToolbox.hpp>

float GameToolbox_bounceTime_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameToolbox_createHashString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GameToolbox_doWeHaveInternet_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameToolbox_easeToText_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

uint64_t GameToolbox_fast_rand_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GameToolbox_fast_rand_0_1_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GameToolbox_fast_rand_minus1_1_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GameToolbox_gen_random_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float GameToolbox_getEasedValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

uint64_t GameToolbox_getfast_srand_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GameToolbox_getInvertedEasing_override() {
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

bool GameToolbox_isIOS_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GameToolbox_isRateEasing_override() {
	return modUtils::chooseRandomNum(0, 1);
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

bool GameToolbox_saveStringToFile_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GameToolbox_stringFromHSV_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GameToolbox_timestampToHumanReadable_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GameToolbox)
SCREWYOU3_HOOK(static float bounceTime(float time))
SCREWYOU3_HOOK_IMPL(GameToolbox, bounceTime, "m1 android imac win ios", time)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string createHashString(gd::string const& str, int length))
SCREWYOU3_HOOK_IMPL(GameToolbox, createHashString, " m1 android imac", str, length)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool doWeHaveInternet())
SCREWYOU3_HOOK_IMPL(GameToolbox, doWeHaveInternet, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(static gd::string easeToText(int easingType))
SCREWYOU3_HOOK_IMPL(GameToolbox, easeToText, "m1 android imac win ios", easingType)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static uint64_t fast_rand())
SCREWYOU3_HOOK_IMPL(GameToolbox, fast_rand, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static float fast_rand_0_1())
SCREWYOU3_HOOK_IMPL(GameToolbox, fast_rand_0_1, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static float fast_rand_minus1_1())
SCREWYOU3_HOOK_IMPL(GameToolbox, fast_rand_minus1_1, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(static gd::string gen_random(int length))
SCREWYOU3_HOOK_IMPL(GameToolbox, gen_random, "m1 android imac win ios", length)
SCREWYOU3_HOOK(static float getEasedValue(float value, int easingType, float easingRate))
SCREWYOU3_HOOK_IMPL(GameToolbox, getEasedValue, "m1 android imac win ios", value, easingType, easingRate)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static uint64_t getfast_srand())
SCREWYOU3_HOOK_IMPL(GameToolbox, getfast_srand, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static int getInvertedEasing(int easingType))
SCREWYOU3_HOOK_IMPL(GameToolbox, getInvertedEasing, " m1 android imac", easingType)
#endif
SCREWYOU3_HOOK(static gd::string getResponse(cocos2d::extension::CCHttpResponse* response))
SCREWYOU3_HOOK_IMPL(GameToolbox, getResponse, "m1 android imac win ios", response)
SCREWYOU3_HOOK(static gd::string getTimeString(int seconds, bool noSeconds))
SCREWYOU3_HOOK_IMPL(GameToolbox, getTimeString, "m1 android imac win ios", seconds, noSeconds)
SCREWYOU3_HOOK(static gd::string intToShortString(int value))
SCREWYOU3_HOOK_IMPL(GameToolbox, intToShortString, "m1 android imac win ios", value)
SCREWYOU3_HOOK(static gd::string intToString(int value))
SCREWYOU3_HOOK_IMPL(GameToolbox, intToString, "m1 android imac win ios", value)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool isIOS())
SCREWYOU3_HOOK_IMPL(GameToolbox, isIOS, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool isRateEasing(int easingType))
SCREWYOU3_HOOK_IMPL(GameToolbox, isRateEasing, " m1 android imac ios", easingType)
#endif
SCREWYOU3_HOOK(static gd::string msToTimeString(int milliseconds, int formattingMode))
SCREWYOU3_HOOK_IMPL(GameToolbox, msToTimeString, "m1 android imac win ios", milliseconds, formattingMode)
SCREWYOU3_HOOK(static gd::string pointsToString(int points))
SCREWYOU3_HOOK_IMPL(GameToolbox, pointsToString, "m1 android imac win ios", points)
SCREWYOU3_HOOK(static gd::string saveParticleToString(cocos2d::CCParticleSystemQuad* system))
SCREWYOU3_HOOK_IMPL(GameToolbox, saveParticleToString, "m1 android imac win ios", system)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool saveStringToFile(gd::string const& path, gd::string const& content))
SCREWYOU3_HOOK_IMPL(GameToolbox, saveStringToFile, " m1 android imac", path, content)
#endif
SCREWYOU3_HOOK(static gd::string stringFromHSV(cocos2d::ccHSVValue value, char const* separator))
SCREWYOU3_HOOK_IMPL(GameToolbox, stringFromHSV, "m1 android imac win ios", value, separator)
SCREWYOU3_HOOK(static gd::string timestampToHumanReadable(time_t timestamp))
SCREWYOU3_HOOK_IMPL(GameToolbox, timestampToHumanReadable, "m1 android imac win ios", timestamp)
SCREWYOU3_HOOK_END("GameToolbox::bounceTime")

#include <Geode/modify/GauntletLayer.hpp>

bool GauntletLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GauntletLayer)
SCREWYOU3_HOOK(bool init(GauntletType type))
SCREWYOU3_HOOK_IMPL(GauntletLayer, init, "m1 android imac win ios", type)
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
SCREWYOU3_HOOK_IMPL(GauntletNode, frameForType, "m1 android imac win ios", type)
SCREWYOU3_HOOK(static gd::string nameForType(GauntletType type))
SCREWYOU3_HOOK_IMPL(GauntletNode, nameForType, "m1 android imac win ios", type)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(GJMapPack* gauntlet))
SCREWYOU3_HOOK_IMPL(GauntletNode, init, " m1 android imac ios", gauntlet)
#endif
SCREWYOU3_HOOK_END("GauntletNode::frameForType")

#include <Geode/modify/GauntletSelectLayer.hpp>

bool GauntletSelectLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GauntletSelectLayer)
SCREWYOU3_HOOK(bool init(int unused))
SCREWYOU3_HOOK_IMPL(GauntletSelectLayer, init, "m1 android imac win ios", unused)
SCREWYOU3_HOOK_END("GauntletSelectLayer::init")

#include <Geode/modify/GauntletSprite.hpp>

bool GauntletSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float GauntletSprite_luminanceForType_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GauntletSprite)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(GauntletType type, bool locked))
SCREWYOU3_HOOK_IMPL(GauntletSprite, init, " m1 android imac ios", type, locked)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float luminanceForType(GauntletType type))
SCREWYOU3_HOOK_IMPL(GauntletSprite, luminanceForType, " m1 android imac ios", type)
#endif
SCREWYOU3_HOOK_END("GauntletSprite::init")

#include <Geode/modify/GhostTrailEffect.hpp>

bool GhostTrailEffect_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GhostTrailEffect)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GhostTrailEffect, init, "m1 android imac win ios", )
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

bool GJAccountManager_isDLActive_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJAccountManager_syncAccount_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJAccountManager_updateAccountSettings_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJAccountManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJAccountManager, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool backupAccount(gd::string url))
SCREWYOU3_HOOK_IMPL(GJAccountManager, backupAccount, "m1 android imac win ios", url)
SCREWYOU3_HOOK(bool getAccountBackupURL())
SCREWYOU3_HOOK_IMPL(GJAccountManager, getAccountBackupURL, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool getAccountSyncURL())
SCREWYOU3_HOOK_IMPL(GJAccountManager, getAccountSyncURL, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getShaPassword(gd::string password))
SCREWYOU3_HOOK_IMPL(GJAccountManager, getShaPassword, "m1 android imac win ios", password)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isDLActive(char const* tag))
SCREWYOU3_HOOK_IMPL(GJAccountManager, isDLActive, " m1 android imac", tag)
#endif
SCREWYOU3_HOOK(bool syncAccount(gd::string url))
SCREWYOU3_HOOK_IMPL(GJAccountManager, syncAccount, "m1 android imac win ios", url)
SCREWYOU3_HOOK(bool updateAccountSettings(int messageStatus, int friendRequestStatus, int commentStatus, gd::string youtube, gd::string twitter, gd::string twitch, gd::string instagram, gd::string tiktok, gd::string discord, gd::string custom))
SCREWYOU3_HOOK_IMPL(GJAccountManager, updateAccountSettings, "m1 android imac win ios", messageStatus, friendRequestStatus, commentStatus, youtube, twitter, twitch, instagram, tiktok, discord, custom)
SCREWYOU3_HOOK_END("GJAccountManager::init")

#include <Geode/modify/GJAccountSettingsLayer.hpp>

bool GJAccountSettingsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJAccountSettingsLayer)
SCREWYOU3_HOOK(bool init(int accountID))
SCREWYOU3_HOOK_IMPL(GJAccountSettingsLayer, init, "m1 android imac win ios", accountID)
SCREWYOU3_HOOK_END("GJAccountSettingsLayer::init")

#include <Geode/modify/GJActionManager.hpp>

bool GJActionManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJActionManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJActionManager, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJActionManager::init")

#include <Geode/modify/GJBaseGameLayer.hpp>

float GJBaseGameLayer_convertToClosestDirection_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJBaseGameLayer_gameEventToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJBaseGameLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float GJBaseGameLayer_opacityForObject_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJBaseGameLayer_checkSpawnAbuse_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_addGuideArt_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJBaseGameLayer_atlasValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJBaseGameLayer_buttonIDToButton_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJBaseGameLayer_buttonIsRelevant_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_canBeActivatedByPlayer_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_canProcessSFX_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_canTouchObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_checkCollision_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJBaseGameLayer_checkCollisions_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJBaseGameLayer_countCollectedUserCoins_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJBaseGameLayer_generateEnterEasingBuffer_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJBaseGameLayer_getAreaObjectValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJBaseGameLayer_getBumpMod_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJBaseGameLayer_getCameraEdgeValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJBaseGameLayer_getCapacityString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float GJBaseGameLayer_getEasedAreaValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJBaseGameLayer_getEnterEasingKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJBaseGameLayer_getEnterEasingValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJBaseGameLayer_getGroundHeight_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJBaseGameLayer_getGroundHeightForMode_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJBaseGameLayer_getGroupParentsString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
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

double GJBaseGameLayer_getModifiedDelta_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJBaseGameLayer_getParticleKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJBaseGameLayer_getParticleKey2_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GJBaseGameLayer_getPlayerButtonID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJBaseGameLayer_getPlayTimerFullSeconds_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJBaseGameLayer_getPlayTimerMilli_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJBaseGameLayer_getRecordExtra_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJBaseGameLayer_getRecordString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float GJBaseGameLayer_getScaledGroundHeight_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJBaseGameLayer_getSpecialKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJBaseGameLayer_getTargetFlyCameraY_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJBaseGameLayer_hasItem_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_hasUniqueCoin_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_isButtonAllowed_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_isFlipping_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_isPlayer2Button_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJBaseGameLayer_maxZOrderForShaderZ_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJBaseGameLayer_minZOrderForShaderZ_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJBaseGameLayer_objectIntersectsCircle_override() {
	return modUtils::chooseRandomNum(0, 1);
}

double GJBaseGameLayer_performMathOperation_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

double GJBaseGameLayer_performMathRounding_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJBaseGameLayer_playerCircleCollision_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_playerIntersectsCircle_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_playerWasTouchingObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_processSongState_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_rectIntersectsCircle_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJBaseGameLayer_registerSpawnRemap_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJBaseGameLayer_resetAreaObjectValues_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_shouldExitHackedLevel_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJBaseGameLayer_shouldUseSubstepForButton_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float GJBaseGameLayer_volumeForProximityEffect_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GJBaseGameLayer)
SCREWYOU3_HOOK(static float convertToClosestDirection(float angle, float bound))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, convertToClosestDirection, "m1 android imac win ios", angle, bound)
SCREWYOU3_HOOK(static gd::string gameEventToString(GJGameEvent event))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, gameEventToString, "m1 android imac win ios", event)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(float opacityForObject(GameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, opacityForObject, "m1 android imac win ios", object)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool checkSpawnAbuse())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, checkSpawnAbuse, "ios android", )
#endif
SCREWYOU3_HOOK(bool addGuideArt(GameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, addGuideArt, "m1 android imac win ios", object)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int atlasValue(int atlas))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, atlasValue, " m1 android imac", atlas)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int buttonIDToButton(int id))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, buttonIDToButton, " m1 android imac", id)
#endif
SCREWYOU3_HOOK(bool buttonIsRelevant(PlayerButtonCommand const& button))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, buttonIsRelevant, "m1 android imac win ios", button)
SCREWYOU3_HOOK(bool canBeActivatedByPlayer(PlayerObject* player, EffectGameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, canBeActivatedByPlayer, "m1 android imac win ios", player, object)
SCREWYOU3_HOOK(bool canProcessSFX(SFXTriggerState& state, gd::unordered_map<int, int>& stateIndices, gd::unordered_map<int, float>& times, gd::vector<SFXTriggerState>& states))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, canProcessSFX, "m1 android imac win ios", state, stateIndices, times, states)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canTouchObject(GameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, canTouchObject, " m1 android imac", object)
#endif
SCREWYOU3_HOOK(bool checkCollision(int blockAID, int blockBID))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, checkCollision, "m1 android imac win ios", blockAID, blockBID)
SCREWYOU3_HOOK(int checkCollisions(PlayerObject* object, float dt, bool ignoreDamage))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, checkCollisions, "m1 android imac win ios", object, dt, ignoreDamage)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int countCollectedUserCoins())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, countCollectedUserCoins, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(int generateEnterEasingBuffer(int easingType, float easingRate))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, generateEnterEasingBuffer, "m1 android imac win ios", easingType, easingRate)
SCREWYOU3_HOOK(float getAreaObjectValue(EnterEffectInstance* instance, GameObject* object, cocos2d::CCPoint& position, bool& show))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getAreaObjectValue, "m1 android imac win ios", instance, object, position, show)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getBumpMod(PlayerObject* player, int type))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getBumpMod, " m1 android imac ios", player, type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getCameraEdgeValue(int type))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getCameraEdgeValue, " m1 android imac ios", type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getCapacityString())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getCapacityString, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getEasedAreaValue(GameObject* object, EnterEffectInstance* instance, float value, bool show, int index))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getEasedAreaValue, "m1 android imac win", object, instance, value, show, index)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getEnterEasingKey(int easingType, float easingRate))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getEnterEasingKey, " m1 android imac", easingType, easingRate)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getEnterEasingValue(float value, int easingType, float easingRate, int easingBuffer))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getEnterEasingValue, " m1 android imac ios", value, easingType, easingRate, easingBuffer)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getGroundHeight(PlayerObject* player, int type))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getGroundHeight, " m1 android imac ios", player, type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getGroundHeightForMode(int type))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getGroundHeightForMode, "m1 android imac win", type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getGroupParentsString(GameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getGroupParentsString, " m1 android imac ios", object)
#endif
SCREWYOU3_HOOK(double getItemValue(int type, int id))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getItemValue, "m1 android imac win ios", type, id)
SCREWYOU3_HOOK(float getMaxPortalY())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getMaxPortalY, "m1 android imac win ios", )
SCREWYOU3_HOOK(float getMinDistance(cocos2d::CCPoint position, cocos2d::CCArray* objects, float minNear, int mode))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getMinDistance, "m1 android imac win ios", position, objects, minNear, mode)
SCREWYOU3_HOOK(float getMinPortalY())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getMinPortalY, "m1 android imac win ios", )
SCREWYOU3_HOOK(double getModifiedDelta(float dt))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getModifiedDelta, "m1 android imac win ios", dt)
SCREWYOU3_HOOK(gd::string getParticleKey(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getParticleKey, "m1 android imac win ios", objectType, plistName, tag, positionType)
SCREWYOU3_HOOK(gd::string getParticleKey2(gd::string key))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getParticleKey2, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getPlayerButtonID(int button, bool player2))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getPlayerButtonID, " m1 android imac ios", button, player2)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getPlayTimerFullSeconds())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getPlayTimerFullSeconds, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getPlayTimerMilli())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getPlayTimerMilli, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getRecordExtra())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getRecordExtra, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(gd::string getRecordString(bool compress))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getRecordString, "m1 android imac win ios", compress)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getScaledGroundHeight(float height))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getScaledGroundHeight, " m1 android imac", height)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getSpecialKey(int groupID, bool ignoreGroupParent, bool ignoreLinkedObjects))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getSpecialKey, " m1 android imac", groupID, ignoreGroupParent, ignoreLinkedObjects)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getTargetFlyCameraY(GameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, getTargetFlyCameraY, " m1 android imac ios", object)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool hasItem(int id))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, hasItem, " m1 android imac ios", id)
#endif
SCREWYOU3_HOOK(bool hasUniqueCoin(EffectGameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, hasUniqueCoin, "m1 android imac win ios", object)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isButtonAllowed(bool down, int button, bool isPlayer1))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, isButtonAllowed, "android", down, button, isPlayer1)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isFlipping())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, isFlipping, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isPlayer2Button(int button))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, isPlayer2Button, " m1 android imac", button)
#endif
SCREWYOU3_HOOK(int maxZOrderForShaderZ(int zLayer))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, maxZOrderForShaderZ, "m1 android imac win ios", zLayer)
SCREWYOU3_HOOK(int minZOrderForShaderZ(int zLayer))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, minZOrderForShaderZ, "m1 android imac win ios", zLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool objectIntersectsCircle(GameObject* object, GameObject* circle))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, objectIntersectsCircle, " m1 android imac ios", object, circle)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(double performMathOperation(double operand1, double operand2, int operation))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, performMathOperation, " m1 android imac", operand1, operand2, operation)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(double performMathRounding(double value, int type))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, performMathRounding, " m1 android imac", value, type)
#endif
SCREWYOU3_HOOK(bool playerCircleCollision(PlayerObject* player, GameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, playerCircleCollision, "m1 android imac win ios", player, object)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool playerIntersectsCircle(PlayerObject* player, GameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, playerIntersectsCircle, " m1 android imac ios", player, object)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool playerWasTouchingObject(PlayerObject* player, GameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, playerWasTouchingObject, " m1 android imac", player, object)
#endif
SCREWYOU3_HOOK(bool processSongState(int musicID, float spawnDelay, float levelTime, int songOffset, float volume, float speed, gd::vector<SongTriggerState>* states, SongTriggerGameObject* object))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, processSongState, "m1 android imac win ios", musicID, spawnDelay, levelTime, songOffset, volume, speed, states, object)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool rectIntersectsCircle(cocos2d::CCRect rect, cocos2d::CCPoint center, float radius))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, rectIntersectsCircle, " m1 android imac ios", rect, center, radius)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int registerSpawnRemap(gd::vector<ChanceObject>& spawnRemap))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, registerSpawnRemap, " m1 android imac ios", spawnRemap)
#endif
SCREWYOU3_HOOK(bool resetAreaObjectValues(GameObject* object, bool update))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, resetAreaObjectValues, "m1 android imac win ios", object, update)
SCREWYOU3_HOOK(bool shouldExitHackedLevel())
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, shouldExitHackedLevel, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldUseSubstepForButton(float dt))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, shouldUseSubstepForButton, " m1 android imac ios", dt)
#endif
SCREWYOU3_HOOK(float volumeForProximityEffect(SFXTriggerInstance& instance))
SCREWYOU3_HOOK_IMPL(GJBaseGameLayer, volumeForProximityEffect, "m1 android imac win ios", instance)
SCREWYOU3_HOOK_END("GJBaseGameLayer::convertToClosestDirection")

#include <Geode/modify/GJBigSprite.hpp>

bool GJBigSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJBigSprite)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJBigSprite, init, "m1 imac android", )
#endif
SCREWYOU3_HOOK_END("GJBigSprite::init")

#include <Geode/modify/GJBigSpriteNode.hpp>

bool GJBigSpriteNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJBigSpriteNode)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJBigSpriteNode, init, "m1 imac android", )
#endif
SCREWYOU3_HOOK_END("GJBigSpriteNode::init")

#include <Geode/modify/GJChallengeItem.hpp>

bool GJChallengeItem_canEncode_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJChallengeItem_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJChallengeItem)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canEncode())
SCREWYOU3_HOOK_IMPL(GJChallengeItem, canEncode, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(GJChallengeType challengeType, int goal, int reward, int timeLeft, gd::string questName))
SCREWYOU3_HOOK_IMPL(GJChallengeItem, init, " m1 android imac ios", challengeType, goal, reward, timeLeft, questName)
#endif
SCREWYOU3_HOOK_END("GJChallengeItem::canEncode")

#include <Geode/modify/GJChestSprite.hpp>

bool GJChestSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJChestSprite)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int chestType))
SCREWYOU3_HOOK_IMPL(GJChestSprite, init, " m1 android imac ios", chestType)
#endif
SCREWYOU3_HOOK_END("GJChestSprite::init")

#include <Geode/modify/GJColorSetupLayer.hpp>

bool GJColorSetupLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJColorSetupLayer)
SCREWYOU3_HOOK(bool init(LevelSettingsObject* object))
SCREWYOU3_HOOK_IMPL(GJColorSetupLayer, init, "m1 android imac win ios", object)
SCREWYOU3_HOOK_END("GJColorSetupLayer::init")

#include <Geode/modify/GJComment.hpp>

bool GJComment_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJComment)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJComment, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJComment::init")

#include <Geode/modify/GJCommentListLayer.hpp>

bool GJCommentListLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJCommentListLayer)
SCREWYOU3_HOOK(bool init(BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, bool blueBorder))
SCREWYOU3_HOOK_IMPL(GJCommentListLayer, init, "m1 android imac win ios", listView, title, color, width, height, blueBorder)
SCREWYOU3_HOOK_END("GJCommentListLayer::init")

#include <Geode/modify/GJDifficultySprite.hpp>

gd::string GJDifficultySprite_getDifficultyFrame_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJDifficultySprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJDifficultySprite)
SCREWYOU3_HOOK(static gd::string getDifficultyFrame(int difficulty, GJDifficultyName name))
SCREWYOU3_HOOK_IMPL(GJDifficultySprite, getDifficultyFrame, "m1 android imac win ios", difficulty, name)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int difficulty, GJDifficultyName name))
SCREWYOU3_HOOK_IMPL(GJDifficultySprite, init, " m1 android imac ios", difficulty, name)
#endif
SCREWYOU3_HOOK_END("GJDifficultySprite::getDifficultyFrame")

#include <Geode/modify/GJDropDownLayer.hpp>

bool GJDropDownLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJDropDownLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJDropDownLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(GJDropDownLayer, ccTouchBegan, " m1 android imac ios", touch, event)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* title))
SCREWYOU3_HOOK_IMPL(GJDropDownLayer, init, " m1 android imac ios", title)
#endif
SCREWYOU3_HOOK(bool init(char const* title, float height, bool noBack))
SCREWYOU3_HOOK_IMPL(GJDropDownLayer, init, "m1 android imac win ios", title, height, noBack)
SCREWYOU3_HOOK_END("GJDropDownLayer::ccTouchBegan")

#include <Geode/modify/GJEffectManager.hpp>

bool GJEffectManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float GJEffectManager_activeOpacityForIndex_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJEffectManager_checkCollision_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJEffectManager_colorExists_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJEffectManager_countForItem_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJEffectManager_getPersistentStateString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJEffectManager_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJEffectManager_hasActiveDualTouch_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJEffectManager_hasBeenTriggered_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJEffectManager_hasPulseEffectForGroupID_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJEffectManager_isGroupEnabled_override() {
	return modUtils::chooseRandomNum(0, 1);
}

const char* GJEffectManager_keyForGroupIDColor_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float GJEffectManager_opacityForIndex_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJEffectManager_opacityModForGroup_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJEffectManager_shouldBlend_override() {
	return modUtils::chooseRandomNum(0, 1);
}

double GJEffectManager_timeForItem_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJEffectManager_timerExists_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJEffectManager_wasFollowing_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJEffectManager_wouldCreateLoop_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJEffectManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJEffectManager, init, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float activeOpacityForIndex(int index))
SCREWYOU3_HOOK_IMPL(GJEffectManager, activeOpacityForIndex, " m1 android imac ios", index)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool checkCollision(int const& blockAID, int const& blockBID))
SCREWYOU3_HOOK_IMPL(GJEffectManager, checkCollision, " m1 android imac ios", blockAID, blockBID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool colorExists(int col))
SCREWYOU3_HOOK_IMPL(GJEffectManager, colorExists, " m1 android imac ios", col)
#endif
SCREWYOU3_HOOK(int countForItem(int id))
SCREWYOU3_HOOK_IMPL(GJEffectManager, countForItem, "m1 android imac win ios", id)
SCREWYOU3_HOOK(gd::string getPersistentStateString())
SCREWYOU3_HOOK_IMPL(GJEffectManager, getPersistentStateString, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getSaveString())
SCREWYOU3_HOOK_IMPL(GJEffectManager, getSaveString, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool hasActiveDualTouch())
SCREWYOU3_HOOK_IMPL(GJEffectManager, hasActiveDualTouch, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool hasBeenTriggered(int objectUniqueID, int playerUniqueID))
SCREWYOU3_HOOK_IMPL(GJEffectManager, hasBeenTriggered, " m1 android imac ios", objectUniqueID, playerUniqueID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool hasPulseEffectForGroupID(int id))
SCREWYOU3_HOOK_IMPL(GJEffectManager, hasPulseEffectForGroupID, " m1 android imac", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isGroupEnabled(int id))
SCREWYOU3_HOOK_IMPL(GJEffectManager, isGroupEnabled, " m1 android imac ios", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* keyForGroupIDColor(int id, cocos2d::ccColor3B const& color, bool mainColor))
SCREWYOU3_HOOK_IMPL(GJEffectManager, keyForGroupIDColor, " m1 android imac", id, color, mainColor)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float opacityForIndex(int index))
SCREWYOU3_HOOK_IMPL(GJEffectManager, opacityForIndex, " m1 android imac", index)
#endif
SCREWYOU3_HOOK(float opacityModForGroup(int id))
SCREWYOU3_HOOK_IMPL(GJEffectManager, opacityModForGroup, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldBlend(int id))
SCREWYOU3_HOOK_IMPL(GJEffectManager, shouldBlend, " m1 android imac ios", id)
#endif
SCREWYOU3_HOOK(double timeForItem(int id))
SCREWYOU3_HOOK_IMPL(GJEffectManager, timeForItem, "m1 android imac win ios", id)
SCREWYOU3_HOOK(bool timerExists(int id))
SCREWYOU3_HOOK_IMPL(GJEffectManager, timerExists, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool wasFollowing(int targetID, int targetPosID))
SCREWYOU3_HOOK_IMPL(GJEffectManager, wasFollowing, " m1 android imac ios", targetID, targetPosID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool wouldCreateLoop(InheritanceNode* node, int id))
SCREWYOU3_HOOK_IMPL(GJEffectManager, wouldCreateLoop, "m1 android imac win", node, id)
#endif
SCREWYOU3_HOOK_END("GJEffectManager::init")

#include <Geode/modify/GJFlyGroundLayer.hpp>

bool GJFlyGroundLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJFlyGroundLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJFlyGroundLayer, init, "m1 imac android", )
#endif
SCREWYOU3_HOOK_END("GJFlyGroundLayer::init")

#include <Geode/modify/GJFollowCommandLayer.hpp>

bool GJFollowCommandLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJFollowCommandLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(GJFollowCommandLayer, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("GJFollowCommandLayer::init")

#include <Geode/modify/GJFriendRequest.hpp>

bool GJFriendRequest_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJFriendRequest)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJFriendRequest, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJFriendRequest::init")

#include <Geode/modify/GJGameLevel.hpp>

int GJGameLevel_demonIconForDifficulty_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJGameLevel_getLengthKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJGameLevel_lengthKeyToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJGameLevel_canEncode_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJGameLevel_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJGameLevel_areCoinsVerified_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GJGameLevel_generateSettingsString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
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

int GJGameLevel_getNormalPercent_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string GJGameLevel_getSongName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJGameLevel_getUnpackedLevelDescription_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJGameLevel_isPlatformer_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GJGameLevel_scoreVectorToString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJGameLevel_shouldCheatReset_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJGameLevel)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static int demonIconForDifficulty(DemonDifficultyType type))
SCREWYOU3_HOOK_IMPL(GJGameLevel, demonIconForDifficulty, " m1 android imac ios", type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static int getLengthKey(int length, bool platformer))
SCREWYOU3_HOOK_IMPL(GJGameLevel, getLengthKey, " m1 android imac ios", length, platformer)
#endif
SCREWYOU3_HOOK(static gd::string lengthKeyToString(int key))
SCREWYOU3_HOOK_IMPL(GJGameLevel, lengthKeyToString, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canEncode())
SCREWYOU3_HOOK_IMPL(GJGameLevel, canEncode, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJGameLevel, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool areCoinsVerified())
SCREWYOU3_HOOK_IMPL(GJGameLevel, areCoinsVerified, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string generateSettingsString())
SCREWYOU3_HOOK_IMPL(GJGameLevel, generateSettingsString, " m1 android imac", )
#endif
SCREWYOU3_HOOK(gd::string getAudioFileName())
SCREWYOU3_HOOK_IMPL(GJGameLevel, getAudioFileName, "m1 android imac win ios", )
SCREWYOU3_HOOK(int getAverageDifficulty())
SCREWYOU3_HOOK_IMPL(GJGameLevel, getAverageDifficulty, "m1 android imac win ios", )
SCREWYOU3_HOOK(int getLastBuildPageForTab(int tab))
SCREWYOU3_HOOK_IMPL(GJGameLevel, getLastBuildPageForTab, "m1 android imac win ios", tab)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getNormalPercent())
SCREWYOU3_HOOK_IMPL(GJGameLevel, getNormalPercent, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(gd::string getSongName())
SCREWYOU3_HOOK_IMPL(GJGameLevel, getSongName, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getUnpackedLevelDescription())
SCREWYOU3_HOOK_IMPL(GJGameLevel, getUnpackedLevelDescription, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isPlatformer())
SCREWYOU3_HOOK_IMPL(GJGameLevel, isPlatformer, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string scoreVectorToString(gd::vector<int>& vec, int type))
SCREWYOU3_HOOK_IMPL(GJGameLevel, scoreVectorToString, " m1 android imac ios", vec, type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldCheatReset())
SCREWYOU3_HOOK_IMPL(GJGameLevel, shouldCheatReset, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("GJGameLevel::demonIconForDifficulty")

#include <Geode/modify/GJGameLoadingLayer.hpp>

bool GJGameLoadingLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJGameLoadingLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(GJGameLevel* level, bool editor))
SCREWYOU3_HOOK_IMPL(GJGameLoadingLayer, init, " m1 android imac ios", level, editor)
#endif
SCREWYOU3_HOOK_END("GJGameLoadingLayer::init")

#include <Geode/modify/GJGarageLayer.hpp>

gd::string GJGarageLayer_achievementForUnlock_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJGarageLayer_descriptionForUnlock_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJGarageLayer_titleForUnlock_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJGarageLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GJGarageLayer_getLockFrame_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GJGarageLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string achievementForUnlock(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GJGarageLayer, achievementForUnlock, " m1 android imac", id, type)
#endif
SCREWYOU3_HOOK(static gd::string descriptionForUnlock(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GJGarageLayer, descriptionForUnlock, "m1 android imac win ios", id, type)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string titleForUnlock(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GJGarageLayer, titleForUnlock, " m1 android imac ios", id, type)
#endif
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJGarageLayer, init, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getLockFrame(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(GJGarageLayer, getLockFrame, " m1 android imac", id, type)
#endif
SCREWYOU3_HOOK_END("GJGarageLayer::achievementForUnlock")

#include <Geode/modify/GJGradientLayer.hpp>

bool GJGradientLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJGradientLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJGradientLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJGradientLayer::init")

#include <Geode/modify/GJGroundLayer.hpp>

float GJGroundLayer_getGroundY_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJGroundLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float GJGroundLayer_scaleGround_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GJGroundLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getGroundY())
SCREWYOU3_HOOK_IMPL(GJGroundLayer, getGroundY, " m1 android imac", )
#endif
SCREWYOU3_HOOK(bool init(int groundID, int lineType))
SCREWYOU3_HOOK_IMPL(GJGroundLayer, init, "m1 android imac win ios", groundID, lineType)
SCREWYOU3_HOOK(float scaleGround(float scale))
SCREWYOU3_HOOK_IMPL(GJGroundLayer, scaleGround, "m1 android imac win ios", scale)
SCREWYOU3_HOOK_END("GJGroundLayer::getGroundY")

#include <Geode/modify/GJHttpResult.hpp>

bool GJHttpResult_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJHttpResult)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(bool success, gd::string response, gd::string tag, GJHttpType type))
SCREWYOU3_HOOK_IMPL(GJHttpResult, init, " m1 android imac", success, response, tag, type)
#endif
SCREWYOU3_HOOK_END("GJHttpResult::init")

#include <Geode/modify/GJItemIcon.hpp>

float GJItemIcon_scaleForType_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJItemIcon_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJItemIcon)
SCREWYOU3_HOOK(static float scaleForType(UnlockType type))
SCREWYOU3_HOOK_IMPL(GJItemIcon, scaleForType, "m1 android imac win ios", type)
SCREWYOU3_HOOK(bool init(UnlockType type, int id, cocos2d::ccColor3B color1, cocos2d::ccColor3B color2, bool dark, bool unused, bool noLabel, cocos2d::ccColor3B unlockColor))
SCREWYOU3_HOOK_IMPL(GJItemIcon, init, "m1 android imac win ios", type, id, color1, color2, dark, unused, noLabel, unlockColor)
SCREWYOU3_HOOK_END("GJItemIcon::scaleForType")

#include <Geode/modify/GJLevelList.hpp>

gd::string GJLevelList_frameForListDifficulty_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJLevelList_canEncode_override() {
	return modUtils::chooseRandomNum(0, 1);
}

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

int GJLevelList_orderForLevel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJLevelList_totalLevels_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GJLevelList)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string frameForListDifficulty(int diff, DifficultyIconType type))
SCREWYOU3_HOOK_IMPL(GJLevelList, frameForListDifficulty, " m1 android imac ios", diff, type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canEncode())
SCREWYOU3_HOOK_IMPL(GJLevelList, canEncode, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJLevelList, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(int completedLevels())
SCREWYOU3_HOOK_IMPL(GJLevelList, completedLevels, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getUnpackedDescription())
SCREWYOU3_HOOK_IMPL(GJLevelList, getUnpackedDescription, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool hasMatchingLevels(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(GJLevelList, hasMatchingLevels, "m1 android imac win ios", list)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int orderForLevel(int id))
SCREWYOU3_HOOK_IMPL(GJLevelList, orderForLevel, " m1 android imac ios", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int totalLevels())
SCREWYOU3_HOOK_IMPL(GJLevelList, totalLevels, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("GJLevelList::frameForListDifficulty")

#include <Geode/modify/GJLevelScoreCell.hpp>

bool GJLevelScoreCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJLevelScoreCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJLevelScoreCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJLevelScoreCell::init")

#include <Geode/modify/GJListLayer.hpp>

bool GJListLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJListLayer)
SCREWYOU3_HOOK(bool init(BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, int type))
SCREWYOU3_HOOK_IMPL(GJListLayer, init, "m1 android imac win ios", listView, title, color, width, height, type)
SCREWYOU3_HOOK_END("GJListLayer::init")

#include <Geode/modify/GJLocalLevelScoreCell.hpp>

bool GJLocalLevelScoreCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJLocalLevelScoreCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJLocalLevelScoreCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJLocalLevelScoreCell::init")

#include <Geode/modify/GJLocalScore.hpp>

bool GJLocalScore_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJLocalScore)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int points, int type))
SCREWYOU3_HOOK_IMPL(GJLocalScore, init, " m1 android imac", points, type)
#endif
SCREWYOU3_HOOK_END("GJLocalScore::init")

#include <Geode/modify/GJMapObject.hpp>

bool GJMapObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJMapObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(GJMapObject, init, "m1 imac android", parent)
#endif
SCREWYOU3_HOOK_END("GJMapObject::init")

#include <Geode/modify/GJMapPack.hpp>

bool GJMapPack_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJMapPack_completedMaps_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJMapPack_hasCompletedMapPack_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJMapPack_totalMaps_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GJMapPack)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJMapPack, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(int completedMaps())
SCREWYOU3_HOOK_IMPL(GJMapPack, completedMaps, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool hasCompletedMapPack())
SCREWYOU3_HOOK_IMPL(GJMapPack, hasCompletedMapPack, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int totalMaps())
SCREWYOU3_HOOK_IMPL(GJMapPack, totalMaps, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("GJMapPack::init")

#include <Geode/modify/GJMessageCell.hpp>

bool GJMessageCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJMessageCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJMessageCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJMessageCell::init")

#include <Geode/modify/GJMessagePopup.hpp>

bool GJMessagePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJMessagePopup)
SCREWYOU3_HOOK(bool init(GJUserMessage* message))
SCREWYOU3_HOOK_IMPL(GJMessagePopup, init, "m1 android imac win ios", message)
SCREWYOU3_HOOK_END("GJMessagePopup::init")

#include <Geode/modify/GJMGLayer.hpp>

float GJMGLayer_defaultYOffsetForBG2_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJMGLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float GJMGLayer_scaleGround_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GJMGLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static float defaultYOffsetForBG2(int index))
SCREWYOU3_HOOK_IMPL(GJMGLayer, defaultYOffsetForBG2, " m1 android imac", index)
#endif
SCREWYOU3_HOOK(bool init(int index))
SCREWYOU3_HOOK_IMPL(GJMGLayer, init, "m1 android imac win ios", index)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float scaleGround(float scale))
SCREWYOU3_HOOK_IMPL(GJMGLayer, scaleGround, " m1 android imac ios", scale)
#endif
SCREWYOU3_HOOK_END("GJMGLayer::defaultYOffsetForBG2")

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

int GJMultiplayerManager_getLastCommentIDForGame_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJMultiplayerManager_isDLActive_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJMultiplayerManager_joinLobby_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJMultiplayerManager_uploadComment_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJMultiplayerManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, init, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool exitLobby(int id))
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, exitLobby, "m1 imac android", id)
#endif
SCREWYOU3_HOOK(gd::string getBasePostString())
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, getBasePostString, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getLastCommentIDForGame(int id))
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, getLastCommentIDForGame, " m1 android imac", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isDLActive(char const* tag))
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, isDLActive, " m1 android imac", tag)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool joinLobby(int id))
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, joinLobby, "m1 imac android", id)
#endif
SCREWYOU3_HOOK(bool uploadComment(gd::string text, int lobbyID))
SCREWYOU3_HOOK_IMPL(GJMultiplayerManager, uploadComment, "m1 android imac win ios", text, lobbyID)
SCREWYOU3_HOOK_END("GJMultiplayerManager::init")

#include <Geode/modify/GJObjectDecoder.hpp>

bool GJObjectDecoder_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJObjectDecoder)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJObjectDecoder, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJObjectDecoder::init")

#include <Geode/modify/GJOptionsLayer.hpp>

int GJOptionsLayer_countForPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

const char* GJOptionsLayer_infoKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

const char* GJOptionsLayer_layerKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GJOptionsLayer_objectKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* GJOptionsLayer_pageKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GJOptionsLayer)
SCREWYOU3_HOOK(int countForPage(int page))
SCREWYOU3_HOOK_IMPL(GJOptionsLayer, countForPage, "m1 android imac win ios", page)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* infoKey(int index))
SCREWYOU3_HOOK_IMPL(GJOptionsLayer, infoKey, " m1 android imac", index)
#endif
SCREWYOU3_HOOK(bool init(int background))
SCREWYOU3_HOOK_IMPL(GJOptionsLayer, init, "m1 android imac win ios", background)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* layerKey(int page))
SCREWYOU3_HOOK_IMPL(GJOptionsLayer, layerKey, " m1 android imac", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* objectKey(int page))
SCREWYOU3_HOOK_IMPL(GJOptionsLayer, objectKey, " m1 android imac", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* pageKey(int page))
SCREWYOU3_HOOK_IMPL(GJOptionsLayer, pageKey, " m1 android imac", page)
#endif
SCREWYOU3_HOOK_END("GJOptionsLayer::countForPage")

#include <Geode/modify/GJPathPage.hpp>

bool GJPathPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJPathPage)
SCREWYOU3_HOOK(bool init(int path, GJPathsLayer* layer))
SCREWYOU3_HOOK_IMPL(GJPathPage, init, "m1 android imac win ios", path, layer)
SCREWYOU3_HOOK_END("GJPathPage::init")

#include <Geode/modify/GJPathRewardPopup.hpp>

bool GJPathRewardPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJPathRewardPopup)
SCREWYOU3_HOOK(bool init(int path))
SCREWYOU3_HOOK_IMPL(GJPathRewardPopup, init, "m1 android imac win ios", path)
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
SCREWYOU3_HOOK_IMPL(GJPathsLayer, nameForPath, "m1 android imac win ios", path)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJPathsLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJPathsLayer::nameForPath")

#include <Geode/modify/GJPathSprite.hpp>

bool GJPathSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJPathSprite)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int path))
SCREWYOU3_HOOK_IMPL(GJPathSprite, init, " m1 android imac ios", path)
#endif
SCREWYOU3_HOOK_END("GJPathSprite::init")

#include <Geode/modify/GJPFollowCommandLayer.hpp>

bool GJPFollowCommandLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJPFollowCommandLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(GJPFollowCommandLayer, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("GJPFollowCommandLayer::init")

#include <Geode/modify/GJPromoPopup.hpp>

bool GJPromoPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJPromoPopup)
SCREWYOU3_HOOK(bool init(gd::string filename))
SCREWYOU3_HOOK_IMPL(GJPromoPopup, init, "m1 android imac win ios", filename)
SCREWYOU3_HOOK_END("GJPromoPopup::init")

#include <Geode/modify/GJRateLevelLayer.hpp>

bool GJRateLevelLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJRateLevelLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(GJRateLevelLayer, init, "m1 android imac win ios", level)
SCREWYOU3_HOOK_END("GJRateLevelLayer::init")

#include <Geode/modify/GJRequestCell.hpp>

bool GJRequestCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJRequestCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJRequestCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJRequestCell::init")

#include <Geode/modify/GJRewardItem.hpp>

bool GJRewardItem_isShardType_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GJRewardItem_rewardItemToStat_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJRewardItem_canEncode_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJRewardItem_getRewardCount_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJRewardItem_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJRewardItem)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool isShardType(SpecialRewardItem type))
SCREWYOU3_HOOK_IMPL(GJRewardItem, isShardType, " m1 android imac", type)
#endif
SCREWYOU3_HOOK(static gd::string rewardItemToStat(SpecialRewardItem rewardItem))
SCREWYOU3_HOOK_IMPL(GJRewardItem, rewardItemToStat, "m1 android imac win ios", rewardItem)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canEncode())
SCREWYOU3_HOOK_IMPL(GJRewardItem, canEncode, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getRewardCount(SpecialRewardItem type))
SCREWYOU3_HOOK_IMPL(GJRewardItem, getRewardCount, " m1 android imac ios", type)
#endif
SCREWYOU3_HOOK(bool init(int chestID, int timeRemaining, gd::string rewardStr))
SCREWYOU3_HOOK_IMPL(GJRewardItem, init, "m1 android imac win ios", chestID, timeRemaining, rewardStr)
SCREWYOU3_HOOK_END("GJRewardItem::isShardType")

#include <Geode/modify/GJRewardObject.hpp>

bool GJRewardObject_canEncode_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJRewardObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJRewardObject_isSpecialType_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJRewardObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canEncode())
SCREWYOU3_HOOK_IMPL(GJRewardObject, canEncode, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(SpecialRewardItem specialRewardItem, int total, int itemID))
SCREWYOU3_HOOK_IMPL(GJRewardObject, init, " m1 android imac", specialRewardItem, total, itemID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isSpecialType())
SCREWYOU3_HOOK_IMPL(GJRewardObject, isSpecialType, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("GJRewardObject::canEncode")

#include <Geode/modify/GJRobotSprite.hpp>

bool GJRobotSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJRobotSprite)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int frame))
SCREWYOU3_HOOK_IMPL(GJRobotSprite, init, " m1 android imac ios", frame)
#endif
SCREWYOU3_HOOK(bool init(int frame, gd::string animName))
SCREWYOU3_HOOK_IMPL(GJRobotSprite, init, "m1 android imac win ios", frame, animName)
SCREWYOU3_HOOK_END("GJRobotSprite::init")

#include <Geode/modify/GJRotateCommandLayer.hpp>

bool GJRotateCommandLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJRotateCommandLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(GJRotateCommandLayer, init, "m1 imac android", object, objects)
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
SCREWYOU3_HOOK_IMPL(GJRotationControl, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(GJRotationControl, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK_END("GJRotationControl::init")

#include <Geode/modify/GJScaleControl.hpp>

bool GJScaleControl_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJScaleControl_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float GJScaleControl_scaleFromValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJScaleControl_skewFromValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJScaleControl_valueFromScale_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJScaleControl_valueFromSkew_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GJScaleControl)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJScaleControl, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(GJScaleControl, ccTouchBegan, "m1 android imac win ios", touch, event)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float scaleFromValue(float value))
SCREWYOU3_HOOK_IMPL(GJScaleControl, scaleFromValue, " m1 android imac", value)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float skewFromValue(float value))
SCREWYOU3_HOOK_IMPL(GJScaleControl, skewFromValue, " m1 android imac", value)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float valueFromScale(float scale))
SCREWYOU3_HOOK_IMPL(GJScaleControl, valueFromScale, " m1 android imac", scale)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float valueFromSkew(float value))
SCREWYOU3_HOOK_IMPL(GJScaleControl, valueFromSkew, " m1 android imac", value)
#endif
SCREWYOU3_HOOK_END("GJScaleControl::init")

#include <Geode/modify/GJScoreCell.hpp>

bool GJScoreCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJScoreCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJScoreCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJScoreCell::init")

#include <Geode/modify/GJSearchObject.hpp>

bool GJSearchObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJSearchObject_isLevelSearchObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJSearchObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(SearchType searchType, gd::string searchQuery, gd::string difficulty, gd::string length, int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, bool onlyCompleted, int demonFilter, int folder, int searchMode))
SCREWYOU3_HOOK_IMPL(GJSearchObject, init, " m1 android imac ios", searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode)
#endif
SCREWYOU3_HOOK(bool isLevelSearchObject())
SCREWYOU3_HOOK_IMPL(GJSearchObject, isLevelSearchObject, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJSearchObject::init")

#include <Geode/modify/GJShopLayer.hpp>

bool GJShopLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJShopLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJShopLayer)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(GJShopLayer, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK(bool init(ShopType type))
SCREWYOU3_HOOK_IMPL(GJShopLayer, init, "m1 android imac win ios", type)
SCREWYOU3_HOOK_END("GJShopLayer::ccTouchBegan")

#include <Geode/modify/GJSmartBlockPreview.hpp>

bool GJSmartBlockPreview_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJSmartBlockPreview)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(gd::string key))
SCREWYOU3_HOOK_IMPL(GJSmartBlockPreview, init, " m1 android imac ios", key)
#endif
SCREWYOU3_HOOK_END("GJSmartBlockPreview::init")

#include <Geode/modify/GJSmartBlockPreviewSprite.hpp>

bool GJSmartBlockPreviewSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJSmartBlockPreviewSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJSmartBlockPreviewSprite, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJSmartBlockPreviewSprite::init")

#include <Geode/modify/GJSmartPrefab.hpp>

bool GJSmartPrefab_canEncode_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJSmartPrefab_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJSmartPrefab)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canEncode())
SCREWYOU3_HOOK_IMPL(GJSmartPrefab, canEncode, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJSmartPrefab, init, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("GJSmartPrefab::canEncode")

#include <Geode/modify/GJSmartTemplate.hpp>

gd::string GJSmartTemplate_flipKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJSmartTemplate_getSimplifiedKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJSmartTemplate_getVerySimplifiedKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJSmartTemplate_keyFromNeighbors_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJSmartTemplate_keyFromNeighborsOld_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GJSmartTemplate_rotateKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJSmartTemplate_shouldDiscardObject_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJSmartTemplate_smartTypeToObjectKey_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJSmartTemplate_canEncode_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GJSmartTemplate_getNoCornerKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int GJSmartTemplate_getTotalChanceForPrefab_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJSmartTemplate_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJSmartTemplate_isUnrequired_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GJSmartTemplate_logTemplateStatus_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GJSmartTemplate)
SCREWYOU3_HOOK(static gd::string flipKey(gd::string key, bool flipX, bool flipY))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, flipKey, "m1 android imac win ios", key, flipX, flipY)
SCREWYOU3_HOOK(static gd::string getSimplifiedKey(gd::string key))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, getSimplifiedKey, "m1 android imac win ios", key)
SCREWYOU3_HOOK(static gd::string getVerySimplifiedKey(gd::string key))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, getVerySimplifiedKey, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string keyFromNeighbors(SmartBlockType type, SmartBlockType left, SmartBlockType right, SmartBlockType top, SmartBlockType bottom, SmartBlockType topLeft, SmartBlockType topRight, SmartBlockType bottomLeft, SmartBlockType bottomRight))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, keyFromNeighbors, " m1 android imac ios", type, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight)
#endif
SCREWYOU3_HOOK(static gd::string keyFromNeighbors(cocos2d::CCPoint position, SmartGameObject* object, SmartGameObject* left, SmartGameObject* right, SmartGameObject* top, SmartGameObject* bottom, SmartGameObject* topLeft, SmartGameObject* topRight, SmartGameObject* bottomLeft, SmartGameObject* bottomRight))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, keyFromNeighbors, "m1 android imac win ios", position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string keyFromNeighborsOld(bool left, bool right, bool top, bool bottom, bool topLeft, bool topRight, bool bottomLeft, bool bottomRight))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, keyFromNeighborsOld, " m1 android imac", left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight)
#endif
SCREWYOU3_HOOK(static gd::string rotateKey(gd::string key, int degrees))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, rotateKey, "m1 android imac win ios", key, degrees)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool shouldDiscardObject(SmartBlockType type, GJSmartDirection direction))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, shouldDiscardObject, " m1 android imac ios", type, direction)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static int smartTypeToObjectKey(SmartBlockType type))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, smartTypeToObjectKey, " m1 android imac ios", type)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canEncode())
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, canEncode, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(gd::string getNoCornerKey(gd::string key))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, getNoCornerKey, "m1 android imac win ios", key)
SCREWYOU3_HOOK(int getTotalChanceForPrefab(gd::string key))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, getTotalChanceForPrefab, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, init, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool isUnrequired(gd::string key))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, isUnrequired, "m1 android imac win ios", key)
SCREWYOU3_HOOK(gd::string logTemplateStatus(bool unused))
SCREWYOU3_HOOK_IMPL(GJSmartTemplate, logTemplateStatus, "m1 android imac win ios", unused)
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
SCREWYOU3_HOOK_IMPL(GJSongBrowser, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(GJSongBrowser, cellPerformedAction, "m1 android imac win ios", cell, listType, action, parent)
SCREWYOU3_HOOK(int getSelectedCellIdx())
SCREWYOU3_HOOK_IMPL(GJSongBrowser, getSelectedCellIdx, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(GJSpecialColorSelect, textForColorIdx, "m1 android imac win ios", index)
SCREWYOU3_HOOK(bool init(int id, GJSpecialColorSelectDelegate* delegate, ColorSelectType type))
SCREWYOU3_HOOK_IMPL(GJSpecialColorSelect, init, "m1 android imac win ios", id, delegate, type)
SCREWYOU3_HOOK_END("GJSpecialColorSelect::textForColorIdx")

#include <Geode/modify/GJSpiderSprite.hpp>

bool GJSpiderSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJSpiderSprite)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int frame))
SCREWYOU3_HOOK_IMPL(GJSpiderSprite, init, " m1 android imac ios", frame)
#endif
SCREWYOU3_HOOK_END("GJSpiderSprite::init")

#include <Geode/modify/GJStoreItem.hpp>

gd::string GJStoreItem_getCurrencyKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GJStoreItem_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJStoreItem)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getCurrencyKey())
SCREWYOU3_HOOK_IMPL(GJStoreItem, getCurrencyKey, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int index, int typeID, int unlockType, int price, ShopType shopType))
SCREWYOU3_HOOK_IMPL(GJStoreItem, init, " m1 android imac ios", index, typeID, unlockType, price, shopType)
#endif
SCREWYOU3_HOOK_END("GJStoreItem::getCurrencyKey")

#include <Geode/modify/GJTransformControl.hpp>

bool GJTransformControl_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool GJTransformControl_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJTransformControl)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJTransformControl, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(GJTransformControl, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK_END("GJTransformControl::init")

#include <Geode/modify/GJUINode.hpp>

int GJUINode_activeRangeTouchTest_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int GJUINode_activeTouchTest_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float GJUINode_getButtonScale_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

uint8_t GJUINode_getOpacity_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool GJUINode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int GJUINode_touchTest_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(GJUINode)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int activeRangeTouchTest(cocos2d::CCPoint position))
SCREWYOU3_HOOK_IMPL(GJUINode, activeRangeTouchTest, " m1 android imac ios", position)
#endif
SCREWYOU3_HOOK(int activeTouchTest(cocos2d::CCPoint position))
SCREWYOU3_HOOK_IMPL(GJUINode, activeTouchTest, "m1 android imac win ios", position)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getButtonScale())
SCREWYOU3_HOOK_IMPL(GJUINode, getButtonScale, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(uint8_t getOpacity())
SCREWYOU3_HOOK_IMPL(GJUINode, getOpacity, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool init(UIButtonConfig& config))
SCREWYOU3_HOOK_IMPL(GJUINode, init, "m1 android imac win ios", config)
SCREWYOU3_HOOK(int touchTest(cocos2d::CCPoint position))
SCREWYOU3_HOOK_IMPL(GJUINode, touchTest, "m1 android imac win ios", position)
SCREWYOU3_HOOK_END("GJUINode::activeRangeTouchTest")

#include <Geode/modify/GJUnlockableItem.hpp>

bool GJUnlockableItem_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJUnlockableItem)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJUnlockableItem, init, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("GJUnlockableItem::init")

#include <Geode/modify/GJUserCell.hpp>

bool GJUserCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJUserCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJUserCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GJUserCell::init")

#include <Geode/modify/GJUserMessage.hpp>

bool GJUserMessage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJUserMessage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GJUserMessage, init, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(GJUserScore, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool isCurrentUser())
SCREWYOU3_HOOK_IMPL(GJUserScore, isCurrentUser, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(GJWorldNode, addDotsToLevel, "m1 imac android", levelID, animate)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int type, WorldSelectLayer* layer))
SCREWYOU3_HOOK_IMPL(GJWorldNode, init, "m1 imac android", type, layer)
#endif
SCREWYOU3_HOOK_END("GJWorldNode::addDotsToLevel")

#include <Geode/modify/GJWriteMessagePopup.hpp>

bool GJWriteMessagePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GJWriteMessagePopup)
SCREWYOU3_HOOK(bool init(int accountID, int messageID))
SCREWYOU3_HOOK_IMPL(GJWriteMessagePopup, init, "m1 android imac win ios", accountID, messageID)
SCREWYOU3_HOOK_END("GJWriteMessagePopup::init")

#include <Geode/modify/GManager.hpp>

bool GManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GManager_getCompressedSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string GManager_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool GManager_tryLoadData_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GManager, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getCompressedSaveString())
SCREWYOU3_HOOK_IMPL(GManager, getCompressedSaveString, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getSaveString())
SCREWYOU3_HOOK_IMPL(GManager, getSaveString, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool tryLoadData(DS_Dictionary* dict, gd::string const& filename))
SCREWYOU3_HOOK_IMPL(GManager, tryLoadData, " m1 android imac ios", dict, filename)
#endif
SCREWYOU3_HOOK_END("GManager::init")

#include <Geode/modify/GooglePlayManager.hpp>

bool GooglePlayManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GooglePlayManager)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GooglePlayManager, init, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("GooglePlayManager::init")

#include <Geode/modify/GradientTriggerObject.hpp>

bool GradientTriggerObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string GradientTriggerObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(GradientTriggerObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GradientTriggerObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(GradientTriggerObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("GradientTriggerObject::init")

#include <Geode/modify/GraphicsReloadLayer.hpp>

bool GraphicsReloadLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GraphicsReloadLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::TextureQuality quality, cocos2d::CCSize resolution, bool fullscreen, bool borderless, bool fix, bool changedResolution))
SCREWYOU3_HOOK_IMPL(GraphicsReloadLayer, init, " m1 android imac", quality, resolution, fullscreen, borderless, fix, changedResolution)
#endif
SCREWYOU3_HOOK_END("GraphicsReloadLayer::init")

#include <Geode/modify/GravityEffectSprite.hpp>

bool GravityEffectSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(GravityEffectSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(GravityEffectSprite, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("GravityEffectSprite::init")

#include <Geode/modify/HardStreak.hpp>

bool HardStreak_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

double HardStreak_normalizeAngle_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(HardStreak)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(HardStreak, init, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(double normalizeAngle(double angle))
SCREWYOU3_HOOK_IMPL(HardStreak, normalizeAngle, " m1 android imac", angle)
#endif
SCREWYOU3_HOOK_END("HardStreak::init")

#include <Geode/modify/HSVLiveOverlay.hpp>

bool HSVLiveOverlay_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(HSVLiveOverlay)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(HSVLiveOverlay, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("HSVLiveOverlay::init")

#include <Geode/modify/HSVWidgetPopup.hpp>

bool HSVWidgetPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(HSVWidgetPopup)
SCREWYOU3_HOOK(bool init(cocos2d::ccHSVValue hsv, HSVWidgetDelegate* delegate, gd::string title))
SCREWYOU3_HOOK_IMPL(HSVWidgetPopup, init, "m1 android imac win ios", hsv, delegate, title)
SCREWYOU3_HOOK_END("HSVWidgetPopup::init")

#include <Geode/modify/InfoAlertButton.hpp>

bool InfoAlertButton_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(InfoAlertButton)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(gd::string title, gd::string desc, float spriteScale))
SCREWYOU3_HOOK_IMPL(InfoAlertButton, init, " m1 android imac ios", title, desc, spriteScale)
#endif
SCREWYOU3_HOOK_END("InfoAlertButton::init")

#include <Geode/modify/InfoLayer.hpp>

int InfoLayer_getAccountID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int InfoLayer_getID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int InfoLayer_getRealID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool InfoLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool InfoLayer_isCorrect_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(InfoLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getAccountID())
SCREWYOU3_HOOK_IMPL(InfoLayer, getAccountID, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getID())
SCREWYOU3_HOOK_IMPL(InfoLayer, getID, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getRealID())
SCREWYOU3_HOOK_IMPL(InfoLayer, getRealID, " m1 android imac", )
#endif
SCREWYOU3_HOOK(bool init(GJGameLevel* level, GJUserScore* score, GJLevelList* list))
SCREWYOU3_HOOK_IMPL(InfoLayer, init, "m1 android imac win ios", level, score, list)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(InfoLayer, isCorrect, "m1 android imac win ios", key)
SCREWYOU3_HOOK_END("InfoLayer::getAccountID")

#include <Geode/modify/InheritanceNode.hpp>

bool InheritanceNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(InheritanceNode)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int colorID, InheritanceNode* node))
SCREWYOU3_HOOK_IMPL(InheritanceNode, init, " m1 android imac", colorID, node)
#endif
SCREWYOU3_HOOK_END("InheritanceNode::init")

#include <Geode/modify/ItemInfoPopup.hpp>

gd::string ItemInfoPopup_nameForUnlockType_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool ItemInfoPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool ItemInfoPopup_isUnlockedByDefault_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ItemInfoPopup)
SCREWYOU3_HOOK(static gd::string nameForUnlockType(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(ItemInfoPopup, nameForUnlockType, "m1 android imac win ios", id, type)
SCREWYOU3_HOOK(bool init(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(ItemInfoPopup, init, "m1 android imac win ios", id, type)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isUnlockedByDefault(int id, UnlockType type))
SCREWYOU3_HOOK_IMPL(ItemInfoPopup, isUnlockedByDefault, " m1 android imac", id, type)
#endif
SCREWYOU3_HOOK_END("ItemInfoPopup::nameForUnlockType")

#include <Geode/modify/ItemTriggerGameObject.hpp>

gd::string ItemTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool ItemTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ItemTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(ItemTriggerGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(ItemTriggerGameObject, init, " m1 android imac", frame)
#endif
SCREWYOU3_HOOK_END("ItemTriggerGameObject::getSaveString")

#include <Geode/modify/KeybindingsLayer.hpp>

bool KeybindingsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int KeybindingsLayer_countForPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

const char* KeybindingsLayer_infoKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* KeybindingsLayer_layerKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* KeybindingsLayer_objectKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* KeybindingsLayer_pageKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(KeybindingsLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(KeybindingsLayer, init, "m1 imac win android", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int countForPage(int page))
SCREWYOU3_HOOK_IMPL(KeybindingsLayer, countForPage, "m1 imac win android", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* infoKey(int index))
SCREWYOU3_HOOK_IMPL(KeybindingsLayer, infoKey, " m1 android imac", index)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* layerKey(int page))
SCREWYOU3_HOOK_IMPL(KeybindingsLayer, layerKey, " m1 android imac", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* objectKey(int page))
SCREWYOU3_HOOK_IMPL(KeybindingsLayer, objectKey, " m1 android imac", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* pageKey(int page))
SCREWYOU3_HOOK_IMPL(KeybindingsLayer, pageKey, " m1 android imac", page)
#endif
SCREWYOU3_HOOK_END("KeybindingsLayer::init")

#include <Geode/modify/KeybindingsManager.hpp>

bool KeybindingsManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

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
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(KeybindingsManager, init, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool commandForKey(cocos2d::enumKeyCodes key, GJKeyGroup group, bool control, bool alt, bool shift))
SCREWYOU3_HOOK_IMPL(KeybindingsManager, commandForKey, "m1 imac android", key, group, control, alt, shift)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool commandForKeyMods(cocos2d::enumKeyCodes key, GJKeyGroup group))
SCREWYOU3_HOOK_IMPL(KeybindingsManager, commandForKeyMods, "m1 imac android", key, group)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool commandForKeyNoMods(cocos2d::enumKeyCodes key, GJKeyGroup group))
SCREWYOU3_HOOK_IMPL(KeybindingsManager, commandForKeyNoMods, "m1 imac android", key, group)
#endif
SCREWYOU3_HOOK_END("KeybindingsManager::init")

#include <Geode/modify/KeyframeAnimTriggerObject.hpp>

bool KeyframeAnimTriggerObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string KeyframeAnimTriggerObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(KeyframeAnimTriggerObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(KeyframeAnimTriggerObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(KeyframeAnimTriggerObject, getSaveString, "m1 android imac win ios", layer)
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
SCREWYOU3_HOOK_IMPL(KeyframeGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(KeyframeGameObject, getSaveString, "m1 android imac win ios", layer)
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
SCREWYOU3_HOOK_IMPL(LabelGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(LabelGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK(int getTextKerning())
SCREWYOU3_HOOK_IMPL(LabelGameObject, getTextKerning, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("LabelGameObject::init")

#include <Geode/modify/LeaderboardsLayer.hpp>

bool LeaderboardsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LeaderboardsLayer_isCorrect_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LeaderboardsLayer)
SCREWYOU3_HOOK(bool init(LeaderboardType type, LeaderboardStat stat))
SCREWYOU3_HOOK_IMPL(LeaderboardsLayer, init, "m1 android imac win ios", type, stat)
SCREWYOU3_HOOK(bool isCorrect(gd::string key))
SCREWYOU3_HOOK_IMPL(LeaderboardsLayer, isCorrect, "m1 android imac win ios", key)
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
SCREWYOU3_HOOK_IMPL(LevelAreaInnerLayer, init, "m1 android imac win ios", returning)
SCREWYOU3_HOOK(bool playStep1())
SCREWYOU3_HOOK_IMPL(LevelAreaInnerLayer, playStep1, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(LevelAreaLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool onEnterTower())
SCREWYOU3_HOOK_IMPL(LevelAreaLayer, onEnterTower, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("LevelAreaLayer::init")

#include <Geode/modify/LevelBrowserLayer.hpp>

bool LevelBrowserLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

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
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(LevelBrowserLayer, ccTouchBegan, " m1 android imac ios", touch, event)
#endif
SCREWYOU3_HOOK(bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(LevelBrowserLayer, cellPerformedAction, "m1 android imac win ios", cell, listType, action, parent)
SCREWYOU3_HOOK(gd::string getSearchTitle())
SCREWYOU3_HOOK_IMPL(LevelBrowserLayer, getSearchTitle, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool init(GJSearchObject* object))
SCREWYOU3_HOOK_IMPL(LevelBrowserLayer, init, "m1 android imac win ios", object)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(LevelBrowserLayer, isCorrect, "m1 android imac win ios", key)
SCREWYOU3_HOOK_END("LevelBrowserLayer::ccTouchBegan")

#include <Geode/modify/LevelCell.hpp>

bool LevelCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LevelCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("LevelCell::init")

#include <Geode/modify/LevelEditorLayer.hpp>

float LevelEditorLayer_timeForPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool LevelEditorLayer_activateTriggerEffect_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelEditorLayer_canPasteState_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float LevelEditorLayer_getLastObjectX_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string LevelEditorLayer_getLevelString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string LevelEditorLayer_getLockedLayers_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int LevelEditorLayer_getNextColorChannel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int LevelEditorLayer_getNextFreeAreaEffectID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int LevelEditorLayer_getNextFreeBlockID_override() {
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

int LevelEditorLayer_getNextFreeSFXGroupID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int LevelEditorLayer_getNextFreeSFXID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string LevelEditorLayer_getSavedEditorPositions_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int LevelEditorLayer_getSectionCount_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int LevelEditorLayer_getSelectedEditorOrder_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int LevelEditorLayer_getSelectedOrderChannel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string LevelEditorLayer_getSFXIDs_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string LevelEditorLayer_getSongIDs_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool LevelEditorLayer_hasAction_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelEditorLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelEditorLayer_isLayerLocked_override() {
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

bool LevelEditorLayer_validGroup_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelEditorLayer)
SCREWYOU3_HOOK(float timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, int id))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, timeForPos, "m1 android imac win ios", position, order, channel, songTriggers, id)
SCREWYOU3_HOOK(bool activateTriggerEffect(EffectGameObject* object, float currentTime, float playTime, float boundTime, bool active))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, activateTriggerEffect, "m1 android imac win ios", object, currentTime, playTime, boundTime, active)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canPasteState())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, canPasteState, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(float getLastObjectX())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getLastObjectX, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getLevelString())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getLevelString, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getLockedLayers())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getLockedLayers, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(int getNextColorChannel())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextColorChannel, "m1 android imac win ios", )
SCREWYOU3_HOOK(int getNextFreeAreaEffectID(const gd::unordered_set<int>& exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeAreaEffectID, "m1 android imac win ios", exclude)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getNextFreeBlockID(const gd::unordered_set<int>& exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeBlockID, " m1 android imac ios", exclude)
#endif
SCREWYOU3_HOOK(int getNextFreeEditorLayer(const gd::unordered_set<int>& exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeEditorLayer, "m1 android imac win ios", exclude)
SCREWYOU3_HOOK(int getNextFreeEnterChannel(const gd::unordered_set<int>& exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeEnterChannel, "m1 android imac win ios", exclude)
SCREWYOU3_HOOK(int getNextFreeGradientID(const gd::unordered_set<int>& exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeGradientID, "m1 android imac win ios", exclude)
SCREWYOU3_HOOK(int getNextFreeGroupID(const gd::unordered_set<int>& exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeGroupID, "m1 android imac win ios", exclude)
SCREWYOU3_HOOK(int getNextFreeItemID(const gd::unordered_set<int>& exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeItemID, "m1 android imac win ios", exclude)
SCREWYOU3_HOOK(int getNextFreeOrderChannel(const gd::unordered_set<int>& exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeOrderChannel, "m1 android imac win ios", exclude)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getNextFreeSFXGroupID(const gd::unordered_set<int>& exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeSFXGroupID, " m1 android imac ios", exclude)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getNextFreeSFXID(const gd::unordered_set<int>& exclude))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getNextFreeSFXID, " m1 android imac ios", exclude)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getSavedEditorPositions())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getSavedEditorPositions, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getSectionCount())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getSectionCount, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getSelectedEditorOrder())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getSelectedEditorOrder, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getSelectedOrderChannel())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getSelectedOrderChannel, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(gd::string getSFXIDs())
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getSFXIDs, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSongIDs(bool& multipleSongs))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, getSongIDs, "m1 android imac win ios", multipleSongs)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool hasAction(bool redo))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, hasAction, " m1 android imac ios", redo)
#endif
SCREWYOU3_HOOK(bool init(GJGameLevel* level, bool noUI))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, init, "m1 android imac win ios", level, noUI)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isLayerLocked(int layer))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, isLayerLocked, " m1 android imac ios", layer)
#endif
SCREWYOU3_HOOK(float rotationForSlopeNearObject(GameObject* object))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, rotationForSlopeNearObject, "m1 android imac win ios", object)
SCREWYOU3_HOOK(bool shouldBlend(int colorID))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, shouldBlend, "m1 android imac win ios", colorID)
SCREWYOU3_HOOK(bool tryUpdateSpeedObject(EffectGameObject* object, bool noPreview))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, tryUpdateSpeedObject, "m1 android imac win ios", object, noPreview)
SCREWYOU3_HOOK(bool typeExistsAtPosition(int objectID, cocos2d::CCPoint position, bool flipX, bool flipY, float rotation))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, typeExistsAtPosition, "m1 android imac win ios", objectID, position, flipX, flipY, rotation)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool validGroup(GameObject* object, bool checkLockedLayers))
SCREWYOU3_HOOK_IMPL(LevelEditorLayer, validGroup, " m1 android imac ios", object, checkLockedLayers)
#endif
SCREWYOU3_HOOK_END("LevelEditorLayer::timeForPos")

#include <Geode/modify/LevelFeatureLayer.hpp>

bool LevelFeatureLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelFeatureLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int levelID))
SCREWYOU3_HOOK_IMPL(LevelFeatureLayer, init, "m1 imac android", levelID)
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
SCREWYOU3_HOOK_IMPL(LevelInfoLayer, cellPerformedAction, "m1 android imac win ios", cell, listType, action, parent)
SCREWYOU3_HOOK(bool init(GJGameLevel* level, bool challenge))
SCREWYOU3_HOOK_IMPL(LevelInfoLayer, init, "m1 android imac win ios", level, challenge)
SCREWYOU3_HOOK(bool shouldDownloadLevel())
SCREWYOU3_HOOK_IMPL(LevelInfoLayer, shouldDownloadLevel, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(LevelLeaderboard, init, "m1 android imac win ios", level, type, mode)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(LevelLeaderboard, isCorrect, "m1 android imac win ios", key)
SCREWYOU3_HOOK_END("LevelLeaderboard::init")

#include <Geode/modify/LevelListCell.hpp>

bool LevelListCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelListCell)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LevelListCell, init, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("LevelListCell::init")

#include <Geode/modify/LevelListLayer.hpp>

bool LevelListLayer_cellPerformedAction_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelListLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelListLayer)
SCREWYOU3_HOOK(bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(LevelListLayer, cellPerformedAction, "m1 android imac win ios", cell, listType, action, parent)
SCREWYOU3_HOOK(bool init(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(LevelListLayer, init, "m1 android imac win ios", list)
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
SCREWYOU3_HOOK_IMPL(LevelOptionsLayer, getValue, "m1 android imac win ios", tag)
SCREWYOU3_HOOK(bool init(LevelSettingsObject* object))
SCREWYOU3_HOOK_IMPL(LevelOptionsLayer, init, "m1 android imac win ios", object)
SCREWYOU3_HOOK_END("LevelOptionsLayer::getValue")

#include <Geode/modify/LevelOptionsLayer2.hpp>

bool LevelOptionsLayer2_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelOptionsLayer2)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(LevelSettingsObject* object))
SCREWYOU3_HOOK_IMPL(LevelOptionsLayer2, init, " m1 android imac ios", object)
#endif
SCREWYOU3_HOOK_END("LevelOptionsLayer2::init")

#include <Geode/modify/LevelPage.hpp>

bool LevelPage_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelPage)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(LevelPage, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(LevelPage, init, "m1 android imac win ios", level)
SCREWYOU3_HOOK_END("LevelPage::ccTouchBegan")

#include <Geode/modify/LevelSearchLayer.hpp>

bool LevelSearchLayer_checkDiff_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelSearchLayer_checkTime_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string LevelSearchLayer_getLevelLenKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string LevelSearchLayer_getSearchDiffKey_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool LevelSearchLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelSearchLayer)
SCREWYOU3_HOOK(bool checkDiff(int diff))
SCREWYOU3_HOOK_IMPL(LevelSearchLayer, checkDiff, "m1 android imac win ios", diff)
SCREWYOU3_HOOK(bool checkTime(int time))
SCREWYOU3_HOOK_IMPL(LevelSearchLayer, checkTime, "m1 android imac win ios", time)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getLevelLenKey())
SCREWYOU3_HOOK_IMPL(LevelSearchLayer, getLevelLenKey, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getSearchDiffKey())
SCREWYOU3_HOOK_IMPL(LevelSearchLayer, getSearchDiffKey, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool init(int type))
SCREWYOU3_HOOK_IMPL(LevelSearchLayer, init, "m1 android imac win ios", type)
SCREWYOU3_HOOK_END("LevelSearchLayer::checkDiff")

#include <Geode/modify/LevelSelectLayer.hpp>

bool LevelSelectLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelSelectLayer)
SCREWYOU3_HOOK(bool init(int page))
SCREWYOU3_HOOK_IMPL(LevelSelectLayer, init, "m1 android imac win ios", page)
SCREWYOU3_HOOK_END("LevelSelectLayer::init")

#include <Geode/modify/LevelSettingsLayer.hpp>

bool LevelSettingsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelSettingsLayer)
SCREWYOU3_HOOK(bool init(LevelSettingsObject* object, LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(LevelSettingsLayer, init, "m1 android imac win ios", object, layer)
SCREWYOU3_HOOK_END("LevelSettingsLayer::init")

#include <Geode/modify/LevelSettingsObject.hpp>

bool LevelSettingsObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string LevelSettingsObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool LevelSettingsObject_shouldUseYSection_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LevelSettingsObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LevelSettingsObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString())
SCREWYOU3_HOOK_IMPL(LevelSettingsObject, getSaveString, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldUseYSection())
SCREWYOU3_HOOK_IMPL(LevelSettingsObject, shouldUseYSection, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("LevelSettingsObject::init")

#include <Geode/modify/LevelTools.hpp>

int LevelTools_artistForAudio_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string LevelTools_base64DecodeString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string LevelTools_base64EncodeString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string LevelTools_fbURLForArtist_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int LevelTools_getAudioBPM_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
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

bool LevelTools_getLastGameplayReversed_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool LevelTools_getLastGameplayRotated_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float LevelTools_getLastTimewarp_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string LevelTools_nameForArtist_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string LevelTools_ngURLForArtist_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float LevelTools_offsetBPMForTrack_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float LevelTools_timeForPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string LevelTools_urlForAudio_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

float LevelTools_valueForSpeedMod_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool LevelTools_verifyLevelIntegrity_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string LevelTools_ytURLForArtist_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(LevelTools)
SCREWYOU3_HOOK(static int artistForAudio(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, artistForAudio, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string base64DecodeString(gd::string str))
SCREWYOU3_HOOK_IMPL(LevelTools, base64DecodeString, " m1 android imac ios", str)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string base64EncodeString(gd::string str))
SCREWYOU3_HOOK_IMPL(LevelTools, base64EncodeString, " m1 android imac ios", str)
#endif
SCREWYOU3_HOOK(static gd::string fbURLForArtist(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, fbURLForArtist, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static int getAudioBPM(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, getAudioBPM, " m1 android imac", id)
#endif
SCREWYOU3_HOOK(static gd::string getAudioFileName(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, getAudioFileName, "m1 android imac win ios", id)
SCREWYOU3_HOOK(static gd::string getAudioString(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, getAudioString, "m1 android imac win ios", id)
SCREWYOU3_HOOK(static gd::string getAudioTitle(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, getAudioTitle, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool getLastGameplayReversed())
SCREWYOU3_HOOK_IMPL(LevelTools, getLastGameplayReversed, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool getLastGameplayRotated())
SCREWYOU3_HOOK_IMPL(LevelTools, getLastGameplayRotated, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static float getLastTimewarp())
SCREWYOU3_HOOK_IMPL(LevelTools, getLastTimewarp, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(static gd::string nameForArtist(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, nameForArtist, "m1 android imac win ios", id)
SCREWYOU3_HOOK(static gd::string ngURLForArtist(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, ngURLForArtist, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static float offsetBPMForTrack(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, offsetBPMForTrack, " m1 android imac", id)
#endif
SCREWYOU3_HOOK(static float timeForPos(cocos2d::CCPoint position, cocos2d::CCArray* objects, int speed, int order, int channel, bool songTriggers, bool platformer, bool ignoreWarp, bool ignoreRotate, int id))
SCREWYOU3_HOOK_IMPL(LevelTools, timeForPos, "m1 android imac win ios", position, objects, speed, order, channel, songTriggers, platformer, ignoreWarp, ignoreRotate, id)
SCREWYOU3_HOOK(static gd::string urlForAudio(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, urlForAudio, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static float valueForSpeedMod(int speed))
SCREWYOU3_HOOK_IMPL(LevelTools, valueForSpeedMod, " m1 android imac", speed)
#endif
SCREWYOU3_HOOK(static bool verifyLevelIntegrity(gd::string str, int id))
SCREWYOU3_HOOK_IMPL(LevelTools, verifyLevelIntegrity, "m1 android imac win ios", str, id)
SCREWYOU3_HOOK(static gd::string ytURLForArtist(int id))
SCREWYOU3_HOOK_IMPL(LevelTools, ytURLForArtist, "m1 android imac win ios", id)
SCREWYOU3_HOOK_END("LevelTools::artistForAudio")

#include <Geode/modify/LikeItemLayer.hpp>

bool LikeItemLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LikeItemLayer)
SCREWYOU3_HOOK(bool init(LikeItemType type, int id, int parentID))
SCREWYOU3_HOOK_IMPL(LikeItemLayer, init, "m1 android imac win ios", type, id, parentID)
SCREWYOU3_HOOK_END("LikeItemLayer::init")

#include <Geode/modify/ListButtonBar.hpp>

int ListButtonBar_getPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool ListButtonBar_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ListButtonBar)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getPage())
SCREWYOU3_HOOK_IMPL(ListButtonBar, getPage, " m1 android imac", )
#endif
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* items, cocos2d::CCPoint position, int columns, int rows, float columnOffset, float rowOffset, float offset, float arrowOffset, int arrowType))
SCREWYOU3_HOOK_IMPL(ListButtonBar, init, "m1 android imac win ios", items, position, columns, rows, columnOffset, rowOffset, offset, arrowOffset, arrowType)
SCREWYOU3_HOOK_END("ListButtonBar::getPage")

#include <Geode/modify/ListButtonPage.hpp>

bool ListButtonPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ListButtonPage)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* items, cocos2d::CCPoint position, int columns, int rows, float columnOffset, float rowOffset, float offset))
SCREWYOU3_HOOK_IMPL(ListButtonPage, init, " m1 android imac ios", items, position, columns, rows, columnOffset, rowOffset, offset)
#endif
SCREWYOU3_HOOK_END("ListButtonPage::init")

#include <Geode/modify/ListCell.hpp>

bool ListCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ListCell)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ListCell, init, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("ListCell::init")

#include <Geode/modify/LoadingCircle.hpp>

bool LoadingCircle_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LoadingCircle)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LoadingCircle, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("LoadingCircle::init")

#include <Geode/modify/LoadingCircleSprite.hpp>

bool LoadingCircleSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(LoadingCircleSprite)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(float spinSpeed))
SCREWYOU3_HOOK_IMPL(LoadingCircleSprite, init, " m1 android imac ios", spinSpeed)
#endif
SCREWYOU3_HOOK_END("LoadingCircleSprite::init")

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
SCREWYOU3_HOOK_IMPL(LoadingLayer, getLoadingString, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool init(bool refresh))
SCREWYOU3_HOOK_IMPL(LoadingLayer, init, "m1 android imac win ios", refresh)
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

int LocalLevelManager_updateListOrder_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(LocalLevelManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(LocalLevelManager, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getMainLevelString(int id))
SCREWYOU3_HOOK_IMPL(LocalLevelManager, getMainLevelString, "m1 android imac win ios", id)
SCREWYOU3_HOOK(int updateLevelOrder())
SCREWYOU3_HOOK_IMPL(LocalLevelManager, updateLevelOrder, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int updateListOrder())
SCREWYOU3_HOOK_IMPL(LocalLevelManager, updateListOrder, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("LocalLevelManager::init")

#include <Geode/modify/MapPackCell.hpp>

bool MapPackCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MapPackCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MapPackCell, init, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(MapSelectLayer, init, "m1 imac android", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(MapSelectLayer, ccTouchBegan, "m1 imac android", touch, event)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool checkTouchMonster(cocos2d::CCPoint position))
SCREWYOU3_HOOK_IMPL(MapSelectLayer, checkTouchMonster, "m1 imac android", position)
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
SCREWYOU3_HOOK_IMPL(MenuGameLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(MenuGameLayer, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK_END("MenuGameLayer::init")

#include <Geode/modify/MenuLayer.hpp>

bool MenuLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MenuLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_MENULAYER_CUSTOM_INIT(MenuLayer, init, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(MessagesProfilePage, init, "m1 android imac win ios", sent)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(MessagesProfilePage, isCorrect, "m1 android imac win ios", key)
SCREWYOU3_HOOK_END("MessagesProfilePage::init")

#include <Geode/modify/MoreOptionsLayer.hpp>

bool MoreOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int MoreOptionsLayer_countForPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

const char* MoreOptionsLayer_infoKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* MoreOptionsLayer_layerKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* MoreOptionsLayer_objectKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* MoreOptionsLayer_pageKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(MoreOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MoreOptionsLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(int countForPage(int page))
SCREWYOU3_HOOK_IMPL(MoreOptionsLayer, countForPage, "m1 android imac win ios", page)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* infoKey(int index))
SCREWYOU3_HOOK_IMPL(MoreOptionsLayer, infoKey, " m1 android imac", index)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* layerKey(int page))
SCREWYOU3_HOOK_IMPL(MoreOptionsLayer, layerKey, " m1 android imac", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* objectKey(int page))
SCREWYOU3_HOOK_IMPL(MoreOptionsLayer, objectKey, " m1 android imac", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* pageKey(int page))
SCREWYOU3_HOOK_IMPL(MoreOptionsLayer, pageKey, " m1 android imac", page)
#endif
SCREWYOU3_HOOK_END("MoreOptionsLayer::init")

#include <Geode/modify/MoreSearchLayer.hpp>

bool MoreSearchLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MoreSearchLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MoreSearchLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("MoreSearchLayer::init")

#include <Geode/modify/MoreVideoOptionsLayer.hpp>

bool MoreVideoOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int MoreVideoOptionsLayer_countForPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

const char* MoreVideoOptionsLayer_infoKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* MoreVideoOptionsLayer_layerKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* MoreVideoOptionsLayer_objectKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* MoreVideoOptionsLayer_pageKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(MoreVideoOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MoreVideoOptionsLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(int countForPage(int page))
SCREWYOU3_HOOK_IMPL(MoreVideoOptionsLayer, countForPage, "m1 android imac win ios", page)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* infoKey(int index))
SCREWYOU3_HOOK_IMPL(MoreVideoOptionsLayer, infoKey, " m1 android imac", index)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* layerKey(int page))
SCREWYOU3_HOOK_IMPL(MoreVideoOptionsLayer, layerKey, " m1 android imac", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* objectKey(int page))
SCREWYOU3_HOOK_IMPL(MoreVideoOptionsLayer, objectKey, " m1 android imac", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* pageKey(int page))
SCREWYOU3_HOOK_IMPL(MoreVideoOptionsLayer, pageKey, " m1 android imac", page)
#endif
SCREWYOU3_HOOK_END("MoreVideoOptionsLayer::init")

#include <Geode/modify/MPLobbyLayer.hpp>

bool MPLobbyLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MPLobbyLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int type))
SCREWYOU3_HOOK_IMPL(MPLobbyLayer, init, "m1 imac android", type)
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
SCREWYOU3_HOOK_IMPL(MultilineBitmapFont, initWithFont, "m1 android imac win ios", font, text, scale, width, anchor, height, disableColor)
SCREWYOU3_HOOK(gd::string readColorInfo(gd::string text))
SCREWYOU3_HOOK_IMPL(MultilineBitmapFont, readColorInfo, "m1 android imac win ios", text)
SCREWYOU3_HOOK(gd::string stringWithMaxWidth(gd::string text, float width, float scale))
SCREWYOU3_HOOK_IMPL(MultilineBitmapFont, stringWithMaxWidth, "m1 android imac win ios", text, width, scale)
SCREWYOU3_HOOK_END("MultilineBitmapFont::initWithFont")

#include <Geode/modify/MultiplayerLayer.hpp>

bool MultiplayerLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MultiplayerLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(MultiplayerLayer, init, "m1 imac android", )
#endif
SCREWYOU3_HOOK_END("MultiplayerLayer::init")

#include <Geode/modify/MultiTriggerPopup.hpp>

bool MultiTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MultiTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(MultiTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("MultiTriggerPopup::init")

#include <Geode/modify/MusicArtistObject.hpp>

bool MusicArtistObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MusicArtistObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int id, gd::string name, gd::string url, gd::string youtube))
SCREWYOU3_HOOK_IMPL(MusicArtistObject, init, " m1 android imac", id, name, url, youtube)
#endif
SCREWYOU3_HOOK_END("MusicArtistObject::init")

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
SCREWYOU3_HOOK_IMPL(MusicBrowser, cellPerformedAction, "m1 android imac win ios", cell, listType, action, parent)
SCREWYOU3_HOOK(int getSelectedCellIdx())
SCREWYOU3_HOOK_IMPL(MusicBrowser, getSelectedCellIdx, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool init(int songID, GJSongType songType))
SCREWYOU3_HOOK_IMPL(MusicBrowser, init, "m1 android imac win ios", songID, songType)
SCREWYOU3_HOOK_END("MusicBrowser::cellPerformedAction")

#include <Geode/modify/MusicDelegateHandler.hpp>

bool MusicDelegateHandler_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MusicDelegateHandler)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(MusicDownloadDelegate* delegate))
SCREWYOU3_HOOK_IMPL(MusicDelegateHandler, init, " m1 android imac", delegate)
#endif
SCREWYOU3_HOOK_END("MusicDelegateHandler::init")

#include <Geode/modify/MusicDownloadManager.hpp>

bool MusicDownloadManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string MusicDownloadManager_generateCustomContentURL_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int MusicDownloadManager_getDownloadProgress_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int MusicDownloadManager_getSFXDownloadProgress_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string MusicDownloadManager_getSFXFolderPathForID_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int MusicDownloadManager_getSongPriority_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool MusicDownloadManager_isDLActive_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MusicDownloadManager_isMusicLibraryLoaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MusicDownloadManager_isResourceSFX_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MusicDownloadManager_isResourceSong_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MusicDownloadManager_isRunningActionForSongID_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MusicDownloadManager_isSFXDownloaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MusicDownloadManager_isSFXLibraryLoaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool MusicDownloadManager_isSongDownloaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string MusicDownloadManager_nameForTagID_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
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
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string generateCustomContentURL(gd::string path))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, generateCustomContentURL, "m1 android imac win ios", path)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getDownloadProgress(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, getDownloadProgress, " m1 android imac ios", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getSFXDownloadProgress(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, getSFXDownloadProgress, " m1 android imac ios", id)
#endif
SCREWYOU3_HOOK(gd::string getSFXFolderPathForID(int id, bool nextFolder))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, getSFXFolderPathForID, "m1 android imac win ios", id, nextFolder)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getSongPriority())
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, getSongPriority, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isDLActive(char const* tag))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, isDLActive, " m1 android imac", tag)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isMusicLibraryLoaded())
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, isMusicLibraryLoaded, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isResourceSFX(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, isResourceSFX, " m1 android imac", id)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isResourceSong(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, isResourceSong, " m1 android imac", id)
#endif
SCREWYOU3_HOOK(bool isRunningActionForSongID(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, isRunningActionForSongID, "m1 android imac win ios", id)
SCREWYOU3_HOOK(bool isSFXDownloaded(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, isSFXDownloaded, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isSFXLibraryLoaded())
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, isSFXLibraryLoaded, " m1 android imac", )
#endif
SCREWYOU3_HOOK(bool isSongDownloaded(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, isSongDownloaded, "m1 android imac win ios", id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string nameForTagID(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, nameForTagID, " m1 android imac ios", id)
#endif
SCREWYOU3_HOOK(gd::string pathForSFX(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, pathForSFX, "m1 android imac win ios", id)
SCREWYOU3_HOOK(gd::string pathForSFXFolder(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, pathForSFXFolder, "m1 android imac win ios", id)
SCREWYOU3_HOOK(gd::string pathForSong(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, pathForSong, "m1 android imac win ios", id)
SCREWYOU3_HOOK(gd::string pathForSongFolder(int id))
SCREWYOU3_HOOK_IMPL(MusicDownloadManager, pathForSongFolder, "m1 android imac win ios", id)
SCREWYOU3_HOOK_END("MusicDownloadManager::init")

#include <Geode/modify/MusicSearchResult.hpp>

bool MusicSearchResult_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(MusicSearchResult)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(GJSongType songType))
SCREWYOU3_HOOK_IMPL(MusicSearchResult, init, " m1 android imac", songType)
#endif
SCREWYOU3_HOOK_END("MusicSearchResult::init")

#include <Geode/modify/NCSInfoLayer.hpp>

bool NCSInfoLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(NCSInfoLayer)
SCREWYOU3_HOOK(bool init(CustomSongLayer* layer))
SCREWYOU3_HOOK_IMPL(NCSInfoLayer, init, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("NCSInfoLayer::init")

#include <Geode/modify/NewgroundsInfoLayer.hpp>

bool NewgroundsInfoLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(NewgroundsInfoLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(NewgroundsInfoLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("NewgroundsInfoLayer::init")

#include <Geode/modify/NodePoint.hpp>

bool NodePoint_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(NodePoint)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCPoint point))
SCREWYOU3_HOOK_IMPL(NodePoint, init, " m1 android imac", point)
#endif
SCREWYOU3_HOOK_END("NodePoint::init")

#include <Geode/modify/NumberInputLayer.hpp>

bool NumberInputLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(NumberInputLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(NumberInputLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("NumberInputLayer::init")

#include <Geode/modify/OBB2D.hpp>

bool OBB2D_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool OBB2D_overlaps_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool OBB2D_overlaps1Way_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(OBB2D)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCPoint center, float width, float height, float rotationAngle))
SCREWYOU3_HOOK_IMPL(OBB2D, init, " m1 android imac ios", center, width, height, rotationAngle)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool overlaps(OBB2D* other))
SCREWYOU3_HOOK_IMPL(OBB2D, overlaps, " m1 android imac ios", other)
#endif
SCREWYOU3_HOOK(bool overlaps1Way(OBB2D* other))
SCREWYOU3_HOOK_IMPL(OBB2D, overlaps1Way, "m1 android imac win ios", other)
SCREWYOU3_HOOK_END("OBB2D::init")

#include <Geode/modify/ObjectControlGameObject.hpp>

bool ObjectControlGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string ObjectControlGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(ObjectControlGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ObjectControlGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(ObjectControlGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("ObjectControlGameObject::init")

#include <Geode/modify/ObjectManager.hpp>

bool ObjectManager_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool ObjectManager_animLoaded_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ObjectManager)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ObjectManager, init, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool animLoaded(char const* anim))
SCREWYOU3_HOOK_IMPL(ObjectManager, animLoaded, " m1 android imac ios", anim)
#endif
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
SCREWYOU3_HOOK_IMPL(ObjectToolbox, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(float gridNodeSizeForKey(int key))
SCREWYOU3_HOOK_IMPL(ObjectToolbox, gridNodeSizeForKey, "m1 android imac win ios", key)
SCREWYOU3_HOOK(const char* intKeyToFrame(int key))
SCREWYOU3_HOOK_IMPL(ObjectToolbox, intKeyToFrame, "m1 android imac win ios", key)
SCREWYOU3_HOOK(const char* perspectiveBlockFrame(int key))
SCREWYOU3_HOOK_IMPL(ObjectToolbox, perspectiveBlockFrame, "m1 android imac win ios", key)
SCREWYOU3_HOOK_END("ObjectToolbox::init")

#include <Geode/modify/OptionsObject.hpp>

bool OptionsObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(OptionsObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int id, bool enabled, gd::string name, OptionsObjectDelegate* delegate))
SCREWYOU3_HOOK_IMPL(OptionsObject, init, " m1 android imac", id, enabled, name, delegate)
#endif
SCREWYOU3_HOOK_END("OptionsObject::init")

#include <Geode/modify/OptionsScrollLayer.hpp>

bool OptionsScrollLayer_cellPerformedAction_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool OptionsScrollLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(OptionsScrollLayer)
SCREWYOU3_HOOK(bool cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(OptionsScrollLayer, cellPerformedAction, "m1 android imac win ios", cell, listType, action, parent)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* objects, bool recreate, int minimum))
SCREWYOU3_HOOK_IMPL(OptionsScrollLayer, init, " m1 android imac ios", objects, recreate, minimum)
#endif
SCREWYOU3_HOOK_END("OptionsScrollLayer::cellPerformedAction")

#include <Geode/modify/ParentalOptionsLayer.hpp>

bool ParentalOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int ParentalOptionsLayer_countForPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

const char* ParentalOptionsLayer_infoKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* ParentalOptionsLayer_layerKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* ParentalOptionsLayer_objectKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

const char* ParentalOptionsLayer_pageKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(ParentalOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ParentalOptionsLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(int countForPage(int page))
SCREWYOU3_HOOK_IMPL(ParentalOptionsLayer, countForPage, "m1 android imac win ios", page)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* infoKey(int index))
SCREWYOU3_HOOK_IMPL(ParentalOptionsLayer, infoKey, " m1 android imac", index)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* layerKey(int page))
SCREWYOU3_HOOK_IMPL(ParentalOptionsLayer, layerKey, " m1 android imac", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* objectKey(int page))
SCREWYOU3_HOOK_IMPL(ParentalOptionsLayer, objectKey, " m1 android imac", page)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* pageKey(int page))
SCREWYOU3_HOOK_IMPL(ParentalOptionsLayer, pageKey, " m1 android imac", page)
#endif
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
SCREWYOU3_HOOK_IMPL(ParticleGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(ParticleGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("ParticleGameObject::init")

#include <Geode/modify/ParticlePreviewLayer.hpp>

bool ParticlePreviewLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ParticlePreviewLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCParticleSystemQuad* particleSystem))
SCREWYOU3_HOOK_IMPL(ParticlePreviewLayer, init, " m1 android imac ios", particleSystem)
#endif
SCREWYOU3_HOOK_END("ParticlePreviewLayer::init")

#include <Geode/modify/PauseLayer.hpp>

bool PauseLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PauseLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(bool unfocused))
SCREWYOU3_HOOK_IMPL(PauseLayer, init, " m1 android imac", unfocused)
#endif
SCREWYOU3_HOOK_END("PauseLayer::init")

#include <Geode/modify/PlatformToolbox.hpp>

bool PlatformToolbox_copyToClipboard_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlatformToolbox_doesFileExist_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string PlatformToolbox_getClipboardString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string PlatformToolbox_getRawPath_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string PlatformToolbox_getUniqueUserID_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string PlatformToolbox_getUserID_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool PlatformToolbox_isControllerConnected_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlatformToolbox_isHD_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlatformToolbox_isLocalPlayerAuthenticated_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlatformToolbox_isLowMemoryDevice_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlatformToolbox_isNetworkAvailable_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlatformToolbox_isSignedInGooglePlay_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlatformToolbox_shouldResumeSound_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PlatformToolbox)
SCREWYOU3_HOOK(static bool copyToClipboard(gd::string str))
SCREWYOU3_HOOK_IMPL(PlatformToolbox, copyToClipboard, "m1 android imac win ios", str)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool doesFileExist(gd::string path))
SCREWYOU3_HOOK_IMPL(PlatformToolbox, doesFileExist, " m1 android imac ios", path)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string getClipboardString())
SCREWYOU3_HOOK_IMPL(PlatformToolbox, getClipboardString, "ios android", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string getRawPath(char const* path))
SCREWYOU3_HOOK_IMPL(PlatformToolbox, getRawPath, " m1 android imac", path)
#endif
SCREWYOU3_HOOK(static gd::string getUniqueUserID())
SCREWYOU3_HOOK_IMPL(PlatformToolbox, getUniqueUserID, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string getUserID())
SCREWYOU3_HOOK_IMPL(PlatformToolbox, getUserID, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool isControllerConnected())
SCREWYOU3_HOOK_IMPL(PlatformToolbox, isControllerConnected, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool isHD())
SCREWYOU3_HOOK_IMPL(PlatformToolbox, isHD, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool isLocalPlayerAuthenticated())
SCREWYOU3_HOOK_IMPL(PlatformToolbox, isLocalPlayerAuthenticated, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool isLowMemoryDevice())
SCREWYOU3_HOOK_IMPL(PlatformToolbox, isLowMemoryDevice, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool isNetworkAvailable())
SCREWYOU3_HOOK_IMPL(PlatformToolbox, isNetworkAvailable, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool isSignedInGooglePlay())
SCREWYOU3_HOOK_IMPL(PlatformToolbox, isSignedInGooglePlay, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static bool shouldResumeSound())
SCREWYOU3_HOOK_IMPL(PlatformToolbox, shouldResumeSound, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("PlatformToolbox::copyToClipboard")

#include <Geode/modify/PlayerCheckpoint.hpp>

bool PlayerCheckpoint_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PlayerCheckpoint)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(PlayerCheckpoint, init, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(PlayerControlGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(PlayerControlGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("PlayerControlGameObject::init")

#include <Geode/modify/PlayerFireBoostSprite.hpp>

bool PlayerFireBoostSprite_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PlayerFireBoostSprite)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(PlayerFireBoostSprite, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("PlayerFireBoostSprite::init")

#include <Geode/modify/PlayerObject.hpp>

float PlayerObject_getObjectRotation_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool PlayerObject_buttonDown_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_canStickToGround_override() {
	return modUtils::chooseRandomNum(0, 1);
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

bool PlayerObject_destroyFromHitHead_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int PlayerObject_flipMod_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

double PlayerObject_getCurrentXVelocity_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float PlayerObject_getModifiedSlopeYVel_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float PlayerObject_getOldPosition_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

double PlayerObject_getYVelocity_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool PlayerObject_handleRotatedCollisionInternal_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_handleRotatedObjectCollision_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_isBoostValid_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_isFlying_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_isInBasicMode_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_isInNormalMode_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_isSafeFlip_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_isSafeHeadTest_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_isSafeMode_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_isSafeSpiderFlip_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_levelFlipping_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_playerIsFalling_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_playerIsFallingBugged_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_playerIsMovingUp_override() {
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

int PlayerObject_reverseMod_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool PlayerObject_switchedDirTo_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_testForMoving_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayerObject_usingWallLimitedMode_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PlayerObject)
SCREWYOU3_HOOK(float getObjectRotation())
SCREWYOU3_HOOK_IMPL(PlayerObject, getObjectRotation, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool buttonDown(PlayerButton button))
SCREWYOU3_HOOK_IMPL(PlayerObject, buttonDown, " m1 android imac", button)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canStickToGround())
SCREWYOU3_HOOK_IMPL(PlayerObject, canStickToGround, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool collidedWithObject(float dt, GameObject* object))
SCREWYOU3_HOOK_IMPL(PlayerObject, collidedWithObject, " m1 android imac ios", dt, object)
#endif
SCREWYOU3_HOOK(bool collidedWithObject(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck))
SCREWYOU3_HOOK_IMPL(PlayerObject, collidedWithObject, "m1 android imac win ios", dt, object, rect, skipCheck)
SCREWYOU3_HOOK(bool collidedWithObjectInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck))
SCREWYOU3_HOOK_IMPL(PlayerObject, collidedWithObjectInternal, "m1 android imac win ios", dt, object, rect, skipCheck)
SCREWYOU3_HOOK(float convertToClosestRotation(float rotation))
SCREWYOU3_HOOK_IMPL(PlayerObject, convertToClosestRotation, "m1 android imac win ios", rotation)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool destroyFromHitHead())
SCREWYOU3_HOOK_IMPL(PlayerObject, destroyFromHitHead, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int flipMod())
SCREWYOU3_HOOK_IMPL(PlayerObject, flipMod, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(double getCurrentXVelocity())
SCREWYOU3_HOOK_IMPL(PlayerObject, getCurrentXVelocity, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getModifiedSlopeYVel())
SCREWYOU3_HOOK_IMPL(PlayerObject, getModifiedSlopeYVel, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getOldPosition(float dt))
SCREWYOU3_HOOK_IMPL(PlayerObject, getOldPosition, " m1 android imac ios", dt)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(double getYVelocity())
SCREWYOU3_HOOK_IMPL(PlayerObject, getYVelocity, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool handleRotatedCollisionInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck, bool skipPre, bool slope))
SCREWYOU3_HOOK_IMPL(PlayerObject, handleRotatedCollisionInternal, "m1 android imac win ios", dt, object, rect, skipCheck, skipPre, slope)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool handleRotatedObjectCollision(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck))
SCREWYOU3_HOOK_IMPL(PlayerObject, handleRotatedObjectCollision, " m1 android imac", dt, object, rect, skipCheck)
#endif
SCREWYOU3_HOOK(bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer))
SCREWYOU3_HOOK_IMPL(PlayerObject, init, "m1 android imac win ios", player, ship, gameLayer, layer, playLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isBoostValid(float yVelocity))
SCREWYOU3_HOOK_IMPL(PlayerObject, isBoostValid, " m1 android imac ios", yVelocity)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isFlying())
SCREWYOU3_HOOK_IMPL(PlayerObject, isFlying, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isInBasicMode())
SCREWYOU3_HOOK_IMPL(PlayerObject, isInBasicMode, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isInNormalMode())
SCREWYOU3_HOOK_IMPL(PlayerObject, isInNormalMode, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isSafeFlip(float flipTime))
SCREWYOU3_HOOK_IMPL(PlayerObject, isSafeFlip, " m1 android imac ios", flipTime)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isSafeHeadTest())
SCREWYOU3_HOOK_IMPL(PlayerObject, isSafeHeadTest, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isSafeMode(float changeTime))
SCREWYOU3_HOOK_IMPL(PlayerObject, isSafeMode, " m1 android imac", changeTime)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isSafeSpiderFlip(float flipTime))
SCREWYOU3_HOOK_IMPL(PlayerObject, isSafeSpiderFlip, " m1 android imac", flipTime)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool levelFlipping())
SCREWYOU3_HOOK_IMPL(PlayerObject, levelFlipping, "m1 android imac win", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool playerIsFalling(float yVelocity))
SCREWYOU3_HOOK_IMPL(PlayerObject, playerIsFalling, " m1 android imac", yVelocity)
#endif
SCREWYOU3_HOOK(bool playerIsFallingBugged())
SCREWYOU3_HOOK_IMPL(PlayerObject, playerIsFallingBugged, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool playerIsMovingUp())
SCREWYOU3_HOOK_IMPL(PlayerObject, playerIsMovingUp, " m1 android imac", )
#endif
SCREWYOU3_HOOK(bool preSlopeCollision(float dt, GameObject* object))
SCREWYOU3_HOOK_IMPL(PlayerObject, preSlopeCollision, "m1 android imac win ios", dt, object)
SCREWYOU3_HOOK(bool pushButton(PlayerButton button))
SCREWYOU3_HOOK_IMPL(PlayerObject, pushButton, "m1 android imac win ios", button)
SCREWYOU3_HOOK(bool releaseButton(PlayerButton button))
SCREWYOU3_HOOK_IMPL(PlayerObject, releaseButton, "m1 android imac win ios", button)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int reverseMod())
SCREWYOU3_HOOK_IMPL(PlayerObject, reverseMod, " m1 android imac", )
#endif
SCREWYOU3_HOOK(bool switchedDirTo(PlayerButton button))
SCREWYOU3_HOOK_IMPL(PlayerObject, switchedDirTo, "m1 android imac win ios", button)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool testForMoving(float dt, GameObject* object))
SCREWYOU3_HOOK_IMPL(PlayerObject, testForMoving, " m1 android imac ios", dt, object)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool usingWallLimitedMode())
SCREWYOU3_HOOK_IMPL(PlayerObject, usingWallLimitedMode, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("PlayerObject::getObjectRotation")

#include <Geode/modify/PlayLayer.hpp>

float PlayLayer_opacityForObject_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float PlayLayer_timeForPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool PlayLayer_canPauseGame_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float PlayLayer_getCurrentPercent_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int PlayLayer_getCurrentPercentInt_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float PlayLayer_getRelativeMod_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float PlayLayer_getRelativeModNew_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

double PlayLayer_getTempMilliTime_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool PlayLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayLayer_isGameplayActive_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayLayer_shouldBlend_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool PlayLayer_shouldDebugDraw_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PlayLayer)
SCREWYOU3_HOOK(float opacityForObject(GameObject* object))
SCREWYOU3_HOOK_IMPL(PlayLayer, opacityForObject, "m1 android imac win ios", object)
SCREWYOU3_HOOK(float timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, int id))
SCREWYOU3_HOOK_IMPL(PlayLayer, timeForPos, "m1 android imac win ios", position, order, channel, songTriggers, id)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canPauseGame())
SCREWYOU3_HOOK_IMPL(PlayLayer, canPauseGame, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(float getCurrentPercent())
SCREWYOU3_HOOK_IMPL(PlayLayer, getCurrentPercent, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getCurrentPercentInt())
SCREWYOU3_HOOK_IMPL(PlayLayer, getCurrentPercentInt, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getRelativeMod(cocos2d::CCPoint position, float right, float left, float offset))
SCREWYOU3_HOOK_IMPL(PlayLayer, getRelativeMod, " m1 android imac", position, right, left, offset)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getRelativeModNew(cocos2d::CCPoint position, float mod, float offset, bool unused, bool isRight))
SCREWYOU3_HOOK_IMPL(PlayLayer, getRelativeModNew, " m1 android imac", position, mod, offset, unused, isRight)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(double getTempMilliTime())
SCREWYOU3_HOOK_IMPL(PlayLayer, getTempMilliTime, " android", )
#endif
SCREWYOU3_HOOK(bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects))
SCREWYOU3_HOOK_IMPL(PlayLayer, init, "m1 android imac win ios", level, useReplay, dontCreateObjects)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isGameplayActive())
SCREWYOU3_HOOK_IMPL(PlayLayer, isGameplayActive, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldBlend(int colorID))
SCREWYOU3_HOOK_IMPL(PlayLayer, shouldBlend, " m1 android imac ios", colorID)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldDebugDraw())
SCREWYOU3_HOOK_IMPL(PlayLayer, shouldDebugDraw, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("PlayLayer::opacityForObject")

#include <Geode/modify/PointNode.hpp>

bool PointNode_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PointNode)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCPoint point))
SCREWYOU3_HOOK_IMPL(PointNode, init, " m1 android imac", point)
#endif
SCREWYOU3_HOOK_END("PointNode::init")

#include <Geode/modify/PriceLabel.hpp>

bool PriceLabel_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PriceLabel)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int price))
SCREWYOU3_HOOK_IMPL(PriceLabel, init, "m1 imac android", price)
#endif
SCREWYOU3_HOOK_END("PriceLabel::init")

#include <Geode/modify/ProfilePage.hpp>

bool ProfilePage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool ProfilePage_isCorrect_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool ProfilePage_isOnWatchlist_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ProfilePage)
SCREWYOU3_HOOK(bool init(int accountID, bool ownProfile))
SCREWYOU3_HOOK_IMPL(ProfilePage, init, "m1 android imac win ios", accountID, ownProfile)
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(ProfilePage, isCorrect, "m1 android imac win ios", key)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isOnWatchlist(int id))
SCREWYOU3_HOOK_IMPL(ProfilePage, isOnWatchlist, " m1 android imac", id)
#endif
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
SCREWYOU3_HOOK_IMPL(PromoInterstitial, ccTouchBegan, "m1 imac android", touch, event)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(bool fullVersion))
SCREWYOU3_HOOK_IMPL(PromoInterstitial, init, "m1 imac android", fullVersion)
#endif
SCREWYOU3_HOOK_END("PromoInterstitial::ccTouchBegan")

#include <Geode/modify/PulseEffectAction.hpp>

bool PulseEffectAction_isFinished_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float PulseEffectAction_valueForDelta_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(PulseEffectAction)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isFinished())
SCREWYOU3_HOOK_IMPL(PulseEffectAction, isFinished, " m1 android imac", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float valueForDelta(float currentTime, float fadeInTime, float holdTime, float fadeOutTime))
SCREWYOU3_HOOK_IMPL(PulseEffectAction, valueForDelta, " m1 android imac", currentTime, fadeInTime, holdTime, fadeOutTime)
#endif
SCREWYOU3_HOOK_END("PulseEffectAction::isFinished")

#include <Geode/modify/PurchaseItemPopup.hpp>

bool PurchaseItemPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(PurchaseItemPopup)
SCREWYOU3_HOOK(bool init(GJStoreItem* item))
SCREWYOU3_HOOK_IMPL(PurchaseItemPopup, init, "m1 android imac win ios", item)
SCREWYOU3_HOOK_END("PurchaseItemPopup::init")

#include <Geode/modify/RandTriggerGameObject.hpp>

bool RandTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string RandTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int RandTriggerGameObject_getRandomGroupID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int RandTriggerGameObject_getTotalChance_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(RandTriggerGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(RandTriggerGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(RandTriggerGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getRandomGroupID())
SCREWYOU3_HOOK_IMPL(RandTriggerGameObject, getRandomGroupID, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getTotalChance())
SCREWYOU3_HOOK_IMPL(RandTriggerGameObject, getTotalChance, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK_END("RandTriggerGameObject::init")

#include <Geode/modify/RateDemonLayer.hpp>

bool RateDemonLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(RateDemonLayer)
SCREWYOU3_HOOK(bool init(int levelID))
SCREWYOU3_HOOK_IMPL(RateDemonLayer, init, "m1 android imac win ios", levelID)
SCREWYOU3_HOOK_END("RateDemonLayer::init")

#include <Geode/modify/RateLevelLayer.hpp>

bool RateLevelLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(RateLevelLayer)
SCREWYOU3_HOOK(bool init(int levelID))
SCREWYOU3_HOOK_IMPL(RateLevelLayer, init, "m1 android imac win ios", levelID)
SCREWYOU3_HOOK_END("RateLevelLayer::init")

#include <Geode/modify/RateStarsLayer.hpp>

bool RateStarsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(RateStarsLayer)
SCREWYOU3_HOOK(bool init(int levelID, bool platformer, bool moderator))
SCREWYOU3_HOOK_IMPL(RateStarsLayer, init, "m1 android imac win ios", levelID, platformer, moderator)
SCREWYOU3_HOOK_END("RateStarsLayer::init")

#include <Geode/modify/RetryLevelLayer.hpp>

const char* RetryLevelLayer_getEndText_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(RetryLevelLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(const char* getEndText())
SCREWYOU3_HOOK_IMPL(RetryLevelLayer, getEndText, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("RetryLevelLayer::getEndText")

#include <Geode/modify/RewardsPage.hpp>

bool RewardsPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(RewardsPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(RewardsPage, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("RewardsPage::init")

#include <Geode/modify/RewardUnlockLayer.hpp>

bool RewardUnlockLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool RewardUnlockLayer_readyToCollect_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool RewardUnlockLayer_showCollectReward_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(RewardUnlockLayer)
SCREWYOU3_HOOK(bool init(int type, RewardsPage* page))
SCREWYOU3_HOOK_IMPL(RewardUnlockLayer, init, "m1 android imac win ios", type, page)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool readyToCollect(GJRewardItem* item))
SCREWYOU3_HOOK_IMPL(RewardUnlockLayer, readyToCollect, " m1 android imac", item)
#endif
SCREWYOU3_HOOK(bool showCollectReward(GJRewardItem* item))
SCREWYOU3_HOOK_IMPL(RewardUnlockLayer, showCollectReward, "m1 android imac win ios", item)
SCREWYOU3_HOOK_END("RewardUnlockLayer::init")

#include <Geode/modify/RingObject.hpp>

gd::string RingObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool RingObject_shouldDrawEditorHitbox_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool RingObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(RingObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(RingObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK(bool shouldDrawEditorHitbox())
SCREWYOU3_HOOK_IMPL(RingObject, shouldDrawEditorHitbox, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(RingObject, init, " m1 android imac", frame)
#endif
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
SCREWYOU3_HOOK_IMPL(RotateGameplayGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(RotateGameplayGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("RotateGameplayGameObject::init")

#include <Geode/modify/ScrollingLayer.hpp>

bool ScrollingLayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool ScrollingLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ScrollingLayer)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(ScrollingLayer, ccTouchBegan, "m1 android imac win ios", touch, event)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCSize size, cocos2d::CCPoint position, float factor))
SCREWYOU3_HOOK_IMPL(ScrollingLayer, init, " m1 android imac ios", size, position, factor)
#endif
SCREWYOU3_HOOK_END("ScrollingLayer::ccTouchBegan")

#include <Geode/modify/SearchButton.hpp>

bool SearchButton_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SearchButton)
SCREWYOU3_HOOK(bool init(char const* background, char const* label, float scale, char const* icon))
SCREWYOU3_HOOK_IMPL(SearchButton, init, "m1 android imac win ios", background, label, scale, icon)
SCREWYOU3_HOOK_END("SearchButton::init")

#include <Geode/modify/SearchSFXPopup.hpp>

bool SearchSFXPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SearchSFXPopup)
SCREWYOU3_HOOK(bool init(gd::string query))
SCREWYOU3_HOOK_IMPL(SearchSFXPopup, init, "m1 android imac win ios", query)
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
SCREWYOU3_HOOK_IMPL(SecretGame01Layer, init, "m1 imac android", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getCountForDifficulty(int difficulty))
SCREWYOU3_HOOK_IMPL(SecretGame01Layer, getCountForDifficulty, "m1 imac android", difficulty)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getFrameForDifficulty(int difficulty))
SCREWYOU3_HOOK_IMPL(SecretGame01Layer, getFrameForDifficulty, "m1 imac android", difficulty)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getRowsForDifficulty(int difficulty))
SCREWYOU3_HOOK_IMPL(SecretGame01Layer, getRowsForDifficulty, "m1 imac android", difficulty)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getTimeForDifficulty(int difficulty))
SCREWYOU3_HOOK_IMPL(SecretGame01Layer, getTimeForDifficulty, "m1 imac android", difficulty)
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
SCREWYOU3_HOOK_IMPL(SecretLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getBasicMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer, getBasicMessage, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer, getMessage, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getThreadMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer, getThreadMessage, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(SecretLayer2, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getBasicMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer2, getBasicMessage, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getErrorMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer2, getErrorMessage, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer2, getMessage, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getThreadMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer2, getThreadMessage, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("SecretLayer2::init")

#include <Geode/modify/SecretLayer3.hpp>

bool SecretLayer3_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SecretLayer3)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer3, init, "m1 android imac win ios", )
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
SCREWYOU3_HOOK_IMPL(SecretLayer4, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getBasicMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer4, getBasicMessage, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getErrorMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer4, getErrorMessage, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer4, getMessage, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getThreadMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer4, getThreadMessage, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("SecretLayer4::init")

#include <Geode/modify/SecretLayer5.hpp>

bool SecretLayer5_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string SecretLayer5_getMessage_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SecretLayer5)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer5, init, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getMessage())
SCREWYOU3_HOOK_IMPL(SecretLayer5, getMessage, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("SecretLayer5::init")

#include <Geode/modify/SecretLayer6.hpp>

bool SecretLayer6_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SecretLayer6)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretLayer6, init, "m1 imac android", )
#endif
SCREWYOU3_HOOK_END("SecretLayer6::init")

#include <Geode/modify/SecretNumberLayer.hpp>

bool SecretNumberLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SecretNumberLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SecretNumberLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("SecretNumberLayer::init")

#include <Geode/modify/SecretRewardsLayer.hpp>

bool SecretRewardsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SecretRewardsLayer)
SCREWYOU3_HOOK(bool init(bool fromShop))
SCREWYOU3_HOOK_IMPL(SecretRewardsLayer, init, "m1 android imac win ios", fromShop)
SCREWYOU3_HOOK_END("SecretRewardsLayer::init")

#include <Geode/modify/SelectArtLayer.hpp>

bool SelectArtLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectArtLayer)
SCREWYOU3_HOOK(bool init(SelectArtType type, int index))
SCREWYOU3_HOOK_IMPL(SelectArtLayer, init, "m1 android imac win ios", type, index)
SCREWYOU3_HOOK_END("SelectArtLayer::init")

#include <Geode/modify/SelectEventLayer.hpp>

bool SelectEventLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectEventLayer)
SCREWYOU3_HOOK(bool init(SetupEventLinkPopup* popup, gd::set<int>& eventIDs))
SCREWYOU3_HOOK_IMPL(SelectEventLayer, init, "m1 android imac win ios", popup, eventIDs)
SCREWYOU3_HOOK_END("SelectEventLayer::init")

#include <Geode/modify/SelectFontLayer.hpp>

bool SelectFontLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectFontLayer)
SCREWYOU3_HOOK(bool init(LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(SelectFontLayer, init, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("SelectFontLayer::init")

#include <Geode/modify/SelectListIconLayer.hpp>

bool SelectListIconLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectListIconLayer)
SCREWYOU3_HOOK(bool init(int difficulty))
SCREWYOU3_HOOK_IMPL(SelectListIconLayer, init, "m1 android imac win ios", difficulty)
SCREWYOU3_HOOK_END("SelectListIconLayer::init")

#include <Geode/modify/SelectPremadeLayer.hpp>

bool SelectPremadeLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectPremadeLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SelectPremadeLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("SelectPremadeLayer::init")

#include <Geode/modify/SelectSettingLayer.hpp>

gd::string SelectSettingLayer_frameForItem_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

gd::string SelectSettingLayer_frameForValue_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int SelectSettingLayer_idxToValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int SelectSettingLayer_valueToIdx_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string SelectSettingLayer_getSelectedFrame_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int SelectSettingLayer_getSelectedValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SelectSettingLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectSettingLayer)
SCREWYOU3_HOOK(static gd::string frameForItem(SelectSettingType type, int index))
SCREWYOU3_HOOK_IMPL(SelectSettingLayer, frameForItem, "m1 android imac win ios", type, index)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static gd::string frameForValue(SelectSettingType type, int value))
SCREWYOU3_HOOK_IMPL(SelectSettingLayer, frameForValue, " m1 android imac ios", type, value)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static int idxToValue(SelectSettingType type, int idx))
SCREWYOU3_HOOK_IMPL(SelectSettingLayer, idxToValue, " m1 android imac", type, idx)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(static int valueToIdx(SelectSettingType type, int value))
SCREWYOU3_HOOK_IMPL(SelectSettingLayer, valueToIdx, " m1 android imac", type, value)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getSelectedFrame())
SCREWYOU3_HOOK_IMPL(SelectSettingLayer, getSelectedFrame, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getSelectedValue())
SCREWYOU3_HOOK_IMPL(SelectSettingLayer, getSelectedValue, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool init(SelectSettingType type, int value))
SCREWYOU3_HOOK_IMPL(SelectSettingLayer, init, "m1 android imac win ios", type, value)
SCREWYOU3_HOOK_END("SelectSettingLayer::frameForItem")

#include <Geode/modify/SelectSFXSortLayer.hpp>

bool SelectSFXSortLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SelectSFXSortLayer)
SCREWYOU3_HOOK(bool init(AudioSortType sortType))
SCREWYOU3_HOOK_IMPL(SelectSFXSortLayer, init, "m1 android imac win ios", sortType)
SCREWYOU3_HOOK_END("SelectSFXSortLayer::init")

#include <Geode/modify/SequenceTriggerGameObject.hpp>

bool SequenceTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string SequenceTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool SequenceTriggerGameObject_reorderTarget_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SequenceTriggerGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SequenceTriggerGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SequenceTriggerGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool reorderTarget(int index, bool left))
SCREWYOU3_HOOK_IMPL(SequenceTriggerGameObject, reorderTarget, " m1 android imac ios", index, left)
#endif
SCREWYOU3_HOOK_END("SequenceTriggerGameObject::init")

#include <Geode/modify/SetColorIDPopup.hpp>

bool SetColorIDPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetColorIDPopup)
SCREWYOU3_HOOK(bool init(int id))
SCREWYOU3_HOOK_IMPL(SetColorIDPopup, init, "m1 android imac win ios", id)
SCREWYOU3_HOOK_END("SetColorIDPopup::init")

#include <Geode/modify/SetFolderPopup.hpp>

bool SetFolderPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetFolderPopup)
SCREWYOU3_HOOK(bool init(int value, bool isCreated, gd::string title))
SCREWYOU3_HOOK_IMPL(SetFolderPopup, init, "m1 android imac win ios", value, isCreated, title)
SCREWYOU3_HOOK_END("SetFolderPopup::init")

#include <Geode/modify/SetGroupIDLayer.hpp>

bool SetGroupIDLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetGroupIDLayer)
SCREWYOU3_HOOK(bool init(GameObject* obj, cocos2d::CCArray* objs))
SCREWYOU3_HOOK_IMPL(SetGroupIDLayer, init, "m1 android imac win ios", obj, objs)
SCREWYOU3_HOOK_END("SetGroupIDLayer::init")

#include <Geode/modify/SetIDPopup.hpp>

bool SetIDPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetIDPopup)
SCREWYOU3_HOOK(bool init(int current, int begin, int end, gd::string title, gd::string button, bool resetButton, int defaultValue, float offset, bool numberInput, bool arrows))
SCREWYOU3_HOOK_IMPL(SetIDPopup, init, "m1 android imac win ios", current, begin, end, title, button, resetButton, defaultValue, offset, numberInput, arrows)
SCREWYOU3_HOOK_END("SetIDPopup::init")

#include <Geode/modify/SetItemIDLayer.hpp>

bool SetItemIDLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetItemIDLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetItemIDLayer, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetItemIDLayer::init")

#include <Geode/modify/SetLevelOrderPopup.hpp>

bool SetLevelOrderPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetLevelOrderPopup)
SCREWYOU3_HOOK(bool init(int levelID, int order, int amount))
SCREWYOU3_HOOK_IMPL(SetLevelOrderPopup, init, "m1 android imac win ios", levelID, order, amount)
SCREWYOU3_HOOK_END("SetLevelOrderPopup::init")

#include <Geode/modify/SetTargetIDLayer.hpp>

bool SetTargetIDLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetTargetIDLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, gd::string title, gd::string label, int minimum, int maximum, int objectID))
SCREWYOU3_HOOK_IMPL(SetTargetIDLayer, init, "m1 android imac win ios", object, objects, title, label, minimum, maximum, objectID)
SCREWYOU3_HOOK_END("SetTargetIDLayer::init")

#include <Geode/modify/SetTextPopup.hpp>

bool SetTextPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetTextPopup)
SCREWYOU3_HOOK(bool init(gd::string value, gd::string placeholder, int maxLength, gd::string title, gd::string okBtnText, bool showResetBtn, float offset))
SCREWYOU3_HOOK_IMPL(SetTextPopup, init, "m1 android imac win ios", value, placeholder, maxLength, title, okBtnText, showResetBtn, offset)
SCREWYOU3_HOOK_END("SetTextPopup::init")

#include <Geode/modify/SetupAdvFollowEditPhysicsPopup.hpp>

bool SetupAdvFollowEditPhysicsPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAdvFollowEditPhysicsPopup)
SCREWYOU3_HOOK(bool init(AdvancedFollowEditObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAdvFollowEditPhysicsPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupAdvFollowEditPhysicsPopup::init")

#include <Geode/modify/SetupAdvFollowPopup.hpp>

bool SetupAdvFollowPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAdvFollowPopup)
SCREWYOU3_HOOK(bool init(AdvancedFollowTriggerObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAdvFollowPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupAdvFollowPopup::init")

#include <Geode/modify/SetupAdvFollowRetargetPopup.hpp>

bool SetupAdvFollowRetargetPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAdvFollowRetargetPopup)
SCREWYOU3_HOOK(bool init(AdvancedFollowEditObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAdvFollowRetargetPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupAdvFollowRetargetPopup::init")

#include <Geode/modify/SetupAnimationPopup.hpp>

bool SetupAnimationPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAnimationPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAnimationPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupAnimationPopup::init")

#include <Geode/modify/SetupAnimSettingsPopup.hpp>

bool SetupAnimSettingsPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAnimSettingsPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAnimSettingsPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupAnimSettingsPopup::init")

#include <Geode/modify/SetupAreaAnimTriggerPopup.hpp>

bool SetupAreaAnimTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaAnimTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupAreaAnimTriggerPopup, init, "m1 android imac win ios", object, objects, id)
SCREWYOU3_HOOK_END("SetupAreaAnimTriggerPopup::init")

#include <Geode/modify/SetupAreaFadeTriggerPopup.hpp>

bool SetupAreaFadeTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaFadeTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaFadeTriggerPopup, init, "m1 android imac win ios", object, objects)
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
SCREWYOU3_HOOK_IMPL(SetupAreaMoveTriggerPopup, triggerValueFromSliderValue, "m1 android imac win ios", tag, value)
SCREWYOU3_HOOK(float triggerSliderValueFromValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupAreaMoveTriggerPopup, triggerSliderValueFromValue, "m1 android imac win ios", tag, value)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaMoveTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupAreaMoveTriggerPopup::triggerValueFromSliderValue")

#include <Geode/modify/SetupAreaRotateTriggerPopup.hpp>

bool SetupAreaRotateTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaRotateTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaRotateTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupAreaRotateTriggerPopup::init")

#include <Geode/modify/SetupAreaTintTriggerPopup.hpp>

bool SetupAreaTintTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaTintTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaTintTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupAreaTintTriggerPopup::init")

#include <Geode/modify/SetupAreaTransformTriggerPopup.hpp>

bool SetupAreaTransformTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaTransformTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaTransformTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupAreaTransformTriggerPopup::init")

#include <Geode/modify/SetupAreaTriggerPopup.hpp>

bool SetupAreaTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAreaTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAreaTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupAreaTriggerPopup::init")

#include <Geode/modify/SetupArtSwitchPopup.hpp>

bool SetupArtSwitchPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupArtSwitchPopup)
SCREWYOU3_HOOK(bool init(ArtTriggerGameObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupArtSwitchPopup, init, "m1 android imac win ios", object, objects, id)
SCREWYOU3_HOOK_END("SetupArtSwitchPopup::init")

#include <Geode/modify/SetupAudioLineGuidePopup.hpp>

bool SetupAudioLineGuidePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupAudioLineGuidePopup)
SCREWYOU3_HOOK(bool init(AudioLineGuideGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupAudioLineGuidePopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupAudioLineGuidePopup::init")

#include <Geode/modify/SetupBGSpeedTrigger.hpp>

bool SetupBGSpeedTrigger_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupBGSpeedTrigger)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupBGSpeedTrigger, init, "m1 android imac win ios", object, objects, id)
SCREWYOU3_HOOK_END("SetupBGSpeedTrigger::init")

#include <Geode/modify/SetupCameraEdgePopup.hpp>

bool SetupCameraEdgePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCameraEdgePopup)
SCREWYOU3_HOOK(bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraEdgePopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupCameraEdgePopup::init")

#include <Geode/modify/SetupCameraGuidePopup.hpp>

bool SetupCameraGuidePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCameraGuidePopup)
SCREWYOU3_HOOK(bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraGuidePopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupCameraGuidePopup::init")

#include <Geode/modify/SetupCameraModePopup.hpp>

bool SetupCameraModePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCameraModePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraModePopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupCameraModePopup::init")

#include <Geode/modify/SetupCameraOffsetTrigger.hpp>

bool SetupCameraOffsetTrigger_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int SetupCameraOffsetTrigger_posFromSliderValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupCameraOffsetTrigger_sliderValueFromPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(SetupCameraOffsetTrigger)
SCREWYOU3_HOOK(bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraOffsetTrigger, init, "m1 android imac win ios", object, objects)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int posFromSliderValue(float value))
SCREWYOU3_HOOK_IMPL(SetupCameraOffsetTrigger, posFromSliderValue, " m1 android imac", value)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float sliderValueFromPos(int pos))
SCREWYOU3_HOOK_IMPL(SetupCameraOffsetTrigger, sliderValueFromPos, " m1 android imac", pos)
#endif
SCREWYOU3_HOOK_END("SetupCameraOffsetTrigger::init")

#include <Geode/modify/SetupCameraRotatePopup.hpp>

bool SetupCameraRotatePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCameraRotatePopup)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraRotatePopup, init, "m1 imac android", object, objects)
#endif
SCREWYOU3_HOOK_END("SetupCameraRotatePopup::init")

#include <Geode/modify/SetupCameraRotatePopup2.hpp>

bool SetupCameraRotatePopup2_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCameraRotatePopup2)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCameraRotatePopup2, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupCameraRotatePopup2::init")

#include <Geode/modify/SetupCheckpointPopup.hpp>

bool SetupCheckpointPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCheckpointPopup)
SCREWYOU3_HOOK(bool init(CheckpointGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCheckpointPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupCheckpointPopup::init")

#include <Geode/modify/SetupCoinLayer.hpp>

bool SetupCoinLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCoinLayer)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCoinLayer, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupCoinLayer::init")

#include <Geode/modify/SetupCollisionStateTriggerPopup.hpp>

bool SetupCollisionStateTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCollisionStateTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCollisionStateTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupCollisionStateTriggerPopup::init")

#include <Geode/modify/SetupCollisionTriggerPopup.hpp>

bool SetupCollisionTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCollisionTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCollisionTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupCollisionTriggerPopup::init")

#include <Geode/modify/SetupCountTriggerPopup.hpp>

bool SetupCountTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupCountTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupCountTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupCountTriggerPopup::init")

#include <Geode/modify/SetupDashRingPopup.hpp>

bool SetupDashRingPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupDashRingPopup)
SCREWYOU3_HOOK(bool init(DashRingObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupDashRingPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupDashRingPopup::init")

#include <Geode/modify/SetupEndPopup.hpp>

bool SetupEndPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupEndPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupEndPopup, init, "m1 android imac win ios", object, objects)
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
SCREWYOU3_HOOK_IMPL(SetupEnterEffectPopup, triggerValueFromSliderValue, "m1 android imac win ios", tag, value)
SCREWYOU3_HOOK(float triggerSliderValueFromValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupEnterEffectPopup, triggerSliderValueFromValue, "m1 android imac win ios", tag, value)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects, int id))
SCREWYOU3_HOOK_IMPL(SetupEnterEffectPopup, init, "m1 android imac win ios", object, objects, id)
SCREWYOU3_HOOK_END("SetupEnterEffectPopup::triggerValueFromSliderValue")

#include <Geode/modify/SetupEnterTriggerPopup.hpp>

bool SetupEnterTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupEnterTriggerPopup)
SCREWYOU3_HOOK(bool init(EnterEffectObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupEnterTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupEnterTriggerPopup::init")

#include <Geode/modify/SetupEventLinkPopup.hpp>

bool SetupEventLinkPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupEventLinkPopup)
SCREWYOU3_HOOK(bool init(EventLinkTrigger* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupEventLinkPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupEventLinkPopup::init")

#include <Geode/modify/SetupForceBlockPopup.hpp>

bool SetupForceBlockPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupForceBlockPopup)
SCREWYOU3_HOOK(bool init(ForceBlockGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupForceBlockPopup, init, "m1 android imac win ios", object, objects)
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
SCREWYOU3_HOOK_IMPL(SetupGameplayOffsetPopup, triggerValueFromSliderValue, "m1 android imac win ios", tag, value)
SCREWYOU3_HOOK(float triggerSliderValueFromValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupGameplayOffsetPopup, triggerSliderValueFromValue, "m1 android imac win ios", tag, value)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupGameplayOffsetPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupGameplayOffsetPopup::triggerValueFromSliderValue")

#include <Geode/modify/SetupGradientPopup.hpp>

bool SetupGradientPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupGradientPopup)
SCREWYOU3_HOOK(bool init(GradientTriggerObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupGradientPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupGradientPopup::init")

#include <Geode/modify/SetupGravityModPopup.hpp>

bool SetupGravityModPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupGravityModPopup)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, bool gravityTrigger))
SCREWYOU3_HOOK_IMPL(SetupGravityModPopup, init, "m1 imac android", object, objects, gravityTrigger)
#endif
SCREWYOU3_HOOK_END("SetupGravityModPopup::init")

#include <Geode/modify/SetupGravityTriggerPopup.hpp>

bool SetupGravityTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupGravityTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupGravityTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupGravityTriggerPopup::init")

#include <Geode/modify/SetupInstantCollisionTriggerPopup.hpp>

bool SetupInstantCollisionTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupInstantCollisionTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupInstantCollisionTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupInstantCollisionTriggerPopup::init")

#include <Geode/modify/SetupInstantCountPopup.hpp>

bool SetupInstantCountPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupInstantCountPopup)
SCREWYOU3_HOOK(bool init(CountTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupInstantCountPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupInstantCountPopup::init")

#include <Geode/modify/SetupInteractObjectPopup.hpp>

bool SetupInteractObjectPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupInteractObjectPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupInteractObjectPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupInteractObjectPopup::init")

#include <Geode/modify/SetupItemCompareTriggerPopup.hpp>

bool SetupItemCompareTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupItemCompareTriggerPopup)
SCREWYOU3_HOOK(bool init(ItemTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupItemCompareTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupItemCompareTriggerPopup::init")

#include <Geode/modify/SetupItemEditTriggerPopup.hpp>

bool SetupItemEditTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupItemEditTriggerPopup)
SCREWYOU3_HOOK(bool init(ItemTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupItemEditTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupItemEditTriggerPopup::init")

#include <Geode/modify/SetupKeyframeAnimPopup.hpp>

bool SetupKeyframeAnimPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupKeyframeAnimPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupKeyframeAnimPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupKeyframeAnimPopup::init")

#include <Geode/modify/SetupKeyframePopup.hpp>

bool SetupKeyframePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupKeyframePopup)
SCREWYOU3_HOOK(bool init(KeyframeGameObject* object, cocos2d::CCArray* objects, LevelEditorLayer* layer))
SCREWYOU3_HOOK_IMPL(SetupKeyframePopup, init, "m1 android imac win ios", object, objects, layer)
SCREWYOU3_HOOK_END("SetupKeyframePopup::init")

#include <Geode/modify/SetupMGTrigger.hpp>

bool SetupMGTrigger_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int SetupMGTrigger_posFromSliderValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupMGTrigger_sliderValueFromPos_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}


SCREWYOU3_HOOK_BEGIN(SetupMGTrigger)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupMGTrigger, init, "m1 android imac win ios", object, objects)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int posFromSliderValue(float value))
SCREWYOU3_HOOK_IMPL(SetupMGTrigger, posFromSliderValue, " m1 android imac", value)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float sliderValueFromPos(int pos))
SCREWYOU3_HOOK_IMPL(SetupMGTrigger, sliderValueFromPos, " m1 android imac", pos)
#endif
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
SCREWYOU3_HOOK_IMPL(SetupMoveCommandPopup, triggerValueFromSliderValue, "m1 android imac win ios", tag, value)
SCREWYOU3_HOOK(float triggerSliderValueFromValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupMoveCommandPopup, triggerSliderValueFromValue, "m1 android imac win ios", tag, value)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupMoveCommandPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupMoveCommandPopup::triggerValueFromSliderValue")

#include <Geode/modify/SetupObjectControlPopup.hpp>

bool SetupObjectControlPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupObjectControlPopup)
SCREWYOU3_HOOK(bool init(ObjectControlGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupObjectControlPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupObjectControlPopup::init")

#include <Geode/modify/SetupObjectOptions2Popup.hpp>

bool SetupObjectOptions2Popup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupObjectOptions2Popup)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupObjectOptions2Popup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupObjectOptions2Popup::init")

#include <Geode/modify/SetupObjectOptionsPopup.hpp>

bool SetupObjectOptionsPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupObjectOptionsPopup)
SCREWYOU3_HOOK(bool init(GameObject* object, cocos2d::CCArray* objects, SetGroupIDLayer* layer))
SCREWYOU3_HOOK_IMPL(SetupObjectOptionsPopup, init, "m1 android imac win ios", object, objects, layer)
SCREWYOU3_HOOK_END("SetupObjectOptionsPopup::init")

#include <Geode/modify/SetupObjectTogglePopup.hpp>

bool SetupObjectTogglePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupObjectTogglePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects, bool platformer))
SCREWYOU3_HOOK_IMPL(SetupObjectTogglePopup, init, "m1 android imac win ios", object, objects, platformer)
SCREWYOU3_HOOK_END("SetupObjectTogglePopup::init")

#include <Geode/modify/SetupOpacityPopup.hpp>

bool SetupOpacityPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupOpacityPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupOpacityPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupOpacityPopup::init")

#include <Geode/modify/SetupOptionsTriggerPopup.hpp>

bool SetupOptionsTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupOptionsTriggerPopup)
SCREWYOU3_HOOK(bool init(GameOptionsTrigger* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupOptionsTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupOptionsTriggerPopup::init")

#include <Geode/modify/SetupPersistentItemTriggerPopup.hpp>

bool SetupPersistentItemTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupPersistentItemTriggerPopup)
SCREWYOU3_HOOK(bool init(ItemTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPersistentItemTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupPersistentItemTriggerPopup::init")

#include <Geode/modify/SetupPickupTriggerPopup.hpp>

bool SetupPickupTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupPickupTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPickupTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupPickupTriggerPopup::init")

#include <Geode/modify/SetupPlatformerEndPopup.hpp>

bool SetupPlatformerEndPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupPlatformerEndPopup)
SCREWYOU3_HOOK(bool init(EndTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPlatformerEndPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupPlatformerEndPopup::init")

#include <Geode/modify/SetupPlayerControlPopup.hpp>

bool SetupPlayerControlPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupPlayerControlPopup)
SCREWYOU3_HOOK(bool init(PlayerControlGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPlayerControlPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupPlayerControlPopup::init")

#include <Geode/modify/SetupPortalPopup.hpp>

bool SetupPortalPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupPortalPopup)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPortalPopup, init, "m1 imac android", object, objects)
#endif
SCREWYOU3_HOOK_END("SetupPortalPopup::init")

#include <Geode/modify/SetupPulsePopup.hpp>

bool SetupPulsePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupPulsePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupPulsePopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupPulsePopup::init")

#include <Geode/modify/SetupRandAdvTriggerPopup.hpp>

bool SetupRandAdvTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupRandAdvTriggerPopup)
SCREWYOU3_HOOK(bool init(RandTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRandAdvTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupRandAdvTriggerPopup::init")

#include <Geode/modify/SetupRandTriggerPopup.hpp>

bool SetupRandTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupRandTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRandTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupRandTriggerPopup::init")

#include <Geode/modify/SetupResetTriggerPopup.hpp>

bool SetupResetTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupResetTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupResetTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupResetTriggerPopup::init")

#include <Geode/modify/SetupReverbPopup.hpp>

bool SetupReverbPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupReverbPopup)
SCREWYOU3_HOOK(bool init(SFXTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupReverbPopup, init, "m1 android imac win ios", object, objects)
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
SCREWYOU3_HOOK_IMPL(SetupRotateCommandPopup, triggerValueFromSliderValue, "m1 android imac win ios", tag, value)
SCREWYOU3_HOOK(float triggerSliderValueFromValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupRotateCommandPopup, triggerSliderValueFromValue, "m1 android imac win ios", tag, value)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRotateCommandPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupRotateCommandPopup::triggerValueFromSliderValue")

#include <Geode/modify/SetupRotateGameplayPopup.hpp>

bool SetupRotateGameplayPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupRotateGameplayPopup)
SCREWYOU3_HOOK(bool init(RotateGameplayGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRotateGameplayPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupRotateGameplayPopup::init")

#include <Geode/modify/SetupRotatePopup.hpp>

bool SetupRotatePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupRotatePopup)
SCREWYOU3_HOOK(bool init(EnhancedGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupRotatePopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupRotatePopup::init")

#include <Geode/modify/SetupSequenceTriggerPopup.hpp>

bool SetupSequenceTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSequenceTriggerPopup)
SCREWYOU3_HOOK(bool init(SequenceTriggerGameObject* object))
SCREWYOU3_HOOK_IMPL(SetupSequenceTriggerPopup, init, "m1 android imac win ios", object)
SCREWYOU3_HOOK_END("SetupSequenceTriggerPopup::init")

#include <Geode/modify/SetupSFXEditPopup.hpp>

bool SetupSFXEditPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSFXEditPopup)
SCREWYOU3_HOOK(bool init(SFXTriggerGameObject* object, cocos2d::CCArray* objects, bool songTrigger))
SCREWYOU3_HOOK_IMPL(SetupSFXEditPopup, init, "m1 android imac win ios", object, objects, songTrigger)
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
SCREWYOU3_HOOK_IMPL(SetupSFXPopup, getActiveSFXID, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool overridePlaySFX(SFXInfoObject* object))
SCREWYOU3_HOOK_IMPL(SetupSFXPopup, overridePlaySFX, "m1 android imac win ios", object)
SCREWYOU3_HOOK(bool init(SFXTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSFXPopup, init, "m1 android imac win ios", object, objects)
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
SCREWYOU3_HOOK_IMPL(SetupShaderEffectPopup, init, "m1 android imac win ios", object, objects, id)
SCREWYOU3_HOOK(gd::string zLayerToString(int zLayer))
SCREWYOU3_HOOK_IMPL(SetupShaderEffectPopup, zLayerToString, "m1 android imac win ios", zLayer)
SCREWYOU3_HOOK_END("SetupShaderEffectPopup::init")

#include <Geode/modify/SetupShakePopup.hpp>

bool SetupShakePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupShakePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupShakePopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupShakePopup::init")

#include <Geode/modify/SetupSmartBlockLayer.hpp>

bool SetupSmartBlockLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSmartBlockLayer)
SCREWYOU3_HOOK(bool init(SmartGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSmartBlockLayer, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupSmartBlockLayer::init")

#include <Geode/modify/SetupSmartTemplateLayer.hpp>

bool SetupSmartTemplateLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSmartTemplateLayer)
SCREWYOU3_HOOK(bool init(GJSmartTemplate* smartTemplate))
SCREWYOU3_HOOK_IMPL(SetupSmartTemplateLayer, init, "m1 android imac win ios", smartTemplate)
SCREWYOU3_HOOK_END("SetupSmartTemplateLayer::init")

#include <Geode/modify/SetupSongTriggerPopup.hpp>

bool SetupSongTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSongTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSongTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupSongTriggerPopup::init")

#include <Geode/modify/SetupSpawnParticlePopup.hpp>

bool SetupSpawnParticlePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSpawnParticlePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSpawnParticlePopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupSpawnParticlePopup::init")

#include <Geode/modify/SetupSpawnPopup.hpp>

bool SetupSpawnPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupSpawnPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupSpawnPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupSpawnPopup::init")

#include <Geode/modify/SetupStaticCameraPopup.hpp>

bool SetupStaticCameraPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupStaticCameraPopup)
SCREWYOU3_HOOK(bool init(CameraTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupStaticCameraPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupStaticCameraPopup::init")

#include <Geode/modify/SetupStopTriggerPopup.hpp>

bool SetupStopTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupStopTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupStopTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupStopTriggerPopup::init")

#include <Geode/modify/SetupTeleportPopup.hpp>

bool SetupTeleportPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTeleportPopup)
SCREWYOU3_HOOK(bool init(TeleportPortalObject* object, cocos2d::CCArray* objects, int id, bool platformer))
SCREWYOU3_HOOK_IMPL(SetupTeleportPopup, init, "m1 android imac win ios", object, objects, id, platformer)
SCREWYOU3_HOOK_END("SetupTeleportPopup::init")

#include <Geode/modify/SetupTimerControlTriggerPopup.hpp>

bool SetupTimerControlTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTimerControlTriggerPopup)
SCREWYOU3_HOOK(bool init(TimerTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTimerControlTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupTimerControlTriggerPopup::init")

#include <Geode/modify/SetupTimerEventTriggerPopup.hpp>

bool SetupTimerEventTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTimerEventTriggerPopup)
SCREWYOU3_HOOK(bool init(TimerTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTimerEventTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupTimerEventTriggerPopup::init")

#include <Geode/modify/SetupTimerTriggerPopup.hpp>

bool SetupTimerTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTimerTriggerPopup)
SCREWYOU3_HOOK(bool init(TimerTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTimerTriggerPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupTimerTriggerPopup::init")

#include <Geode/modify/SetupTimeWarpPopup.hpp>

bool SetupTimeWarpPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTimeWarpPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTimeWarpPopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupTimeWarpPopup::init")

#include <Geode/modify/SetupTouchTogglePopup.hpp>

bool SetupTouchTogglePopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTouchTogglePopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTouchTogglePopup, init, "m1 android imac win ios", object, objects)
SCREWYOU3_HOOK_END("SetupTouchTogglePopup::init")

#include <Geode/modify/SetupTransformPopup.hpp>

bool SetupTransformPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTransformPopup)
SCREWYOU3_HOOK(bool init(TransformTriggerGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupTransformPopup, init, "m1 android imac win ios", object, objects)
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

float SetupTriggerPopup_getMaxSliderValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupTriggerPopup_getMinSliderValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupTriggerPopup_getTriggerValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupTriggerPopup_getTruncatedValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float SetupTriggerPopup_getTruncatedValueByTag_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SetupTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool SetupTriggerPopup_shouldLimitValue_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupTriggerPopup)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK(float getValue(int tag))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, getValue, "m1 android imac win ios", tag)
SCREWYOU3_HOOK(float triggerValueFromSliderValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, triggerValueFromSliderValue, "m1 android imac win ios", tag, value)
SCREWYOU3_HOOK(float triggerSliderValueFromValue(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, triggerSliderValueFromValue, "m1 android imac win ios", tag, value)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getMaxSliderValue(int property))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, getMaxSliderValue, " m1 android imac", property)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getMinSliderValue(int property))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, getMinSliderValue, " m1 android imac", property)
#endif
SCREWYOU3_HOOK(float getTriggerValue(int property, GameObject* object))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, getTriggerValue, "m1 android imac win ios", property, object)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getTruncatedValue(float value, int decimals))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, getTruncatedValue, "m1 android imac win", value, decimals)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getTruncatedValueByTag(int tag, float value))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, getTruncatedValueByTag, " m1 android imac ios", tag, value)
#endif
SCREWYOU3_HOOK(bool init(EffectGameObject* trigger, cocos2d::CCArray* triggers, float width, float height, int background))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, init, "m1 android imac win ios", trigger, triggers, width, height, background)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool shouldLimitValue(int property))
SCREWYOU3_HOOK_IMPL(SetupTriggerPopup, shouldLimitValue, " m1 android imac", property)
#endif
SCREWYOU3_HOOK_END("SetupTriggerPopup::ccTouchBegan")

#include <Geode/modify/SetupZoomTriggerPopup.hpp>

bool SetupZoomTriggerPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SetupZoomTriggerPopup)
SCREWYOU3_HOOK(bool init(EffectGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(SetupZoomTriggerPopup, init, "m1 android imac win ios", object, objects)
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
SCREWYOU3_HOOK_IMPL(SFXBrowser, cellPerformedAction, "m1 android imac win ios", cell, listType, action, parent)
SCREWYOU3_HOOK(int getSelectedCellIdx())
SCREWYOU3_HOOK_IMPL(SFXBrowser, getSelectedCellIdx, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool shouldSnapToSelected())
SCREWYOU3_HOOK_IMPL(SFXBrowser, shouldSnapToSelected, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool init(int id))
SCREWYOU3_HOOK_IMPL(SFXBrowser, init, "m1 android imac win ios", id)
SCREWYOU3_HOOK_END("SFXBrowser::cellPerformedAction")

#include <Geode/modify/SFXFolderObject.hpp>

bool SFXFolderObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SFXFolderObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int id, gd::string name, int folderID))
SCREWYOU3_HOOK_IMPL(SFXFolderObject, init, " m1 android imac ios", id, name, folderID)
#endif
SCREWYOU3_HOOK_END("SFXFolderObject::init")

#include <Geode/modify/SFXInfoObject.hpp>

gd::string SFXInfoObject_getLowerCaseName_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool SFXInfoObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SFXInfoObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(gd::string getLowerCaseName())
SCREWYOU3_HOOK_IMPL(SFXInfoObject, getLowerCaseName, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int id, gd::string name, int folderID, int size, int duration))
SCREWYOU3_HOOK_IMPL(SFXInfoObject, init, " m1 android imac", id, name, folderID, size, duration)
#endif
SCREWYOU3_HOOK_END("SFXInfoObject::getLowerCaseName")

#include <Geode/modify/SFXSearchResult.hpp>

int SFXSearchResult_getSelectedPage_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SFXSearchResult_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SFXSearchResult)
SCREWYOU3_HOOK(int getSelectedPage(int id, int count))
SCREWYOU3_HOOK_IMPL(SFXSearchResult, getSelectedPage, "m1 android imac win ios", id, count)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int folderID))
SCREWYOU3_HOOK_IMPL(SFXSearchResult, init, " m1 android imac", folderID)
#endif
SCREWYOU3_HOOK_END("SFXSearchResult::getSelectedPage")

#include <Geode/modify/SFXTriggerGameObject.hpp>

gd::string SFXTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int SFXTriggerGameObject_getSFXRefID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

int SFXTriggerGameObject_getUniqueSFXID_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SFXTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SFXTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SFXTriggerGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getSFXRefID())
SCREWYOU3_HOOK_IMPL(SFXTriggerGameObject, getSFXRefID, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(int getUniqueSFXID())
SCREWYOU3_HOOK_IMPL(SFXTriggerGameObject, getUniqueSFXID, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(SFXTriggerGameObject, init, " m1 android imac", frame)
#endif
SCREWYOU3_HOOK_END("SFXTriggerGameObject::getSaveString")

#include <Geode/modify/ShaderGameObject.hpp>

gd::string ShaderGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool ShaderGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ShaderGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(ShaderGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(ShaderGameObject, init, " m1 android imac", frame)
#endif
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
SCREWYOU3_HOOK_IMPL(ShaderLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool resetAllShaders())
SCREWYOU3_HOOK_IMPL(ShaderLayer, resetAllShaders, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool updateZLayer(int minLayer, int maxLayer, bool noParticles))
SCREWYOU3_HOOK_IMPL(ShaderLayer, updateZLayer, "m1 android imac win ios", minLayer, maxLayer, noParticles)
SCREWYOU3_HOOK_END("ShaderLayer::init")

#include <Geode/modify/ShardsPage.hpp>

bool ShardsPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ShardsPage)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(ShardsPage, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("ShardsPage::init")

#include <Geode/modify/ShareCommentLayer.hpp>

bool ShareCommentLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ShareCommentLayer)
SCREWYOU3_HOOK(bool init(gd::string title, int charLimit, CommentType type, int ID, gd::string desc))
SCREWYOU3_HOOK_IMPL(ShareCommentLayer, init, "m1 android imac win ios", title, charLimit, type, ID, desc)
SCREWYOU3_HOOK_END("ShareCommentLayer::init")

#include <Geode/modify/ShareLevelLayer.hpp>

bool ShareLevelLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ShareLevelLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(ShareLevelLayer, init, "m1 android imac win ios", level)
SCREWYOU3_HOOK_END("ShareLevelLayer::init")

#include <Geode/modify/ShareLevelSettingsLayer.hpp>

bool ShareLevelSettingsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ShareLevelSettingsLayer)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(ShareLevelSettingsLayer, init, "m1 android imac win ios", level)
SCREWYOU3_HOOK_END("ShareLevelSettingsLayer::init")

#include <Geode/modify/ShareListLayer.hpp>

bool ShareListLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(ShareListLayer)
SCREWYOU3_HOOK(bool init(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(ShareListLayer, init, "m1 android imac win ios", list)
SCREWYOU3_HOOK_END("ShareListLayer::init")

#include <Geode/modify/SimpleObject.hpp>

bool SimpleObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SimpleObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SimpleObject, init, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("SimpleObject::init")

#include <Geode/modify/SimplePlayer.hpp>

bool SimplePlayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SimplePlayer)
SCREWYOU3_HOOK(bool init(int id))
SCREWYOU3_HOOK_IMPL(SimplePlayer, init, "m1 android imac win ios", id)
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
SCREWYOU3_HOOK_IMPL(SlideInLayer, init, "m1 imac android", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(SlideInLayer, ccTouchBegan, "m1 imac android", touch, event)
#endif
SCREWYOU3_HOOK_END("SlideInLayer::init")

#include <Geode/modify/Slider.hpp>

bool Slider_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool Slider_getLiveDragging_override() {
	return modUtils::chooseRandomNum(0, 1);
}

float Slider_getValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool Slider_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(Slider)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(Slider, ccTouchBegan, "m1 android imac win ios", touch, event)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool getLiveDragging())
SCREWYOU3_HOOK_IMPL(Slider, getLiveDragging, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float getValue())
SCREWYOU3_HOOK_IMPL(Slider, getValue, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler, char const* bar, char const* groove, char const* thumb, char const* thumbSel, float scale))
SCREWYOU3_HOOK_IMPL(Slider, init, "m1 android imac win ios", target, handler, bar, groove, thumb, thumbSel, scale)
SCREWYOU3_HOOK_END("Slider::ccTouchBegan")

#include <Geode/modify/SliderThumb.hpp>

float SliderThumb_getValue_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool SliderThumb_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SliderThumb)
SCREWYOU3_HOOK(float getValue())
SCREWYOU3_HOOK_IMPL(SliderThumb, getValue, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler selector, char const* normalFrame, char const* selectedFrame))
SCREWYOU3_HOOK_IMPL(SliderThumb, init, " m1 android imac", target, selector, normalFrame, selectedFrame)
#endif
SCREWYOU3_HOOK_END("SliderThumb::getValue")

#include <Geode/modify/SliderTouchLogic.hpp>

bool SliderTouchLogic_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool SliderTouchLogic_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SliderTouchLogic)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(SliderTouchLogic, ccTouchBegan, "m1 android imac win ios", touch, event)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler selector, char const* thumb, char const* thumbSel, float scale))
SCREWYOU3_HOOK_IMPL(SliderTouchLogic, init, " m1 android imac ios", target, selector, thumb, thumbSel, scale)
#endif
SCREWYOU3_HOOK_END("SliderTouchLogic::ccTouchBegan")

#include <Geode/modify/SmartGameObject.hpp>

gd::string SmartGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool SmartGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SmartGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SmartGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(SmartGameObject, init, " m1 android imac ios", frame)
#endif
SCREWYOU3_HOOK_END("SmartGameObject::getSaveString")

#include <Geode/modify/SmartTemplateCell.hpp>

bool SmartTemplateCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SmartTemplateCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SmartTemplateCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("SmartTemplateCell::init")

#include <Geode/modify/SongCell.hpp>

bool SongCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SongCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SongCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("SongCell::init")

#include <Geode/modify/SongInfoLayer.hpp>

bool SongInfoLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SongInfoLayer)
SCREWYOU3_HOOK(bool init(gd::string songName, gd::string artistName, gd::string songURL, gd::string newgroundsURL, gd::string youtubeURL, gd::string facebookURL, int songID, gd::string songTags, int nongType))
SCREWYOU3_HOOK_IMPL(SongInfoLayer, init, "m1 android imac win ios", songName, artistName, songURL, newgroundsURL, youtubeURL, facebookURL, songID, songTags, nongType)
SCREWYOU3_HOOK_END("SongInfoLayer::init")

#include <Geode/modify/SongInfoObject.hpp>

bool SongInfoObject_canEncode_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool SongInfoObject_containsTag_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string SongInfoObject_getArtistNames_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int SongInfoObject_getExtraArtistCount_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

gd::string SongInfoObject_getTagsString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool SongInfoObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SongInfoObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool canEncode())
SCREWYOU3_HOOK_IMPL(SongInfoObject, canEncode, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool containsTag(int tag))
SCREWYOU3_HOOK_IMPL(SongInfoObject, containsTag, " m1 android imac", tag)
#endif
SCREWYOU3_HOOK(gd::string getArtistNames(int unused))
SCREWYOU3_HOOK_IMPL(SongInfoObject, getArtistNames, "m1 android imac win ios", unused)
SCREWYOU3_HOOK(int getExtraArtistCount())
SCREWYOU3_HOOK_IMPL(SongInfoObject, getExtraArtistCount, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getTagsString(bool shortTags))
SCREWYOU3_HOOK_IMPL(SongInfoObject, getTagsString, "m1 android imac win ios", shortTags)
SCREWYOU3_HOOK(bool init(int songID, gd::string songName, gd::string artistName, int artistID, float filesize, gd::string youtubeVideo, gd::string youtubeChannel, gd::string url, gd::string downloadLinkOverride, int nongType, gd::string extraArtistIDs, bool isNew, int libraryOrder, int priority))
SCREWYOU3_HOOK_IMPL(SongInfoObject, init, "m1 android imac win ios", songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, downloadLinkOverride, nongType, extraArtistIDs, isNew, libraryOrder, priority)
SCREWYOU3_HOOK_END("SongInfoObject::canEncode")

#include <Geode/modify/SongObject.hpp>

bool SongObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SongObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int audioID))
SCREWYOU3_HOOK_IMPL(SongObject, init, " m1 android imac", audioID)
#endif
SCREWYOU3_HOOK_END("SongObject::init")

#include <Geode/modify/SongOptionsLayer.hpp>

bool SongOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SongOptionsLayer)
SCREWYOU3_HOOK(bool init(CustomSongDelegate* delegate))
SCREWYOU3_HOOK_IMPL(SongOptionsLayer, init, "m1 android imac win ios", delegate)
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
SCREWYOU3_HOOK_IMPL(SongSelectNode, getActiveSongID, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSongFileName())
SCREWYOU3_HOOK_IMPL(SongSelectNode, getSongFileName, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool init(int id, bool customSong, LevelSettingsObject* settings, SongSelectType selectType, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCMenu* menu, bool noLabel))
SCREWYOU3_HOOK_IMPL(SongSelectNode, init, "m1 android imac win ios", id, customSong, settings, selectType, position, parent, menu, noLabel)
SCREWYOU3_HOOK_END("SongSelectNode::getActiveSongID")

#include <Geode/modify/SongTriggerGameObject.hpp>

gd::string SongTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool SongTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SongTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SongTriggerGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(SongTriggerGameObject, init, " m1 android imac", frame)
#endif
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
SCREWYOU3_HOOK_IMPL(SpawnParticleGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SpawnParticleGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("SpawnParticleGameObject::init")

#include <Geode/modify/SpawnTriggerAction.hpp>

bool SpawnTriggerAction_isFinished_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SpawnTriggerAction)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isFinished())
SCREWYOU3_HOOK_IMPL(SpawnTriggerAction, isFinished, " m1 android imac", )
#endif
SCREWYOU3_HOOK_END("SpawnTriggerAction::isFinished")

#include <Geode/modify/SpawnTriggerGameObject.hpp>

bool SpawnTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

gd::string SpawnTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(SpawnTriggerGameObject)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(SpawnTriggerGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SpawnTriggerGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("SpawnTriggerGameObject::init")

#include <Geode/modify/SpecialAnimGameObject.hpp>

gd::string SpecialAnimGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool SpecialAnimGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SpecialAnimGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(SpecialAnimGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(SpecialAnimGameObject, init, " m1 android imac", frame)
#endif
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
SCREWYOU3_HOOK_IMPL(SpriteAnimationManager, getPrio, "m1 android imac win ios", animation)
SCREWYOU3_HOOK(bool initWithOwner(CCAnimatedSprite* sprite, gd::string definition))
SCREWYOU3_HOOK_IMPL(SpriteAnimationManager, initWithOwner, "m1 android imac win ios", sprite, definition)
SCREWYOU3_HOOK_END("SpriteAnimationManager::getPrio")

#include <Geode/modify/SpriteDescription.hpp>

bool SpriteDescription_initDescription_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(SpriteDescription)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool initDescription(DS_Dictionary* dict))
SCREWYOU3_HOOK_IMPL(SpriteDescription, initDescription, "m1 imac win android", dict)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool initDescription(cocos2d::CCDictionary* dict))
SCREWYOU3_HOOK_IMPL(SpriteDescription, initDescription, " m1 android imac ios", dict)
#endif
SCREWYOU3_HOOK_END("SpriteDescription::initDescription")

#include <Geode/modify/StarInfoPopup.hpp>

bool StarInfoPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(StarInfoPopup)
SCREWYOU3_HOOK(bool init(int autos, int easies, int normals, int hards, int harders, int insanes, int dailies, int gauntlets, int maps, bool platformer))
SCREWYOU3_HOOK_IMPL(StarInfoPopup, init, "m1 android imac win ios", autos, easies, normals, hards, harders, insanes, dailies, gauntlets, maps, platformer)
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
SCREWYOU3_HOOK_IMPL(StartPosObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(StartPosObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("StartPosObject::init")

#include <Geode/modify/StatsCell.hpp>

bool StatsCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

const char* StatsCell_getTitleFromKey_override() {

if (Mod::get()->getSettingValue<bool>("can-be-nullptr") && modUtils::chooseRandomNum(100) >= (100 - Mod::get()->getSettingValue<int64_t>("nullptr-chance")))
    	return nullptr;
	return modUtils::getRandomCharSequence_c(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}


SCREWYOU3_HOOK_BEGIN(StatsCell)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(StatsCell, init, " m1 android imac ios", )
#endif
SCREWYOU3_HOOK(const char* getTitleFromKey(char const* key))
SCREWYOU3_HOOK_IMPL(StatsCell, getTitleFromKey, "m1 android imac win ios", key)
SCREWYOU3_HOOK_END("StatsCell::init")

#include <Geode/modify/StatsObject.hpp>

bool StatsObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(StatsObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* key, int value))
SCREWYOU3_HOOK_IMPL(StatsObject, init, " m1 android imac ios", key, value)
#endif
SCREWYOU3_HOOK_END("StatsObject::init")

#include <Geode/modify/TableView.hpp>

bool TableView_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

int TableView_checkBoundaryOfCell_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool TableView_dequeueReusableCellWithIdentifier_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool TableView_isDuplicateIndexPath_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool TableView_isDuplicateInVisibleCellArray_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool TableView_removeIndexPathFromPathAddedArray_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TableView)
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(TableView, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK(int checkBoundaryOfCell(TableViewCell* cell))
SCREWYOU3_HOOK_IMPL(TableView, checkBoundaryOfCell, "m1 android imac win ios", cell)
SCREWYOU3_HOOK(int checkBoundaryOfCell(cocos2d::CCPoint& position, float height))
SCREWYOU3_HOOK_IMPL(TableView, checkBoundaryOfCell, "m1 android imac win ios", position, height)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool dequeueReusableCellWithIdentifier(char const* identifier))
SCREWYOU3_HOOK_IMPL(TableView, dequeueReusableCellWithIdentifier, " m1 android imac ios", identifier)
#endif
SCREWYOU3_HOOK(bool isDuplicateIndexPath(CCIndexPath& path))
SCREWYOU3_HOOK_IMPL(TableView, isDuplicateIndexPath, "m1 android imac win ios", path)
SCREWYOU3_HOOK(bool isDuplicateInVisibleCellArray(CCIndexPath* path))
SCREWYOU3_HOOK_IMPL(TableView, isDuplicateInVisibleCellArray, "m1 android imac win ios", path)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool removeIndexPathFromPathAddedArray(CCIndexPath& path))
SCREWYOU3_HOOK_IMPL(TableView, removeIndexPathFromPathAddedArray, " m1 android imac ios", path)
#endif
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

bool TeleportPortalObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TeleportPortalObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(TeleportPortalObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK(int addToGroup(int id))
SCREWYOU3_HOOK_IMPL(TeleportPortalObject, addToGroup, "m1 android imac win ios", id)
SCREWYOU3_HOOK(float getTeleportXOff(cocos2d::CCNode* parent))
SCREWYOU3_HOOK_IMPL(TeleportPortalObject, getTeleportXOff, "m1 android imac win ios", parent)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame, bool trigger))
SCREWYOU3_HOOK_IMPL(TeleportPortalObject, init, " m1 android imac", frame, trigger)
#endif
SCREWYOU3_HOOK_END("TeleportPortalObject::getSaveString")

#include <Geode/modify/TextAlertPopup.hpp>

bool TextAlertPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TextAlertPopup)
SCREWYOU3_HOOK(bool init(gd::string text, float delay, float scale, int opacity, gd::string font))
SCREWYOU3_HOOK_IMPL(TextAlertPopup, init, "m1 android imac win ios", text, delay, scale, opacity, font)
SCREWYOU3_HOOK_END("TextAlertPopup::init")

#include <Geode/modify/TextArea.hpp>

float TextArea_fadeIn_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

float TextArea_fadeInCharacters_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool TextArea_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TextArea)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(float fadeIn(float duration, bool unused))
SCREWYOU3_HOOK_IMPL(TextArea, fadeIn, " m1 android imac", duration, unused)
#endif
SCREWYOU3_HOOK(float fadeInCharacters(float duration, float charDuration, bool fadeOut, TextFadeInStyle style))
SCREWYOU3_HOOK_IMPL(TextArea, fadeInCharacters, "m1 android imac win ios", duration, charDuration, fadeOut, style)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(gd::string str, char const* font, float scale, float width, cocos2d::CCPoint anchor, float lineHeight, bool disableColor))
SCREWYOU3_HOOK_IMPL(TextArea, init, " m1 android imac ios", str, font, scale, width, anchor, lineHeight, disableColor)
#endif
SCREWYOU3_HOOK_END("TextArea::fadeIn")

#include <Geode/modify/TextGameObject.hpp>

gd::string TextGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

int TextGameObject_getTextKerning_override() {
	return modUtils::chooseRandomNum(Mod::get()->getSettingValue<double>("gibberish-data-numerical-min"), Mod::get()->getSettingValue<double>("gibberish-data-numerical-max"));
}

bool TextGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TextGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(TextGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK(int getTextKerning())
SCREWYOU3_HOOK_IMPL(TextGameObject, getTextKerning, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCTexture2D* texture))
SCREWYOU3_HOOK_IMPL(TextGameObject, init, " m1 android imac", texture)
#endif
SCREWYOU3_HOOK_END("TextGameObject::getSaveString")

#include <Geode/modify/TextStyleSection.hpp>

bool TextStyleSection_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TextStyleSection)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int start, int end, TextStyleType type))
SCREWYOU3_HOOK_IMPL(TextStyleSection, init, " m1 android imac", start, end, type)
#endif
SCREWYOU3_HOOK_END("TextStyleSection::init")

#include <Geode/modify/TimerTriggerGameObject.hpp>

gd::string TimerTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool TimerTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TimerTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(TimerTriggerGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(TimerTriggerGameObject, init, " m1 android imac", frame)
#endif
SCREWYOU3_HOOK_END("TimerTriggerGameObject::getSaveString")

#include <Geode/modify/TopArtistsLayer.hpp>

bool TopArtistsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool TopArtistsLayer_isCorrect_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TopArtistsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(TopArtistsLayer, init, "m1 android imac win ios", )
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isCorrect(char const* key))
SCREWYOU3_HOOK_IMPL(TopArtistsLayer, isCorrect, " m1 android imac", key)
#endif
SCREWYOU3_HOOK_END("TopArtistsLayer::init")

#include <Geode/modify/TOSPopup.hpp>

bool TOSPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TOSPopup)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(TOSPopup, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("TOSPopup::init")

#include <Geode/modify/TransformTriggerGameObject.hpp>

gd::string TransformTriggerGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool TransformTriggerGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TransformTriggerGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(TransformTriggerGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(TransformTriggerGameObject, init, " m1 android imac", frame)
#endif
SCREWYOU3_HOOK_END("TransformTriggerGameObject::getSaveString")

#include <Geode/modify/TriggerControlGameObject.hpp>

gd::string TriggerControlGameObject_getSaveString_override() {
	return modUtils::getRandomCharSequence(Mod::get()->getSettingValue<int64_t>("gibberish-data-string-lenght"));
}

bool TriggerControlGameObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TriggerControlGameObject)
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(TriggerControlGameObject, getSaveString, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(char const* frame))
SCREWYOU3_HOOK_IMPL(TriggerControlGameObject, init, " m1 android imac ios", frame)
#endif
SCREWYOU3_HOOK_END("TriggerControlGameObject::getSaveString")

#include <Geode/modify/TutorialLayer.hpp>

bool TutorialLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TutorialLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(TutorialLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("TutorialLayer::init")

#include <Geode/modify/TutorialPopup.hpp>

bool TutorialPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(TutorialPopup)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(gd::string frame))
SCREWYOU3_HOOK_IMPL(TutorialPopup, init, "m1 imac android", frame)
#endif
SCREWYOU3_HOOK_END("TutorialPopup::init")

#include <Geode/modify/UILayer.hpp>

bool UILayer_ccTouchBegan_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool UILayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool UILayer_isJumpButtonPressed_override() {
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
SCREWYOU3_HOOK_IMPL(UILayer, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK(bool init(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(UILayer, init, "m1 android imac win ios", layer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isJumpButtonPressed())
SCREWYOU3_HOOK_IMPL(UILayer, isJumpButtonPressed, " m1 android imac ios", )
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool isJumpButtonPressed(bool player1))
SCREWYOU3_HOOK_IMPL(UILayer, isJumpButtonPressed, " m1 android imac", player1)
#endif
SCREWYOU3_HOOK(bool processUINodesTouch(GJUITouchEvent event, cocos2d::CCTouch* touch))
SCREWYOU3_HOOK_IMPL(UILayer, processUINodesTouch, "m1 android imac win ios", event, touch)
SCREWYOU3_HOOK(bool processUINodeTouch(GJUITouchEvent event, int touchID, cocos2d::CCPoint position, GJUINode* node, double timestamp))
SCREWYOU3_HOOK_IMPL(UILayer, processUINodeTouch, "m1 android imac win ios", event, touchID, position, node, timestamp)
SCREWYOU3_HOOK_END("UILayer::ccTouchBegan")

#include <Geode/modify/UIObjectSettingsPopup.hpp>

bool UIObjectSettingsPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UIObjectSettingsPopup)
SCREWYOU3_HOOK(bool init(UISettingsGameObject* object, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(UIObjectSettingsPopup, init, "m1 android imac win ios", object, objects)
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
SCREWYOU3_HOOK_IMPL(UIOptionsLayer, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK(float getValue(int tag))
SCREWYOU3_HOOK_IMPL(UIOptionsLayer, getValue, "m1 android imac win ios", tag)
SCREWYOU3_HOOK(bool init(bool dual))
SCREWYOU3_HOOK_IMPL(UIOptionsLayer, init, "m1 android imac win ios", dual)
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
SCREWYOU3_HOOK_IMPL(UIPOptionsLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event))
SCREWYOU3_HOOK_IMPL(UIPOptionsLayer, ccTouchBegan, "m1 android imac win ios", touch, event)
SCREWYOU3_HOOK(float getValue(int tag))
SCREWYOU3_HOOK_IMPL(UIPOptionsLayer, getValue, "m1 android imac win ios", tag)
SCREWYOU3_HOOK_END("UIPOptionsLayer::init")

#include <Geode/modify/UISaveLoadLayer.hpp>

bool UISaveLoadLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UISaveLoadLayer)
SCREWYOU3_HOOK(bool init(UIOptionsLayer* layer))
SCREWYOU3_HOOK_IMPL(UISaveLoadLayer, init, "m1 android imac win ios", layer)
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
SCREWYOU3_HOOK_IMPL(UISettingsGameObject, init, "m1 android imac win ios", )
SCREWYOU3_HOOK(gd::string getSaveString(GJBaseGameLayer* layer))
SCREWYOU3_HOOK_IMPL(UISettingsGameObject, getSaveString, "m1 android imac win ios", layer)
SCREWYOU3_HOOK_END("UISettingsGameObject::init")

#include <Geode/modify/UndoObject.hpp>

bool UndoObject_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}

bool UndoObject_initWithTransformObjects_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UndoObject)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(GameObject* object, UndoCommand command))
SCREWYOU3_HOOK_IMPL(UndoObject, init, " m1 android imac", object, command)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(cocos2d::CCArray* array, UndoCommand command))
SCREWYOU3_HOOK_IMPL(UndoObject, init, " m1 android imac ios", array, command)
#endif
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool initWithTransformObjects(cocos2d::CCArray* objects, UndoCommand command))
SCREWYOU3_HOOK_IMPL(UndoObject, initWithTransformObjects, " m1 android imac ios", objects, command)
#endif
SCREWYOU3_HOOK_END("UndoObject::init")

#include <Geode/modify/UpdateAccountSettingsPopup.hpp>

bool UpdateAccountSettingsPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UpdateAccountSettingsPopup)
SCREWYOU3_HOOK(bool init(GJAccountSettingsLayer* settingsLayer, int messageStatus, int friendStatus, int commentStatus, gd::string youtubeURL, gd::string twitterURL, gd::string twitchURL, gd::string instagramURL, gd::string tiktokURL, gd::string discordUsername, gd::string customString))
SCREWYOU3_HOOK_IMPL(UpdateAccountSettingsPopup, init, "m1 android imac win ios", settingsLayer, messageStatus, friendStatus, commentStatus, youtubeURL, twitterURL, twitchURL, instagramURL, tiktokURL, discordUsername, customString)
SCREWYOU3_HOOK_END("UpdateAccountSettingsPopup::init")

#include <Geode/modify/UploadActionPopup.hpp>

bool UploadActionPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UploadActionPopup)
SCREWYOU3_HOOK(bool init(UploadPopupDelegate* delegate, gd::string str))
SCREWYOU3_HOOK_IMPL(UploadActionPopup, init, "m1 android imac win ios", delegate, str)
SCREWYOU3_HOOK_END("UploadActionPopup::init")

#include <Geode/modify/UploadListPopup.hpp>

bool UploadListPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UploadListPopup)
SCREWYOU3_HOOK(bool init(GJLevelList* list))
SCREWYOU3_HOOK_IMPL(UploadListPopup, init, "m1 android imac win ios", list)
SCREWYOU3_HOOK_END("UploadListPopup::init")

#include <Geode/modify/UploadPopup.hpp>

bool UploadPopup_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(UploadPopup)
SCREWYOU3_HOOK(bool init(GJGameLevel* level))
SCREWYOU3_HOOK_IMPL(UploadPopup, init, "m1 android imac win ios", level)
SCREWYOU3_HOOK_END("UploadPopup::init")

#include <Geode/modify/URLCell.hpp>

bool URLCell_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(URLCell)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(URLCell, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("URLCell::init")

#include <Geode/modify/URLViewLayer.hpp>

bool URLViewLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(URLViewLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(gd::string title, cocos2d::CCArray* objects))
SCREWYOU3_HOOK_IMPL(URLViewLayer, init, " m1 android imac ios", title, objects)
#endif
SCREWYOU3_HOOK_END("URLViewLayer::init")

#include <Geode/modify/VideoOptionsLayer.hpp>

bool VideoOptionsLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(VideoOptionsLayer)
SCREWYOU3_HOOK(bool init())
SCREWYOU3_HOOK_IMPL(VideoOptionsLayer, init, "m1 android imac win ios", )
SCREWYOU3_HOOK_END("VideoOptionsLayer::init")

#include <Geode/modify/WorldLevelPage.hpp>

bool WorldLevelPage_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(WorldLevelPage)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(GJGameLevel* level, GJWorldNode* node))
SCREWYOU3_HOOK_IMPL(WorldLevelPage, init, "m1 imac android", level, node)
#endif
SCREWYOU3_HOOK_END("WorldLevelPage::init")

#include <Geode/modify/WorldSelectLayer.hpp>

bool WorldSelectLayer_init_override() {
	return modUtils::chooseRandomNum(0, 1);
}


SCREWYOU3_HOOK_BEGIN(WorldSelectLayer)
#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
SCREWYOU3_HOOK(bool init(int page))
SCREWYOU3_HOOK_IMPL(WorldSelectLayer, init, "m1 imac android", page)
#endif
SCREWYOU3_HOOK_END("WorldSelectLayer::init")

