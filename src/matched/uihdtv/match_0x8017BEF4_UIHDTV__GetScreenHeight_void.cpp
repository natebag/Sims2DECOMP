// 0x8017BEF4 UIHDTV::GetScreenHeight(void) (12 B)

struct UIHDTV {
    char pad_0000[0x18];
    int m_screenWidth;
    int m_screenHeight;

    static int GetScreenHeight();
};

extern UIHDTV* g_pUIHDTV;

int UIHDTV::GetScreenHeight() {
    return g_pUIHDTV->m_screenHeight;
}
