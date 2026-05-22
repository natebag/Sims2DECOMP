// 0x80287D54 __static_initialization_and_destruction_0 (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 9,-32700; lhz 11,-6476(9); addi 0,9,-6476; stw 0,-22980(13); addi 11,11,1; sth 11,-6476(9); b 1f; 0:; lwz 4,-22980(13); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80287D54_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80287D54_0();
extern "C" void f_80287D54() {}
