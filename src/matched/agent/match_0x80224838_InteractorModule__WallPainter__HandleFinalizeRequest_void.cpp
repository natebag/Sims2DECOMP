// 0x80224838 InteractorModule::WallPainter::HandleFinalizeRequest(void) (396 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 11,0x9c(31); addi 10,31,156; lwz 0,0x4(10); mr 9,11; cmpw 11,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; stw 11,0x4(10); li 3,0; lwz 0,0x88(31); andi. 9,0,128; beq 4f; andi. 9,0,16; beq 2f; mr 3,31; bl _s80224838_0; b 4f; 2:; andi. 9,0,4; beq 3f; mr 3,31; bl _s80224838_1; b 4f; 3:; andi. 9,0,8; beq 4f; mr 3,31; bl _s80224838_2; 4:; lwz 9,0x88(31); cmpwi 3,1; rlwinm 0,9,0,28,25; stw 0,0x88(31); bne 9f; andi. 0,9,4; beq 6f; lwz 0,-31536(13); cmpwi 0,0; bne 5f; li 3,120; bl _s80224838_3; bl _s80224838_4; stw 3,-31536(13); 5:; lis 4,-32543; lwz 3,-31536(13); ori 4,4,43469; bl _s80224838_5; b 8f; 6:; lwz 0,-31536(13); cmpwi 0,0; bne 7f; li 3,120; bl _s80224838_6; bl _s80224838_7; stw 3,-31536(13); 7:; lis 4,26334; lwz 3,-31536(13); ori 4,4,56946; bl _s80224838_8; 8:; lwz 0,0x8(31); addi 9,31,8; lwz 10,0x8(9); addi 11,31,96; lwz 8,0x4(9); li 7,-4098; stw 0,0x60(31); mr 3,31; stw 10,0x8(11); li 4,0; stw 8,0x4(11); lwz 0,0x88(31); and 0,0,7; stw 0,0x88(31); bl _s80224838_9; lis 3,-32704; addi 3,3,-7384; crxor 6,6,6; bl _s80224838_10; b 11f; 9:; lwz 0,-31536(13); cmpwi 0,0; bne 10f; li 3,120; bl _s80224838_11; bl _s80224838_12; stw 3,-31536(13); 10:; lis 4,28199; lwz 3,-31536(13); ori 4,4,30903; bl _s80224838_13; 11:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80224838_0();
extern "C" void _s80224838_1();
extern "C" void _s80224838_2();
extern "C" void _s80224838_3();
extern "C" void _s80224838_4();
extern "C" void _s80224838_5();
extern "C" void _s80224838_6();
extern "C" void _s80224838_7();
extern "C" void _s80224838_8();
extern "C" void _s80224838_9();
extern "C" void _s80224838_10();
extern "C" void _s80224838_11();
extern "C" void _s80224838_12();
extern "C" void _s80224838_13();
extern "C" void f_80224838() {}
