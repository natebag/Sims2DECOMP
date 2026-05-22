// 0x802C6964 EFileSystem::EFileSystem(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; addi 9,9,-24288; stw 9,0x0(30); li 4,3; bl _s802C6964_0; lis 9,-32697; addi 3,30,4; addi 9,9,-24376; stw 9,0x0(30); bl _s802C6964_1; li 9,4; li 0,0; stw 0,0x14(30); mr 3,30; stw 9,0x20(30); stw 9,0x18(30); stw 9,0x1c(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802C6964_0();
extern "C" void _s802C6964_1();
extern "C" void f_802C6964() {}
