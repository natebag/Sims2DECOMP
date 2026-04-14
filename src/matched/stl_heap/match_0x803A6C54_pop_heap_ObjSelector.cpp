// 0x803A6C54 pop_heap template (64B)
struct ObjSelector;
typedef bool (*CmpFn_pop_heap_ObjSelector)(ObjSelector*, ObjSelector*);
extern void __adjust_heap_pop_heap_ObjSelector(ObjSelector** first, int hole, int len, ObjSelector* value, CmpFn_pop_heap_ObjSelector cmp);
void pop_heap_ObjSelector(ObjSelector** first, ObjSelector** last, CmpFn_pop_heap_ObjSelector cmp) {
    ObjSelector** last_m1 = last - 1;
    ObjSelector* value = *last_m1;
    *last_m1 = *first;
    __adjust_heap_pop_heap_ObjSelector(first, 0, last_m1 - first, value, cmp);
}
