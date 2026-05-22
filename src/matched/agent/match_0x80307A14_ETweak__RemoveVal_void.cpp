// 0x80307A14 ETweak::RemoveVal(void (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 11,4; lwz 4,0xc(30); cmpwi 4,0; beq 3f; 0:; lwz 31,0x0(4); lwz 9,0x8(4); lwz 0,0x0(31); cmpw 0,11; bne 2f; addi 3,30,12; bl _s80307A14_0; cmpwi 31,0; beq 1f; mr 3,31; lwzu 4,0x4(3); bl _s80307A14_1; mr 3,31; bl _s80307A14_2; 1:; lwz 9,0x8(30); addi 9,9,-1; stw 9,0x8(30); b 3f; 2:; mr. 4,9; bne 0b; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80307A14_0();
extern "C" void _s80307A14_1();
extern "C" void _s80307A14_2();
extern "C" void f_80307A14() {}
