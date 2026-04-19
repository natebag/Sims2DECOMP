// 0x80079A64 CUnlockDisplayObject::SetCharacterID(unsigned int) (40B)

struct CUnlockDisplayObject {
    char pad[0x30];
    unsigned int m_characterID;
    unsigned int m_someField;
    char pad2[0x48];
    int m_flag;

    void SetCharacterID(unsigned int id);
};

void CUnlockDisplayObject::SetCharacterID(unsigned int id) {
    m_characterID = id;
    int flag = 0;
    if (id != 0 && m_someField == 0)
        flag = 1;
    m_flag = flag;
}
