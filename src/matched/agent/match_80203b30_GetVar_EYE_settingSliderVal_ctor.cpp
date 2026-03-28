extern int GetVar_slider_base_vtable[];
extern int GetVar_slider_derived_vtable[];

typedef void *FnPtr2;

int InitNameString_gslider(const char *name);

struct GetVar_EYE_settingSliderVal {
    const char *m_name;
    int m_nameId;
    int *m_vtable;
    FnPtr2 m_callback;

    GetVar_EYE_settingSliderVal(const char *name, FnPtr2 callback);
};

GetVar_EYE_settingSliderVal::GetVar_EYE_settingSliderVal(const char *name, FnPtr2 callback) {
    m_vtable = GetVar_slider_base_vtable;
    m_name = name;
    m_nameId = InitNameString_gslider(name);
    m_callback = callback;
    m_vtable = GetVar_slider_derived_vtable;
}
