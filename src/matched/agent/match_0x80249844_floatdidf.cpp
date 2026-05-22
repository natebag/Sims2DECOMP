// 0x80249844 __floatdidf (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mr 10,3; xoris 0,10,32768; lis 6,17200; stw 0,0xc(1); mr 7,8; lis 11,-32704; lis 9,-32704; stw 6,0x8(1); lis 10,-32704; lfd f12,0x238(11); lfd f0,0x8(1); stw 4,0xc(1); lfd f11,0x240(9); fsub f0,f0,f12; stw 6,0x8(1); lfd f13,0x248(10); fmul f0,f0,f11,f0; lfd f1,0x8(1); fsub f1,f1,f13; fmadd f1,f0,f11,f1; addi 1,1,16"
extern "C" void f_80249844() {}
