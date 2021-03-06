//
//  ORGMCommonProtocols.h
//  OrigamiEngine
//
//  Created by ap4y on 8/8/12.
//
//

#define kErrorDomain @"com.origami.engine.error"
typedef enum : NSInteger {
    ORGMEngineErrorCodesSourceFailed,
    ORGMEngineErrorCodesConverterFailed,
    ORGMEngineErrorCodesDecoderFailed,
    ORGMEngineErrorCodesContainerFailed
} ORGMEngineErrorCodes;

@protocol ORGMEngineObject <NSObject>
@end

@protocol ORGMSource <ORGMEngineObject>
+ (NSString*)scheme;

- (NSURL*)url;
- (long)size;

- (BOOL)open:(NSURL*)url;
- (BOOL)seekable;
- (BOOL)seek:(long)position whence:(int)whence;
- (long)tell;
- (int)read:(void*)buffer amount:(int)amount;
- (void)close;
@end

@protocol ORGMContainer <ORGMEngineObject>
+ (NSArray *)fileTypes;
+ (NSArray*)urlsForContainerURL:(NSURL*)url;
@end

@protocol ORGMDecoder <ORGMEngineObject>
@required
+ (NSArray*)fileTypes;
- (NSDictionary*)properties;
- (NSDictionary*)metadata;

- (int)readAudio:(void*)buffer frames:(UInt32)frames;
- (BOOL)open:(id<ORGMSource>)source;
- (long)seek:(long)frame;
- (void)close;
@end