void target_func(void*, int, int, int, int, int, void*, short, int, int);

struct cSoundPlayer {
    char pad[0x7C];
    void* m_field7C;
    void PlayBySource(char* name, short priority);
};

void cSoundPlayer::PlayBySource(char* name, short priority) {
    if (m_field7C == 0) return;
    target_func(this, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, name, priority, 0, 0);
}
