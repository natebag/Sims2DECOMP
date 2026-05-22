// 0x800F239C UserDataSaveLoad::DoStream(ReconBuffer (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 29,0x8c(1); stw 0,0x9c(1); mr 31,3; mr 30,4; mr 29,5; mr 3,30; mr 4,31; li 5,1; bl _s800F239C_0; mr 5,29; addi 3,31,4; mr 4,30; bl _s800F239C_1; lis 9,-32697; lis 5,-32706; lwz 11,-6536(9); addi 5,5,-19168; lwz 7,0x0(31); addi 3,1,8; lwz 6,0x0(11); li 4,128; crxor 6,6,6; bl _s800F239C_2; lwz 0,0xc(30); cmpwi 0,0; bne 2f; lis 3,-32697; lwz 4,0x0(31); addi 3,3,24012; bl _s800F239C_3; mr. 30,3; beq 2f; lwz 9,0x10(30); addi 3,31,8; li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; li 5,32; bl _s800F239C_4; lwz 3,0x14(30); addi 4,31,72; li 0,0; cmpwi 3,0; beq 1f; lwz 0,0x0(3); 1:; mr 3,4; li 5,32; mr 4,0; bl _s800F239C_5; 2:; lwz 0,0x9c(1); mtspr 8,0; lmw 29,0x8c(1); addi 1,1,152"
extern "C" void _s800F239C_0();
extern "C" void _s800F239C_1();
extern "C" void _s800F239C_2();
extern "C" void _s800F239C_3();
extern "C" void _s800F239C_4();
extern "C" void _s800F239C_5();
extern "C" void f_800F239C() {}
