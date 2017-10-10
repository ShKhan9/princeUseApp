//
//  Helprox.h
//  Helprox
//
//  Created by ShKhan on 10/3/17.
//  Copyright © 2017 Approcks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
//! Project version number for Helprox.
FOUNDATION_EXPORT double HelproxVersionNumber;

//! Project version string for Helprox.
FOUNDATION_EXPORT const unsigned char HelproxVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <Helprox/PublicHeader.h>

#import <Helprox/InsertManager.h>
 
#import <Starscream/Starscream.h>

@interface Helprox : NSObject



//=========================================================================================================
/*! @name Getting set up */
//=========================================================================================================
/*!
 Initialize Helprox with your iOS API key and App ID.  This will allow your app to connect with Helprox.
 This is best done in the application delegate's didFinishLaunchingWithOptions: method.
 
 @param apiKey The iOS API key found on the API Key settings page.
 @param appId  The App ID of your Helprox app.
 */
+ (void)setApiKey:(NSString *)apiKey forAppId:(NSString *)appId;


//=========================================================================================================
/*! @name Getting set up */
//=========================================================================================================
/*!
 Initialize Helprox with your iOS server url
 
 @param serverUrl The iOS server url .
 
 */
+ (void)setServerUrl:(NSString *)serverUrl;


//=========================================================================================================
/*! @name Resetting user data */
//=========================================================================================================
/*!
 reset is used to reset all local caches and user data Helprox has created. Reset will also close any active
 UI that is on screen. Use this at a time when you wish to log a user out of your app or change a user.
 Once called, Helprox for iOS will no longer communicate with Helprox until a further registration is made.
 */
+ (void)reset;


//=========================================================================================================
/*! @name Working with push notifications */
//=========================================================================================================
/*!
 Set the device token for push notifications. Once the device token is set, the methods for receiving push
 notifications are safely swizzled so ones sent from Helprox can be intercepted. When a push notification from
 Helprox is received, Helprox for iOS will automatically launch the message from the notification.
 
 @param deviceToken The device token provided in the `didRegisterForRemoteNotificationsWithDeviceToken` method.
 */
+ (void)setDeviceToken:(NSData *)deviceToken;

/*!
 Use this method to check if a push notification payload was sent by Helprox. Typically you should call
 +[Helprox handleHelproxPushNotification:] after checking this.
 
 @note This is only needed if you have set `HelproxAutoIntegratePushNotifications` to NO in your Info.plist
 @return YES if the payload is an Helprox push notification, NO otherwise.
 */
+ (BOOL)isHelproxPushNotification:(NSDictionary *)userInfo;

/*!
 Use this method to handle a push notification payload received by Helprox. You should first check if this
 notification was send by Helprox with `+[Helprox isHelproxPushNotification:]`.
 
 @note This is only needed if you have set `HelproxAutoIntegratePushNotifications` to NO in your Info.plist
 */
+ (void)handleHelproxPushNotification:(NSDictionary *)userInfo;


//=========================================================================================================
/*! @name Helprox Notifications */
//=========================================================================================================
/*!
 These are notifications thrown by Helprox for iOS when the Helprox window is displayed and hidden or when
 a new conversation has been started. These notifications are fired only when there is a change in the state
 of Helprox's UI: when a user receives a message for instance, willShow and didShow notifications will be
 fired accordingly when the Helprox Notification (chat head) is presented.
 
 Once the user taps on the chat head, the message is presented in your app. It will be presented covering
 the entire screen, but no notifications will be thrown here as Helprox has already been visible.
 
 In the case of a new conversation this notification may be used to prompt users to enable push notifications.
 */

UIKIT_EXTERN NSString *const HelproxWindowWillShowNotification;
UIKIT_EXTERN NSString *const HelproxWindowDidShowNotification;
UIKIT_EXTERN NSString *const HelproxWindowWillHideNotification;
UIKIT_EXTERN NSString *const HelproxWindowDidHideNotification;
UIKIT_EXTERN NSString *const HelproxDidStartNewConversationNotification;








@end
