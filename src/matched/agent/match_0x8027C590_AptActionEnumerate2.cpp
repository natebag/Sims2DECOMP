struct AptLocalCtx_E2 {
    char pad[4];
    void* m_arg1;
    void* m_arg2;
};
extern void AptAction_Enumerate2_inner(void* interp, void* a, void* b);
void AptActionEnumerate2(void* interp, AptLocalCtx_E2* ctx) {
    AptAction_Enumerate2_inner(interp, ctx->m_arg1, ctx->m_arg2);
}
