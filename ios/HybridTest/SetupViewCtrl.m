//
//  SetupViewCtrl.m
//  HybridTest
//
//  Created by luyeeB on 2018/11/8.
//  Copyright © 2018年 luyeeB. All rights reserved.
//

#import "SetupViewCtrl.h"


#import <React/RCTBridgeModule.h>
#import "React/RCTLog.h"

#import "BCTCPKKit.h"

#import "AppDelegate.h"

@interface SetupViewCtrl ()  <RCTBridgeModule>

@end

@implementation SetupViewCtrl

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(encodeBase64:(NSString *)clearStr withCallBack:(RCTResponseSenderBlock)callback)
{
    NSString *base64Str = [BCTCPKKit bctBase64Encode:clearStr];
    BOOL result = base64Str.length;
    callback(@[@(result),base64Str]);
}

RCT_EXPORT_METHOD(decodeBase64:(NSString *)base64Str withCallBack:(RCTResponseSenderBlock)callback)
{
    NSString *clearStr = [BCTCPKKit bctBase64Decode:base64Str];
    BOOL result = base64Str.length;
    callback(@[@(result),clearStr]);
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"SetupViewCtrl";
}

@end
