// VERSION_DIFF: branch structure differs (DOL uses li r31 pattern)
// C++ logic is correct
// 0x800AA9BC (92 bytes)
/* AmbientSoundPlayer::IsFinished(void) */

struct AmbientSoundPlayer_IsFinished_Vtable {
    char pad[0x28];
    short m_delta;
    char _pad[2];
    void* m_func;
};

struct AmbientSoundPlayer_IsFinished_Inner {
    AmbientSoundPlayer_IsFinished_Vtable* m_vtable;
};

struct AmbientSoundPlayer_IsFinished {
    char _pad[0x08];
    AmbientSoundPlayer_IsFinished_Inner* m_inner;
    
    int IsFinished(void);
};

int AmbientSoundPlayer_IsFinished::IsFinished(void) {
    AmbientSoundPlayer_IsFinished_Inner* inner = m_inner;
    if (inner != 0) {
        AmbientSoundPlayer_IsFinished_Vtable* vt = inner->m_vtable;
        short delta = vt->m_delta;
        int (*fn)(void*) = (int (*)(void*))vt->m_func;
        int result = fn((char*)inner + delta);
        if (result != 0) {
            return 1;
        }
    }
    return 0;
}
