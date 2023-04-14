//
//  KCP_Analytics.h
//  KCP_Analytics
//
//  Created by Kim BaeSung on 2020/03/19.
//  Copyright © 2020 Kim BaeSung. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@protocol KCPA_Datasource <NSObject>

@required
/**
 * @return Return the current playback position.
 */
- (NSInteger)KCPA_GetPlaybackPosition;

/**
 * @return Return the bitrate currently playing
 */
- (NSString * _Nonnull)KCPA_GetPlaybackBitrate;

@optional

@end


@protocol KCPA_Delegate <NSObject>

@optional
/**
 * This method is called when it succeeds in receiving authentication information after calling KCPA_InitSDK.
 */
- (void)authenticationInfoDidReceived;

/**
 * This method is called when error occurred in the KCPA SDK.
 * @param apiName  API name where the error occurred
 * @param errCode  Error code number
 * @param strErrMsg Error message
 * @param error Error object
 */
- (void)KCPA:(NSString *)apiName didReceiveError:(NSInteger)errCode withMessage:(nonnull NSString *)strErrMsg error:(nullable id)error reqParam:(nullable NSDictionary *)dicRegParam;
- (void)analyticsDebug:(NSString *)apiName statusCode:(NSInteger)statusCode header:(NSDictionary *)dicHeader;

@end


@interface KCP_Analytics : NSObject

/**
 * The KCP Analtyics SDK datasource protocol.
 */
@property (weak, nonatomic) id<KCPA_Datasource> datasource;
/**
 * The KCP Analtyics SDK delegate protocol.
 */
@property (weak, nonatomic) id<KCPA_Delegate> delegate;

+ (instancetype)sharedInstance;


#pragma mark - Initialize
/**
 * The KCP Analtyics Server type.
 */
typedef NS_ENUM(NSInteger, KCPA_ServerType) {
    KCPAServerStg = 0,
    KCPAServerProd
};

/**
 * Platform type.
 * iPadOS contains in KCPA_PlatformiOS
 */
typedef NS_ENUM(NSInteger, KCPA_ApplePlatform) {
    KCPA_PlatformiOS = 0,
    KCPA_PlatformtvOS
};

/**
 * SDK initializer.
 * @param serverType The type of the KCP Analytics Server
 * @param platform Platform type of device using KCP Analytics SDK
 * @param strID The user ID assigned by KCP
 * @param strPasswd The password of the user ID assigned by KCP
 * @param strServiceName The name of Service assigned by KCP
 * @param debugLogEnabled Flag to enable whether to print debug log on Xcode debug console.
 * @return YES on initialize success, NO otherwise.
 */
- (BOOL)KCPA_InitSDK:(KCPA_ServerType)serverType
        platformType:(KCPA_ApplePlatform)platform
              userID:(NSString * _Nonnull)strID
        userPassword:(NSString * _Nonnull)strPasswd
         serviceName:(NSString * _Nonnull)strServiceName
          logEnabled:(BOOL)debugLogEnabled;


#pragma mark - Session log

/**
 * Session action type
 */
typedef NS_ENUM(NSInteger, KCPA_SessionActionType) {
    KCPA_Session_SignIn = 0,
    KCPA_Session_SignOut,
    KCPA_Session_Exit
};

/**
 * This method should be called  inside the "authenticationInfoDidReceived" delegate method.
 * @param strAppVersion App version information
 * @param strUserID User ID
 * @param strEmail Email
 * @param strUserType User type (Non-sub, Anonymous or subscription ID for subscriber's)
 * @param strGender Gender
 * @param strBirthDay BirthDay
 * @param strHouseholdID HouseholdID, Unique UUID of the device
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_StartSession:(NSString * _Nonnull)strAppVersion
                   userID:(NSString * _Nonnull)strUserID
                    email:(NSString * _Nonnull)strEmail
                 userType:(NSString * _Nonnull)strUserType
                   gender:(NSString * _Nonnull)strGender
                 birthday:(NSString * _Nonnull)strBirthDay
              householdID:(NSString * _Nonnull)strHouseholdID;

/**
 * This method should be called when user session info updated
 * @param actionType Action type of the session info updated
 * @param strUserID User ID
 * @param strEmail Email
 * @param strUserType User type. Current subscription status at the moment user tries to watch a video. (Non-sub, Anonymous or subscription ID for subscriber's)
 * @param strGender Gender
 * @param strBirthDay BirthDay
 * @param strHouseholdID HouseholdID, Unique UUID of the device
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_UpdateSession:(KCPA_SessionActionType)actionType
                    userID:(NSString * _Nonnull)strUserID
                     email:(NSString * _Nonnull)strEmail
                  userType:(NSString * _Nonnull)strUserType
                    gender:(NSString * _Nonnull)strGender
                  birthday:(NSString * _Nonnull)strBirthDay
               householdID:(NSString * _Nonnull)strHouseholdID;

/**
 * This method should be called when error occurred while user signin and signout.
 * @param strErrCode Error code
 * @param strErrMsg Error message
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_ErrorSession:(NSString * _Nonnull)strErrCode
               errMessage:(NSString * _Nonnull)strErrMsg;
            

#pragma mark - Watch log
/**
 * This method should be called before the KCPA_StartWatch API is called
 * @param strServerName Streaming server URL
 * @param strCP CP (Content provider) name
 * @param strCategory Category name
 * @param strSeriesName Series name
 * @param strSeasonName Season name
 * @param strEpisodeName Episode name
 * @param nEpisodeNum Episode number
 * @param nDuration Content duration
 * @param strAssetID This ID has to be a unique key value for the media asset.
 * @param strParentID This ID is a parent ID of this media asset
 * @param strCollectionName Channel (or menu) name. (ex. "New", "Drama", "Watched", "Keyword Search: xxxx")
 * @param strServiceType Content lifecycle info (AVOD-R / AVOD-A / SVOD / LIVE)
 * @param strUserType User type. Current subscription status at the moment user tries to watch a video. (Non-sub, Anonymous or subscription ID for subscriber's)
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_SetWatchContent:(NSString * _Nonnull)strServerName
                          cp:(NSString * _Nonnull)strCP
                    category:(NSString * _Nonnull)strCategory
                  seriesName:(NSString * _Nonnull)strSeriesName
                  seasonName:(NSString * _Nonnull)strSeasonName
                 episodeName:(NSString * _Nonnull)strEpisodeName
                  episodeNum:(NSUInteger)nEpisodeNum
             contentDuration:(NSUInteger)nDuration
                     assetID:(NSString * _Nonnull)strAssetID
                    parentID:(NSString * _Nonnull)strParentID
              collectionName:(NSString * _Nonnull)strCollectionName
                 serviceType:(NSString * _Nonnull)strServiceType
                    userType:(NSString * _Nonnull)strUserType;

#pragma mark - Download log
/**
 * This method should be called before the KCPA_CompleteDownload API is called
 * @param strServerName Download content URL
 * @param strCP CP (Content provider) name
 * @param strCategory Category name
 * @param strSeriesName Series name
 * @param strSeasonName Season name
 * @param strEpisodeName Episode name
 * @param nEpisodeNum Episode number
 * @param nDuration Content duration
 * @param strAssetID This ID has to be a unique key value for the media asset.
 * @param strParentID This ID is a parent ID of this media asset
 * @param strCollectionName Channel (or menu) name. (ex. "New", "Drama", "Watched", "Keyword Search: xxxx")
 * @param strServiceType Content lifecycle info (AVOD-R / AVOD-A / SVOD / LIVE)
 * @param strUserType User type. Current subscription status at the moment user tries to watch a video. (Non-sub, Anonymous or subscription ID for subscriber's)
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_SetDownloadContent:(NSString * _Nonnull)strServerName
                             cp:(NSString * _Nonnull)strCP
                       category:(NSString * _Nonnull)strCategory
                     seriesName:(NSString * _Nonnull)strSeriesName
                     seasonName:(NSString * _Nonnull)strSeasonName
                    episodeName:(NSString * _Nonnull)strEpisodeName
                     episodeNum:(NSUInteger)nEpisodeNum
                contentDuration:(NSUInteger)nDuration
                        assetID:(NSString * _Nonnull)strAssetID
                       parentID:(NSString * _Nonnull)strParentID
                 collectionName:(NSString * _Nonnull)strCollectionName
                    serviceType:(NSString * _Nonnull)strServiceType
                       userType:(NSString * _Nonnull)strUserType;

/**
 * Player event type
 */
typedef NS_ENUM(NSInteger, KCPA_PlayerStatus) {
    KCPA_PlayerBuffer = 0,
    KCPA_PlayerPlay,
    KCPA_PlayerPause,
    KCPA_PlayerSeek,
    KCPA_PlayerStop,
    KCPA_PlayerExit
};

/**
 * Cast type
 */
typedef NS_ENUM(NSInteger, KCPA_CastType) {
    KCPA_CastPlayer = 0,
    KCPA_CastAirPlay,
    KCPA_CastGooglCast,
};

/**
 * This method return KCP Analytics configuration info for sending to ChromeCast receiver
 * @return KCP Analytics configuration info.
 */
- (NSDictionary *)getWatchLogInfo;

/**
 * This method should be called when player status changed
 * @param nPlaybackStartPosition Start position of content
 * @param strAudioLang Audio language (ex. "en", "pt", "kr")
 * @param strSubtitleLang Subtitle language (ex. "en", "pt", "kr")
 * @param castType Cast type
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_StartWatch:(NSInteger)nPlaybackStartPosition
              audioLang:(NSString * _Nonnull)strAudioLang
           subtitleLang:(NSString * _Nonnull)strSubtitleLang
               castType:(KCPA_CastType)castType;

/**
 * This method should be called when player status changed
 * @param playerStatus Player status
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_UpdateWatchPlayerStatus:(KCPA_PlayerStatus)playerStatus;

/**
 * This method should be called when audio language changed
 * @param strAudioLang Audio language (ex. "en", "pt", "kr")
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_UpdateWatchAudioLang:(NSString * _Nonnull)strAudioLang;

/**
 * This method should be called when subtitle language changed
 * @param strSubtitleLang Subtitle language (ex. "en", "pt", "kr")
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_UpdateWatchSubtitleLang:(NSString * _Nonnull)strSubtitleLang;

/**
 * This method should be called when playback speed changed
 * @param strPlaybackSpeed Playback speed
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_UpdateWatchPlaybackSpeed:(NSString * _Nonnull)strPlaybackSpeed;

/**
 * This method should be called when casting type changed (ex. AirPlay, Chromecast). default is KCPA_CastPlayer
 * @param castType Cast type
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_UpdateWatchCastType:(KCPA_CastType)castType;

/**
 * This method should be called when error occurred while content playing.
 * @param strErrCode Error code
 * @param strErrMsg Error message
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_ErrorWatch:(NSString * _Nonnull)strErrCode
             errMessage:(NSString * _Nonnull)strErrMsg;


#pragma mark - Download log
/**
 * This method should be called when content download finished.
 * @param strAssetID This ID has to be a unique key value for the media asset.
 * @param strValidUntil Valid date of downloaded content
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_CompleteDownload:(NSString * _Nonnull)strAssetID
                   validUntil:(NSString * _Nonnull)strValidUntil;

/**
 * This method should be called when error occurred while content download.
 * @param strAssetID This ID has to be a unique key value for the media asset.
 * @param strErrCode Error code
 * @param strErrMsg Error message
 * @return YES on success, NO otherwise.
 */
- (BOOL)KCPA_ErrorDownload:(NSString * _Nonnull)strAssetID
                   errCode:(NSString * _Nonnull)strErrCode
                errMessage:(NSString * _Nonnull)strErrMsg;


@end

NS_ASSUME_NONNULL_END
