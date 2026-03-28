typedef unsigned char u8;

void SimModel_FlushLoadingModels(u8*);
void SimModel_DeallocateAllModels(u8*);
void SimModel_DeallocateAllSkinTextures(u8*);
void CasSimPartsS2C_dtor(void*, int);
void __builtin_delete_func(void*);

void SimModel_Reset(u8* pThis) {
    SimModel_FlushLoadingModels(pThis);
    SimModel_DeallocateAllModels(pThis);
    SimModel_DeallocateAllSkinTextures(pThis);
    void* pParts = *(void**)(pThis + 0x138);
    if (pParts != 0) {
        CasSimPartsS2C_dtor(pParts, 3);
    }
    int oldFlags = *(int*)(pThis + 0x154);
    *(void**)(pThis + 0x138) = 0;
    *(int*)(pThis + 0x150) = 1;
    if (oldFlags != 0) {
        void* pDesc = *(void**)(pThis + 0x13C);
        if (pDesc != 0) {
            __builtin_delete_func(pDesc);
            *(void**)(pThis + 0x13C) = 0;
        }
    }
    *(void**)(pThis + 0x13C) = 0;
    *(int*)(pThis + 0x154) = 0;
}
