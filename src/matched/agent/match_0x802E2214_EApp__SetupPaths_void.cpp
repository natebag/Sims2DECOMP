// 0x802E2214 EApp::SetupPaths(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x470(31); cmpwi 0,0; bne 0f; li 3,4; bl _s802E2214_0; mr 30,3; bl _s802E2214_1; stw 30,0x470(31); 0:; lis 4,-32702; mr 3,31; addi 4,4,-6168; bl _s802E2214_2; mr. 4,3; beq 1f; lwz 3,0x470(31); bl _s802E2214_3; b 2f; 1:; lis 4,-32702; lwz 3,0x470(31); addi 4,4,-6164; bl _s802E2214_4; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E2214_0();
extern "C" void _s802E2214_1();
extern "C" void _s802E2214_2();
extern "C" void _s802E2214_3();
extern "C" void _s802E2214_4();
extern "C" void f_802E2214() {}
