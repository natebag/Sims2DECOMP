// 0x801522C0 DestroyTheWorld(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,-21488(13); cmpwi 11,0; beq 0f; lwz 9,0x0(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 0,0; stw 0,-21488(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_801522C0() {}
