// 0x801C872C cTrack::Pause(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 0,0x1c(1); mr 31,4; mr 29,3; cmpwi 31,1; bne 0f; lis 9,-32697; li 30,0; addi 9,9,23428; stw 31,0x84(9); stw 30,0xf0(9); bl _s801C872C_0; lis 9,-32697; mr 3,29; addi 9,9,24012; li 4,1; stw 30,0x44c(9); stw 31,0x448(9); bl _s801C872C_1; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801C872C_0();
extern "C" void _s801C872C_1();
extern "C" void f_801C872C() {}
