// 0x801F0EFC INVTarget::SetAllObjectRelatedCheatStrings(ObjSelector (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; mr 3,4; addi 29,30,4491; bl _s801F0EFC_0; mr 31,3; lwz 28,0x38(31); addi 3,1,8; mr 4,31; crxor 6,6,6; bl _s801F0EFC_1; lwz 9,0x8(1); li 6,0; cmpwi 9,0; beq 0f; lwz 6,0x0(9); 0:; mr 4,29; mr 3,30; li 5,2048; bl _s801F0EFC_2; lwz 6,0x14(31); mr 3,30; addi 4,30,6539; li 5,2048; bl _s801F0EFC_3; mr 3,30; lhz 6,0x24(28); addi 4,3,8587; li 5,2048; bl _s801F0EFC_4; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s801F0EFC_0();
extern "C" void _s801F0EFC_1();
extern "C" void _s801F0EFC_2();
extern "C" void _s801F0EFC_3();
extern "C" void _s801F0EFC_4();
extern "C" void f_801F0EFC() {}
