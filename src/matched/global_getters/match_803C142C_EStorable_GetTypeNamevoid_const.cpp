// 0x803C142C EStorable::GetTypeName (12b)
// TU: e_instance

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo EStorable_typeInfo;

struct EStorable {
    const char* GetTypeName() const;
};

const char* EStorable::GetTypeName() const {
    return EStorable_typeInfo.m_name;
}
