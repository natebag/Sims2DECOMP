struct EInstance {
    char _pad1[0x1C];
    int m_field1C;
    char _pad2[0x28 - 0x20];
    int m_field28;
    void RegisterThisSideFn(int a, int b);
};
void EInstance::RegisterThisSideFn(int a, int b) {
    int t = b;
    m_field28 = a;
    m_field1C = t;
}
