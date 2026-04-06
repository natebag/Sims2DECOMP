extern void* gAptCtx1;
extern void* gAptCtx2;
extern "C" void registerRefs1(void*);
extern "C" void registerRefs2(void*, int);
void AptRegisterGlobalReferences() {
    registerRefs1(gAptCtx1);
    if (gAptCtx2) {
        registerRefs2(gAptCtx2, 0);
    }
}
