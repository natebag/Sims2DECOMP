// 0x80293348 AptCIH::checkIfHigher(AptCIH (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 27,4; bl _s80293348_0; mr 29,3; cmpw 28,27; beq 3f; cmpwi 29,0; bne 1f; b 3f; 0:; li 3,1; b 4f; 1:; li 30,0; cmpw 30,29; bgt 3f; 2:; mr 4,30; mr 3,28; bl _s80293348_1; mr 31,3; mr 4,30; mr 3,27; bl _s80293348_2; cmpw 31,3; bgt 0b; cmpw 3,31; bgt 3f; addi 30,30,1; cmpw 30,29; ble 2b; 3:; li 3,0; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80293348_0();
extern "C" void _s80293348_1();
extern "C" void _s80293348_2();
extern "C" void f_80293348() {}
