// 0x8032CB70 EAudio::EAudio (20b)

extern int EAudio_vtable[];

struct EAudio {
    int* m_vt;
    EAudio();
};

EAudio::EAudio() {
    *(int**)this = EAudio_vtable;
}
