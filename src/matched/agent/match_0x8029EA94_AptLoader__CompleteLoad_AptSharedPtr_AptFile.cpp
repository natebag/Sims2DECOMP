// 0x8029EA94 AptLoader::CompleteLoad(AptSharedPtr<AptFile>, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 31,6; mr 28,7; mr. 30,5; beq 2f; lwz 0,0x14(31); cmpwi 0,0; beq 0f; add 0,30,0; stw 0,0x14(31); 0:; lwz 3,0x14(31); mr 4,30; mr 5,31; mr 6,28; addi 3,3,8; bl _s8029EA94_0; lwz 0,0x14(31); li 10,3; lwz 11,0x0(29); stw 28,0x14(11); stw 0,0x10(11); stw 30,0xc(11); lwz 9,0x0(29); stw 10,0x8(9); lwz 0,0x14(31); cmpwi 0,0; beq 1f; subf 0,30,0; stw 0,0x14(31); 1:; lis 9,-32694; mr 3,31; lwz 0,-16248(9); mtspr 8,0; blrl; 2:; lwz 3,0x0(29); cmpwi 3,0; beq 3f; bl _s8029EA94_1; cmpwi 3,0; bne 3f; lwz 3,0x0(29); bl _s8029EA94_2; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8029EA94_0();
extern "C" void _s8029EA94_1();
extern "C" void _s8029EA94_2();
extern "C" void f_8029EA94() {}
