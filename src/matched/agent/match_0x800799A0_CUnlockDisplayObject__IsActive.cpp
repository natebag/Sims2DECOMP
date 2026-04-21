// 0x800799A0 (36B) CUnlockDisplayObject::IsActive(void)
// Returns 1 if m_field12 != 0 AND m_field120 == 0; else 0.
// Uses subfic+adde idiom for the (m_field120 == 0) bool conversion.

class CUnlockDisplayObject {
public:
    char _pad0[12];
    int m_field12;
    char _pad1[104];
    int m_field120;  // offset 120
    int IsActive();
};

int CUnlockDisplayObject::IsActive() {
    int r = 0;
    if (m_field12 != 0) {
        r = (m_field120 == 0);
    }
    return r;
}
