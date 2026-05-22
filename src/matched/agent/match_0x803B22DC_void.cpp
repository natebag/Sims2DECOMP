// 0x803B22DC void (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,4; mr 31,6; mr 28,3; mr 27,5; cmplw 31,30; ble 1f; bl _s803B22DC_0; cmpwi 3,0; beq 0f; li 9,0; stw 9,0x0(9); 0:; .long 0x00000001; 1:; mr 4,30; mulli 26,31,20; subf. 29,31,4; beq 3f; mulli 9,4,20; addi 0,9,-20; add 30,9,28; add 31,0,28; 2:; mr 3,30; mr 4,31; bl _s803B22DC_1; addi 30,30,-20; lbz 0,0x10(31); addic. 29,29,-1; lbz 9,0x11(31); stb 0,0x24(31); stb 9,0x25(31); addi 31,31,-20; bne 2b; 3:; add 30,26,28; mr 4,27; mr 3,30; bl _s803B22DC_2; lbz 0,0x10(27); stb 0,0x10(30); lbz 9,0x11(27); stb 9,0x11(30); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s803B22DC_0();
extern "C" void _s803B22DC_1();
extern "C" void _s803B22DC_2();
extern "C" void f_803B22DC() {}
