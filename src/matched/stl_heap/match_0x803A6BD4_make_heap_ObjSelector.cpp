// 0x803A6BD4 make_heap<ObjSelector**, bool (*)(ObjSelector*, ObjSelector*)> (128B)
struct ObjSelector;
typedef bool (*CmpFn_ObjSelector)(ObjSelector*, ObjSelector*);
extern void __adjust_heap_ObjSelector(ObjSelector** first, int hole, int len, ObjSelector* value, CmpFn_ObjSelector cmp);

void make_heap_ObjSelector(ObjSelector** first, ObjSelector** last, CmpFn_ObjSelector cmp) {
    int count = last - first;
    if (count <= 1) return;
    int parent = (count - 2) / 2;
    do {
        ObjSelector* value = first[parent];
        __adjust_heap_ObjSelector(first, parent, count, value, cmp);
        if (parent == 0) return;
        parent = parent - 1;
    } while (1);
}
