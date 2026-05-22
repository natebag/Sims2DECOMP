// 0x8024EBA4 LoadDol (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-96(1); stw 31,0x5c(1); stw 30,0x58(1); mr 30,3; mr 12,4; addi 3,1,84; addi 4,1,80; addi 5,1,76; mtspr 8,12; blrl; li 3,28; li 4,1; bl _s8024EBA4_0; mr 31,3; mr 3,31; mr 4,30; li 5,28; bl _s8024EBA4_1; lis 4,-32768; lwz 12,0x54(1); lis 3,-32731; stw 31,0x30f0(4); addi 3,3,-8416; mtspr 8,12; blrl; mr 3,31; bl _s8024EBA4_2; b 0f; 0:; b 1f; 1:; b 7f; 2:; lwz 6,0x40(1); addi 3,1,16; lwz 5,0x44(1); li 7,0; lwz 4,0x48(1); li 8,0; bl _s8024EBA4_3; b 3f; 3:; b 4f; 4:; b 6f; 5:; bl _s8024EBA4_4; cmpwi 3,0; bne 6f; li 3,0; bl _s8024EBA4_5; 6:; addi 3,1,16; bl _s8024EBA4_6; cmpwi 3,0; bne 5b; 7:; lwz 12,0x50(1); addi 3,1,72; addi 4,1,68; addi 5,1,64; mtspr 8,12; blrl; cmpwi 3,0; bne 2b; lwz 12,0x4c(1); mtspr 8,12; blrl; lwz 0,0x64(1); lwz 31,0x5c(1); lwz 30,0x58(1); addi 1,1,96; mtspr 8,0"
extern "C" void _s8024EBA4_0();
extern "C" void _s8024EBA4_1();
extern "C" void _s8024EBA4_2();
extern "C" void _s8024EBA4_3();
extern "C" void _s8024EBA4_4();
extern "C" void _s8024EBA4_5();
extern "C" void _s8024EBA4_6();
extern "C" void f_8024EBA4() {}
