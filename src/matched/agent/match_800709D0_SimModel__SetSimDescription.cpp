typedef unsigned char u8;

void __builtin_delete_func(void*);
void CasSimPartsS2C_SetGender(void*, int);

void SimModel_SetSimDescription(u8* pThis, u8* pDesc) {
    if (pDesc != 0) {
        int flags = *(int*)(pThis + 0x154);
        if (flags != 0) {
            void* pOld = *(void**)(pThis + 0x13C);
            if (pOld != 0) {
                __builtin_delete_func(pOld);
                *(void**)(pThis + 0x13C) = 0;
            }
        }
        *(u8**)(pThis + 0x13C) = pDesc;
        void* pParts = *(void**)(pThis + 0x138);
        int gender = *(int*)(pDesc + 0x84);
        CasSimPartsS2C_SetGender(pParts, gender);
    }
}
