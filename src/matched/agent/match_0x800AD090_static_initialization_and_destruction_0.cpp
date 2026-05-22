// 0x800AD090 __static_initialization_and_destruction_0 (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 2f; cmpwi 3,0; beq 0f; li 0,0; lis 9,-32696; addi 11,9,24016; stw 0,0x5dd0(9); addi 10,11,8; stw 0,0x4(11); stw 0,0x4(10); b 2f; 0:; lis 9,-32696; lwz 3,0x5dd0(9); addi 9,9,24016; cmpwi 3,0; beq 2f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 1f; bl _s800AD090_0; b 2f; 1:; bl _s800AD090_1; 2:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s800AD090_0();
extern "C" void _s800AD090_1();
extern "C" void f_800AD090() {}
