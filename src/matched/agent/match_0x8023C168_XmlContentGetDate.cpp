// 0x8023C168 XmlContentGetDate (396 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 27,0x34(1); stw 0,0x4c(1); mr 31,4; bl _s8023C168_0; mr. 3,3; beq 7f; lbz 9,0x0(3); addi 4,1,28; addi 30,1,24; addi 29,1,20; addi 9,9,-1; addi 28,1,16; cmplwi 9,31; addi 27,1,12; bgt 1f; 0:; lbzu 9,0x1(3); addi 9,9,-1; cmplwi 9,31; ble 0b; 1:; li 9,0; li 0,-1; stw 9,0x24(1); stw 9,0x20(1); stw 0,0x28(1); bl _s8023C168_1; lbz 9,0x0(3); addi 9,9,-45; cmplwi 9,1; bgt 2f; addi 3,3,1; 2:; mr 4,30; bl _s8023C168_2; lbz 9,0x0(3); addi 9,9,-45; cmplwi 9,1; bgt 3f; addi 3,3,1; 3:; mr 4,29; bl _s8023C168_3; lbz 0,0x0(3); cmpwi 0,32; bne 4f; addi 3,3,1; 4:; mr 4,28; bl _s8023C168_4; lbz 0,0x0(3); cmpwi 0,58; bne 5f; addi 3,3,1; 5:; mr 4,27; bl _s8023C168_5; lbz 0,0x0(3); cmpwi 0,58; bne 6f; addi 3,3,1; 6:; addi 4,1,8; bl _s8023C168_6; lwz 9,0x1c(1); addi 0,9,-1970; cmplwi 0,129; bgt 7f; lwz 11,0x18(1); cmpwi 11,0; ble 7f; cmpwi 11,12; bgt 7f; lwz 0,0x14(1); cmpwi 0,0; ble 7f; cmpwi 0,31; bgt 7f; lwz 0,0x10(1); cmplwi 0,23; bgt 7f; lwz 0,0xc(1); cmpwi 0,0; blt 7f; cmpwi 0,59; bgt 7f; lwz 0,0x8(1); cmpwi 0,0; blt 7f; cmpwi 0,61; ble 8f; 7:; mr 3,31; b 9f; 8:; addi 0,11,-1; addi 9,9,-1900; stw 0,0x18(1); addi 3,1,8; stw 9,0x1c(1); bl _s8023C168_7; 9:; lwz 0,0x4c(1); mtspr 8,0; lmw 27,0x34(1); addi 1,1,72"
extern "C" void _s8023C168_0();
extern "C" void _s8023C168_1();
extern "C" void _s8023C168_2();
extern "C" void _s8023C168_3();
extern "C" void _s8023C168_4();
extern "C" void _s8023C168_5();
extern "C" void _s8023C168_6();
extern "C" void _s8023C168_7();
extern "C" void f_8023C168() {}
