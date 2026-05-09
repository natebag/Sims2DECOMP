// 0x801F99FC KEYTarget::IsModeValid(void) (32B)

struct KEYTarget {
    char pad[0x8c];
    int m_mode;
    int IsModeValid() const;
};

int KEYTarget::IsModeValid() const {
    int r = 0;
    if (m_mode <= 4 && m_mode >= 1) r = 1;
    return r;
}
