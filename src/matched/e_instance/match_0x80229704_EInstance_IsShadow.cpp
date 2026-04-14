// 0x80229704 EInstance::IsShadow (24b)
struct EInstance {
    char pad[0x18];
    int m_shadowField;
    int IsShadow();
};

int EInstance::IsShadow() {
    int result = 1;
    if (m_shadowField != 0) return result;
    result = 0;
    return result;
}
