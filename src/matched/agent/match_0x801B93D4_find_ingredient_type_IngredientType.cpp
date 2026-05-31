// 0x801B93D4 find_ingredient_type(IngredientType**, unsigned, int) (72 B)

struct IngredientType {
    short m_id;
};

IngredientType* find_ingredient_type(IngredientType** list, unsigned count, int id) {
    unsigned i = 0;
    IngredientType** p = list;
    IngredientType* item;
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
