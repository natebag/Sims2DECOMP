// 0x80336340 ENgcMovie::PlayerGetFrameRate(void) (40B)

struct ENgcMovieMgr_Cls {
    char pad0[76];
    float m_cachedFps;
    char pad1[80];
    void* m_movie;
};

extern ENgcMovieMgr_Cls s_movieMgr;
extern char s_defaultFps_storage[];

struct ENgcMovie {
    float PlayerGetFrameRate();
};

float ENgcMovie::PlayerGetFrameRate() {
    if (s_movieMgr.m_movie != 0) return s_movieMgr.m_cachedFps;
    return *(float*)s_defaultFps_storage;
}
