// 0x801E8EA0 EYETarget::GetVariable(char (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 3,4; bl _s801E8EA0_0; mr 29,3; li 3,32; bl _s801E8EA0_1; li 0,0; mr 31,3; stb 0,0x0(31); addi 11,30,196; li 10,0; lwz 0,0xc4(30); lwz 9,0x4(11); subf 9,0,9; srawi. 0,9,2; ble 2f; mr 7,11; li 8,0; 0:; lwz 9,0xc4(30); lwzx 11,9,8; lwz 0,0x4(11); cmpw 29,0; bne 1f; lwz 9,0x8(11); mr 4,31; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; b 2f; 1:; lwz 0,0x4(7); addi 10,10,1; addi 8,8,4; subf 0,9,0; srawi 0,0,2; cmpw 10,0; blt 0b; 2:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801E8EA0_0();
extern "C" void _s801E8EA0_1();
extern "C" void f_801E8EA0() {}
