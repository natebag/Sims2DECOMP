// 0x8021F648 InteractorModule::WallManipulator::~WallManipulator(void) (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; lis 11,-32697; lwz 3,0xa8(31); lis 9,-32698; addi 11,11,-30832; addi 9,9,-10560; addi 10,31,168; mr 28,4; stw 11,0x5c(31); cmpwi 3,0; stw 9,0xf0(31); beq 1f; lwz 0,0xc(10); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s8021F648_0; b 1f; 0:; bl _s8021F648_1; 1:; addi 11,31,152; lwz 9,0x98(31); lwz 0,0x4(11); addi 30,31,136; addi 29,31,120; cmpw 9,0; beq 3f; 2:; addi 9,9,8; cmpw 9,0; bne 2b; 3:; lwz 3,0x0(11); cmpwi 3,0; beq 5f; lwz 0,0xc(11); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 4f; bl _s8021F648_2; b 5f; 4:; bl _s8021F648_3; 5:; lwz 0,0x4(30); lwz 9,0x88(31); cmpw 9,0; beq 7f; 6:; addi 9,9,8; cmpw 9,0; bne 6b; 7:; lwz 3,0x0(30); cmpwi 3,0; beq 9f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 8f; bl _s8021F648_4; b 9f; 8:; bl _s8021F648_5; 9:; lwz 0,0x4(29); lwz 9,0x78(31); cmpw 9,0; beq 11f; 10:; addi 9,9,8; cmpw 9,0; bne 10b; 11:; lwz 3,0x0(29); cmpwi 3,0; beq 13f; lwz 0,0xc(29); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 12f; bl _s8021F648_6; b 13f; 12:; bl _s8021F648_7; 13:; lis 9,-32697; andi. 0,28,1; addi 9,9,-32144; stw 9,0x5c(31); beq 14f; mr 3,31; bl _s8021F648_8; 14:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8021F648_0();
extern "C" void _s8021F648_1();
extern "C" void _s8021F648_2();
extern "C" void _s8021F648_3();
extern "C" void _s8021F648_4();
extern "C" void _s8021F648_5();
extern "C" void _s8021F648_6();
extern "C" void _s8021F648_7();
extern "C" void _s8021F648_8();
extern "C" void f_8021F648() {}
