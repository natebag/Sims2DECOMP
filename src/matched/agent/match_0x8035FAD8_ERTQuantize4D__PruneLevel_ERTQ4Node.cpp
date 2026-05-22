// 0x8035FAD8 ERTQuantize4D::PruneLevel(ERTQ4Node (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,4; mr 29,3; lhz 0,0x3a(28); cmpwi 0,0; beq 4f; li 30,0; addi 31,28,26; 0:; lhz 0,0x3a(28); sraw 0,0,30; andi. 9,0,1; beq 3f; lhz 9,0x0(31); cmpwi 9,0; beq 1f; mulli 9,9,72; lwz 0,0x1008(29); add 4,0,9; b 2f; 1:; li 4,0; 2:; mr 3,29; bl _s8035FAD8_0; 3:; addi 30,30,1; addi 31,31,2; cmplwi 30,15; ble 0b; 4:; lbz 9,0x44(28); lwz 0,0x101c(29); cmpw 9,0; bne 5f; mr 3,29; mr 4,28; bl _s8035FAD8_1; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8035FAD8_0();
extern "C" void _s8035FAD8_1();
extern "C" void f_8035FAD8() {}
