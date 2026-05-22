// 0x8025F754 DVDCancelAsync (636 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); addi 30,4,0; stw 29,0x1c(1); addi 29,3,0; bl _s8025F754_0; lwz 4,0xc(29); addi 31,3,0; addi 0,4,1; cmplwi 0,12; bgt 15f; lis 3,-32700; addi 3,3,-14292; rlwinm 0,0,2,0,29; lwzx 0,3,0; mtspr 9,0; bctr; cmplwi 30,0; beq 15f; addi 12,30,0; mtspr 8,12; addi 4,29,0; li 3,0; blrl; b 15f; lwz 0,-23448(13); cmplwi 0,0; beq 0f; mr 3,31; bl _s8025F754_1; li 3,0; b 16f; 0:; li 0,1; stw 30,-23444(13); stw 0,-23448(13); lwz 0,0x8(29); cmplwi 0,4; beq 1f; cmplwi 0,1; bne 15f; 1:; bl _s8025F754_2; b 15f; mr 3,29; bl _s8025F754_3; li 0,10; stw 0,0xc(29); lwz 12,0x28(29); cmplwi 12,0; beq 2f; mtspr 8,12; addi 4,29,0; li 3,-3; blrl; 2:; cmplwi 30,0; beq 15f; addi 12,30,0; mtspr 8,12; addi 4,29,0; li 3,0; blrl; b 15f; lwz 0,0x8(29); cmpwi 0,13; beq 4f; bge 3f; cmpwi 0,6; bge 5f; cmpwi 0,4; bge 4f; b 5f; 3:; cmpwi 0,15; beq 4f; b 5f; 4:; cmplwi 30,0; beq 15f; addi 12,30,0; mtspr 8,12; addi 4,29,0; li 3,0; blrl; b 15f; 5:; lwz 0,-23448(13); cmplwi 0,0; beq 6f; mr 3,31; bl _s8025F754_4; li 3,0; b 16f; 6:; li 0,1; stw 30,-23444(13); stw 0,-23448(13); b 15f; bl _s8025F754_5; lis 4,-32730; addi 0,4,-11716; cmplw 3,0; beq 7f; mr 3,31; bl _s8025F754_6; li 3,0; b 16f; 7:; lwz 0,0xc(29); cmpwi 0,4; bne 8f; li 0,3; stw 0,-23440(13); 8:; lwz 0,0xc(29); cmpwi 0,5; bne 9f; li 0,4; stw 0,-23440(13); 9:; lwz 0,0xc(29); cmpwi 0,6; bne 10f; li 0,1; stw 0,-23440(13); 10:; lwz 0,0xc(29); cmpwi 0,11; bne 11f; li 0,2; stw 0,-23440(13); 11:; lwz 0,0xc(29); cmpwi 0,7; bne 12f; li 0,7; stw 0,-23440(13); 12:; lis 3,-32694; addi 0,3,-17184; stw 0,-23480(13); li 0,10; stw 0,0xc(29); lwz 12,0x28(29); cmplwi 12,0; beq 13f; mtspr 8,12; addi 4,29,0; li 3,-3; blrl; 13:; cmplwi 30,0; beq 14f; addi 12,30,0; mtspr 8,12; addi 4,29,0; li 3,0; blrl; 14:; bl _s8025F754_7; 15:; mr 3,31; bl _s8025F754_8; li 3,1; 16:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8025F754_0();
extern "C" void _s8025F754_1();
extern "C" void _s8025F754_2();
extern "C" void _s8025F754_3();
extern "C" void _s8025F754_4();
extern "C" void _s8025F754_5();
extern "C" void _s8025F754_6();
extern "C" void _s8025F754_7();
extern "C" void _s8025F754_8();
extern "C" void f_8025F754() {}
