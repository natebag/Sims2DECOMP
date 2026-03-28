struct GA_STF {
    char pad[0x4D8];
    void* m_traceFunc;
    void* m_traceCtx;
    void SetTraceFunction(void* func, void* ctx);
};
void GA_STF::SetTraceFunction(void* func, void* ctx) {
    m_traceFunc = func;
    m_traceCtx = ctx;
}
