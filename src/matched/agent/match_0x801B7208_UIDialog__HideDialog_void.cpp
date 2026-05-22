// 0x801B7208 UIDialog::HideDialog(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,0; li 5,-1; addi 3,30,40; bl _s801B7208_0; li 4,0; li 5,-1; addi 3,30,48; bl _s801B7208_1; li 4,0; li 5,-1; addi 3,30,52; bl _s801B7208_2; addi 3,30,56; li 4,0; li 5,-1; bl _s801B7208_3; lis 9,-32697; lwz 3,0x5f08(9); bl _s801B7208_4; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801B7208_0();
extern "C" void _s801B7208_1();
extern "C" void _s801B7208_2();
extern "C" void _s801B7208_3();
extern "C" void _s801B7208_4();
extern "C" void f_801B7208() {}
