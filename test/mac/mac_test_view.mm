#include "mac_test_view.h"

@implementation mac_test_view

- (id)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
    }
    return self;
}

- (void)drawRect:(NSRect)rect {
    [super drawRect:rect];
    [[NSColor colorWithSRGBRed:0 green:0 blue:0 alpha:1] setFill];
    NSRectFill(rect);

    NSBezierPath *line = [NSBezierPath bezierPath];
    [line moveToPoint:NSMakePoint(NSMinX([self bounds]), NSMinY([self bounds]))];
    [line lineToPoint:NSMakePoint(NSMaxX([self bounds]), NSMaxY([self bounds]))];
    [line setLineWidth:5.0]; /// Make it easy to see
    [[NSColor colorWithSRGBRed:1 green:0 blue:0 alpha:1] set]; /// Make future drawing the color of lineColor.
    [line stroke];

}
@end
