// 0x80207278 InteractorModule::FloorPainter::HandleActionCmdInPlaceMode(void) (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; lbz 0,0x60(31); rlwinm 9,0,0,24,31; cmpwi 9,0; bne 1f; ori 0,0,5; lwz 7,0x20(31); stb 0,0x60(31); addi 9,31,32; addi 10,31,100; lwz 0,-31536(13); lwz 11,0x8(9); lwz 8,0x4(9); cmpwi 0,0; stw 7,0x64(31); stw 11,0x8(10); stw 8,0x4(10); bne 0f; li 3,120; bl _s80207278_0; bl _s80207278_1; stw 3,-31536(13); 0:; lis 4,14155; lwz 3,-31536(13); ori 4,4,56554; bl _s80207278_2; b 10f; 1:; andi. 11,9,2; beq 3f; rlwinm 28,9,27,31,31; cmpwi 28,0; bne 4f; ori 0,0,16; lis 11,-32697; stb 0,0x60(31); li 30,0; lwz 9,0x5ea0(11); lwz 9,0x0(9); cmpwi 9,0; beq 2f; lwz 30,-4(9); 2:; lwz 3,0xb8(31); li 4,0; rlwinm 5,30,2,0,29; bl _s80207278_3; lwz 4,0xb8(31); mr 3,31; bl _s80207278_4; b 8f; 3:; andi. 11,9,1; beq 10f; rlwinm 28,9,27,31,31; cmpwi 28,0; beq 6f; 4:; lwz 0,-31536(13); cmpwi 0,0; bne 5f; li 3,120; bl _s80207278_5; bl _s80207278_6; stw 3,-31536(13); 5:; lis 4,28199; lwz 3,-31536(13); ori 4,4,30903; bl _s80207278_7; b 10f; 6:; ori 0,0,16; lis 11,-32697; stb 0,0x60(31); li 30,0; lwz 9,0x5ea0(11); lwz 9,0x0(9); cmpwi 9,0; beq 7f; lwz 30,-4(9); 7:; lwz 3,0xb8(31); li 4,0; rlwinm 5,30,2,0,29; bl _s80207278_8; lwz 4,0xb8(31); mr 3,31; bl _s80207278_9; 8:; mr. 29,3; ble 9f; lwz 4,0xb8(31); mr 3,31; mr 5,30; bl _s80207278_10; mr 3,31; mr 4,29; bl _s80207278_11; 9:; lwz 0,0x7c(31); stb 28,0x60(31); subf 0,29,0; stw 0,0x7c(31); 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80207278_0();
extern "C" void _s80207278_1();
extern "C" void _s80207278_2();
extern "C" void _s80207278_3();
extern "C" void _s80207278_4();
extern "C" void _s80207278_5();
extern "C" void _s80207278_6();
extern "C" void _s80207278_7();
extern "C" void _s80207278_8();
extern "C" void _s80207278_9();
extern "C" void _s80207278_10();
extern "C" void _s80207278_11();
extern "C" void f_80207278() {}
