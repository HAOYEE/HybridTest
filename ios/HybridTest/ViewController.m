//
//  ViewController.m
//  HybridTest
//
//  Created by luyeeB on 2018/11/5.
//  Copyright © 2018年 luyeeB. All rights reserved.
//

#import "ViewController.h"

#import <React/RCTBundleURLProvider.h>
#import <React/RCTRootView.h>

@interface ViewController ()

@end

@implementation ViewController
- (IBAction)btnClicked:(id)sender {
    NSURL *jsCodeLocation;
    jsCodeLocation = [NSURL URLWithString:@"http://localhost:8081/index.bundle?platform=ios"];
    RCTRootView *rootView = [[RCTRootView alloc] initWithBundleURL:jsCodeLocation
                                                        moduleName:@"HybridTest"
                                                 initialProperties:nil
                                                     launchOptions:nil];
    UIViewController *navVC = [[UIViewController alloc]init];
    navVC.view.backgroundColor = [UIColor yellowColor];
    navVC.view = rootView;
    [self.navigationController pushViewController:navVC animated:YES];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.view.backgroundColor = UIColor.whiteColor;
    
    self.title = @"开始展示";
    
    
}


@end
