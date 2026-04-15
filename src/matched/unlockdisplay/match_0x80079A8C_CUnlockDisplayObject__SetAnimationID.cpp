/* CUnlockDisplayObject::SetAnimationID(unsigned int) - 0x80079A8C (40B) */

class CUnlockDisplayObject {
public:
    char pad0[48];
    unsigned int m_charID;
    unsigned int m_animID;
    char pad1[72];
    int m_enabled;

    void SetAnimationID(unsigned int id);
};

void CUnlockDisplayObject::SetAnimationID(unsigned int id) {
    unsigned int ch = m_charID;
    int f = 0;
    m_animID = id;
    if (ch == 0 || id == 0) f = 1;
    m_enabled = f;
}
