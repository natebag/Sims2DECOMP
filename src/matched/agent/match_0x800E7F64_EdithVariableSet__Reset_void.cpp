// 0x800E7F64 EdithVariableSet::Reset(void) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 30,3; li 4,72; bl _s800E7F64_0; addi 0,30,12; li 9,0; stw 0,0xc(1); stw 3,0x10(1); stw 9,0x14(1); stw 30,0x8(1); addi 31,1,8; addi 29,1,24; b 2f; 0:; lwz 10,0x4(31); lwz 9,0xc(31); lwz 11,0x0(10); add 9,9,9; sthx 7,11,9; lwz 3,0x8(1); lwz 4,0x8(31); bl _s800E7F64_1; cmpwi 3,72; stw 3,0x8(31); beq 1f; lwz 9,0xc(31); addi 9,9,1; stw 9,0xc(31); b 2f; 1:; lwz 9,0x4(31); lwz 11,0x0(9); lwz 0,0x4(9); subf 0,11,0; srawi 0,0,1; stw 0,0xc(31); 2:; addi 9,30,12; li 10,72; lwz 11,0x4(9); li 7,0; stw 9,0x1c(1); li 5,72; stw 30,0x18(1); li 8,0; stw 10,0x8(29); lwz 0,0xc(30); lwz 10,0x8(1); subf 11,0,11; lwz 9,0x18(1); srawi 11,11,1; cmpw 10,9; stw 11,0x24(1); bne 3f; lwz 9,0x8(31); lwz 0,0x20(1); cmpw 9,0; beq 4f; 3:; li 8,1; 4:; cmpwi 8,0; bne 0b; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s800E7F64_0();
extern "C" void _s800E7F64_1();
extern "C" void f_800E7F64() {}
