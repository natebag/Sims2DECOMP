/* UIHDTV::GetScreenWidth(void) - 0x8017BF00 (12 bytes) */

struct UIHDTVData {
    char pad[24];
    int m_screenWidth;
};

extern UIHDTVData* g_uihdtv;

struct UIHDTV {
    static int GetScreenWidth();
};

int UIHDTV::GetScreenWidth() {
    return g_uihdtv->m_screenWidth;
}
