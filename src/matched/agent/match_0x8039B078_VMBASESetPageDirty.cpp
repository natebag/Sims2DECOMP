// 0x8039B078 VMBASESetPageDirty (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); stw 31,0x1c(1); stw 30,0x18(1); mr 30,4; stw 29,0x14(1); mr 29,3; bl _s8039B078_0; mr 0,3; mr 3,29; mr 31,0; bl _s8039B078_1; cmpwi 30,0; beq 0f; lwz 0,0x4(3); ori 0,0,128; stw 0,0x4(3); b 1f; 0:; lwz 0,0x4(3); rlwinm 0,0,0,25,23; stw 0,0x4(3); 1:; addi 3,3,4; li 4,4; bl _s8039B078_2; mr 3,29; bl _s8039B078_3; mr 3,31; bl _s8039B078_4; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s8039B078_0();
extern "C" void _s8039B078_1();
extern "C" void _s8039B078_2();
extern "C" void _s8039B078_3();
extern "C" void _s8039B078_4();
extern "C" void f_8039B078() {}
