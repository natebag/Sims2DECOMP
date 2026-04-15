// 0x801BBBF0 INGTarget::get_current_ingredient(void) (36B)
struct INGTarget;

extern void** INGTarget__find_current_ing_slot(INGTarget* self);

void* INGTarget__get_current_ingredient(INGTarget* self) {
    void** p = INGTarget__find_current_ing_slot(self);
    if (p == 0) return 0;
    return *p;
}
