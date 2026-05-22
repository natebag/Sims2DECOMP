// 0x802E174C EThread::SetupStack(int, (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,5; mr 29,4; bl _s802E174C_0; cmpwi 30,0; beq 0f; li 0,0; stw 30,0x31c(31); b 2f; 0:; bl _s802E174C_1; mr 4,29; li 5,64; li 6,0; li 7,0; bl _s802E174C_2; stw 30,0x328(31); cmpwi 3,0; stw 3,0x31c(31); bne 1f; li 3,0; b 3f; 1:; li 0,1; 2:; stw 0,0x324(31); stw 29,0x320(31); lis 4,-9253; lwz 3,0x31c(31); mr 5,29; ori 4,4,56283; bl _s802E174C_3; li 0,1; li 3,1; stw 0,0x328(31); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802E174C_0();
extern "C" void _s802E174C_1();
extern "C" void _s802E174C_2();
extern "C" void _s802E174C_3();
extern "C" void f_802E174C() {}
