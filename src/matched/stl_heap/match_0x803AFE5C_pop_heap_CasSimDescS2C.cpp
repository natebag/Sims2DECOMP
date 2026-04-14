// 0x803AFE5C pop_heap template (64B)
struct CasSimDescriptionS2C;
typedef bool (*CmpFn_pop_heap_CasSimDescS2C)(CasSimDescriptionS2C*, CasSimDescriptionS2C*);
extern void __adjust_heap_pop_heap_CasSimDescS2C(CasSimDescriptionS2C** first, int hole, int len, CasSimDescriptionS2C* value, CmpFn_pop_heap_CasSimDescS2C cmp);
void pop_heap_CasSimDescS2C(CasSimDescriptionS2C** first, CasSimDescriptionS2C** last, CmpFn_pop_heap_CasSimDescS2C cmp) {
    CasSimDescriptionS2C** last_m1 = last - 1;
    CasSimDescriptionS2C* value = *last_m1;
    *last_m1 = *first;
    __adjust_heap_pop_heap_CasSimDescS2C(first, 0, last_m1 - first, value, cmp);
}
