/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 */

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CAPCDVCommandStatus) {
    CAPCDVCommandStatus_NO_RESULT NS_SWIFT_NAME(noResult) = 0,
    CAPCDVCommandStatus_OK NS_SWIFT_NAME(ok),
    CAPCDVCommandStatus_CLASS_NOT_FOUND_EXCEPTION NS_SWIFT_NAME(classNotFoundException),
    CAPCDVCommandStatus_ILLEGAL_ACCESS_EXCEPTION NS_SWIFT_NAME(illegalAccessException),
    CAPCDVCommandStatus_INSTANTIATION_EXCEPTION NS_SWIFT_NAME(instantiationException),
    CAPCDVCommandStatus_MALFORMED_URL_EXCEPTION NS_SWIFT_NAME(malformedUrlException),
    CAPCDVCommandStatus_IO_EXCEPTION NS_SWIFT_NAME(ioException),
    CAPCDVCommandStatus_INVALID_ACTION NS_SWIFT_NAME(invalidAction),
    CAPCDVCommandStatus_JSON_EXCEPTION NS_SWIFT_NAME(jsonException),
    CAPCDVCommandStatus_ERROR NS_SWIFT_NAME(error)
};

// This exists to preserve compatibility with early Swift plugins, who are
// using CAPCDVCommandStatus as ObjC-style constants rather than as Swift enum
// values.
// This declares extern'ed constants (implemented in CAPCDVPluginResult.m)
#define SWIFT_ENUM_COMPAT_HACK(enumVal) extern const CAPCDVCommandStatus SWIFT_##enumVal NS_SWIFT_NAME(enumVal)
SWIFT_ENUM_COMPAT_HACK(CAPCDVCommandStatus_NO_RESULT);
SWIFT_ENUM_COMPAT_HACK(CAPCDVCommandStatus_OK);
SWIFT_ENUM_COMPAT_HACK(CAPCDVCommandStatus_CLASS_NOT_FOUND_EXCEPTION);
SWIFT_ENUM_COMPAT_HACK(CAPCDVCommandStatus_ILLEGAL_ACCESS_EXCEPTION);
SWIFT_ENUM_COMPAT_HACK(CAPCDVCommandStatus_INSTANTIATION_EXCEPTION);
SWIFT_ENUM_COMPAT_HACK(CAPCDVCommandStatus_MALFORMED_URL_EXCEPTION);
SWIFT_ENUM_COMPAT_HACK(CAPCDVCommandStatus_IO_EXCEPTION);
SWIFT_ENUM_COMPAT_HACK(CAPCDVCommandStatus_INVALID_ACTION);
SWIFT_ENUM_COMPAT_HACK(CAPCDVCommandStatus_JSON_EXCEPTION);
SWIFT_ENUM_COMPAT_HACK(CAPCDVCommandStatus_ERROR);
#undef SWIFT_ENUM_COMPAT_HACK

@interface CAPCDVPluginResult : NSObject {}

@property (nonatomic, strong, readonly) NSNumber* status;
@property (nonatomic, strong, readonly) id message;
@property (nonatomic, strong)           NSNumber* keepCallback;
// This property can be used to scope the lifetime of another object. For example,
// Use it to store the associated NSData when `message` is created using initWithBytesNoCopy.
@property (nonatomic, strong) id associatedObject;

- (CAPCDVPluginResult*)init;
+ (CAPCDVPluginResult*)resultWithStatus:(CAPCDVCommandStatus)statusOrdinal;
+ (CAPCDVPluginResult*)resultWithStatus:(CAPCDVCommandStatus)statusOrdinal messageAsString:(NSString*)theMessage;
+ (CAPCDVPluginResult*)resultWithStatus:(CAPCDVCommandStatus)statusOrdinal messageAsArray:(NSArray*)theMessage;
+ (CAPCDVPluginResult*)resultWithStatus:(CAPCDVCommandStatus)statusOrdinal messageAsInt:(int)theMessage;
+ (CAPCDVPluginResult*)resultWithStatus:(CAPCDVCommandStatus)statusOrdinal messageAsNSInteger:(NSInteger)theMessage;
+ (CAPCDVPluginResult*)resultWithStatus:(CAPCDVCommandStatus)statusOrdinal messageAsNSUInteger:(NSUInteger)theMessage;
+ (CAPCDVPluginResult*)resultWithStatus:(CAPCDVCommandStatus)statusOrdinal messageAsDouble:(double)theMessage;
+ (CAPCDVPluginResult*)resultWithStatus:(CAPCDVCommandStatus)statusOrdinal messageAsBool:(BOOL)theMessage;
+ (CAPCDVPluginResult*)resultWithStatus:(CAPCDVCommandStatus)statusOrdinal messageAsDictionary:(NSDictionary*)theMessage;
+ (CAPCDVPluginResult*)resultWithStatus:(CAPCDVCommandStatus)statusOrdinal messageAsArrayBuffer:(NSData*)theMessage;
+ (CAPCDVPluginResult*)resultWithStatus:(CAPCDVCommandStatus)statusOrdinal messageAsMultipart:(NSArray*)theMessages;
+ (CAPCDVPluginResult*)resultWithStatus:(CAPCDVCommandStatus)statusOrdinal messageToErrorObject:(int)errorCode;

+ (void)setVerbose:(BOOL)verbose;
+ (BOOL)isVerbose;

- (void)setKeepCallbackAsBool:(BOOL)bKeepCallback;

- (NSString*)argumentsAsJSON;

@end
