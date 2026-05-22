// 0x8025D610 stateBusy (832 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32730; stw 0,0x4(1); addi 0,4,-10736; mr 7,3; stwu 1,-8(1); stw 0,-23392(13); lwz 0,0x8(3); cmplwi 0,16; bgt 5f; lis 3,-32700; addi 3,3,-14440; rlwinm 0,0,2,0,29; lwzx 0,3,0; mtspr 9,0; bctr; lis 3,-13312; lwz 0,0x6004(3); addi 5,3,24576; lis 3,-32730; stw 0,0x4(5); li 0,32; addi 4,3,-9684; stw 0,0x1c(7); lwz 3,0x18(7); bl _s8025D610_0; b 6f; lwz 0,0x14(7); cmplwi 0,0; bne 1f; lis 3,-32694; lwz 4,-23480(13); addi 0,3,-17184; stw 0,-23480(13); li 0,0; stw 0,0xc(4); lwz 12,0x28(4); cmplwi 12,0; beq 0f; mtspr 8,12; li 3,0; blrl; 0:; bl _s8025D610_1; b 6f; 1:; lis 3,-13312; addi 3,3,24576; lwz 0,0x4(3); lis 4,8; stw 0,0x4(3); lwz 3,0x20(7); lwz 0,0x14(7); subf 0,3,0; cmplw 0,4; ble 2f; b 3f; 2:; mr 4,0; 3:; stw 4,0x1c(7); lis 3,-32730; addi 6,3,-9684; lwz 5,0x20(7); lwz 3,0x18(7); lwz 0,0x10(7); add 3,3,5; lwz 4,0x1c(7); add 5,0,5; bl _s8025D610_2; b 6f; lis 3,-13312; lwz 0,0x6004(3); addi 5,3,24576; lis 3,-32730; stw 0,0x4(5); addi 4,3,-9684; lwz 3,0x10(7); bl _s8025D610_3; b 6f; lis 3,-32730; addi 3,3,-9684; bl _s8025D610_4; b 6f; lis 3,-32730; addi 3,3,-9684; bl _s8025D610_5; b 6f; lis 3,-13312; addi 3,3,24576; lwz 0,0x4(3); stw 0,0x4(3); lwz 0,-23460(13); cmpwi 0,0; beq 4f; lwz 5,-23480(13); li 0,0; lis 3,-32730; stw 0,0x1c(5); addi 4,3,-9684; li 3,0; bl _s8025D610_6; b 6f; 4:; lwz 4,-23480(13); li 0,1; lis 3,-32730; stw 0,0x1c(4); addi 6,3,-9684; li 3,0; lwz 4,0x14(7); lwz 5,0x10(7); bl _s8025D610_7; b 6f; lis 3,-13312; lwz 0,0x6004(3); addi 4,3,24576; lis 3,-32730; stw 0,0x4(4); addi 6,3,-9684; lis 3,1; li 4,0; li 5,0; bl _s8025D610_8; b 6f; lis 3,-13312; lwz 0,0x6004(3); addi 4,3,24576; lis 3,-32730; stw 0,0x4(4); li 0,1; addi 6,3,-9684; stw 0,-23460(13); li 3,0; li 4,0; li 5,0; bl _s8025D610_9; b 6f; lis 3,-13312; lwz 0,0x6004(3); addi 5,3,24576; lis 3,-32730; stw 0,0x4(5); addi 4,3,-9684; li 3,0; bl _s8025D610_10; b 6f; lis 3,-13312; lwz 0,0x6004(3); addi 5,3,24576; lis 3,-32730; stw 0,0x4(5); addi 4,3,-9684; lis 3,1; bl _s8025D610_11; b 6f; lis 3,-13312; lwz 0,0x6004(3); addi 5,3,24576; lis 3,-32730; stw 0,0x4(5); addi 4,3,-9684; lis 3,2; bl _s8025D610_12; b 6f; lis 3,-13312; lwz 0,0x6004(3); addi 5,3,24576; lis 3,-32730; stw 0,0x4(5); addi 4,3,-9684; lis 3,3; bl _s8025D610_13; b 6f; lis 3,-13312; lwz 0,0x6004(3); addi 4,3,24576; lis 3,-32730; stw 0,0x4(4); addi 5,3,-9684; lwz 3,0x10(7); lwz 4,0x14(7); bl _s8025D610_14; b 6f; lis 3,-13312; lwz 0,0x6004(3); addi 5,3,24576; lis 3,-32730; stw 0,0x4(5); li 0,32; addi 4,3,-9684; stw 0,0x1c(7); lwz 3,0x18(7); bl _s8025D610_15; b 6f; lis 3,-13312; lwz 0,0x6004(3); addi 4,3,24576; lis 3,-32730; stw 0,0x4(4); addi 3,3,-9684; bl _s8025D610_16; b 6f; 5:; lwz 12,-27784(13); lis 3,-32730; addi 4,3,-9684; mtspr 8,12; addi 3,7,0; blrl; 6:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025D610_0();
extern "C" void _s8025D610_1();
extern "C" void _s8025D610_2();
extern "C" void _s8025D610_3();
extern "C" void _s8025D610_4();
extern "C" void _s8025D610_5();
extern "C" void _s8025D610_6();
extern "C" void _s8025D610_7();
extern "C" void _s8025D610_8();
extern "C" void _s8025D610_9();
extern "C" void _s8025D610_10();
extern "C" void _s8025D610_11();
extern "C" void _s8025D610_12();
extern "C" void _s8025D610_13();
extern "C" void _s8025D610_14();
extern "C" void _s8025D610_15();
extern "C" void _s8025D610_16();
extern "C" void f_8025D610() {}
