// 0x802AFE3C AptTextFormat::AptTextFormat(TextFormat (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 28,0x10(1); stw 0,0x2c(1); mr 29,3; mr 30,4; li 4,36; bl _s802AFE3C_0; addi 31,29,36; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,29,12; stw 9,0x8(29); lis 28,-32703; bl _s802AFE3C_1; li 0,0; lis 9,-32703; stb 0,0x20(29); addi 9,9,21120; stw 9,0x8(29); addi 4,28,4000; lwz 0,0x20(29); mr 3,31; rlwinm 0,0,0,10,7; stw 0,0x20(29); bl _s802AFE3C_2; lis 9,-32703; li 11,-1; lfs f31,0x13b8(9); li 0,3; li 9,2; stw 0,0xc(31); stfs f31,0x4(31); mr 3,31; stw 9,0x10(31); mr 4,30; stw 11,0x1c(31); stw 11,0x8(31); stw 11,0x14(31); stw 11,0x18(31); bl _s802AFE3C_3; lis 9,-32703; addi 9,9,4912; stw 9,0x8(29); lwz 0,0xc(30); cmpwi 0,3; beq 0f; stw 0,0xc(31); 0:; lwz 0,0x8(30); cmpwi 0,-1; beq 1f; stw 0,0x8(31); 1:; addi 4,28,4000; mr 3,30; bl _s802AFE3C_4; cmpwi 3,0; beq 2f; mr 3,31; mr 4,30; bl _s802AFE3C_5; 2:; lfs f0,0x4(30); fcmpu 0,f0,f31; beq 3f; stfs f0,0x4(31); 3:; lwz 0,0x10(30); cmpwi 0,2; beq 4f; stw 0,0x10(31); 4:; lwz 0,0x14(30); cmpwi 0,-1; beq 5f; stw 0,0x14(31); 5:; lwz 0,0x18(30); cmpwi 0,-1; beq 6f; stw 0,0x18(31); 6:; lwz 3,0x1c(30); cmpwi 3,-1; beq 7f; stw 3,0x1c(31); 7:; mr 3,29; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x10(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s802AFE3C_0();
extern "C" void _s802AFE3C_1();
extern "C" void _s802AFE3C_2();
extern "C" void _s802AFE3C_3();
extern "C" void _s802AFE3C_4();
extern "C" void _s802AFE3C_5();
extern "C" void f_802AFE3C() {}
