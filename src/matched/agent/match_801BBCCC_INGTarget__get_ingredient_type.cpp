struct Ingredient {
    char _pad[0x04];
    struct IngredientType {
        short m_typeId;
    };
    IngredientType *m_type;
};

class INGTarget {
public:
    struct IngInfo {
        Ingredient *m_ingredient;
        void *m_ptr2;
    };

    short get_ingredient_type(IngInfo &info) const;
};

short INGTarget::get_ingredient_type(IngInfo &info) const {
    Ingredient *ing = info.m_ingredient;
    if (ing == 0) return 0;
    Ingredient::IngredientType *type = ing->m_type;
    if (type == 0) return 0;
    return type->m_typeId;
}
