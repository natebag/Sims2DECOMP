// 0x800A5A14 WriteHandleToFile(Memory::HandleNode (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lis 9,-32706; mr 3,4; addi 4,9,-28496; bl _s800A5A14_0; mr. 29,3; li 3,-1; beq 1f; lwz 3,0x4(30); cmpwi 30,0; li 31,0; beq 0f; lwz 31,0x0(30); 0:; li 4,1; mr 5,31; mr 6,29; bl _s800A5A14_1; mr 30,3; mr 3,29; bl _s800A5A14_2; cmpw 30,31; li 3,-1; bne 1f; li 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A5A14_0();
extern "C" void _s800A5A14_1();
extern "C" void _s800A5A14_2();
extern "C" void f_800A5A14() {}
