// 0x801D1A10 FindSelectorContainingResData(ObjSelector (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x50(3); li 30,0; bl _s801D1A10_0; mr. 3,3; beq 2f; 0:; lwz 9,0x38(3); cmpwi 9,0; beq 1f; lwz 0,0xc0(9); cmpwi 0,0; bne 3f; 1:; lwz 9,0x0(31); mr 4,3; mr 5,30; lha 3,0xa8(9); addi 30,30,1; lwz 0,0xac(9); add 3,31,3; mtspr 8,0; blrl; mr. 3,3; bne 0b; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801D1A10_0();
extern "C" void f_801D1A10() {}
