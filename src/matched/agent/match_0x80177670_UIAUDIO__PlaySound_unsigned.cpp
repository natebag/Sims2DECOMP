// 0x80177670 UIAUDIO::PlaySound(unsigned (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 31,3; lwz 0,0x6200(9); mr 29,4; cmpwi 0,0; beq 2f; lwz 0,0xc(31); addi 11,31,16; rlwinm 0,0,2,0,29; lwzx 9,11,0; cmpwi 9,0; beq 2f; addi 30,31,56; lwzx 4,30,0; cmpwi 4,0; beq 0f; lwz 3,-22572(13); bl _s80177670_0; lwz 0,0xc(31); addi 11,31,36; li 9,0; rlwinm 0,0,2,0,29; stwx 9,11,0; 0:; lwz 0,0xc(31); lwz 11,-22572(13); rlwinm 0,0,2,0,29; stwx 29,30,0; lwz 9,0xd1c(11); lwz 0,0xc(31); lha 3,0x20(9); lwz 9,0x24(9); rlwinm 0,0,2,0,29; lwzx 4,30,0; add 3,11,3; mtspr 8,9; blrl; lwz 4,0xc(31); mr 3,31; bl _s80177670_1; lwz 9,0xc(31); li 0,0; addi 9,9,1; stw 9,0xc(31); cmpwi 9,4; bgt 1f; mr 0,9; 1:; mr 3,31; mr 4,0; stw 0,0xc(31); bl _s80177670_2; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80177670_0();
extern "C" void _s80177670_1();
extern "C" void _s80177670_2();
extern "C" void f_80177670() {}
