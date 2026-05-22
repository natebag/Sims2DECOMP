// 0x8004B29C IngredientManager::IngredientManager(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; addi 31,9,24012; lwz 3,0xf8(31); cmpwi 3,0; beq 0f; lis 4,-32707; addi 4,4,11968; bl _s8004B29C_0; lis 4,-32707; lwz 3,0xf8(31); addi 4,4,11984; bl _s8004B29C_1; lis 4,-32707; lwz 3,0xf8(31); addi 4,4,11996; bl _s8004B29C_2; 0:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8004B29C_0();
extern "C" void _s8004B29C_1();
extern "C" void _s8004B29C_2();
extern "C" void f_8004B29C() {}
