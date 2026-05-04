// cXObjectImpl::InventoryCommandParam_GetCount(InventoryCommandParam &) at 0x80106A28 (100B)
//
// Looks up an inventory-command count via InterpValue. The DOL produces a
// 100B function that copies two fields of `param` (varType byte, opIdx
// half) into a 6-byte local block at sp+8 plus result half at sp+12, then
// passes &result to InterpValue. The byte/half stores at sp+8/sp+10 are
// dead w.r.t. InterpValue's contract but appear in DOL — modeling the
// fields as a `ParamLocal` struct member in the source reproduces them.
//
// Source-level coax: assign `varType` BEFORE `opIdx`. cc1plus then picks
// r11 for opIdx (matching DOL) and r0 for varType, and naturally emits
// the post-clrlwi sth/stb pair in the DOL order. No mutator needed.

struct InventoryCommandParam;

struct ParamLocal {
    unsigned char varType;
    char pad;
    unsigned short opIdx;
    short result;
};

struct ICGC {
    long long InterpValue(short, short, short **, float **, short *);
    int InventoryCommandParam_GetCount(InventoryCommandParam &param);
};

int ICGC::InventoryCommandParam_GetCount(InventoryCommandParam &param) {
    ParamLocal local;
    local.varType = *(unsigned char *)((char *)&param + 5);
    local.opIdx = *(unsigned short *)((char *)&param + 6);
    local.result = 0;
    long long r = InterpValue(local.varType, (short)local.opIdx, 0, 0, &local.result);
    if (r == -1LL) {
        return 0;
    }
    return local.result;
}
