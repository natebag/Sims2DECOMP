// 0x800E2544 cXObjectImpl::GetRequiredSegment(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x3a0(9); lwz 9,0x3a4(9); add 3,3,0; mtspr 8,9; blrl; andi. 3,3,5; cmpwi 3,1; beq 0f; ble 2f; cmpwi 3,4; beq 1f; b 2f; 0:; li 30,2; b 2f; 1:; li 30,8; 2:; cmpwi 30,0; beq 3f; addi 31,31,40; li 4,1; mr 3,31; bl _s800E2544_0; lha 0,0x0(3); cmpwi 0,0; beq 3f; li 4,1; mr 3,31; bl _s800E2544_1; lha 4,0x0(3); mr 3,30; rlwinm 0,4,1,31,31; add 4,4,0; srawi 4,4,1; bl _s800E2544_2; mr 30,3; 3:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800E2544_0();
extern "C" void _s800E2544_1();
extern "C" void _s800E2544_2();
extern "C" void f_800E2544() {}
