// 0x8026559C PADTypeAndStatusCallback (812 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 6,-32694; stw 0,0x4(1); rlwinm. 0,4,0,28,31; stwu 1,-64(1); stw 31,0x3c(1); lis 31,-32768; stw 30,0x38(1); addi 30,6,-16416; stw 29,0x34(1); stw 28,0x30(1); lwz 29,-27652(13); lwz 5,-23172(13); srw 28,31,29; andc 3,5,28; stw 3,-23172(13); and 5,5,28; li 3,1; beq 0f; lwz 4,-23176(13); cntlzw 0,4; stw 0,-27652(13); lwz 3,-27652(13); cmpwi 3,32; beq 9f; mulli 0,3,12; srw 3,31,3; andc 4,4,3; add 3,30,0; stw 4,-23176(13); li 4,0; li 5,12; addi 3,3,16; bl _s8026559C_0; lis 4,-32730; lwz 3,-27652(13); addi 4,4,21916; bl _s8026559C_1; b 9f; 0:; rlwinm 6,4,0,0,23; rlwinm 4,4,0,3,4; addis 0,4,-2048; rlwinm 4,29,2,0,29; cmplwi 0,0; stwx 6,30,4; bne 1f; rlwinm. 0,6,0,7,7; bne 2f; 1:; lwz 5,-23176(13); cntlzw 0,5; stw 0,-27652(13); lwz 4,-27652(13); cmpwi 4,32; beq 9f; lis 3,-32768; mulli 0,4,12; srw 3,3,4; andc 4,5,3; add 3,30,0; stw 4,-23176(13); li 4,0; li 5,12; addi 3,3,16; bl _s8026559C_2; lis 4,-32730; lwz 3,-27652(13); addi 4,4,21916; bl _s8026559C_3; b 9f; 2:; lwz 0,-27640(13); cmplwi 0,2; bge 3f; lwz 0,-23180(13); addi 3,29,0; addi 4,1,28; or 0,0,28; stw 0,-23180(13); bl _s8026559C_4; lwz 0,-27644(13); addi 3,29,0; oris 4,0,64; bl _s8026559C_5; lwz 3,-23180(13); bl _s8026559C_6; lwz 4,-23176(13); cntlzw 0,4; stw 0,-27652(13); lwz 3,-27652(13); cmpwi 3,32; beq 9f; mulli 0,3,12; srw 3,31,3; andc 4,4,3; add 3,30,0; stw 4,-23176(13); li 4,0; li 5,12; addi 3,3,16; bl _s8026559C_7; lis 4,-32730; lwz 3,-27652(13); addi 4,4,21916; bl _s8026559C_8; b 9f; 3:; rlwinm. 0,6,0,0,0; beq 4f; rlwinm. 0,6,0,5,5; beq 6f; 4:; cmplwi 5,0; beq 5f; mulli 0,29,12; lis 3,-32730; add 6,30,0; addi 8,3,21300; addi 3,29,0; addi 4,13,-27628; li 5,3; li 7,10; li 10,0; li 9,0; addi 6,6,16; bl _s8026559C_9; b 8f; 5:; mulli 0,29,12; lis 3,-32730; add 6,30,0; addi 8,3,21300; addi 3,29,0; addi 4,13,-27632; li 5,1; li 7,10; li 10,0; li 9,0; addi 6,6,16; bl _s8026559C_10; b 8f; 6:; rlwinm. 0,6,0,11,11; beq 8f; rlwinm. 0,6,0,12,12; bne 8f; rlwinm. 0,6,0,13,13; bne 8f; rlwinm. 0,6,0,1,1; beq 7f; mulli 0,29,12; lis 3,-32730; add 6,30,0; addi 8,3,21300; addi 3,29,0; addi 4,13,-27632; li 5,1; li 7,10; li 10,0; li 9,0; addi 6,6,16; bl _s8026559C_11; b 8f; 7:; mulli 0,29,12; lis 3,-32730; add 4,30,4; add 6,30,0; addi 8,3,21700; addi 3,29,0; li 5,3; li 7,8; li 10,0; li 9,0; addi 4,4,64; addi 6,6,16; bl _s8026559C_12; 8:; cmpwi 3,0; bne 9f; lwz 5,-23176(13); lwz 3,-23160(13); cntlzw 0,5; stw 0,-27652(13); or 0,3,28; lwz 4,-27652(13); stw 0,-23160(13); cmpwi 4,32; beq 9f; lis 3,-32768; mulli 0,4,12; srw 3,3,4; andc 4,5,3; add 3,30,0; stw 4,-23176(13); li 4,0; li 5,12; addi 3,3,16; bl _s8026559C_13; lis 4,-32730; lwz 3,-27652(13); addi 4,4,21916; bl _s8026559C_14; 9:; lwz 0,0x44(1); lwz 31,0x3c(1); lwz 30,0x38(1); lwz 29,0x34(1); lwz 28,0x30(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s8026559C_0();
extern "C" void _s8026559C_1();
extern "C" void _s8026559C_2();
extern "C" void _s8026559C_3();
extern "C" void _s8026559C_4();
extern "C" void _s8026559C_5();
extern "C" void _s8026559C_6();
extern "C" void _s8026559C_7();
extern "C" void _s8026559C_8();
extern "C" void _s8026559C_9();
extern "C" void _s8026559C_10();
extern "C" void _s8026559C_11();
extern "C" void _s8026559C_12();
extern "C" void _s8026559C_13();
extern "C" void _s8026559C_14();
extern "C" void f_8026559C() {}
