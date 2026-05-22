// 0x803A8D6C PassiveInfluenceTarget::~PassiveInfluenceTarget(void) (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); lis 9,-32698; mr 31,3; addi 9,9,8936; mr 29,4; stw 9,0x0(31); addi 5,1,8; li 0,0; addi 8,5,8; stw 0,0x8(1); addi 7,31,8; stw 0,0x4(5); addi 6,7,8; stw 0,0x4(8); lwz 0,0xc(31); lwz 9,0x8(31); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x8(31); lwz 0,0x4(8); stw 10,0xc(31); stw 0,0x24(1); lwz 9,0x8(7); lwz 0,0x4(6); stw 9,0x8(5); stw 0,0x4(8); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x8(7); stw 0,0x4(6); lwz 0,0x4(5); lwz 9,0x8(1); cmpw 9,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(5); cmpwi 3,0; beq 3f; lwz 0,0xc(5); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 2f; bl _s803A8D6C_0; b 3f; 2:; bl _s803A8D6C_1; 3:; addi 30,31,28; mr 3,30; bl _s803A8D6C_2; mr 3,30; bl _s803A8D6C_3; lwz 3,0x4(30); cmpwi 3,0; beq 4f; li 4,16; bl _s803A8D6C_4; 4:; addi 11,31,8; lwz 9,0x8(31); lwz 0,0x4(11); cmpw 9,0; beq 6f; 5:; addi 9,9,8; cmpw 9,0; bne 5b; 6:; lwz 3,0x0(11); cmpwi 3,0; beq 8f; lwz 0,0xc(11); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 7f; bl _s803A8D6C_5; b 8f; 7:; bl _s803A8D6C_6; 8:; lis 9,-32698; andi. 0,29,1; addi 9,9,8984; stw 9,0x0(31); beq 9f; mr 3,31; bl _s803A8D6C_7; 9:; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s803A8D6C_0();
extern "C" void _s803A8D6C_1();
extern "C" void _s803A8D6C_2();
extern "C" void _s803A8D6C_3();
extern "C" void _s803A8D6C_4();
extern "C" void _s803A8D6C_5();
extern "C" void _s803A8D6C_6();
extern "C" void _s803A8D6C_7();
extern "C" void f_803A8D6C() {}
