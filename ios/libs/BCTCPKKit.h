//
//  BCTCPKKit.h
//  HybridTest
//
//  Created by luyeeB on 2018/11/7.
//  Copyright © 2018年 luyeeB. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BCTCPKKit : NSObject

+ (NSString *)bctBase64Encode:(NSString *)clearStr;

+ (NSString *)bctBase64Decode:(NSString *)base64Str;

@end

NS_ASSUME_NONNULL_END
