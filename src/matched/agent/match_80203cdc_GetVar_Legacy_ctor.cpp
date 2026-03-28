extern int GetVar_base_vtable[];
extern int GetVar_Legacy_vtable[];

int InitNameString_GetVar_Legacy(const char *name);

struct GetVar_Legacy {
    const char *m_name;
    int m_nameId;
    int *m_vtable;

    GetVar_Legacy(const char *name);
};

GetVar_Legacy::GetVar_Legacy(const char *name) {
    m_vtable = GetVar_base_vtable;
    m_name = name;
    m_nameId = InitNameString_GetVar_Legacy(name);
    m_vtable = GetVar_Legacy_vtable;
}
