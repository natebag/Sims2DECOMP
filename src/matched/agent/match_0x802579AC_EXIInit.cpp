// 0x802579AC EXIInit (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); lis 3,-13312; addi 3,3,26624; 0:; lwz 0,0xc(3); rlwinm 0,0,0,31,31; cmplwi 0,1; beq 0b; lwz 0,0x20(3); rlwinm 0,0,0,31,31; cmplwi 0,1; beq 0b; lwz 0,0x34(3); rlwinm 0,0,0,31,31; cmplwi 0,1; beq 0b; lis 3,128; addi 3,3,-32768; bl _s802579AC_0; li 31,0; lis 4,-13312; stw 31,0x6800(4); stw 31,0x6814(4); stw 31,0x6828(4); li 0,8192; stw 0,0x6800(4); li 3,9; lis 4,-32731; addi 28,4,30204; addi 4,28,0; bl _s802579AC_1; li 3,10; lis 4,-32731; addi 29,4,30404; addi 4,29,0; bl _s802579AC_2; li 3,11; lis 4,-32731; addi 30,4,30940; addi 4,30,0; bl _s802579AC_3; li 3,12; addi 4,28,0; bl _s802579AC_4; li 3,13; addi 4,29,0; bl _s802579AC_5; li 3,14; addi 4,30,0; bl _s802579AC_6; li 3,15; addi 4,28,0; bl _s802579AC_7; li 3,16; addi 4,29,0; bl _s802579AC_8; li 3,0; li 4,2; addi 5,13,-23568; bl _s802579AC_9; lwz 0,-23704(13); cmpwi 0,0; beq 1f; lis 4,-32768; stw 31,0x30c4(4); stw 31,0x30c0(4); lis 3,-32694; addi 3,3,-22064; stw 31,0x60(3); stw 31,0x20(3); li 3,0; bl _s802579AC_10; li 3,1; bl _s802579AC_11; b 3f; 1:; li 3,0; li 4,0; addi 5,1,8; bl _s802579AC_12; cmpwi 3,0; beq 2f; lwz 3,0x8(1); addis 0,3,-1793; cmplwi 0,0; bne 2f; li 3,1; li 4,0; bl _s802579AC_13; b 3f; 2:; li 3,1; li 4,0; addi 5,1,8; bl _s802579AC_14; cmpwi 3,0; beq 3f; lwz 3,0x8(1); addis 0,3,-1793; cmplwi 0,0; bne 3f; li 3,0; li 4,2; bl _s802579AC_15; 3:; lwz 3,-27888(13); bl _s802579AC_16; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s802579AC_0();
extern "C" void _s802579AC_1();
extern "C" void _s802579AC_2();
extern "C" void _s802579AC_3();
extern "C" void _s802579AC_4();
extern "C" void _s802579AC_5();
extern "C" void _s802579AC_6();
extern "C" void _s802579AC_7();
extern "C" void _s802579AC_8();
extern "C" void _s802579AC_9();
extern "C" void _s802579AC_10();
extern "C" void _s802579AC_11();
extern "C" void _s802579AC_12();
extern "C" void _s802579AC_13();
extern "C" void _s802579AC_14();
extern "C" void _s802579AC_15();
extern "C" void _s802579AC_16();
extern "C" void f_802579AC() {}
