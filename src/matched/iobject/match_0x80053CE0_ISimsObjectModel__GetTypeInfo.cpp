// 0x80053CE0 (12 bytes) - ISimsObjectModel::GetTypeInfo(void) const
// Returns address of static m_typeInfo (.bss:0x804FB7C8, size 0x28).
// S17 semantic conversion of inject-based stub.
// FLAGS: -fno-schedule-insns

extern char ISimsObjectModel__m_typeInfo[];

class ISimsObjectModel {
public:
    char* GetTypeInfo() const;
};

char* ISimsObjectModel::GetTypeInfo() const {
    return ISimsObjectModel__m_typeInfo;
}
