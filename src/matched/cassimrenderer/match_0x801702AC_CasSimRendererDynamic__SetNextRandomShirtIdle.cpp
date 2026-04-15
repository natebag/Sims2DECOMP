/* CasSimRendererDynamic::SetNextRandomShirtIdle(void) - 0x801702AC (116B) */

struct SomeAnim;

struct IdleArray {
    char pad[40];
    SomeAnim* m_default;  // +40
    SomeAnim* m_low;      // +44
    SomeAnim* m_mid;      // +48
};

int RangedRandInt(int n);

class CasSimRendererDynamic {
public:
    char pad[548];
    IdleArray* m_array;  // +548

    SomeAnim* SetNextAnimation(SomeAnim* anim);
    SomeAnim* SetNextRandomShirtIdle(void);
};

SomeAnim* CasSimRendererDynamic::SetNextRandomShirtIdle(void) {
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
