extern int SetVar_base_vtable[];
extern int SetVar_EYE_topLevelCurrSel_vtable[];

int InitNameString_SetVar_EYE_topLevelCurrSel(const char *name);

struct SetVar_EYE_topLevelCurrSel {
    const char *m_name;
    int m_nameId;
    int *m_vtable;

    SetVar_EYE_topLevelCurrSel(const char *name);
};

SetVar_EYE_topLevelCurrSel::SetVar_EYE_topLevelCurrSel(const char *name) {
    m_vtable = SetVar_base_vtable;
    m_name = name;
    m_nameId = InitNameString_SetVar_EYE_topLevelCurrSel(name);
    m_vtable = SetVar_EYE_topLevelCurrSel_vtable;
}
