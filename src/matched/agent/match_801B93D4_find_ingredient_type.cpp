struct IngredientType {
    short m_id;
};

IngredientType *find_ingredient_type(IngredientType **array, unsigned int count, short id) {
    for (unsigned int i = 0; i < count; i++) {
        IngredientType *ing = array[i];
        if (ing == 0) break;
        if (ing->m_id == id) return ing;
    }
    return 0;
}
