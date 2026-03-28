extern int GetVar_base_vtable[];
extern int GetVar_EYE_exists_vtable[];

int InitNameString_GetVar_EYE_exists(const char *name);

struct GetVar_EYE_exists {
    const char *m_name;
    int m_nameId;
    int *m_vtable;

    GetVar_EYE_exists(const char *name);
};

GetVar_EYE_exists::GetVar_EYE_exists(const char *name) {
    m_vtable = GetVar_base_vtable;
    m_name = name;
    m_nameId = InitNameString_GetVar_EYE_exists(name);
    m_vtable = GetVar_EYE_exists_vtable;
}
