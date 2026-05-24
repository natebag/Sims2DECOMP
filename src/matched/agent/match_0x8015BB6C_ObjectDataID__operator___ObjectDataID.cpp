// 0x8015BB6C ObjectDataID::operator==(ObjectDataID const&) (48 B)
// FLAGS: -fno-schedule-insns
// Pattern: li result=0 between loads; cmpw bne for !=; xor+subfic+adde branchless equality for subId

struct ObjectDataID {
    unsigned int m_namespaceID;
    unsigned short m_resourceID;
    bool operator==(const ObjectDataID& rhs) const;
};

bool ObjectDataID::operator==(const ObjectDataID& rhs) const {
    unsigned int a = m_namespaceID;
    bool result = false;
    unsigned int b = rhs.m_namespaceID;
    if (a != b) goto done;
    {
        unsigned short c = m_resourceID;
        unsigned short d = rhs.m_resourceID;
        result = (c == d);
    }
  done:
    return result;
}
