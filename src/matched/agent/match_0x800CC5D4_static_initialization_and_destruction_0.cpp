// 0x800CC5D4 __static_initialization_and_destruction_0 (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 4f; cmpwi 3,0; beq 0f; li 0,0; lis 9,-32696; addi 11,9,25212; stw 0,0x627c(9); addi 10,11,8; stw 0,0x4(11); stw 0,0x4(10); b 4f; 0:; lis 9,-32696; addi 11,9,25212; lwz 9,0x627c(9); lwz 0,0x4(11); cmpw 9,0; beq 2f; 1:; addi 9,9,8; cmpw 9,0; bne 1b; 2:; lwz 3,0x0(11); cmpwi 3,0; beq 4f; lwz 0,0xc(11); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 3f; bl _s800CC5D4_0; b 4f; 3:; bl _s800CC5D4_1; 4:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s800CC5D4_0();
extern "C" void _s800CC5D4_1();
extern "C" void f_800CC5D4() {}
