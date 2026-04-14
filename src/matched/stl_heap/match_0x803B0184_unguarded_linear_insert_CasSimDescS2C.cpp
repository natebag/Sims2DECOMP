// 0x803B0184 __unguarded_linear_insert<CasSimDescriptionS2C**, CasSimDescriptionS2C*, bool (*)(CasSimDescriptionS2C*, CasSimDescriptionS2C*)> (96B)

struct CasSimDescriptionS2C;
typedef bool (*CmpFnCasSimDescS2C)(CasSimDescriptionS2C*, CasSimDescriptionS2C*);

void __unguarded_linear_insert_CasSimDescS2C(CasSimDescriptionS2C** last, CasSimDescriptionS2C* value, CmpFnCasSimDescS2C cmp) {
    CasSimDescriptionS2C** next = last - 1;
    while (cmp(value, *next)) {
        *last = *next;
        last = next;
        next = last - 1;
    }
    *last = value;
}
