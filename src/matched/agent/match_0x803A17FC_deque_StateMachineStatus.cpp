// 0x803A17FC deque<StateMachineStatus (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x14(31); cmpwi 3,0; beq 0f; li 4,128; bl _s803A17FC_0; 0:; lwz 10,0x1c(31); addi 11,31,16; addi 0,10,-4; stw 0,0xc(11); lwz 9,-4(10); addi 0,9,128; stw 9,0x4(11); stw 0,0x8(11); lwz 9,0x18(31); addi 9,9,-4; stw 9,0x10(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s803A17FC_0();
extern "C" void f_803A17FC() {}
