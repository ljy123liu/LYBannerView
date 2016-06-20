//
//  ViewController.m
//  LYBannerView
//
//  Created by LIUYONG on 16/6/20.
//  Copyright © 2016年 WanJianTechnology. All rights reserved.
//

#import "ViewController.h"
#import "LYBannerView.h"
@interface ViewController () <LYBannerViewDelegate>
@property (nonatomic, strong) LYBannerView *bannerView;
@property (nonatomic, strong) LYBannerView *bannerView1;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    //本地图片
    NSArray *arr1 = @[[UIImage imageNamed:@"1.jpg"], [UIImage imageNamed:@"2.jpg"], [UIImage imageNamed:@"3.jpg"]];
    
    //网络图片
    NSArray *arr2 = @[@"http://hiphotos.baidu.com/praisejesus/pic/item/e8df7df89fac869eb68f316d.jpg", @"http://pic39.nipic.com/20140226/18071023_162553457000_2.jpg", @"http://file27.mafengwo.net/M00/B2/12/wKgB6lO0ahWAMhL8AAV1yBFJDJw20.jpeg"];
    //既有本地图片也有网络图片
    NSArray *arr3 = @[@"http://pic39.nipic.com/20140226/18071023_162553457000_2.jpg", [UIImage imageNamed:@"2.jpg"], @"http://hiphotos.baidu.com/praisejesus/pic/item/e8df7df89fac869eb68f316d.jpg", [UIImage imageNamed:@"1.jpg"]];
    NSArray *describeArray = @[@"这是第一张图片的描述", @"这是第二张图片的描述", @"这是第三张图片的描述", @"这是第四张图片的描述"];
    
    self.bannerView = [LYBannerView bannerViewWithImageArray:arr2 describeArray:describeArray];
    self.bannerView.frame = CGRectMake(0, 100, [UIScreen mainScreen].bounds.size.width, 180);
    self.bannerView.delegate = self;
    self.bannerView.time = 2;
    [self.bannerView setPageImage:[UIImage imageNamed:@"other"] andCurrentPageImage:[UIImage imageNamed:@"current"]];
    self.bannerView.pagePosition = PositionTopCenter;
    
    UIColor *bgColor = [[UIColor blueColor] colorWithAlphaComponent:0.5];
    UIFont *font = [UIFont systemFontOfSize:15];
    UIColor *textColor = [UIColor greenColor];
    [self.bannerView setDescribeTextColor:textColor font:font bgColor:bgColor];
    [self.view addSubview:self.bannerView];
}

- (void)bannerView:(LYBannerView *)bannerView clickImageAtIndex:(NSInteger)index {
    NSLog(@"%ld",(long)index);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
