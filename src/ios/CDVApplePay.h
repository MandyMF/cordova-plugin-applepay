#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Cordova/CDVPlugin.h>

#import <PassKit/PassKit.h>

typedef void (^ARAuthorizationBlock)(PKPaymentAuthorizationStatus status);
typedef void (^ARListUpdateBlock)(PKPaymentAuthorizationStatus status, NSArray<PKShippingMethod *> * _Nullable shippingMethods, NSArray<PKPaymentSummaryItem *> * _Nullable summaryItems);

@interface CDVApplePay : CDVPlugin <PKPaymentAuthorizationViewControllerDelegate> {}

@property (nonatomic, nullable) ARAuthorizationBlock paymentAuthorizationBlock;

@property (nonatomic, nullable) ARListUpdateBlock updateItemsAndShippingMethodsBlock;

@property (nonatomic, nullable) NSString* paymentCallbackId;

@property (nonatomic, nullable) NSString* shippingContactSelectionListenerCallbackId;

@property (nonatomic, strong, nullable) NSArray<PKShippingMethod *>* shippingMethods;

@property (nonatomic, strong, nullable) NSArray<PKPaymentSummaryItem *>* summaryItems;

- (void)makePaymentRequest:(CDVInvokedUrlCommand*)command;
- (void)startListeningForShippingContactSelection:(CDVInvokedUrlCommand*)command;
- (void)stopListeningForShippingContactSelection:(CDVInvokedUrlCommand*)command;
- (void)updateItemsAndShippingMethods:(CDVInvokedUrlCommand*)command;
- (void)canMakePayments:(CDVInvokedUrlCommand*)command;
- (void)completeLastTransaction:(CDVInvokedUrlCommand*)command;

@end
