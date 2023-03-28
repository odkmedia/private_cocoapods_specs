#
#  Be sure to run `pod spec lint GoogleAds-PAL-iOS-SDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         				= "GoogleAds-PAL-iOS-SDK"
  spec.version      				= "2.5.3"
  spec.summary      				= "Google Ads PAL iOS framework"
  spec.description  				= "Google Ads PAL framework for iOS and tvOS"
  spec.homepage     				= "https://developers.google.com/ad-manager/pal"
  spec.license      				= { :type => "MIT" }
  spec.author       				= { "ODK Media Dev" => "support@odkmedia.net" }
  spec.source       				= { :http => "https://imasdk.googleapis.com/native/downloads/pal-ios-v2.5.3.zip" }
  
  spec.ios.vendored_frameworks		= "ProgrammaticAccessLibrary.xcframework"
  spec.ios.deployment_target		= "14.0"

end
