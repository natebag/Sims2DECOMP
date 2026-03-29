/* UIHDTV::GetScreenWidth(void) - 0x8017BF00 (12 bytes) */
// TU: uihdtv

extern int UIHDTV_s_screenWidth;

struct UIHDTV {
    static int GetScreenWidth();
};

int UIHDTV::GetScreenWidth() {
    return UIHDTV_s_screenWidth;
}
