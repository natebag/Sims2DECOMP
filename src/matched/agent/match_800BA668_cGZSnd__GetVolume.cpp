class cGZSnd {
public:
    char pad[0x20];
    int m_volume;

    int GetVolume(void);
};

int cGZSnd::GetVolume(void) {
    return m_volume;
}
