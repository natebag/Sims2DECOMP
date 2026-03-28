struct IngredientTypeInfo {
    short m_type;
};

struct IngredientObj {
    void *m_data0;
    IngredientTypeInfo *m_typeInfo;
};

class INGTarget {
public:
    struct IngInfo {
        IngredientObj *m_obj;
        void *m_field4;
    };

    short get_ingredient_type(IngInfo &info) const;
};

short INGTarget::get_ingredient_type(IngInfo &info) const {
    IngredientObj *obj = info.m_obj;
    if (obj == 0) {
        return 0;
    }
    IngredientTypeInfo *ti = obj->m_typeInfo;
    if (ti == 0) {
        return 0;
    }
    return ti->m_type;
}
