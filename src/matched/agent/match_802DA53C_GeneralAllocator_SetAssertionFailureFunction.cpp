struct GA_SAFF {
    char pad[0x4D0];
    void* m_assertFunc;
    void* m_assertCtx;
    void SetAssertionFailureFunction(void* func, void* ctx);
};
void GA_SAFF::SetAssertionFailureFunction(void* func, void* ctx) {
    m_assertFunc = func;
    m_assertCtx = ctx;
}
