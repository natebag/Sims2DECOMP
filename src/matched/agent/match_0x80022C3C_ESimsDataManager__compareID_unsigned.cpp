// 0x80022C3C ESimsDataManager::compareID(unsigned (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); li 0,0; mr 29,4; stw 0,0x10(1); lis 30,-32693; stw 0,0x8(1); addi 30,30,24536; addi 5,1,8; addi 6,1,12; lwz 4,0x0(3); mr 3,30; bl _s80022C3C_0; lwz 4,0x0(29); mr 3,30; addi 5,1,16; addi 6,1,20; bl _s80022C3C_1; lwz 0,0x8(1); lwz 3,0x10(1); subfc 3,3,0; subfe 3,3,3; neg 3,3; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80022C3C_0();
extern "C" void _s80022C3C_1();
extern "C" void f_80022C3C() {}
