// Generated using 'generate.py'
#include <map>
#include <string>

using ScrewYouFuncsT = std::map<std::string, std::vector<std::string>>;

constexpr void addToMap(ScrewYouFuncsT& map, std::string clazz, std::string func) {
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
	addToMap(classes, "AchievementBar", "init");
	addToMap(classes, "AchievementManager", "init");
	addToMap(classes, "AchievementNotifier", "init");
	addToMap(classes, "AnimatedGameObject", "init");
	addToMap(classes, "ArtistCell", "init");
	addToMap(classes, "AudioAssetsBrowser", "init");
	addToMap(classes, "AudioEffectsLayer", "init");
	addToMap(classes, "AudioLineGuideGameObject", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "BonusDropdown", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "BoomListLayer", "init");
	#endif
	addToMap(classes, "BoomListView", "init");
	addToMap(classes, "BoomScrollLayer", "init");
	addToMap(classes, "BrowseSmartKeyLayer", "init");
	addToMap(classes, "BrowseSmartTemplateLayer", "init");
	addToMap(classes, "ButtonSprite", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "CCAlertCircle", "init");
	#endif
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
	addToMap(classes, "CCTextInputNode", "init");
	addToMap(classes, "ChallengeNode", "init");
	addToMap(classes, "ChallengesPage", "init");
	addToMap(classes, "CharacterColorPage", "init");
	addToMap(classes, "CheckpointGameObject", "init");
	addToMap(classes, "CheckpointObject", "init");
	addToMap(classes, "CollisionBlockPopup", "init");
	addToMap(classes, "ColorActionSprite", "init");
	addToMap(classes, "ColorChannelSprite", "init");
	addToMap(classes, "ColorSelectLiveOverlay", "init");
	addToMap(classes, "ColorSelectPopup", "init");
	addToMap(classes, "CommentCell", "init");
	addToMap(classes, "CommunityCreditsPage", "init");
	addToMap(classes, "ConfigureHSVWidget", "init");
	addToMap(classes, "ConfigureValuePopup", "init");
	addToMap(classes, "CreateGuidelinesLayer", "init");
	addToMap(classes, "CreateParticlePopup", "init");
	addToMap(classes, "CreatorLayer", "init");
	addToMap(classes, "CurrencyRewardLayer", "init");
	addToMap(classes, "CurrencySprite", "init");
	addToMap(classes, "CustomizeObjectLayer", "init");
	addToMap(classes, "CustomizeObjectSettingsPopup", "init");
	addToMap(classes, "CustomSFXCell", "init");
	addToMap(classes, "CustomSFXWidget", "init");
	addToMap(classes, "CustomSongCell", "init");
	addToMap(classes, "CustomSongLayer", "init");
	addToMap(classes, "CustomSongWidget", "init");
	addToMap(classes, "DailyLevelNode", "init");
	addToMap(classes, "DailyLevelPage", "init");
	addToMap(classes, "DemonFilterSelectLayer", "init");
	addToMap(classes, "DemonInfoPopup", "init");
	addToMap(classes, "DialogLayer", "init");
	addToMap(classes, "DungeonBarsSprite", "init");
	addToMap(classes, "EditGameObjectPopup", "init");
	addToMap(classes, "EditLevelLayer", "init");
	addToMap(classes, "EditorOptionsLayer", "init");
	addToMap(classes, "EditorPauseLayer", "init");
	addToMap(classes, "EditorUI", "init");
	addToMap(classes, "EditTriggersPopup", "init");
	addToMap(classes, "EndPortalObject", "init");
	addToMap(classes, "EndTriggerGameObject", "init");
	addToMap(classes, "EnhancedGameObject", "init");
	addToMap(classes, "EventLinkTrigger", "init");
	addToMap(classes, "ExplodeItemSprite", "init");
	addToMap(classes, "ExtendedLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "FileSaveManager", "init");
	#endif
	addToMap(classes, "FindObjectPopup", "init");
	addToMap(classes, "FLAlertLayer", "init");
	addToMap(classes, "FMODLevelVisualizer", "init");
	addToMap(classes, "FollowRewardPage", "init");
	addToMap(classes, "FRequestProfilePage", "init");
	addToMap(classes, "FriendRequestPopup", "init");
	addToMap(classes, "FriendsProfilePage", "init");
	addToMap(classes, "GameCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GameEffectsManager", "init");
	#endif
	addToMap(classes, "GameLevelManager", "init");
	addToMap(classes, "GameManager", "init");
	addToMap(classes, "GameStatsManager", "init");
	addToMap(classes, "GauntletLayer", "init");
	addToMap(classes, "GauntletNode", "init");
	addToMap(classes, "GauntletSelectLayer", "init");
	addToMap(classes, "GhostTrailEffect", "init");
	addToMap(classes, "GJAccountManager", "init");
	addToMap(classes, "GJAccountSettingsLayer", "init");
	addToMap(classes, "GJActionManager", "init");
	addToMap(classes, "GJBaseGameLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBigSprite", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJBigSpriteNode", "init");
	#endif
	addToMap(classes, "GJColorSetupLayer", "init");
	addToMap(classes, "GJComment", "init");
	addToMap(classes, "GJCommentListLayer", "init");
	addToMap(classes, "GJDropDownLayer", "init");
	addToMap(classes, "GJEffectManager", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJFlyGroundLayer", "init");
	#endif
	addToMap(classes, "GJFollowCommandLayer", "init");
	addToMap(classes, "GJFriendRequest", "init");
	addToMap(classes, "GJGameLevel", "init");
	addToMap(classes, "GJGarageLayer", "init");
	addToMap(classes, "GJGradientLayer", "init");
	addToMap(classes, "GJGroundLayer", "init");
	addToMap(classes, "GJItemIcon", "init");
	addToMap(classes, "GJLevelList", "init");
	addToMap(classes, "GJLevelScoreCell", "init");
	addToMap(classes, "GJListLayer", "init");
	addToMap(classes, "GJLocalLevelScoreCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJMapObject", "init");
	#endif
	addToMap(classes, "GJMapPack", "init");
	addToMap(classes, "GJMessageCell", "init");
	addToMap(classes, "GJMessagePopup", "init");
	addToMap(classes, "GJMGLayer", "init");
	addToMap(classes, "GJMultiplayerManager", "init");
	addToMap(classes, "GJObjectDecoder", "init");
	addToMap(classes, "GJOptionsLayer", "init");
	addToMap(classes, "GJPathPage", "init");
	addToMap(classes, "GJPathRewardPopup", "init");
	addToMap(classes, "GJPathsLayer", "init");
	addToMap(classes, "GJPFollowCommandLayer", "init");
	addToMap(classes, "GJPromoPopup", "init");
	addToMap(classes, "GJRequestCell", "init");
	addToMap(classes, "GJRewardItem", "init");
	addToMap(classes, "GJRobotSprite", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJRotateCommandLayer", "init");
	#endif
	addToMap(classes, "GJRotationControl", "init");
	addToMap(classes, "GJScaleControl", "init");
	addToMap(classes, "GJScoreCell", "init");
	addToMap(classes, "GJShopLayer", "init");
	addToMap(classes, "GJSmartBlockPreviewSprite", "init");
	addToMap(classes, "GJSongBrowser", "init");
	addToMap(classes, "GJSpecialColorSelect", "init");
	addToMap(classes, "GJTransformControl", "init");
	addToMap(classes, "GJUINode", "init");
	addToMap(classes, "GJUserCell", "init");
	addToMap(classes, "GJUserMessage", "init");
	addToMap(classes, "GJUserScore", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "GJWorldNode", "init");
	#endif
	addToMap(classes, "GJWriteMessagePopup", "init");
	addToMap(classes, "GManager", "init");
	addToMap(classes, "GradientTriggerObject", "init");
	addToMap(classes, "GravityEffectSprite", "init");
	addToMap(classes, "HardStreak", "init");
	addToMap(classes, "HSVLiveOverlay", "init");
	addToMap(classes, "HSVWidgetPopup", "init");
	addToMap(classes, "InfoLayer", "init");
	addToMap(classes, "ItemInfoPopup", "init");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "KeybindingsLayer", "init");
	#endif
	addToMap(classes, "KeyframeAnimTriggerObject", "init");
	addToMap(classes, "KeyframeGameObject", "init");
	addToMap(classes, "LabelGameObject", "init");
	addToMap(classes, "LeaderboardsLayer", "init");
	addToMap(classes, "LevelAreaInnerLayer", "init");
	addToMap(classes, "LevelAreaLayer", "init");
	addToMap(classes, "LevelBrowserLayer", "init");
	addToMap(classes, "LevelCell", "init");
	addToMap(classes, "LevelEditorLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "LevelFeatureLayer", "init");
	#endif
	addToMap(classes, "LevelInfoLayer", "init");
	addToMap(classes, "LevelLeaderboard", "init");
	addToMap(classes, "LevelListLayer", "init");
	addToMap(classes, "LevelOptionsLayer", "init");
	addToMap(classes, "LevelPage", "init");
	addToMap(classes, "LevelSearchLayer", "init");
	addToMap(classes, "LevelSelectLayer", "init");
	addToMap(classes, "LevelSettingsLayer", "init");
	addToMap(classes, "LevelSettingsObject", "init");
	addToMap(classes, "LikeItemLayer", "init");
	addToMap(classes, "ListButtonBar", "init");
	addToMap(classes, "LoadingCircle", "init");
	addToMap(classes, "LoadingLayer", "init");
	addToMap(classes, "LocalLevelManager", "init");
	addToMap(classes, "MapPackCell", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MapSelectLayer", "init");
	#endif
	addToMap(classes, "MenuGameLayer", "init");
	addToMap(classes, "MenuLayer", "init");
	addToMap(classes, "MessagesProfilePage", "init");
	addToMap(classes, "MoreOptionsLayer", "init");
	addToMap(classes, "MoreSearchLayer", "init");
	addToMap(classes, "MoreVideoOptionsLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MPLobbyLayer", "init");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "MultiplayerLayer", "init");
	#endif
	addToMap(classes, "MultiTriggerPopup", "init");
	addToMap(classes, "MusicBrowser", "init");
	addToMap(classes, "MusicDownloadManager", "init");
	addToMap(classes, "NCSInfoLayer", "init");
	addToMap(classes, "NewgroundsInfoLayer", "init");
	addToMap(classes, "NumberInputLayer", "init");
	addToMap(classes, "ObjectControlGameObject", "init");
	addToMap(classes, "ObjectManager", "init");
	addToMap(classes, "ObjectToolbox", "init");
	addToMap(classes, "ParentalOptionsLayer", "init");
	addToMap(classes, "ParticleGameObject", "init");
	addToMap(classes, "PlayerCheckpoint", "init");
	addToMap(classes, "PlayerControlGameObject", "init");
	addToMap(classes, "PlayerFireBoostSprite", "init");
	addToMap(classes, "PlayerObject", "init");
	addToMap(classes, "PlayLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PriceLabel", "init");
	#endif
	addToMap(classes, "ProfilePage", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "PromoInterstitial", "init");
	#endif
	addToMap(classes, "PurchaseItemPopup", "init");
	addToMap(classes, "RandTriggerGameObject", "init");
	addToMap(classes, "RateDemonLayer", "init");
	addToMap(classes, "RateLevelLayer", "init");
	addToMap(classes, "RateStarsLayer", "init");
	addToMap(classes, "RewardsPage", "init");
	addToMap(classes, "RewardUnlockLayer", "init");
	addToMap(classes, "RotateGameplayGameObject", "init");
	addToMap(classes, "SearchButton", "init");
	addToMap(classes, "SearchSFXPopup", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SecretGame01Layer", "init");
	#endif
	addToMap(classes, "SecretLayer", "init");
	addToMap(classes, "SecretLayer2", "init");
	addToMap(classes, "SecretLayer3", "init");
	addToMap(classes, "SecretLayer4", "init");
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
	addToMap(classes, "SelectSettingLayer", "init");
	addToMap(classes, "SelectSFXSortLayer", "init");
	addToMap(classes, "SequenceTriggerGameObject", "init");
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
	addToMap(classes, "SetupEnterEffectPopup", "init");
	addToMap(classes, "SetupEnterTriggerPopup", "init");
	addToMap(classes, "SetupEventLinkPopup", "init");
	addToMap(classes, "SetupForceBlockPopup", "init");
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
	addToMap(classes, "SetupRotateCommandPopup", "init");
	addToMap(classes, "SetupRotateGameplayPopup", "init");
	addToMap(classes, "SetupRotatePopup", "init");
	addToMap(classes, "SetupSequenceTriggerPopup", "init");
	addToMap(classes, "SetupSFXEditPopup", "init");
	addToMap(classes, "SetupSFXPopup", "init");
	addToMap(classes, "SetupShaderEffectPopup", "init");
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
	addToMap(classes, "SetupTriggerPopup", "init");
	addToMap(classes, "SetupZoomTriggerPopup", "init");
	addToMap(classes, "SFXBrowser", "init");
	addToMap(classes, "ShaderLayer", "init");
	addToMap(classes, "ShardsPage", "init");
	addToMap(classes, "ShareCommentLayer", "init");
	addToMap(classes, "ShareLevelLayer", "init");
	addToMap(classes, "ShareLevelSettingsLayer", "init");
	addToMap(classes, "ShareListLayer", "init");
	addToMap(classes, "SimplePlayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "SlideInLayer", "init");
	#endif
	addToMap(classes, "Slider", "init");
	addToMap(classes, "SmartTemplateCell", "init");
	addToMap(classes, "SongCell", "init");
	addToMap(classes, "SongInfoLayer", "init");
	addToMap(classes, "SongInfoObject", "init");
	addToMap(classes, "SongOptionsLayer", "init");
	addToMap(classes, "SongSelectNode", "init");
	addToMap(classes, "SpawnParticleGameObject", "init");
	addToMap(classes, "SpawnTriggerGameObject", "init");
	addToMap(classes, "StarInfoPopup", "init");
	addToMap(classes, "StartPosObject", "init");
	addToMap(classes, "TextAlertPopup", "init");
	addToMap(classes, "TopArtistsLayer", "init");
	addToMap(classes, "TOSPopup", "init");
	addToMap(classes, "TutorialLayer", "init");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	addToMap(classes, "TutorialPopup", "init");
	#endif
	addToMap(classes, "UILayer", "init");
	addToMap(classes, "UIObjectSettingsPopup", "init");
	addToMap(classes, "UIOptionsLayer", "init");
	addToMap(classes, "UIPOptionsLayer", "init");
	addToMap(classes, "UISaveLoadLayer", "init");
	addToMap(classes, "UISettingsGameObject", "init");
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
