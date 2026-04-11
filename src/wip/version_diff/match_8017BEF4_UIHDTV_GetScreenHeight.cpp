/* UIHDTV::GetScreenHeight(void) - 0x8017BEF4 (12 bytes) */
// TU: uihdtv

extern int UIHDTV_s_screenHeight;

struct UIHDTV {
    static int GetScreenHeight();
};

int UIHDTV::GetScreenHeight() {
    return UIHDTV_s_screenHeight;
}
