extern int GetVar_base_vtable[];
extern int GetVar_EYE_targetState_vtable[];

int InitNameString_GetVar_EYE_targetState(const char *name);

struct GetVar_EYE_targetState {
    const char *m_name;
    int m_nameId;
    int *m_vtable;

    GetVar_EYE_targetState(const char *name);
};

GetVar_EYE_targetState::GetVar_EYE_targetState(const char *name) {
    m_vtable = GetVar_base_vtable;
    m_name = name;
    m_nameId = InitNameString_GetVar_EYE_targetState(name);
    m_vtable = GetVar_EYE_targetState_vtable;
}
