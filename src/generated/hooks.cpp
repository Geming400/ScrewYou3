// Generated using 'generate.py'
// Can't wait for someone to destroy `PlayerObject`'s as their first destroyed init :3
#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include "../ScrewYou3Manager.hpp"

using namespace geode::prelude;

// Cursed macros but whatever, this isn't supposed to be the most readable thing after all

#define SCREWYOU2_MENULAYER_CUSTOM_INIT(className, ...) { \
        if (ScrewYou3Manager::get()->isKilled(CLASS_NAME) && Mod::get()->getSettingValue<bool>("enabled")) return true; \
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

#define SCREWYOU3_HOOK(className, ...) \
class $modify(Screwd##className, className) { \
    bool init(__VA_ARGS__) // `SCREWYOU3_HOOK_INIT()` macro goes here

#define SCREWYOU3_HOOK_INIT(className, ...) { \
        if (ScrewYou3Manager::get()->isKilled(CLASS_NAME) && Mod::get()->getSettingValue<bool>("enabled")) return true;\
        if (!className::init(__VA_ARGS__)) return false; \
        return true; \
    } \
};

// Hooking classes
// You might notice that the 'GEODE_IS_DEKSTOP' and 'GEODE_IS_MOBILE' macros aren't used, this is just because
// this file was automatically generated, so I just didn't want to bother with that, not like it was going
// to change a thing either way

#include <Geode/modify/AccountLoginLayer.hpp>
SCREWYOU3_HOOK(AccountLoginLayer, gd::string p0)
SCREWYOU3_HOOK_INIT(AccountLoginLayer, p0)

#include <Geode/modify/AccountRegisterLayer.hpp>
SCREWYOU3_HOOK(AccountRegisterLayer, )
SCREWYOU3_HOOK_INIT(AccountRegisterLayer)

#include <Geode/modify/AchievementBar.hpp>
SCREWYOU3_HOOK(AchievementBar, char const* title, char const* desc, char const* icon, bool quest)
SCREWYOU3_HOOK_INIT(AchievementBar, title, desc, icon, quest)

#include <Geode/modify/AchievementManager.hpp>
SCREWYOU3_HOOK(AchievementManager, )
SCREWYOU3_HOOK_INIT(AchievementManager)

#include <Geode/modify/AchievementNotifier.hpp>
SCREWYOU3_HOOK(AchievementNotifier, )
SCREWYOU3_HOOK_INIT(AchievementNotifier)

#include <Geode/modify/AnimatedGameObject.hpp>
SCREWYOU3_HOOK(AnimatedGameObject, int p0)
SCREWYOU3_HOOK_INIT(AnimatedGameObject, p0)

#include <Geode/modify/ArtistCell.hpp>
SCREWYOU3_HOOK(ArtistCell, )
SCREWYOU3_HOOK_INIT(ArtistCell)

#include <Geode/modify/AudioAssetsBrowser.hpp>
SCREWYOU3_HOOK(AudioAssetsBrowser, gd::vector<int>& songIds, gd::vector<int>& sfxIds)
SCREWYOU3_HOOK_INIT(AudioAssetsBrowser, songIds, sfxIds)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID
#include <Geode/modify/AudioEffectsLayer.hpp>
SCREWYOU3_HOOK(AudioEffectsLayer, gd::string p0)
SCREWYOU3_HOOK_INIT(AudioEffectsLayer, p0)
#endif

#include <Geode/modify/AudioLineGuideGameObject.hpp>
SCREWYOU3_HOOK(AudioLineGuideGameObject, )
SCREWYOU3_HOOK_INIT(AudioLineGuideGameObject)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/BonusDropdown.hpp>
SCREWYOU3_HOOK(BonusDropdown, gd::string p0, int p1)
SCREWYOU3_HOOK_INIT(BonusDropdown, p0, p1)
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/BoomListLayer.hpp>
SCREWYOU3_HOOK(BoomListLayer, BoomListView* p0, char const* p1)
SCREWYOU3_HOOK_INIT(BoomListLayer, p0, p1)
#endif

#include <Geode/modify/BoomListView.hpp>
SCREWYOU3_HOOK(BoomListView, cocos2d::CCArray* p0, TableViewCellDelegate* p1, float p2, float p3, int p4, BoomListType p5, float p6)
SCREWYOU3_HOOK_INIT(BoomListView, p0, p1, p2, p3, p4, p5, p6)

#include <Geode/modify/BoomScrollLayer.hpp>
SCREWYOU3_HOOK(BoomScrollLayer, cocos2d::CCArray* p0, int p1, bool p2, cocos2d::CCArray* p3, DynamicScrollDelegate* p4)
SCREWYOU3_HOOK_INIT(BoomScrollLayer, p0, p1, p2, p3, p4)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/BrowseSmartKeyLayer.hpp>
SCREWYOU3_HOOK(BrowseSmartKeyLayer, GJSmartTemplate* p0, gd::string p1)
SCREWYOU3_HOOK_INIT(BrowseSmartKeyLayer, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/BrowseSmartTemplateLayer.hpp>
SCREWYOU3_HOOK(BrowseSmartTemplateLayer, GJSmartTemplate* p0, SmartBrowseFilter p1)
SCREWYOU3_HOOK_INIT(BrowseSmartTemplateLayer, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/ButtonSprite.hpp>
SCREWYOU3_HOOK(ButtonSprite, cocos2d::CCSprite* topSprite, int width, int unused, float height, float scale, bool absolute, char const* bgSprite, bool noScaleSpriteForBG)
SCREWYOU3_HOOK_INIT(ButtonSprite, topSprite, width, unused, height, scale, absolute, bgSprite, noScaleSpriteForBG)
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/CCAlertCircle.hpp>
SCREWYOU3_HOOK(CCAlertCircle, )
SCREWYOU3_HOOK_INIT(CCAlertCircle)
#endif

#include <Geode/modify/CCBlockLayer.hpp>
SCREWYOU3_HOOK(CCBlockLayer, )
SCREWYOU3_HOOK_INIT(CCBlockLayer)

#include <Geode/modify/CCCircleWave.hpp>
SCREWYOU3_HOOK(CCCircleWave, float startRadius, float endRadius, float duration, bool fadeIn, bool easeOut)
SCREWYOU3_HOOK_INIT(CCCircleWave, startRadius, endRadius, duration, fadeIn, easeOut)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/CCCountdown.hpp>
SCREWYOU3_HOOK(CCCountdown, )
SCREWYOU3_HOOK_INIT(CCCountdown)
#endif

#include <Geode/modify/CCMenuItemSpriteExtra.hpp>
SCREWYOU3_HOOK(CCMenuItemSpriteExtra, cocos2d::CCNode* sprite, cocos2d::CCNode* disabledSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback)
SCREWYOU3_HOOK_INIT(CCMenuItemSpriteExtra, sprite, disabledSprite, target, callback)

#include <Geode/modify/CCNodeContainer.hpp>
SCREWYOU3_HOOK(CCNodeContainer, )
SCREWYOU3_HOOK_INIT(CCNodeContainer)

#include <Geode/modify/CCTextInputNode.hpp>
SCREWYOU3_HOOK(CCTextInputNode, float p0, float p1, char const* p2, char const* p3, int p4, char const* p5)
SCREWYOU3_HOOK_INIT(CCTextInputNode, p0, p1, p2, p3, p4, p5)

#include <Geode/modify/ChallengeNode.hpp>
SCREWYOU3_HOOK(ChallengeNode, GJChallengeItem* challengeItem, ChallengesPage* challengesPage, bool isNew)
SCREWYOU3_HOOK_INIT(ChallengeNode, challengeItem, challengesPage, isNew)

#include <Geode/modify/ChallengesPage.hpp>
SCREWYOU3_HOOK(ChallengesPage, )
SCREWYOU3_HOOK_INIT(ChallengesPage)

#include <Geode/modify/CharacterColorPage.hpp>
SCREWYOU3_HOOK(CharacterColorPage, )
SCREWYOU3_HOOK_INIT(CharacterColorPage)

#include <Geode/modify/CheckpointGameObject.hpp>
SCREWYOU3_HOOK(CheckpointGameObject, )
SCREWYOU3_HOOK_INIT(CheckpointGameObject)

#include <Geode/modify/CheckpointObject.hpp>
SCREWYOU3_HOOK(CheckpointObject, )
SCREWYOU3_HOOK_INIT(CheckpointObject)

#include <Geode/modify/CollisionBlockPopup.hpp>
SCREWYOU3_HOOK(CollisionBlockPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(CollisionBlockPopup, p0, p1)

#include <Geode/modify/ColorActionSprite.hpp>
SCREWYOU3_HOOK(ColorActionSprite, )
SCREWYOU3_HOOK_INIT(ColorActionSprite)

#include <Geode/modify/ColorChannelSprite.hpp>
SCREWYOU3_HOOK(ColorChannelSprite, )
SCREWYOU3_HOOK_INIT(ColorChannelSprite)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/ColorSelectLiveOverlay.hpp>
SCREWYOU3_HOOK(ColorSelectLiveOverlay, ColorAction* p0, ColorAction* p1, EffectGameObject* p2)
SCREWYOU3_HOOK_INIT(ColorSelectLiveOverlay, p0, p1, p2)
#endif

#include <Geode/modify/ColorSelectPopup.hpp>
SCREWYOU3_HOOK(ColorSelectPopup, EffectGameObject* p0, cocos2d::CCArray* p1, ColorAction* p2)
SCREWYOU3_HOOK_INIT(ColorSelectPopup, p0, p1, p2)

#include <Geode/modify/CommentCell.hpp>
SCREWYOU3_HOOK(CommentCell, )
SCREWYOU3_HOOK_INIT(CommentCell)

#include <Geode/modify/CommunityCreditsPage.hpp>
SCREWYOU3_HOOK(CommunityCreditsPage, )
SCREWYOU3_HOOK_INIT(CommunityCreditsPage)

#include <Geode/modify/ConfigureHSVWidget.hpp>
SCREWYOU3_HOOK(ConfigureHSVWidget, cocos2d::ccHSVValue hsv, bool unused, bool addInputs)
SCREWYOU3_HOOK_INIT(ConfigureHSVWidget, hsv, unused, addInputs)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/ConfigureValuePopup.hpp>
SCREWYOU3_HOOK(ConfigureValuePopup, ConfigureValuePopupDelegate* p0, float p1, float p2, float p3, gd::string p4, gd::string p5)
SCREWYOU3_HOOK_INIT(ConfigureValuePopup, p0, p1, p2, p3, p4, p5)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/CreateGuidelinesLayer.hpp>
SCREWYOU3_HOOK(CreateGuidelinesLayer, CustomSongDelegate* p0, AudioGuidelinesType p1)
SCREWYOU3_HOOK_INIT(CreateGuidelinesLayer, p0, p1)
#endif

#include <Geode/modify/CreateParticlePopup.hpp>
SCREWYOU3_HOOK(CreateParticlePopup, ParticleGameObject* p0, cocos2d::CCArray* p1, gd::string p2)
SCREWYOU3_HOOK_INIT(CreateParticlePopup, p0, p1, p2)

#include <Geode/modify/CreatorLayer.hpp>
SCREWYOU3_HOOK(CreatorLayer, )
SCREWYOU3_HOOK_INIT(CreatorLayer)

#include <Geode/modify/CurrencyRewardLayer.hpp>
SCREWYOU3_HOOK(CurrencyRewardLayer, int orbs, int stars, int moons, int diamonds, CurrencySpriteType demonKey, int keyCount, CurrencySpriteType shardType, int shardsCount, cocos2d::CCPoint position, CurrencyRewardType rewardType, float p10, float time)
SCREWYOU3_HOOK_INIT(CurrencyRewardLayer, orbs, stars, moons, diamonds, demonKey, keyCount, shardType, shardsCount, position, rewardType, p10, time)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/CurrencySprite.hpp>
SCREWYOU3_HOOK(CurrencySprite, CurrencySpriteType p0, bool p1)
SCREWYOU3_HOOK_INIT(CurrencySprite, p0, p1)
#endif

#include <Geode/modify/CustomizeObjectLayer.hpp>
SCREWYOU3_HOOK(CustomizeObjectLayer, GameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(CustomizeObjectLayer, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/CustomizeObjectSettingsPopup.hpp>
SCREWYOU3_HOOK(CustomizeObjectSettingsPopup, GameObject* p0, cocos2d::CCArray* p1, CustomizeObjectLayer* p2)
SCREWYOU3_HOOK_INIT(CustomizeObjectSettingsPopup, p0, p1, p2)
#endif

#include <Geode/modify/CustomSFXCell.hpp>
SCREWYOU3_HOOK(CustomSFXCell, )
SCREWYOU3_HOOK_INIT(CustomSFXCell)

#include <Geode/modify/CustomSFXWidget.hpp>
SCREWYOU3_HOOK(CustomSFXWidget, SFXInfoObject* p0, CustomSFXDelegate* p1, bool p2, bool p3, bool p4, bool p5, bool p6)
SCREWYOU3_HOOK_INIT(CustomSFXWidget, p0, p1, p2, p3, p4, p5, p6)

#include <Geode/modify/CustomSongCell.hpp>
SCREWYOU3_HOOK(CustomSongCell, )
SCREWYOU3_HOOK_INIT(CustomSongCell)

#include <Geode/modify/CustomSongLayer.hpp>
SCREWYOU3_HOOK(CustomSongLayer, CustomSongDelegate* p0)
SCREWYOU3_HOOK_INIT(CustomSongLayer, p0)

#include <Geode/modify/CustomSongWidget.hpp>
SCREWYOU3_HOOK(CustomSongWidget, SongInfoObject* songInfo, CustomSongDelegate* songDelegate, bool showSongSelect, bool showPlayMusic, bool showDownload, bool isRobtopSong, bool unkBool, bool isMusicLibrary, int unk)
SCREWYOU3_HOOK_INIT(CustomSongWidget, songInfo, songDelegate, showSongSelect, showPlayMusic, showDownload, isRobtopSong, unkBool, isMusicLibrary, unk)

#include <Geode/modify/DailyLevelNode.hpp>
SCREWYOU3_HOOK(DailyLevelNode, GJGameLevel* p0, DailyLevelPage* p1, bool p2)
SCREWYOU3_HOOK_INIT(DailyLevelNode, p0, p1, p2)

#include <Geode/modify/DailyLevelPage.hpp>
SCREWYOU3_HOOK(DailyLevelPage, GJTimedLevelType p0)
SCREWYOU3_HOOK_INIT(DailyLevelPage, p0)

#include <Geode/modify/DemonFilterSelectLayer.hpp>
SCREWYOU3_HOOK(DemonFilterSelectLayer, )
SCREWYOU3_HOOK_INIT(DemonFilterSelectLayer)

#include <Geode/modify/DemonInfoPopup.hpp>
SCREWYOU3_HOOK(DemonInfoPopup, int easyClassic, int mediumClassic, int hardClassic, int insaneClassic, int extremeClassic, int easyPlatformer, int mediumPlatformer, int hardPlatformer, int insanePlatformer, int extremePlatformer, int weekly, int gauntlet)
SCREWYOU3_HOOK_INIT(DemonInfoPopup, easyClassic, mediumClassic, hardClassic, insaneClassic, extremeClassic, easyPlatformer, mediumPlatformer, hardPlatformer, insanePlatformer, extremePlatformer, weekly, gauntlet)

#include <Geode/modify/DialogLayer.hpp>
SCREWYOU3_HOOK(DialogLayer, DialogObject* p0, cocos2d::CCArray* p1, int p2)
SCREWYOU3_HOOK_INIT(DialogLayer, p0, p1, p2)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
#include <Geode/modify/DrawGridLayer.hpp>
SCREWYOU3_HOOK(DrawGridLayer, cocos2d::CCNode* p0, LevelEditorLayer* p1)
SCREWYOU3_HOOK_INIT(DrawGridLayer, p0, p1)
#endif

#include <Geode/modify/DungeonBarsSprite.hpp>
SCREWYOU3_HOOK(DungeonBarsSprite, )
SCREWYOU3_HOOK_INIT(DungeonBarsSprite)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/EditButtonBar.hpp>
SCREWYOU3_HOOK(EditButtonBar, cocos2d::CCArray* objects, cocos2d::CCPoint position, int tab, bool hasCreateItems, int columns, int rows)
SCREWYOU3_HOOK_INIT(EditButtonBar, objects, position, tab, hasCreateItems, columns, rows)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/EditGameObjectPopup.hpp>
SCREWYOU3_HOOK(EditGameObjectPopup, EffectGameObject* p0, cocos2d::CCArray* p1, bool p2)
SCREWYOU3_HOOK_INIT(EditGameObjectPopup, p0, p1, p2)
#endif

#include <Geode/modify/EditLevelLayer.hpp>
SCREWYOU3_HOOK(EditLevelLayer, GJGameLevel* p0)
SCREWYOU3_HOOK_INIT(EditLevelLayer, p0)

#include <Geode/modify/EditorOptionsLayer.hpp>
SCREWYOU3_HOOK(EditorOptionsLayer, )
SCREWYOU3_HOOK_INIT(EditorOptionsLayer)

#include <Geode/modify/EditorPauseLayer.hpp>
SCREWYOU3_HOOK(EditorPauseLayer, LevelEditorLayer* p0)
SCREWYOU3_HOOK_INIT(EditorPauseLayer, p0)

#include <Geode/modify/EditorUI.hpp>
SCREWYOU3_HOOK(EditorUI, LevelEditorLayer* editorLayer)
SCREWYOU3_HOOK_INIT(EditorUI, editorLayer)

#include <Geode/modify/EditTriggersPopup.hpp>
SCREWYOU3_HOOK(EditTriggersPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(EditTriggersPopup, p0, p1)

#include <Geode/modify/EffectGameObject.hpp>
SCREWYOU3_HOOK(EffectGameObject, char const* p0)
SCREWYOU3_HOOK_INIT(EffectGameObject, p0)

#include <Geode/modify/EndPortalObject.hpp>
SCREWYOU3_HOOK(EndPortalObject, )
SCREWYOU3_HOOK_INIT(EndPortalObject)

#include <Geode/modify/EndTriggerGameObject.hpp>
SCREWYOU3_HOOK(EndTriggerGameObject, )
SCREWYOU3_HOOK_INIT(EndTriggerGameObject)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID
#include <Geode/modify/EnhancedGameObject.hpp>
SCREWYOU3_HOOK(EnhancedGameObject, char const* p0)
SCREWYOU3_HOOK_INIT(EnhancedGameObject, p0)
#endif

#include <Geode/modify/EventLinkTrigger.hpp>
SCREWYOU3_HOOK(EventLinkTrigger, )
SCREWYOU3_HOOK_INIT(EventLinkTrigger)

#include <Geode/modify/ExplodeItemSprite.hpp>
SCREWYOU3_HOOK(ExplodeItemSprite, )
SCREWYOU3_HOOK_INIT(ExplodeItemSprite)

#include <Geode/modify/ExtendedLayer.hpp>
SCREWYOU3_HOOK(ExtendedLayer, )
SCREWYOU3_HOOK_INIT(ExtendedLayer)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/FileSaveManager.hpp>
SCREWYOU3_HOOK(FileSaveManager, )
SCREWYOU3_HOOK_INIT(FileSaveManager)
#endif

#include <Geode/modify/FindObjectPopup.hpp>
SCREWYOU3_HOOK(FindObjectPopup, )
SCREWYOU3_HOOK_INIT(FindObjectPopup)

#include <Geode/modify/FLAlertLayer.hpp>
SCREWYOU3_HOOK(FLAlertLayer, int p0)
SCREWYOU3_HOOK_INIT(FLAlertLayer, p0)

#include <Geode/modify/FMODLevelVisualizer.hpp>
SCREWYOU3_HOOK(FMODLevelVisualizer, )
SCREWYOU3_HOOK_INIT(FMODLevelVisualizer)

#include <Geode/modify/FollowRewardPage.hpp>
SCREWYOU3_HOOK(FollowRewardPage, )
SCREWYOU3_HOOK_INIT(FollowRewardPage)

#include <Geode/modify/FRequestProfilePage.hpp>
SCREWYOU3_HOOK(FRequestProfilePage, bool p0)
SCREWYOU3_HOOK_INIT(FRequestProfilePage, p0)

#include <Geode/modify/FriendRequestPopup.hpp>
SCREWYOU3_HOOK(FriendRequestPopup, GJFriendRequest* p0)
SCREWYOU3_HOOK_INIT(FriendRequestPopup, p0)

#include <Geode/modify/FriendsProfilePage.hpp>
SCREWYOU3_HOOK(FriendsProfilePage, UserListType type)
SCREWYOU3_HOOK_INIT(FriendsProfilePage, type)

#include <Geode/modify/GameCell.hpp>
SCREWYOU3_HOOK(GameCell, )
SCREWYOU3_HOOK_INIT(GameCell)

#include <Geode/modify/GameLevelManager.hpp>
SCREWYOU3_HOOK(GameLevelManager, )
SCREWYOU3_HOOK_INIT(GameLevelManager)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GameLevelOptionsLayer.hpp>
SCREWYOU3_HOOK(GameLevelOptionsLayer, GJGameLevel* p0)
SCREWYOU3_HOOK_INIT(GameLevelOptionsLayer, p0)
#endif

#include <Geode/modify/GameManager.hpp>
SCREWYOU3_HOOK(GameManager, )
SCREWYOU3_HOOK_INIT(GameManager)

#include <Geode/modify/GameStatsManager.hpp>
SCREWYOU3_HOOK(GameStatsManager, )
SCREWYOU3_HOOK_INIT(GameStatsManager)

#include <Geode/modify/GauntletLayer.hpp>
SCREWYOU3_HOOK(GauntletLayer, GauntletType p0)
SCREWYOU3_HOOK_INIT(GauntletLayer, p0)

#include <Geode/modify/GauntletNode.hpp>
SCREWYOU3_HOOK(GauntletNode, GJMapPack* p0)
SCREWYOU3_HOOK_INIT(GauntletNode, p0)

#include <Geode/modify/GauntletSelectLayer.hpp>
SCREWYOU3_HOOK(GauntletSelectLayer, int p0)
SCREWYOU3_HOOK_INIT(GauntletSelectLayer, p0)

#include <Geode/modify/GhostTrailEffect.hpp>
SCREWYOU3_HOOK(GhostTrailEffect, )
SCREWYOU3_HOOK_INIT(GhostTrailEffect)

#include <Geode/modify/GJAccountManager.hpp>
SCREWYOU3_HOOK(GJAccountManager, )
SCREWYOU3_HOOK_INIT(GJAccountManager)

#include <Geode/modify/GJAccountSettingsLayer.hpp>
SCREWYOU3_HOOK(GJAccountSettingsLayer, int p0)
SCREWYOU3_HOOK_INIT(GJAccountSettingsLayer, p0)

#include <Geode/modify/GJActionManager.hpp>
SCREWYOU3_HOOK(GJActionManager, )
SCREWYOU3_HOOK_INIT(GJActionManager)

#include <Geode/modify/GJBaseGameLayer.hpp>
SCREWYOU3_HOOK(GJBaseGameLayer, )
SCREWYOU3_HOOK_INIT(GJBaseGameLayer)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJBigSprite.hpp>
SCREWYOU3_HOOK(GJBigSprite, )
SCREWYOU3_HOOK_INIT(GJBigSprite)
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJBigSpriteNode.hpp>
SCREWYOU3_HOOK(GJBigSpriteNode, )
SCREWYOU3_HOOK_INIT(GJBigSpriteNode)
#endif

#include <Geode/modify/GJColorSetupLayer.hpp>
SCREWYOU3_HOOK(GJColorSetupLayer, LevelSettingsObject* p0)
SCREWYOU3_HOOK_INIT(GJColorSetupLayer, p0)

#include <Geode/modify/GJComment.hpp>
SCREWYOU3_HOOK(GJComment, )
SCREWYOU3_HOOK_INIT(GJComment)

#include <Geode/modify/GJCommentListLayer.hpp>
SCREWYOU3_HOOK(GJCommentListLayer, BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, bool blueBorder)
SCREWYOU3_HOOK_INIT(GJCommentListLayer, listView, title, color, width, height, blueBorder)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJDifficultySprite.hpp>
SCREWYOU3_HOOK(GJDifficultySprite, int p0, GJDifficultyName p1)
SCREWYOU3_HOOK_INIT(GJDifficultySprite, p0, p1)
#endif

#include <Geode/modify/GJDropDownLayer.hpp>
SCREWYOU3_HOOK(GJDropDownLayer, char const* p0, float p1, bool p2)
SCREWYOU3_HOOK_INIT(GJDropDownLayer, p0, p1, p2)

#include <Geode/modify/GJEffectManager.hpp>
SCREWYOU3_HOOK(GJEffectManager, )
SCREWYOU3_HOOK_INIT(GJEffectManager)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJFlyGroundLayer.hpp>
SCREWYOU3_HOOK(GJFlyGroundLayer, )
SCREWYOU3_HOOK_INIT(GJFlyGroundLayer)
#endif

#include <Geode/modify/GJFollowCommandLayer.hpp>
SCREWYOU3_HOOK(GJFollowCommandLayer, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(GJFollowCommandLayer, p0, p1)

#include <Geode/modify/GJFriendRequest.hpp>
SCREWYOU3_HOOK(GJFriendRequest, )
SCREWYOU3_HOOK_INIT(GJFriendRequest)

#include <Geode/modify/GJGameLevel.hpp>
SCREWYOU3_HOOK(GJGameLevel, )
SCREWYOU3_HOOK_INIT(GJGameLevel)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
#include <Geode/modify/GJGameLoadingLayer.hpp>
SCREWYOU3_HOOK(GJGameLoadingLayer, GJGameLevel* level, bool editor)
SCREWYOU3_HOOK_INIT(GJGameLoadingLayer, level, editor)
#endif

#include <Geode/modify/GJGarageLayer.hpp>
SCREWYOU3_HOOK(GJGarageLayer, )
SCREWYOU3_HOOK_INIT(GJGarageLayer)

#include <Geode/modify/GJGradientLayer.hpp>
SCREWYOU3_HOOK(GJGradientLayer, )
SCREWYOU3_HOOK_INIT(GJGradientLayer)

#include <Geode/modify/GJGroundLayer.hpp>
SCREWYOU3_HOOK(GJGroundLayer, int p0, int p1)
SCREWYOU3_HOOK_INIT(GJGroundLayer, p0, p1)

#include <Geode/modify/GJItemIcon.hpp>
SCREWYOU3_HOOK(GJItemIcon, UnlockType p0, int p1, cocos2d::ccColor3B p2, cocos2d::ccColor3B p3, bool p4, bool p5, bool p6, cocos2d::ccColor3B p7)
SCREWYOU3_HOOK_INIT(GJItemIcon, p0, p1, p2, p3, p4, p5, p6, p7)

#include <Geode/modify/GJLevelList.hpp>
SCREWYOU3_HOOK(GJLevelList, )
SCREWYOU3_HOOK_INIT(GJLevelList)

#include <Geode/modify/GJLevelScoreCell.hpp>
SCREWYOU3_HOOK(GJLevelScoreCell, )
SCREWYOU3_HOOK_INIT(GJLevelScoreCell)

#include <Geode/modify/GJListLayer.hpp>
SCREWYOU3_HOOK(GJListLayer, BoomListView* p0, char const* p1, cocos2d::ccColor4B p2, float p3, float p4, int p5)
SCREWYOU3_HOOK_INIT(GJListLayer, p0, p1, p2, p3, p4, p5)

#include <Geode/modify/GJLocalLevelScoreCell.hpp>
SCREWYOU3_HOOK(GJLocalLevelScoreCell, )
SCREWYOU3_HOOK_INIT(GJLocalLevelScoreCell)

#include <Geode/modify/GJMapPack.hpp>
SCREWYOU3_HOOK(GJMapPack, )
SCREWYOU3_HOOK_INIT(GJMapPack)

#include <Geode/modify/GJMessageCell.hpp>
SCREWYOU3_HOOK(GJMessageCell, )
SCREWYOU3_HOOK_INIT(GJMessageCell)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID
#include <Geode/modify/GJMessagePopup.hpp>
SCREWYOU3_HOOK(GJMessagePopup, GJUserMessage* p0)
SCREWYOU3_HOOK_INIT(GJMessagePopup, p0)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJMGLayer.hpp>
SCREWYOU3_HOOK(GJMGLayer, int p0)
SCREWYOU3_HOOK_INIT(GJMGLayer, p0)
#endif

#include <Geode/modify/GJMultiplayerManager.hpp>
SCREWYOU3_HOOK(GJMultiplayerManager, )
SCREWYOU3_HOOK_INIT(GJMultiplayerManager)

#include <Geode/modify/GJObjectDecoder.hpp>
SCREWYOU3_HOOK(GJObjectDecoder, )
SCREWYOU3_HOOK_INIT(GJObjectDecoder)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJOptionsLayer.hpp>
SCREWYOU3_HOOK(GJOptionsLayer, int p0)
SCREWYOU3_HOOK_INIT(GJOptionsLayer, p0)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJPathPage.hpp>
SCREWYOU3_HOOK(GJPathPage, int p0, GJPathsLayer* p1)
SCREWYOU3_HOOK_INIT(GJPathPage, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJPathRewardPopup.hpp>
SCREWYOU3_HOOK(GJPathRewardPopup, int p0)
SCREWYOU3_HOOK_INIT(GJPathRewardPopup, p0)
#endif

#include <Geode/modify/GJPathsLayer.hpp>
SCREWYOU3_HOOK(GJPathsLayer, )
SCREWYOU3_HOOK_INIT(GJPathsLayer)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJPathSprite.hpp>
SCREWYOU3_HOOK(GJPathSprite, int p0)
SCREWYOU3_HOOK_INIT(GJPathSprite, p0)
#endif

#include <Geode/modify/GJPFollowCommandLayer.hpp>
SCREWYOU3_HOOK(GJPFollowCommandLayer, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(GJPFollowCommandLayer, p0, p1)

#include <Geode/modify/GJPromoPopup.hpp>
SCREWYOU3_HOOK(GJPromoPopup, gd::string p0)
SCREWYOU3_HOOK_INIT(GJPromoPopup, p0)

#include <Geode/modify/GJRequestCell.hpp>
SCREWYOU3_HOOK(GJRequestCell, )
SCREWYOU3_HOOK_INIT(GJRequestCell)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJRewardItem.hpp>
SCREWYOU3_HOOK(GJRewardItem, int chestID, int timeRemaining, gd::string p2)
SCREWYOU3_HOOK_INIT(GJRewardItem, chestID, timeRemaining, p2)
#endif

#include <Geode/modify/GJRobotSprite.hpp>
SCREWYOU3_HOOK(GJRobotSprite, int p0, gd::string p1)
SCREWYOU3_HOOK_INIT(GJRobotSprite, p0, p1)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJRotateCommandLayer.hpp>
SCREWYOU3_HOOK(GJRotateCommandLayer, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(GJRotateCommandLayer, p0, p1)
#endif

#include <Geode/modify/GJRotationControl.hpp>
SCREWYOU3_HOOK(GJRotationControl, )
SCREWYOU3_HOOK_INIT(GJRotationControl)

#include <Geode/modify/GJScaleControl.hpp>
SCREWYOU3_HOOK(GJScaleControl, )
SCREWYOU3_HOOK_INIT(GJScaleControl)

#include <Geode/modify/GJScoreCell.hpp>
SCREWYOU3_HOOK(GJScoreCell, )
SCREWYOU3_HOOK_INIT(GJScoreCell)

#include <Geode/modify/GJShopLayer.hpp>
SCREWYOU3_HOOK(GJShopLayer, ShopType p0)
SCREWYOU3_HOOK_INIT(GJShopLayer, p0)

#include <Geode/modify/GJSmartBlockPreviewSprite.hpp>
SCREWYOU3_HOOK(GJSmartBlockPreviewSprite, )
SCREWYOU3_HOOK_INIT(GJSmartBlockPreviewSprite)

#include <Geode/modify/GJSongBrowser.hpp>
SCREWYOU3_HOOK(GJSongBrowser, )
SCREWYOU3_HOOK_INIT(GJSongBrowser)

#include <Geode/modify/GJSpecialColorSelect.hpp>
SCREWYOU3_HOOK(GJSpecialColorSelect, int p0, GJSpecialColorSelectDelegate* p1, ColorSelectType p2)
SCREWYOU3_HOOK_INIT(GJSpecialColorSelect, p0, p1, p2)

#include <Geode/modify/GJTransformControl.hpp>
SCREWYOU3_HOOK(GJTransformControl, )
SCREWYOU3_HOOK_INIT(GJTransformControl)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJUINode.hpp>
SCREWYOU3_HOOK(GJUINode, UIButtonConfig& p0)
SCREWYOU3_HOOK_INIT(GJUINode, p0)
#endif

#include <Geode/modify/GJUserCell.hpp>
SCREWYOU3_HOOK(GJUserCell, )
SCREWYOU3_HOOK_INIT(GJUserCell)

#include <Geode/modify/GJUserMessage.hpp>
SCREWYOU3_HOOK(GJUserMessage, )
SCREWYOU3_HOOK_INIT(GJUserMessage)

#include <Geode/modify/GJUserScore.hpp>
SCREWYOU3_HOOK(GJUserScore, )
SCREWYOU3_HOOK_INIT(GJUserScore)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJWorldNode.hpp>
SCREWYOU3_HOOK(GJWorldNode, int p0, WorldSelectLayer* p1)
SCREWYOU3_HOOK_INIT(GJWorldNode, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/GJWriteMessagePopup.hpp>
SCREWYOU3_HOOK(GJWriteMessagePopup, int p0, int p1)
SCREWYOU3_HOOK_INIT(GJWriteMessagePopup, p0, p1)
#endif

#include <Geode/modify/GManager.hpp>
SCREWYOU3_HOOK(GManager, )
SCREWYOU3_HOOK_INIT(GManager)

#include <Geode/modify/GradientTriggerObject.hpp>
SCREWYOU3_HOOK(GradientTriggerObject, )
SCREWYOU3_HOOK_INIT(GradientTriggerObject)

#include <Geode/modify/GravityEffectSprite.hpp>
SCREWYOU3_HOOK(GravityEffectSprite, )
SCREWYOU3_HOOK_INIT(GravityEffectSprite)

#include <Geode/modify/HardStreak.hpp>
SCREWYOU3_HOOK(HardStreak, )
SCREWYOU3_HOOK_INIT(HardStreak)

#include <Geode/modify/HSVLiveOverlay.hpp>
SCREWYOU3_HOOK(HSVLiveOverlay, GameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(HSVLiveOverlay, p0, p1)

#include <Geode/modify/HSVWidgetPopup.hpp>
SCREWYOU3_HOOK(HSVWidgetPopup, cocos2d::ccHSVValue hsv, HSVWidgetDelegate* delegate, gd::string title)
SCREWYOU3_HOOK_INIT(HSVWidgetPopup, hsv, delegate, title)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/InfoAlertButton.hpp>
SCREWYOU3_HOOK(InfoAlertButton, gd::string title, gd::string desc, float spriteScale)
SCREWYOU3_HOOK_INIT(InfoAlertButton, title, desc, spriteScale)
#endif

#include <Geode/modify/InfoLayer.hpp>
SCREWYOU3_HOOK(InfoLayer, GJGameLevel* p0, GJUserScore* p1, GJLevelList* p2)
SCREWYOU3_HOOK_INIT(InfoLayer, p0, p1, p2)

#include <Geode/modify/ItemInfoPopup.hpp>
SCREWYOU3_HOOK(ItemInfoPopup, int p0, UnlockType p1)
SCREWYOU3_HOOK_INIT(ItemInfoPopup, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/KeybindingsLayer.hpp>
SCREWYOU3_HOOK(KeybindingsLayer, )
SCREWYOU3_HOOK_INIT(KeybindingsLayer)
#endif

#include <Geode/modify/KeyframeAnimTriggerObject.hpp>
SCREWYOU3_HOOK(KeyframeAnimTriggerObject, )
SCREWYOU3_HOOK_INIT(KeyframeAnimTriggerObject)

#include <Geode/modify/KeyframeGameObject.hpp>
SCREWYOU3_HOOK(KeyframeGameObject, )
SCREWYOU3_HOOK_INIT(KeyframeGameObject)

#include <Geode/modify/LabelGameObject.hpp>
SCREWYOU3_HOOK(LabelGameObject, )
SCREWYOU3_HOOK_INIT(LabelGameObject)

#include <Geode/modify/LeaderboardsLayer.hpp>
SCREWYOU3_HOOK(LeaderboardsLayer, LeaderboardState p0)
SCREWYOU3_HOOK_INIT(LeaderboardsLayer, p0)

#include <Geode/modify/LevelAreaInnerLayer.hpp>
SCREWYOU3_HOOK(LevelAreaInnerLayer, bool returning)
SCREWYOU3_HOOK_INIT(LevelAreaInnerLayer, returning)

#include <Geode/modify/LevelAreaLayer.hpp>
SCREWYOU3_HOOK(LevelAreaLayer, )
SCREWYOU3_HOOK_INIT(LevelAreaLayer)

#include <Geode/modify/LevelBrowserLayer.hpp>
SCREWYOU3_HOOK(LevelBrowserLayer, GJSearchObject* p0)
SCREWYOU3_HOOK_INIT(LevelBrowserLayer, p0)

#include <Geode/modify/LevelCell.hpp>
SCREWYOU3_HOOK(LevelCell, )
SCREWYOU3_HOOK_INIT(LevelCell)

#include <Geode/modify/LevelEditorLayer.hpp>
SCREWYOU3_HOOK(LevelEditorLayer, GJGameLevel* p0, bool p1)
SCREWYOU3_HOOK_INIT(LevelEditorLayer, p0, p1)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/LevelFeatureLayer.hpp>
SCREWYOU3_HOOK(LevelFeatureLayer, int p0)
SCREWYOU3_HOOK_INIT(LevelFeatureLayer, p0)
#endif

#include <Geode/modify/LevelInfoLayer.hpp>
SCREWYOU3_HOOK(LevelInfoLayer, GJGameLevel* level, bool challenge)
SCREWYOU3_HOOK_INIT(LevelInfoLayer, level, challenge)

#include <Geode/modify/LevelLeaderboard.hpp>
SCREWYOU3_HOOK(LevelLeaderboard, GJGameLevel* p0, LevelLeaderboardType p1, LevelLeaderboardMode p2)
SCREWYOU3_HOOK_INIT(LevelLeaderboard, p0, p1, p2)

#include <Geode/modify/LevelListLayer.hpp>
SCREWYOU3_HOOK(LevelListLayer, GJLevelList* p0)
SCREWYOU3_HOOK_INIT(LevelListLayer, p0)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/LevelOptionsLayer.hpp>
SCREWYOU3_HOOK(LevelOptionsLayer, LevelSettingsObject* p0)
SCREWYOU3_HOOK_INIT(LevelOptionsLayer, p0)
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/LevelOptionsLayer2.hpp>
SCREWYOU3_HOOK(LevelOptionsLayer2, LevelSettingsObject* p0)
SCREWYOU3_HOOK_INIT(LevelOptionsLayer2, p0)
#endif

#include <Geode/modify/LevelPage.hpp>
SCREWYOU3_HOOK(LevelPage, GJGameLevel* p0)
SCREWYOU3_HOOK_INIT(LevelPage, p0)

#include <Geode/modify/LevelSearchLayer.hpp>
SCREWYOU3_HOOK(LevelSearchLayer, int p0)
SCREWYOU3_HOOK_INIT(LevelSearchLayer, p0)

#include <Geode/modify/LevelSelectLayer.hpp>
SCREWYOU3_HOOK(LevelSelectLayer, int page)
SCREWYOU3_HOOK_INIT(LevelSelectLayer, page)

#include <Geode/modify/LevelSettingsLayer.hpp>
SCREWYOU3_HOOK(LevelSettingsLayer, LevelSettingsObject* p0, LevelEditorLayer* p1)
SCREWYOU3_HOOK_INIT(LevelSettingsLayer, p0, p1)

#include <Geode/modify/LevelSettingsObject.hpp>
SCREWYOU3_HOOK(LevelSettingsObject, )
SCREWYOU3_HOOK_INIT(LevelSettingsObject)

#include <Geode/modify/LikeItemLayer.hpp>
SCREWYOU3_HOOK(LikeItemLayer, LikeItemType p0, int p1, int p2)
SCREWYOU3_HOOK_INIT(LikeItemLayer, p0, p1, p2)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/ListButtonBar.hpp>
SCREWYOU3_HOOK(ListButtonBar, cocos2d::CCArray* items, cocos2d::CCPoint position, int columns, int rows, float columnOffset, float rowOffset, float offset, float arrowOffset, int arrowType)
SCREWYOU3_HOOK_INIT(ListButtonBar, items, position, columns, rows, columnOffset, rowOffset, offset, arrowOffset, arrowType)
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/ListButtonPage.hpp>
SCREWYOU3_HOOK(ListButtonPage, cocos2d::CCArray* items, cocos2d::CCPoint position, int columns, int rows, float columnOffset, float rowOffset, float offset)
SCREWYOU3_HOOK_INIT(ListButtonPage, items, position, columns, rows, columnOffset, rowOffset, offset)
#endif

#include <Geode/modify/LoadingCircle.hpp>
SCREWYOU3_HOOK(LoadingCircle, )
SCREWYOU3_HOOK_INIT(LoadingCircle)

#include <Geode/modify/LoadingLayer.hpp>
SCREWYOU3_HOOK(LoadingLayer, bool p0)
SCREWYOU3_HOOK_INIT(LoadingLayer, p0)

#include <Geode/modify/LocalLevelManager.hpp>
SCREWYOU3_HOOK(LocalLevelManager, )
SCREWYOU3_HOOK_INIT(LocalLevelManager)

#include <Geode/modify/MapPackCell.hpp>
SCREWYOU3_HOOK(MapPackCell, )
SCREWYOU3_HOOK_INIT(MapPackCell)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/MapSelectLayer.hpp>
SCREWYOU3_HOOK(MapSelectLayer, )
SCREWYOU3_HOOK_INIT(MapSelectLayer)
#endif

#include <Geode/modify/MenuGameLayer.hpp>
SCREWYOU3_HOOK(MenuGameLayer, )
SCREWYOU3_HOOK_INIT(MenuGameLayer)

#include <Geode/modify/MenuLayer.hpp>
SCREWYOU3_HOOK(MenuLayer, )
SCREWYOU3_MENULAYER_CUSTOM_INIT(MenuLayer)

#include <Geode/modify/MessagesProfilePage.hpp>
SCREWYOU3_HOOK(MessagesProfilePage, bool p0)
SCREWYOU3_HOOK_INIT(MessagesProfilePage, p0)

#include <Geode/modify/MoreOptionsLayer.hpp>
SCREWYOU3_HOOK(MoreOptionsLayer, )
SCREWYOU3_HOOK_INIT(MoreOptionsLayer)

#include <Geode/modify/MoreSearchLayer.hpp>
SCREWYOU3_HOOK(MoreSearchLayer, )
SCREWYOU3_HOOK_INIT(MoreSearchLayer)

#include <Geode/modify/MoreVideoOptionsLayer.hpp>
SCREWYOU3_HOOK(MoreVideoOptionsLayer, )
SCREWYOU3_HOOK_INIT(MoreVideoOptionsLayer)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/MultiplayerLayer.hpp>
SCREWYOU3_HOOK(MultiplayerLayer, )
SCREWYOU3_HOOK_INIT(MultiplayerLayer)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/MultiTriggerPopup.hpp>
SCREWYOU3_HOOK(MultiTriggerPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(MultiTriggerPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/MusicBrowser.hpp>
SCREWYOU3_HOOK(MusicBrowser, int p0, GJSongType p1)
SCREWYOU3_HOOK_INIT(MusicBrowser, p0, p1)
#endif

#include <Geode/modify/MusicDownloadManager.hpp>
SCREWYOU3_HOOK(MusicDownloadManager, )
SCREWYOU3_HOOK_INIT(MusicDownloadManager)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/NCSInfoLayer.hpp>
SCREWYOU3_HOOK(NCSInfoLayer, CustomSongLayer* p0)
SCREWYOU3_HOOK_INIT(NCSInfoLayer, p0)
#endif

#include <Geode/modify/NewgroundsInfoLayer.hpp>
SCREWYOU3_HOOK(NewgroundsInfoLayer, )
SCREWYOU3_HOOK_INIT(NewgroundsInfoLayer)

#include <Geode/modify/NumberInputLayer.hpp>
SCREWYOU3_HOOK(NumberInputLayer, )
SCREWYOU3_HOOK_INIT(NumberInputLayer)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/OBB2D.hpp>
SCREWYOU3_HOOK(OBB2D, cocos2d::CCPoint center, float width, float height, float rotationAngle)
SCREWYOU3_HOOK_INIT(OBB2D, center, width, height, rotationAngle)
#endif

#include <Geode/modify/ObjectControlGameObject.hpp>
SCREWYOU3_HOOK(ObjectControlGameObject, )
SCREWYOU3_HOOK_INIT(ObjectControlGameObject)

#include <Geode/modify/ObjectManager.hpp>
SCREWYOU3_HOOK(ObjectManager, )
SCREWYOU3_HOOK_INIT(ObjectManager)

#include <Geode/modify/ObjectToolbox.hpp>
SCREWYOU3_HOOK(ObjectToolbox, )
SCREWYOU3_HOOK_INIT(ObjectToolbox)

#include <Geode/modify/ParentalOptionsLayer.hpp>
SCREWYOU3_HOOK(ParentalOptionsLayer, )
SCREWYOU3_HOOK_INIT(ParentalOptionsLayer)

#include <Geode/modify/ParticleGameObject.hpp>
SCREWYOU3_HOOK(ParticleGameObject, )
SCREWYOU3_HOOK_INIT(ParticleGameObject)

#include <Geode/modify/PlayerCheckpoint.hpp>
SCREWYOU3_HOOK(PlayerCheckpoint, )
SCREWYOU3_HOOK_INIT(PlayerCheckpoint)

#include <Geode/modify/PlayerControlGameObject.hpp>
SCREWYOU3_HOOK(PlayerControlGameObject, )
SCREWYOU3_HOOK_INIT(PlayerControlGameObject)

#include <Geode/modify/PlayerFireBoostSprite.hpp>
SCREWYOU3_HOOK(PlayerFireBoostSprite, )
SCREWYOU3_HOOK_INIT(PlayerFireBoostSprite)

#include <Geode/modify/PlayerObject.hpp>
SCREWYOU3_HOOK(PlayerObject, int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
SCREWYOU3_HOOK_INIT(PlayerObject, player, ship, gameLayer, layer, playLayer)

#include <Geode/modify/PlayLayer.hpp>
SCREWYOU3_HOOK(PlayLayer, GJGameLevel* level, bool useReplay, bool dontCreateObjects)
SCREWYOU3_HOOK_INIT(PlayLayer, level, useReplay, dontCreateObjects)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/PriceLabel.hpp>
SCREWYOU3_HOOK(PriceLabel, int p0)
SCREWYOU3_HOOK_INIT(PriceLabel, p0)
#endif

#include <Geode/modify/ProfilePage.hpp>
SCREWYOU3_HOOK(ProfilePage, int accountID, bool ownProfile)
SCREWYOU3_HOOK_INIT(ProfilePage, accountID, ownProfile)

#include <Geode/modify/PurchaseItemPopup.hpp>
SCREWYOU3_HOOK(PurchaseItemPopup, GJStoreItem* p0)
SCREWYOU3_HOOK_INIT(PurchaseItemPopup, p0)

#include <Geode/modify/RandTriggerGameObject.hpp>
SCREWYOU3_HOOK(RandTriggerGameObject, )
SCREWYOU3_HOOK_INIT(RandTriggerGameObject)

#include <Geode/modify/RateDemonLayer.hpp>
SCREWYOU3_HOOK(RateDemonLayer, int p0)
SCREWYOU3_HOOK_INIT(RateDemonLayer, p0)

#include <Geode/modify/RateLevelLayer.hpp>
SCREWYOU3_HOOK(RateLevelLayer, int p0)
SCREWYOU3_HOOK_INIT(RateLevelLayer, p0)

#include <Geode/modify/RateStarsLayer.hpp>
SCREWYOU3_HOOK(RateStarsLayer, int p0, bool p1, bool p2)
SCREWYOU3_HOOK_INIT(RateStarsLayer, p0, p1, p2)

#include <Geode/modify/RewardsPage.hpp>
SCREWYOU3_HOOK(RewardsPage, )
SCREWYOU3_HOOK_INIT(RewardsPage)

#include <Geode/modify/RewardUnlockLayer.hpp>
SCREWYOU3_HOOK(RewardUnlockLayer, int p0, RewardsPage* p1)
SCREWYOU3_HOOK_INIT(RewardUnlockLayer, p0, p1)

#include <Geode/modify/RotateGameplayGameObject.hpp>
SCREWYOU3_HOOK(RotateGameplayGameObject, )
SCREWYOU3_HOOK_INIT(RotateGameplayGameObject)

#include <Geode/modify/SearchButton.hpp>
SCREWYOU3_HOOK(SearchButton, char const* p0, char const* p1, float p2, char const* p3)
SCREWYOU3_HOOK_INIT(SearchButton, p0, p1, p2, p3)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SearchSFXPopup.hpp>
SCREWYOU3_HOOK(SearchSFXPopup, gd::string p0)
SCREWYOU3_HOOK_INIT(SearchSFXPopup, p0)
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SecretGame01Layer.hpp>
SCREWYOU3_HOOK(SecretGame01Layer, )
SCREWYOU3_HOOK_INIT(SecretGame01Layer)
#endif

#include <Geode/modify/SecretLayer.hpp>
SCREWYOU3_HOOK(SecretLayer, )
SCREWYOU3_HOOK_INIT(SecretLayer)

#include <Geode/modify/SecretLayer2.hpp>
SCREWYOU3_HOOK(SecretLayer2, )
SCREWYOU3_HOOK_INIT(SecretLayer2)

#include <Geode/modify/SecretLayer3.hpp>
SCREWYOU3_HOOK(SecretLayer3, )
SCREWYOU3_HOOK_INIT(SecretLayer3)

#include <Geode/modify/SecretLayer4.hpp>
SCREWYOU3_HOOK(SecretLayer4, )
SCREWYOU3_HOOK_INIT(SecretLayer4)

#include <Geode/modify/SecretLayer5.hpp>
SCREWYOU3_HOOK(SecretLayer5, )
SCREWYOU3_HOOK_INIT(SecretLayer5)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SecretLayer6.hpp>
SCREWYOU3_HOOK(SecretLayer6, )
SCREWYOU3_HOOK_INIT(SecretLayer6)
#endif

#include <Geode/modify/SecretNumberLayer.hpp>
SCREWYOU3_HOOK(SecretNumberLayer, )
SCREWYOU3_HOOK_INIT(SecretNumberLayer)

#include <Geode/modify/SecretRewardsLayer.hpp>
SCREWYOU3_HOOK(SecretRewardsLayer, bool p0)
SCREWYOU3_HOOK_INIT(SecretRewardsLayer, p0)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SelectArtLayer.hpp>
SCREWYOU3_HOOK(SelectArtLayer, SelectArtType p0, int p1)
SCREWYOU3_HOOK_INIT(SelectArtLayer, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SelectEventLayer.hpp>
SCREWYOU3_HOOK(SelectEventLayer, SetupEventLinkPopup* p0, gd::set<int>& p1)
SCREWYOU3_HOOK_INIT(SelectEventLayer, p0, p1)
#endif

#include <Geode/modify/SelectFontLayer.hpp>
SCREWYOU3_HOOK(SelectFontLayer, LevelEditorLayer* p0)
SCREWYOU3_HOOK_INIT(SelectFontLayer, p0)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SelectListIconLayer.hpp>
SCREWYOU3_HOOK(SelectListIconLayer, int p0)
SCREWYOU3_HOOK_INIT(SelectListIconLayer, p0)
#endif

#include <Geode/modify/SelectPremadeLayer.hpp>
SCREWYOU3_HOOK(SelectPremadeLayer, )
SCREWYOU3_HOOK_INIT(SelectPremadeLayer)

#include <Geode/modify/SelectSettingLayer.hpp>
SCREWYOU3_HOOK(SelectSettingLayer, SelectSettingType p0, int p1)
SCREWYOU3_HOOK_INIT(SelectSettingLayer, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SelectSFXSortLayer.hpp>
SCREWYOU3_HOOK(SelectSFXSortLayer, AudioSortType p0)
SCREWYOU3_HOOK_INIT(SelectSFXSortLayer, p0)
#endif

#include <Geode/modify/SequenceTriggerGameObject.hpp>
SCREWYOU3_HOOK(SequenceTriggerGameObject, )
SCREWYOU3_HOOK_INIT(SequenceTriggerGameObject)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetColorIDPopup.hpp>
SCREWYOU3_HOOK(SetColorIDPopup, int p0)
SCREWYOU3_HOOK_INIT(SetColorIDPopup, p0)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetFolderPopup.hpp>
SCREWYOU3_HOOK(SetFolderPopup, int value, bool isCreated, gd::string title)
SCREWYOU3_HOOK_INIT(SetFolderPopup, value, isCreated, title)
#endif

#include <Geode/modify/SetGroupIDLayer.hpp>
SCREWYOU3_HOOK(SetGroupIDLayer, GameObject* obj, cocos2d::CCArray* objs)
SCREWYOU3_HOOK_INIT(SetGroupIDLayer, obj, objs)

#include <Geode/modify/SetIDPopup.hpp>
SCREWYOU3_HOOK(SetIDPopup, int current, int begin, int end, gd::string title, gd::string button, bool p5, int p6, float p7, bool p8, bool p9)
SCREWYOU3_HOOK_INIT(SetIDPopup, current, begin, end, title, button, p5, p6, p7, p8, p9)

#include <Geode/modify/SetItemIDLayer.hpp>
SCREWYOU3_HOOK(SetItemIDLayer, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetItemIDLayer, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetLevelOrderPopup.hpp>
SCREWYOU3_HOOK(SetLevelOrderPopup, int levelID, int order, int amount)
SCREWYOU3_HOOK_INIT(SetLevelOrderPopup, levelID, order, amount)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetTargetIDLayer.hpp>
SCREWYOU3_HOOK(SetTargetIDLayer, EffectGameObject* p0, cocos2d::CCArray* p1, gd::string p2, gd::string p3, int p4, int p5, int p6)
SCREWYOU3_HOOK_INIT(SetTargetIDLayer, p0, p1, p2, p3, p4, p5, p6)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetTextPopup.hpp>
SCREWYOU3_HOOK(SetTextPopup, gd::string p0, gd::string p1, int p2, gd::string p3, gd::string p4, bool p5, float p6)
SCREWYOU3_HOOK_INIT(SetTextPopup, p0, p1, p2, p3, p4, p5, p6)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupAdvFollowEditPhysicsPopup.hpp>
SCREWYOU3_HOOK(SetupAdvFollowEditPhysicsPopup, AdvancedFollowEditObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupAdvFollowEditPhysicsPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupAdvFollowPopup.hpp>
SCREWYOU3_HOOK(SetupAdvFollowPopup, AdvancedFollowTriggerObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupAdvFollowPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupAdvFollowRetargetPopup.hpp>
SCREWYOU3_HOOK(SetupAdvFollowRetargetPopup, AdvancedFollowEditObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupAdvFollowRetargetPopup, p0, p1)
#endif

#include <Geode/modify/SetupAnimationPopup.hpp>
SCREWYOU3_HOOK(SetupAnimationPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupAnimationPopup, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupAnimSettingsPopup.hpp>
SCREWYOU3_HOOK(SetupAnimSettingsPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupAnimSettingsPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupAreaAnimTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupAreaAnimTriggerPopup, EnterEffectObject* p0, cocos2d::CCArray* p1, int p2)
SCREWYOU3_HOOK_INIT(SetupAreaAnimTriggerPopup, p0, p1, p2)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupAreaFadeTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupAreaFadeTriggerPopup, EnterEffectObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupAreaFadeTriggerPopup, p0, p1)
#endif

#include <Geode/modify/SetupAreaMoveTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupAreaMoveTriggerPopup, EnterEffectObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupAreaMoveTriggerPopup, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupAreaRotateTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupAreaRotateTriggerPopup, EnterEffectObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupAreaRotateTriggerPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupAreaTintTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupAreaTintTriggerPopup, EnterEffectObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupAreaTintTriggerPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupAreaTransformTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupAreaTransformTriggerPopup, EnterEffectObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupAreaTransformTriggerPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupAreaTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupAreaTriggerPopup, EnterEffectObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupAreaTriggerPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupArtSwitchPopup.hpp>
SCREWYOU3_HOOK(SetupArtSwitchPopup, ArtTriggerGameObject* p0, cocos2d::CCArray* p1, int p2)
SCREWYOU3_HOOK_INIT(SetupArtSwitchPopup, p0, p1, p2)
#endif

#include <Geode/modify/SetupAudioLineGuidePopup.hpp>
SCREWYOU3_HOOK(SetupAudioLineGuidePopup, AudioLineGuideGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupAudioLineGuidePopup, p0, p1)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupBGSpeedTrigger.hpp>
SCREWYOU3_HOOK(SetupBGSpeedTrigger, EffectGameObject* p0, cocos2d::CCArray* p1, int p2)
SCREWYOU3_HOOK_INIT(SetupBGSpeedTrigger, p0, p1, p2)
#endif

#include <Geode/modify/SetupCameraEdgePopup.hpp>
SCREWYOU3_HOOK(SetupCameraEdgePopup, CameraTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupCameraEdgePopup, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupCameraGuidePopup.hpp>
SCREWYOU3_HOOK(SetupCameraGuidePopup, CameraTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupCameraGuidePopup, p0, p1)
#endif

#include <Geode/modify/SetupCameraModePopup.hpp>
SCREWYOU3_HOOK(SetupCameraModePopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupCameraModePopup, p0, p1)

#include <Geode/modify/SetupCameraOffsetTrigger.hpp>
SCREWYOU3_HOOK(SetupCameraOffsetTrigger, CameraTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupCameraOffsetTrigger, p0, p1)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupCameraRotatePopup.hpp>
SCREWYOU3_HOOK(SetupCameraRotatePopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupCameraRotatePopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupCameraRotatePopup2.hpp>
SCREWYOU3_HOOK(SetupCameraRotatePopup2, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupCameraRotatePopup2, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupCheckpointPopup.hpp>
SCREWYOU3_HOOK(SetupCheckpointPopup, CheckpointGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupCheckpointPopup, p0, p1)
#endif

#include <Geode/modify/SetupCoinLayer.hpp>
SCREWYOU3_HOOK(SetupCoinLayer, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupCoinLayer, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupCollisionStateTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupCollisionStateTriggerPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupCollisionStateTriggerPopup, p0, p1)
#endif

#include <Geode/modify/SetupCollisionTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupCollisionTriggerPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupCollisionTriggerPopup, p0, p1)

#include <Geode/modify/SetupCountTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupCountTriggerPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupCountTriggerPopup, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupDashRingPopup.hpp>
SCREWYOU3_HOOK(SetupDashRingPopup, DashRingObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupDashRingPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupEndPopup.hpp>
SCREWYOU3_HOOK(SetupEndPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupEndPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupEnterEffectPopup.hpp>
SCREWYOU3_HOOK(SetupEnterEffectPopup, EnterEffectObject* p0, cocos2d::CCArray* p1, int p2)
SCREWYOU3_HOOK_INIT(SetupEnterEffectPopup, p0, p1, p2)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupEnterTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupEnterTriggerPopup, EnterEffectObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupEnterTriggerPopup, p0, p1)
#endif

#include <Geode/modify/SetupEventLinkPopup.hpp>
SCREWYOU3_HOOK(SetupEventLinkPopup, EventLinkTrigger* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupEventLinkPopup, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupForceBlockPopup.hpp>
SCREWYOU3_HOOK(SetupForceBlockPopup, ForceBlockGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupForceBlockPopup, p0, p1)
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupGameplayOffsetPopup.hpp>
SCREWYOU3_HOOK(SetupGameplayOffsetPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupGameplayOffsetPopup, p0, p1)
#endif

#include <Geode/modify/SetupGradientPopup.hpp>
SCREWYOU3_HOOK(SetupGradientPopup, GradientTriggerObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupGradientPopup, p0, p1)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupGravityModPopup.hpp>
SCREWYOU3_HOOK(SetupGravityModPopup, EffectGameObject* p0, cocos2d::CCArray* p1, bool p2)
SCREWYOU3_HOOK_INIT(SetupGravityModPopup, p0, p1, p2)
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupGravityTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupGravityTriggerPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupGravityTriggerPopup, p0, p1)
#endif

#include <Geode/modify/SetupInstantCollisionTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupInstantCollisionTriggerPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupInstantCollisionTriggerPopup, p0, p1)

#include <Geode/modify/SetupInstantCountPopup.hpp>
SCREWYOU3_HOOK(SetupInstantCountPopup, CountTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupInstantCountPopup, p0, p1)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupInteractObjectPopup.hpp>
SCREWYOU3_HOOK(SetupInteractObjectPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupInteractObjectPopup, p0, p1)
#endif

#include <Geode/modify/SetupItemCompareTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupItemCompareTriggerPopup, ItemTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupItemCompareTriggerPopup, p0, p1)

#include <Geode/modify/SetupItemEditTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupItemEditTriggerPopup, ItemTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupItemEditTriggerPopup, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupKeyframeAnimPopup.hpp>
SCREWYOU3_HOOK(SetupKeyframeAnimPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupKeyframeAnimPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupKeyframePopup.hpp>
SCREWYOU3_HOOK(SetupKeyframePopup, KeyframeGameObject* p0, cocos2d::CCArray* p1, LevelEditorLayer* p2)
SCREWYOU3_HOOK_INIT(SetupKeyframePopup, p0, p1, p2)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupMGTrigger.hpp>
SCREWYOU3_HOOK(SetupMGTrigger, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupMGTrigger, p0, p1)
#endif

#include <Geode/modify/SetupMoveCommandPopup.hpp>
SCREWYOU3_HOOK(SetupMoveCommandPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupMoveCommandPopup, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupObjectControlPopup.hpp>
SCREWYOU3_HOOK(SetupObjectControlPopup, ObjectControlGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupObjectControlPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupObjectOptions2Popup.hpp>
SCREWYOU3_HOOK(SetupObjectOptions2Popup, GameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupObjectOptions2Popup, p0, p1)
#endif

#include <Geode/modify/SetupObjectOptionsPopup.hpp>
SCREWYOU3_HOOK(SetupObjectOptionsPopup, GameObject* p0, cocos2d::CCArray* p1, SetGroupIDLayer* p2)
SCREWYOU3_HOOK_INIT(SetupObjectOptionsPopup, p0, p1, p2)

#include <Geode/modify/SetupObjectTogglePopup.hpp>
SCREWYOU3_HOOK(SetupObjectTogglePopup, EffectGameObject* p0, cocos2d::CCArray* p1, bool p2)
SCREWYOU3_HOOK_INIT(SetupObjectTogglePopup, p0, p1, p2)

#include <Geode/modify/SetupOpacityPopup.hpp>
SCREWYOU3_HOOK(SetupOpacityPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupOpacityPopup, p0, p1)

#include <Geode/modify/SetupOptionsTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupOptionsTriggerPopup, GameOptionsTrigger* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupOptionsTriggerPopup, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupPersistentItemTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupPersistentItemTriggerPopup, ItemTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupPersistentItemTriggerPopup, p0, p1)
#endif

#include <Geode/modify/SetupPickupTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupPickupTriggerPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupPickupTriggerPopup, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupPlatformerEndPopup.hpp>
SCREWYOU3_HOOK(SetupPlatformerEndPopup, EndTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupPlatformerEndPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupPlayerControlPopup.hpp>
SCREWYOU3_HOOK(SetupPlayerControlPopup, PlayerControlGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupPlayerControlPopup, p0, p1)
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupPortalPopup.hpp>
SCREWYOU3_HOOK(SetupPortalPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupPortalPopup, p0, p1)
#endif

#include <Geode/modify/SetupPulsePopup.hpp>
SCREWYOU3_HOOK(SetupPulsePopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupPulsePopup, p0, p1)

#include <Geode/modify/SetupRandAdvTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupRandAdvTriggerPopup, RandTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupRandAdvTriggerPopup, p0, p1)

#include <Geode/modify/SetupRandTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupRandTriggerPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupRandTriggerPopup, p0, p1)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupResetTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupResetTriggerPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupResetTriggerPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupReverbPopup.hpp>
SCREWYOU3_HOOK(SetupReverbPopup, SFXTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupReverbPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupRotateCommandPopup.hpp>
SCREWYOU3_HOOK(SetupRotateCommandPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupRotateCommandPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupRotateGameplayPopup.hpp>
SCREWYOU3_HOOK(SetupRotateGameplayPopup, RotateGameplayGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupRotateGameplayPopup, p0, p1)
#endif

#include <Geode/modify/SetupRotatePopup.hpp>
SCREWYOU3_HOOK(SetupRotatePopup, EnhancedGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupRotatePopup, p0, p1)

#include <Geode/modify/SetupSequenceTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupSequenceTriggerPopup, SequenceTriggerGameObject* p0)
SCREWYOU3_HOOK_INIT(SetupSequenceTriggerPopup, p0)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupSFXEditPopup.hpp>
SCREWYOU3_HOOK(SetupSFXEditPopup, SFXTriggerGameObject* p0, cocos2d::CCArray* p1, bool p2)
SCREWYOU3_HOOK_INIT(SetupSFXEditPopup, p0, p1, p2)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupSFXPopup.hpp>
SCREWYOU3_HOOK(SetupSFXPopup, SFXTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupSFXPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID
#include <Geode/modify/SetupShaderEffectPopup.hpp>
SCREWYOU3_HOOK(SetupShaderEffectPopup, EffectGameObject* p0, cocos2d::CCArray* p1, int p2)
SCREWYOU3_HOOK_INIT(SetupShaderEffectPopup, p0, p1, p2)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupShakePopup.hpp>
SCREWYOU3_HOOK(SetupShakePopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupShakePopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupSmartBlockLayer.hpp>
SCREWYOU3_HOOK(SetupSmartBlockLayer, SmartGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupSmartBlockLayer, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupSmartTemplateLayer.hpp>
SCREWYOU3_HOOK(SetupSmartTemplateLayer, GJSmartTemplate* p0)
SCREWYOU3_HOOK_INIT(SetupSmartTemplateLayer, p0)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupSongTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupSongTriggerPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupSongTriggerPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupSpawnParticlePopup.hpp>
SCREWYOU3_HOOK(SetupSpawnParticlePopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupSpawnParticlePopup, p0, p1)
#endif

#include <Geode/modify/SetupSpawnPopup.hpp>
SCREWYOU3_HOOK(SetupSpawnPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupSpawnPopup, p0, p1)

#include <Geode/modify/SetupStaticCameraPopup.hpp>
SCREWYOU3_HOOK(SetupStaticCameraPopup, CameraTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupStaticCameraPopup, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupStopTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupStopTriggerPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupStopTriggerPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupTeleportPopup.hpp>
SCREWYOU3_HOOK(SetupTeleportPopup, TeleportPortalObject* p0, cocos2d::CCArray* p1, int p2, bool p3)
SCREWYOU3_HOOK_INIT(SetupTeleportPopup, p0, p1, p2, p3)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupTimerControlTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupTimerControlTriggerPopup, TimerTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupTimerControlTriggerPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupTimerEventTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupTimerEventTriggerPopup, TimerTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupTimerEventTriggerPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupTimerTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupTimerTriggerPopup, TimerTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupTimerTriggerPopup, p0, p1)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupTimeWarpPopup.hpp>
SCREWYOU3_HOOK(SetupTimeWarpPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupTimeWarpPopup, p0, p1)
#endif

#include <Geode/modify/SetupTouchTogglePopup.hpp>
SCREWYOU3_HOOK(SetupTouchTogglePopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupTouchTogglePopup, p0, p1)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SetupTransformPopup.hpp>
SCREWYOU3_HOOK(SetupTransformPopup, TransformTriggerGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupTransformPopup, p0, p1)
#endif

#include <Geode/modify/SetupTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupTriggerPopup, EffectGameObject* trigger, cocos2d::CCArray* triggers, float width, float height, int background)
SCREWYOU3_HOOK_INIT(SetupTriggerPopup, trigger, triggers, width, height, background)

#include <Geode/modify/SetupZoomTriggerPopup.hpp>
SCREWYOU3_HOOK(SetupZoomTriggerPopup, EffectGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(SetupZoomTriggerPopup, p0, p1)

#include <Geode/modify/SFXBrowser.hpp>
SCREWYOU3_HOOK(SFXBrowser, int p0)
SCREWYOU3_HOOK_INIT(SFXBrowser, p0)

#include <Geode/modify/ShaderLayer.hpp>
SCREWYOU3_HOOK(ShaderLayer, )
SCREWYOU3_HOOK_INIT(ShaderLayer)

#include <Geode/modify/ShardsPage.hpp>
SCREWYOU3_HOOK(ShardsPage, )
SCREWYOU3_HOOK_INIT(ShardsPage)

#include <Geode/modify/ShareCommentLayer.hpp>
SCREWYOU3_HOOK(ShareCommentLayer, gd::string title, int charLimit, CommentType type, int ID, gd::string desc)
SCREWYOU3_HOOK_INIT(ShareCommentLayer, title, charLimit, type, ID, desc)

#include <Geode/modify/ShareLevelLayer.hpp>
SCREWYOU3_HOOK(ShareLevelLayer, GJGameLevel* level)
SCREWYOU3_HOOK_INIT(ShareLevelLayer, level)

#include <Geode/modify/ShareLevelSettingsLayer.hpp>
SCREWYOU3_HOOK(ShareLevelSettingsLayer, GJGameLevel* p0)
SCREWYOU3_HOOK_INIT(ShareLevelSettingsLayer, p0)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/ShareListLayer.hpp>
SCREWYOU3_HOOK(ShareListLayer, GJLevelList* p0)
SCREWYOU3_HOOK_INIT(ShareListLayer, p0)
#endif

#include <Geode/modify/SimplePlayer.hpp>
SCREWYOU3_HOOK(SimplePlayer, int p0)
SCREWYOU3_HOOK_INIT(SimplePlayer, p0)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SlideInLayer.hpp>
SCREWYOU3_HOOK(SlideInLayer, )
SCREWYOU3_HOOK_INIT(SlideInLayer)
#endif

#include <Geode/modify/Slider.hpp>
SCREWYOU3_HOOK(Slider, cocos2d::CCNode* p0, cocos2d::SEL_MenuHandler p1, char const* p2, char const* p3, char const* p4, char const* p5, float p6)
SCREWYOU3_HOOK_INIT(Slider, p0, p1, p2, p3, p4, p5, p6)

#include <Geode/modify/SmartTemplateCell.hpp>
SCREWYOU3_HOOK(SmartTemplateCell, )
SCREWYOU3_HOOK_INIT(SmartTemplateCell)

#include <Geode/modify/SongCell.hpp>
SCREWYOU3_HOOK(SongCell, )
SCREWYOU3_HOOK_INIT(SongCell)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SongInfoLayer.hpp>
SCREWYOU3_HOOK(SongInfoLayer, gd::string p0, gd::string p1, gd::string p2, gd::string p3, gd::string p4, gd::string p5, int p6, gd::string p7, int p8)
SCREWYOU3_HOOK_INIT(SongInfoLayer, p0, p1, p2, p3, p4, p5, p6, p7, p8)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_IOS
#include <Geode/modify/SongInfoObject.hpp>
SCREWYOU3_HOOK(SongInfoObject, int songID, gd::string songName, gd::string artistName, int artistID, float filesize, gd::string youtubeVideo, gd::string youtubeChannel, gd::string url, int nongType, gd::string extraArtistIDs, bool isNew, int libraryOrder, int priority)
SCREWYOU3_HOOK_INIT(SongInfoObject, songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, nongType, extraArtistIDs, isNew, libraryOrder, priority)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/SongOptionsLayer.hpp>
SCREWYOU3_HOOK(SongOptionsLayer, CustomSongDelegate* p0)
SCREWYOU3_HOOK_INIT(SongOptionsLayer, p0)
#endif

#include <Geode/modify/SongSelectNode.hpp>
SCREWYOU3_HOOK(SongSelectNode, int p0, bool p1, LevelSettingsObject* p2, SongSelectType p3, cocos2d::CCPoint p4, cocos2d::CCNode* p5, cocos2d::CCMenu* p6, bool p7)
SCREWYOU3_HOOK_INIT(SongSelectNode, p0, p1, p2, p3, p4, p5, p6, p7)

#include <Geode/modify/SpawnParticleGameObject.hpp>
SCREWYOU3_HOOK(SpawnParticleGameObject, )
SCREWYOU3_HOOK_INIT(SpawnParticleGameObject)

#include <Geode/modify/SpawnTriggerGameObject.hpp>
SCREWYOU3_HOOK(SpawnTriggerGameObject, )
SCREWYOU3_HOOK_INIT(SpawnTriggerGameObject)

#include <Geode/modify/StarInfoPopup.hpp>
SCREWYOU3_HOOK(StarInfoPopup, int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, bool p9)
SCREWYOU3_HOOK_INIT(StarInfoPopup, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)

#include <Geode/modify/StartPosObject.hpp>
SCREWYOU3_HOOK(StartPosObject, )
SCREWYOU3_HOOK_INIT(StartPosObject)

#include <Geode/modify/TextAlertPopup.hpp>
SCREWYOU3_HOOK(TextAlertPopup, gd::string text, float delay, float scale, int opacity, gd::string font)
SCREWYOU3_HOOK_INIT(TextAlertPopup, text, delay, scale, opacity, font)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/TextArea.hpp>
SCREWYOU3_HOOK(TextArea, gd::string str, char const* font, float scale, float width, cocos2d::CCPoint anchor, float lineHeight, bool disableColor)
SCREWYOU3_HOOK_INIT(TextArea, str, font, scale, width, anchor, lineHeight, disableColor)
#endif

#include <Geode/modify/TopArtistsLayer.hpp>
SCREWYOU3_HOOK(TopArtistsLayer, )
SCREWYOU3_HOOK_INIT(TopArtistsLayer)

#include <Geode/modify/TOSPopup.hpp>
SCREWYOU3_HOOK(TOSPopup, )
SCREWYOU3_HOOK_INIT(TOSPopup)

#include <Geode/modify/TutorialLayer.hpp>
SCREWYOU3_HOOK(TutorialLayer, )
SCREWYOU3_HOOK_INIT(TutorialLayer)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/TutorialPopup.hpp>
SCREWYOU3_HOOK(TutorialPopup, gd::string p0)
SCREWYOU3_HOOK_INIT(TutorialPopup, p0)
#endif

#include <Geode/modify/UILayer.hpp>
SCREWYOU3_HOOK(UILayer, GJBaseGameLayer* p0)
SCREWYOU3_HOOK_INIT(UILayer, p0)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/UIObjectSettingsPopup.hpp>
SCREWYOU3_HOOK(UIObjectSettingsPopup, UISettingsGameObject* p0, cocos2d::CCArray* p1)
SCREWYOU3_HOOK_INIT(UIObjectSettingsPopup, p0, p1)
#endif

#include <Geode/modify/UIOptionsLayer.hpp>
SCREWYOU3_HOOK(UIOptionsLayer, bool p0)
SCREWYOU3_HOOK_INIT(UIOptionsLayer, p0)

#include <Geode/modify/UIPOptionsLayer.hpp>
SCREWYOU3_HOOK(UIPOptionsLayer, )
SCREWYOU3_HOOK_INIT(UIPOptionsLayer)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/UISaveLoadLayer.hpp>
SCREWYOU3_HOOK(UISaveLoadLayer, UIOptionsLayer* p0)
SCREWYOU3_HOOK_INIT(UISaveLoadLayer, p0)
#endif

#include <Geode/modify/UISettingsGameObject.hpp>
SCREWYOU3_HOOK(UISettingsGameObject, )
SCREWYOU3_HOOK_INIT(UISettingsGameObject)

#include <Geode/modify/UpdateAccountSettingsPopup.hpp>
SCREWYOU3_HOOK(UpdateAccountSettingsPopup, GJAccountSettingsLayer* p0, int p1, int p2, int p3, gd::string p4, gd::string p5, gd::string p6)
SCREWYOU3_HOOK_INIT(UpdateAccountSettingsPopup, p0, p1, p2, p3, p4, p5, p6)

#include <Geode/modify/UploadActionPopup.hpp>
SCREWYOU3_HOOK(UploadActionPopup, UploadPopupDelegate* delegate, gd::string str)
SCREWYOU3_HOOK_INIT(UploadActionPopup, delegate, str)


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/UploadListPopup.hpp>
SCREWYOU3_HOOK(UploadListPopup, GJLevelList* p0)
SCREWYOU3_HOOK_INIT(UploadListPopup, p0)
#endif


#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/UploadPopup.hpp>
SCREWYOU3_HOOK(UploadPopup, GJGameLevel* p0)
SCREWYOU3_HOOK_INIT(UploadPopup, p0)
#endif

#include <Geode/modify/URLCell.hpp>
SCREWYOU3_HOOK(URLCell, )
SCREWYOU3_HOOK_INIT(URLCell)

#include <Geode/modify/VideoOptionsLayer.hpp>
SCREWYOU3_HOOK(VideoOptionsLayer, )
SCREWYOU3_HOOK_INIT(VideoOptionsLayer)


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/WorldLevelPage.hpp>
SCREWYOU3_HOOK(WorldLevelPage, GJGameLevel* p0, GJWorldNode* p1)
SCREWYOU3_HOOK_INIT(WorldLevelPage, p0, p1)
#endif


#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
#include <Geode/modify/WorldSelectLayer.hpp>
SCREWYOU3_HOOK(WorldSelectLayer, int p0)
SCREWYOU3_HOOK_INIT(WorldSelectLayer, p0)
#endif

