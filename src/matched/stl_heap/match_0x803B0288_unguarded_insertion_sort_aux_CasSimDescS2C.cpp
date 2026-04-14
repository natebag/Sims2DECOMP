// 0x803B0288 __unguarded_insertion_sort_aux<CasSimDescriptionS2C**, CasSimDescriptionS2C*, bool (*)(CasSimDescriptionS2C*, CasSimDescriptionS2C*)> (84B)

struct CasSimDescriptionS2C;
typedef bool (*CmpFnCasSimDescS2C)(CasSimDescriptionS2C*, CasSimDescriptionS2C*);

extern void __unguarded_linear_insert_CasSimDescS2C(CasSimDescriptionS2C** last, CasSimDescriptionS2C* value, CmpFnCasSimDescS2C cmp);

void __unguarded_insertion_sort_aux_CasSimDescS2C(CasSimDescriptionS2C** first, CasSimDescriptionS2C** last, CasSimDescriptionS2C** /*unused*/, CmpFnCasSimDescS2C cmp) {
    CasSimDescriptionS2C** end = last;
    CasSimDescriptionS2C** i = first;
    if (i == end) return;
    do {
        __unguarded_linear_insert_CasSimDescS2C(i, *i, cmp);
        ++i;
    } while (i != end);
}
