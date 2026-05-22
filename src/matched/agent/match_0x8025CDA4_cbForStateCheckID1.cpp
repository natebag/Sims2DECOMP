// 0x8025CDA4 cbForStateCheckID1 (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,16; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); bne 0f; lis 3,291; addi 3,3,17768; bl _s8025CDA4_0; bl _s8025CDA4_1; li 3,0; bl _s8025CDA4_2; b 5f; 0:; rlwinm. 0,3,0,30,30; beq 1f; lis 3,291; addi 3,3,17767; bl _s8025CDA4_3; lis 3,-32730; addi 3,3,-15216; bl _s8025CDA4_4; b 5f; 1:; li 4,0; stw 4,-23428(13); lwz 0,-23448(13); cmplwi 0,0; beq 4f; li 0,1; lwz 31,-23480(13); stw 0,-23440(13); lis 3,-32694; addi 3,3,-17184; stw 4,-23448(13); li 0,10; stw 3,-23480(13); stw 0,0xc(31); lwz 12,0x28(31); cmplwi 12,0; beq 2f; mtspr 8,12; addi 4,31,0; li 3,-3; blrl; 2:; lwz 12,-23444(13); cmplwi 12,0; beq 3f; mtspr 8,12; addi 4,31,0; li 3,0; blrl; 3:; bl _s8025CDA4_5; li 4,1; 4:; cmpwi 4,0; bne 5f; lwz 3,-23480(13); li 0,6; stw 0,0xc(3); bl _s8025CDA4_6; 5:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025CDA4_0();
extern "C" void _s8025CDA4_1();
extern "C" void _s8025CDA4_2();
extern "C" void _s8025CDA4_3();
extern "C" void _s8025CDA4_4();
extern "C" void _s8025CDA4_5();
extern "C" void _s8025CDA4_6();
extern "C" void f_8025CDA4() {}
