/* ObjSelector::TestFromSameFile(ObjSelector *) const - 0x80110828 - 24 bytes */
/* lwz r0, 4(r3); lwz r3, 4(r4); xor r3, r0, r3; subfic r9, r3, 0; adde r3, r9, r3; blr */
/* Returns (this->m_field4 == other->m_field4) as int */

class ObjSelector {
public:
    char _pad[0x4];
    int m_fileId;

    int TestFromSameFile(ObjSelector *other) const;
};

int ObjSelector::TestFromSameFile(ObjSelector *other) const {
    return m_fileId == other->m_fileId;
}
