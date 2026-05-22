// 0x8026609C PADControlAllMotors (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 26,0x10(1); mr 26,3; bl _s8026609C_0; lis 30,-32768; lbz 0,0x30e3(30); addi 29,3,0; li 27,0; rlwinm 31,0,0,26,26; li 28,0; 0:; lwz 3,-23180(13); srw 0,30,28; and. 0,3,0; beq 3f; mr 3,28; bl _s8026609C_1; rlwinm. 0,3,0,2,2; bne 3f; lwz 0,-27640(13); lwz 3,0x0(26); cmplwi 0,2; bge 1f; cmplwi 3,2; bne 1f; li 3,0; 1:; cmpwi 31,0; beq 2f; li 3,0; 2:; lwz 4,-27644(13); rlwinm 0,3,0,30,31; addi 3,28,0; oris 4,4,64; or 4,4,0; bl _s8026609C_2; li 27,1; 3:; addi 28,28,1; cmpwi 28,4; addi 26,26,4; blt 0b; cmpwi 27,0; beq 4f; bl _s8026609C_3; 4:; mr 3,29; bl _s8026609C_4; lmw 26,0x10(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8026609C_0();
extern "C" void _s8026609C_1();
extern "C" void _s8026609C_2();
extern "C" void _s8026609C_3();
extern "C" void _s8026609C_4();
extern "C" void f_8026609C() {}
