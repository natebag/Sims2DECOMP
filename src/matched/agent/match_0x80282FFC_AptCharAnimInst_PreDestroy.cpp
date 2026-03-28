struct AptCharAnimInst_PD {
    char pad[0x24];
    char m_sub;
};
extern void AptCharAnimInst_PreDestroy_inner(void* sub, int flag);
void AptCharAnimInst_PreDestroy(AptCharAnimInst_PD* self) {
    AptCharAnimInst_PreDestroy_inner(&self->m_sub, 0);
}
