// 0x803A6F7C __unguarded_linear_insert<ObjSelector**, ObjSelector*, bool (*)(ObjSelector*, ObjSelector*)> (96B)

struct ObjSelector;
typedef bool (*CmpFnObjSelector)(ObjSelector*, ObjSelector*);

void __unguarded_linear_insert_ObjSelector(ObjSelector** last, ObjSelector* value, CmpFnObjSelector cmp) {
    ObjSelector** next = last - 1;
    while (cmp(value, *next)) {
        *last = *next;
        last = next;
        next = last - 1;
    }
    *last = value;
}
