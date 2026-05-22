// 0x800CA424 Neighbor::AdjustRelationship(Neighbor (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,5; mr. 4,4; beq 1f; lwz 3,0x10(30); lha 31,0x4(4); lwz 9,0x0(3); mr 4,31; lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 3,0x10(30); mr 4,31; li 5,1; lwz 9,0x0(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 3,0x10(30); mr 4,31; mr 6,29; li 5,0; lwz 9,0x0(3); lha 0,0x48(9); lwz 9,0x4c(9); add 3,3,0; mtspr 8,9; blrl; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_800CA424() {}
