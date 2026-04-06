// 0x80038E50 EyeToyClient::ApplyFunFrame (20b)

// SDA global at r13-32564 - use small array for SDA
extern char g_funFrame[4];

void EyeToyClient_ApplyFunFrame(int frame) {
    int* ptr = (int*)g_funFrame;
    if (*ptr == 0) {
        *ptr = frame;
    }
}

extern "C" void _ZN12EyeToyClient13ApplyFunFrameEi(int frame) {
    EyeToyClient_ApplyFunFrame(frame);
}
