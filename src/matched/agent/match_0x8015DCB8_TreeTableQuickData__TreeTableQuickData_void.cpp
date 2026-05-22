// 0x8015DCB8 TreeTableQuickData::TreeTableQuickData(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); lis 9,-32698; mr 30,3; li 29,0; addi 9,9,23400; stw 9,0x0(30); addi 11,30,8; stw 29,0x4(30); addi 9,11,8; stw 29,0x8(30); addi 3,30,24; stw 29,0x4(11); li 4,0; stw 29,0x4(9); li 5,0; bl _s8015DCB8_0; stw 29,0x20(30); mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8015DCB8_0();
extern "C" void f_8015DCB8() {}
