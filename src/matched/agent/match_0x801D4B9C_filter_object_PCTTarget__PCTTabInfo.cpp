// 0x801D4B9C filter_object(PCTTarget::PCTTabInfo (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr. 31,4; li 3,0; beq 4f; mr 3,31; bl _s801D4B9C_0; cmpwi 3,0; li 3,0; bne 4f; lwz 3,0x38(31); cmpwi 3,0; beq 0f; lha 9,0x8a(3); cmpwi 9,0; bne 2f; lhz 0,0x50(3); mr 3,0; cmpwi 0,0; bne 1f; lis 9,-32697; lwz 0,0x618c(9); cmpwi 0,0; beq 0f; lha 0,0x6(30); cmpwi 0,64; beq 1f; 0:; li 3,0; b 4f; 1:; lhz 0,0x6(30); and. 9,0,3; bne 3f; b 0b; 2:; lha 0,0x4(30); li 3,0; cmpw 9,0; bne 4f; 3:; li 3,1; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801D4B9C_0();
extern "C" void f_801D4B9C() {}
