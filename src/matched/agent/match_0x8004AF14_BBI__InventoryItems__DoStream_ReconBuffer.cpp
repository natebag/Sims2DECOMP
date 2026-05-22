// 0x8004AF14 BBI::InventoryItems::DoStream(ReconBuffer (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 29,5; mr. 31,4; beq 1f; lis 0,18766; mr 3,31; ori 0,0,22016; addi 4,1,8; stw 0,0x8(1); li 5,1; bl _s8004AF14_0; lwz 0,0xc(31); cmpwi 0,0; beq 0f; blt 1f; cmpwi 0,2; bgt 1f; mr 3,30; mr 4,31; mr 5,29; bl _s8004AF14_1; b 2f; 0:; mr 3,30; mr 4,31; mr 5,29; bl _s8004AF14_2; b 2f; 1:; li 3,0; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8004AF14_0();
extern "C" void _s8004AF14_1();
extern "C" void _s8004AF14_2();
extern "C" void f_8004AF14() {}
