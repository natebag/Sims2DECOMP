// 0x8016A460 CasSimDescriptionS2C::ShouldBootTopBeDisplayed(CasSimPartsS2C (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; mr 30,4; lwz 29,0xd0(31); li 3,1; stw 3,0xd0(31); li 5,17; addi 3,1,8; mr 4,31; bl _s8016A460_0; lbz 5,0xcc(31); mr 3,30; li 4,17; addi 6,1,8; extsb 5,5; bl _s8016A460_1; cmpwi 3,0; beq 0f; lwz 0,0xc8(31); li 3,0; cmpwi 0,0; beq 1f; li 3,1; b 1f; 0:; li 3,0; 1:; stw 29,0xd0(31); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8016A460_0();
extern "C" void _s8016A460_1();
extern "C" void f_8016A460() {}
