struct EThread_GS {
    char pad[0x31C];
    void* m_stack;
    void* GetStack();
};
void* EThread_GS::GetStack() {
    return m_stack;
}
