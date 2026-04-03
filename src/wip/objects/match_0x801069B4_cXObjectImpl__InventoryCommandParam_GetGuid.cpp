struct InventoryCommandParam {
    unsigned short field0;
    unsigned short field2;
    unsigned char field4;
};

struct InterpLocal {
    unsigned char source;
    char pad;
    unsigned short index;
    short result;
};

struct cXObjectImpl_ICPG {
    long long InterpValue(short, short, short **, float **, short *);
    short InventoryCommandParam_GetGuid(InventoryCommandParam &param);
};

short cXObjectImpl_ICPG::InventoryCommandParam_GetGuid(InventoryCommandParam &param) {
    if (param.field4 >> 7) {
        return 0;
    }
    InterpLocal local;
    local.result = -1;
    unsigned short rawField2 = param.field2;
    unsigned short rawField0 = param.field0;
    short dataIndex = (short)rawField2;
    unsigned char dataSource = (unsigned char)rawField0;
    local.source = (unsigned char)rawField0;
    local.index = rawField2;
    if (InterpValue(dataSource, dataIndex, 0, 0, &local.result) == -1) {
        return 0;
    }
    return local.result;
}
