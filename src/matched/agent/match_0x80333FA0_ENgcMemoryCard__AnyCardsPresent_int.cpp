// 0x80333FA0 ENgcMemoryCard::AnyCardsPresent(int (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; li 0,-1; stw 0,0x0(30); mr 31,3; li 4,1; lwz 9,0x0(31); lha 3,0xa0(9); lwz 0,0xa4(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; li 0,1; stw 0,0x0(30); 0:; lwz 9,0x0(31); li 4,0; lha 3,0xa0(9); lwz 0,0xa4(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; li 0,0; stw 0,0x0(30); 1:; lwz 0,0x0(30); li 3,1; cmpwi 0,-1; bne 2f; li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_80333FA0() {}
