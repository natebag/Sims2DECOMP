// 0x803104DC EResourceLoaderImpl::FlushCommandQueue(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; lwz 9,0x0(31); lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; addi 30,1,8; mr 3,30; bl _s803104DC_0; li 5,0; li 4,1; mr 3,30; bl _s803104DC_1; li 3,40; bl _s803104DC_2; bl _s803104DC_3; mr 9,3; li 0,1; mr 4,9; stw 0,0x0(9); stw 30,0x1c(9); mr 3,31; bl _s803104DC_4; li 4,-1; mr 3,30; bl _s803104DC_5; mr 3,30; bl _s803104DC_6; mr 3,30; li 4,2; bl _s803104DC_7; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s803104DC_0();
extern "C" void _s803104DC_1();
extern "C" void _s803104DC_2();
extern "C" void _s803104DC_3();
extern "C" void _s803104DC_4();
extern "C" void _s803104DC_5();
extern "C" void _s803104DC_6();
extern "C" void _s803104DC_7();
extern "C" void f_803104DC() {}
