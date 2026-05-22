// 0x803A8B60 PassiveInfluenceObject::~PassiveInfluenceObject(void) (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); lis 9,-32698; mr 31,3; addi 9,9,8840; mr 30,4; stw 9,0x0(31); addi 5,1,8; li 0,0; addi 8,5,8; stw 0,0x8(1); addi 7,31,8; stw 0,0x4(5); addi 6,7,8; stw 0,0x4(8); lwz 0,0xc(31); lwz 9,0x8(31); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x8(31); lwz 0,0x4(8); stw 10,0xc(31); stw 0,0x24(1); lwz 9,0x8(7); lwz 0,0x4(6); stw 9,0x8(5); stw 0,0x4(8); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x8(7); stw 0,0x4(6); lwz 0,0x4(5); lwz 9,0x8(1); cmpw 9,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(5); cmpwi 3,0; beq 3f; lwz 0,0xc(5); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 2f; bl _s803A8B60_0; b 3f; 2:; bl _s803A8B60_1; 3:; addi 11,31,8; lwz 9,0x8(31); lwz 0,0x4(11); cmpw 9,0; beq 5f; 4:; addi 9,9,8; cmpw 9,0; bne 4b; 5:; lwz 3,0x0(11); cmpwi 3,0; beq 7f; lwz 0,0xc(11); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 6f; bl _s803A8B60_2; b 7f; 6:; bl _s803A8B60_3; 7:; lis 9,-32698; andi. 0,30,1; addi 9,9,8984; stw 9,0x0(31); beq 8f; mr 3,31; bl _s803A8B60_4; 8:; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"
extern "C" void _s803A8B60_0();
extern "C" void _s803A8B60_1();
extern "C" void _s803A8B60_2();
extern "C" void _s803A8B60_3();
extern "C" void _s803A8B60_4();
extern "C" void f_803A8B60() {}
