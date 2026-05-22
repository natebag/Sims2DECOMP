// 0x80257B80 EXILock (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 27,0x1c(1); addi 27,3,0; addi 31,4,0; addi 28,5,0; rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 30,0,4; bl _s80257B80_0; mr 29,3; lwz 0,0xc(30); rlwinm. 0,0,0,27,27; beq 4f; cmplwi 28,0; beq 3f; mr 3,30; lwz 4,0x24(30); mtspr 9,4; cmpwi 4,0; ble 2f; 0:; lwz 0,0x28(3); cmplw 0,31; bne 1f; mr 3,29; bl _s80257B80_1; li 3,0; b 5f; 1:; addi 3,3,8; bdnz 0b; 2:; rlwinm 0,4,3,0,28; add 3,30,0; stw 28,0x2c(3); lwz 0,0x24(30); rlwinm 0,0,3,0,28; add 3,30,0; stw 31,0x28(3); lwz 3,0x24(30); addi 0,3,1; stw 0,0x24(30); 3:; mr 3,29; bl _s80257B80_2; li 3,0; b 5f; 4:; lwz 0,0xc(30); ori 0,0,16; stw 0,0xc(30); stw 31,0x18(30); addi 3,27,0; addi 4,30,0; bl _s80257B80_3; mr 3,29; bl _s80257B80_4; li 3,1; 5:; lwz 0,0x34(1); lmw 27,0x1c(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s80257B80_0();
extern "C" void _s80257B80_1();
extern "C" void _s80257B80_2();
extern "C" void _s80257B80_3();
extern "C" void _s80257B80_4();
extern "C" void f_80257B80() {}
