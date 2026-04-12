// 0x803C1438 EStorable::GetTypeKey (12b)
// TU: e_instance

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo EStorable_typeInfo;

struct EStorable {
    unsigned int GetTypeKey() const;
};

unsigned int EStorable::GetTypeKey() const {
    return EStorable_typeInfo.m_key;
}
