// 0x80214F94 InteractorModule::InteractorVisualizer::Draw(InteractorModule::WallPainter (644 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 25,0x5c(1); stw 0,0x7c(1); mr 28,3; mr 31,4; bl _s80214F94_0; mr. 25,3; beq 12f; addi 3,1,8; addi 29,31,108; bl _s80214F94_1; addi 30,31,32; addi 3,1,8; mr 4,29; bl _s80214F94_2; mr 27,30; lwz 3,0x0(31); lis 9,-32697; addi 26,9,23428; rlwinm 3,3,4,0,27; addi 3,3,244; add 3,3,26; bl _s80214F94_3; mr 6,3; lis 5,-10799; mr 4,31; ori 5,5,32328; addi 7,1,8; mr 3,28; bl _s80214F94_4; addi 3,1,8; bl _s80214F94_5; addi 3,1,8; mr 4,30; bl _s80214F94_6; lwz 0,0x88(31); mr 9,29; andi. 11,0,16; beq 2f; mr 3,28; mr 4,31; bl _s80214F94_7; lwz 0,0x88(31); andi. 9,0,128; beq 0f; lis 9,-32696; addi 9,9,32272; b 1f; 0:; lis 9,-32696; addi 9,9,32284; 1:; lfs f0,0x0(9); lis 5,-16025; mr 3,28; mr 4,31; stfs f0,0x48(1); ori 5,5,50249; addi 6,1,72; addi 7,1,8; lfs f0,0x4(9); stfs f0,0x4c(1); lfs f13,0x8(9); stfs f13,0x50(1); bl _s80214F94_8; b 12f; 2:; andi. 11,0,1; li 0,0; beq 3f; li 0,1; 3:; cmpwi 0,0; beq 11f; lfs f13,0x20(31); li 29,0; lfs f0,0x60(31); addi 30,31,96; fmr f10,f13; fcmpu 0,f13,f0; bne 4f; lfs f13,0x4(27); lfs f0,0x4(30); fcmpu 0,f13,f0; bne 4f; lfs f13,0x8(27); lfs f0,0x8(30); fcmpu 0,f13,f0; beq 5f; 4:; li 29,1; 5:; cmpwi 29,0; beq 6f; lfs f11,0x8(9); lfs f0,0x6c(31); lfs f1,0x4(27); lfs f12,0x4(9); fsubs f0,f10,f0; lfs f13,0x8(27); fmr f2,f0; fsubs f1,f1,f12; stfs f0,0x48(1); fsubs f13,f13,f11; stfs f1,0x4c(1); stfs f13,0x50(1); bl _s80214F94_9; lfs f0,0x84(31); addi 3,1,8; fadds f1,f1,f0; bl _s80214F94_10; 6:; lwz 0,0x88(31); andi. 9,0,128; beq 8f; cmpwi 29,1; bne 7f; mr 3,28; mr 4,31; bl _s80214F94_11; 7:; lis 5,26001; lis 6,-32696; mr 3,28; mr 4,31; addi 6,6,32272; b 10f; 8:; lis 4,-5607; mr 3,25; ori 4,4,1515; bl _s80214F94_12; mr. 3,3; beq 9f; lis 9,-32704; mr 4,3; lfs f1,-21084(13); mr 5,30; lfs f2,-10464(9); mr 6,27; mr 3,28; li 7,0; bl _s80214F94_13; 9:; lis 5,26001; lis 6,-32696; mr 3,28; mr 4,31; addi 6,6,32284; 10:; ori 5,5,43216; addi 7,1,8; bl _s80214F94_14; b 12f; 11:; lwz 3,0x0(31); rlwinm 3,3,4,0,27; addi 3,3,244; add 3,3,26; bl _s80214F94_15; mr 6,3; lis 5,-16025; mr 3,28; mr 4,31; ori 5,5,50249; addi 7,1,8; bl _s80214F94_16; 12:; lwz 0,0x7c(1); mtspr 8,0; lmw 25,0x5c(1); addi 1,1,120"
extern "C" void _s80214F94_0();
extern "C" void _s80214F94_1();
extern "C" void _s80214F94_2();
extern "C" void _s80214F94_3();
extern "C" void _s80214F94_4();
extern "C" void _s80214F94_5();
extern "C" void _s80214F94_6();
extern "C" void _s80214F94_7();
extern "C" void _s80214F94_8();
extern "C" void _s80214F94_9();
extern "C" void _s80214F94_10();
extern "C" void _s80214F94_11();
extern "C" void _s80214F94_12();
extern "C" void _s80214F94_13();
extern "C" void _s80214F94_14();
extern "C" void _s80214F94_15();
extern "C" void _s80214F94_16();
extern "C" void f_80214F94() {}
