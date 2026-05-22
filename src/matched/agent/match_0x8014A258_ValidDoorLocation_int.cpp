// 0x8014A258 ValidDoorLocation(int, (748 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-168(1); mfspr 0,8; stmw 27,0x94(1); stw 0,0xac(1); mr 28,6; mr 29,7; subf 11,4,28; subf 9,5,29; addi 0,11,1; mr 30,3; cmplwi 0,2; bgt 7f; cmpwi 9,-1; blt 7f; cmpwi 9,1; bgt 7f; cmpwi 11,0; bne 0f; cmpwi 9,0; beq 7f; b 1f; 0:; cmpwi 9,0; bne 7f; 1:; addi 3,1,8; mr 6,30; bl _s8014A258_0; addi 3,1,16; mr 4,28; mr 5,29; mr 6,30; mr 31,3; bl _s8014A258_1; lwz 11,-21488(13); addi 4,1,8; lwz 9,0x0(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 6f; lwz 3,-21488(13); mr 4,31; lwz 9,0x0(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 6f; addi 30,1,32; li 4,0; li 5,0; mr 3,30; bl _s8014A258_2; li 27,0; addi 29,1,24; addi 4,1,8; mr 5,30; mr 3,29; bl _s8014A258_3; mr 4,31; mr 3,29; bl _s8014A258_4; mr 28,3; li 4,2; mr 3,29; bl _s8014A258_5; mr 3,30; li 4,2; bl _s8014A258_6; cmpwi 28,0; beq 2f; li 27,2; b 5f; 2:; addi 30,1,48; li 4,1; li 5,0; mr 3,30; bl _s8014A258_7; addi 29,1,40; addi 4,1,8; mr 5,30; mr 3,29; bl _s8014A258_8; mr 4,31; mr 3,29; bl _s8014A258_9; mr 28,3; li 4,2; mr 3,29; bl _s8014A258_10; mr 3,30; li 4,2; bl _s8014A258_11; cmpwi 28,0; beq 3f; li 27,8; b 5f; 3:; addi 30,1,64; li 4,2; li 5,0; mr 3,30; bl _s8014A258_12; addi 29,1,56; addi 4,1,8; mr 5,30; mr 3,29; bl _s8014A258_13; mr 4,31; mr 3,29; bl _s8014A258_14; mr 28,3; li 4,2; mr 3,29; bl _s8014A258_15; mr 3,30; li 4,2; bl _s8014A258_16; cmpwi 28,0; beq 4f; li 27,1; b 5f; 4:; addi 30,1,80; li 4,3; li 5,0; mr 3,30; bl _s8014A258_17; addi 29,1,72; addi 4,1,8; mr 5,30; mr 3,29; bl _s8014A258_18; mr 4,31; mr 3,29; bl _s8014A258_19; mr 28,3; li 4,2; mr 3,29; bl _s8014A258_20; mr 3,30; li 4,2; bl _s8014A258_21; cmpwi 28,0; beq 5f; li 27,4; 5:; cmpwi 27,0; beq 6f; lwz 11,-21488(13); addi 30,1,88; addi 5,1,8; mr 3,30; lwz 9,0x0(11); lha 4,0xa8(9); lwz 0,0xac(9); add 4,11,4; mtspr 8,0; blrl; mr 4,27; mr 3,30; bl _s8014A258_22; mr 29,3; li 4,2; mr 3,30; bl _s8014A258_23; mr 3,31; li 4,2; bl _s8014A258_24; addi 3,1,8; li 4,2; bl _s8014A258_25; mr 3,29; b 8f; 6:; mr 3,31; li 4,2; bl _s8014A258_26; addi 3,1,8; li 4,2; bl _s8014A258_27; 7:; li 3,0; 8:; lwz 0,0xac(1); mtspr 8,0; lmw 27,0x94(1); addi 1,1,168"
extern "C" void _s8014A258_0();
extern "C" void _s8014A258_1();
extern "C" void _s8014A258_2();
extern "C" void _s8014A258_3();
extern "C" void _s8014A258_4();
extern "C" void _s8014A258_5();
extern "C" void _s8014A258_6();
extern "C" void _s8014A258_7();
extern "C" void _s8014A258_8();
extern "C" void _s8014A258_9();
extern "C" void _s8014A258_10();
extern "C" void _s8014A258_11();
extern "C" void _s8014A258_12();
extern "C" void _s8014A258_13();
extern "C" void _s8014A258_14();
extern "C" void _s8014A258_15();
extern "C" void _s8014A258_16();
extern "C" void _s8014A258_17();
extern "C" void _s8014A258_18();
extern "C" void _s8014A258_19();
extern "C" void _s8014A258_20();
extern "C" void _s8014A258_21();
extern "C" void _s8014A258_22();
extern "C" void _s8014A258_23();
extern "C" void _s8014A258_24();
extern "C" void _s8014A258_25();
extern "C" void _s8014A258_26();
extern "C" void _s8014A258_27();
extern "C" void f_8014A258() {}
