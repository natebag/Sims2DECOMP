// 0x802C7428 EFixedString::Concatonate(char (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; mr 28,5; mr. 29,4; bne 0f; lwz 29,-26884(13); 0:; mr 3,29; bl _s802C7428_0; mr 27,3; cmpwi 28,0; bne 1f; lwz 28,-26884(13); 1:; mr 3,28; bl _s802C7428_1; lwz 31,0x4(30); mr 26,3; cmpw 31,27; ble 2f; mr 31,27; 2:; cmpwi 31,0; beq 3f; lwz 3,0x0(30); mr 4,29; mr 5,31; crxor 6,6,6; bl _s802C7428_2; 3:; lwz 9,0x4(30); addi 3,26,1; subf 9,31,9; addi 5,9,-1; cmpw 5,3; ble 4f; mr 5,3; 4:; cmpwi 5,0; ble 5f; lwz 3,0x0(30); mr 4,28; add 3,3,31; crxor 6,6,6; bl _s802C7428_3; 5:; lwz 9,0x4(30); li 11,0; lwz 0,0x0(30); mr 3,30; add 9,9,0; stb 11,-1(9); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s802C7428_0();
extern "C" void _s802C7428_1();
extern "C" void _s802C7428_2();
extern "C" void _s802C7428_3();
extern "C" void f_802C7428() {}
