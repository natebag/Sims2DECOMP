// FLAGS: -fno-schedule-insns
// 0x80075B10 SkinCompositor::SkinCompositor (96b)
void sc_reset(void*);

struct SC_Ctor {
    short m_field0;      // 0x00
    short m_pad02;       // 0x02
    int m_field04;       // 0x04
    int m_field08;       // 0x08
    int m_field0C;       // 0x0C
    int m_field10;       // 0x10
    int m_field14;       // 0x14
    int m_field18;       // 0x18
    char m_field1C;      // 0x1C
    char m_pad1D[3];
    int m_field20;       // 0x20
    int m_field24;       // 0x24
};

void* SC_ctor(SC_Ctor* self) {
    self->m_field24 = 0;
    self->m_field0 = 256;
    self->m_field04 = 0;
    self->m_field08 = 0;
    self->m_field0C = 0;
    self->m_field10 = 0;
    self->m_field14 = 0;
    self->m_field18 = 0;
    self->m_field1C = 0;
    self->m_field20 = 0;
    sc_reset(self);
    return self;
}
