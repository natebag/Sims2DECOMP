// 0x80054444 (12 bytes) - IShrubObject::GetTypeInfoStatic(void)
// &m_typeInfo (static, same bytes)
// FLAGS: -fno-schedule-insns

extern char IShrubObject__m_typeInfo[];

class IShrubObject {
public:
    static char* GetTypeInfoStatic();
};

char* IShrubObject::GetTypeInfoStatic() {
    return IShrubObject__m_typeInfo;
}
