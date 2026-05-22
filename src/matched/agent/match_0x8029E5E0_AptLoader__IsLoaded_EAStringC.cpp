// 0x8029E5E0 AptLoader::IsLoaded(EAStringC (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; addi 3,1,8; bl _s8029E5E0_0; lwz 3,0x8(1); li 0,1; cmpwi 7,3,0; bne cr7,0f; li 0,0; 0:; cmpwi 0,0; beq 3f; lwz 0,0x8(3); cmpwi 0,4; beq 1f; cmpwi 0,5; bne 3f; 1:; stw 3,0x0(31); beq cr7,2f; bl _s8029E5E0_1; 2:; lwz 3,0x8(1); cmpwi 3,0; beq 4f; bl _s8029E5E0_2; cmpwi 3,0; bne 4f; lwz 3,0x8(1); bl _s8029E5E0_3; b 4f; 3:; lwz 3,0x8(1); li 0,0; stw 0,0x0(31); cmpwi 3,0; beq 4f; bl _s8029E5E0_4; cmpwi 3,0; bne 4f; lwz 3,0x8(1); bl _s8029E5E0_5; 4:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s8029E5E0_0();
extern "C" void _s8029E5E0_1();
extern "C" void _s8029E5E0_2();
extern "C" void _s8029E5E0_3();
extern "C" void _s8029E5E0_4();
extern "C" void _s8029E5E0_5();
extern "C" void f_8029E5E0() {}
