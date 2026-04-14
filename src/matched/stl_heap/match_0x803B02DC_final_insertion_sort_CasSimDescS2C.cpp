// 0x803B02DC __final_insertion_sort<CasSimDescriptionS2C**, ...> (108B)
struct CasSimDescriptionS2C;
typedef bool (*CmpFn_Cas)(CasSimDescriptionS2C*, CasSimDescriptionS2C*);
extern void __insertion_sort_Cas(CasSimDescriptionS2C** first, CasSimDescriptionS2C** last, CmpFn_Cas cmp);
extern void __unguarded_insertion_sort_aux_Cas(CasSimDescriptionS2C** first, CasSimDescriptionS2C** last, CasSimDescriptionS2C** dummy, CmpFn_Cas cmp);

void __final_insertion_sort_Cas(CasSimDescriptionS2C** first, CasSimDescriptionS2C** last, CmpFn_Cas cmp) {
    int count = last - first;
    if (count > 16) {
        CasSimDescriptionS2C** mid = first + 16;
        __insertion_sort_Cas(first, mid, cmp);
        __unguarded_insertion_sort_aux_Cas(mid, last, (CasSimDescriptionS2C**)0, cmp);
    } else {
        __insertion_sort_Cas(first, last, cmp);
    }
}
