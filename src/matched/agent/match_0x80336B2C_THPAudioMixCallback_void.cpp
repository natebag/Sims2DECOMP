// 0x80336B2C THPAudioMixCallback(void) (412 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,-26356(13); cmpwi 0,0; bne 1f; lwz 0,-22536(13); lis 9,-32691; addi 31,9,20384; li 4,640; xori 0,0,1; li 30,1; rlwinm 3,0,2,0,29; stw 0,-22536(13); add 3,3,0; rlwinm 3,3,7,0,24; add 3,3,31; bl _s80336B2C_0; bl _s80336B2C_1; cmpwi 3,0; bne 0f; li 30,0; 0:; lwz 0,-22536(13); li 4,0; li 5,160; rlwinm 3,0,2,0,29; add 3,3,0; rlwinm 3,3,7,0,24; add 3,3,31; bl _s80336B2C_2; lwz 0,-22536(13); li 4,640; rlwinm 3,0,2,0,29; add 3,3,0; rlwinm 3,3,7,0,24; add 3,3,31; bl _s80336B2C_3; mr 3,30; bl _s80336B2C_4; b 7f; 1:; cmpwi 0,1; bne 3f; lwz 0,-22532(13); cmpwi 0,0; beq 2f; stw 0,-22528(13); 2:; lwz 9,-26360(13); mtspr 8,9; blrl; bl _s80336B2C_5; addis 3,3,-32768; stw 3,-22532(13); b 4f; 3:; lwz 9,-26360(13); mtspr 8,9; blrl; bl _s80336B2C_6; addis 3,3,-32768; stw 3,-22528(13); 4:; lwz 0,-22536(13); lis 9,-32691; addi 31,9,20384; li 4,640; xori 0,0,1; li 30,1; rlwinm 3,0,2,0,29; stw 0,-22536(13); add 3,3,0; rlwinm 3,3,7,0,24; add 3,3,31; bl _s80336B2C_7; bl _s80336B2C_8; cmpwi 3,0; bne 5f; li 30,0; 5:; lwz 3,-22528(13); cmpwi 3,0; beq 6f; li 4,640; bl _s80336B2C_9; 6:; lwz 0,-22536(13); li 5,160; lwz 4,-22528(13); rlwinm 3,0,2,0,29; add 3,3,0; rlwinm 3,3,7,0,24; add 3,3,31; bl _s80336B2C_10; lwz 0,-22536(13); li 4,640; rlwinm 3,0,2,0,29; add 3,3,0; rlwinm 3,3,7,0,24; add 3,3,31; bl _s80336B2C_11; mr 3,30; bl _s80336B2C_12; 7:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80336B2C_0();
extern "C" void _s80336B2C_1();
extern "C" void _s80336B2C_2();
extern "C" void _s80336B2C_3();
extern "C" void _s80336B2C_4();
extern "C" void _s80336B2C_5();
extern "C" void _s80336B2C_6();
extern "C" void _s80336B2C_7();
extern "C" void _s80336B2C_8();
extern "C" void _s80336B2C_9();
extern "C" void _s80336B2C_10();
extern "C" void _s80336B2C_11();
extern "C" void _s80336B2C_12();
extern "C" void f_80336B2C() {}
