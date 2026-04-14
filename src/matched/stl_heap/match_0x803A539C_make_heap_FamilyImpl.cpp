// 0x803A539C make_heap<FamilyImpl**, bool (*)(Family*&, Family*&)> (128B)

struct FamilyImpl;
struct Family;
typedef bool (*FamilyCmp)(Family*&, Family*&);

extern void __adjust_heap_FamilyImpl(FamilyImpl** first, int hole, int len, FamilyImpl* value, FamilyCmp cmp);

void make_heap_FamilyImpl(FamilyImpl** first, FamilyImpl** last, FamilyCmp cmp) {
    int count = last - first;
    if (count <= 1) return;
    int parent = (count - 2) / 2;
    do {
        FamilyImpl* value = first[parent];
        __adjust_heap_FamilyImpl(first, parent, count, value, cmp);
        if (parent == 0) return;
        parent = parent - 1;
    } while (1);
}
