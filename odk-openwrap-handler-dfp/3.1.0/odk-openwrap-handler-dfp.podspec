
Pod::Spec.new do |spec|

  spec.name         				= "odk-openwrap-handler-dfp"
  spec.version      				= "3.1.0"
  spec.summary      				= "The PubMatic iOS SDK makes it easy to incorporate ads into iOS applications & monetize your applications with ease"
  spec.homepage     				= "https://community.pubmatic.com/display/IS"
  spec.license      				= { :type => "Pubmatic Inc. license", :text => "                                /*\n \n * PubMatic Inc. (\"PubMatic\") CONFIDENTIAL\n \n * Unpublished Copyright (c) 2006-2022 PubMatic, All Rights Reserved.\n \n *\n \n * NOTICE:  All information contained herein is, and remains the property of PubMatic. The intellectual and technical concepts contained\n \n * herein are proprietary to PubMatic and may be covered by U.S. and Foreign Patents, patents in process, and are protected by trade secret or copyright law.\n \n * Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained\n \n * from PubMatic.  Access to the source code contained herein is hereby forbidden to anyone except current PubMatic employees, managers or contractors who have executed\n \n * Confidentiality and Non-disclosure agreements explicitly covering such access.\n \n *\n \n * The copyright notice above does not evidence any actual or intended publication or disclosure  of  this source code, which includes\n \n * information that is confidential and/or proprietary, and is a trade secret, of  PubMatic.   ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC  PERFORMANCE,\n \n * OR PUBLIC DISPLAY OF OR THROUGH USE  OF THIS  SOURCE CODE  WITHOUT  THE EXPRESS WRITTEN CONSENT OF PubMatic IS STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE\n \n * LAWS AND INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS\n \n * TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE, USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.\n \n */\n" }
  spec.author       				= { "PubMatic" => "pm-library@pubmatic.com" }
  spec.source       				= { :git => "https://github.com/odkmedia/private_cocoapods_specs.git", :branch => "main" }

  spec.platform = :ios, "11.0"

  spec.vendored_frameworks		= "Frameworks/odk-openwrap-handler-dfp/3.1.0/OpenWrapHandlerDFP.xcframework"
 
  spec.static_framework = true 
  spec.frameworks = ["Foundation", "UIKit"]

  # Common Dependencies
  spec.dependency "OpenWrapSDK"
  spec.dependency "Google-Mobile-Ads-SDK", ">=8.12.0"
  
end