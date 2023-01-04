#
#  Be sure to run `pod spec lint KCP_Analytics.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         				= "ODK_KCP_Analytics"
  spec.version      				= "1.0.14"
  spec.summary      				= "KCP Analytics framework"
  spec.description  				= "KCP Analytics framework for iOS and tvOS"
  spec.homepage     				= "http://EXAMPLE/KCP_Analytics"
  spec.license      				= { :type => "MIT" }
  spec.author       				= { "KCP FE Dev" => "PLATFORM_DEV@kcpglob.com" }
  spec.source       				= { :git => "https://ShinSeung-Hwan@bitbucket.org/kcpglob/kcp-analytics-pod.git", :tag => "#{spec.version}" }
  
  spec.ios.vendored_frameworks		= "Framework/KCP_Analytics_iOS.framework"
  spec.ios.deployment_target		= "10.0"
  
  spec.tvos.vendored_frameworks		= "Framework/KCP_Analytics_tvOS.framework"
  spec.tvos.deployment_target		= "10.0"
  
  # Common Dependencies
  spec.dependency "AFNetworking", '>= 4.0'
  
  # iOS Dependencies
  spec.ios.dependency "AFNetworking+RetryPolicy"

  other_frameworks =  ['ODK_KCP_Analytics']
  
  other_ldflags = '$(inherited) -framework ' + other_frameworks.join(' -framework ')

  spec.xcconfig = { 
    'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/ODK_KCP_Analytics"',

    'OTHER_LDFLAGS[arch=arm64]'  => other_ldflags,
    'OTHER_LDFLAGS[arch=armv7]'  => other_ldflags,
    'OTHER_LDFLAGS[arch=armv7s]' => other_ldflags
  }
end
