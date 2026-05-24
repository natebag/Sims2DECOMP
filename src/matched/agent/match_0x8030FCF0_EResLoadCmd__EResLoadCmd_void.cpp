/* FLAGS: -fno-schedule-insns */
/* 0x8030FCF0 EResLoadCmd::EResLoadCmd (52 B) */
/* mr 9,3; li 0,0; li 11,1; stw 0,0x18(9); stw 11,0x24(9); stw 0,0x0(9); stw 0,0x4(9); stw 0,0x8(9); stw 0,0xc(9); stw 0,0x10(9); stw 0,0x14(9); stw 11,0x20(9) */
/* Compiler moves last 2 src assigns to compiled front; src order derived by inversion */
struct EResLoadCmd {
    int m_f00;
    int m_f04;
    int m_f08;
    int m_f0c;
    int m_f10;
    int m_f14;
    int m_f18;
    int m_f1c;
    int m_f20;
    int m_f24;

    EResLoadCmd();
};

EResLoadCmd::EResLoadCmd() {
    m_f00 = 0;
    m_f04 = 0;
    m_f08 = 0;
    m_f0c = 0;
    m_f10 = 0;
    m_f14 = 0;
    m_f20 = 1;
    m_f18 = 0;
    m_f24 = 1;
}
