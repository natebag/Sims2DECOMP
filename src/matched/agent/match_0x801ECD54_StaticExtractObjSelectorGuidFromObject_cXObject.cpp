// 0x801ECD54 StaticExtractObjSelectorGuidFromObject(cXObject (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 11,3; bne 0f; li 3,0; b 2f; 0:; lwz 9,0x4(11); lha 3,0x368(9); lwz 0,0x36c(9); add 3,11,3; mtspr 8,0; blrl; mr. 31,3; li 3,0; beq 2f; mr 3,31; bl _s801ECD54_0; mr. 3,3; bne 1f; mr 3,31; 1:; bl _s801ECD54_1; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801ECD54_0();
extern "C" void _s801ECD54_1();
extern "C" void f_801ECD54() {}
