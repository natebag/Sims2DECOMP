// 0x800568B8 ISimInstance::GetTypeName (12b)

extern char g_typeTable[];

struct ISimInstance {
    virtual const char* GetTypeName() const;
};

const char* ISimInstance::GetTypeName() const {
    return *(const char**)(g_typeTable + 12);
}
