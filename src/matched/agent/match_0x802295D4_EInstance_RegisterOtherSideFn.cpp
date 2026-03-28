struct EInstance {
    char _pad[0x20];
    int m_field20;
    int m_field24;
    void RegisterOtherSideFn(int a, int b);
};
void EInstance::RegisterOtherSideFn(int a, int b) {
    int t = b;
    m_field24 = a;
    m_field20 = t;
}
