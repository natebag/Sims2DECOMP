// 0x8017BEA0 (84B) UIHDTV::UsingHDTV(void)
// Returns true (using HDTV mode) unless screen is exactly 640x448.
// goto-shared-label: bne(width!=640) and fall-through (height!=448) both share ret1.

class UIHDTV {
public:
    int GetScreenWidth();
    int GetScreenHeight();
    bool UsingHDTV();
};

bool UIHDTV::UsingHDTV() {
    int width = GetScreenWidth();
    int height = GetScreenHeight();
    if (width != 640) goto ret1;
    if (height == 448) goto ret0;
ret1:
    return true;
ret0:
    return false;
}
