// 0x80110368 ObjResFile::ObjResFile(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80110368_0; lis 9,-32698; mr 3,30; addi 9,9,8536; stw 9,0xc(30); bl _s80110368_1; lis 5,-32706; mr 3,30; addi 5,5,-15692; li 4,2; bl _s80110368_2; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80110368_0();
extern "C" void _s80110368_1();
extern "C" void _s80110368_2();
extern "C" void f_80110368() {}
