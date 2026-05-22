// 0x80135634 iResFile::Release(Memory::HandleNode (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; lwz 9,0xc(30); lha 3,0xd8(9); lwz 0,0xdc(9); add 3,30,3; mtspr 8,0; blrl; mr 3,30; bl _s80135634_0; cmpwi 3,0; bne 1f; cmpwi 31,0; beq 1f; lwz 0,0x8(31); cmpwi 0,0; beq 0f; bl _s80135634_1; lwz 4,0x4(31); bl _s80135634_2; 0:; bl _s80135634_3; mr 4,31; bl _s80135634_4; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80135634_0();
extern "C" void _s80135634_1();
extern "C" void _s80135634_2();
extern "C" void _s80135634_3();
extern "C" void _s80135634_4();
extern "C" void f_80135634() {}
