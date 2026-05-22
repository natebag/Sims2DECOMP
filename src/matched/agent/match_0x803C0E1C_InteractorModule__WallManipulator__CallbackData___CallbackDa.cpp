// 0x803C0E1C InteractorModule::WallManipulator::CallbackData::~CallbackData(void) (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; addi 11,31,52; lwz 9,0x34(31); lwz 0,0x4(11); cmpw 9,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(11); cmpwi 3,0; beq 3f; lwz 0,0xc(11); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 2f; bl _s803C0E1C_0; b 3f; 2:; bl _s803C0E1C_1; 3:; addi 11,31,36; lwz 9,0x24(31); lwz 0,0x4(11); addi 30,31,20; cmpw 9,0; beq 5f; 4:; addi 9,9,8; cmpw 9,0; bne 4b; 5:; lwz 3,0x0(11); cmpwi 3,0; beq 7f; lwz 0,0xc(11); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 6f; bl _s803C0E1C_2; b 7f; 6:; bl _s803C0E1C_3; 7:; lwz 0,0x4(30); lwz 9,0x14(31); cmpw 9,0; beq 9f; 8:; addi 9,9,8; cmpw 9,0; bne 8b; 9:; lwz 3,0x0(30); cmpwi 3,0; beq 11f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 10f; bl _s803C0E1C_4; b 11f; 10:; bl _s803C0E1C_5; 11:; lis 9,-32697; andi. 0,29,1; addi 9,9,-32168; stw 9,0x8(31); beq 12f; mr 3,31; bl _s803C0E1C_6; 12:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803C0E1C_0();
extern "C" void _s803C0E1C_1();
extern "C" void _s803C0E1C_2();
extern "C" void _s803C0E1C_3();
extern "C" void _s803C0E1C_4();
extern "C" void _s803C0E1C_5();
extern "C" void _s803C0E1C_6();
extern "C" void f_803C0E1C() {}
