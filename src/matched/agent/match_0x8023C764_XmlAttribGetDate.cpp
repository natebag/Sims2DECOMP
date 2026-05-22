// 0x8023C764 XmlAttribGetDate (420 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 27,0x34(1); stw 0,0x4c(1); mr 31,5; bl _s8023C764_0; mr. 3,3; beq 9f; lbz 9,0x0(3); addi 4,1,28; addi 30,1,24; addi 29,1,20; addi 9,9,-1; addi 28,1,16; cmplwi 9,31; addi 27,1,12; bgt 1f; 0:; lbzu 9,0x1(3); addi 9,9,-1; cmplwi 9,31; ble 0b; 1:; lbz 0,0x0(3); cmpwi 0,34; beq 2f; cmpwi 0,39; bne 3f; 2:; addi 3,3,1; 3:; li 9,0; li 0,-1; stw 9,0x24(1); stw 9,0x20(1); stw 0,0x28(1); bl _s8023C764_1; lbz 9,0x0(3); addi 9,9,-45; cmplwi 9,1; bgt 4f; addi 3,3,1; 4:; mr 4,30; bl _s8023C764_2; lbz 9,0x0(3); addi 9,9,-45; cmplwi 9,1; bgt 5f; addi 3,3,1; 5:; mr 4,29; bl _s8023C764_3; lbz 0,0x0(3); cmpwi 0,32; bne 6f; addi 3,3,1; 6:; mr 4,28; bl _s8023C764_4; lbz 0,0x0(3); cmpwi 0,58; bne 7f; addi 3,3,1; 7:; mr 4,27; bl _s8023C764_5; lbz 0,0x0(3); cmpwi 0,58; bne 8f; addi 3,3,1; 8:; addi 4,1,8; bl _s8023C764_6; lwz 9,0x1c(1); addi 0,9,-1970; cmplwi 0,129; bgt 9f; lwz 11,0x18(1); cmpwi 11,0; ble 9f; cmpwi 11,12; bgt 9f; lwz 0,0x14(1); cmpwi 0,0; ble 9f; cmpwi 0,31; bgt 9f; lwz 0,0x10(1); cmplwi 0,23; bgt 9f; lwz 0,0xc(1); cmpwi 0,0; blt 9f; cmpwi 0,59; bgt 9f; lwz 0,0x8(1); cmpwi 0,0; blt 9f; cmpwi 0,61; ble 10f; 9:; mr 3,31; b 11f; 10:; addi 0,11,-1; addi 9,9,-1900; stw 0,0x18(1); addi 3,1,8; stw 9,0x1c(1); bl _s8023C764_7; 11:; lwz 0,0x4c(1); mtspr 8,0; lmw 27,0x34(1); addi 1,1,72"
extern "C" void _s8023C764_0();
extern "C" void _s8023C764_1();
extern "C" void _s8023C764_2();
extern "C" void _s8023C764_3();
extern "C" void _s8023C764_4();
extern "C" void _s8023C764_5();
extern "C" void _s8023C764_6();
extern "C" void _s8023C764_7();
extern "C" void f_8023C764() {}
