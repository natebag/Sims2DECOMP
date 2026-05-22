// 0x80072B20 SimModel::CompositeAllSkin(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; mfcr 12; stmw 29,0xc(1); stw 0,0x1c(1); stw 12,0x8(1); mr 30,3; lwz 9,0x13c(30); cmpwi 9,0; beq 2f; lwz 0,0x118(9); li 29,0; cmpwi 0,0; bne 0f; lbz 5,0x88(9); lbz 4,0x89(9); lwz 3,0x138(30); extsb 5,5; extsb 4,4; bl _s80072B20_0; mr 4,3; li 5,0; lis 3,-32693; li 6,0; addi 3,3,24536; bl _s80072B20_1; mr 29,3; 0:; li 31,0; cmpwi 4,29,0; 1:; mr 4,31; mr 3,30; bl _s80072B20_2; addi 0,31,1; rlwinm 31,0,0,24,31; cmplwi 31,3; ble 1b; beq cr4,2f; lis 3,-32693; mr 4,29; addi 3,3,24536; li 5,1; bl _s80072B20_3; 2:; lwz 0,0x1c(1); lwz 12,0x8(1); mtspr 8,0; lmw 29,0xc(1); mtcrf 8,12; addi 1,1,24"
extern "C" void _s80072B20_0();
extern "C" void _s80072B20_1();
extern "C" void _s80072B20_2();
extern "C" void _s80072B20_3();
extern "C" void f_80072B20() {}
