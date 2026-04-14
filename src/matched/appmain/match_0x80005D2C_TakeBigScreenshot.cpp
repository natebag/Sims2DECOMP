// 0x80005D2C ESimsApp::TakeBigScreenshot (20b)

class ESimsApp {
public:
    char pad[0x49C];   // padding to offset 0x49C (1180)
    int field49C;      // at offset 0x49C = 1180
    int field4A0;      // at offset 0x4A0 = 1184
    int field4A4;      // at offset 0x4A4 = 1188
};

void ESimsApp_TakeBigScreenshot(ESimsApp* this_, int w, int h) {
    this_->field49C = 1;
    this_->field4A0 = w;
    this_->field4A4 = h;
}

extern "C" void _ZN8ESimsApp17TakeBigScreenshotEii(ESimsApp* this_, int w, int h) {
    ESimsApp_TakeBigScreenshot(this_, w, h);
}
