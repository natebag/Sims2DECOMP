// 0x801F8BC0 INTTarget::Update(void) (472 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x84(31); cmpwi 0,0; beq 3f; lwz 0,0x8c(31); cmpwi 0,0; bne 3f; lwz 0,0x94(31); lwz 9,0x88(31); mr 11,0; cmpwi 0,0; beq 2f; cmpwi 9,0; bne 1f; lwz 0,0x9c(31); cmpwi 0,0; beq 1f; lwz 8,0x98(31); addi 9,13,-28644; addi 30,31,200; lwz 4,-28672(13); rlwinm 0,8,2,0,29; li 5,250; lwzx 7,9,0; li 6,0; mr 3,30; mr 29,30; bl _s801F8BC0_0; li 4,255; mr 3,30; bl _s801F8BC0_1; mr 3,30; bl _s801F8BC0_2; li 0,1; mr 3,30; stw 0,0x8c(31); bl _s801F8BC0_3; lwz 4,-28672(13); mr 3,30; lwz 5,0x98(31); bl _s801F8BC0_4; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 0f; lwz 0,0x98(31); cmpwi 0,0; bne 0f; mr 3,29; li 4,-320; bl _s801F8BC0_5; 0:; mr 3,29; li 4,1; bl _s801F8BC0_6; lwz 4,-28528(13); li 5,0; mr 3,29; bl _s801F8BC0_7; lis 4,-32704; mr 3,29; addi 4,4,-22824; bl _s801F8BC0_8; lwz 5,0x98(31); mr 3,29; lwz 4,-28532(13); bl _s801F8BC0_9; lwz 4,0xdc(31); mr 3,29; bl _s801F8BC0_10; mr 3,29; bl _s801F8BC0_11; lis 9,-32697; lwz 4,0x98(31); lwz 3,0x5bcc(9); li 5,0; bl _s801F8BC0_12; li 0,1; stw 0,0x88(31); b 3f; 1:; cmpwi 11,0; bne 3f; 2:; cmpwi 9,0; beq 3f; lwz 29,0x90(31); cmpwi 29,0; bne 3f; lwz 8,0x98(31); addi 9,13,-28632; addi 30,31,200; lwz 4,-28672(13); rlwinm 0,8,2,0,29; li 5,250; lwzx 7,9,0; li 6,0; mr 3,30; bl _s801F8BC0_13; li 4,0; mr 3,30; bl _s801F8BC0_14; mr 3,30; bl _s801F8BC0_15; li 0,1; stw 29,0x9c(31); stw 0,0x8c(31); lis 9,-32697; lwz 4,0x98(31); li 5,1; lwz 3,0x5bcc(9); bl _s801F8BC0_16; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801F8BC0_0();
extern "C" void _s801F8BC0_1();
extern "C" void _s801F8BC0_2();
extern "C" void _s801F8BC0_3();
extern "C" void _s801F8BC0_4();
extern "C" void _s801F8BC0_5();
extern "C" void _s801F8BC0_6();
extern "C" void _s801F8BC0_7();
extern "C" void _s801F8BC0_8();
extern "C" void _s801F8BC0_9();
extern "C" void _s801F8BC0_10();
extern "C" void _s801F8BC0_11();
extern "C" void _s801F8BC0_12();
extern "C" void _s801F8BC0_13();
extern "C" void _s801F8BC0_14();
extern "C" void _s801F8BC0_15();
extern "C" void _s801F8BC0_16();
extern "C" void f_801F8BC0() {}
