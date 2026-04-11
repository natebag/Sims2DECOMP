extern int SetVar_base_vtable[];
extern int SetVar_EYE_filterCurrSel_vtable[];

int InitNameString_SetVar_EYE_filterCurrSel(const char *name);

struct SetVar_EYE_filterCurrSel {
    const char *m_name;
    int m_nameId;
    int *m_vtable;

    SetVar_EYE_filterCurrSel(const char *name);
};

SetVar_EYE_filterCurrSel::SetVar_EYE_filterCurrSel(const char *name) {
    m_vtable = SetVar_base_vtable;
    m_name = name;
    m_nameId = InitNameString_SetVar_EYE_filterCurrSel(name);
    m_vtable = SetVar_EYE_filterCurrSel_vtable;
}
