// 0x8003A784 FlashPiMenu::Die(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x4(31); cmpwi 0,0; beq 0f; bl _s8003A784_0; mr 3,31; bl _s8003A784_1; lwz 9,0x8(31); lis 11,-32697; addi 11,11,23428; li 4,0; rlwinm 9,9,4,0,27; add 9,9,11; lwz 3,0x100(9); bl _s8003A784_2; li 0,0; stw 0,0x4(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8003A784_0();
extern "C" void _s8003A784_1();
extern "C" void _s8003A784_2();
extern "C" void f_8003A784() {}
