struct GA_SHF {
    char pad[0x4BC];
    void* m_hookFunc;
    void* m_hookCtx;
    void SetHookFunction(void* func, void* ctx);
};
void GA_SHF::SetHookFunction(void* func, void* ctx) {
    m_hookFunc = func;
    m_hookCtx = ctx;
}
