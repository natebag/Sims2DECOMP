// 0x803A541C pop_heap<FamilyImpl**, bool (*)(Family*&, Family*&)> (64B)

struct FamilyImpl;
struct Family;
typedef bool (*FamilyCmp)(Family*&, Family*&);

extern void __adjust_heap_FamilyImpl(FamilyImpl** first, int hole, int len, FamilyImpl* value, FamilyCmp cmp);

void pop_heap_FamilyImpl(FamilyImpl** first, FamilyImpl** last, FamilyCmp cmp) {
    FamilyImpl** last_m1 = last - 1;
    FamilyImpl* value = *last_m1;
    *last_m1 = *first;
    __adjust_heap_FamilyImpl(first, 0, last_m1 - first, value, cmp);
}
