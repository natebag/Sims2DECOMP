// 0x801B938C find_ingredient(Ingredient**, unsigned, int) (72 B)

struct Ingredient {
    short m_id;
};

Ingredient* find_ingredient(Ingredient** list, unsigned count, int id) {
    unsigned i = 0;
    Ingredient** p = list;
    Ingredient* item;
    if (i >= count) {
        goto ret0;
    }
    item = *p;
    while (item != 0) {
        if (item->m_id == id) {
            return item;
        }
        i++;
        if (i >= count) {
            goto ret0;
        }
        item = *++p;
    }
ret0:
    return 0;
}
