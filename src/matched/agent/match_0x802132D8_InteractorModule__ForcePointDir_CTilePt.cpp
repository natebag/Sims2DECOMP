// 0x802132D8 InteractorModule::ForcePointDir(CTilePt (692 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 31,3; mr 28,4; mr 4,31; addi 3,1,8; bl _s802132D8_0; addi 3,1,16; mr 4,28; mr 29,3; bl _s802132D8_1; lbz 6,0x8(1); lbz 8,0x10(1); extsb 7,6; extsb 11,8; cmpw cr6,7,11; bne cr6,2f; lbz 9,0x11(1); lbz 10,0x9(1); extsb 0,9; mr 11,9; extsb 8,10; cmpw 0,8; ble 0f; mr 9,10; 0:; extsb 0,11; extsb 9,9; cmpw 0,8; bge 1f; mr 11,10; 1:; stb 9,0x9(1); addi 3,1,8; stb 11,0x11(1); mr 4,31; bl _s802132D8_2; cmpwi 3,0; beq 11f; lbz 9,0x9(1); lbz 11,0x11(1); addi 9,9,1; addi 11,11,1; stb 9,0x9(1); stb 11,0x11(1); b 11f; 2:; lbz 0,0x9(1); lbz 9,0x11(1); extsb 10,0; extsb 0,9; cmpw cr7,10,0; bne cr7,5f; cmpw 11,7; mr 0,8; ble 3f; mr 0,6; 3:; extsb 9,0; mr 0,8; bge 4f; mr 0,6; 4:; stb 9,0x8(1); addi 3,1,8; stb 0,0x10(1); mr 4,31; bl _s802132D8_3; cmpwi 3,0; beq 11f; lbz 9,0x8(1); lbz 11,0x10(1); addi 9,9,1; addi 11,11,1; stb 9,0x8(1); b 10f; 5:; subf 0,10,0; lis 6,17200; xoris 0,0,32768; stw 0,0x24(1); subf 11,7,11; mr 8,10; xoris 11,11,32768; stw 6,0x20(1); lis 9,-32704; lfd f12,-11088(9); lis 7,-32704; lfd f13,0x20(1); stw 11,0x24(1); fsub f13,f13,f12; lfs f11,-11080(7); stw 6,0x20(1); frsp f13,f13; lfd f0,0x20(1); fsub f0,f0,f12; frsp f0,f0; fdivs f13,f13,f0; fcmpu 0,f13,f11; ble 7f; ble cr6,6f; addi 30,1,24; addi 4,1,8; mr 3,30; bl _s802132D8_4; mr 4,29; addi 3,1,8; bl _s802132D8_5; mr 4,30; mr 3,29; bl _s802132D8_6; mr 3,30; li 4,2; bl _s802132D8_7; 6:; addi 3,1,8; mr 4,31; bl _s802132D8_8; cmpwi 3,0; beq 11f; lbz 9,0x9(1); lbz 10,0x8(1); lbz 8,0x11(1); addi 9,9,1; lbz 11,0x10(1); addi 10,10,1; addi 8,8,1; stb 9,0x9(1); addi 11,11,1; b 9f; 7:; ble cr7,8f; addi 30,1,24; addi 4,1,8; mr 3,30; bl _s802132D8_9; mr 4,29; addi 3,1,8; bl _s802132D8_10; mr 4,30; mr 3,29; bl _s802132D8_11; mr 3,30; li 4,2; bl _s802132D8_12; 8:; addi 3,1,8; mr 4,31; bl _s802132D8_13; cmpwi 3,0; beq 11f; lbz 9,0x9(1); lbz 10,0x8(1); lbz 8,0x11(1); addi 9,9,1; lbz 11,0x10(1); addi 10,10,-1; addi 8,8,1; stb 9,0x9(1); addi 11,11,-1; 9:; stb 10,0x8(1); stb 8,0x11(1); 10:; stb 11,0x10(1); 11:; addi 4,1,8; mr 3,31; bl _s802132D8_14; mr 4,29; mr 3,28; bl _s802132D8_15; mr 3,29; li 4,2; bl _s802132D8_16; addi 3,1,8; li 4,2; bl _s802132D8_17; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s802132D8_0();
extern "C" void _s802132D8_1();
extern "C" void _s802132D8_2();
extern "C" void _s802132D8_3();
extern "C" void _s802132D8_4();
extern "C" void _s802132D8_5();
extern "C" void _s802132D8_6();
extern "C" void _s802132D8_7();
extern "C" void _s802132D8_8();
extern "C" void _s802132D8_9();
extern "C" void _s802132D8_10();
extern "C" void _s802132D8_11();
extern "C" void _s802132D8_12();
extern "C" void _s802132D8_13();
extern "C" void _s802132D8_14();
extern "C" void _s802132D8_15();
extern "C" void _s802132D8_16();
extern "C" void _s802132D8_17();
extern "C" void f_802132D8() {}
