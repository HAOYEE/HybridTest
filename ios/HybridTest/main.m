//
//  main.m
//  HybridTest
//
//  Created by luyeeB on 2018/11/5.
//  Copyright © 2018年 luyeeB. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

#include "cpkdev.h"
#include "cpksoft.h"

static char *device;
static char *verify;

int config(){
    if (!device) {
        device = [[NSBundle mainBundle] URLForResource:@"Alice" withExtension:@"vkd"].absoluteString.UTF8String;
        device += 7;
    }
    if (!verify) {
        verify = [[NSBundle mainBundle] URLForResource:@"test.cn" withExtension:@"pkm"].absoluteString.UTF8String;
        verify += 7;
    }
    return device && verify;
}

int vailConfig(){
    int rv = 0, times = 0;
    char pin[16] = {0};
    //设备类型(0: CPK Key; 1: CPK TCard; 2: Smart Card 5: CPK VKey)
    int devType = 5;
    
    //打开设备
    rv = DevOpen(devType, device);
    if(rv)
    {
        printf("Open device failed, error code is %d!\n", rv);
        return rv;
    }
    else
    {
        printf("Open device success.\n");
    }
    
    //验证口令
    memset (pin, 0x31, 8);
    rv = DevVerifyPin(0x02, pin, &times);
    if(rv)
    {
        printf("Verify pin failed, error code is %d, %d times left!\n", rv, times);
    }
    else
    {
        printf("Verify pin success.\n");
    }
    
    //关闭设备
    rv = DevClose();
    if(rv)
    {
        printf("Close device failed, error code is %d!\n", rv);
    }
    else
    {
        printf("Close device success.\n");
    }
    return rv;
}

int cpkSafeLogin(){
    int rv = 0, times = 0;
    char pin[17] = {0}, signerId[128] = {0}, vkeyFile[256] = {0};
    unsigned char signVal[256] = {0};
    char signTime[32] = {0};
    int devType = 5, signLen = 256, signerIdLen = 128, signTimeLen = 32;
    
    sprintf(vkeyFile, "%s", device);
    //1. 打开设备
    rv = DevOpen(devType, vkeyFile);
    if(rv)
    {
        printf("Open device fail, error code is %d.\n", rv);
        return rv;
    }
    else
    {
        printf("Open device success.\n");
    }
    
    //2. 验证用户口令
    memset(pin, 0x31, 0x08);
    rv = DevVerifyPin(2, pin, &times);
    if(rv)
    {
        printf("Verify pin fail, error code is %d, %d times left.\n", rv , times);
        goto err;
    }
    else
    {
        printf("Verify pin success.\n");
    }
    
    //3. 对当前时间签名
    rv = DevSignData(REAL_NAME, NULL, 0, signVal, &signLen);
    if(rv)
    {
        printf("Signature fail, error code is %d.\n", rv);
    }
    else
    {
        printf("Signature success.\n");
    }
    
    //4. 将签名数据发给服务器
    
    //5. 签证签名
    rv = CPK_Verify_Data(verify, NULL, 0, signVal, signLen);
    if(rv)
    {
        printf("Verify signature fail, error code is %d.\n", rv);
        goto err;
    }
    else
    {
        printf("Verify signature success.\n");
    }
    
    //6. 取签名时间
    rv = CPK_GetSignTime(signVal, signLen, signTime, &signTimeLen);
    if (rv)
    {
        printf("Get signature time fail, error code is %d.\n", rv);
        goto err;
    }
    else
    {
        printf("signature time: %s\n", signTime);
    }
    
    //7. 将签名时间与当前时间比较，判断时间是否是在允许的范围内，可防止复制攻击
    
    //8. 得到签名者标识
    rv = CPK_GetSignerId(signVal, signLen, signerId, &signerIdLen);
    if(rv)
    {
        printf("Get identity of signer fail, error code is %d.\n", rv);
        goto err;
    }
    else
    {
        printf("SignerId:%s\n", signerId);
    }
    
    //9. 标识鉴别，以上述得到的标识查询数据库
    //或配置文件进行标识合法性检查，代码略
    
err:
    //10. 关闭设备
    rv = DevClose();
    if(rv)
    {
        printf("Close device fail, error code is %d.\n", rv);
    }
    else
    {
        printf("Close device success.\n");
    }
    return rv;
}

void cpktest(){
    config();
    
    // 验证配置
//    vailConfig();
    
    // 验证安全登录
    cpkSafeLogin();
    
    //
}

int main(int argc, char * argv[]) {
    
//    cpktest();
    
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
