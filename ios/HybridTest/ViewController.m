//
//  ViewController.m
//  HybridTest
//
//  Created by luyeeB on 2018/11/5.
//  Copyright © 2018年 luyeeB. All rights reserved.
//

#import "ViewController.h"

#import "SetupViewCtrl.h"
#import <React/RCTBundleURLProvider.h>
#import <React/RCTRootView.h>

#import "AppDelegate.h"

@interface ViewController () 

@end

@implementation ViewController


- (IBAction)btnClicked:(id)sender {
    SetupViewCtrl *setupVC = [[UIStoryboard storyboardWithName:@"Main" bundle:nil] instantiateViewControllerWithIdentifier:@"SetupViewCtrl"];
    
    NSURL *jsCodeLocation;
    jsCodeLocation = [NSURL URLWithString:@"http://localhost:8081/index.bundle?platform=ios&dev=true"];
    RCTRootView *rootView = [[RCTRootView alloc] initWithBundleURL:jsCodeLocation
                                                        moduleName:@"HybridTest"
                                                 initialProperties:NSDictionary.new
                                                     launchOptions:((AppDelegate *)([UIApplication sharedApplication].delegate)).launchOptions];
    
    setupVC.view = rootView;
    
    [self.navigationController pushViewController:setupVC animated:YES];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.view.backgroundColor = UIColor.whiteColor;
    
    self.title = @"开始展示";
}


@end


/*

export default class RNTestForIOS extends Component{
    render() {
        return (
                // <View>
                // <Text style={{flex: 1, backgroundColor: 'powderblue'}}>This is setup page !</Text>
                // </View>
                <Button
                onPress={onBtnPress}
                title="点击（回调)"
                color="#841584"
                >
                </Button>
                )
    }
}

*/

