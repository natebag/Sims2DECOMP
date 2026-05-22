// 0x800759D4 SimsMemCardWrap::LoadHouse(int) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; addi 9,9,23428; li 3,0; lwz 0,0xe8(9); li 11,0; cmpwi 0,0; bne 0f; lwz 0,0xf0(9); subfic 9,0,0; adde 11,9,0; 0:; lwz 9,-26824(13); lwz 0,0x468(9); cmpwi 0,0; bne 2f; cmpwi 11,0; beq 1f; lwz 3,-32056(13); bl _s800759D4_0; 1:; lwz 3,-32056(13); mr 4,31; li 5,0; li 6,0; bl _s800759D4_1; 2:; lwz 9,-26512(13); li 0,1; stw 0,0xc(9); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800759D4_0();
extern "C" void _s800759D4_1();
extern "C" void f_800759D4() {}
