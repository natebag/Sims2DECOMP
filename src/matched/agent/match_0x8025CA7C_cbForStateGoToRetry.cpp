// 0x8025CA7C cbForStateGoToRetry (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,16; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); bne 0f; lis 3,291; addi 3,3,17768; bl _s8025CA7C_0; bl _s8025CA7C_1; li 3,0; bl _s8025CA7C_2; b 8f; 0:; rlwinm. 0,3,0,30,30; beq 1f; lis 3,291; addi 3,3,17767; bl _s8025CA7C_3; lis 3,-32730; addi 3,3,-15216; bl _s8025CA7C_4; b 8f; 1:; li 0,0; stw 0,-23428(13); lwz 0,-23452(13); cmplwi 0,4; beq 2f; lwz 0,-23452(13); cmplwi 0,5; beq 2f; lwz 0,-23452(13); cmplwi 0,13; beq 2f; lwz 0,-23452(13); cmplwi 0,15; bne 3f; 2:; li 0,1; stw 0,-23424(13); 3:; lwz 0,-23448(13); cmplwi 0,0; beq 6f; li 0,2; lwz 31,-23480(13); lis 3,-32694; stw 0,-23440(13); addi 0,3,-17184; li 3,0; stw 0,-23480(13); li 0,10; stw 3,-23448(13); stw 0,0xc(31); lwz 12,0x28(31); cmplwi 12,0; beq 4f; mtspr 8,12; addi 4,31,0; li 3,-3; blrl; 4:; lwz 12,-23444(13); cmplwi 12,0; beq 5f; mtspr 8,12; addi 4,31,0; li 3,0; blrl; 5:; bl _s8025CA7C_5; li 0,1; b 7f; 6:; li 0,0; 7:; cmpwi 0,0; bne 8f; lwz 3,-23480(13); li 0,11; stw 0,0xc(3); bl _s8025CA7C_6; 8:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025CA7C_0();
extern "C" void _s8025CA7C_1();
extern "C" void _s8025CA7C_2();
extern "C" void _s8025CA7C_3();
extern "C" void _s8025CA7C_4();
extern "C" void _s8025CA7C_5();
extern "C" void _s8025CA7C_6();
extern "C" void f_8025CA7C() {}
