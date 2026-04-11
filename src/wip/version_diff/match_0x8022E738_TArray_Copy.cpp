
extern char g_setupModelString[];

void SetupModel_Init(void *);
void* SetupModel_CreateResource(char *, void *, int, int);
void SetupModel_Finalize(void *);

struct SetupModelObj {
    char _pad[0x90];
    void* m_field_090;
    char _pad2[0x0C];
    void* m_field_0A0;

    void SetupModel(void);
};

void SetupModelObj::SetupModel(void) {
    SetupModel_Init(this);
    m_field_0A0 = SetupModel_CreateResource(g_setupModelString, m_field_090, 0, 0);
    SetupModel_Finalize(this);
}
