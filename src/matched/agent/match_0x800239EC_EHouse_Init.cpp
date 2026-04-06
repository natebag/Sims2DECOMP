// 0x800239EC EHouse::Init (52b)

extern void EHouse_Init_sub(void*);

struct EHouse {
    char pad[0x14];
    int m_inited;
};

void EHouse_Init(EHouse* self) {
    EHouse_Init_sub(self);
    self->m_inited = 1;
}
