// 0x8007B5F4 GetMoneyString(int, (676 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-640(1); mfspr 0,8; stmw 23,0x25c(1); stw 0,0x284(1); mr 25,4; mr 31,5; li 23,0; mr. 3,3; bge 0f; srawi 0,3,31; li 23,1; xor 3,0,3; subf 3,0,3; cmpwi 3,0; blt 1f; 0:; lis 0,15; mr 30,3; ori 0,0,16959; cmpw 30,0; ble 2f; lis 30,15; ori 30,30,16959; b 2f; 1:; li 30,0; 2:; cmpwi 30,999; bgt 3f; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,26404; addi 3,1,592; crxor 6,6,6; bl _s8007B5F4_0; b 4f; 3:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,26428; addi 3,1,592; crxor 6,6,6; bl _s8007B5F4_1; 4:; lwz 9,0x250(1); li 0,0; cmpwi 9,0; beq 5f; lwz 0,0x0(9); 5:; mr. 4,0; beq 14f; cmpwi 31,0; bne 8f; cmpwi 30,999; bgt 6f; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,26452; addi 3,1,596; crxor 6,6,6; bl _s8007B5F4_2; b 7f; 6:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,26484; addi 3,1,596; crxor 6,6,6; bl _s8007B5F4_3; 7:; lwz 9,0x254(1); li 4,0; cmpwi 9,0; beq 8f; lwz 4,0x0(9); 8:; mr 27,4; cmpwi 27,0; beq 14f; lis 0,4194; srawi 11,30,31; ori 0,0,19923; lis 9,-32696; mulhw 0,30,0; addi 26,9,22460; li 24,0; addi 31,1,8; sth 24,0x57bc(9); li 6,0; mr 4,26; srawi 0,0,6; li 5,32; subf 29,11,0; mr 28,29; mulli 0,28,1000; mr 3,28; subf 29,0,30; bl _s8007B5F4_4; addi 4,31,8; li 5,256; mr 3,31; bl _s8007B5F4_5; mr 3,31; bl _s8007B5F4_6; cmpwi 23,0; beq 9f; addi 30,1,528; lis 3,-32707; mr 4,30; li 5,32; addi 3,3,26520; bl _s8007B5F4_7; mr 4,30; mr 3,31; li 5,-1; bl _s8007B5F4_8; 9:; mr 4,27; li 5,-1; mr 3,31; bl _s8007B5F4_9; mr 3,31; bl _s8007B5F4_10; mr 30,3; addi 3,13,-24852; bl _s8007B5F4_11; mr 4,3; mr 5,26; mr 3,30; mr 6,25; bl _s8007B5F4_12; lis 9,-32696; cmpwi 28,0; sth 24,0x57bc(9); bne 10f; cmpwi 29,99; ble 11f; 10:; mr 3,29; mr 4,26; li 5,32; li 6,3; bl _s8007B5F4_13; b 13f; 11:; cmpwi 29,9; ble 12f; mr 3,29; mr 4,26; li 5,32; li 6,2; bl _s8007B5F4_14; b 13f; 12:; mr 3,29; mr 4,26; li 5,32; li 6,1; bl _s8007B5F4_15; 13:; mr 3,25; lis 29,-32696; bl _s8007B5F4_16; mr 30,3; addi 3,13,-24848; bl _s8007B5F4_17; mr 4,3; mr 6,25; mr 3,30; addi 5,29,22460; bl _s8007B5F4_18; li 0,0; sth 0,0x57bc(29); 14:; lwz 0,0x284(1); mtspr 8,0; lmw 23,0x25c(1); addi 1,1,640"
extern "C" void _s8007B5F4_0();
extern "C" void _s8007B5F4_1();
extern "C" void _s8007B5F4_2();
extern "C" void _s8007B5F4_3();
extern "C" void _s8007B5F4_4();
extern "C" void _s8007B5F4_5();
extern "C" void _s8007B5F4_6();
extern "C" void _s8007B5F4_7();
extern "C" void _s8007B5F4_8();
extern "C" void _s8007B5F4_9();
extern "C" void _s8007B5F4_10();
extern "C" void _s8007B5F4_11();
extern "C" void _s8007B5F4_12();
extern "C" void _s8007B5F4_13();
extern "C" void _s8007B5F4_14();
extern "C" void _s8007B5F4_15();
extern "C" void _s8007B5F4_16();
extern "C" void _s8007B5F4_17();
extern "C" void _s8007B5F4_18();
extern "C" void f_8007B5F4() {}
