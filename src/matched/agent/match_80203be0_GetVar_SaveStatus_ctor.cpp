extern int GetVar_base_vtable[];
extern int GetVar_SaveStatus_vtable[];

int InitNameString_GetVar_SaveStatus(const char *name);

struct GetVar_SaveStatus {
    const char *m_name;
    int m_nameId;
    int *m_vtable;

    GetVar_SaveStatus(const char *name);
};

GetVar_SaveStatus::GetVar_SaveStatus(const char *name) {
    m_vtable = GetVar_base_vtable;
    m_name = name;
    m_nameId = InitNameString_GetVar_SaveStatus(name);
    m_vtable = GetVar_SaveStatus_vtable;
}
