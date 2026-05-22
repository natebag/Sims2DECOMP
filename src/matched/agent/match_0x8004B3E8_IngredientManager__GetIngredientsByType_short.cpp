// 0x8004B3E8 IngredientManager::GetIngredientsByType(short, (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 31,6; mr. 30,5; beq 0f; cmpwi 31,0; bne 1f; 0:; li 3,0; b 5f; 1:; li 4,0; rlwinm 5,31,2,0,29; mr 3,30; bl _s8004B3E8_0; lis 9,-32697; lis 4,-32707; lwz 3,0x5ec4(9); addi 4,4,11984; bl _s8004B3E8_1; mr 7,3; li 8,0; lwz 0,0xc(7); li 6,0; cmplw 8,0; bge 4f; cmplw 8,31; bge 4f; lwz 11,0x4(7); cmpwi 11,0; beq 4f; mr 3,30; mr 5,7; li 10,0; 2:; lwz 9,0x4(11); lha 0,0x0(9); cmpw 0,29; bne 3f; stw 11,0x0(3); addi 8,8,1; addi 3,3,4; 3:; lwz 0,0xc(5); addi 6,6,1; addi 10,10,80; cmplw 6,0; bge 4f; cmplw 8,31; bge 4f; lwz 0,0x4(7); add. 11,0,10; bne 2b; 4:; li 3,1; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8004B3E8_0();
extern "C" void _s8004B3E8_1();
extern "C" void f_8004B3E8() {}
