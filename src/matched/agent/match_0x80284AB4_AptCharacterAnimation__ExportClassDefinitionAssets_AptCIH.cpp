// 0x80284AB4 AptCharacterAnimation::ExportClassDefinitionAssets(AptCIH (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 24,0x18(1); stw 0,0x3c(1); stw 12,0x14(1); mr 30,3; li 31,0; lwz 0,0x28(30); mr 26,4; cmpw 31,0; bge 7f; 0:; rlwinm 9,31,3,0,28; lwz 11,0x2c(30); mr 27,9; add 9,9,11; lwz 0,0x4(9); cmpwi 0,0; blt 7f; lwzx 3,27,11; lis 4,-32704; addi 4,4,12344; addi 24,31,1; bl _s80284AB4_0; cmpwi 3,0; beq 6f; lwz 11,0x4(30); li 8,0; lwz 9,0x2c(30); lwz 0,0x0(11); mr 6,11; add 9,27,9; lwz 7,0x4(9); cmpw 8,0; bge 5f; lis 28,-32694; cmpwi 4,26,0; li 29,0; li 10,0; 1:; lwz 9,0x4(11); lwzx 9,10,9; lwz 0,0x0(9); cmpwi 0,8; bne 4f; lwz 0,0x4(9); cmpw 0,7; bne 4f; addi 3,28,-16032; addi 4,1,8; bl _s80284AB4_1; addi 25,1,8; mr 31,3; beq cr4,2f; mr 3,26; bl _s80284AB4_2; lwz 7,0x4c(3); b 3f; 2:; li 7,0; 3:; lwz 9,0x4(30); mr 5,26; addi 3,28,-16032; li 6,-1; lwz 11,0x4(9); lwzx 9,29,11; lwz 4,0x8(9); bl _s80284AB4_3; addi 3,28,-16032; mr 4,31; mr 5,25; bl _s80284AB4_4; b 5f; 4:; mr 11,6; addi 8,8,1; lwz 0,0x0(11); addi 29,29,4; addi 10,10,4; cmpw 8,0; blt 1b; 5:; lwz 9,0x2c(30); add 9,27,9; lwz 0,0x4(9); neg 0,0; stw 0,0x4(9); 6:; lwz 0,0x28(30); mr 31,24; cmpw 31,0; blt 0b; 7:; lwz 0,0x3c(1); lwz 12,0x14(1); mtspr 8,0; lmw 24,0x18(1); mtcrf 8,12; addi 1,1,56"
extern "C" void _s80284AB4_0();
extern "C" void _s80284AB4_1();
extern "C" void _s80284AB4_2();
extern "C" void _s80284AB4_3();
extern "C" void _s80284AB4_4();
extern "C" void f_80284AB4() {}
