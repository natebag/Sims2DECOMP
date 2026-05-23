// 0x800542B0 (12 bytes) - ISimsCounterTopObject::GetTypeInfoStatic(void)
// &m_typeInfo (static, same bytes)
// FLAGS: -fno-schedule-insns

extern char ISimsCounterTopObject__m_typeInfo[];

class ISimsCounterTopObject {
public:
    static char* GetTypeInfoStatic();
};

char* ISimsCounterTopObject::GetTypeInfoStatic() {
    return ISimsCounterTopObject__m_typeInfo;
}
