// 0x800D3CD0 NghResFile::GetByIndex(int, (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,5; bl _s800D3CD0_0; lwz 3,0x0(3); li 9,1; cmpwi 3,0; beq 2f; 0:; cmpw 9,30; bne 1f; stw 3,0x180(31); lwz 3,0x4(3); b 3f; 1:; lwz 3,0x0(3); addi 0,9,1; extsh 9,0; cmpwi 3,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800D3CD0_0();
extern "C" void f_800D3CD0() {}
