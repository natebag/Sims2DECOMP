/* cSamplePatch::SetLooped(int) - 0x80118F0C - 8 bytes */
/* stw r4, 16(r3); blr */

class cSamplePatch {
public:
    char _pad[0x10];
    int m_looped;

    void SetLooped(int looped);
};

void cSamplePatch::SetLooped(int looped) {
    m_looped = looped;
}
