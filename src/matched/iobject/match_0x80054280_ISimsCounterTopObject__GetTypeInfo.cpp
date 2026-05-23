// 0x80054280 (12 bytes) - ISimsCounterTopObject::GetTypeInfo(void) const
// &m_typeInfo (returns base addr)
// FLAGS: -fno-schedule-insns

extern char ISimsCounterTopObject__m_typeInfo[];

class ISimsCounterTopObject {
public:
    char* GetTypeInfo() const;
};

char* ISimsCounterTopObject::GetTypeInfo() const {
    return ISimsCounterTopObject__m_typeInfo;
}
