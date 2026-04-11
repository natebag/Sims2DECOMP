extern int GetVar_base_vtable[];
extern int GetVar_SaveRequired_vtable[];

int InitNameString_GetVar_SaveRequired(const char *name);

struct GetVar_SaveRequired {
    const char *m_name;
    int m_nameId;
    int *m_vtable;

    GetVar_SaveRequired(const char *name);
};

GetVar_SaveRequired::GetVar_SaveRequired(const char *name) {
    m_vtable = GetVar_base_vtable;
    m_name = name;
    m_nameId = InitNameString_GetVar_SaveRequired(name);
    m_vtable = GetVar_SaveRequired_vtable;
}
