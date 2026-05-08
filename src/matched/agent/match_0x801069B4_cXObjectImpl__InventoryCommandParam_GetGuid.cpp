// cXObjectImpl::InventoryCommandParam_GetGuid(InventoryCommandParam &) at 0x801069B4 (116B)
//
// Sister of InventoryCommandParam_GetCount @ 0x80106A28. Same ParamLocal
// struct shape — the byte/half stores at sp+8/sp+10 read dead from
// InterpValue's contract but appear in DOL because the source uses a
// stack-local struct whose address is taken via &local.result.
//
// Two differences vs GetCount:
//  (1) Source byte is the LOW BYTE of param.field0 (a 16-bit half), not a
//      direct uchar load — the DOL emits `lhz r11, 0(r4)` then `stb r11,
//      8(r1)`. So field0 must be declared as `unsigned short`, then the
//      varType assignment uses `(unsigned char)param.field0`.
//  (2) The result slot is initialized to -1 (sth -1) before the call, not
//      0 like GetCount. The post-call check is `result == -1LL` (compares
//      both r3 and r4 against -1).

struct InventoryCommandParam {
    unsigned short field0;
    unsigned short field2;
    unsigned char  flags;
};

struct ParamLocal {
    unsigned char  varType;
    char           pad;
    unsigned short opIdx;
    short          result;
};

struct ICGG {
    long long InterpValue(short, short, short **, float **, short *);
    int InventoryCommandParam_GetGuid(InventoryCommandParam &param);
};

int ICGG::InventoryCommandParam_GetGuid(InventoryCommandParam &param) {
    if ((param.flags >> 7) != 0) {
        return 0;
    }
    ParamLocal local;
    unsigned short f0 = param.field0;
    local.result = -1;
    local.varType = (unsigned char)f0;
    local.opIdx = param.field2;
    long long r = InterpValue((unsigned char)f0, (short)param.field2, 0, 0, &local.result);
    if (r == -1LL) {
        return 0;
    }
    return local.result;
}
