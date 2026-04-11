/* FadeSquare::StartFade(void) at 0x8021CEE4 (12B) */

struct FadeSquare {
    char pad[0x14];
    int m_fadeStarted;

    void StartFade(void);
};

void FadeSquare::StartFade(void) {
    m_fadeStarted = 1;
}
