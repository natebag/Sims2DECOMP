// 0x80087110 TextBaseItem::CalculateSize(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 9,0x1c(31); addi 3,31,32; lwz 11,0x38(3); lha 0,0x68(9); addi 29,9,104; andis. 9,11,4096; add 30,31,0; beq 0f; bl _s80087110_0; 0:; lwz 0,0x4(29); mr 3,30; addi 4,31,60; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80087110_0();
extern "C" void f_80087110() {}
