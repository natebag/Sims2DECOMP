// 0x800B54D4 EdithDialogPrimitive::AssignString(StringSet (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 29,0x14(1); stw 0,0x24(1); stw 12,0x10(1); mr 29,5; mr 11,4; mr 30,7; mr. 5,6; bgt 0f; cmpwi 30,0; beq 1f; mr 3,29; mr 4,30; bl _s800B54D4_0; b 7f; 0:; cmpwi 5,254; bne 2f; 1:; lis 4,-32706; mr 3,29; addi 4,4,-26324; bl _s800B54D4_1; b 7f; 2:; lwz 9,0x0(11); addi 3,1,8; lwz 0,0x8c(9); lha 4,0x88(9); mtspr 8,0; add 4,11,4; crxor 6,6,6; blrl; lwz 31,0x8(1); li 0,0; cmpwi 4,31,0; beq cr4,3f; lwz 0,0x0(31); 3:; cmpwi 0,0; beq 6f; li 3,0; beq cr4,4f; lwz 3,0x0(31); 4:; bl _s800B54D4_2; cmpwi 3,0; beq 6f; li 4,0; beq cr4,5f; lwz 4,0x0(31); 5:; mr 3,29; bl _s800B54D4_3; b 7f; 6:; cmpwi 30,0; beq 7f; mr 3,29; mr 4,30; bl _s800B54D4_4; 7:; lwz 0,0x24(1); lwz 12,0x10(1); mtspr 8,0; lmw 29,0x14(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s800B54D4_0();
extern "C" void _s800B54D4_1();
extern "C" void _s800B54D4_2();
extern "C" void _s800B54D4_3();
extern "C" void _s800B54D4_4();
extern "C" void f_800B54D4() {}
