#
#  Be sure to run `pod spec lint GoogleAds-PAL-tvOS-SDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         				= "GoogleAds-PAL-tvOS-SDK"
  spec.version      				= "2.5.3"
  spec.summary      				= "Google Ads PAL tvOS framework"
  spec.description  				= "Google Ads PAL framework for iOS and tvOS"
  spec.homepage     				= "https://developers.google.com/ad-manager/pal"
  spec.license      				= { :type => "MIT" }
  spec.author       				= { "ODK Media Dev" => "support@odkmedia.net" }
  spec.source       				= { :http => "https://imasdk.googleapis.com/native/downloads/pal-tvos-v2.5.3.zip" }
  
  spec.tvos.vendored_frameworks		= "ProgrammaticAccessLibrary.xcframework"
  spec.tvos.deployment_target		= "15.0"

end
