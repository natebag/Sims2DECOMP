void WallManipulator_CancelSession(void*);

struct WallManipulator {
    char pad_00[0xC4];
    int m_flags;

    void HandleExitRequest();
};

void WallManipulator::HandleExitRequest() {
    int flags = m_flags;
    if (flags & 1) {
        int newFlags = flags & ~0x45;
        m_flags = newFlags;
        if ((flags & 0x200) == 0) {
            m_flags = newFlags & ~0x8;
        }
    } else {
        m_flags = 0;
        WallManipulator_CancelSession(this);
    }
}
