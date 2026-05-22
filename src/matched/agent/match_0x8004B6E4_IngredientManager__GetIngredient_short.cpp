// 0x8004B6E4 IngredientManager::GetIngredient(short) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; lis 9,-32697; lis 4,-32707; lwz 3,0x5ec4(9); addi 4,4,11984; bl _s8004B6E4_0; lwz 0,0xc(3); li 9,0; cmplw 9,0; bge 1f; lwz 3,0x4(3); mr 11,0; 0:; lha 0,0x0(3); cmpw 0,31; beq 2f; addi 9,9,1; addi 3,3,80; cmplw 9,11; blt 0b; 1:; li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8004B6E4_0();
extern "C" void f_8004B6E4() {}
