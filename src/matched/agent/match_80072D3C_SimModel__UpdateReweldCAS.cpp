typedef unsigned char u8;

void SimModel_RebuildModified(u8*);
void SimRenderer_MorphParts(u8*, int);
void SimModel_DeallocateMorphResources(u8*);

void SimModel_UpdateReweldCAS(u8* pThis, int bForce) {
    SimModel_RebuildModified(pThis);
    int flags = *(int*)(pThis + 0x04);
    if (!(flags & 4)) {
        if (bForce != 0) {
            SimRenderer_MorphParts(pThis + 0x68, 1);
            SimModel_DeallocateMorphResources(pThis);
        }
    }
}
