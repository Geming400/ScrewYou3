// Generated using 'generate.py'
#include <vector>
#include <string>

constexpr std::vector<std::string> getClasses() {
    std::vector<std::string> classes;
	classes.push_back("AccountLoginLayer");
	classes.push_back("AccountRegisterLayer");
	classes.push_back("AchievementBar");
	classes.push_back("AchievementManager");
	classes.push_back("AchievementNotifier");
	classes.push_back("AnimatedGameObject");
	classes.push_back("ArtistCell");
	classes.push_back("AudioAssetsBrowser");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID
	classes.push_back("AudioEffectsLayer");
	#endif
	classes.push_back("AudioLineGuideGameObject");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("BonusDropdown");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("BoomListLayer");
	#endif
	classes.push_back("BoomListView");
	classes.push_back("BoomScrollLayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("BrowseSmartKeyLayer");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("BrowseSmartTemplateLayer");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("ButtonSprite");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("CCAlertCircle");
	#endif
	classes.push_back("CCBlockLayer");
	classes.push_back("CCCircleWave");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("CCCountdown");
	#endif
	classes.push_back("CCMenuItemSpriteExtra");
	classes.push_back("CCNodeContainer");
	classes.push_back("CCTextInputNode");
	classes.push_back("ChallengeNode");
	classes.push_back("ChallengesPage");
	classes.push_back("CharacterColorPage");
	classes.push_back("CheckpointGameObject");
	classes.push_back("CheckpointObject");
	classes.push_back("CollisionBlockPopup");
	classes.push_back("ColorActionSprite");
	classes.push_back("ColorChannelSprite");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("ColorSelectLiveOverlay");
	#endif
	classes.push_back("ColorSelectPopup");
	classes.push_back("CommentCell");
	classes.push_back("CommunityCreditsPage");
	classes.push_back("ConfigureHSVWidget");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("ConfigureValuePopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("CreateGuidelinesLayer");
	#endif
	classes.push_back("CreateParticlePopup");
	classes.push_back("CreatorLayer");
	classes.push_back("CurrencyRewardLayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("CurrencySprite");
	#endif
	classes.push_back("CustomizeObjectLayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("CustomizeObjectSettingsPopup");
	#endif
	classes.push_back("CustomSFXCell");
	classes.push_back("CustomSFXWidget");
	classes.push_back("CustomSongCell");
	classes.push_back("CustomSongLayer");
	classes.push_back("CustomSongWidget");
	classes.push_back("DailyLevelNode");
	classes.push_back("DailyLevelPage");
	classes.push_back("DemonFilterSelectLayer");
	classes.push_back("DemonInfoPopup");
	classes.push_back("DialogLayer");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	classes.push_back("DrawGridLayer");
	#endif
	classes.push_back("DungeonBarsSprite");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("EditButtonBar");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("EditGameObjectPopup");
	#endif
	classes.push_back("EditLevelLayer");
	classes.push_back("EditorOptionsLayer");
	classes.push_back("EditorPauseLayer");
	classes.push_back("EditorUI");
	classes.push_back("EditTriggersPopup");
	classes.push_back("EffectGameObject");
	classes.push_back("EndPortalObject");
	classes.push_back("EndTriggerGameObject");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID
	classes.push_back("EnhancedGameObject");
	#endif
	classes.push_back("EventLinkTrigger");
	classes.push_back("ExplodeItemSprite");
	classes.push_back("ExtendedLayer");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("FileSaveManager");
	#endif
	classes.push_back("FindObjectPopup");
	classes.push_back("FLAlertLayer");
	classes.push_back("FMODLevelVisualizer");
	classes.push_back("FollowRewardPage");
	classes.push_back("FRequestProfilePage");
	classes.push_back("FriendRequestPopup");
	classes.push_back("FriendsProfilePage");
	classes.push_back("GameCell");
	classes.push_back("GameLevelManager");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GameLevelOptionsLayer");
	#endif
	classes.push_back("GameManager");
	classes.push_back("GameStatsManager");
	classes.push_back("GauntletLayer");
	classes.push_back("GauntletNode");
	classes.push_back("GauntletSelectLayer");
	classes.push_back("GhostTrailEffect");
	classes.push_back("GJAccountManager");
	classes.push_back("GJAccountSettingsLayer");
	classes.push_back("GJActionManager");
	classes.push_back("GJBaseGameLayer");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJBigSprite");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJBigSpriteNode");
	#endif
	classes.push_back("GJColorSetupLayer");
	classes.push_back("GJComment");
	classes.push_back("GJCommentListLayer");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJDifficultySprite");
	#endif
	classes.push_back("GJDropDownLayer");
	classes.push_back("GJEffectManager");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJFlyGroundLayer");
	#endif
	classes.push_back("GJFollowCommandLayer");
	classes.push_back("GJFriendRequest");
	classes.push_back("GJGameLevel");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC || defined GEODE_IS_IOS
	classes.push_back("GJGameLoadingLayer");
	#endif
	classes.push_back("GJGarageLayer");
	classes.push_back("GJGradientLayer");
	classes.push_back("GJGroundLayer");
	classes.push_back("GJItemIcon");
	classes.push_back("GJLevelList");
	classes.push_back("GJLevelScoreCell");
	classes.push_back("GJListLayer");
	classes.push_back("GJLocalLevelScoreCell");
	classes.push_back("GJMapPack");
	classes.push_back("GJMessageCell");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID
	classes.push_back("GJMessagePopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJMGLayer");
	#endif
	classes.push_back("GJMultiplayerManager");
	classes.push_back("GJObjectDecoder");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJOptionsLayer");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJPathPage");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJPathRewardPopup");
	#endif
	classes.push_back("GJPathsLayer");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJPathSprite");
	#endif
	classes.push_back("GJPFollowCommandLayer");
	classes.push_back("GJPromoPopup");
	classes.push_back("GJRequestCell");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJRewardItem");
	#endif
	classes.push_back("GJRobotSprite");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJRotateCommandLayer");
	#endif
	classes.push_back("GJRotationControl");
	classes.push_back("GJScaleControl");
	classes.push_back("GJScoreCell");
	classes.push_back("GJShopLayer");
	classes.push_back("GJSmartBlockPreviewSprite");
	classes.push_back("GJSongBrowser");
	classes.push_back("GJSpecialColorSelect");
	classes.push_back("GJTransformControl");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJUINode");
	#endif
	classes.push_back("GJUserCell");
	classes.push_back("GJUserMessage");
	classes.push_back("GJUserScore");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJWorldNode");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("GJWriteMessagePopup");
	#endif
	classes.push_back("GManager");
	classes.push_back("GradientTriggerObject");
	classes.push_back("GravityEffectSprite");
	classes.push_back("HardStreak");
	classes.push_back("HSVLiveOverlay");
	classes.push_back("HSVWidgetPopup");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("InfoAlertButton");
	#endif
	classes.push_back("InfoLayer");
	classes.push_back("ItemInfoPopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("KeybindingsLayer");
	#endif
	classes.push_back("KeyframeAnimTriggerObject");
	classes.push_back("KeyframeGameObject");
	classes.push_back("LabelGameObject");
	classes.push_back("LeaderboardsLayer");
	classes.push_back("LevelAreaInnerLayer");
	classes.push_back("LevelAreaLayer");
	classes.push_back("LevelBrowserLayer");
	classes.push_back("LevelCell");
	classes.push_back("LevelEditorLayer");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("LevelFeatureLayer");
	#endif
	classes.push_back("LevelInfoLayer");
	classes.push_back("LevelLeaderboard");
	classes.push_back("LevelListLayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("LevelOptionsLayer");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("LevelOptionsLayer2");
	#endif
	classes.push_back("LevelPage");
	classes.push_back("LevelSearchLayer");
	classes.push_back("LevelSelectLayer");
	classes.push_back("LevelSettingsLayer");
	classes.push_back("LevelSettingsObject");
	classes.push_back("LikeItemLayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("ListButtonBar");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("ListButtonPage");
	#endif
	classes.push_back("LoadingCircle");
	classes.push_back("LoadingLayer");
	classes.push_back("LocalLevelManager");
	classes.push_back("MapPackCell");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("MapSelectLayer");
	#endif
	classes.push_back("MenuGameLayer");
	classes.push_back("MenuLayer");
	classes.push_back("MessagesProfilePage");
	classes.push_back("MoreOptionsLayer");
	classes.push_back("MoreSearchLayer");
	classes.push_back("MoreVideoOptionsLayer");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("MultiplayerLayer");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("MultiTriggerPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("MusicBrowser");
	#endif
	classes.push_back("MusicDownloadManager");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("NCSInfoLayer");
	#endif
	classes.push_back("NewgroundsInfoLayer");
	classes.push_back("NumberInputLayer");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("OBB2D");
	#endif
	classes.push_back("ObjectControlGameObject");
	classes.push_back("ObjectManager");
	classes.push_back("ObjectToolbox");
	classes.push_back("ParentalOptionsLayer");
	classes.push_back("ParticleGameObject");
	classes.push_back("PlayerCheckpoint");
	classes.push_back("PlayerControlGameObject");
	classes.push_back("PlayerFireBoostSprite");
	classes.push_back("PlayerObject");
	classes.push_back("PlayLayer");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("PriceLabel");
	#endif
	classes.push_back("ProfilePage");
	classes.push_back("PurchaseItemPopup");
	classes.push_back("RandTriggerGameObject");
	classes.push_back("RateDemonLayer");
	classes.push_back("RateLevelLayer");
	classes.push_back("RateStarsLayer");
	classes.push_back("RewardsPage");
	classes.push_back("RewardUnlockLayer");
	classes.push_back("RotateGameplayGameObject");
	classes.push_back("SearchButton");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SearchSFXPopup");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SecretGame01Layer");
	#endif
	classes.push_back("SecretLayer");
	classes.push_back("SecretLayer2");
	classes.push_back("SecretLayer3");
	classes.push_back("SecretLayer4");
	classes.push_back("SecretLayer5");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SecretLayer6");
	#endif
	classes.push_back("SecretNumberLayer");
	classes.push_back("SecretRewardsLayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SelectArtLayer");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SelectEventLayer");
	#endif
	classes.push_back("SelectFontLayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SelectListIconLayer");
	#endif
	classes.push_back("SelectPremadeLayer");
	classes.push_back("SelectSettingLayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SelectSFXSortLayer");
	#endif
	classes.push_back("SequenceTriggerGameObject");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetColorIDPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetFolderPopup");
	#endif
	classes.push_back("SetGroupIDLayer");
	classes.push_back("SetIDPopup");
	classes.push_back("SetItemIDLayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetLevelOrderPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetTargetIDLayer");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetTextPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupAdvFollowEditPhysicsPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupAdvFollowPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupAdvFollowRetargetPopup");
	#endif
	classes.push_back("SetupAnimationPopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupAnimSettingsPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupAreaAnimTriggerPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupAreaFadeTriggerPopup");
	#endif
	classes.push_back("SetupAreaMoveTriggerPopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupAreaRotateTriggerPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupAreaTintTriggerPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupAreaTransformTriggerPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupAreaTriggerPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupArtSwitchPopup");
	#endif
	classes.push_back("SetupAudioLineGuidePopup");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupBGSpeedTrigger");
	#endif
	classes.push_back("SetupCameraEdgePopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupCameraGuidePopup");
	#endif
	classes.push_back("SetupCameraModePopup");
	classes.push_back("SetupCameraOffsetTrigger");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupCameraRotatePopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupCameraRotatePopup2");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupCheckpointPopup");
	#endif
	classes.push_back("SetupCoinLayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupCollisionStateTriggerPopup");
	#endif
	classes.push_back("SetupCollisionTriggerPopup");
	classes.push_back("SetupCountTriggerPopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupDashRingPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupEndPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupEnterEffectPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupEnterTriggerPopup");
	#endif
	classes.push_back("SetupEventLinkPopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupForceBlockPopup");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupGameplayOffsetPopup");
	#endif
	classes.push_back("SetupGradientPopup");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupGravityModPopup");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupGravityTriggerPopup");
	#endif
	classes.push_back("SetupInstantCollisionTriggerPopup");
	classes.push_back("SetupInstantCountPopup");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupInteractObjectPopup");
	#endif
	classes.push_back("SetupItemCompareTriggerPopup");
	classes.push_back("SetupItemEditTriggerPopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupKeyframeAnimPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupKeyframePopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupMGTrigger");
	#endif
	classes.push_back("SetupMoveCommandPopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupObjectControlPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupObjectOptions2Popup");
	#endif
	classes.push_back("SetupObjectOptionsPopup");
	classes.push_back("SetupObjectTogglePopup");
	classes.push_back("SetupOpacityPopup");
	classes.push_back("SetupOptionsTriggerPopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupPersistentItemTriggerPopup");
	#endif
	classes.push_back("SetupPickupTriggerPopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupPlatformerEndPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupPlayerControlPopup");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupPortalPopup");
	#endif
	classes.push_back("SetupPulsePopup");
	classes.push_back("SetupRandAdvTriggerPopup");
	classes.push_back("SetupRandTriggerPopup");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupResetTriggerPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupReverbPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupRotateCommandPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupRotateGameplayPopup");
	#endif
	classes.push_back("SetupRotatePopup");
	classes.push_back("SetupSequenceTriggerPopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupSFXEditPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupSFXPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID
	classes.push_back("SetupShaderEffectPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupShakePopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupSmartBlockLayer");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupSmartTemplateLayer");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupSongTriggerPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupSpawnParticlePopup");
	#endif
	classes.push_back("SetupSpawnPopup");
	classes.push_back("SetupStaticCameraPopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupStopTriggerPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupTeleportPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupTimerControlTriggerPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupTimerEventTriggerPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupTimerTriggerPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupTimeWarpPopup");
	#endif
	classes.push_back("SetupTouchTogglePopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SetupTransformPopup");
	#endif
	classes.push_back("SetupTriggerPopup");
	classes.push_back("SetupZoomTriggerPopup");
	classes.push_back("SFXBrowser");
	classes.push_back("ShaderLayer");
	classes.push_back("ShardsPage");
	classes.push_back("ShareCommentLayer");
	classes.push_back("ShareLevelLayer");
	classes.push_back("ShareLevelSettingsLayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("ShareListLayer");
	#endif
	classes.push_back("SimplePlayer");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SlideInLayer");
	#endif
	classes.push_back("Slider");
	classes.push_back("SmartTemplateCell");
	classes.push_back("SongCell");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SongInfoLayer");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_IOS
	classes.push_back("SongInfoObject");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("SongOptionsLayer");
	#endif
	classes.push_back("SongSelectNode");
	classes.push_back("SpawnParticleGameObject");
	classes.push_back("SpawnTriggerGameObject");
	classes.push_back("StarInfoPopup");
	classes.push_back("StartPosObject");
	classes.push_back("TextAlertPopup");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("TextArea");
	#endif
	classes.push_back("TopArtistsLayer");
	classes.push_back("TOSPopup");
	classes.push_back("TutorialLayer");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("TutorialPopup");
	#endif
	classes.push_back("UILayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("UIObjectSettingsPopup");
	#endif
	classes.push_back("UIOptionsLayer");
	classes.push_back("UIPOptionsLayer");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("UISaveLoadLayer");
	#endif
	classes.push_back("UISettingsGameObject");
	classes.push_back("UpdateAccountSettingsPopup");
	classes.push_back("UploadActionPopup");
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("UploadListPopup");
	#endif
	#if defined GEODE_IS_WINDOWS || defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("UploadPopup");
	#endif
	classes.push_back("URLCell");
	classes.push_back("VideoOptionsLayer");
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("WorldLevelPage");
	#endif
	#if defined GEODE_IS_ANDROID || defined GEODE_IS_ARM_MAC
	classes.push_back("WorldSelectLayer");
	#endif

	classes.shrink_to_fit();
	return classes;
}