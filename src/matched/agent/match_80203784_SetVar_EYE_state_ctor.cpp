extern int SetVar_base_vtable[];
extern int SetVar_EYE_state_vtable[];

int InitNameString(const char *name);

struct SetVar_EYE_state {
    const char *m_name;
    int m_nameId;
    int *m_vtable;

    SetVar_EYE_state(const char *name);
};

SetVar_EYE_state::SetVar_EYE_state(const char *name) {
    m_vtable = SetVar_base_vtable;
    m_name = name;
    m_nameId = InitNameString(name);
    m_vtable = SetVar_EYE_state_vtable;
}
