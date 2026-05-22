// 0x8035F15C ERTQuantize4D::AddPixel(unsigned (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lbz 8,0x1(4); lis 11,128; lbz 10,0x0(4); ori 11,11,16417; lbz 0,0x2(4); rlwinm 8,8,8,0,23; lbz 9,0x3(4); or 10,10,8; rlwinm 0,0,16,0,15; mr 28,3; or 10,10,0; rlwinm 9,9,24,0,7; or 29,10,9; mulhwu 11,29,11; subf 0,11,29; rlwinm 0,0,31,1,31; add 11,11,0; rlwinm 9,11,24,8,31; rlwinm 0,9,9,0,22; subf 0,9,0; subf 9,0,29; rlwinm 9,9,3,0,28; addi 30,9,4; lwzx 0,28,30; add 31,28,30; cmpw 0,29; bne 0f; lwz 9,0x4(31); addi 9,9,1; stw 9,0x4(31); b 2f; 0:; lwz 0,0x4(31); cmpwi 0,0; beq 1f; mr 3,28; mr 4,31; bl _s8035F15C_0; 1:; stwx 29,28,30; li 0,1; stw 0,0x4(31); 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8035F15C_0();
extern "C" void f_8035F15C() {}
