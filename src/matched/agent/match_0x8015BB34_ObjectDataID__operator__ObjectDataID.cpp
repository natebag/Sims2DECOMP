// 0x8015BB34 ObjectDataID::operator<(ObjectDataID const&) (56 B)
// FLAGS: -fno-schedule-insns
// Pattern: lexicographic compare; li result=0 between loads; cmplw blt/cmpw bne/cmplw bge; goto shared label

struct ObjectDataID {
    unsigned int m_namespaceID;
    unsigned short m_resourceID;
    bool operator<(const ObjectDataID& rhs) const;
};

bool ObjectDataID::operator<(const ObjectDataID& rhs) const {
    unsigned int a = m_namespaceID;
    bool result = false;
    unsigned int b = rhs.m_namespaceID;
    if (a < b) goto set_true;
    if (a != b) goto done;
    {
        unsigned short c = m_resourceID;
        unsigned short d = rhs.m_resourceID;
        if (c >= d) goto done;
    }
  set_true:
    result = true;
  done:
    return result;
}
