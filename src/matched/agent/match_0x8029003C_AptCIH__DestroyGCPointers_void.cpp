// 0x8029003C AptCIH::DestroyGCPointers(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 11,0x4c(31); cmpwi 11,0; beq 0f; lis 0,-17747; ori 0,0,61453; cmpw 11,0; beq 0f; lwz 9,0x14(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 11,0x48(31); cmpwi 11,0; beq 1f; lwz 9,0x8(11); lis 4,-32704; lis 5,-32704; addi 4,4,22884; lha 3,0x10(9); addi 5,5,22800; lwz 0,0x14(9); li 6,208; add 3,11,3; mtspr 8,0; blrl; 1:; li 0,0; stw 0,0x48(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_8029003C() {}
