// 0x800A3374 BString2::c_str(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s800A3374_0; cmpwi 3,0; beq 0f; lwz 9,0x0(31); lwz 3,0x0(9); b 1f; 0:; li 3,0; 1:; cmpwi 3,0; bne 2f; lis 3,-32706; addi 3,3,-28616; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800A3374_0();
extern "C" void f_800A3374() {}
