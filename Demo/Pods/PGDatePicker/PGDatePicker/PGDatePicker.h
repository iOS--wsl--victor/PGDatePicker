//
//  PGDatePicker.h
//  HooDatePickerDemo
//
//  Created by piggybear on 2017/7/25.
//  Copyright © 2017年 piggybear. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSDate+PGCategory.h"
#import "UIColor+PGHex.h"
#import "NSCalendar+PGCurrent.h"
#import "PGPickerView.h"

typedef NS_ENUM(NSInteger, PGDatePickerMode) {
    PGDatePickerModeYear, //年
    PGDatePickerModeYearAndMonth, //年月
    PGDatePickerModeDate, //年月日
     PGDatePickerModeDateHourMinute, //年月日时分
    PGDatePickerModeDateHourMinuteSecond, //年月日时分秒
    PGDatePickerModeTime, //时分
    PGDatePickerModeTimeAndSecond, //时分秒
    PGDatePickerModeDateAndTime, //月日周 时分
};

@protocol PGDatePickerDelegate;

@interface PGDatePicker : UIControl
@property (nonatomic, weak) id<PGDatePickerDelegate> delegate;
@property (nonatomic, assign) PGDatePickerMode datePickerMode; // default is PGDatePickerModeYear

@property (nonatomic, copy) NSString *cancelButtonText;
@property (nonatomic, copy) UIFont *cancelButtonFont;
@property (nonatomic, copy) UIColor *cancelButtonTextColor;

@property (nonatomic, copy) NSString *confirmButtonText;
@property (nonatomic, copy) UIFont *confirmButtonFont;
@property (nonatomic, copy) UIColor *confirmButtonTextColor;

@property (nonatomic, weak) UILabel *titleLabel;

@property (nonatomic, strong)UIColor *titleColorForSelectedRow;
@property (nonatomic, strong)UIColor *titleColorForOtherRow;
@property(nonatomic, strong) UIColor *lineBackgroundColor;          

@property (nonatomic, strong) NSLocale   *locale;   // default is [NSLocale currentLocale]. setting nil returns to default
@property (nonatomic, copy)   NSCalendar *calendar; // default is [NSCalendar currentCalendar]. setting nil returns to default
@property (nonatomic, strong) NSTimeZone *timeZone; // default is nil. use current time zone or time zone from calendar

@property (nonatomic, strong) NSDate *minimumDate; // specify min/max date range. default is nil. When min > max, the values are ignored. Ignored in countdown timer mode
@property (nonatomic, strong) NSDate *maximumDate; // default is nil

- (void)setDate:(NSDate *)date;

- (void)show;
@end

@protocol PGDatePickerDelegate <NSObject>

- (void)datePicker:(PGDatePicker *)datePicker didSelectDate:(NSDateComponents *)dateComponents;
@end

