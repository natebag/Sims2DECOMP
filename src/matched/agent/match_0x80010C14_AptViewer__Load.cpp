/* AptViewer::Load(char *, bool) at 0x80010C14 (128B) */

void AptAuxPCEorGL_LoadFile(char*);
void AptAuxPCEorGL_LoadAnimation(char*);
void EString_assign(void*, char*);
void AptAuxPCEorGL_Tick(void);

struct AptViewer {
    char pad_00[0x350];
    int m_loaded;
    char pad_354[0x2C];
    char m_name[0x100];

    void Load(char* name, int anim);
    void Unload(void);
};

void AptViewer::Load(char* name, int anim) {
    if (name == 0) return;
    if (*(char*)name == 0) return;
    if (m_loaded != 0) {
        Unload();
    }
    AptAuxPCEorGL_LoadFile(name);
    if (anim != 0) {
        AptAuxPCEorGL_LoadAnimation(name);
    }
    EString_assign(&m_name, name);
    m_loaded = 1;
    AptAuxPCEorGL_Tick();
}
