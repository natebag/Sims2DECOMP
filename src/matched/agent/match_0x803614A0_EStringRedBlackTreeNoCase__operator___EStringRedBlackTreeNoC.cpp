// 0x803614A0 EStringRedBlackTreeNoCase::operator==(EStringRedBlackTreeNoCase (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 30,0x0(3); lwz 31,0x0(4); b 4f; 0:; li 0,1; cmpwi 31,0; bne 1f; li 0,0; 1:; cmpwi 0,0; beq 2f; lwz 4,0x1c(31); addi 3,30,28; bl _s803614A0_0; cmpwi 3,0; bne 2f; lwz 9,0x18(30); lwz 0,0x18(31); cmpw 9,0; beq 3f; 2:; li 3,0; b 7f; 3:; lwz 30,0x10(30); lwz 31,0x10(31); 4:; li 0,1; cmpwi 30,0; bne 5f; li 0,0; 5:; cmpwi 0,0; bne 0b; cmpwi 31,0; li 3,1; bne 6f; li 3,0; 6:; xori 3,3,1; 7:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803614A0_0();
extern "C" void f_803614A0() {}
