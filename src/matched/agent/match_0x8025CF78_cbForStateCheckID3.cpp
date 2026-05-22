// 0x8025CF78 cbForStateCheckID3 (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,16; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); bne 0f; lis 3,291; addi 3,3,17768; bl _s8025CF78_0; bl _s8025CF78_1; li 3,0; bl _s8025CF78_2; b 5f; 0:; rlwinm. 0,3,0,31,31; beq 4f; li 4,0; stw 4,-23428(13); lwz 0,-23448(13); cmplwi 0,0; beq 3f; stw 4,-23440(13); lis 3,-32694; lwz 31,-23480(13); addi 3,3,-17184; stw 4,-23448(13); li 0,10; stw 3,-23480(13); stw 0,0xc(31); lwz 12,0x28(31); cmplwi 12,0; beq 1f; mtspr 8,12; addi 4,31,0; li 3,-3; blrl; 1:; lwz 12,-23444(13); cmplwi 12,0; beq 2f; mtspr 8,12; addi 4,31,0; li 3,0; blrl; 2:; bl _s8025CF78_3; li 4,1; 3:; cmpwi 4,0; bne 5f; lwz 3,-23480(13); li 0,1; stw 0,0xc(3); lwz 3,-23480(13); bl _s8025CF78_4; b 5f; 4:; lis 3,-32730; addi 3,3,-14572; bl _s8025CF78_5; 5:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025CF78_0();
extern "C" void _s8025CF78_1();
extern "C" void _s8025CF78_2();
extern "C" void _s8025CF78_3();
extern "C" void _s8025CF78_4();
extern "C" void _s8025CF78_5();
extern "C" void f_8025CF78() {}
