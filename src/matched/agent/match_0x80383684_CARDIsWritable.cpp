// 0x80383684 __CARDIsWritable (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 27,0x14(1); mr 27,4; lbz 0,0x0(4); lwz 29,0x10c(3); cmplwi 0,255; bne 0f; li 30,-4; b 3f; 0:; lis 3,-32688; addi 0,3,-23456; cmplw 29,0; beq 1f; addi 3,27,0; addi 4,29,0; li 5,4; bl _s80383684_0; cmpwi 3,0; bne 2f; addi 3,27,4; addi 4,29,4; li 5,2; bl _s80383684_1; cmpwi 3,0; bne 2f; 1:; li 30,0; b 3f; 2:; li 30,-10; 3:; cmpwi 30,-10; bne 5f; lbz 3,0x34(27); lbz 0,-25334(13); and 0,3,0; rlwinm 28,0,0,24,31; rlwinm. 0,0,0,26,26; beq 4f; lis 3,-32688; addi 31,3,-23456; addi 3,27,0; addi 4,31,0; li 5,4; bl _s80383684_2; cmpwi 3,0; bne 4f; addi 3,27,4; addi 4,31,4; li 5,2; bl _s80383684_3; cmpwi 3,0; bne 4f; li 3,0; b 6f; 4:; rlwinm. 0,28,0,25,25; beq 5f; lis 3,-32688; addi 4,3,-23456; addi 3,27,0; li 5,4; bl _s80383684_4; cmpwi 3,0; bne 5f; addi 3,27,4; addi 4,29,4; li 5,2; bl _s80383684_5; cmpwi 3,0; bne 5f; li 3,0; b 6f; 5:; mr 3,30; 6:; lmw 27,0x14(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80383684_0();
extern "C" void _s80383684_1();
extern "C" void _s80383684_2();
extern "C" void _s80383684_3();
extern "C" void _s80383684_4();
extern "C" void _s80383684_5();
extern "C" void f_80383684() {}
