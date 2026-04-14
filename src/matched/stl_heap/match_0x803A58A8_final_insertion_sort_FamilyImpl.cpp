// 0x803A58A8 __final_insertion_sort<FamilyImpl**, bool (*)(Family*&, Family*&)> (108B)
struct FamilyImpl;
struct Family;
typedef bool (*FamilyCmp)(Family*&, Family*&);

extern void __insertion_sort_FamilyImpl(FamilyImpl** first, FamilyImpl** last, FamilyCmp cmp);
extern void __unguarded_insertion_sort_aux_FamilyImpl(FamilyImpl** first, FamilyImpl** last, FamilyImpl** dummy, FamilyCmp cmp);

void __final_insertion_sort_FamilyImpl(FamilyImpl** first, FamilyImpl** last, FamilyCmp cmp) {
    int count = last - first;
    if (count > 16) {
        FamilyImpl** mid = first + 16;
        __insertion_sort_FamilyImpl(first, mid, cmp);
        __unguarded_insertion_sort_aux_FamilyImpl(mid, last, (FamilyImpl**)0, cmp);
    } else {
        __insertion_sort_FamilyImpl(first, last, cmp);
    }
}
