// 0x8017BF00 UIHDTV::GetScreenWidth(void) (12 B)

struct UIHDTV {
    char pad_0000[0x18];
    int m_screenWidth;
    int m_screenHeight;

    static int GetScreenWidth();
};

extern UIHDTV* g_pUIHDTV;

int UIHDTV::GetScreenWidth() {
    return g_pUIHDTV->m_screenWidth;
}
