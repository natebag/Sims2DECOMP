// 0x801B938C find_ingredient(Ingredient (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 9,0; mr 11,3; cmplw 9,4; bge 1f; lwz 3,0x0(11); cmpwi 3,0; beq 1f; 0:; lha 0,0x0(3); cmpw 0,5; beqlr; addi 9,9,1; cmplw 9,4; bge 1f; lwzu 3,0x4(11); cmpwi 3,0; bne 0b; 1:; li 3,0"
extern "C" int f_801B938C() {}
