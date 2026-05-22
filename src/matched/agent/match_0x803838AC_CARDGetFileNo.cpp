// 0x803838AC __CARDGetFileNo (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-56(1); stmw 25,0x1c(1); mr 27,3; addi 28,4,0; addi 29,5,0; lwz 0,0x0(3); cmpwi 0,0; bne 0f; li 3,-3; b 12f; 0:; mr 3,27; bl _s803838AC_0; lis 4,-32688; addi 31,3,0; addi 26,4,-23456; li 30,0; 1:; lbz 0,0x0(31); lwz 25,0x10c(27); cmplwi 0,255; bne 2f; li 0,-4; b 5f; 2:; cmplw 25,26; beq 3f; addi 3,31,0; addi 4,25,0; li 5,4; bl _s803838AC_1; cmpwi 3,0; bne 4f; addi 3,31,4; addi 4,25,4; li 5,2; bl _s803838AC_2; cmpwi 3,0; bne 4f; 3:; li 0,0; b 5f; 4:; li 0,-10; 5:; cmpwi 0,0; blt 11f; addi 7,28,0; addi 6,31,8; li 4,32; b 8f; 6:; lbz 0,0x0(6); addi 6,6,1; lbz 5,0x0(7); addi 7,7,1; extsb 3,0; extsb 0,5; cmpw 3,0; beq 7f; li 0,0; b 10f; 7:; extsb. 0,5; bne 8f; li 0,1; b 10f; 8:; addic. 4,4,-1; bge 6b; lbz 0,0x0(7); extsb. 0,0; bne 9f; li 0,1; b 10f; 9:; li 0,0; 10:; cmpwi 0,0; beq 11f; stw 30,0x0(29); li 3,0; b 12f; 11:; addi 30,30,1; cmpwi 30,127; addi 31,31,64; blt 1b; li 3,-4; 12:; lmw 25,0x1c(1); lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s803838AC_0();
extern "C" void _s803838AC_1();
extern "C" void _s803838AC_2();
extern "C" void f_803838AC() {}
