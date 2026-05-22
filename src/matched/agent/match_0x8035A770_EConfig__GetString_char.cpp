// 0x8035A770 EConfig::GetString(char (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,5; addi 3,3,20; addi 5,1,8; bl _s8035A770_0; cmpwi 3,0; bne 0f; mr 3,30; b 1f; 0:; lwz 9,0x8(1); li 4,61; li 5,0; lwz 30,0x0(9); mr 3,30; bl _s8035A770_1; lwz 0,0x0(30); addi 3,3,1; add 3,0,3; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8035A770_0();
extern "C" void _s8035A770_1();
extern "C" void f_8035A770() {}
