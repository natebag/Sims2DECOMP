// 0x80304250 EController::SetCommandMap(EBtnToCmdAssoc (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; mr 0,4; lis 6,-32720; stw 5,0x1a8(9); mr 4,5; mr 3,0; addi 6,6,16944; stw 0,0x1a4(9); li 5,8; bl _s80304250_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80304250_0();
extern "C" void f_80304250() {}
