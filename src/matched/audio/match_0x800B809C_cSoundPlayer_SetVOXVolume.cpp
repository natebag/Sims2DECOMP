// 0x800B809C cSoundPlayer::SetVOXVolume (96B)

extern char _data_80475F14[];
extern void* g_pSoundBox;
extern char _rodata_803E9B18[];
extern void cBoxX_Event(void* box, int eventId, int volume, int a, int b, float c);

class cSoundPlayer {
public:
    int m_initialized;
    void* m_soundSystem;
    int m_soundEnabled;
    void SetVOXVolume(int volume);
};

void cSoundPlayer::SetVOXVolume(int volume) {
    *(signed char*)((char*)*(void**)_data_80475F14 + 0x28) = (signed char)volume;
    if (m_initialized == 0) return;
    if (m_soundEnabled == 0) return;
    cBoxX_Event(g_pSoundBox, 0x27, volume, 0, 0, *(float*)_rodata_803E9B18);
}
