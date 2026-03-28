struct Ingredient {
    short m_id;
};

Ingredient *find_ingredient(Ingredient **array, unsigned int count, short id) {
    for (unsigned int i = 0; i < count; i++) {
        Ingredient *ing = array[i];
        if (ing == 0) break;
        if (ing->m_id == id) return ing;
    }
    return 0;
}
