// 0x800C879C TArray<ENDummyPoint, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 9,0x8(11); lwz 11,0x8(1); lwz 3,0xc(11); b 2f; lwz 0,0x4(25); li 9,1; stw 9,0x18(1); li 3,20; stw 0,0x38(1); sth 29,0x10(1); bl _s800C879C_0; lhz 0,0x10(1); mr 30,3; addi 31,30,8; sth 0,0x8(30); lwz 11,0x14(1); stw 11,0xc(30); cmpwi 11,0; beq 0f; lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x18(1); stw 0,0x8(31); lwz 9,0x38(1); lwz 11,0x4(9); stw 9,0x0(30); stw 11,0x4(30); stw 30,0x0(11); stw 30,0x4(9); stw 30,0x30(1); lwz 30,0x14(1); cmpwi 30,0; beq 1f; lwz 9,0x0(30); lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; 1:; mr 3,30; 2:; lwz 0,0xac(1); mtspr 8,0; lmw 23,0x84(1); addi 1,1,168; blr; lwz 3,0x30(3)"
extern "C" void _s800C879C_0();
extern "C" void f_800C879C() {}
