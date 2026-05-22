// 0x800812C8 MUWrapper::Draw(ERC (636 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; addi 31,9,24012; mr 29,4; lwz 3,0xb4(31); lis 4,-32707; addi 4,4,27980; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s800812C8_0; lwz 3,0xb4(31); lis 4,-32707; addi 4,4,28000; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s800812C8_1; lwz 3,0xb4(31); lis 4,-32707; addi 4,4,28016; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s800812C8_2; lwz 3,0xb4(31); lis 4,-32707; lis 8,-32707; addi 4,4,27500; addi 8,8,27520; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800812C8_3; lwz 0,0x108(30); cmpwi 0,0; beq 0f; lis 4,-32707; lis 8,-32707; lwz 3,0xb4(31); addi 4,4,28032; addi 8,8,27540; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800812C8_4; 0:; lwz 0,0x10c(30); cmpwi 0,0; beq 1f; lis 4,-32707; lis 8,-32707; lwz 3,0xb4(31); addi 4,4,28032; addi 8,8,27548; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800812C8_5; 1:; lwz 0,0x110(30); cmpwi 0,0; beq 2f; lis 4,-32707; lis 8,-32707; lwz 3,0xb4(31); addi 4,4,28032; addi 8,8,27556; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800812C8_6; 2:; lwz 0,0x114(30); cmpwi 0,0; beq 3f; lis 4,-32707; lis 8,-32707; lwz 3,0xb4(31); addi 4,4,28032; addi 8,8,27564; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s800812C8_7; 3:; lwz 3,0xb4(31); lis 4,-32707; addi 4,4,27616; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s800812C8_8; lwz 0,0xc8(30); cmpwi 0,0; beq 4f; lis 9,-32707; lwz 3,0xa8(30); lwz 31,0x6dc0(9); li 4,3; li 5,0; bl _s800812C8_9; lwz 0,0x4(3); ori 0,0,1; b 5f; 4:; lis 9,-32707; lwz 3,0xa8(30); lwz 31,0x6dc4(9); li 4,3; li 5,0; bl _s800812C8_10; lwz 0,0x4(3); rlwinm 0,0,0,0,30; 5:; stw 0,0x4(3); lwz 9,0xa8(30); mr 3,30; mr 4,29; stw 31,0x2c(9); bl _s800812C8_11; lis 30,-32697; lis 4,-32707; addi 30,30,24012; addi 4,4,28044; lwz 3,0xb4(30); li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s800812C8_12; lwz 3,0xb4(30); lis 4,-32707; addi 4,4,28064; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s800812C8_13; lis 4,-32707; lwz 3,0xb4(30); addi 4,4,28080; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s800812C8_14; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800812C8_0();
extern "C" void _s800812C8_1();
extern "C" void _s800812C8_2();
extern "C" void _s800812C8_3();
extern "C" void _s800812C8_4();
extern "C" void _s800812C8_5();
extern "C" void _s800812C8_6();
extern "C" void _s800812C8_7();
extern "C" void _s800812C8_8();
extern "C" void _s800812C8_9();
extern "C" void _s800812C8_10();
extern "C" void _s800812C8_11();
extern "C" void _s800812C8_12();
extern "C" void _s800812C8_13();
extern "C" void _s800812C8_14();
extern "C" void f_800812C8() {}
