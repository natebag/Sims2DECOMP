struct EInstance {
    char _pad[0x2C];
    int m_field2C;
    int m_field30;
    void RegisterHiddenFn(int a, int b);
};
void EInstance::RegisterHiddenFn(int a, int b) {
    int t = b;
    m_field2C = a;
    m_field30 = t;
}
