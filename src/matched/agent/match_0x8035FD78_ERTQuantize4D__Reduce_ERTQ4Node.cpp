// 0x8035FD78 ERTQuantize4D::Reduce(ERTQ4Node (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,4; mr 31,3; lhz 0,0x3a(28); cmpwi 0,0; beq 4f; li 29,0; addi 30,28,26; 0:; lhz 0,0x3a(28); sraw 0,0,29; andi. 9,0,1; beq 3f; lhz 9,0x0(30); cmpwi 9,0; beq 1f; mulli 9,9,72; lwz 0,0x1008(31); add 4,0,9; b 2f; 1:; li 4,0; 2:; mr 3,31; bl _s8035FD78_0; 3:; addi 29,29,1; addi 30,30,2; cmplwi 29,15; ble 0b; 4:; lwz 0,0x14(28); cmpwi 0,0; beq 5f; lwz 9,0x1024(31); addi 9,9,1; stw 9,0x1024(31); 5:; lwz 9,0x10(28); lwz 0,0x102c(31); cmplw 9,0; bge 6f; lwz 0,0x1028(31); cmplw 9,0; ble 7f; stw 9,0x102c(31); 6:; lwz 9,0x10(28); lwz 0,0x1028(31); cmplw 9,0; bgt 8f; 7:; mr 3,31; mr 4,28; bl _s8035FD78_1; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8035FD78_0();
extern "C" void _s8035FD78_1();
extern "C" void f_8035FD78() {}
