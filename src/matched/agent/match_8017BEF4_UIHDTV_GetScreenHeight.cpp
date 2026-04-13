/* UIHDTV::GetScreenHeight(void) - 0x8017BEF4 (12 bytes) */

struct UIHDTVData {
    char pad[28];
    int m_screenHeight;
};

extern UIHDTVData* g_uihdtv;

struct UIHDTV {
    static int GetScreenHeight();
};

int UIHDTV::GetScreenHeight() {
    return g_uihdtv->m_screenHeight;
}
