// 0x800AAA18 (40B) AmbientSoundPlayer::IsValid(void)
// Returns true if both internal pointers are non-null.

struct AmbientSoundPlayer {
    void* m_ptr1;
    void* m_ptr2;
    bool IsValid();
};

bool AmbientSoundPlayer::IsValid() {
    return m_ptr1 != 0 && m_ptr2 != 0;
}
