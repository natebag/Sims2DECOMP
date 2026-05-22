// 0x8023C908 XmlConvEpoch2Date (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 25,0x34(1); stw 0,0x54(1); mr 30,4; mr 29,5; mr 4,3; mr 28,6; mr 27,7; mr 26,8; mr 25,9; addi 3,1,8; bl _s8023C908_0; li 31,-1; cmpwi 3,0; beq 6f; cmpwi 30,0; beq 0f; lwz 0,0x1c(1); stw 0,0x0(30); 0:; cmpwi 29,0; beq 1f; lwz 0,0x18(1); stw 0,0x0(29); 1:; cmpwi 28,0; beq 2f; lwz 0,0x14(1); stw 0,0x0(28); 2:; cmpwi 27,0; beq 3f; lwz 0,0x10(1); stw 0,0x0(27); 3:; cmpwi 26,0; beq 4f; lwz 0,0xc(1); stw 0,0x0(26); 4:; cmpwi 25,0; beq 5f; lwz 0,0x8(1); stw 0,0x0(25); 5:; li 31,0; 6:; mr 3,31; lwz 0,0x54(1); mtspr 8,0; lmw 25,0x34(1); addi 1,1,80"
extern "C" void _s8023C908_0();
extern "C" void f_8023C908() {}
