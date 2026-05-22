// 0x802544D0 OSSuspendThread (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 29,3; bl _s802544D0_0; lwz 4,0x2cc(29); addi 31,3,0; addi 0,4,1; mr. 30,4; stw 0,0x2cc(29); bne 12f; lhz 0,0x2c8(29); cmpwi 0,3; beq 11f; bge 0f; cmpwi 0,1; beq 2f; bge 1f; b 11f; 0:; cmpwi 0,5; bge 11f; b 3f; 1:; li 0,1; stw 0,-23580(13); sth 0,0x2c8(29); b 11f; 2:; mr 3,29; bl _s802544D0_1; b 11f; 3:; lwz 4,0x2e0(29); lwz 5,0x2e4(29); cmplwi 4,0; bne 4f; lwz 3,0x2dc(29); stw 5,0x4(3); b 5f; 4:; stw 5,0x2e4(4); 5:; cmplwi 5,0; bne 6f; lwz 3,0x2dc(29); stw 4,0x0(3); b 7f; 6:; stw 4,0x2e0(5); 7:; li 0,32; stw 0,0x2d0(29); lwz 4,0x2dc(29); lwz 3,0x4(4); cmplwi 3,0; bne 8f; stw 29,0x0(4); b 9f; 8:; stw 29,0x2e0(3); 9:; stw 3,0x2e4(29); li 0,0; stw 0,0x2e0(29); lwz 3,0x2dc(29); stw 29,0x4(3); lwz 3,0x2f0(29); cmplwi 3,0; beq 11f; lwz 29,0x8(3); 10:; lwz 0,0x2cc(29); cmpwi 0,0; bgt 11f; mr 3,29; bl _s802544D0_2; lwz 0,0x2d0(29); addi 4,3,0; cmpw 0,4; beq 11f; mr 3,29; bl _s802544D0_3; mr. 29,3; bne 10b; 11:; lwz 0,-23580(13); cmpwi 0,0; beq 12f; li 3,0; bl _s802544D0_4; 12:; mr 3,31; bl _s802544D0_5; mr 3,30; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s802544D0_0();
extern "C" void _s802544D0_1();
extern "C" void _s802544D0_2();
extern "C" void _s802544D0_3();
extern "C" void _s802544D0_4();
extern "C" void _s802544D0_5();
extern "C" void f_802544D0() {}
