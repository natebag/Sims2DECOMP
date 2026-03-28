extern void* EIStaticModel_opnew(unsigned int size);
extern void* EIStaticModel_copyCtor(void* mem, void* src);

void* EIStaticModel_Construct(void* src) {
    void* mem = EIStaticModel_opnew(0x320);
    return EIStaticModel_copyCtor(mem, src);
}
