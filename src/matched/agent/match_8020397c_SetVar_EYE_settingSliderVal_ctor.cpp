extern int SetVar_slider_base_vtable[];
extern int SetVar_slider_derived_vtable[];

typedef void *FnPtr;

int InitNameString_slider(const char *name);

struct SetVar_EYE_settingSliderVal {
    const char *m_name;
    int m_nameId;
    int *m_vtable;
    FnPtr m_callback;

    SetVar_EYE_settingSliderVal(const char *name, FnPtr callback);
};

SetVar_EYE_settingSliderVal::SetVar_EYE_settingSliderVal(const char *name, FnPtr callback) {
    m_vtable = SetVar_slider_base_vtable;
    m_name = name;
    m_nameId = InitNameString_slider(name);
    m_callback = callback;
    m_vtable = SetVar_slider_derived_vtable;
}
