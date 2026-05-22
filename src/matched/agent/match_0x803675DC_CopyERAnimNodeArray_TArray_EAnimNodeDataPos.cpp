// 0x803675DC CopyERAnimNodeArray(TArray<EAnimNodeDataPos, (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,4; mr 30,3; li 5,4; addi 3,1,8; mr 27,31; bl _s803675DC_0; li 28,0; lwz 4,0x8(1); mr 3,30; li 5,0; addi 31,31,4; bl _s803675DC_1; lwz 0,0x8(1); cmpw 28,0; bge 1f; li 29,0; 0:; lwz 3,0x0(30); mr 4,31; li 5,4; addi 31,31,4; add 3,3,29; addi 28,28,1; addi 3,3,4; bl _s803675DC_2; lwz 3,0x0(30); mr 4,31; li 5,4; addi 31,31,4; add 3,3,29; addi 3,3,8; bl _s803675DC_3; lwz 3,0x0(30); mr 4,31; li 5,4; addi 31,31,4; add 3,3,29; addi 3,3,12; bl _s803675DC_4; lwz 3,0x0(30); mr 4,31; li 5,4; addi 31,31,4; add 3,3,29; addi 3,3,16; bl _s803675DC_5; lwz 3,0x0(30); mr 4,31; li 5,4; addi 31,31,4; add 3,3,29; addi 3,3,20; bl _s803675DC_6; lwz 3,0x0(30); mr 4,31; li 5,4; addi 31,31,4; add 3,3,29; addi 3,3,24; bl _s803675DC_7; lwz 3,0x0(30); mr 4,31; li 5,4; addi 31,31,4; add 3,3,29; addi 3,3,28; bl _s803675DC_8; lwz 3,0x0(30); mr 4,31; li 5,4; addi 31,31,4; add 3,3,29; addi 3,3,32; addi 29,29,36; bl _s803675DC_9; lwz 0,0x8(1); cmpw 28,0; blt 0b; 1:; subf 3,27,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s803675DC_0();
extern "C" void _s803675DC_1();
extern "C" void _s803675DC_2();
extern "C" void _s803675DC_3();
extern "C" void _s803675DC_4();
extern "C" void _s803675DC_5();
extern "C" void _s803675DC_6();
extern "C" void _s803675DC_7();
extern "C" void _s803675DC_8();
extern "C" void _s803675DC_9();
extern "C" void f_803675DC() {}
