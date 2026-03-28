extern int __vt_cSoundPlayer[];

void KillSounds(void);

struct BaseClass {
    ~BaseClass();
};

struct SoundHandle {
    char pad[0x50];
    int m_flags;
};

struct cSoundPlayer : BaseClass {
    char pad04[0x78];
    SoundHandle* m_soundHandle;
    
    ~cSoundPlayer();
};

cSoundPlayer::~cSoundPlayer() {
    *(int*)this = (int)__vt_cSoundPlayer;
    if (m_soundHandle != 0) {
        if ((m_soundHandle->m_flags & 0x4000) == 0) {
            KillSounds();
        }
    }
}
