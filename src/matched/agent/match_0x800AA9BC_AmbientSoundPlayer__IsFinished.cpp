// 0x800AA9BC AmbientSoundPlayer::IsFinished(void) (92B)

struct AsfVT {
    char pad[0x28];
    short m_delta;
    char pad2[2];
    void* m_func;
};

struct AsfInner {
    AsfVT* m_vtable;
};

struct AmbientSoundPlayer {
    char pad[0x08];
    AsfInner* m_inner;

    int IsFinished();
};

int AmbientSoundPlayer::IsFinished() {
    int result = 0;
    AsfInner* inner = m_inner;
    if (inner == 0) {
        result = 1;
    } else {
        AsfVT* vt = inner->m_vtable;
        short delta = vt->m_delta;
        int (*fn)(void*) = (int (*)(void*))vt->m_func;
        if (fn((char*)inner + delta) == 0) {
            result = 1;
        }
    }
    return result;
}
