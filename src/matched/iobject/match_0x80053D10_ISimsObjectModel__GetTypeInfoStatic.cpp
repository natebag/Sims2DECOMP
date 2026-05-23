// 0x80053D10 (12 bytes) - ISimsObjectModel::GetTypeInfoStatic(void)
// Static method returning address of m_typeInfo. Same bytes as GetTypeInfo.
// FLAGS: -fno-schedule-insns

extern char ISimsObjectModel__m_typeInfo[];

class ISimsObjectModel {
public:
    static char* GetTypeInfoStatic();
};

char* ISimsObjectModel::GetTypeInfoStatic() {
    return ISimsObjectModel__m_typeInfo;
}
