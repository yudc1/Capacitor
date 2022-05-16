//
//  CAPCDVPluginManager.h
//  CapacitorCordova
//
//  Created by Julio Cesar Sanchez Hernandez on 26/2/18.
//

#import <Foundation/Foundation.h>
#import "CAPCDVPlugin.h"
#import "CAPCDVConfigParser.h"
#import "CAPCDVCommandDelegate.h"

@interface CAPCDVPluginManager : NSObject

@property (nonatomic, strong) NSMutableDictionary * pluginsMap;
@property (nonatomic, strong) NSMutableDictionary * pluginObjects;
@property (nonatomic, strong) NSMutableDictionary * settings;
@property (nonatomic, strong) UIViewController * viewController;
@property (nonatomic, strong) WKWebView * webView;
@property (nonatomic, strong) id <CAPCDVCommandDelegate> commandDelegate;

- (id)initWithParser:(CAPCDVConfigParser*)parser viewController:(UIViewController*)viewController webView:(WKWebView *)webview;
- (CAPCDVPlugin *)getCommandInstance:(NSString*)pluginName;

@end
