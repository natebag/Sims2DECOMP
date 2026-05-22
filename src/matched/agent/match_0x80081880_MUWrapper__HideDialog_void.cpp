// 0x80081880 MUWrapper::HideDialog(void) (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; lwz 0,0xc0(31); cmpwi 0,0; beq 0f; lis 4,-32707; addi 4,4,28168; lis 29,-32707; bl _s80081880_0; li 28,0; lis 30,-32697; lis 4,-32707; addi 30,30,24012; lis 8,-32707; lwz 3,0xb4(30); addi 8,8,27520; addi 4,4,27500; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80081880_1; lwz 3,0xb4(30); lis 8,-32707; addi 8,8,27540; addi 4,29,27568; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80081880_2; lwz 3,0xb4(30); lis 8,-32707; addi 8,8,27548; addi 4,29,27568; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80081880_3; lwz 3,0xb4(30); lis 8,-32707; addi 8,8,27556; addi 4,29,27568; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80081880_4; lwz 3,0xb4(30); lis 8,-32707; addi 8,8,27564; addi 4,29,27568; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80081880_5; stw 28,0x114(31); lis 4,-32707; stw 28,0x110(31); addi 4,4,27616; stw 28,0x10c(31); li 5,0; stw 28,0x108(31); li 6,0; li 7,0; lwz 3,0xb4(30); crxor 6,6,6; bl _s80081880_6; lwz 9,0xa8(31); lwz 0,0x4(9); mr 3,9; rlwinm 0,0,0,0,30; stw 0,0x4(9); bl _s80081880_7; stw 28,0xc0(31); 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80081880_0();
extern "C" void _s80081880_1();
extern "C" void _s80081880_2();
extern "C" void _s80081880_3();
extern "C" void _s80081880_4();
extern "C" void _s80081880_5();
extern "C" void _s80081880_6();
extern "C" void _s80081880_7();
extern "C" void f_80081880() {}
