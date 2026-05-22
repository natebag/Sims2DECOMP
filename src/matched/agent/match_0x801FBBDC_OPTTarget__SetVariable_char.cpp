// 0x801FBBDC OPTTarget::SetVariable(char (832 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 29,3; mr 31,4; lis 3,-32704; mr 30,5; addi 3,3,-21224; bl _s801FBBDC_0; cmpwi 3,0; bne 0f; mr 3,30; bl _s801FBBDC_1; lis 9,-32704; lis 11,-32704; lfs f12,-20864(9); lfs f13,-20860(11); lwz 3,-21492(13); fmadds f1,f1,f12,f13; fctiwz f0,f1; stfd f0,0x8(1); lwz 4,0xc(1); bl _s801FBBDC_2; b 18f; 0:; lis 3,-32704; mr 4,31; addi 3,3,-21196; bl _s801FBBDC_3; cmpwi 3,0; bne 1f; mr 3,30; bl _s801FBBDC_4; lis 9,-32704; lis 11,-32704; lfs f12,-20864(9); lfs f13,-20860(11); lwz 3,-21492(13); fmadds f1,f1,f12,f13; fctiwz f0,f1; stfd f0,0x8(1); lwz 4,0xc(1); bl _s801FBBDC_5; b 18f; 1:; lis 3,-32704; mr 4,31; addi 3,3,-21164; bl _s801FBBDC_6; cmpwi 3,0; bne 2f; mr 3,30; bl _s801FBBDC_7; mr 3,29; bl _s801FBBDC_8; lis 9,-32697; addi 9,9,24012; lwz 11,0x148(9); stb 3,0x1f(11); b 3f; 2:; lis 3,-32704; mr 4,31; addi 3,3,-21128; bl _s801FBBDC_9; cmpwi 3,0; bne 4f; mr 3,30; bl _s801FBBDC_10; mr 3,29; bl _s801FBBDC_11; lis 9,-32697; addi 9,9,24012; lwz 11,0x148(9); stb 3,0x20(11); 3:; mr 3,9; bl _s801FBBDC_12; b 18f; 4:; lis 3,-32704; mr 4,31; addi 3,3,-21092; bl _s801FBBDC_13; cmpwi 3,0; bne 8f; mr 3,30; bl _s801FBBDC_14; lis 9,-32697; cmpwi 3,0; addi 9,9,24012; li 0,1; lwz 11,0x148(9); bne 5f; li 0,0; 5:; stw 0,0x4(11); lwz 9,0x148(9); lwz 0,0x4(9); cmpwi 0,0; beq 18f; lis 9,-32697; li 30,1; lwz 0,0x5c70(9); cmpwi 0,0; beq 6f; li 30,2; 6:; li 31,0; cmpw 31,30; bge 18f; lis 28,-32704; lis 29,-32704; 7:; lwz 3,-26524(13); mr 4,31; addi 31,31,1; bl _s801FBBDC_15; lwz 9,-21432(13); rlwinm 4,3,0,24,31; lfs f1,-20868(28); lfs f3,-20860(29); lwz 3,0x110(9); fmr f2,f1; fmr f4,f3; bl _s801FBBDC_16; cmpw 31,30; blt 7b; b 18f; 8:; lis 3,-32704; mr 4,31; addi 3,3,-21080; bl _s801FBBDC_17; cmpwi 3,0; bne 10f; mr 3,30; bl _s801FBBDC_18; lis 9,-32697; cmpwi 3,0; lwz 9,0x5f14(9); li 0,1; bne 9f; li 0,0; 9:; stw 0,0x0(9); b 18f; 10:; lis 3,-32704; mr 4,31; addi 3,3,-21064; bl _s801FBBDC_19; cmpwi 3,0; bne 12f; mr 3,30; bl _s801FBBDC_20; lis 9,-32697; cmpwi 3,0; lwz 9,0x5f14(9); li 0,1; bne 11f; li 0,0; 11:; stw 0,0x14(9); b 18f; 12:; lis 3,-32704; mr 4,31; addi 3,3,-21048; bl _s801FBBDC_21; cmpwi 3,0; bne 14f; mr 3,30; bl _s801FBBDC_22; lis 9,-32697; cmpwi 3,0; lwz 9,0x5f14(9); li 0,1; bne 13f; li 0,0; 13:; stw 0,0x18(9); b 18f; 14:; lis 3,-32704; mr 4,31; addi 3,3,-21028; bl _s801FBBDC_23; cmpwi 3,0; bne 16f; mr 3,30; bl _s801FBBDC_24; lis 9,-32697; cmpwi 3,0; lwz 9,0x5f14(9); li 0,1; bne 15f; li 0,0; 15:; stw 0,0x10(9); b 18f; 16:; lis 3,-32704; mr 4,31; addi 3,3,-21012; bl _s801FBBDC_25; cmpwi 3,0; bne 18f; mr 3,30; bl _s801FBBDC_26; mr. 3,3; bne 17f; mr 3,29; bl _s801FBBDC_27; b 18f; 17:; cmpwi 3,1; bne 18f; mr 3,29; bl _s801FBBDC_28; 18:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s801FBBDC_0();
extern "C" void _s801FBBDC_1();
extern "C" void _s801FBBDC_2();
extern "C" void _s801FBBDC_3();
extern "C" void _s801FBBDC_4();
extern "C" void _s801FBBDC_5();
extern "C" void _s801FBBDC_6();
extern "C" void _s801FBBDC_7();
extern "C" void _s801FBBDC_8();
extern "C" void _s801FBBDC_9();
extern "C" void _s801FBBDC_10();
extern "C" void _s801FBBDC_11();
extern "C" void _s801FBBDC_12();
extern "C" void _s801FBBDC_13();
extern "C" void _s801FBBDC_14();
extern "C" void _s801FBBDC_15();
extern "C" void _s801FBBDC_16();
extern "C" void _s801FBBDC_17();
extern "C" void _s801FBBDC_18();
extern "C" void _s801FBBDC_19();
extern "C" void _s801FBBDC_20();
extern "C" void _s801FBBDC_21();
extern "C" void _s801FBBDC_22();
extern "C" void _s801FBBDC_23();
extern "C" void _s801FBBDC_24();
extern "C" void _s801FBBDC_25();
extern "C" void _s801FBBDC_26();
extern "C" void _s801FBBDC_27();
extern "C" void _s801FBBDC_28();
extern "C" void f_801FBBDC() {}
