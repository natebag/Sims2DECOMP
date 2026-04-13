// 0x80106A28 (100 bytes) — [VERSION_DIFF]
// cXObjectImpl::InventoryCommandParam_GetCount(InventoryCommandParam &)
// Extracts count from inventory command params via InterpValue lookup.
// Returns 0 on error, otherwise the interpreted result value.
// NON_MATCHING: v3.93 uses different register alloc (r5/r0 vs DOL r11/r9),
// omits dead stores (stb sp+8, sth sp+10), uses mr instead of clrlwi.
// DOL=100B, compiled=92B (2 instructions fewer due to dead store elimination).

struct InventoryCommandParam;

struct ICGC {
    long long InterpValue(short, short, short **, float **, short *);
    int InventoryCommandParam_GetCount(InventoryCommandParam &param);
};

int ICGC::InventoryCommandParam_GetCount(InventoryCommandParam &param) {
    unsigned short opIdx = *(unsigned short *)((char *)&param + 6);
    unsigned char varType = *(unsigned char *)((char *)&param + 5);
    short result = 0;
    long long r = InterpValue(varType, (short)opIdx, 0, 0, &result);
    if (r == -1LL) {
        return 0;
    }
    return result;
}
