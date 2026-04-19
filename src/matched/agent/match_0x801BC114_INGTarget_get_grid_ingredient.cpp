// 0x801BC114 (64B) INGTarget::get_grid_ingredient(short)
// Linear search over 12-slot array of Ingredient* pointers at this+0x1B0,
// stride 4. Returns slot if *slot && (*slot)->id matches. Leaf fn.

struct Ingredient {
    short id;
};

struct GridSlot {
    Ingredient* ing;
};

class INGTarget {
public:
    char pad_000[0x1B0];
    GridSlot* m_gridSlots[12];
    GridSlot* get_grid_ingredient(short id);
};

GridSlot* INGTarget::get_grid_ingredient(short id) {
    GridSlot** p = &m_gridSlots[0];
    for (int i = 0; i < 12; ++i) {
        GridSlot* s = *p;
        ++p;
        if (s == 0) continue;
        Ingredient* ing = s->ing;
        if (ing == 0) continue;
        if (ing->id == id) return s;
    }
    return 0;
}
