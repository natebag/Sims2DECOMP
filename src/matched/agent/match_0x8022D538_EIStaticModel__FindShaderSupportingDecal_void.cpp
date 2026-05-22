// 0x8022D538 EIStaticModel::FindShaderSupportingDecal(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 27,3; lwz 9,0x120(27); cmpwi 9,0; bne 1f; b 7f; 0:; lwz 3,0x4(30); b 8f; 1:; lwz 0,0x40(9); li 26,0; lwz 30,0x118(27); cmpw 26,0; bge 7f; li 25,0; 2:; lwz 9,0x120(27); li 29,0; lwz 0,0x3c(9); add 28,0,25; lwz 9,0x4(28); cmpw 29,9; bge 6f; 3:; lwz 31,0x4(30); mr 3,31; bl _s8022D538_0; cmpwi 3,0; beq 4f; lwz 9,0x18(31); lwz 0,0x58(9); b 5f; 4:; lwz 0,0x58(31); 5:; rlwinm 0,0,25,31,31; cmpwi 0,0; bne 0b; lwz 0,0x4(28); addi 29,29,1; addi 30,30,16; cmpw 29,0; blt 3b; 6:; lwz 9,0x120(27); addi 26,26,1; addi 25,25,24; lwz 0,0x40(9); cmpw 26,0; blt 2b; 7:; li 3,0; 8:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8022D538_0();
extern "C" void f_8022D538() {}
