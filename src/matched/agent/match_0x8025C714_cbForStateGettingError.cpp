// 0x8025C714 cbForStateGettingError (612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,16; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); bne 0f; lis 3,291; addi 3,3,17768; bl _s8025C714_0; bl _s8025C714_1; li 3,0; bl _s8025C714_2; b 18f; 0:; rlwinm. 0,3,0,30,30; beq 1f; lis 3,291; addi 3,3,17767; bl _s8025C714_3; lis 3,-32730; addi 3,3,-15216; bl _s8025C714_4; b 18f; 1:; lis 3,-13312; lwz 29,0x6020(3); addi 3,29,0; rlwinm 28,29,0,0,7; bl _s8025C714_5; addi 31,3,0; cmplwi 31,1; bne 2f; mr 3,29; bl _s8025C714_6; lis 3,-32730; addi 3,3,-15216; bl _s8025C714_7; b 18f; 2:; addi 0,31,-2; cmplwi 0,1; bgt 3f; li 4,0; b 7f; 3:; addis 0,28,-256; cmplwi 0,0; bne 4f; li 4,4; b 7f; 4:; addis 0,28,-512; cmplwi 0,0; bne 5f; li 4,6; b 7f; 5:; addis 0,28,-768; cmplwi 0,0; bne 6f; li 4,3; b 7f; 6:; li 4,5; 7:; lwz 0,-23448(13); cmplwi 0,0; beq 10f; lis 3,-32694; stw 4,-23440(13); li 0,0; lwz 30,-23480(13); addi 3,3,-17184; stw 0,-23448(13); li 0,10; stw 3,-23480(13); stw 0,0xc(30); lwz 12,0x28(30); cmplwi 12,0; beq 8f; mtspr 8,12; addi 4,30,0; li 3,-3; blrl; 8:; lwz 12,-23444(13); cmplwi 12,0; beq 9f; mtspr 8,12; addi 4,30,0; li 3,0; blrl; 9:; bl _s8025C714_8; li 0,1; b 11f; 10:; li 0,0; 11:; cmpwi 0,0; bne 18f; cmplwi 31,2; bne 12f; mr 3,29; bl _s8025C714_9; bl _s8025C714_10; b 18f; 12:; cmplwi 31,3; bne 14f; rlwinm 3,29,0,8,31; addis 0,3,-3; cmplwi 0,4352; bne 13f; lwz 5,-23480(13); lis 3,-32730; addi 4,3,-13960; lwz 3,0x10(5); bl _s8025C714_11; b 18f; 13:; lwz 12,-23392(13); lwz 3,-23480(13); mtspr 8,12; blrl; b 18f; 14:; addis 0,28,-256; cmplwi 0,0; bne 15f; lwz 3,-23480(13); li 0,5; stw 0,0xc(3); bl _s8025C714_12; b 18f; 15:; addis 0,28,-512; cmplwi 0,0; bne 16f; lwz 3,-23480(13); li 0,3; stw 0,0xc(3); bl _s8025C714_13; b 18f; 16:; addis 0,28,-768; cmplwi 0,0; bne 17f; lwz 3,-23480(13); li 0,4; stw 0,0xc(3); bl _s8025C714_14; b 18f; 17:; lis 3,291; addi 3,3,17767; bl _s8025C714_15; lis 3,-32730; addi 3,3,-15216; bl _s8025C714_16; 18:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025C714_0();
extern "C" void _s8025C714_1();
extern "C" void _s8025C714_2();
extern "C" void _s8025C714_3();
extern "C" void _s8025C714_4();
extern "C" void _s8025C714_5();
extern "C" void _s8025C714_6();
extern "C" void _s8025C714_7();
extern "C" void _s8025C714_8();
extern "C" void _s8025C714_9();
extern "C" void _s8025C714_10();
extern "C" void _s8025C714_11();
extern "C" void _s8025C714_12();
extern "C" void _s8025C714_13();
extern "C" void _s8025C714_14();
extern "C" void _s8025C714_15();
extern "C" void _s8025C714_16();
extern "C" void f_8025C714() {}
