struct AptCharSpriteInstBase_PD {
    char pad[0x24];
    char m_sub;
};
extern void AptCharSpriteInstBase_PreDestroy_inner(void* sub);
void AptCharSpriteInstBase_PreDestroy(AptCharSpriteInstBase_PD* self) {
    AptCharSpriteInstBase_PreDestroy_inner(&self->m_sub);
}
