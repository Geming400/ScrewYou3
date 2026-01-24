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
	addToMap(classes, "AchievementBar", "init");
	addToMap(classes, "AchievementManager", "init");
	addToMap(classes, "AchievementManager", "achievementForUnlock");
	addToMap(classes, "AchievementManager", "isAchievementEarned");
	addToMap(classes, "AchievementManager", "percentForAchievement");
	addToMap(classes, "AchievementNotifier", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AdToolbox", "hasCachedInterstitial");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AdToolbox", "hasCachedRewardedVideo");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "AdToolbox", "isShowingAd");
	#endif
	addToMap(classes, "AdvancedFollowEditObject", "getSaveString");
	addToMap(classes, "AdvancedFollowTriggerObject", "getSaveString");
	addToMap(classes, "AnimatedGameObject", "animationForID");
	addToMap(classes, "AnimatedGameObject", "init");
	addToMap(classes, "AppDelegate", "applicationDidFinishLaunching");
	addToMap(classes, "AppDelegate", "musicTest");
	addToMap(classes, "ArtistCell", "init");
	addToMap(classes, "ArtTriggerGameObject", "getSaveString");
	addToMap(classes, "AudioAssetsBrowser", "init");
	addToMap(classes, "AudioEffectsLayer", "init");
	addToMap(classes, "AudioLineGuideGameObject", "init");
	addToMap(classes, "AudioLineGuideGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "BonusDropdown", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "BoomListLayer", "init");
	#endif
	addToMap(classes, "BoomListView", "cellHeightForRowAtIndexPath");
	addToMap(classes, "BoomListView", "numberOfRowsInSection");
	addToMap(classes, "BoomListView", "init");
	addToMap(classes, "BoomScrollLayer", "ccTouchBegan");
	addToMap(classes, "BoomScrollLayer", "init");
	addToMap(classes, "BoomScrollLayer", "pageNumberForPosition");
	addToMap(classes, "BrowseSmartKeyLayer", "init");
	addToMap(classes, "BrowseSmartTemplateLayer", "init");
	addToMap(classes, "ButtonSprite", "init");
	addToMap(classes, "ButtonSprite", "init");
	addToMap(classes, "CameraTriggerGameObject", "getSaveString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCAlertCircle", "init");
	#endif
	addToMap(classes, "CCAnimatedSprite", "initWithType");
	addToMap(classes, "CCBlockLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCCircleAlert", "init");
	#endif
	addToMap(classes, "CCCircleWave", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCCountdown", "init");
	#endif
	addToMap(classes, "CCMenuItemSpriteExtra", "init");
	addToMap(classes, "CCNodeContainer", "init");
	addToMap(classes, "CCPartAnimSprite", "isFrameDisplayed");
	addToMap(classes, "CCPartAnimSprite", "initWithAnimDesc");
	addToMap(classes, "CCScrollLayerExt", "ccTouchBegan");
	addToMap(classes, "CCSpriteGrayscale", "getShaderName");
	addToMap(classes, "CCSpriteGrayscale", "shaderBody");
	addToMap(classes, "CCSpritePlus", "initWithTexture");
	addToMap(classes, "CCSpritePlus", "initWithSpriteFrameName");
	addToMap(classes, "CCSpriteWithHue", "initWithTexture");
	addToMap(classes, "CCSpriteWithHue", "initWithTexture");
	addToMap(classes, "CCSpriteWithHue", "initWithTexture");
	addToMap(classes, "CCSpriteWithHue", "initWithSpriteFrame");
	addToMap(classes, "CCSpriteWithHue", "getShaderName");
	addToMap(classes, "CCSpriteWithHue", "shaderBody");
	addToMap(classes, "CCTextInputNode", "ccTouchBegan");
	addToMap(classes, "CCTextInputNode", "onTextFieldInsertText");
	addToMap(classes, "CCTextInputNode", "onTextFieldAttachWithIME");
	addToMap(classes, "CCTextInputNode", "onTextFieldDetachWithIME");
	addToMap(classes, "CCTextInputNode", "init");
	addToMap(classes, "ChallengeNode", "init");
	addToMap(classes, "ChallengesPage", "init");
	addToMap(classes, "CharacterColorPage", "init");
	addToMap(classes, "CharacterColorPage", "activeColorForMode");
	addToMap(classes, "CharacterColorPage", "colorForIndex");
	addToMap(classes, "CheckpointGameObject", "init");
	addToMap(classes, "CheckpointGameObject", "getSaveString");
	addToMap(classes, "CheckpointObject", "init");
	addToMap(classes, "CollisionBlockPopup", "init");
	addToMap(classes, "ColorActionSprite", "init");
	addToMap(classes, "ColorChannelSprite", "init");
	addToMap(classes, "ColorSelectLiveOverlay", "init");
	addToMap(classes, "ColorSelectPopup", "colorToHex");
	addToMap(classes, "ColorSelectPopup", "init");
	addToMap(classes, "CommentCell", "init");
	addToMap(classes, "CommunityCreditsPage", "init");
	addToMap(classes, "ConfigureHSVWidget", "init");
	addToMap(classes, "ConfigureValuePopup", "init");
	addToMap(classes, "CountTriggerGameObject", "getSaveString");
	addToMap(classes, "CreateGuidelinesLayer", "ccTouchBegan");
	addToMap(classes, "CreateGuidelinesLayer", "getMergedRecordString");
	addToMap(classes, "CreateGuidelinesLayer", "init");
	addToMap(classes, "CreateParticlePopup", "ccTouchBegan");
	addToMap(classes, "CreateParticlePopup", "init");
	addToMap(classes, "CreateParticlePopup", "maxSliderValueForType");
	addToMap(classes, "CreateParticlePopup", "minSliderValueForType");
	addToMap(classes, "CreateParticlePopup", "titleForParticleValue");
	addToMap(classes, "CreateParticlePopup", "valueForParticleValue");
	addToMap(classes, "CreatorLayer", "init");
	addToMap(classes, "CurrencyRewardLayer", "init");
	addToMap(classes, "CurrencySprite", "spriteTypeToStat");
	addToMap(classes, "CurrencySprite", "init");
	addToMap(classes, "CustomizeObjectLayer", "getActiveMode");
	addToMap(classes, "CustomizeObjectLayer", "init");
	addToMap(classes, "CustomizeObjectSettingsPopup", "init");
	addToMap(classes, "CustomListView", "getCellHeight");
	addToMap(classes, "CustomSFXCell", "init");
	addToMap(classes, "CustomSFXCell", "getActiveSFXID");
	addToMap(classes, "CustomSFXWidget", "init");
	addToMap(classes, "CustomSongCell", "init");
	addToMap(classes, "CustomSongCell", "getActiveSongID");
	addToMap(classes, "CustomSongCell", "getSongFileName");
	addToMap(classes, "CustomSongLayer", "init");
	addToMap(classes, "CustomSongWidget", "init");
	addToMap(classes, "DailyLevelNode", "init");
	addToMap(classes, "DailyLevelPage", "getDailyTimeString");
	addToMap(classes, "DailyLevelPage", "init");
	addToMap(classes, "DashRingObject", "getSaveString");
	addToMap(classes, "DemonFilterSelectLayer", "init");
	addToMap(classes, "DemonInfoPopup", "init");
	addToMap(classes, "DialogLayer", "ccTouchBegan");
	addToMap(classes, "DialogLayer", "init");
	addToMap(classes, "DungeonBarsSprite", "init");
	addToMap(classes, "EditGameObjectPopup", "init");
	addToMap(classes, "EditLevelLayer", "init");
	addToMap(classes, "EditorOptionsLayer", "init");
	addToMap(classes, "EditorPauseLayer", "init");
	addToMap(classes, "EditorUI", "ccTouchBegan");
	addToMap(classes, "EditorUI", "canSelectObject");
	addToMap(classes, "EditorUI", "convertKeyBasedOnNeighbors");
	addToMap(classes, "EditorUI", "convertToBaseKey");
	addToMap(classes, "EditorUI", "copyObjects");
	addToMap(classes, "EditorUI", "editButton2Usable");
	addToMap(classes, "EditorUI", "editButtonUsable");
	addToMap(classes, "EditorUI", "getRandomStartKey");
	addToMap(classes, "EditorUI", "getSmartObjectKey");
	addToMap(classes, "EditorUI", "getXMin");
	addToMap(classes, "EditorUI", "init");
	addToMap(classes, "EditorUI", "isSpecialSnapObject");
	addToMap(classes, "EditorUI", "onCreate");
	addToMap(classes, "EditorUI", "shouldDeleteObject");
	addToMap(classes, "EditorUI", "smartTypeForKey");
	addToMap(classes, "EditTriggersPopup", "init");
	addToMap(classes, "EffectGameObject", "getSaveString");
	addToMap(classes, "EffectGameObject", "spawnXPosition");
	addToMap(classes, "EffectGameObject", "canReverse");
	addToMap(classes, "EffectGameObject", "canBeOrdered");
	addToMap(classes, "EndLevelLayer", "getCoinString");
	addToMap(classes, "EndLevelLayer", "getEndText");
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
	addToMap(classes, "EnterEffectObject", "getSaveString");
	addToMap(classes, "EventLinkTrigger", "init");
	addToMap(classes, "EventLinkTrigger", "getSaveString");
	addToMap(classes, "ExplodeItemSprite", "init");
	addToMap(classes, "ExtendedLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "FileOperation", "getFilePath");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "FileSaveManager", "init");
	#endif
	addToMap(classes, "FindObjectPopup", "init");
	addToMap(classes, "FLAlertLayer", "ccTouchBegan");
	addToMap(classes, "FLAlertLayer", "init");
	addToMap(classes, "FLAlertLayer", "init");
	addToMap(classes, "FMODAudioEngine", "channelIDForUniqueID");
	addToMap(classes, "FMODAudioEngine", "getFMODStatus");
	addToMap(classes, "FMODAudioEngine", "getMusicLengthMS");
	addToMap(classes, "FMODAudioEngine", "getMusicTimeMS");
	addToMap(classes, "FMODAudioEngine", "isMusicPlaying");
	addToMap(classes, "FMODAudioEngine", "isMusicPlaying");
	addToMap(classes, "FMODAudioEngine", "isPersistentMatchPlaying");
	addToMap(classes, "FMODAudioEngine", "lengthForSound");
	addToMap(classes, "FMODAudioEngine", "pitchForIdx");
	addToMap(classes, "FMODAudioEngine", "playEffect");
	addToMap(classes, "FMODAudioEngine", "playEffect");
	addToMap(classes, "FMODAudioEngine", "playEffectAdvanced");
	addToMap(classes, "FMODAudioEngine", "queuePlayEffect");
	addToMap(classes, "FMODAudioEngine", "registerChannel");
	addToMap(classes, "FMODAudioEngine", "reverbToString");
	addToMap(classes, "FMODAudioEngine", "stopAndGetFade");
	addToMap(classes, "FMODLevelVisualizer", "init");
	addToMap(classes, "FollowRewardPage", "init");
	addToMap(classes, "ForceBlockGameObject", "getSaveString");
	addToMap(classes, "FRequestProfilePage", "init");
	addToMap(classes, "FRequestProfilePage", "isCorrect");
	addToMap(classes, "FriendRequestPopup", "init");
	addToMap(classes, "FriendsProfilePage", "init");
	addToMap(classes, "GameCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameEffectsManager", "init");
	#endif
	addToMap(classes, "GameLevelManager", "init");
	addToMap(classes, "GameLevelManager", "acceptFriendRequest");
	addToMap(classes, "GameLevelManager", "accountIDForUserID");
	addToMap(classes, "GameLevelManager", "blockUser");
	addToMap(classes, "GameLevelManager", "deleteFriendRequests");
	addToMap(classes, "GameLevelManager", "deleteUserMessages");
	addToMap(classes, "GameLevelManager", "getBasePostString");
	addToMap(classes, "GameLevelManager", "getCompletedDailyLevels");
	addToMap(classes, "GameLevelManager", "getCompletedEventLevels");
	addToMap(classes, "GameLevelManager", "getCompletedWeeklyLevels");
	addToMap(classes, "GameLevelManager", "getDemonLevelsString");
	addToMap(classes, "GameLevelManager", "getDifficultyStr");
	addToMap(classes, "GameLevelManager", "getFolderName");
	addToMap(classes, "GameLevelManager", "getGJChallenges");
	addToMap(classes, "GameLevelManager", "getGJDailyLevelState");
	addToMap(classes, "GameLevelManager", "getGJRewards");
	addToMap(classes, "GameLevelManager", "getGJSecretReward");
	addToMap(classes, "GameLevelManager", "getLengthStr");
	addToMap(classes, "GameLevelManager", "getNextLevelName");
	addToMap(classes, "GameLevelManager", "getPageInfo");
	addToMap(classes, "GameLevelManager", "getSplitIntFromKey");
	addToMap(classes, "GameLevelManager", "getStarLevelsString");
	addToMap(classes, "GameLevelManager", "getTimeLeft");
	addToMap(classes, "GameLevelManager", "hasDownloadedLevel");
	addToMap(classes, "GameLevelManager", "hasLikedAccountItem");
	addToMap(classes, "GameLevelManager", "hasLikedItem");
	addToMap(classes, "GameLevelManager", "hasLikedItemFullCheck");
	addToMap(classes, "GameLevelManager", "hasRatedDemon");
	addToMap(classes, "GameLevelManager", "hasRatedLevelStars");
	addToMap(classes, "GameLevelManager", "hasReportedLevel");
	addToMap(classes, "GameLevelManager", "isDLActive");
	addToMap(classes, "GameLevelManager", "isFollowingUser");
	addToMap(classes, "GameLevelManager", "isTimeValid");
	addToMap(classes, "GameLevelManager", "keyHasTimer");
	addToMap(classes, "GameLevelManager", "levelIDFromCommentKey");
	addToMap(classes, "GameLevelManager", "rateDemon");
	addToMap(classes, "GameLevelManager", "removeFriend");
	addToMap(classes, "GameLevelManager", "requestUserAccess");
	addToMap(classes, "GameLevelManager", "tryGetUsername");
	addToMap(classes, "GameLevelManager", "unblockUser");
	addToMap(classes, "GameLevelManager", "updateDescription");
	addToMap(classes, "GameLevelManager", "uploadFriendRequest");
	addToMap(classes, "GameLevelManager", "userNameForUserID");
	addToMap(classes, "GameLevelManager", "verifyContainerOnlyHasLevels");
	addToMap(classes, "GameLevelManager", "writeSpecialFilters");
	addToMap(classes, "GameManager", "init");
	addToMap(classes, "GameManager", "activeIconForType");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameManager", "canShowRewardedVideo");
	#endif
	addToMap(classes, "GameManager", "colorKey");
	addToMap(classes, "GameManager", "countForType");
	addToMap(classes, "GameManager", "dpadConfigToString");
	addToMap(classes, "GameManager", "generateSecretNumber");
	addToMap(classes, "GameManager", "getGameVariable");
	addToMap(classes, "GameManager", "getIntGameVariable");
	addToMap(classes, "GameManager", "getMenuMusicFile");
	addToMap(classes, "GameManager", "getUGV");
	addToMap(classes, "GameManager", "iconKey");
	addToMap(classes, "GameManager", "isColorUnlocked");
	addToMap(classes, "GameManager", "isIconUnlocked");
	addToMap(classes, "GameManager", "playSFXTrigger");
	addToMap(classes, "GameManager", "reorderKey");
	addToMap(classes, "GameManager", "safePopScene");
	addToMap(classes, "GameManager", "sheetNameForIcon");
	addToMap(classes, "GameManager", "stringForCustomObject");
	addToMap(classes, "GameManager", "toggleGameVariable");
	addToMap(classes, "GameObject", "initWithTexture");
	addToMap(classes, "GameObject", "getSaveString");
	addToMap(classes, "GameObject", "isFlipX");
	addToMap(classes, "GameObject", "isFlipY");
	addToMap(classes, "GameObject", "getRScaleX");
	addToMap(classes, "GameObject", "getRScaleY");
	addToMap(classes, "GameObject", "getObjectRotation");
	addToMap(classes, "GameObject", "addToGroup");
	addToMap(classes, "GameObject", "spawnXPosition");
	addToMap(classes, "GameObject", "getColorFrame");
	addToMap(classes, "GameObject", "getColorKey");
	addToMap(classes, "GameObject", "getGlowFrame");
	addToMap(classes, "GameObject", "getObjectDirection");
	addToMap(classes, "GameObject", "getParentMode");
	addToMap(classes, "GameObject", "groupOpacityMod");
	addToMap(classes, "GameObject", "ignoreEditorDuration");
	addToMap(classes, "GameObject", "isBasicTrigger");
	addToMap(classes, "GameObject", "isFacingDown");
	addToMap(classes, "GameObject", "isFacingLeft");
	addToMap(classes, "GameObject", "isSpawnableTrigger");
	addToMap(classes, "GameObject", "isSpecialObject");
	addToMap(classes, "GameObject", "isTrigger");
	addToMap(classes, "GameObject", "perspectiveColorFrame");
	addToMap(classes, "GameObject", "perspectiveFrame");
	addToMap(classes, "GameObject", "shouldBlendColor");
	addToMap(classes, "GameObject", "shouldLockX");
	addToMap(classes, "GameObject", "slopeYPos");
	addToMap(classes, "GameOptionsTrigger", "getSaveString");
	addToMap(classes, "GameStatsManager", "init");
	addToMap(classes, "GameStatsManager", "awardSecretKey");
	addToMap(classes, "GameStatsManager", "getAwardedCurrencyForLevel");
	addToMap(classes, "GameStatsManager", "getAwardedDiamondsForLevel");
	addToMap(classes, "GameStatsManager", "getBaseCurrencyForLevel");
	addToMap(classes, "GameStatsManager", "getCollectedCoinsForLevel");
	addToMap(classes, "GameStatsManager", "getGauntletRewardKey");
	addToMap(classes, "GameStatsManager", "getItemKey");
	addToMap(classes, "GameStatsManager", "getItemUnlockState");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameStatsManager", "getItemUnlockStateLite");
	#endif
	addToMap(classes, "GameStatsManager", "getLevelKey");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameStatsManager", "getNextVideoAdReward");
	#endif
	addToMap(classes, "GameStatsManager", "getPathRewardKey");
	addToMap(classes, "GameStatsManager", "getRewardKey");
	addToMap(classes, "GameStatsManager", "getSpecialUnlockDescription");
	addToMap(classes, "GameStatsManager", "getStat");
	addToMap(classes, "GameStatsManager", "getTotalCollectedCurrency");
	addToMap(classes, "GameStatsManager", "getTotalCollectedDiamonds");
	addToMap(classes, "GameStatsManager", "hasClaimedListReward");
	addToMap(classes, "GameStatsManager", "hasCompletedChallenge");
	addToMap(classes, "GameStatsManager", "hasCompletedDailyLevel");
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
	addToMap(classes, "GameStatsManager", "isItemUnlocked");
	addToMap(classes, "GameStatsManager", "isSecretChestUnlocked");
	addToMap(classes, "GameStatsManager", "isSecretCoinValid");
	addToMap(classes, "GameStatsManager", "isSpecialChestUnlocked");
	addToMap(classes, "GameStatsManager", "isStoreItemUnlocked");
	addToMap(classes, "GameStatsManager", "purchaseItem");
	addToMap(classes, "GameToolbox", "bounceTime");
	addToMap(classes, "GameToolbox", "easeToText");
	addToMap(classes, "GameToolbox", "gen_random");
	addToMap(classes, "GameToolbox", "getEasedValue");
	addToMap(classes, "GameToolbox", "getResponse");
	addToMap(classes, "GameToolbox", "getTimeString");
	addToMap(classes, "GameToolbox", "intToShortString");
	addToMap(classes, "GameToolbox", "intToString");
	addToMap(classes, "GameToolbox", "msToTimeString");
	addToMap(classes, "GameToolbox", "pointsToString");
	addToMap(classes, "GameToolbox", "saveParticleToString");
	addToMap(classes, "GameToolbox", "stringFromHSV");
	addToMap(classes, "GameToolbox", "timestampToHumanReadable");
	addToMap(classes, "GauntletLayer", "init");
	addToMap(classes, "GauntletNode", "frameForType");
	addToMap(classes, "GauntletNode", "nameForType");
	addToMap(classes, "GauntletNode", "init");
	addToMap(classes, "GauntletSelectLayer", "init");
	addToMap(classes, "GhostTrailEffect", "init");
	addToMap(classes, "GJAccountManager", "init");
	addToMap(classes, "GJAccountManager", "backupAccount");
	addToMap(classes, "GJAccountManager", "getAccountBackupURL");
	addToMap(classes, "GJAccountManager", "getAccountSyncURL");
	addToMap(classes, "GJAccountManager", "getShaPassword");
	addToMap(classes, "GJAccountManager", "syncAccount");
	addToMap(classes, "GJAccountSettingsLayer", "init");
	addToMap(classes, "GJActionManager", "init");
	addToMap(classes, "GJBaseGameLayer", "init");
	addToMap(classes, "GJBaseGameLayer", "opacityForObject");
	addToMap(classes, "GJBaseGameLayer", "addGuideArt");
	addToMap(classes, "GJBaseGameLayer", "canBeActivatedByPlayer");
	addToMap(classes, "GJBaseGameLayer", "canProcessSFX");
	addToMap(classes, "GJBaseGameLayer", "checkCollision");
	addToMap(classes, "GJBaseGameLayer", "checkCollisions");
	addToMap(classes, "GJBaseGameLayer", "convertToClosestDirection");
	addToMap(classes, "GJBaseGameLayer", "gameEventToString");
	addToMap(classes, "GJBaseGameLayer", "generateEnterEasingBuffer");
	addToMap(classes, "GJBaseGameLayer", "getItemValue");
	addToMap(classes, "GJBaseGameLayer", "getMaxPortalY");
	addToMap(classes, "GJBaseGameLayer", "getMinDistance");
	addToMap(classes, "GJBaseGameLayer", "getMinPortalY");
	addToMap(classes, "GJBaseGameLayer", "getModifiedDelta");
	addToMap(classes, "GJBaseGameLayer", "getParticleKey");
	addToMap(classes, "GJBaseGameLayer", "getParticleKey2");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBaseGameLayer", "getRecordString");
	#endif
	addToMap(classes, "GJBaseGameLayer", "hasUniqueCoin");
	addToMap(classes, "GJBaseGameLayer", "maxZOrderForShaderZ");
	addToMap(classes, "GJBaseGameLayer", "minZOrderForShaderZ");
	addToMap(classes, "GJBaseGameLayer", "playerCircleCollision");
	addToMap(classes, "GJBaseGameLayer", "processSongState");
	addToMap(classes, "GJBaseGameLayer", "shouldExitHackedLevel");
	addToMap(classes, "GJBaseGameLayer", "volumeForProximityEffect");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBigSprite", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBigSpriteNode", "init");
	#endif
	addToMap(classes, "GJColorSetupLayer", "init");
	addToMap(classes, "GJComment", "init");
	addToMap(classes, "GJCommentListLayer", "init");
	addToMap(classes, "GJDifficultySprite", "getDifficultyFrame");
	addToMap(classes, "GJDropDownLayer", "init");
	addToMap(classes, "GJEffectManager", "init");
	addToMap(classes, "GJEffectManager", "countForItem");
	addToMap(classes, "GJEffectManager", "opacityModForGroup");
	addToMap(classes, "GJEffectManager", "timeForItem");
	addToMap(classes, "GJEffectManager", "timerExists");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJFlyGroundLayer", "init");
	#endif
	addToMap(classes, "GJFollowCommandLayer", "init");
	addToMap(classes, "GJFriendRequest", "init");
	addToMap(classes, "GJGameLevel", "lengthKeyToString");
	addToMap(classes, "GJGameLevel", "init");
	addToMap(classes, "GJGameLevel", "areCoinsVerified");
	addToMap(classes, "GJGameLevel", "getAudioFileName");
	addToMap(classes, "GJGameLevel", "getAverageDifficulty");
	addToMap(classes, "GJGameLevel", "getLastBuildPageForTab");
	addToMap(classes, "GJGameLevel", "getSongName");
	addToMap(classes, "GJGameLevel", "getUnpackedLevelDescription");
	addToMap(classes, "GJGarageLayer", "init");
	addToMap(classes, "GJGarageLayer", "descriptionForUnlock");
	addToMap(classes, "GJGradientLayer", "init");
	addToMap(classes, "GJGroundLayer", "init");
	addToMap(classes, "GJGroundLayer", "scaleGround");
	addToMap(classes, "GJItemIcon", "scaleForType");
	addToMap(classes, "GJItemIcon", "init");
	addToMap(classes, "GJLevelList", "init");
	addToMap(classes, "GJLevelList", "completedLevels");
	addToMap(classes, "GJLevelList", "getUnpackedDescription");
	addToMap(classes, "GJLevelList", "hasMatchingLevels");
	addToMap(classes, "GJLevelScoreCell", "init");
	addToMap(classes, "GJListLayer", "init");
	addToMap(classes, "GJLocalLevelScoreCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJMapObject", "init");
	#endif
	addToMap(classes, "GJMapPack", "init");
	addToMap(classes, "GJMapPack", "completedMaps");
	addToMap(classes, "GJMessageCell", "init");
	addToMap(classes, "GJMessagePopup", "init");
	addToMap(classes, "GJMGLayer", "init");
	addToMap(classes, "GJMultiplayerManager", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJMultiplayerManager", "exitLobby");
	#endif
	addToMap(classes, "GJMultiplayerManager", "getBasePostString");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJMultiplayerManager", "joinLobby");
	#endif
	addToMap(classes, "GJMultiplayerManager", "uploadComment");
	addToMap(classes, "GJObjectDecoder", "init");
	addToMap(classes, "GJOptionsLayer", "countForPage");
	addToMap(classes, "GJOptionsLayer", "init");
	addToMap(classes, "GJPathPage", "init");
	addToMap(classes, "GJPathRewardPopup", "init");
	addToMap(classes, "GJPathsLayer", "nameForPath");
	addToMap(classes, "GJPathsLayer", "init");
	addToMap(classes, "GJPFollowCommandLayer", "init");
	addToMap(classes, "GJPromoPopup", "init");
	addToMap(classes, "GJRequestCell", "init");
	addToMap(classes, "GJRewardItem", "rewardItemToStat");
	addToMap(classes, "GJRewardItem", "init");
	addToMap(classes, "GJRobotSprite", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJRotateCommandLayer", "init");
	#endif
	addToMap(classes, "GJRotationControl", "init");
	addToMap(classes, "GJRotationControl", "ccTouchBegan");
	addToMap(classes, "GJScaleControl", "init");
	addToMap(classes, "GJScaleControl", "ccTouchBegan");
	addToMap(classes, "GJScoreCell", "init");
	addToMap(classes, "GJSearchObject", "isLevelSearchObject");
	addToMap(classes, "GJShopLayer", "ccTouchBegan");
	addToMap(classes, "GJShopLayer", "init");
	addToMap(classes, "GJSmartBlockPreviewSprite", "init");
	addToMap(classes, "GJSmartTemplate", "flipKey");
	addToMap(classes, "GJSmartTemplate", "getNoCornerKey");
	addToMap(classes, "GJSmartTemplate", "getSimplifiedKey");
	addToMap(classes, "GJSmartTemplate", "getTotalChanceForPrefab");
	addToMap(classes, "GJSmartTemplate", "getVerySimplifiedKey");
	addToMap(classes, "GJSmartTemplate", "isUnrequired");
	addToMap(classes, "GJSmartTemplate", "keyFromNeighbors");
	addToMap(classes, "GJSmartTemplate", "logTemplateStatus");
	addToMap(classes, "GJSmartTemplate", "rotateKey");
	addToMap(classes, "GJSongBrowser", "init");
	addToMap(classes, "GJSongBrowser", "cellPerformedAction");
	addToMap(classes, "GJSongBrowser", "getSelectedCellIdx");
	addToMap(classes, "GJSpecialColorSelect", "textForColorIdx");
	addToMap(classes, "GJSpecialColorSelect", "init");
	addToMap(classes, "GJTransformControl", "init");
	addToMap(classes, "GJTransformControl", "ccTouchBegan");
	addToMap(classes, "GJUINode", "activeTouchTest");
	addToMap(classes, "GJUINode", "init");
	addToMap(classes, "GJUINode", "touchTest");
	addToMap(classes, "GJUserCell", "init");
	addToMap(classes, "GJUserMessage", "init");
	addToMap(classes, "GJUserScore", "init");
	addToMap(classes, "GJUserScore", "isCurrentUser");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJWorldNode", "addDotsToLevel");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJWorldNode", "init");
	#endif
	addToMap(classes, "GJWriteMessagePopup", "init");
	addToMap(classes, "GManager", "init");
	addToMap(classes, "GManager", "getCompressedSaveString");
	addToMap(classes, "GradientTriggerObject", "init");
	addToMap(classes, "GradientTriggerObject", "getSaveString");
	addToMap(classes, "GravityEffectSprite", "init");
	addToMap(classes, "HardStreak", "init");
	addToMap(classes, "HSVLiveOverlay", "init");
	addToMap(classes, "HSVWidgetPopup", "init");
	addToMap(classes, "InfoLayer", "init");
	addToMap(classes, "InfoLayer", "isCorrect");
	addToMap(classes, "ItemInfoPopup", "nameForUnlockType");
	addToMap(classes, "ItemInfoPopup", "init");
	addToMap(classes, "ItemTriggerGameObject", "getSaveString");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsLayer", "init");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsLayer", "countForPage");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsManager", "commandForKey");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsManager", "commandForKeyMods");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
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
	addToMap(classes, "LevelBrowserLayer", "cellPerformedAction");
	addToMap(classes, "LevelBrowserLayer", "getSearchTitle");
	addToMap(classes, "LevelBrowserLayer", "init");
	addToMap(classes, "LevelBrowserLayer", "isCorrect");
	addToMap(classes, "LevelCell", "init");
	addToMap(classes, "LevelEditorLayer", "timeForPos");
	addToMap(classes, "LevelEditorLayer", "activateTriggerEffect");
	addToMap(classes, "LevelEditorLayer", "getLastObjectX");
	addToMap(classes, "LevelEditorLayer", "getLevelString");
	addToMap(classes, "LevelEditorLayer", "getNextColorChannel");
	addToMap(classes, "LevelEditorLayer", "getNextFreeAreaEffectID");
	addToMap(classes, "LevelEditorLayer", "getNextFreeEditorLayer");
	addToMap(classes, "LevelEditorLayer", "getNextFreeEnterChannel");
	addToMap(classes, "LevelEditorLayer", "getNextFreeGradientID");
	addToMap(classes, "LevelEditorLayer", "getNextFreeGroupID");
	addToMap(classes, "LevelEditorLayer", "getNextFreeItemID");
	addToMap(classes, "LevelEditorLayer", "getNextFreeOrderChannel");
	addToMap(classes, "LevelEditorLayer", "getSFXIDs");
	addToMap(classes, "LevelEditorLayer", "getSongIDs");
	addToMap(classes, "LevelEditorLayer", "init");
	addToMap(classes, "LevelEditorLayer", "rotationForSlopeNearObject");
	addToMap(classes, "LevelEditorLayer", "shouldBlend");
	addToMap(classes, "LevelEditorLayer", "tryUpdateSpeedObject");
	addToMap(classes, "LevelEditorLayer", "typeExistsAtPosition");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "LevelFeatureLayer", "init");
	#endif
	addToMap(classes, "LevelInfoLayer", "cellPerformedAction");
	addToMap(classes, "LevelInfoLayer", "init");
	addToMap(classes, "LevelInfoLayer", "shouldDownloadLevel");
	addToMap(classes, "LevelLeaderboard", "init");
	addToMap(classes, "LevelLeaderboard", "isCorrect");
	addToMap(classes, "LevelListLayer", "cellPerformedAction");
	addToMap(classes, "LevelListLayer", "init");
	addToMap(classes, "LevelOptionsLayer", "getValue");
	addToMap(classes, "LevelOptionsLayer", "init");
	addToMap(classes, "LevelPage", "ccTouchBegan");
	addToMap(classes, "LevelPage", "init");
	addToMap(classes, "LevelSearchLayer", "checkDiff");
	addToMap(classes, "LevelSearchLayer", "checkTime");
	addToMap(classes, "LevelSearchLayer", "init");
	addToMap(classes, "LevelSelectLayer", "init");
	addToMap(classes, "LevelSettingsLayer", "init");
	addToMap(classes, "LevelSettingsObject", "init");
	addToMap(classes, "LevelSettingsObject", "getSaveString");
	addToMap(classes, "LevelTools", "artistForAudio");
	addToMap(classes, "LevelTools", "fbURLForArtist");
	addToMap(classes, "LevelTools", "getAudioFileName");
	addToMap(classes, "LevelTools", "getAudioString");
	addToMap(classes, "LevelTools", "getAudioTitle");
	addToMap(classes, "LevelTools", "nameForArtist");
	addToMap(classes, "LevelTools", "ngURLForArtist");
	addToMap(classes, "LevelTools", "timeForPos");
	addToMap(classes, "LevelTools", "urlForAudio");
	addToMap(classes, "LevelTools", "verifyLevelIntegrity");
	addToMap(classes, "LevelTools", "ytURLForArtist");
	addToMap(classes, "LikeItemLayer", "init");
	addToMap(classes, "ListButtonBar", "init");
	addToMap(classes, "LoadingCircle", "init");
	addToMap(classes, "LoadingLayer", "getLoadingString");
	addToMap(classes, "LoadingLayer", "init");
	addToMap(classes, "LocalLevelManager", "init");
	addToMap(classes, "LocalLevelManager", "getMainLevelString");
	addToMap(classes, "LocalLevelManager", "updateLevelOrder");
	addToMap(classes, "MapPackCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MapSelectLayer", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MapSelectLayer", "ccTouchBegan");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MapSelectLayer", "checkTouchMonster");
	#endif
	addToMap(classes, "MenuGameLayer", "init");
	addToMap(classes, "MenuGameLayer", "ccTouchBegan");
	addToMap(classes, "MenuLayer", "init");
	addToMap(classes, "MessagesProfilePage", "init");
	addToMap(classes, "MessagesProfilePage", "isCorrect");
	addToMap(classes, "MoreOptionsLayer", "init");
	addToMap(classes, "MoreOptionsLayer", "countForPage");
	addToMap(classes, "MoreSearchLayer", "init");
	addToMap(classes, "MoreVideoOptionsLayer", "init");
	addToMap(classes, "MoreVideoOptionsLayer", "countForPage");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MPLobbyLayer", "init");
	#endif
	addToMap(classes, "MultilineBitmapFont", "initWithFont");
	addToMap(classes, "MultilineBitmapFont", "readColorInfo");
	addToMap(classes, "MultilineBitmapFont", "stringWithMaxWidth");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MultiplayerLayer", "init");
	#endif
	addToMap(classes, "MultiTriggerPopup", "init");
	addToMap(classes, "MusicBrowser", "cellPerformedAction");
	addToMap(classes, "MusicBrowser", "getSelectedCellIdx");
	addToMap(classes, "MusicBrowser", "init");
	addToMap(classes, "MusicDownloadManager", "init");
	addToMap(classes, "MusicDownloadManager", "generateCustomContentURL");
	addToMap(classes, "MusicDownloadManager", "getSFXFolderPathForID");
	addToMap(classes, "MusicDownloadManager", "isRunningActionForSongID");
	addToMap(classes, "MusicDownloadManager", "isSFXDownloaded");
	addToMap(classes, "MusicDownloadManager", "isSongDownloaded");
	addToMap(classes, "MusicDownloadManager", "pathForSFX");
	addToMap(classes, "MusicDownloadManager", "pathForSFXFolder");
	addToMap(classes, "MusicDownloadManager", "pathForSong");
	addToMap(classes, "MusicDownloadManager", "pathForSongFolder");
	addToMap(classes, "NCSInfoLayer", "init");
	addToMap(classes, "NewgroundsInfoLayer", "init");
	addToMap(classes, "NumberInputLayer", "init");
	addToMap(classes, "OBB2D", "overlaps1Way");
	addToMap(classes, "ObjectControlGameObject", "init");
	addToMap(classes, "ObjectControlGameObject", "getSaveString");
	addToMap(classes, "ObjectManager", "init");
	addToMap(classes, "ObjectToolbox", "init");
	addToMap(classes, "ObjectToolbox", "gridNodeSizeForKey");
	addToMap(classes, "ObjectToolbox", "intKeyToFrame");
	addToMap(classes, "ObjectToolbox", "perspectiveBlockFrame");
	addToMap(classes, "OptionsScrollLayer", "cellPerformedAction");
	addToMap(classes, "ParentalOptionsLayer", "init");
	addToMap(classes, "ParentalOptionsLayer", "countForPage");
	addToMap(classes, "ParticleGameObject", "init");
	addToMap(classes, "ParticleGameObject", "getSaveString");
	addToMap(classes, "PlatformToolbox", "copyToClipboard");
	addToMap(classes, "PlatformToolbox", "getUniqueUserID");
	addToMap(classes, "PlayerCheckpoint", "init");
	addToMap(classes, "PlayerControlGameObject", "init");
	addToMap(classes, "PlayerControlGameObject", "getSaveString");
	addToMap(classes, "PlayerFireBoostSprite", "init");
	addToMap(classes, "PlayerObject", "getObjectRotation");
	addToMap(classes, "PlayerObject", "collidedWithObject");
	addToMap(classes, "PlayerObject", "collidedWithObjectInternal");
	addToMap(classes, "PlayerObject", "convertToClosestRotation");
	addToMap(classes, "PlayerObject", "handleRotatedCollisionInternal");
	addToMap(classes, "PlayerObject", "init");
	addToMap(classes, "PlayerObject", "levelFlipping");
	addToMap(classes, "PlayerObject", "playerIsFallingBugged");
	addToMap(classes, "PlayerObject", "preSlopeCollision");
	addToMap(classes, "PlayerObject", "pushButton");
	addToMap(classes, "PlayerObject", "releaseButton");
	addToMap(classes, "PlayerObject", "switchedDirTo");
	addToMap(classes, "PlayLayer", "opacityForObject");
	addToMap(classes, "PlayLayer", "timeForPos");
	addToMap(classes, "PlayLayer", "getCurrentPercent");
	addToMap(classes, "PlayLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PriceLabel", "init");
	#endif
	addToMap(classes, "ProfilePage", "init");
	addToMap(classes, "ProfilePage", "isCorrect");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PromoInterstitial", "ccTouchBegan");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PromoInterstitial", "init");
	#endif
	addToMap(classes, "PurchaseItemPopup", "init");
	addToMap(classes, "RandTriggerGameObject", "init");
	addToMap(classes, "RandTriggerGameObject", "getSaveString");
	addToMap(classes, "RateDemonLayer", "init");
	addToMap(classes, "RateLevelLayer", "init");
	addToMap(classes, "RateStarsLayer", "init");
	addToMap(classes, "RewardsPage", "init");
	addToMap(classes, "RewardUnlockLayer", "init");
	addToMap(classes, "RewardUnlockLayer", "showCollectReward");
	addToMap(classes, "RingObject", "getSaveString");
	addToMap(classes, "RingObject", "shouldDrawEditorHitbox");
	addToMap(classes, "RotateGameplayGameObject", "init");
	addToMap(classes, "RotateGameplayGameObject", "getSaveString");
	addToMap(classes, "ScrollingLayer", "ccTouchBegan");
	addToMap(classes, "SearchButton", "init");
	addToMap(classes, "SearchSFXPopup", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SecretGame01Layer", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SecretGame01Layer", "getCountForDifficulty");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SecretGame01Layer", "getFrameForDifficulty");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SecretGame01Layer", "getRowsForDifficulty");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
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
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
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
	addToMap(classes, "SelectSettingLayer", "init");
	addToMap(classes, "SelectSFXSortLayer", "init");
	addToMap(classes, "SequenceTriggerGameObject", "init");
	addToMap(classes, "SequenceTriggerGameObject", "getSaveString");
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
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
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
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
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
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
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
	addToMap(classes, "SetupTriggerPopup", "getTriggerValue");
	addToMap(classes, "SetupTriggerPopup", "init");
	addToMap(classes, "SetupZoomTriggerPopup", "init");
	addToMap(classes, "SFXBrowser", "cellPerformedAction");
	addToMap(classes, "SFXBrowser", "getSelectedCellIdx");
	addToMap(classes, "SFXBrowser", "shouldSnapToSelected");
	addToMap(classes, "SFXBrowser", "init");
	addToMap(classes, "SFXSearchResult", "getSelectedPage");
	addToMap(classes, "SFXTriggerGameObject", "getSaveString");
	addToMap(classes, "ShaderGameObject", "getSaveString");
	addToMap(classes, "ShaderLayer", "init");
	addToMap(classes, "ShaderLayer", "resetAllShaders");
	addToMap(classes, "ShaderLayer", "updateZLayer");
	addToMap(classes, "ShardsPage", "init");
	addToMap(classes, "ShareCommentLayer", "init");
	addToMap(classes, "ShareLevelLayer", "init");
	addToMap(classes, "ShareLevelSettingsLayer", "init");
	addToMap(classes, "ShareListLayer", "init");
	addToMap(classes, "SimplePlayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SlideInLayer", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SlideInLayer", "ccTouchBegan");
	#endif
	addToMap(classes, "Slider", "ccTouchBegan");
	addToMap(classes, "Slider", "init");
	addToMap(classes, "SliderThumb", "getValue");
	addToMap(classes, "SliderTouchLogic", "ccTouchBegan");
	addToMap(classes, "SmartGameObject", "getSaveString");
	addToMap(classes, "SmartTemplateCell", "init");
	addToMap(classes, "SongCell", "init");
	addToMap(classes, "SongInfoLayer", "init");
	addToMap(classes, "SongInfoObject", "getArtistNames");
	addToMap(classes, "SongInfoObject", "getTagsString");
	addToMap(classes, "SongInfoObject", "init");
	addToMap(classes, "SongOptionsLayer", "init");
	addToMap(classes, "SongSelectNode", "getActiveSongID");
	addToMap(classes, "SongSelectNode", "getSongFileName");
	addToMap(classes, "SongSelectNode", "init");
	addToMap(classes, "SongTriggerGameObject", "getSaveString");
	addToMap(classes, "SpawnParticleGameObject", "init");
	addToMap(classes, "SpawnParticleGameObject", "getSaveString");
	addToMap(classes, "SpawnTriggerGameObject", "init");
	addToMap(classes, "SpawnTriggerGameObject", "getSaveString");
	addToMap(classes, "SpecialAnimGameObject", "getSaveString");
	addToMap(classes, "SpriteAnimationManager", "getPrio");
	addToMap(classes, "SpriteAnimationManager", "initWithOwner");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SpriteDescription", "initDescription");
	#endif
	addToMap(classes, "StarInfoPopup", "init");
	addToMap(classes, "StartPosObject", "init");
	addToMap(classes, "StartPosObject", "getSaveString");
	addToMap(classes, "StatsCell", "getTitleFromKey");
	addToMap(classes, "TableView", "ccTouchBegan");
	addToMap(classes, "TableView", "checkBoundaryOfCell");
	addToMap(classes, "TableView", "checkBoundaryOfCell");
	addToMap(classes, "TableView", "isDuplicateIndexPath");
	addToMap(classes, "TableView", "isDuplicateInVisibleCellArray");
	addToMap(classes, "TeleportPortalObject", "getSaveString");
	addToMap(classes, "TeleportPortalObject", "addToGroup");
	addToMap(classes, "TeleportPortalObject", "getTeleportXOff");
	addToMap(classes, "TextAlertPopup", "init");
	addToMap(classes, "TextArea", "fadeInCharacters");
	addToMap(classes, "TextGameObject", "getSaveString");
	addToMap(classes, "TextGameObject", "getTextKerning");
	addToMap(classes, "TimerTriggerGameObject", "getSaveString");
	addToMap(classes, "TopArtistsLayer", "init");
	addToMap(classes, "TOSPopup", "init");
	addToMap(classes, "TransformTriggerGameObject", "getSaveString");
	addToMap(classes, "TriggerControlGameObject", "getSaveString");
	addToMap(classes, "TutorialLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "TutorialPopup", "init");
	#endif
	addToMap(classes, "UILayer", "ccTouchBegan");
	addToMap(classes, "UILayer", "init");
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
	addToMap(classes, "UpdateAccountSettingsPopup", "init");
	addToMap(classes, "UploadActionPopup", "init");
	addToMap(classes, "UploadListPopup", "init");
	addToMap(classes, "UploadPopup", "init");
	addToMap(classes, "URLCell", "init");
	addToMap(classes, "VideoOptionsLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "WorldLevelPage", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
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
