// Generated using 'generate.py'
#include <map>
#include <string>

using ScrewYouFuncsT = std::map<std::string, std::vector<std::string>>;

template<typename K, typename V>
constexpr void addToMap(std::map<K, V>& map, std::string clazz, std::string func) {
    if (map.contains(clazz)) {
        map.at(clazz).push_back(func);
	} else {
		std::vector<std::string> toInsert;
		toInsert.push_back(func);
        map[clazz] = toInsert;
	}
}

constexpr ScrewYouFuncsT getFuncs() {
    ScrewYouFuncsT classes;
    
	addToMap(classes, "AccountLoginLayer", "init");
	addToMap(classes, "AccountRegisterLayer", "init");
	addToMap(classes, "AccountRegisterLayer", "allowTextInput");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AccountRegisterLayer", "validEmail");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AccountRegisterLayer", "validPassword");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AccountRegisterLayer", "validUser");
	#endif
	addToMap(classes, "AchievementBar", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "AchievementCell", "init");
	#endif
	addToMap(classes, "AchievementManager", "init");
	addToMap(classes, "AchievementManager", "achievementForUnlock");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AchievementManager", "areAchievementsEarned");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AchievementManager", "isAchievementAvailable");
	#endif
	addToMap(classes, "AchievementManager", "isAchievementEarned");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "AchievementManager", "limitForAchievement");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AchievementManager", "percentageForCount");
	#endif
	addToMap(classes, "AchievementManager", "percentForAchievement");
	addToMap(classes, "AchievementNotifier", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AdToolbox", "hasCachedInterstitial");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AdToolbox", "hasCachedRewardedVideo");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AdToolbox", "isShowingAd");
	#endif
	addToMap(classes, "AdvancedFollowEditObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AdvancedFollowEditObject", "init");
	#endif
	addToMap(classes, "AdvancedFollowTriggerObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "AdvancedFollowTriggerObject", "getAdvancedFollowID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AdvancedFollowTriggerObject", "init");
	#endif
	addToMap(classes, "AnimatedGameObject", "animationForID");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AnimatedGameObject", "getTweenTime");
	#endif
	addToMap(classes, "AnimatedGameObject", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "AnimatedShopKeeper", "init");
	#endif
	addToMap(classes, "AppDelegate", "applicationDidFinishLaunching");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "AppDelegate", "bgScale");
	#endif
	addToMap(classes, "AppDelegate", "musicTest");
	addToMap(classes, "ArtistCell", "init");
	addToMap(classes, "ArtTriggerGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ArtTriggerGameObject", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "AudioAssetsBrowser", "cellPerformedAction");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "AudioAssetsBrowser", "getSelectedCellIdx");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "AudioAssetsBrowser", "getCellDelegateType");
	#endif
	addToMap(classes, "AudioAssetsBrowser", "init");
	addToMap(classes, "AudioEffectsLayer", "init");
	addToMap(classes, "AudioLineGuideGameObject", "init");
	addToMap(classes, "AudioLineGuideGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "BitmapFontCache", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "BonusDropdown", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "BoomListLayer", "init");
	#endif
	addToMap(classes, "BoomListView", "cellHeightForRowAtIndexPath");
	addToMap(classes, "BoomListView", "numberOfRowsInSection");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "BoomListView", "numberOfSectionsInTableView");
	#endif
	addToMap(classes, "BoomListView", "init");
	addToMap(classes, "BoomScrollLayer", "ccTouchBegan");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "BoomScrollLayer", "getRelativePageForNum");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "BoomScrollLayer", "getTotalPages");
	#endif
	addToMap(classes, "BoomScrollLayer", "init");
	addToMap(classes, "BoomScrollLayer", "pageNumberForPosition");
	addToMap(classes, "BrowseSmartKeyLayer", "init");
	addToMap(classes, "BrowseSmartTemplateLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "ButtonPage", "init");
	#endif
	addToMap(classes, "ButtonSprite", "init");
	addToMap(classes, "ButtonSprite", "init");
	addToMap(classes, "CameraTriggerGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CameraTriggerGameObject", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCAlertCircle", "init");
	#endif
	addToMap(classes, "CCAnimatedSprite", "initWithType");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "CCAnimateFrameCache", "init");
	#endif
	addToMap(classes, "CCBlockLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "CCBlockLayer", "ccTouchBegan");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCCircleAlert", "init");
	#endif
	addToMap(classes, "CCCircleWave", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCCountdown", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCCounterLabel", "getTargetCount");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "CCCounterLabel", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "CCLightFlash", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "CCLightStrip", "init");
	#endif
	addToMap(classes, "CCMenuItemSpriteExtra", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "CCMenuItemToggler", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCMoveCNode", "init");
	#endif
	addToMap(classes, "CCNodeContainer", "init");
	addToMap(classes, "CCPartAnimSprite", "isFrameDisplayed");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCPartAnimSprite", "countParts");
	#endif
	addToMap(classes, "CCPartAnimSprite", "initWithAnimDesc");
	addToMap(classes, "CCScrollLayerExt", "ccTouchBegan");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "CCScrollLayerExt", "getMaxY");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCScrollLayerExt", "getMinY");
	#endif
	addToMap(classes, "CCSpriteGrayscale", "getShaderName");
	addToMap(classes, "CCSpriteGrayscale", "shaderBody");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCSpritePart", "getBeingUsed");
	#endif
	addToMap(classes, "CCSpritePlus", "initWithTexture");
	addToMap(classes, "CCSpritePlus", "initWithSpriteFrameName");
	addToMap(classes, "CCSpriteWithHue", "initWithTexture");
	addToMap(classes, "CCSpriteWithHue", "initWithTexture");
	addToMap(classes, "CCSpriteWithHue", "initWithTexture");
	addToMap(classes, "CCSpriteWithHue", "initWithSpriteFrame");
	addToMap(classes, "CCSpriteWithHue", "getShaderName");
	addToMap(classes, "CCSpriteWithHue", "shaderBody");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCSpriteWithHue", "getAlpha");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCSpriteWithHue", "getHue");
	#endif
	addToMap(classes, "CCTextInputNode", "ccTouchBegan");
	addToMap(classes, "CCTextInputNode", "onTextFieldInsertText");
	addToMap(classes, "CCTextInputNode", "onTextFieldAttachWithIME");
	addToMap(classes, "CCTextInputNode", "onTextFieldDetachWithIME");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "CCTextInputNode", "getString");
	#endif
	addToMap(classes, "CCTextInputNode", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCURLObject", "init");
	#endif
	addToMap(classes, "ChallengeNode", "init");
	addToMap(classes, "ChallengesPage", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ChanceTriggerGameObject", "containsTargetID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ChanceTriggerGameObject", "init");
	#endif
	addToMap(classes, "CharacterColorPage", "init");
	addToMap(classes, "CharacterColorPage", "activeColorForMode");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "CharacterColorPage", "checkColor");
	#endif
	addToMap(classes, "CharacterColorPage", "colorForIndex");
	addToMap(classes, "CheckpointGameObject", "init");
	addToMap(classes, "CheckpointGameObject", "getSaveString");
	addToMap(classes, "CheckpointObject", "init");
	addToMap(classes, "CollisionBlockPopup", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ColorAction", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "ColorAction", "isInUse");
	#endif
	addToMap(classes, "ColorActionSprite", "init");
	addToMap(classes, "ColorChannelSprite", "init");
	addToMap(classes, "ColorSelectLiveOverlay", "init");
	addToMap(classes, "ColorSelectPopup", "colorToHex");
	addToMap(classes, "ColorSelectPopup", "init");
	addToMap(classes, "CommentCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CommunityCreditNode", "init");
	#endif
	addToMap(classes, "CommunityCreditsPage", "init");
	addToMap(classes, "ConfigureHSVWidget", "init");
	addToMap(classes, "ConfigureValuePopup", "init");
	addToMap(classes, "CountTriggerGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CountTriggerGameObject", "init");
	#endif
	addToMap(classes, "CreateGuidelinesLayer", "ccTouchBegan");
	addToMap(classes, "CreateGuidelinesLayer", "getMergedRecordString");
	addToMap(classes, "CreateGuidelinesLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CreateMenuItem", "init");
	#endif
	addToMap(classes, "CreateParticlePopup", "ccTouchBegan");
	addToMap(classes, "CreateParticlePopup", "init");
	addToMap(classes, "CreateParticlePopup", "maxSliderValueForType");
	addToMap(classes, "CreateParticlePopup", "minSliderValueForType");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CreateParticlePopup", "particleValueIsInt");
	#endif
	addToMap(classes, "CreateParticlePopup", "titleForParticleValue");
	addToMap(classes, "CreateParticlePopup", "valueForParticleValue");
	addToMap(classes, "CreatorLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CreatorLayer", "canPlayOnlineLevels");
	#endif
	addToMap(classes, "CurrencyRewardLayer", "init");
	addToMap(classes, "CurrencySprite", "spriteTypeToStat");
	addToMap(classes, "CurrencySprite", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "CurrencySprite", "initWithSprite");
	#endif
	addToMap(classes, "CustomizeObjectLayer", "getActiveMode");
	addToMap(classes, "CustomizeObjectLayer", "init");
	addToMap(classes, "CustomizeObjectSettingsPopup", "init");
	addToMap(classes, "CustomListView", "getCellHeight");
	addToMap(classes, "CustomSFXCell", "init");
	addToMap(classes, "CustomSFXCell", "getActiveSFXID");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CustomSFXCell", "shouldReload");
	#endif
	addToMap(classes, "CustomSFXWidget", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CustomSFXWidget", "verifySFXID");
	#endif
	addToMap(classes, "CustomSongCell", "init");
	addToMap(classes, "CustomSongCell", "getActiveSongID");
	addToMap(classes, "CustomSongCell", "getSongFileName");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CustomSongCell", "shouldReload");
	#endif
	addToMap(classes, "CustomSongLayer", "init");
	addToMap(classes, "CustomSongWidget", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CustomSongWidget", "verifySongID");
	#endif
	addToMap(classes, "DailyLevelNode", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "DailyLevelPage", "getDailyTime");
	#endif
	addToMap(classes, "DailyLevelPage", "getDailyTimeString");
	addToMap(classes, "DailyLevelPage", "init");
	addToMap(classes, "DashRingObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "DashRingObject", "init");
	#endif
	addToMap(classes, "DemonFilterSelectLayer", "init");
	addToMap(classes, "DemonInfoPopup", "init");
	addToMap(classes, "DialogLayer", "ccTouchBegan");
	addToMap(classes, "DialogLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "DialogObject", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "DrawGridLayer", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "DrawGridLayer", "timeForPos");
	#endif
	addToMap(classes, "DungeonBarsSprite", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EditButtonBar", "getPage");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EditButtonBar", "init");
	#endif
	addToMap(classes, "EditGameObjectPopup", "init");
	addToMap(classes, "EditLevelLayer", "init");
	addToMap(classes, "EditorOptionsLayer", "init");
	addToMap(classes, "EditorPauseLayer", "init");
	addToMap(classes, "EditorUI", "getRandomStartKey");
	addToMap(classes, "EditorUI", "getSmartObjectKey");
	addToMap(classes, "EditorUI", "smartTypeForKey");
	addToMap(classes, "EditorUI", "ccTouchBegan");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EditorUI", "arrayContainsClass");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EditorUI", "canAllowMultiActivate");
	#endif
	addToMap(classes, "EditorUI", "canSelectObject");
	addToMap(classes, "EditorUI", "convertKeyBasedOnNeighbors");
	addToMap(classes, "EditorUI", "convertToBaseKey");
	addToMap(classes, "EditorUI", "copyObjects");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EditorUI", "copyObjectsDetailed");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EditorUI", "edgeForObject");
	#endif
	addToMap(classes, "EditorUI", "editButton2Usable");
	addToMap(classes, "EditorUI", "editButtonUsable");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "EditorUI", "editColorButtonUsable");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EditorUI", "editorLayerForArray");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EditorUI", "getSnapAngle");
	#endif
	addToMap(classes, "EditorUI", "getXMin");
	addToMap(classes, "EditorUI", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "EditorUI", "isLiveColorSelectTrigger");
	#endif
	addToMap(classes, "EditorUI", "isSpecialSnapObject");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "EditorUI", "liveEditColorUsable");
	#endif
	addToMap(classes, "EditorUI", "onCreate");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EditorUI", "positionIsInSnapped");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "EditorUI", "rotationforCommand");
	#endif
	addToMap(classes, "EditorUI", "shouldDeleteObject");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "EditorUI", "shouldSnap");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EditorUI", "valueFromXPos");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EditorUI", "xPosFromValue");
	#endif
	addToMap(classes, "EditTriggersPopup", "init");
	addToMap(classes, "EffectGameObject", "getSaveString");
	addToMap(classes, "EffectGameObject", "spawnXPosition");
	addToMap(classes, "EffectGameObject", "canReverse");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EffectGameObject", "isSpecialSpawnObject");
	#endif
	addToMap(classes, "EffectGameObject", "canBeOrdered");
	addToMap(classes, "EffectGameObject", "canSpawnTriggers");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "EffectGameObject", "getTargetColorIndex");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "EffectGameObject", "hasSpawnTargetID");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "EffectGameObject", "init");
	#endif
	addToMap(classes, "EndLevelLayer", "getCoinString");
	addToMap(classes, "EndLevelLayer", "getEndText");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "EndLevelLayer", "init");
	#endif
	addToMap(classes, "EndPortalObject", "init");
	addToMap(classes, "EndTriggerGameObject", "init");
	addToMap(classes, "EndTriggerGameObject", "getSaveString");
	addToMap(classes, "EnhancedGameObject", "getSaveString");
	addToMap(classes, "EnhancedGameObject", "hasBeenActivatedByPlayer");
	addToMap(classes, "EnhancedGameObject", "hasBeenActivated");
	addToMap(classes, "EnhancedGameObject", "canAllowMultiActivate");
	addToMap(classes, "EnhancedGameObject", "getHasSyncedAnimation");
	addToMap(classes, "EnhancedGameObject", "getHasRotateAction");
	addToMap(classes, "EnhancedGameObject", "canMultiActivate");
	addToMap(classes, "EnhancedGameObject", "init");
	addToMap(classes, "EnhancedTriggerObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "EnhancedTriggerObject", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "EnterEffectInstance", "getValue");
	#endif
	addToMap(classes, "EnterEffectObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "EnterEffectObject", "init");
	#endif
	addToMap(classes, "EventLinkTrigger", "init");
	addToMap(classes, "EventLinkTrigger", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "ExplodeItemNode", "init");
	#endif
	addToMap(classes, "ExplodeItemSprite", "init");
	addToMap(classes, "ExtendedLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "FileOperation", "getFilePath");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "FileSaveManager", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "FindBPMLayer", "init");
	#endif
	addToMap(classes, "FindObjectPopup", "init");
	addToMap(classes, "FLAlertLayer", "ccTouchBegan");
	addToMap(classes, "FLAlertLayer", "init");
	addToMap(classes, "FLAlertLayer", "init");
	addToMap(classes, "FMODAudioEngine", "pitchForIdx");
	addToMap(classes, "FMODAudioEngine", "reverbToString");
	addToMap(classes, "FMODAudioEngine", "channelIDForUniqueID");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "FMODAudioEngine", "countActiveEffects");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "FMODAudioEngine", "countActiveMusic");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "FMODAudioEngine", "getActiveMusic");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "FMODAudioEngine", "getBackgroundMusicVolume");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "FMODAudioEngine", "getEffectsVolume");
	#endif
	addToMap(classes, "FMODAudioEngine", "getFMODStatus");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "FMODAudioEngine", "getMeteringValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "FMODAudioEngine", "getMusicChannelID");
	#endif
	addToMap(classes, "FMODAudioEngine", "getMusicLengthMS");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "FMODAudioEngine", "getMusicTime");
	#endif
	addToMap(classes, "FMODAudioEngine", "getMusicTimeMS");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "FMODAudioEngine", "getNextChannelID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "FMODAudioEngine", "isAnyPersistentPlaying");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "FMODAudioEngine", "isChannelStopping");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "FMODAudioEngine", "isEffectLoaded");
	#endif
	addToMap(classes, "FMODAudioEngine", "isMusicPlaying");
	addToMap(classes, "FMODAudioEngine", "isMusicPlaying");
	addToMap(classes, "FMODAudioEngine", "isPersistentMatchPlaying");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "FMODAudioEngine", "isSoundReady");
	#endif
	addToMap(classes, "FMODAudioEngine", "lengthForSound");
	addToMap(classes, "FMODAudioEngine", "playEffect");
	addToMap(classes, "FMODAudioEngine", "playEffect");
	addToMap(classes, "FMODAudioEngine", "playEffectAdvanced");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "FMODAudioEngine", "playEffectAsync");
	#endif
	addToMap(classes, "FMODAudioEngine", "queuePlayEffect");
	addToMap(classes, "FMODAudioEngine", "registerChannel");
	addToMap(classes, "FMODAudioEngine", "stopAndGetFade");
	addToMap(classes, "FMODLevelVisualizer", "init");
	addToMap(classes, "FollowRewardPage", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "FontObject", "getFontWidth");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "FontObject", "initWithConfigFile");
	#endif
	addToMap(classes, "ForceBlockGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ForceBlockGameObject", "init");
	#endif
	addToMap(classes, "FRequestProfilePage", "init");
	addToMap(classes, "FRequestProfilePage", "isCorrect");
	addToMap(classes, "FriendRequestPopup", "init");
	addToMap(classes, "FriendsProfilePage", "init");
	addToMap(classes, "GameCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameEffectsManager", "init");
	#endif
	addToMap(classes, "GameLevelManager", "init");
	addToMap(classes, "GameLevelManager", "acceptFriendRequest");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "accountIDForUserID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "areGauntletsLoaded");
	#endif
	addToMap(classes, "GameLevelManager", "blockUser");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "createPageInfo");
	#endif
	addToMap(classes, "GameLevelManager", "deleteFriendRequests");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "deleteSentFriendRequest");
	#endif
	addToMap(classes, "GameLevelManager", "deleteUserMessages");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getAccountCommentKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getActiveDailyID");
	#endif
	addToMap(classes, "GameLevelManager", "getBasePostString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getBoolForKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getCommentKey");
	#endif
	addToMap(classes, "GameLevelManager", "getCompletedDailyLevels");
	addToMap(classes, "GameLevelManager", "getCompletedEventLevels");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getCompletedGauntletDemons");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getCompletedGauntletLevels");
	#endif
	addToMap(classes, "GameLevelManager", "getCompletedWeeklyLevels");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getDailyID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getDailyTimer");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getDeleteCommentKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getDeleteMessageKey");
	#endif
	addToMap(classes, "GameLevelManager", "getDemonLevelsString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getDescKey");
	#endif
	addToMap(classes, "GameLevelManager", "getDifficultyStr");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getDiffKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getDiffVal");
	#endif
	addToMap(classes, "GameLevelManager", "getFolderName");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getFriendRequestKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getGauntletKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getGauntletSearchKey");
	#endif
	addToMap(classes, "GameLevelManager", "getGJChallenges");
	addToMap(classes, "GameLevelManager", "getGJDailyLevelState");
	addToMap(classes, "GameLevelManager", "getGJRewards");
	addToMap(classes, "GameLevelManager", "getGJSecretReward");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getHighestLevelOrder");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getIntForKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getLeaderboardKey");
	#endif
	addToMap(classes, "GameLevelManager", "getLengthStr");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getLenKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getLenVal");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getLevelDownloadKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getLevelKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getLevelLeaderboardKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getLevelListKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getLikeAccountItemKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getLikeItemKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getLowestLevelOrder");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getMapPackKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getMessageKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getMessagesKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getNextFreeTemplateID");
	#endif
	addToMap(classes, "GameLevelManager", "getNextLevelName");
	addToMap(classes, "GameLevelManager", "getPageInfo");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getPostCommentKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getRateStarsKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getReportKey");
	#endif
	addToMap(classes, "GameLevelManager", "getSplitIntFromKey");
	addToMap(classes, "GameLevelManager", "getStarLevelsString");
	addToMap(classes, "GameLevelManager", "getTimeLeft");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "getTopArtistsKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getUploadMessageKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "getUserInfoKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "hasDailyStateBeenLoaded");
	#endif
	addToMap(classes, "GameLevelManager", "hasDownloadedLevel");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "hasDownloadedList");
	#endif
	addToMap(classes, "GameLevelManager", "hasLikedAccountItem");
	addToMap(classes, "GameLevelManager", "hasLikedItem");
	addToMap(classes, "GameLevelManager", "hasLikedItemFullCheck");
	addToMap(classes, "GameLevelManager", "hasRatedDemon");
	addToMap(classes, "GameLevelManager", "hasRatedLevelStars");
	addToMap(classes, "GameLevelManager", "hasReportedLevel");
	addToMap(classes, "GameLevelManager", "isDLActive");
	addToMap(classes, "GameLevelManager", "isFollowingUser");
	addToMap(classes, "GameLevelManager", "isTimeValid");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "isUpdateValid");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "itemIDFromLikeKey");
	#endif
	addToMap(classes, "GameLevelManager", "keyHasTimer");
	addToMap(classes, "GameLevelManager", "levelIDFromCommentKey");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "levelIDFromPostCommentKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "likeFromLikeKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "pageFromCommentKey");
	#endif
	addToMap(classes, "GameLevelManager", "rateDemon");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "rateLevelAdmin");
	#endif
	addToMap(classes, "GameLevelManager", "removeFriend");
	addToMap(classes, "GameLevelManager", "requestUserAccess");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "setLevelStars");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameLevelManager", "specialFromLikeKey");
	#endif
	addToMap(classes, "GameLevelManager", "tryGetUsername");
	addToMap(classes, "GameLevelManager", "unblockUser");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "unrateLevelAdmin");
	#endif
	addToMap(classes, "GameLevelManager", "updateDescription");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "updateLevelRankAdmin");
	#endif
	addToMap(classes, "GameLevelManager", "uploadFriendRequest");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelManager", "userIDForAccountID");
	#endif
	addToMap(classes, "GameLevelManager", "userNameForUserID");
	addToMap(classes, "GameLevelManager", "verifyContainerOnlyHasLevels");
	addToMap(classes, "GameLevelManager", "writeSpecialFilters");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameLevelOptionsLayer", "init");
	#endif
	addToMap(classes, "GameManager", "init");
	addToMap(classes, "GameManager", "activeIconForType");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "canShowRewardedVideo");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "colorForPos");
	#endif
	addToMap(classes, "GameManager", "colorKey");
	addToMap(classes, "GameManager", "countForType");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "defaultFrameForAnimation");
	#endif
	addToMap(classes, "GameManager", "dpadConfigToString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "framesForAnimation");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "frameTimeForAnimation");
	#endif
	addToMap(classes, "GameManager", "generateSecretNumber");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameManager", "getBGTexture");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameManager", "getFontFile");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameManager", "getFontTexture");
	#endif
	addToMap(classes, "GameManager", "getGameVariable");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameManager", "getGTexture");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameManager", "getIconRequestID");
	#endif
	addToMap(classes, "GameManager", "getIntGameVariable");
	addToMap(classes, "GameManager", "getMenuMusicFile");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameManager", "getMGTexture");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameManager", "getNextUniqueObjectKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameManager", "getNextUsedKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameManager", "getPracticeMusicFile");
	#endif
	addToMap(classes, "GameManager", "getUGV");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "groundHasSecondaryColor");
	#endif
	addToMap(classes, "GameManager", "iconKey");
	addToMap(classes, "GameManager", "isColorUnlocked");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameManager", "isIconLoaded");
	#endif
	addToMap(classes, "GameManager", "isIconUnlocked");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "keyForIcon");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "levelIsPremium");
	#endif
	addToMap(classes, "GameManager", "playSFXTrigger");
	addToMap(classes, "GameManager", "reorderKey");
	addToMap(classes, "GameManager", "safePopScene");
	addToMap(classes, "GameManager", "sheetNameForIcon");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "shouldShowInterstitial");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "showInterstitial");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "showInterstitialForced");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "showMainMenuAd");
	#endif
	addToMap(classes, "GameManager", "stringForCustomObject");
	addToMap(classes, "GameManager", "toggleGameVariable");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "isBasicEnterEffect");
	#endif
	addToMap(classes, "GameObject", "initWithTexture");
	addToMap(classes, "GameObject", "getSaveString");
	addToMap(classes, "GameObject", "isFlipX");
	addToMap(classes, "GameObject", "isFlipY");
	addToMap(classes, "GameObject", "getRScaleX");
	addToMap(classes, "GameObject", "getRScaleY");
	addToMap(classes, "GameObject", "getObjectRotation");
	addToMap(classes, "GameObject", "addToGroup");
	addToMap(classes, "GameObject", "spawnXPosition");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "shouldDrawEditorHitbox");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "belongsToGroup");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "canChangeCustomColor");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "canChangeMainColor");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "canChangeSecondaryColor");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "canRotateFree");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameObject", "didScaleXChange");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameObject", "didScaleYChange");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameObject", "dontCountTowardsLimit");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "getBallFrame");
	#endif
	addToMap(classes, "GameObject", "getColorFrame");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "getColorIndex");
	#endif
	addToMap(classes, "GameObject", "getColorKey");
	addToMap(classes, "GameObject", "getGlowFrame");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "getGroupDisabled");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "getGroupID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "getGroupString");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "getMainColorMode");
	#endif
	addToMap(classes, "GameObject", "getObjectDirection");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "getObjectRadius");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "getObjectZOrder");
	#endif
	addToMap(classes, "GameObject", "getParentMode");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "getSecondaryColorMode");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "getSlopeAngle");
	#endif
	addToMap(classes, "GameObject", "groupOpacityMod");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "hasSecondaryColor");
	#endif
	addToMap(classes, "GameObject", "ignoreEditorDuration");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "ignoreEnter");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "ignoreFade");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "init");
	#endif
	addToMap(classes, "GameObject", "isBasicTrigger");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "isColorObject");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "isColorTrigger");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "isConfigurablePortal");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "isEditorSpawnableTrigger");
	#endif
	addToMap(classes, "GameObject", "isFacingDown");
	addToMap(classes, "GameObject", "isFacingLeft");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "isSettingsObject");
	#endif
	addToMap(classes, "GameObject", "isSpawnableTrigger");
	addToMap(classes, "GameObject", "isSpecialObject");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "isSpeedObject");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "isStoppableTrigger");
	#endif
	addToMap(classes, "GameObject", "isTrigger");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "opacityModForMode");
	#endif
	addToMap(classes, "GameObject", "perspectiveColorFrame");
	addToMap(classes, "GameObject", "perspectiveFrame");
	addToMap(classes, "GameObject", "shouldBlendColor");
	addToMap(classes, "GameObject", "shouldLockX");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameObject", "shouldNotHideAnimFreeze");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "shouldShowPickupEffects");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "slopeFloorTop");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "slopeWallLeft");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameObject", "slopeYPos");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "slopeYPos");
	#endif
	addToMap(classes, "GameObject", "slopeYPos");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "usesFreezeAnimation");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObject", "usesSpecialAnimation");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameObjectCopy", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameOptionsLayer", "init");
	#endif
	addToMap(classes, "GameOptionsTrigger", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameOptionsTrigger", "init");
	#endif
	addToMap(classes, "GameStatsManager", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "accountIDForIcon");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "areChallengesLoaded");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "areRewardsLoaded");
	#endif
	addToMap(classes, "GameStatsManager", "awardSecretKey");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameStatsManager", "canItemBeUnlocked");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "claimListReward");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "countSecretChests");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "countUnlockedSecretChests");
	#endif
	addToMap(classes, "GameStatsManager", "getAwardedCurrencyForLevel");
	addToMap(classes, "GameStatsManager", "getAwardedDiamondsForLevel");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getBaseCurrency");
	#endif
	addToMap(classes, "GameStatsManager", "getBaseCurrencyForLevel");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getBaseDiamonds");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getBonusDiamonds");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getChallengeKey");
	#endif
	addToMap(classes, "GameStatsManager", "getCollectedCoinsForLevel");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getCurrencyKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getDailyLevelKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getDemonLevelKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameStatsManager", "getEventRewardKey");
	#endif
	addToMap(classes, "GameStatsManager", "getGauntletRewardKey");
	addToMap(classes, "GameStatsManager", "getItemKey");
	addToMap(classes, "GameStatsManager", "getItemUnlockState");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameStatsManager", "getItemUnlockStateLite");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getLevelKey");
	#endif
	addToMap(classes, "GameStatsManager", "getLevelKey");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getListRewardKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameStatsManager", "getMapPackKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getNextGoldChestID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameStatsManager", "getNextVideoAdReward");
	#endif
	addToMap(classes, "GameStatsManager", "getPathRewardKey");
	addToMap(classes, "GameStatsManager", "getRewardKey");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getSecretChestForItem");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameStatsManager", "getSecretCoinKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getSecretOnlineRewardKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getSpecialRewardDescription");
	#endif
	addToMap(classes, "GameStatsManager", "getSpecialUnlockDescription");
	addToMap(classes, "GameStatsManager", "getStat");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "getStatFromKey");
	#endif
	addToMap(classes, "GameStatsManager", "getTotalCollectedCurrency");
	addToMap(classes, "GameStatsManager", "getTotalCollectedDiamonds");
	addToMap(classes, "GameStatsManager", "hasClaimedListReward");
	addToMap(classes, "GameStatsManager", "hasCompletedChallenge");
	addToMap(classes, "GameStatsManager", "hasCompletedDailyLevel");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "hasCompletedDemonLevel");
	#endif
	addToMap(classes, "GameStatsManager", "hasCompletedGauntletLevel");
	addToMap(classes, "GameStatsManager", "hasCompletedLevel");
	addToMap(classes, "GameStatsManager", "hasCompletedMainLevel");
	addToMap(classes, "GameStatsManager", "hasCompletedMapPack");
	addToMap(classes, "GameStatsManager", "hasCompletedOnlineLevel");
	addToMap(classes, "GameStatsManager", "hasCompletedStarLevel");
	addToMap(classes, "GameStatsManager", "hasPendingUserCoin");
	addToMap(classes, "GameStatsManager", "hasRewardBeenCollected");
	addToMap(classes, "GameStatsManager", "hasSecretCoin");
	addToMap(classes, "GameStatsManager", "hasUserCoin");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "isGauntletChestUnlocked");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "isGauntletUnlocked");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "isItemEnabled");
	#endif
	addToMap(classes, "GameStatsManager", "isItemUnlocked");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "isPathChestUnlocked");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameStatsManager", "isPathUnlocked");
	#endif
	addToMap(classes, "GameStatsManager", "isSecretChestUnlocked");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameStatsManager", "isSecretCoin");
	#endif
	addToMap(classes, "GameStatsManager", "isSecretCoinValid");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameStatsManager", "isSpecialChestLiteUnlockable");
	#endif
	addToMap(classes, "GameStatsManager", "isSpecialChestUnlocked");
	addToMap(classes, "GameStatsManager", "isStoreItemUnlocked");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "keyCostForSecretChest");
	#endif
	addToMap(classes, "GameStatsManager", "purchaseItem");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameStatsManager", "shouldAwardSecretKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "starsForMapPack");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameStatsManager", "usernameForAccountID");
	#endif
	addToMap(classes, "GameToolbox", "bounceTime");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameToolbox", "createHashString");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameToolbox", "doWeHaveInternet");
	#endif
	addToMap(classes, "GameToolbox", "easeToText");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameToolbox", "fast_rand");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameToolbox", "fast_rand_0_1");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameToolbox", "fast_rand_minus1_1");
	#endif
	addToMap(classes, "GameToolbox", "gen_random");
	addToMap(classes, "GameToolbox", "getEasedValue");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameToolbox", "getfast_srand");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameToolbox", "getInvertedEasing");
	#endif
	addToMap(classes, "GameToolbox", "getResponse");
	addToMap(classes, "GameToolbox", "getTimeString");
	addToMap(classes, "GameToolbox", "intToShortString");
	addToMap(classes, "GameToolbox", "intToString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameToolbox", "isIOS");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GameToolbox", "isRateEasing");
	#endif
	addToMap(classes, "GameToolbox", "msToTimeString");
	addToMap(classes, "GameToolbox", "pointsToString");
	addToMap(classes, "GameToolbox", "saveParticleToString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameToolbox", "saveStringToFile");
	#endif
	addToMap(classes, "GameToolbox", "stringFromHSV");
	addToMap(classes, "GameToolbox", "timestampToHumanReadable");
	addToMap(classes, "GauntletLayer", "init");
	addToMap(classes, "GauntletNode", "frameForType");
	addToMap(classes, "GauntletNode", "nameForType");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GauntletNode", "init");
	#endif
	addToMap(classes, "GauntletSelectLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GauntletSprite", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GauntletSprite", "luminanceForType");
	#endif
	addToMap(classes, "GhostTrailEffect", "init");
	addToMap(classes, "GJAccountManager", "init");
	addToMap(classes, "GJAccountManager", "backupAccount");
	addToMap(classes, "GJAccountManager", "getAccountBackupURL");
	addToMap(classes, "GJAccountManager", "getAccountSyncURL");
	addToMap(classes, "GJAccountManager", "getShaPassword");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJAccountManager", "isDLActive");
	#endif
	addToMap(classes, "GJAccountManager", "syncAccount");
	addToMap(classes, "GJAccountManager", "updateAccountSettings");
	addToMap(classes, "GJAccountSettingsLayer", "init");
	addToMap(classes, "GJActionManager", "init");
	addToMap(classes, "GJBaseGameLayer", "convertToClosestDirection");
	addToMap(classes, "GJBaseGameLayer", "gameEventToString");
	addToMap(classes, "GJBaseGameLayer", "init");
	addToMap(classes, "GJBaseGameLayer", "opacityForObject");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "checkSpawnAbuse");
	#endif
	addToMap(classes, "GJBaseGameLayer", "addGuideArt");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "atlasValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "buttonIDToButton");
	#endif
	addToMap(classes, "GJBaseGameLayer", "buttonIsRelevant");
	addToMap(classes, "GJBaseGameLayer", "canBeActivatedByPlayer");
	addToMap(classes, "GJBaseGameLayer", "canProcessSFX");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "canTouchObject");
	#endif
	addToMap(classes, "GJBaseGameLayer", "checkCollision");
	addToMap(classes, "GJBaseGameLayer", "checkCollisions");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "countCollectedUserCoins");
	#endif
	addToMap(classes, "GJBaseGameLayer", "generateEnterEasingBuffer");
	addToMap(classes, "GJBaseGameLayer", "getAreaObjectValue");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "getBumpMod");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "getCameraEdgeValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "getCapacityString");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "getEasedAreaValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "getEnterEasingKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "getEnterEasingValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "getGroundHeight");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "getGroundHeightForMode");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "getGroupParentsString");
	#endif
	addToMap(classes, "GJBaseGameLayer", "getItemValue");
	addToMap(classes, "GJBaseGameLayer", "getMaxPortalY");
	addToMap(classes, "GJBaseGameLayer", "getMinDistance");
	addToMap(classes, "GJBaseGameLayer", "getMinPortalY");
	addToMap(classes, "GJBaseGameLayer", "getModifiedDelta");
	addToMap(classes, "GJBaseGameLayer", "getParticleKey");
	addToMap(classes, "GJBaseGameLayer", "getParticleKey2");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "getPlayerButtonID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "getPlayTimerFullSeconds");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "getPlayTimerMilli");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "getRecordExtra");
	#endif
	addToMap(classes, "GJBaseGameLayer", "getRecordString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "getScaledGroundHeight");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "getSpecialKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "getTargetFlyCameraY");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "hasItem");
	#endif
	addToMap(classes, "GJBaseGameLayer", "hasUniqueCoin");
	#if defined GEODE_IS_ANDROID
	addToMap(classes, "GJBaseGameLayer", "isButtonAllowed");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "isFlipping");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "isPlayer2Button");
	#endif
	addToMap(classes, "GJBaseGameLayer", "maxZOrderForShaderZ");
	addToMap(classes, "GJBaseGameLayer", "minZOrderForShaderZ");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "objectIntersectsCircle");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "performMathOperation");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "performMathRounding");
	#endif
	addToMap(classes, "GJBaseGameLayer", "playerCircleCollision");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "playerIntersectsCircle");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "playerWasTouchingObject");
	#endif
	addToMap(classes, "GJBaseGameLayer", "processSongState");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "rectIntersectsCircle");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "registerSpawnRemap");
	#endif
	addToMap(classes, "GJBaseGameLayer", "resetAreaObjectValues");
	addToMap(classes, "GJBaseGameLayer", "shouldExitHackedLevel");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJBaseGameLayer", "shouldUseSubstepForButton");
	#endif
	addToMap(classes, "GJBaseGameLayer", "volumeForProximityEffect");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBigSprite", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBigSpriteNode", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJChallengeItem", "canEncode");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJChallengeItem", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJChestSprite", "init");
	#endif
	addToMap(classes, "GJColorSetupLayer", "init");
	addToMap(classes, "GJComment", "init");
	addToMap(classes, "GJCommentListLayer", "init");
	addToMap(classes, "GJDifficultySprite", "getDifficultyFrame");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJDifficultySprite", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJDropDownLayer", "ccTouchBegan");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJDropDownLayer", "init");
	#endif
	addToMap(classes, "GJDropDownLayer", "init");
	addToMap(classes, "GJEffectManager", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJEffectManager", "activeOpacityForIndex");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJEffectManager", "checkCollision");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJEffectManager", "colorExists");
	#endif
	addToMap(classes, "GJEffectManager", "countForItem");
	addToMap(classes, "GJEffectManager", "getPersistentStateString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJEffectManager", "getSaveString");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJEffectManager", "hasActiveDualTouch");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJEffectManager", "hasBeenTriggered");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJEffectManager", "hasPulseEffectForGroupID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJEffectManager", "isGroupEnabled");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJEffectManager", "keyForGroupIDColor");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJEffectManager", "opacityForIndex");
	#endif
	addToMap(classes, "GJEffectManager", "opacityModForGroup");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJEffectManager", "shouldBlend");
	#endif
	addToMap(classes, "GJEffectManager", "timeForItem");
	addToMap(classes, "GJEffectManager", "timerExists");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJEffectManager", "wasFollowing");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJEffectManager", "wouldCreateLoop");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJFlyGroundLayer", "init");
	#endif
	addToMap(classes, "GJFollowCommandLayer", "init");
	addToMap(classes, "GJFriendRequest", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJGameLevel", "demonIconForDifficulty");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJGameLevel", "getLengthKey");
	#endif
	addToMap(classes, "GJGameLevel", "lengthKeyToString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJGameLevel", "canEncode");
	#endif
	addToMap(classes, "GJGameLevel", "init");
	addToMap(classes, "GJGameLevel", "areCoinsVerified");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJGameLevel", "generateSettingsString");
	#endif
	addToMap(classes, "GJGameLevel", "getAudioFileName");
	addToMap(classes, "GJGameLevel", "getAverageDifficulty");
	addToMap(classes, "GJGameLevel", "getLastBuildPageForTab");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJGameLevel", "getNormalPercent");
	#endif
	addToMap(classes, "GJGameLevel", "getSongName");
	addToMap(classes, "GJGameLevel", "getUnpackedLevelDescription");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJGameLevel", "isPlatformer");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJGameLevel", "scoreVectorToString");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJGameLevel", "shouldCheatReset");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJGameLoadingLayer", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJGarageLayer", "achievementForUnlock");
	#endif
	addToMap(classes, "GJGarageLayer", "descriptionForUnlock");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJGarageLayer", "titleForUnlock");
	#endif
	addToMap(classes, "GJGarageLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJGarageLayer", "getLockFrame");
	#endif
	addToMap(classes, "GJGradientLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJGroundLayer", "getGroundY");
	#endif
	addToMap(classes, "GJGroundLayer", "init");
	addToMap(classes, "GJGroundLayer", "scaleGround");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJHttpResult", "init");
	#endif
	addToMap(classes, "GJItemIcon", "scaleForType");
	addToMap(classes, "GJItemIcon", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJLevelList", "frameForListDifficulty");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJLevelList", "canEncode");
	#endif
	addToMap(classes, "GJLevelList", "init");
	addToMap(classes, "GJLevelList", "completedLevels");
	addToMap(classes, "GJLevelList", "getUnpackedDescription");
	addToMap(classes, "GJLevelList", "hasMatchingLevels");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJLevelList", "orderForLevel");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJLevelList", "totalLevels");
	#endif
	addToMap(classes, "GJLevelScoreCell", "init");
	addToMap(classes, "GJListLayer", "init");
	addToMap(classes, "GJLocalLevelScoreCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJLocalScore", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJMapObject", "init");
	#endif
	addToMap(classes, "GJMapPack", "init");
	addToMap(classes, "GJMapPack", "completedMaps");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJMapPack", "hasCompletedMapPack");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJMapPack", "totalMaps");
	#endif
	addToMap(classes, "GJMessageCell", "init");
	addToMap(classes, "GJMessagePopup", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJMGLayer", "defaultYOffsetForBG2");
	#endif
	addToMap(classes, "GJMGLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJMGLayer", "scaleGround");
	#endif
	addToMap(classes, "GJMultiplayerManager", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJMultiplayerManager", "exitLobby");
	#endif
	addToMap(classes, "GJMultiplayerManager", "getBasePostString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJMultiplayerManager", "getLastCommentIDForGame");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJMultiplayerManager", "isDLActive");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJMultiplayerManager", "joinLobby");
	#endif
	addToMap(classes, "GJMultiplayerManager", "uploadComment");
	addToMap(classes, "GJObjectDecoder", "init");
	addToMap(classes, "GJOptionsLayer", "countForPage");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJOptionsLayer", "infoKey");
	#endif
	addToMap(classes, "GJOptionsLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJOptionsLayer", "layerKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJOptionsLayer", "objectKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJOptionsLayer", "pageKey");
	#endif
	addToMap(classes, "GJPathPage", "init");
	addToMap(classes, "GJPathRewardPopup", "init");
	addToMap(classes, "GJPathsLayer", "nameForPath");
	addToMap(classes, "GJPathsLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJPathSprite", "init");
	#endif
	addToMap(classes, "GJPFollowCommandLayer", "init");
	addToMap(classes, "GJPromoPopup", "init");
	addToMap(classes, "GJRateLevelLayer", "init");
	addToMap(classes, "GJRequestCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJRewardItem", "isShardType");
	#endif
	addToMap(classes, "GJRewardItem", "rewardItemToStat");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJRewardItem", "canEncode");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJRewardItem", "getRewardCount");
	#endif
	addToMap(classes, "GJRewardItem", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJRewardObject", "canEncode");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJRewardObject", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJRewardObject", "isSpecialType");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJRobotSprite", "init");
	#endif
	addToMap(classes, "GJRobotSprite", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJRotateCommandLayer", "init");
	#endif
	addToMap(classes, "GJRotationControl", "init");
	addToMap(classes, "GJRotationControl", "ccTouchBegan");
	addToMap(classes, "GJScaleControl", "init");
	addToMap(classes, "GJScaleControl", "ccTouchBegan");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJScaleControl", "scaleFromValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJScaleControl", "skewFromValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJScaleControl", "valueFromScale");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJScaleControl", "valueFromSkew");
	#endif
	addToMap(classes, "GJScoreCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJSearchObject", "init");
	#endif
	addToMap(classes, "GJSearchObject", "isLevelSearchObject");
	addToMap(classes, "GJShopLayer", "ccTouchBegan");
	addToMap(classes, "GJShopLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJSmartBlockPreview", "init");
	#endif
	addToMap(classes, "GJSmartBlockPreviewSprite", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJSmartPrefab", "canEncode");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJSmartPrefab", "init");
	#endif
	addToMap(classes, "GJSmartTemplate", "flipKey");
	addToMap(classes, "GJSmartTemplate", "getSimplifiedKey");
	addToMap(classes, "GJSmartTemplate", "getVerySimplifiedKey");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJSmartTemplate", "keyFromNeighbors");
	#endif
	addToMap(classes, "GJSmartTemplate", "keyFromNeighbors");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJSmartTemplate", "keyFromNeighborsOld");
	#endif
	addToMap(classes, "GJSmartTemplate", "rotateKey");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJSmartTemplate", "shouldDiscardObject");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJSmartTemplate", "smartTypeToObjectKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJSmartTemplate", "canEncode");
	#endif
	addToMap(classes, "GJSmartTemplate", "getNoCornerKey");
	addToMap(classes, "GJSmartTemplate", "getTotalChanceForPrefab");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJSmartTemplate", "init");
	#endif
	addToMap(classes, "GJSmartTemplate", "isUnrequired");
	addToMap(classes, "GJSmartTemplate", "logTemplateStatus");
	addToMap(classes, "GJSongBrowser", "init");
	addToMap(classes, "GJSongBrowser", "cellPerformedAction");
	addToMap(classes, "GJSongBrowser", "getSelectedCellIdx");
	addToMap(classes, "GJSpecialColorSelect", "textForColorIdx");
	addToMap(classes, "GJSpecialColorSelect", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJSpiderSprite", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJStoreItem", "getCurrencyKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJStoreItem", "init");
	#endif
	addToMap(classes, "GJTransformControl", "init");
	addToMap(classes, "GJTransformControl", "ccTouchBegan");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJUINode", "activeRangeTouchTest");
	#endif
	addToMap(classes, "GJUINode", "activeTouchTest");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJUINode", "getButtonScale");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GJUINode", "getOpacity");
	#endif
	addToMap(classes, "GJUINode", "init");
	addToMap(classes, "GJUINode", "touchTest");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJUnlockableItem", "init");
	#endif
	addToMap(classes, "GJUserCell", "init");
	addToMap(classes, "GJUserMessage", "init");
	addToMap(classes, "GJUserScore", "init");
	addToMap(classes, "GJUserScore", "isCurrentUser");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJWorldNode", "addDotsToLevel");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJWorldNode", "init");
	#endif
	addToMap(classes, "GJWriteMessagePopup", "init");
	addToMap(classes, "GManager", "init");
	addToMap(classes, "GManager", "getCompressedSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GManager", "getSaveString");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GManager", "tryLoadData");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "GooglePlayManager", "init");
	#endif
	addToMap(classes, "GradientTriggerObject", "init");
	addToMap(classes, "GradientTriggerObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GraphicsReloadLayer", "init");
	#endif
	addToMap(classes, "GravityEffectSprite", "init");
	addToMap(classes, "HardStreak", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "HardStreak", "normalizeAngle");
	#endif
	addToMap(classes, "HSVLiveOverlay", "init");
	addToMap(classes, "HSVWidgetPopup", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "InfoAlertButton", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "InfoLayer", "getAccountID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "InfoLayer", "getID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "InfoLayer", "getRealID");
	#endif
	addToMap(classes, "InfoLayer", "init");
	addToMap(classes, "InfoLayer", "isCorrect");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "InheritanceNode", "init");
	#endif
	addToMap(classes, "ItemInfoPopup", "nameForUnlockType");
	addToMap(classes, "ItemInfoPopup", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ItemInfoPopup", "isUnlockedByDefault");
	#endif
	addToMap(classes, "ItemTriggerGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ItemTriggerGameObject", "init");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsLayer", "init");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsLayer", "countForPage");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsLayer", "infoKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsLayer", "layerKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsLayer", "objectKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsLayer", "pageKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "KeybindingsManager", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsManager", "commandForKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsManager", "commandForKeyMods");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsManager", "commandForKeyNoMods");
	#endif
	addToMap(classes, "KeyframeAnimTriggerObject", "init");
	addToMap(classes, "KeyframeAnimTriggerObject", "getSaveString");
	addToMap(classes, "KeyframeGameObject", "init");
	addToMap(classes, "KeyframeGameObject", "getSaveString");
	addToMap(classes, "LabelGameObject", "init");
	addToMap(classes, "LabelGameObject", "getSaveString");
	addToMap(classes, "LabelGameObject", "getTextKerning");
	addToMap(classes, "LeaderboardsLayer", "init");
	addToMap(classes, "LeaderboardsLayer", "isCorrect");
	addToMap(classes, "LevelAreaInnerLayer", "init");
	addToMap(classes, "LevelAreaInnerLayer", "playStep1");
	addToMap(classes, "LevelAreaLayer", "init");
	addToMap(classes, "LevelAreaLayer", "onEnterTower");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelBrowserLayer", "ccTouchBegan");
	#endif
	addToMap(classes, "LevelBrowserLayer", "cellPerformedAction");
	addToMap(classes, "LevelBrowserLayer", "getSearchTitle");
	addToMap(classes, "LevelBrowserLayer", "init");
	addToMap(classes, "LevelBrowserLayer", "isCorrect");
	addToMap(classes, "LevelCell", "init");
	addToMap(classes, "LevelEditorLayer", "timeForPos");
	addToMap(classes, "LevelEditorLayer", "activateTriggerEffect");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelEditorLayer", "canPasteState");
	#endif
	addToMap(classes, "LevelEditorLayer", "getLastObjectX");
	addToMap(classes, "LevelEditorLayer", "getLevelString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelEditorLayer", "getLockedLayers");
	#endif
	addToMap(classes, "LevelEditorLayer", "getNextColorChannel");
	addToMap(classes, "LevelEditorLayer", "getNextFreeAreaEffectID");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelEditorLayer", "getNextFreeBlockID");
	#endif
	addToMap(classes, "LevelEditorLayer", "getNextFreeEditorLayer");
	addToMap(classes, "LevelEditorLayer", "getNextFreeEnterChannel");
	addToMap(classes, "LevelEditorLayer", "getNextFreeGradientID");
	addToMap(classes, "LevelEditorLayer", "getNextFreeGroupID");
	addToMap(classes, "LevelEditorLayer", "getNextFreeItemID");
	addToMap(classes, "LevelEditorLayer", "getNextFreeOrderChannel");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelEditorLayer", "getNextFreeSFXGroupID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelEditorLayer", "getNextFreeSFXID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelEditorLayer", "getSavedEditorPositions");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelEditorLayer", "getSectionCount");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelEditorLayer", "getSelectedEditorOrder");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelEditorLayer", "getSelectedOrderChannel");
	#endif
	addToMap(classes, "LevelEditorLayer", "getSFXIDs");
	addToMap(classes, "LevelEditorLayer", "getSongIDs");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelEditorLayer", "hasAction");
	#endif
	addToMap(classes, "LevelEditorLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelEditorLayer", "isLayerLocked");
	#endif
	addToMap(classes, "LevelEditorLayer", "rotationForSlopeNearObject");
	addToMap(classes, "LevelEditorLayer", "shouldBlend");
	addToMap(classes, "LevelEditorLayer", "tryUpdateSpeedObject");
	addToMap(classes, "LevelEditorLayer", "typeExistsAtPosition");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelEditorLayer", "validGroup");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "LevelFeatureLayer", "init");
	#endif
	addToMap(classes, "LevelInfoLayer", "cellPerformedAction");
	addToMap(classes, "LevelInfoLayer", "init");
	addToMap(classes, "LevelInfoLayer", "shouldDownloadLevel");
	addToMap(classes, "LevelLeaderboard", "init");
	addToMap(classes, "LevelLeaderboard", "isCorrect");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelListCell", "init");
	#endif
	addToMap(classes, "LevelListLayer", "cellPerformedAction");
	addToMap(classes, "LevelListLayer", "init");
	addToMap(classes, "LevelOptionsLayer", "getValue");
	addToMap(classes, "LevelOptionsLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelOptionsLayer2", "init");
	#endif
	addToMap(classes, "LevelPage", "ccTouchBegan");
	addToMap(classes, "LevelPage", "init");
	addToMap(classes, "LevelSearchLayer", "checkDiff");
	addToMap(classes, "LevelSearchLayer", "checkTime");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelSearchLayer", "getLevelLenKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelSearchLayer", "getSearchDiffKey");
	#endif
	addToMap(classes, "LevelSearchLayer", "init");
	addToMap(classes, "LevelSelectLayer", "init");
	addToMap(classes, "LevelSettingsLayer", "init");
	addToMap(classes, "LevelSettingsObject", "init");
	addToMap(classes, "LevelSettingsObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelSettingsObject", "shouldUseYSection");
	#endif
	addToMap(classes, "LevelTools", "artistForAudio");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelTools", "base64DecodeString");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelTools", "base64EncodeString");
	#endif
	addToMap(classes, "LevelTools", "fbURLForArtist");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "LevelTools", "getAudioBPM");
	#endif
	addToMap(classes, "LevelTools", "getAudioFileName");
	addToMap(classes, "LevelTools", "getAudioString");
	addToMap(classes, "LevelTools", "getAudioTitle");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "LevelTools", "getLastGameplayReversed");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelTools", "getLastGameplayRotated");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LevelTools", "getLastTimewarp");
	#endif
	addToMap(classes, "LevelTools", "nameForArtist");
	addToMap(classes, "LevelTools", "ngURLForArtist");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "LevelTools", "offsetBPMForTrack");
	#endif
	addToMap(classes, "LevelTools", "timeForPos");
	addToMap(classes, "LevelTools", "urlForAudio");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "LevelTools", "valueForSpeedMod");
	#endif
	addToMap(classes, "LevelTools", "verifyLevelIntegrity");
	addToMap(classes, "LevelTools", "ytURLForArtist");
	addToMap(classes, "LikeItemLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ListButtonBar", "getPage");
	#endif
	addToMap(classes, "ListButtonBar", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "ListButtonPage", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "ListCell", "init");
	#endif
	addToMap(classes, "LoadingCircle", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LoadingCircleSprite", "init");
	#endif
	addToMap(classes, "LoadingLayer", "getLoadingString");
	addToMap(classes, "LoadingLayer", "init");
	addToMap(classes, "LocalLevelManager", "init");
	addToMap(classes, "LocalLevelManager", "getMainLevelString");
	addToMap(classes, "LocalLevelManager", "updateLevelOrder");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "LocalLevelManager", "updateListOrder");
	#endif
	addToMap(classes, "MapPackCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MapSelectLayer", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MapSelectLayer", "ccTouchBegan");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MapSelectLayer", "checkTouchMonster");
	#endif
	addToMap(classes, "MenuGameLayer", "init");
	addToMap(classes, "MenuGameLayer", "ccTouchBegan");
	addToMap(classes, "MenuLayer", "init");
	addToMap(classes, "MessagesProfilePage", "init");
	addToMap(classes, "MessagesProfilePage", "isCorrect");
	addToMap(classes, "MoreOptionsLayer", "init");
	addToMap(classes, "MoreOptionsLayer", "countForPage");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MoreOptionsLayer", "infoKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MoreOptionsLayer", "layerKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MoreOptionsLayer", "objectKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MoreOptionsLayer", "pageKey");
	#endif
	addToMap(classes, "MoreSearchLayer", "init");
	addToMap(classes, "MoreVideoOptionsLayer", "init");
	addToMap(classes, "MoreVideoOptionsLayer", "countForPage");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MoreVideoOptionsLayer", "infoKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MoreVideoOptionsLayer", "layerKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MoreVideoOptionsLayer", "objectKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MoreVideoOptionsLayer", "pageKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MPLobbyLayer", "init");
	#endif
	addToMap(classes, "MultilineBitmapFont", "initWithFont");
	addToMap(classes, "MultilineBitmapFont", "readColorInfo");
	addToMap(classes, "MultilineBitmapFont", "stringWithMaxWidth");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MultiplayerLayer", "init");
	#endif
	addToMap(classes, "MultiTriggerPopup", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MusicArtistObject", "init");
	#endif
	addToMap(classes, "MusicBrowser", "cellPerformedAction");
	addToMap(classes, "MusicBrowser", "getSelectedCellIdx");
	addToMap(classes, "MusicBrowser", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MusicDelegateHandler", "init");
	#endif
	addToMap(classes, "MusicDownloadManager", "init");
	addToMap(classes, "MusicDownloadManager", "generateCustomContentURL");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "MusicDownloadManager", "getDownloadProgress");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "MusicDownloadManager", "getSFXDownloadProgress");
	#endif
	addToMap(classes, "MusicDownloadManager", "getSFXFolderPathForID");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MusicDownloadManager", "getSongPriority");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MusicDownloadManager", "isDLActive");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MusicDownloadManager", "isMusicLibraryLoaded");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MusicDownloadManager", "isResourceSFX");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MusicDownloadManager", "isResourceSong");
	#endif
	addToMap(classes, "MusicDownloadManager", "isRunningActionForSongID");
	addToMap(classes, "MusicDownloadManager", "isSFXDownloaded");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MusicDownloadManager", "isSFXLibraryLoaded");
	#endif
	addToMap(classes, "MusicDownloadManager", "isSongDownloaded");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "MusicDownloadManager", "nameForTagID");
	#endif
	addToMap(classes, "MusicDownloadManager", "pathForSFX");
	addToMap(classes, "MusicDownloadManager", "pathForSFXFolder");
	addToMap(classes, "MusicDownloadManager", "pathForSong");
	addToMap(classes, "MusicDownloadManager", "pathForSongFolder");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MusicSearchResult", "init");
	#endif
	addToMap(classes, "NCSInfoLayer", "init");
	addToMap(classes, "NewgroundsInfoLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "NodePoint", "init");
	#endif
	addToMap(classes, "NumberInputLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "OBB2D", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "OBB2D", "overlaps");
	#endif
	addToMap(classes, "OBB2D", "overlaps1Way");
	addToMap(classes, "ObjectControlGameObject", "init");
	addToMap(classes, "ObjectControlGameObject", "getSaveString");
	addToMap(classes, "ObjectManager", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "ObjectManager", "animLoaded");
	#endif
	addToMap(classes, "ObjectToolbox", "init");
	addToMap(classes, "ObjectToolbox", "gridNodeSizeForKey");
	addToMap(classes, "ObjectToolbox", "intKeyToFrame");
	addToMap(classes, "ObjectToolbox", "perspectiveBlockFrame");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "OptionsObject", "init");
	#endif
	addToMap(classes, "OptionsScrollLayer", "cellPerformedAction");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "OptionsScrollLayer", "init");
	#endif
	addToMap(classes, "ParentalOptionsLayer", "init");
	addToMap(classes, "ParentalOptionsLayer", "countForPage");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ParentalOptionsLayer", "infoKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ParentalOptionsLayer", "layerKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ParentalOptionsLayer", "objectKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ParentalOptionsLayer", "pageKey");
	#endif
	addToMap(classes, "ParticleGameObject", "init");
	addToMap(classes, "ParticleGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "ParticlePreviewLayer", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PauseLayer", "init");
	#endif
	addToMap(classes, "PlatformToolbox", "copyToClipboard");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlatformToolbox", "doesFileExist");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_IOS
	addToMap(classes, "PlatformToolbox", "getClipboardString");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlatformToolbox", "getRawPath");
	#endif
	addToMap(classes, "PlatformToolbox", "getUniqueUserID");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlatformToolbox", "getUserID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlatformToolbox", "isControllerConnected");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlatformToolbox", "isHD");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlatformToolbox", "isLocalPlayerAuthenticated");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlatformToolbox", "isLowMemoryDevice");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlatformToolbox", "isNetworkAvailable");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlatformToolbox", "isSignedInGooglePlay");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlatformToolbox", "shouldResumeSound");
	#endif
	addToMap(classes, "PlayerCheckpoint", "init");
	addToMap(classes, "PlayerControlGameObject", "init");
	addToMap(classes, "PlayerControlGameObject", "getSaveString");
	addToMap(classes, "PlayerFireBoostSprite", "init");
	addToMap(classes, "PlayerObject", "getObjectRotation");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayerObject", "buttonDown");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayerObject", "canStickToGround");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayerObject", "collidedWithObject");
	#endif
	addToMap(classes, "PlayerObject", "collidedWithObject");
	addToMap(classes, "PlayerObject", "collidedWithObjectInternal");
	addToMap(classes, "PlayerObject", "convertToClosestRotation");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayerObject", "destroyFromHitHead");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayerObject", "flipMod");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayerObject", "getCurrentXVelocity");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayerObject", "getModifiedSlopeYVel");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayerObject", "getOldPosition");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayerObject", "getYVelocity");
	#endif
	addToMap(classes, "PlayerObject", "handleRotatedCollisionInternal");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayerObject", "handleRotatedObjectCollision");
	#endif
	addToMap(classes, "PlayerObject", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayerObject", "isBoostValid");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayerObject", "isFlying");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayerObject", "isInBasicMode");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayerObject", "isInNormalMode");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayerObject", "isSafeFlip");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayerObject", "isSafeHeadTest");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayerObject", "isSafeMode");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayerObject", "isSafeSpiderFlip");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayerObject", "levelFlipping");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayerObject", "playerIsFalling");
	#endif
	addToMap(classes, "PlayerObject", "playerIsFallingBugged");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayerObject", "playerIsMovingUp");
	#endif
	addToMap(classes, "PlayerObject", "preSlopeCollision");
	addToMap(classes, "PlayerObject", "pushButton");
	addToMap(classes, "PlayerObject", "releaseButton");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayerObject", "reverseMod");
	#endif
	addToMap(classes, "PlayerObject", "switchedDirTo");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayerObject", "testForMoving");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayerObject", "usingWallLimitedMode");
	#endif
	addToMap(classes, "PlayLayer", "opacityForObject");
	addToMap(classes, "PlayLayer", "timeForPos");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayLayer", "canPauseGame");
	#endif
	addToMap(classes, "PlayLayer", "getCurrentPercent");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayLayer", "getCurrentPercentInt");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayLayer", "getRelativeMod");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayLayer", "getRelativeModNew");
	#endif
	#if defined GEODE_IS_ANDROID
	addToMap(classes, "PlayLayer", "getTempMilliTime");
	#endif
	addToMap(classes, "PlayLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayLayer", "isGameplayActive");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "PlayLayer", "shouldBlend");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PlayLayer", "shouldDebugDraw");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PointNode", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PriceLabel", "init");
	#endif
	addToMap(classes, "ProfilePage", "init");
	addToMap(classes, "ProfilePage", "isCorrect");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ProfilePage", "isOnWatchlist");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PromoInterstitial", "ccTouchBegan");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PromoInterstitial", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PulseEffectAction", "isFinished");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PulseEffectAction", "valueForDelta");
	#endif
	addToMap(classes, "PurchaseItemPopup", "init");
	addToMap(classes, "RandTriggerGameObject", "init");
	addToMap(classes, "RandTriggerGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "RandTriggerGameObject", "getRandomGroupID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "RandTriggerGameObject", "getTotalChance");
	#endif
	addToMap(classes, "RateDemonLayer", "init");
	addToMap(classes, "RateLevelLayer", "init");
	addToMap(classes, "RateStarsLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "RetryLevelLayer", "getEndText");
	#endif
	addToMap(classes, "RewardsPage", "init");
	addToMap(classes, "RewardUnlockLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "RewardUnlockLayer", "readyToCollect");
	#endif
	addToMap(classes, "RewardUnlockLayer", "showCollectReward");
	addToMap(classes, "RingObject", "getSaveString");
	addToMap(classes, "RingObject", "shouldDrawEditorHitbox");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "RingObject", "init");
	#endif
	addToMap(classes, "RotateGameplayGameObject", "init");
	addToMap(classes, "RotateGameplayGameObject", "getSaveString");
	addToMap(classes, "ScrollingLayer", "ccTouchBegan");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "ScrollingLayer", "init");
	#endif
	addToMap(classes, "SearchButton", "init");
	addToMap(classes, "SearchSFXPopup", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SecretGame01Layer", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SecretGame01Layer", "getCountForDifficulty");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SecretGame01Layer", "getFrameForDifficulty");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SecretGame01Layer", "getRowsForDifficulty");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SecretGame01Layer", "getTimeForDifficulty");
	#endif
	addToMap(classes, "SecretLayer", "init");
	addToMap(classes, "SecretLayer", "getBasicMessage");
	addToMap(classes, "SecretLayer", "getMessage");
	addToMap(classes, "SecretLayer", "getThreadMessage");
	addToMap(classes, "SecretLayer2", "init");
	addToMap(classes, "SecretLayer2", "getBasicMessage");
	addToMap(classes, "SecretLayer2", "getErrorMessage");
	addToMap(classes, "SecretLayer2", "getMessage");
	addToMap(classes, "SecretLayer2", "getThreadMessage");
	addToMap(classes, "SecretLayer3", "init");
	addToMap(classes, "SecretLayer4", "init");
	addToMap(classes, "SecretLayer4", "getBasicMessage");
	addToMap(classes, "SecretLayer4", "getErrorMessage");
	addToMap(classes, "SecretLayer4", "getMessage");
	addToMap(classes, "SecretLayer4", "getThreadMessage");
	addToMap(classes, "SecretLayer5", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SecretLayer5", "getMessage");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SecretLayer6", "init");
	#endif
	addToMap(classes, "SecretNumberLayer", "init");
	addToMap(classes, "SecretRewardsLayer", "init");
	addToMap(classes, "SelectArtLayer", "init");
	addToMap(classes, "SelectEventLayer", "init");
	addToMap(classes, "SelectFontLayer", "init");
	addToMap(classes, "SelectListIconLayer", "init");
	addToMap(classes, "SelectPremadeLayer", "init");
	addToMap(classes, "SelectSettingLayer", "frameForItem");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SelectSettingLayer", "frameForValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SelectSettingLayer", "idxToValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SelectSettingLayer", "valueToIdx");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SelectSettingLayer", "getSelectedFrame");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SelectSettingLayer", "getSelectedValue");
	#endif
	addToMap(classes, "SelectSettingLayer", "init");
	addToMap(classes, "SelectSFXSortLayer", "init");
	addToMap(classes, "SequenceTriggerGameObject", "init");
	addToMap(classes, "SequenceTriggerGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SequenceTriggerGameObject", "reorderTarget");
	#endif
	addToMap(classes, "SetColorIDPopup", "init");
	addToMap(classes, "SetFolderPopup", "init");
	addToMap(classes, "SetGroupIDLayer", "init");
	addToMap(classes, "SetIDPopup", "init");
	addToMap(classes, "SetItemIDLayer", "init");
	addToMap(classes, "SetLevelOrderPopup", "init");
	addToMap(classes, "SetTargetIDLayer", "init");
	addToMap(classes, "SetTextPopup", "init");
	addToMap(classes, "SetupAdvFollowEditPhysicsPopup", "init");
	addToMap(classes, "SetupAdvFollowPopup", "init");
	addToMap(classes, "SetupAdvFollowRetargetPopup", "init");
	addToMap(classes, "SetupAnimationPopup", "init");
	addToMap(classes, "SetupAnimSettingsPopup", "init");
	addToMap(classes, "SetupAreaAnimTriggerPopup", "init");
	addToMap(classes, "SetupAreaFadeTriggerPopup", "init");
	addToMap(classes, "SetupAreaMoveTriggerPopup", "triggerValueFromSliderValue");
	addToMap(classes, "SetupAreaMoveTriggerPopup", "triggerSliderValueFromValue");
	addToMap(classes, "SetupAreaMoveTriggerPopup", "init");
	addToMap(classes, "SetupAreaRotateTriggerPopup", "init");
	addToMap(classes, "SetupAreaTintTriggerPopup", "init");
	addToMap(classes, "SetupAreaTransformTriggerPopup", "init");
	addToMap(classes, "SetupAreaTriggerPopup", "init");
	addToMap(classes, "SetupArtSwitchPopup", "init");
	addToMap(classes, "SetupAudioLineGuidePopup", "init");
	addToMap(classes, "SetupBGSpeedTrigger", "init");
	addToMap(classes, "SetupCameraEdgePopup", "init");
	addToMap(classes, "SetupCameraGuidePopup", "init");
	addToMap(classes, "SetupCameraModePopup", "init");
	addToMap(classes, "SetupCameraOffsetTrigger", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SetupCameraOffsetTrigger", "posFromSliderValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SetupCameraOffsetTrigger", "sliderValueFromPos");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SetupCameraRotatePopup", "init");
	#endif
	addToMap(classes, "SetupCameraRotatePopup2", "init");
	addToMap(classes, "SetupCheckpointPopup", "init");
	addToMap(classes, "SetupCoinLayer", "init");
	addToMap(classes, "SetupCollisionStateTriggerPopup", "init");
	addToMap(classes, "SetupCollisionTriggerPopup", "init");
	addToMap(classes, "SetupCountTriggerPopup", "init");
	addToMap(classes, "SetupDashRingPopup", "init");
	addToMap(classes, "SetupEndPopup", "init");
	addToMap(classes, "SetupEnterEffectPopup", "triggerValueFromSliderValue");
	addToMap(classes, "SetupEnterEffectPopup", "triggerSliderValueFromValue");
	addToMap(classes, "SetupEnterEffectPopup", "init");
	addToMap(classes, "SetupEnterTriggerPopup", "init");
	addToMap(classes, "SetupEventLinkPopup", "init");
	addToMap(classes, "SetupForceBlockPopup", "init");
	addToMap(classes, "SetupGameplayOffsetPopup", "triggerValueFromSliderValue");
	addToMap(classes, "SetupGameplayOffsetPopup", "triggerSliderValueFromValue");
	addToMap(classes, "SetupGameplayOffsetPopup", "init");
	addToMap(classes, "SetupGradientPopup", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SetupGravityModPopup", "init");
	#endif
	addToMap(classes, "SetupGravityTriggerPopup", "init");
	addToMap(classes, "SetupInstantCollisionTriggerPopup", "init");
	addToMap(classes, "SetupInstantCountPopup", "init");
	addToMap(classes, "SetupInteractObjectPopup", "init");
	addToMap(classes, "SetupItemCompareTriggerPopup", "init");
	addToMap(classes, "SetupItemEditTriggerPopup", "init");
	addToMap(classes, "SetupKeyframeAnimPopup", "init");
	addToMap(classes, "SetupKeyframePopup", "init");
	addToMap(classes, "SetupMGTrigger", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SetupMGTrigger", "posFromSliderValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SetupMGTrigger", "sliderValueFromPos");
	#endif
	addToMap(classes, "SetupMoveCommandPopup", "triggerValueFromSliderValue");
	addToMap(classes, "SetupMoveCommandPopup", "triggerSliderValueFromValue");
	addToMap(classes, "SetupMoveCommandPopup", "init");
	addToMap(classes, "SetupObjectControlPopup", "init");
	addToMap(classes, "SetupObjectOptions2Popup", "init");
	addToMap(classes, "SetupObjectOptionsPopup", "init");
	addToMap(classes, "SetupObjectTogglePopup", "init");
	addToMap(classes, "SetupOpacityPopup", "init");
	addToMap(classes, "SetupOptionsTriggerPopup", "init");
	addToMap(classes, "SetupPersistentItemTriggerPopup", "init");
	addToMap(classes, "SetupPickupTriggerPopup", "init");
	addToMap(classes, "SetupPlatformerEndPopup", "init");
	addToMap(classes, "SetupPlayerControlPopup", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SetupPortalPopup", "init");
	#endif
	addToMap(classes, "SetupPulsePopup", "init");
	addToMap(classes, "SetupRandAdvTriggerPopup", "init");
	addToMap(classes, "SetupRandTriggerPopup", "init");
	addToMap(classes, "SetupResetTriggerPopup", "init");
	addToMap(classes, "SetupReverbPopup", "init");
	addToMap(classes, "SetupRotateCommandPopup", "triggerValueFromSliderValue");
	addToMap(classes, "SetupRotateCommandPopup", "triggerSliderValueFromValue");
	addToMap(classes, "SetupRotateCommandPopup", "init");
	addToMap(classes, "SetupRotateGameplayPopup", "init");
	addToMap(classes, "SetupRotatePopup", "init");
	addToMap(classes, "SetupSequenceTriggerPopup", "init");
	addToMap(classes, "SetupSFXEditPopup", "init");
	addToMap(classes, "SetupSFXPopup", "getActiveSFXID");
	addToMap(classes, "SetupSFXPopup", "overridePlaySFX");
	addToMap(classes, "SetupSFXPopup", "init");
	addToMap(classes, "SetupShaderEffectPopup", "init");
	addToMap(classes, "SetupShaderEffectPopup", "zLayerToString");
	addToMap(classes, "SetupShakePopup", "init");
	addToMap(classes, "SetupSmartBlockLayer", "init");
	addToMap(classes, "SetupSmartTemplateLayer", "init");
	addToMap(classes, "SetupSongTriggerPopup", "init");
	addToMap(classes, "SetupSpawnParticlePopup", "init");
	addToMap(classes, "SetupSpawnPopup", "init");
	addToMap(classes, "SetupStaticCameraPopup", "init");
	addToMap(classes, "SetupStopTriggerPopup", "init");
	addToMap(classes, "SetupTeleportPopup", "init");
	addToMap(classes, "SetupTimerControlTriggerPopup", "init");
	addToMap(classes, "SetupTimerEventTriggerPopup", "init");
	addToMap(classes, "SetupTimerTriggerPopup", "init");
	addToMap(classes, "SetupTimeWarpPopup", "init");
	addToMap(classes, "SetupTouchTogglePopup", "init");
	addToMap(classes, "SetupTransformPopup", "init");
	addToMap(classes, "SetupTriggerPopup", "ccTouchBegan");
	addToMap(classes, "SetupTriggerPopup", "getValue");
	addToMap(classes, "SetupTriggerPopup", "triggerValueFromSliderValue");
	addToMap(classes, "SetupTriggerPopup", "triggerSliderValueFromValue");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SetupTriggerPopup", "getMaxSliderValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SetupTriggerPopup", "getMinSliderValue");
	#endif
	addToMap(classes, "SetupTriggerPopup", "getTriggerValue");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SetupTriggerPopup", "getTruncatedValue");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SetupTriggerPopup", "getTruncatedValueByTag");
	#endif
	addToMap(classes, "SetupTriggerPopup", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SetupTriggerPopup", "shouldLimitValue");
	#endif
	addToMap(classes, "SetupZoomTriggerPopup", "init");
	addToMap(classes, "SFXBrowser", "cellPerformedAction");
	addToMap(classes, "SFXBrowser", "getSelectedCellIdx");
	addToMap(classes, "SFXBrowser", "shouldSnapToSelected");
	addToMap(classes, "SFXBrowser", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SFXFolderObject", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SFXInfoObject", "getLowerCaseName");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SFXInfoObject", "init");
	#endif
	addToMap(classes, "SFXSearchResult", "getSelectedPage");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SFXSearchResult", "init");
	#endif
	addToMap(classes, "SFXTriggerGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SFXTriggerGameObject", "getSFXRefID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SFXTriggerGameObject", "getUniqueSFXID");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SFXTriggerGameObject", "init");
	#endif
	addToMap(classes, "ShaderGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "ShaderGameObject", "init");
	#endif
	addToMap(classes, "ShaderLayer", "init");
	addToMap(classes, "ShaderLayer", "resetAllShaders");
	addToMap(classes, "ShaderLayer", "updateZLayer");
	addToMap(classes, "ShardsPage", "init");
	addToMap(classes, "ShareCommentLayer", "init");
	addToMap(classes, "ShareLevelLayer", "init");
	addToMap(classes, "ShareLevelSettingsLayer", "init");
	addToMap(classes, "ShareListLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SimpleObject", "init");
	#endif
	addToMap(classes, "SimplePlayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SlideInLayer", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SlideInLayer", "ccTouchBegan");
	#endif
	addToMap(classes, "Slider", "ccTouchBegan");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "Slider", "getLiveDragging");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "Slider", "getValue");
	#endif
	addToMap(classes, "Slider", "init");
	addToMap(classes, "SliderThumb", "getValue");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SliderThumb", "init");
	#endif
	addToMap(classes, "SliderTouchLogic", "ccTouchBegan");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SliderTouchLogic", "init");
	#endif
	addToMap(classes, "SmartGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SmartGameObject", "init");
	#endif
	addToMap(classes, "SmartTemplateCell", "init");
	addToMap(classes, "SongCell", "init");
	addToMap(classes, "SongInfoLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SongInfoObject", "canEncode");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SongInfoObject", "containsTag");
	#endif
	addToMap(classes, "SongInfoObject", "getArtistNames");
	addToMap(classes, "SongInfoObject", "getExtraArtistCount");
	addToMap(classes, "SongInfoObject", "getTagsString");
	addToMap(classes, "SongInfoObject", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SongObject", "init");
	#endif
	addToMap(classes, "SongOptionsLayer", "init");
	addToMap(classes, "SongSelectNode", "getActiveSongID");
	addToMap(classes, "SongSelectNode", "getSongFileName");
	addToMap(classes, "SongSelectNode", "init");
	addToMap(classes, "SongTriggerGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SongTriggerGameObject", "init");
	#endif
	addToMap(classes, "SpawnParticleGameObject", "init");
	addToMap(classes, "SpawnParticleGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SpawnTriggerAction", "isFinished");
	#endif
	addToMap(classes, "SpawnTriggerGameObject", "init");
	addToMap(classes, "SpawnTriggerGameObject", "getSaveString");
	addToMap(classes, "SpecialAnimGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SpecialAnimGameObject", "init");
	#endif
	addToMap(classes, "SpriteAnimationManager", "getPrio");
	addToMap(classes, "SpriteAnimationManager", "initWithOwner");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SpriteDescription", "initDescription");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "SpriteDescription", "initDescription");
	#endif
	addToMap(classes, "StarInfoPopup", "init");
	addToMap(classes, "StartPosObject", "init");
	addToMap(classes, "StartPosObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "StatsCell", "init");
	#endif
	addToMap(classes, "StatsCell", "getTitleFromKey");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "StatsObject", "init");
	#endif
	addToMap(classes, "TableView", "ccTouchBegan");
	addToMap(classes, "TableView", "checkBoundaryOfCell");
	addToMap(classes, "TableView", "checkBoundaryOfCell");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "TableView", "dequeueReusableCellWithIdentifier");
	#endif
	addToMap(classes, "TableView", "isDuplicateIndexPath");
	addToMap(classes, "TableView", "isDuplicateInVisibleCellArray");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "TableView", "removeIndexPathFromPathAddedArray");
	#endif
	addToMap(classes, "TeleportPortalObject", "getSaveString");
	addToMap(classes, "TeleportPortalObject", "addToGroup");
	addToMap(classes, "TeleportPortalObject", "getTeleportXOff");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "TeleportPortalObject", "init");
	#endif
	addToMap(classes, "TextAlertPopup", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "TextArea", "fadeIn");
	#endif
	addToMap(classes, "TextArea", "fadeInCharacters");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "TextArea", "init");
	#endif
	addToMap(classes, "TextGameObject", "getSaveString");
	addToMap(classes, "TextGameObject", "getTextKerning");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "TextGameObject", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "TextStyleSection", "init");
	#endif
	addToMap(classes, "TimerTriggerGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "TimerTriggerGameObject", "init");
	#endif
	addToMap(classes, "TopArtistsLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "TopArtistsLayer", "isCorrect");
	#endif
	addToMap(classes, "TOSPopup", "init");
	addToMap(classes, "TransformTriggerGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "TransformTriggerGameObject", "init");
	#endif
	addToMap(classes, "TriggerControlGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "TriggerControlGameObject", "init");
	#endif
	addToMap(classes, "TutorialLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "TutorialPopup", "init");
	#endif
	addToMap(classes, "UILayer", "ccTouchBegan");
	addToMap(classes, "UILayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "UILayer", "isJumpButtonPressed");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "UILayer", "isJumpButtonPressed");
	#endif
	addToMap(classes, "UILayer", "processUINodesTouch");
	addToMap(classes, "UILayer", "processUINodeTouch");
	addToMap(classes, "UIObjectSettingsPopup", "init");
	addToMap(classes, "UIOptionsLayer", "ccTouchBegan");
	addToMap(classes, "UIOptionsLayer", "getValue");
	addToMap(classes, "UIOptionsLayer", "init");
	addToMap(classes, "UIPOptionsLayer", "init");
	addToMap(classes, "UIPOptionsLayer", "ccTouchBegan");
	addToMap(classes, "UIPOptionsLayer", "getValue");
	addToMap(classes, "UISaveLoadLayer", "init");
	addToMap(classes, "UISettingsGameObject", "init");
	addToMap(classes, "UISettingsGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "UndoObject", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "UndoObject", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "UndoObject", "initWithTransformObjects");
	#endif
	addToMap(classes, "UpdateAccountSettingsPopup", "init");
	addToMap(classes, "UploadActionPopup", "init");
	addToMap(classes, "UploadListPopup", "init");
	addToMap(classes, "UploadPopup", "init");
	addToMap(classes, "URLCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	addToMap(classes, "URLViewLayer", "init");
	#endif
	addToMap(classes, "VideoOptionsLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "WorldLevelPage", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_INTEL_MAC || defined GEODE_IS_ARM_MAC
	addToMap(classes, "WorldSelectLayer", "init");
	#endif

	return classes;
}

constexpr std::vector<std::string> getClasses() {
	std::vector<std::string> ret;
    ret.reserve(getFuncs().size());

    for (auto& [clazz, funcs] : getFuncs()) {
        ret.push_back(clazz);
    }

	return ret;
}
