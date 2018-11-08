//
//  BCTCPKKit.m
//  HybridTest
//
//  Created by luyeeB on 2018/11/7.
//  Copyright © 2018年 luyeeB. All rights reserved.
//

#import "BCTCPKKit.h"

#include "cpkdev.h"
#include "cpksoft.h"

@implementation BCTCPKKit

+ (NSString *)bctBase64Encode:(NSString *)clearStr{
    int clearTextLenth = [NSNumber numberWithInteger:clearStr.length].intValue;
    const unsigned char *clearText = clearStr.UTF8String;
    int base64TextLenth = 256;
    char base64Text[256] = {0};
    int result = Base64Encode(clearText, clearTextLenth, base64Text, &base64TextLenth, 0);
    if (result) {
        return @"";
    }else{
        return [NSString stringWithUTF8String:base64Text];
    }
}

+ (NSString *)bctBase64Decode:(NSString *)base64Str{
    int base64TextLenth = [NSNumber numberWithInteger:base64Str.length].intValue;
    const char *base64Text = base64Str.UTF8String;
    int clearTextLenth = 256;
    char clearText[256] = {0};
    int result = Base64Decode(base64Text, base64TextLenth, clearText, &clearTextLenth);
    if (result) {
        return @"";
    }else{
        return [NSString stringWithUTF8String:clearText];
    }
}

@end
