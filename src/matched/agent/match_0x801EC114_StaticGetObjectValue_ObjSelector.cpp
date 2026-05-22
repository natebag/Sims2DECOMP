// 0x801EC114 StaticGetObjectValue(ObjSelector (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 0,3; li 3,0; beq 0f; mr 3,0; bl _s801EC114_0; lwz 9,0x38(3); cmpwi 9,0; li 3,0; beq 0f; lha 3,0x24(9); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801EC114_0();
extern "C" void f_801EC114() {}
