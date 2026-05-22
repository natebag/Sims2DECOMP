// 0x8007CB60 EParticleEffect::~EParticleEffect(void) (528 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x264(1); mtspr 8,0; lmw 26,0x248(1); addi 1,1,608; blr; stwu 1,-152(1); mfspr 0,8; stmw 20,0x68(1); stw 0,0x9c(1); addi 31,1,8; mr 24,3; mr 20,4; lis 30,-32707; addi 30,30,26688; addi 4,31,8; li 5,16; mr 3,31; bl _s8007CB60_0; mr 4,30; li 5,-1; mr 3,31; bl _s8007CB60_1; mr 3,31; bl _s8007CB60_2; mr 4,3; mr 3,24; bl _s8007CB60_3; mr. 28,3; beq 7f; addi 4,1,56; li 5,32; addi 3,1,48; li 27,0; bl _s8007CB60_4; subf 21,24,28; mr 3,31; addi 22,1,48; addi 26,1,88; bl _s8007CB60_5; mr 31,3; addi 25,1,96; add 11,31,31; lhzx 0,11,28; cmpwi 0,0; beq 3f; cmpwi 0,62; beq 4f; mr 30,11; lis 9,-32704; addi 0,30,1; addi 23,9,-935; add 29,0,28; 0:; cmpwi 27,0; bne 1f; lhzx 9,11,28; lbzx 0,9,23; andi. 0,0,23; cmpwi 0,0; beq 2f; 1:; lbz 4,0x0(29); mr 3,22; addi 27,27,1; extsb 4,4; bl _s8007CB60_6; 2:; addi 30,30,2; addi 29,29,2; lhzx 0,30,28; addi 31,31,1; mr 11,30; cmpwi 0,0; beq 3f; cmpwi 0,62; beq 4f; addi 0,27,1; cmpwi 0,31; ble 0b; 3:; add 0,31,31; lhzx 9,28,0; cmpwi 9,62; bne 5f; 4:; addi 31,31,1; 5:; mr 4,24; mr 3,26; bl _s8007CB60_7; srawi 30,21,1; mr 3,22; bl _s8007CB60_8; mr 5,3; lis 4,-32697; mr 3,25; addi 4,4,24012; crxor 6,6,6; bl _s8007CB60_9; lwz 9,0x60(1); li 6,0; cmpwi 9,0; beq 6f; lwz 6,0x0(9); 6:; mr 4,30; mr 5,31; mr 3,26; bl _s8007CB60_10; mr 3,26; bl _s8007CB60_11; mr 4,20; bl _s8007CB60_12; mr 3,26; li 4,2; bl _s8007CB60_13; b 8f; 7:; mr 3,24; mr 4,20; bl _s8007CB60_14; 8:; lwz 0,0x9c(1); mtspr 8,0; lmw 20,0x68(1); addi 1,1,152; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 9f; cmpwi 3,0; beq 9f; bl _s8007CB60_15; 9:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8007CB60_0();
extern "C" void _s8007CB60_1();
extern "C" void _s8007CB60_2();
extern "C" void _s8007CB60_3();
extern "C" void _s8007CB60_4();
extern "C" void _s8007CB60_5();
extern "C" void _s8007CB60_6();
extern "C" void _s8007CB60_7();
extern "C" void _s8007CB60_8();
extern "C" void _s8007CB60_9();
extern "C" void _s8007CB60_10();
extern "C" void _s8007CB60_11();
extern "C" void _s8007CB60_12();
extern "C" void _s8007CB60_13();
extern "C" void _s8007CB60_14();
extern "C" void _s8007CB60_15();
extern "C" void f_8007CB60() {}
