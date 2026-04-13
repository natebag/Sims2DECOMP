// 0x801069B4 (116 bytes) — [VERSION_DIFF]
// cXObjectImpl::InventoryCommandParam_GetGuid(InventoryCommandParam &)
// Extracts GUID from inventory command params via InterpValue lookup.
// Returns 0 on error, otherwise the interpreted result value.
// NON_MATCHING: v3.93 register alloc differs (r5/r0 vs DOL r11/r9),
// omits dead stores to stack, uses different branch structure.
// Same class of issue as GetCount — needs v1.76 compiler.

struct ICGG {
    long long InterpValue(short, short, short **, float **, short *);
    int InventoryCommandParam_GetGuid(unsigned short *param);
};

int ICGG::InventoryCommandParam_GetGuid(unsigned short *param) {
    if (*(unsigned char *)((char *)param + 4) >> 7) {
        return 0;
    }
    short result = -1;
    unsigned short opIdx = param[1];
    unsigned short varTypeRaw = param[0];
    long long r = InterpValue((unsigned char)varTypeRaw, (short)opIdx, 0, 0, &result);
    if (r == -1LL) {
        return 0;
    }
    return result;
}
