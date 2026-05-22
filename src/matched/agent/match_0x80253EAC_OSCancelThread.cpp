// 0x80253EAC OSCancelThread (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); mr 30,3; stw 29,0x14(1); bl _s80253EAC_0; lhz 0,0x2c8(30); addi 31,3,0; cmpwi 0,3; beq 9f; bge 0f; cmpwi 0,1; beq 1f; bge 2f; b 9f; 0:; cmpwi 0,5; bge 9f; b 3f; 1:; lwz 0,0x2cc(30); cmpwi 0,0; bgt 10f; mr 3,30; bl _s80253EAC_1; b 10f; 2:; li 0,1; stw 0,-23580(13); b 10f; 3:; lwz 4,0x2e0(30); lwz 5,0x2e4(30); cmplwi 4,0; bne 4f; lwz 3,0x2dc(30); stw 5,0x4(3); b 5f; 4:; stw 5,0x2e4(4); 5:; cmplwi 5,0; bne 6f; lwz 3,0x2dc(30); stw 4,0x0(3); b 7f; 6:; stw 4,0x2e0(5); 7:; li 0,0; stw 0,0x2dc(30); lwz 0,0x2cc(30); cmpwi 0,0; bgt 10f; lwz 3,0x2f0(30); cmplwi 3,0; beq 10f; lwz 29,0x8(3); 8:; lwz 0,0x2cc(29); cmpwi 0,0; bgt 10f; mr 3,29; bl _s80253EAC_2; lwz 0,0x2d0(29); addi 4,3,0; cmpw 0,4; beq 10f; mr 3,29; bl _s80253EAC_3; mr. 29,3; bne 8b; b 10f; 9:; mr 3,31; bl _s80253EAC_4; b 18f; 10:; mr 3,30; bl _s80253EAC_5; lhz 0,0x2ca(30); rlwinm. 0,0,0,31,31; beq 15f; lwz 4,0x2fc(30); lwz 5,0x300(30); cmplwi 4,0; bne 11f; lis 3,-32768; stw 5,0xe0(3); b 12f; 11:; stw 5,0x300(4); 12:; cmplwi 5,0; bne 13f; lis 3,-32768; stw 4,0xdc(3); b 14f; 13:; stw 4,0x2fc(5); 14:; li 0,0; sth 0,0x2c8(30); b 16f; 15:; li 0,8; sth 0,0x2c8(30); 16:; mr 3,30; bl _s80253EAC_6; addi 3,30,744; bl _s80253EAC_7; lwz 0,-23580(13); cmpwi 0,0; beq 17f; li 3,0; bl _s80253EAC_8; 17:; mr 3,31; bl _s80253EAC_9; 18:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80253EAC_0();
extern "C" void _s80253EAC_1();
extern "C" void _s80253EAC_2();
extern "C" void _s80253EAC_3();
extern "C" void _s80253EAC_4();
extern "C" void _s80253EAC_5();
extern "C" void _s80253EAC_6();
extern "C" void _s80253EAC_7();
extern "C" void _s80253EAC_8();
extern "C" void _s80253EAC_9();
extern "C" void f_80253EAC() {}
