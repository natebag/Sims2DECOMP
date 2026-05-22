// 0x80160694 CasGenetics::BlendSkinColor(signed (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lis 0,10922; srawi 11,4,31; ori 0,0,43691; srawi 10,5,31; mulhw 9,4,0; mulhw 0,5,0; subf 9,11,9; mulli 9,9,6; subf 0,10,0; mulli 0,0,6; subf 4,9,4; extsb 4,4; subf 5,0,5; stb 4,0x8(1); extsb 5,5; mr 0,4; stb 5,0x9(1); cmpw 5,0; bge 0f; stb 5,0x8(1); stb 0,0x9(1); 0:; bl _s80160694_0; li 0,100; lbz 10,0x9(1); divwu 0,3,0; lbz 11,0x8(1); extsb 10,10; lis 9,-32706; extsb 11,11; addi 5,9,-4053; li 6,0; li 7,0; li 8,0; mulli 0,0,100; mulli 10,10,6; mulli 11,11,36; subf 3,0,3; addi 3,3,1; 1:; add 0,8,10; cmpw 3,7; add 0,0,11; lbzx 9,5,0; extsb 9,9; ble 2f; add 0,7,9; cmpw 3,0; bgt 2f; mr 6,8; 2:; addi 0,8,1; add 7,7,9; extsb 8,0; cmpwi 8,5; ble 1b; mr 3,6; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80160694_0();
extern "C" void f_80160694() {}
