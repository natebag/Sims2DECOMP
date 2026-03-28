struct GA_SMFF {
    char pad[0x4C4];
    void* m_mallocFailFunc;
    void* m_mallocFailCtx;
    void SetMallocFailureFunction(void* func, void* ctx);
};
void GA_SMFF::SetMallocFailureFunction(void* func, void* ctx) {
    m_mallocFailFunc = func;
    m_mallocFailCtx = ctx;
}
