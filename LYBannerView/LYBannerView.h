//
//  LYBannerView.h
//  Banner
//
//  Created by LIUYONG on 16/6/18.
//  Copyright © 2016年 WanJianTechnology. All rights reserved.
//

#import <UIKit/UIKit.h>
@class LYBannerView;
typedef void (^clickBlock)(NSInteger index);
//pageControl显示的位置
typedef NS_ENUM(NSInteger,PageControlPosition) {
    PositionNone,           //默认值 == PositionBottomCenter
    PositionHide,           //隐藏
    PositionTopCenter,      //中上
    PositionBottomLeft,     //左下
    PositionBottomCenter,   //中下
    PositionBottomRight     //右下
};

//图片切换到的方式
typedef NS_ENUM(NSInteger,ImageChangeMode) {
    ChangeModeDefault,  //轮播滚动
    ChangeModeFade      //淡入淡出
};

@protocol LYBannerViewDelegate <NSObject>
- (void)bannerView:(LYBannerView *)bannerView clickImageAtIndex:(NSInteger)index;
@end

@interface LYBannerView : UIView
#pragma mark - Necessary

/**
 *  轮播的图片数组，可以是本地图片（UIImage，不能是图片名称），也可以是网络路径
 */
@property (nonatomic, strong) NSArray *imageArray;

#pragma mark - Optional
/**
 *  设置图片切换的模式，默认为ChangeModeDefault
 */
@property (nonatomic, assign) ImageChangeMode changeMode;

/**
 *  设置分页控件位置，默认为PositionBottomCenter
 */
@property (nonatomic, assign) PageControlPosition pagePosition;

/**
 *  图片描述的字符串数组，应与图片顺序对应
 *
 *  图片描述控件默认是隐藏的
 *  设置该属性，控件会显示
 *  设置为nil或空数组，控件会隐藏
 */
@property (nonatomic, strong) NSArray *describeArray;


/**
 *  每一页停留时间，默认为5s，最少2s
 *  当设置的值小于2s时，则为默认值
 */
@property (nonatomic, assign) NSTimeInterval time;

/**
 *  点击图片后要执行的操作，会返回图片在数组中的索引
 */
@property (nonatomic, copy) clickBlock imageClickBlock;

/**
 *  代理，用来处理图片的点击
 */
@property (nonatomic, weak) id <LYBannerViewDelegate> delegate;

#pragma mark - Method
/**
 *  构造方法
 */
- (instancetype)initWithFrame:(CGRect)frame imageArray:(NSArray *)imageArray;
+ (instancetype)bannerViewWithImageArray:(NSArray *)imageArray describeArray:(NSArray *)describeArray;
/**
 *  开启定时器
 *  默认已开启，调用该方法会重新开启
 */
- (void)startTimer;

/**
 *  停止定时器
 *  停止后，如果手动滚动图片，定时器会重新开启
 */
- (void)stopTimer;

/**
 *  设置分页控件指示器的图片
 *  两个图片必须同时设置，否则设置无效
 *  不设置则为系统默认
 *
 *  @param pageImage    其他页码的图片
 *  @param currentImage 当前页码的图片
 */
- (void)setPageImage:(UIImage *)image andCurrentPageImage:(UIImage *)currentImage;

/**
 *  设置分页控件指示器的颜色
 *  不设置则为系统默认
 *
 *  @param color    其他页码的颜色
 *  @param currentColor 当前页码的颜色
 */
- (void)setPageColor:(UIColor *)color andCurrentPageColor:(UIColor *)currentColor;

/**
 *  修改图片描述控件的部分属性，不需要修改的传nil
 *
 *  @param color   字体颜色，默认为[UIColor whiteColor]
 *  @param font    字体，默认为[UIFont systemFontOfSize:13]
 *  @param bgColor 背景颜色，默认为[UIColor colorWithWhite:0 alpha:0.5]
 */
- (void)setDescribeTextColor:(UIColor *)color font:(UIFont *)font bgColor:(UIColor *)bgColor;

/**
 *  清除沙盒中的图片缓存
 */
- (void)clearDiskCache;


@end
