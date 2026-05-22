// 0x802EC4B4 EAnimController::DestroyStreams(EACTrack (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr. 26,4; beq 4f; lwz 0,0x98(26); cmpwi 0,0; beq 4f; lwz 3,0x24(3); cmpwi 3,0; beq 0f; lwz 3,0x18(3); b 1f; 0:; li 3,0; 1:; cmpwi 3,0; ble 3f; mr 27,3; li 31,0; li 28,0; 2:; lwz 30,0x98(26); lwzx 3,30,28; add 29,30,28; bl _s802EC4B4_0; stwx 31,30,28; addi 28,28,32; lwz 3,0x8(29); bl _s802EC4B4_1; lwz 3,0x4(29); stw 31,0x8(29); bl _s802EC4B4_2; lwz 3,0xc(29); stw 31,0x4(29); bl _s802EC4B4_3; lwz 3,0x10(29); stw 31,0xc(29); bl _s802EC4B4_4; lwz 3,0x14(29); stw 31,0x10(29); bl _s802EC4B4_5; lwz 3,0x18(29); stw 31,0x14(29); bl _s802EC4B4_6; stw 31,0x18(29); lwz 3,0x1c(29); bl _s802EC4B4_7; stw 31,0x1c(29); addic. 27,27,-1; bne 2b; 3:; bl _s802EC4B4_8; lwz 4,0x98(26); bl _s802EC4B4_9; li 0,0; stw 0,0x98(26); 4:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s802EC4B4_0();
extern "C" void _s802EC4B4_1();
extern "C" void _s802EC4B4_2();
extern "C" void _s802EC4B4_3();
extern "C" void _s802EC4B4_4();
extern "C" void _s802EC4B4_5();
extern "C" void _s802EC4B4_6();
extern "C" void _s802EC4B4_7();
extern "C" void _s802EC4B4_8();
extern "C" void _s802EC4B4_9();
extern "C" void f_802EC4B4() {}
