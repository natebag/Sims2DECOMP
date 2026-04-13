class cGZMusic {
public:
    void *vtable;
    int pad_04;
    int m_isPlaying;

    int IsPlaying(void);
};

int cGZMusic::IsPlaying(void) {
    return m_isPlaying;
}
