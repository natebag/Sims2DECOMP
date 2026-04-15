/* CasSimRendererDynamic::SetNextRandomRegularIdle(void) - 0x80170320 (116B) */

struct SomeAnim;

struct IdleArray2 {
    SomeAnim* m_default;  // +0
    SomeAnim* m_low;      // +4
    SomeAnim* m_mid;      // +8
};

int RangedRandInt(int n);

class CasSimRendererDynamic {
public:
    char pad[548];
    IdleArray2* m_array;  // +548

    SomeAnim* SetNextAnimation(SomeAnim* anim);
    SomeAnim* SetNextRandomRegularIdle(void);
};

SomeAnim* CasSimRendererDynamic::SetNextRandomRegularIdle(void) {
    int r = RangedRandInt(100);
    SomeAnim* anim;
    if (r <= 14) {
        anim = m_array->m_low;
    } else if ((unsigned)(r - 15) <= 14) {
        anim = m_array->m_mid;
    } else {
        anim = m_array->m_default;
    }
    SetNextAnimation(anim);
    return anim;
}
