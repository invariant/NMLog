//
// Copyright (c) 2011 Nick Moore
//  
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
//

#import <Foundation/Foundation.h>

/*
 NSUserDefaults key for an integer to set the log level.
 */
extern NSString *const kNMLogLevel;

/*
 NSUserDefaults key for an array of strings to specify files for which to turn
 on maximum logging. Matches file name part up to the first dot (if any). For example, to specify
   /Users/me/code/MyFile.m, use the string 'MyFile'.
 Speficy from console as:
   defaults write com.example.appid NMLogFiles -array MyFile MyOtherFile MyThirdFile
 */
extern NSString *const kNMLogFiles;

/*
 NSUSerDefaults key to control whether output is logged to a file on the desktop.
 */
extern NSString *const kNMLogToFile;

/*
 This function performs the logging. Although you can call this directly, I recommend
 using one of the macros below.
 */
void NMLogLog(NSString *levelName, NSInteger levelNumber, NSString *filePath, NSString *format, ...);

/*
 The current date and time as a string.
 */
NSString *NMLogDateTimeString(void);
NSString *NMLogFineDateTimeString(void);

/*
 Macros for the predefined log levels.
 */
#if defined(NMLOG_DISABLE_ALL)
#	define NMLogImportant(...)
#	define NMLogError(...)
#else
#	define NMLogImportant(fmt, ...) NMLogLog(@"INFO", 0, @__FILE__, fmt, ##__VA_ARGS__)
#	define NMLogError(fmt, ...) NMLogLog(@"ERROR", 0, @__FILE__, fmt, ##__VA_ARGS__)
#endif

#if defined(NMLOG_DISABLE_INFO)||defined(NMLOG_DISABLE_ALL)
#	define NMLogTiny(...)
#	define NMLogFine(...)
#	define NMLogInfo(...)
#	define NMLogWarning(...)
#	define NMLogTemp(...)
#else
#	define NMLogTiny(fmt, ...) NMLogLog(@"TINY", 3, @__FILE__, fmt, ##__VA_ARGS__)
#	define NMLogFine(fmt, ...) NMLogLog(@"FINE", 2, @__FILE__, fmt, ##__VA_ARGS__)
#	define NMLogInfo(fmt, ...) NMLogLog(@"INFO", 1, @__FILE__, fmt, ##__VA_ARGS__)
#	define NMLogWarning(fmt, ...) NMLogLog(@"WARNING", 1, @__FILE__, fmt, ##__VA_ARGS__)
#	define NMLogTemp(fmt, ...) NMLogLog(@"TEMP", 0, @__FILE__, fmt, ##__VA_ARGS__)
#endif



