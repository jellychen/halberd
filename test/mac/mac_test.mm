#include <Cocoa/Cocoa.h>
#include <CoreFoundation/CoreFoundation.h>
#include <objc/objc.h>
#include <objc/objc-runtime.h>

#include "mac_test.h"
#include "mac_test_view.h"

void _mac_test() {
    @autoreleasepool{
        [NSApplication sharedApplication];
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
        id applicationName = [[NSProcessInfo processInfo] processName];
        id window = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, 600, 400)
            styleMask:NSTitledWindowMask backing:NSBackingStoreBuffered defer:NO];
        [window cascadeTopLeftFromPoint:NSMakePoint(20,20)];
        [window setTitle: applicationName];
        [window makeKeyAndOrderFront:nil];

        id view = [[mac_test_view alloc] initWithFrame:NSMakeRect(0, 0, 600, 400)];
        [((NSWindow*)window).contentView addSubview: view];
        [NSApp activateIgnoringOtherApps:YES];
        [NSApp run];
    }
}
