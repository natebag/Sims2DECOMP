// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// 0x8003E538 EGlobal::SetAuthorModeCheats(void) (40B)
struct EGlobal {
    char pad[956];
    int m_f956;    // 956
    int m_f960;    // 960
    char pad2[4];
    int m_f968;    // 968
    char pad3[16];
    int m_f988;    // 988
    char pad4[4];
    int m_f996;    // 996
    int m_f1000;   // 1000
    char pad5[4];
    int m_f1008;   // 1008
    char pad6[16];
    int m_f1028;   // 1028
};

void EGlobal__SetAuthorModeCheats(EGlobal* self) {
    self->m_f996 = 1;
    self->m_f956 = 1;
    self->m_f960 = 1;
    self->m_f968 = 1;
    self->m_f988 = 1;
    self->m_f1000 = 1;
    self->m_f1008 = 1;
    self->m_f1028 = 1;
}
