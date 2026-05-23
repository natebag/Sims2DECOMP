/* INGTarget::get_ingredient_type(INGTarget::IngInfo &) const at 0x801BBCCC (44B) */

struct IngInfo_GIT {
    void* m_data;
};

struct IngData_GIT {
    void* m_pad;
    void* m_typePtr;
};

struct INGTarget_GIT {
    int get_ingredient_type(IngInfo_GIT& info) const;
};

int INGTarget_GIT::get_ingredient_type(IngInfo_GIT& info) const {
    IngData_GIT* data = (IngData_GIT*)info.m_data;
    if (!data) return 0;
    void* t = data->m_typePtr;
    if (!t) return 0;
    return *(short*)t;
}
