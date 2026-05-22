// 0x803B30DC _Deque_base<int, (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x24(31); cmpwi 0,0; beq 1f; lwz 5,0x1c(31); lwz 4,0xc(31); addi 5,5,4; bl _s803B30DC_0; lwz 3,0x24(31); lwz 4,0x2c(31); cmpwi 3,0; beq 1f; rlwinm 4,4,2,0,29; cmplwi 4,128; ble 0f; bl _s803B30DC_1; b 1f; 0:; bl _s803B30DC_2; 1:; andi. 0,30,1; beq 2f; mr 3,31; bl _s803B30DC_3; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803B30DC_0();
extern "C" void _s803B30DC_1();
extern "C" void _s803B30DC_2();
extern "C" void _s803B30DC_3();
extern "C" void f_803B30DC() {}
