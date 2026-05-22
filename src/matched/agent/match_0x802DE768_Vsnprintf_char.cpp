// 0x802DE768 Vsnprintf(char (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; addi 9,1,8; stw 31,0x8(1); mr 30,4; li 29,0; lis 3,-32722; addi 3,3,-12668; mr 4,9; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); bl _s802DE768_0; cmpwi 31,0; beq 1f; cmpwi 3,0; blt 1f; cmplw 3,30; bge 0f; stbx 29,31,3; b 1f; 0:; add 9,30,31; stb 29,-1(9); 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s802DE768_0();
extern "C" void f_802DE768() {}
