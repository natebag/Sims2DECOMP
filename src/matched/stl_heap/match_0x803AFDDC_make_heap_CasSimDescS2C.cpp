// 0x803AFDDC make_heap<CasSimDescriptionS2C**, ...> (128B)
struct CasSimDescriptionS2C;
typedef bool (*CmpFn_CasSimDescS2C)(CasSimDescriptionS2C*, CasSimDescriptionS2C*);
extern void __adjust_heap_CasSimDescS2C(CasSimDescriptionS2C** first, int hole, int len, CasSimDescriptionS2C* value, CmpFn_CasSimDescS2C cmp);

void make_heap_CasSimDescS2C(CasSimDescriptionS2C** first, CasSimDescriptionS2C** last, CmpFn_CasSimDescS2C cmp) {
    int count = last - first;
    if (count <= 1) return;
    int parent = (count - 2) / 2;
    do {
        CasSimDescriptionS2C* value = first[parent];
        __adjust_heap_CasSimDescS2C(first, parent, count, value, cmp);
        if (parent == 0) return;
        parent = parent - 1;
    } while (1);
}
