struct SomeObjData {
    char pad[0x24];
    short value;
};

struct SomeObjInfo {
    char pad[0x38];
    SomeObjData* data;
};

class ObjSelector;

SomeObjInfo* GetObjInfo(ObjSelector*);

int StaticGetObjectValue(ObjSelector* sel) {
    if (!sel) return 0;
    SomeObjInfo* info = GetObjInfo(sel);
    SomeObjData* data = info->data;
    if (!data) return 0;
    return data->value;
}
