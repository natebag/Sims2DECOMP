// 0x8015E9D4 CasClothingUnlocks::CasClothingUnlocks(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 11,1; addi 6,31,2560; mr 0,31; li 7,0; 0:; mr 9,0; addi 10,11,-1; addi 8,9,1280; li 11,31; 1:; li 5,40; addi 11,11,-1; mtspr 9,5; addi 0,9,40; 2:; stb 7,0x0(9); addi 9,9,1; bdnz 2b; mr 9,0; cmpwi 11,-1; bne 1b; mr 11,10; mr 0,8; cmpwi 11,-1; bne 0b; mr 0,6; li 11,1; li 6,0; 3:; mr 9,0; addi 8,11,-1; addi 7,9,240; li 11,7; 4:; addi 0,11,-1; addi 10,9,30; li 11,30; mtspr 9,11; 5:; stb 6,0x0(9); addi 9,9,1; bdnz 5b; mr 11,0; mr 9,10; cmpwi 11,-1; bne 4b; mr 11,8; mr 0,7; cmpwi 11,-1; bne 3b; mr 3,31; bl _s8015E9D4_0; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8015E9D4_0();
extern "C" void f_8015E9D4() {}
