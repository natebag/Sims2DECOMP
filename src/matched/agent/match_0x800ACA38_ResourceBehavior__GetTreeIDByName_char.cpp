// 0x800ACA38 ResourceBehavior::GetTreeIDByName(char (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 3,0x10(31); bl _s800ACA38_0; mr. 3,3; bne 1f; lwz 0,0x14(31); cmpwi 0,0; beq 0f; mr 3,0; mr 4,30; bl _s800ACA38_1; 0:; cmpwi 3,0; bne 1f; lwz 3,0x18(31); mr 4,30; bl _s800ACA38_2; 1:; extsh 3,3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800ACA38_0();
extern "C" void _s800ACA38_1();
extern "C" void _s800ACA38_2();
extern "C" void f_800ACA38() {}
