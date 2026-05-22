// 0x80041928 GetResData(cXObject (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x4(31); lha 3,0x390(9); lwz 0,0x394(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; lwz 9,0x4(31); lha 3,0x310(9); lwz 0,0x314(9); add 3,31,3; mtspr 8,0; blrl; lwz 3,0xc0(3); b 5f; 0:; cmpwi 31,0; beq 1f; lwz 3,0x0(31); li 4,3; bl _s80041928_0; mr 31,3; b 2f; 1:; li 31,0; 2:; lwz 9,0x4(31); lha 3,0x10(9); lwz 0,0x14(9); b 4f; 3:; lwz 3,0x0(31); lwz 9,0x4(3); lha 0,0x310(9); lwz 9,0x314(9); add 3,3,0; mtspr 8,9; blrl; lwz 3,0xc0(3); cmpwi 3,0; bne 5f; lwz 9,0x4(31); lha 3,0x18(9); lwz 0,0x1c(9); 4:; add 3,31,3; mtspr 8,0; blrl; mr. 31,3; bne 3b; li 3,0; 5:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80041928_0();
extern "C" void f_80041928() {}
