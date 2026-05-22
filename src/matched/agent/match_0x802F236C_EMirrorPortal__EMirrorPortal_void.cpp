// 0x802F236C EMirrorPortal::EMirrorPortal(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); li 0,4; mr 31,3; mtspr 9,0; 0:; bdnz 0b; li 4,4; mr 3,31; bl _s802F236C_0; lis 9,-32702; li 0,0; lfs f0,-3792(9); stw 0,0x48(31); stfs f0,0x0(31); stw 0,0x44(31); bl _s802F236C_1; li 4,320; li 5,16; li 6,0; li 7,0; bl _s802F236C_2; stw 3,0x34(31); bl _s802F236C_3; li 4,64; li 5,16; li 6,0; li 7,0; bl _s802F236C_4; stw 3,0x40(31); bl _s802F236C_5; li 4,64; li 5,16; li 6,0; li 7,0; bl _s802F236C_6; stw 3,0x3c(31); mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802F236C_0();
extern "C" void _s802F236C_1();
extern "C" void _s802F236C_2();
extern "C" void _s802F236C_3();
extern "C" void _s802F236C_4();
extern "C" void _s802F236C_5();
extern "C" void _s802F236C_6();
extern "C" void f_802F236C() {}
