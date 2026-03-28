struct AptLocalCtx_E {
    char pad[4];
    void* m_arg1;
    void* m_arg2;
};
extern void AptAction_Enumerate_inner(void* interp, void* a, void* b);
void AptActionEnumerate(void* interp, AptLocalCtx_E* ctx) {
    AptAction_Enumerate_inner(interp, ctx->m_arg1, ctx->m_arg2);
}
