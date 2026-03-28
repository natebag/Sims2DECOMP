extern int GetVar_base_vtable[];
extern int GetVar_EYE_connectionStatus_vtable[];

int InitNameString_GetVar_EYE_connectionStatus(const char *name);

struct GetVar_EYE_connectionStatus {
    const char *m_name;
    int m_nameId;
    int *m_vtable;

    GetVar_EYE_connectionStatus(const char *name);
};

GetVar_EYE_connectionStatus::GetVar_EYE_connectionStatus(const char *name) {
    m_vtable = GetVar_base_vtable;
    m_name = name;
    m_nameId = InitNameString_GetVar_EYE_connectionStatus(name);
    m_vtable = GetVar_EYE_connectionStatus_vtable;
}
