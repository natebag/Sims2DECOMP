// 0x8008FBFC ELiveMode::StartIntroCamera(CameraDirector (556 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 26,0x10(1); stw 0,0x2c(1); stw 12,0xc(1); mr. 29,5; mr 27,3; mr 31,4; mfcr 30; beq 0f; mr 3,29; bl _s8008FBFC_0; 0:; lis 9,-32697; addi 26,9,24012; lwz 0,0xac(26); cmpwi 0,0; bne 7f; lwz 8,-26392(13); lis 9,-32707; lfs f1,0x7ec0(9); lis 11,-32707; lwz 10,0x0(8); lis 9,-32707; fmr f3,f1; lfs f4,0x7ec8(9); lha 3,0x1b0(10); cmpwi 4,31,0; lwz 0,0x1b4(10); lfs f2,0x7ec4(11); add 3,8,3; mtspr 8,0; blrl; lis 9,-32707; lwz 3,-26392(13); lfs f1,0x7ecc(9); fmr f2,f1; fmr f3,f2; fmr f4,f3; bl _s8008FBFC_1; beq cr4,7f; lwz 0,0x240(31); mtcrf 128,30; rlwinm 0,0,0,0,30; stw 0,0x240(31); beq 1f; mr 3,31; mr 4,29; li 5,1; bl _s8008FBFC_2; 1:; lis 3,-32692; lis 4,3123; ori 4,4,56129; li 5,0; li 6,0; addi 3,3,-20832; bl _s8008FBFC_3; li 28,0; mr 30,3; lis 4,-32707; addi 4,4,32416; bl _s8008FBFC_4; lwz 0,0xb0(26); mr 4,3; cmpwi 0,0; bne 2f; lwz 11,-32056(13); lis 9,-32702; addi 9,9,15980; lwz 0,0x24(11); stw 0,0x54(27); rlwinm 0,0,2,0,29; lwzx 5,9,0; b 3f; 2:; lis 9,-32707; addi 5,9,32424; 3:; cmpwi 5,0; beq 4f; mr 3,30; bl _s8008FBFC_5; mr 28,3; 4:; cmpwi 28,0; beq 7f; lis 9,-32697; li 10,0; addi 9,9,24012; lwz 0,0xb0(9); cmpwi 0,0; beq 5f; beq cr4,5f; cmpwi 29,0; beq 5f; lwz 0,0x4(29); addi 9,9,188; rlwinm 0,0,2,0,29; lwzx 9,9,0; cmpwi 9,0; beq 5f; lwz 9,0x0(9); lwz 11,0x0(9); lwz 5,0x14(11); cmpwi 5,0; beq 5f; addi 5,5,192; mr 3,31; li 4,0; bl _s8008FBFC_6; li 10,1; 5:; mr 4,28; mr 5,10; mr 3,31; li 6,0; bl _s8008FBFC_7; cmpwi 3,0; beq 7f; mr 3,29; li 4,0; bl _s8008FBFC_8; mr 3,31; bl _s8008FBFC_9; lwz 0,0x240(31); lis 11,-32697; ori 0,0,1; stw 0,0x240(31); lwz 9,0x5c70(11); cmpwi 9,0; beq 6f; li 0,1; stw 0,0x54c(29); 6:; li 3,1; b 8f; 7:; li 3,0; 8:; lwz 0,0x2c(1); lwz 12,0xc(1); mtspr 8,0; lmw 26,0x10(1); mtcrf 8,12; addi 1,1,40"
extern "C" void _s8008FBFC_0();
extern "C" void _s8008FBFC_1();
extern "C" void _s8008FBFC_2();
extern "C" void _s8008FBFC_3();
extern "C" void _s8008FBFC_4();
extern "C" void _s8008FBFC_5();
extern "C" void _s8008FBFC_6();
extern "C" void _s8008FBFC_7();
extern "C" void _s8008FBFC_8();
extern "C" void _s8008FBFC_9();
extern "C" void f_8008FBFC() {}
