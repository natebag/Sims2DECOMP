// 0x8001ECF4 ECheats::~ECheats(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 28,4; li 27,0; bl _s8001ECF4_0; mr 3,30; bl _s8001ECF4_1; li 9,0; 0:; rlwinm 0,9,2,0,29; addi 29,9,1; lwzx 31,30,0; cmpwi 31,0; beq 2f; stwx 27,30,0; 1:; mr 3,31; lwz 31,0x0(31); bl _s8001ECF4_2; cmpwi 31,0; bne 1b; 2:; mr 9,29; cmpwi 9,63; ble 0b; andi. 0,28,1; beq 3f; mr 3,30; bl _s8001ECF4_3; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8001ECF4_0();
extern "C" void _s8001ECF4_1();
extern "C" void _s8001ECF4_2();
extern "C" void _s8001ECF4_3();
extern "C" void f_8001ECF4() {}
