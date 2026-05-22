// 0x803A1864 TheSimsStateMachine::~TheSimsStateMachine(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,-7936; mr 30,4; stw 9,0x18(31); addi 3,31,84; li 4,2; bl _s803A1864_0; lwz 3,0x2c(31); addi 9,31,44; cmpwi 3,0; beq 1f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s803A1864_1; b 1f; 0:; bl _s803A1864_2; 1:; lis 9,-32698; andi. 0,30,1; addi 9,9,-13880; stw 9,0x18(31); beq 2f; mr 3,31; bl _s803A1864_3; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803A1864_0();
extern "C" void _s803A1864_1();
extern "C" void _s803A1864_2();
extern "C" void _s803A1864_3();
extern "C" void f_803A1864() {}
