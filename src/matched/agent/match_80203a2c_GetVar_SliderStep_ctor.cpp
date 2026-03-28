extern int GetVar_SliderStep_base_vtable[];
extern int GetVar_SliderStep_derived_vtable[];

int InitNameString2_GetVar_SliderStep(const char *name);

typedef const char * ExtraParam_GetVar_SliderStep;

struct GetVar_SliderStep {
    const char *m_name;
    int m_nameId;
    int *m_vtable;
    ExtraParam_GetVar_SliderStep m_extra;

    GetVar_SliderStep(const char *name, ExtraParam_GetVar_SliderStep extra);
};

GetVar_SliderStep::GetVar_SliderStep(const char *name, ExtraParam_GetVar_SliderStep extra) {
    m_vtable = GetVar_SliderStep_base_vtable;
    m_name = name;
    m_nameId = InitNameString2_GetVar_SliderStep(name);
    m_extra = extra;
    m_vtable = GetVar_SliderStep_derived_vtable;
}
