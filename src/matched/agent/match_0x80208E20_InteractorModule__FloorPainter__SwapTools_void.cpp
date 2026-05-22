// 0x80208E20 InteractorModule::FloorPainter::SwapTools(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 11,3; lis 9,-32697; lwz 0,0xa4(11); addi 9,9,-32192; lwz 10,0xa0(11); addi 31,1,8; stw 9,0x8(31); addi 11,11,128; subfic 9,0,0; adde 0,9,0; stw 10,0x1c(1); li 9,4; stw 0,0x14(1); stw 9,0x8(1); mr 3,31; lis 9,-32697; lwz 0,0x8(11); addi 30,9,-32168; stw 0,0x4(31); lwz 0,0xc(11); mtspr 8,0; blrl; lwz 0,-31536(13); cmpwi 0,0; bne 0f; li 3,120; bl _s80208E20_0; bl _s80208E20_1; stw 3,-31536(13); 0:; lwz 3,-31536(13); lis 4,100; ori 4,4,44053; bl _s80208E20_2; stw 30,0x8(31); lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s80208E20_0();
extern "C" void _s80208E20_1();
extern "C" void _s80208E20_2();
extern "C" void f_80208E20() {}
