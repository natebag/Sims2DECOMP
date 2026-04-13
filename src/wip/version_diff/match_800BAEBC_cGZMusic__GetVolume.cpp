class cGZMusic {
public:
    void *vtable;
    int pad_04;
    int pad_08;
    int pad_0C;
    int pad_10;
    int m_volume;

    int GetVolume(void);
};

int cGZMusic::GetVolume(void) {
    return m_volume;
}
