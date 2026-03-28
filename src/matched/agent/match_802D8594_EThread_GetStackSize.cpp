struct EThread_GSS {
    char pad[0x320];
    int m_stackSize;
    int GetStackSize();
};
int EThread_GSS::GetStackSize() {
    return m_stackSize;
}
