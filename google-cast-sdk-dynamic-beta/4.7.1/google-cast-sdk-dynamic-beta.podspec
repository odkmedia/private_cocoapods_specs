#
#  Be sure to run `pod spec lint GoogleAds-PAL-iOS-SDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         				= "google-cast-sdk-dynamic-beta"
  spec.version      				= "4.7.1"
  spec.summary      				= "Google Cast iOS framework"
  spec.description  				= "Google Cast framework for iOS"
  spec.homepage     				= "https://developers.google.com/cast/docs/overview"
  spec.license      				= { :type => "MIT" }
  spec.author       				= { "ODK Media Dev" => "support@odkmedia.net" }
  spec.source       				= { :http => "https://dl.google.com/dl/chromecast/sdk/ios/GoogleCastSDK-ios-4.7.1_dynamic_beta.xcframework.zip" }
  
  spec.ios.vendored_frameworks		= "GoogleCast.xcframework"
  spec.ios.deployment_target		= "14.0"

end
