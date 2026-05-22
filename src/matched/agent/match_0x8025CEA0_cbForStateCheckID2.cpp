// 0x8025CEA0 cbForStateCheckID2 (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,16; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); bne 0f; lis 3,291; addi 3,3,17768; bl _s8025CEA0_0; bl _s8025CEA0_1; li 3,0; bl _s8025CEA0_2; b 3f; 0:; rlwinm. 0,3,0,31,31; beq 2f; lis 3,-32730; lwz 4,-23472(13); addi 0,3,-15492; li 5,0; stw 0,-23392(13); lis 3,-32694; stw 5,-23428(13); addi 3,3,-17248; addi 31,3,8; lwz 3,0x3c(4); lwz 0,0x0(31); cmplw 3,0; bge 1f; lis 3,-32700; crxor 6,6,6; addi 5,3,-14492; addi 3,13,-27780; li 4,661; bl _s8025CEA0_3; 1:; lis 3,-32694; lwz 6,0x0(31); addi 5,3,-17248; lwz 7,-23472(13); lis 4,-32730; lwz 5,0x4(5); addi 0,6,31; lwz 3,0x38(7); addi 6,4,-15344; rlwinm 4,0,0,0,26; bl _s8025CEA0_4; b 3f; 2:; lis 3,-32730; addi 3,3,-14572; bl _s8025CEA0_5; 3:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025CEA0_0();
extern "C" void _s8025CEA0_1();
extern "C" void _s8025CEA0_2();
extern "C" void _s8025CEA0_3();
extern "C" void _s8025CEA0_4();
extern "C" void _s8025CEA0_5();
extern "C" void f_8025CEA0() {}
