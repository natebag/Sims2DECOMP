// 0x802331F8 ERLevel::IsInstanceListKindaFull (24b)
struct ERLevel {
    char pad[0x2C2B8];
    int m_instanceCount;
    int IsInstanceListKindaFull();
};

int ERLevel::IsInstanceListKindaFull() {
    return m_instanceCount > 1663;
}
