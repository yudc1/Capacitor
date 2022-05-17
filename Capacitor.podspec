require "json"
package = JSON.parse(File.read(File.join(__dir__, "package.json")))
Pod::Spec.new do |s|
  s.name = 'Capacitor'
  s.version = '3.5.0'
  s.summary = 'Capacitor for iOS'
  s.social_media_url = 'https://twitter.com/capacitorjs'
  s.license = 'MIT'
  s.homepage = 'https://github.com/yudc1/capacitor/tree/main'
  s.ios.deployment_target  = '12.0'
  s.authors = { 'Ionic Team' => 'hi@ionicframework.com' }
  s.source = { :git => 'https://github.com/capacitor.git', :tag => s.name.to_s + '@'+s.version.to_s }
  s.source_files = 'Capacitor/Capacitor/*.{swift,h,m}', 'Capacitor/Capacitor/Plugins/*.{swift,h,m}', 'Capacitor/Capacitor/Plugins/**/*.{swift,h,m}'
  s.module_map = 'Capacitor/Capacitor/Capacitor.modulemap'
  s.resources = ['Capacitor/Capacitor/assets/native-bridge.js']
  
  s.dependency 'CapacitorCordova'
  s.swift_version = '5.1'
end
