// 0x802E185C ENgcFile::ENgcFile(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s802E185C_0; lis 9,-32697; addi 9,9,-23304; stw 9,0x28(30); bl _s802E185C_1; li 4,4096; li 5,2048; li 6,0; li 7,0; bl _s802E185C_2; stw 3,0x6c(30); mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E185C_0();
extern "C" void _s802E185C_1();
extern "C" void _s802E185C_2();
extern "C" void f_802E185C() {}
