// 0x800235E8 __static_initialization_and_destruction_0 (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 3,-32697; addi 3,3,14696; bl _s800235E8_0; lis 30,-32697; addi 30,30,18080; mr 3,30; bl _s800235E8_1; lis 9,-32698; addi 9,9,-20832; stw 9,0x28(30); b 1f; 0:; lis 3,-32697; li 4,0; addi 3,3,18080; bl _s800235E8_2; lis 3,-32697; li 4,2; addi 3,3,14696; bl _s800235E8_3; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800235E8_0();
extern "C" void _s800235E8_1();
extern "C" void _s800235E8_2();
extern "C" void _s800235E8_3();
extern "C" void f_800235E8() {}
