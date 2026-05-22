// 0x802249C4 InteractorModule::WallPainter::HandleSwapRequest(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 0,0; lis 3,-32704; stw 0,0x88(31); addi 3,3,-7352; crxor 6,6,6; bl _s802249C4_0; lwz 0,-31536(13); cmpwi 0,0; bne 0f; li 3,120; bl _s802249C4_1; bl _s802249C4_2; stw 3,-31536(13); 0:; lwz 3,-31536(13); lis 4,100; ori 4,4,44053; bl _s802249C4_3; mr 3,31; li 4,4; bl _s802249C4_4; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802249C4_0();
extern "C" void _s802249C4_1();
extern "C" void _s802249C4_2();
extern "C" void _s802249C4_3();
extern "C" void _s802249C4_4();
extern "C" void f_802249C4() {}
