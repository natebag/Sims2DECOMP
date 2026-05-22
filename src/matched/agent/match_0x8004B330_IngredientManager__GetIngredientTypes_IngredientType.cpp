// 0x8004B330 IngredientManager::GetIngredientTypes(IngredientType (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,5; mr. 30,4; beq 0f; cmpwi 31,0; bne 1f; 0:; li 3,0; b 4f; 1:; li 4,0; rlwinm 5,31,2,0,29; mr 3,30; bl _s8004B330_0; lis 9,-32697; lis 4,-32707; lwz 3,0x5ec4(9); addi 4,4,11968; bl _s8004B330_1; lwz 0,0xc(3); li 9,0; cmplw 9,0; bge 3f; cmplw 9,31; bge 3f; mr 11,3; li 10,0; mr 3,30; 2:; lwz 0,0x4(11); addi 9,9,1; add 0,0,10; stw 0,0x0(3); addi 10,10,20; addi 3,3,4; lwz 0,0xc(11); cmplw 9,0; bge 3f; cmplw 9,31; blt 2b; 3:; li 3,1; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8004B330_0();
extern "C" void _s8004B330_1();
extern "C" void f_8004B330() {}
