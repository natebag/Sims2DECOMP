// 0x8001DFC8 CameraDirector::LetterBox(bool) (24B)

struct CameraDirector {
    char pad[0x234];
    int m_letterBoxParam;
    char pad2[0x08];
    int m_letterBoxFlags;

    void LetterBox(int enable);
};

void CameraDirector::LetterBox(int enable) {
    int flags = m_letterBoxFlags ^ 1;
    if (flags & 1) {
        m_letterBoxParam = enable;
    }
}
