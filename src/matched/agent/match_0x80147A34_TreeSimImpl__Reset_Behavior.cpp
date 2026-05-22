// 0x80147A34 TreeSimImpl::Reset(Behavior (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 30,5; mr 29,4; addi 3,31,12; bl _s80147A34_0; cmpwi 30,0; beq 0f; li 9,0; mr 4,29; li 10,0; mr 6,30; stw 9,0x8(1); stw 10,0xc(1); mr 3,31; addi 5,1,8; bl _s80147A34_1; li 0,0; sth 0,0x34(31); 0:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80147A34_0();
extern "C" void _s80147A34_1();
extern "C" void f_80147A34() {}
