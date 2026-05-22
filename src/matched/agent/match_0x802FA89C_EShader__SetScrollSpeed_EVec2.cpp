// 0x802FA89C EShader::SetScrollSpeed(EVec2 (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 8,3; mr. 6,6; beq 2f; lwz 9,0x4(8); rlwinm 11,5,6,0,25; addi 10,8,116; add 7,11,8; oris 9,9,32768; cmpwi 5,0; stw 9,0x4(8); lwzx 0,10,11; ori 0,0,64; stwx 0,10,11; lwz 9,0x4(4); lwz 0,0x0(4); stw 9,0x90(7); stw 0,0x8c(7); bne 0f; li 0,5; stb 0,0x86(8); b 1f; 0:; li 0,6; stb 0,0x86(7); 1:; mr 3,8; bl _s802FA89C_0; b 6f; 2:; rlwinm 9,5,6,0,25; li 7,0; mr 5,9; li 10,0; add 9,8,9; stb 6,0x86(9); lbz 0,0x0(8); cmpw 7,0; bgt 5f; lbz 9,0x86(8); addi 9,9,-5; cmplwi 9,1; b 4f; 3:; lbz 0,0x0(8); addi 10,10,1; cmpw 10,0; bgt 5f; rlwinm 9,10,6,0,25; add 9,8,9; lbz 11,0x86(9); addi 11,11,-5; cmplwi 11,1; 4:; bgt 3b; li 7,1; 5:; cmpwi 7,0; bne 6f; lwz 0,0x4(8); addi 11,8,116; mr 3,8; rlwinm 0,0,0,1,31; stw 0,0x4(8); lwzx 9,11,5; rlwinm 9,9,0,26,24; stwx 9,11,5; bl _s802FA89C_1; 6:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802FA89C_0();
extern "C" void _s802FA89C_1();
extern "C" void f_802FA89C() {}
