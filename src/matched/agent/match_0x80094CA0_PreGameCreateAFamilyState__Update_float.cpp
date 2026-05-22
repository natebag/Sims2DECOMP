// 0x80094CA0 PreGameCreateAFamilyState::Update(float) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80094CA0_0; lwz 0,0x20(31); li 9,0; cmpwi 0,0; bne 0f; lwz 0,0x28(31); cmpwi 0,0; beq 0f; li 9,1; 0:; cmpwi 9,0; bne 2f; lwz 0,0x20(31); li 9,0; cmpwi 0,0; bne 1f; lwz 0,0x2c(31); cmpwi 0,0; beq 1f; li 9,1; 1:; cmpwi 9,0; beq 7f; 2:; bl _s80094CA0_1; cmpwi 3,0; bne 3f; li 3,2; bl _s80094CA0_2; b 7f; 3:; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 7f; lwz 0,0x20(31); li 11,0; mr 9,0; cmpwi 0,0; bne 4f; lwz 0,0x28(31); cmpwi 0,0; beq 4f; li 11,1; 4:; cmpwi 11,0; beq 5f; mr 3,31; li 4,2; bl _s80094CA0_3; b 7f; 5:; cmpwi 9,0; li 9,0; bne 6f; lwz 0,0x2c(31); cmpwi 0,0; beq 6f; li 9,1; 6:; cmpwi 9,0; beq 7f; mr 3,31; li 4,1; bl _s80094CA0_4; 7:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80094CA0_0();
extern "C" void _s80094CA0_1();
extern "C" void _s80094CA0_2();
extern "C" void _s80094CA0_3();
extern "C" void _s80094CA0_4();
extern "C" void f_80094CA0() {}
