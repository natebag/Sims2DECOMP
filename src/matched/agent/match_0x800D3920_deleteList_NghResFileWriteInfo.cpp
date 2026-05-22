// 0x800D3920 deleteList(NghResFileWriteInfo (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; b 3f; 0:; lwz 30,0x0(30); cmpwi 29,0; beq 3f; lwz 31,0x4(29); cmpwi 31,0; beq 2f; lwz 0,0x8(31); cmpwi 0,0; beq 1f; bl _s800D3920_0; lwz 4,0x4(31); bl _s800D3920_1; 1:; bl _s800D3920_2; mr 4,31; bl _s800D3920_3; 2:; mr 3,29; bl _s800D3920_4; 3:; mr 29,30; cmpwi 30,0; bne 0b; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800D3920_0();
extern "C" void _s800D3920_1();
extern "C" void _s800D3920_2();
extern "C" void _s800D3920_3();
extern "C" void _s800D3920_4();
extern "C" void f_800D3920() {}
