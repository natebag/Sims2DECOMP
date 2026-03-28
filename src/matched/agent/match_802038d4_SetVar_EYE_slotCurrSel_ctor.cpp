extern int SetVar_base_vtable[];
extern int SetVar_EYE_slotCurrSel_vtable[];

int InitNameString_SetVar_EYE_slotCurrSel(const char *name);

struct SetVar_EYE_slotCurrSel {
    const char *m_name;
    int m_nameId;
    int *m_vtable;

    SetVar_EYE_slotCurrSel(const char *name);
};

SetVar_EYE_slotCurrSel::SetVar_EYE_slotCurrSel(const char *name) {
    m_vtable = SetVar_base_vtable;
    m_name = name;
    m_nameId = InitNameString_SetVar_EYE_slotCurrSel(name);
    m_vtable = SetVar_EYE_slotCurrSel_vtable;
}
