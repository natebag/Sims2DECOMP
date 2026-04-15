/* CUnlockDisplayObject::SetCharacterID(unsigned int) - 0x80079A64 (40B) */

class CUnlockDisplayObject {
public:
    char pad0[48];
    unsigned int m_charID;
    unsigned int m_animID;
    char pad1[72];
    int m_enabled;

    void SetCharacterID(unsigned int id);
};

void CUnlockDisplayObject::SetCharacterID(unsigned int id) {
    m_charID = id;
    int f = 0;
    if (id == 0 || m_animID == 0) f = 1;
    m_enabled = f;
}
