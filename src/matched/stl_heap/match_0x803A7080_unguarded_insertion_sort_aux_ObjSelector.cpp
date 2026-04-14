// 0x803A7080 __unguarded_insertion_sort_aux<ObjSelector**, ObjSelector*, bool (*)(ObjSelector*, ObjSelector*)> (84B)

struct ObjSelector;
typedef bool (*CmpFnObjSelector)(ObjSelector*, ObjSelector*);

extern void __unguarded_linear_insert_ObjSelector(ObjSelector** last, ObjSelector* value, CmpFnObjSelector cmp);

void __unguarded_insertion_sort_aux_ObjSelector(ObjSelector** first, ObjSelector** last, ObjSelector** /*unused*/, CmpFnObjSelector cmp) {
    ObjSelector** end = last;
    ObjSelector** i = first;
    if (i == end) return;
    do {
        __unguarded_linear_insert_ObjSelector(i, *i, cmp);
        ++i;
    } while (i != end);
}
