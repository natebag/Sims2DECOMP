// 0x803A02CC Memory::HandleNode (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); lis 9,-32698; addi 30,1,8; addi 9,9,-13808; stw 3,0xc(1); stw 9,0x8(1); addi 3,1,24; stw 4,0x8(30); mr 4,30; bl _s803A02CC_0; mr 29,3; li 4,2; mr 3,30; bl _s803A02CC_1; mr 3,29; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s803A02CC_0();
extern "C" void _s803A02CC_1();
extern "C" void f_803A02CC() {}
