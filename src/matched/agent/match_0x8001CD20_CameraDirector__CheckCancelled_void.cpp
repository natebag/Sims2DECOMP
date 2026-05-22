// 0x8001CD20 CameraDirector::CheckCancelled(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x238(31); cmpwi 0,1; bne 2f; lwz 0,0x240(31); xori 0,0,1; andi. 9,0,1; beq 2f; lwz 9,0x170(31); li 30,0; lwz 3,-26524(13); lwz 4,0x4(9); bl _s8001CD20_0; cmpwi 3,0; beq 0f; lwz 9,0x170(31); lwz 30,-26524(13); lwz 4,0x4(9); mr 3,30; bl _s8001CD20_1; mr 4,3; mr 3,30; bl _s8001CD20_2; mr 30,3; 0:; cmpwi 30,0; beq 2f; lis 29,-32707; lwz 5,0x244(31); lfs f1,-6776(29); mr 3,30; li 4,0; bl _s8001CD20_3; cmpwi 3,0; bne 1f; lfs f1,-6776(29); mr 3,30; lwz 5,0x244(31); li 4,1; bl _s8001CD20_4; cmpwi 3,0; beq 2f; 1:; li 3,1; b 3f; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8001CD20_0();
extern "C" void _s8001CD20_1();
extern "C" void _s8001CD20_2();
extern "C" void _s8001CD20_3();
extern "C" void _s8001CD20_4();
extern "C" void f_8001CD20() {}
