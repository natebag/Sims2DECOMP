// 0x80054414 (12 bytes) - IShrubObject::GetTypeInfo(void) const
// &m_typeInfo (returns base addr)
// FLAGS: -fno-schedule-insns

extern char IShrubObject__m_typeInfo[];

class IShrubObject {
public:
    char* GetTypeInfo() const;
};

char* IShrubObject::GetTypeInfo() const {
    return IShrubObject__m_typeInfo;
}
