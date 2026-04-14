// 0x803A70D4 __final_insertion_sort<ObjSelector**, bool (*)(ObjSelector*, ObjSelector*)> (108B)
struct ObjSelector;
typedef bool (*CmpFn_ObjSel)(ObjSelector*, ObjSelector*);
extern void __insertion_sort_ObjSelector(ObjSelector** first, ObjSelector** last, CmpFn_ObjSel cmp);
extern void __unguarded_insertion_sort_aux_ObjSelector(ObjSelector** first, ObjSelector** last, ObjSelector** dummy, CmpFn_ObjSel cmp);

void __final_insertion_sort_ObjSelector(ObjSelector** first, ObjSelector** last, CmpFn_ObjSel cmp) {
    int count = last - first;
    if (count > 16) {
        ObjSelector** mid = first + 16;
        __insertion_sort_ObjSelector(first, mid, cmp);
        __unguarded_insertion_sort_aux_ObjSelector(mid, last, (ObjSelector**)0, cmp);
    } else {
        __insertion_sort_ObjSelector(first, last, cmp);
    }
}
