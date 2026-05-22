// 0x800CA388 Neighbor::GetRelationshipById(int, (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 3,0x10(30); mr 31,5; lwz 9,0x0(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; bne 1f; cmpwi 31,0; beq 0f; stw 3,0x0(31); 0:; li 3,0; b 3f; 1:; cmpwi 31,0; beq 2f; lwz 3,0x10(30); mr 4,29; li 5,0; lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; stw 3,0x0(31); 2:; li 3,1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_800CA388() {}
