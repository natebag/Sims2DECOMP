// 0x803C49A0 TArray<BSplineVolume, (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; mr 29,4; mr. 27,5; bne 0f; mr 27,29; 0:; lwz 26,0x4(31); cmpw 29,26; bge 1f; mulli 0,29,224; lwz 3,0x0(31); subf 4,29,26; add 3,3,0; bl _s803C49A0_0; 1:; cmpwi 27,0; bne 2f; lis 3,-32692; lwz 4,0x0(31); addi 3,3,-27556; bl _s803C49A0_1; mr 3,31; bl _s803C49A0_2; b 6f; 2:; lwz 0,0x8(31); cmpw 0,27; beq 5f; mulli 4,27,224; lis 25,-32692; addi 3,25,-27556; li 5,16; bl _s803C49A0_3; mr. 28,3; beq 6f; lwz 0,0x0(31); cmpwi 0,0; beq 4f; lwz 0,0x4(31); mr 30,29; cmpw 29,0; ble 3f; mr 30,0; 3:; mr 3,28; mr 4,30; bl _s803C49A0_4; lwz 4,0x0(31); mr 5,30; mr 3,28; bl _s803C49A0_5; lwz 3,0x0(31); lwz 4,0x4(31); bl _s803C49A0_6; lwz 4,0x0(31); addi 3,25,-27556; bl _s803C49A0_7; 4:; stw 28,0x0(31); stw 27,0x8(31); 5:; stw 29,0x4(31); 6:; cmpw 29,26; ble 7f; mulli 0,26,224; lwz 3,0x0(31); subf 4,26,29; add 3,3,0; bl _s803C49A0_8; 7:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s803C49A0_0();
extern "C" void _s803C49A0_1();
extern "C" void _s803C49A0_2();
extern "C" void _s803C49A0_3();
extern "C" void _s803C49A0_4();
extern "C" void _s803C49A0_5();
extern "C" void _s803C49A0_6();
extern "C" void _s803C49A0_7();
extern "C" void _s803C49A0_8();
extern "C" void f_803C49A0() {}
