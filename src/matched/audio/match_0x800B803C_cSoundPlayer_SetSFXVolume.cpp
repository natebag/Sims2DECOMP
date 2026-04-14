// 0x800B803C cSoundPlayer::SetSFXVolume (96B)

extern char _data_80475F14[];
extern void* g_pSoundBox;
extern char _rodata_803E9B14[];
extern void cBoxX_Event(void* box, int eventId, int volume, int a, int b, float c);

class cSoundPlayer {
public:
    int m_initialized;
    void* m_soundSystem;
    int m_soundEnabled;
    void SetSFXVolume(int volume);
};

void cSoundPlayer::SetSFXVolume(int volume) {
    *(signed char*)((char*)*(void**)_data_80475F14 + 0x1C) = (signed char)volume;
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    cBoxX_Event(g_pSoundBox, 0x2B, volume, 0, 0, *(float*)_rodata_803E9B14);
}
