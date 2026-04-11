extern int GetVar_base_vtable[];
extern int GetVar_ImageSlotsAvail_vtable[];

int InitNameString_GetVar_ImageSlotsAvail(const char *name);

struct GetVar_ImageSlotsAvail {
    const char *m_name;
    int m_nameId;
    int *m_vtable;

    GetVar_ImageSlotsAvail(const char *name);
};

GetVar_ImageSlotsAvail::GetVar_ImageSlotsAvail(const char *name) {
    m_vtable = GetVar_base_vtable;
    m_name = name;
    m_nameId = InitNameString_GetVar_ImageSlotsAvail(name);
    m_vtable = GetVar_ImageSlotsAvail_vtable;
}
