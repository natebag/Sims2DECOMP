// 0x802D7C48 ENgcSNFile::ENgcSNFile(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s802D7C48_0; lis 9,-32697; addi 9,9,-23688; stw 9,0x28(30); bl _s802D7C48_1; li 4,2048; li 5,32; li 6,0; li 7,0; bl _s802D7C48_2; stw 3,0x34(30); mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D7C48_0();
extern "C" void _s802D7C48_1();
extern "C" void _s802D7C48_2();
extern "C" void f_802D7C48() {}
