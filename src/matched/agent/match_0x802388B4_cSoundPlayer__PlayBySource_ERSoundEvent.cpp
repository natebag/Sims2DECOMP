void target_func(void*, int, int, int, int, int, int, int, void*, short);

struct cSoundPlayer {
    char pad[0x7C];
    void* m_field7C;
    void PlayBySource(void* event, short priority);
};

void cSoundPlayer::PlayBySource(void* event, short priority) {
    if (m_field7C == 0) return;
    target_func(this, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, event, priority);
}
