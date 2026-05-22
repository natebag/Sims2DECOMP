// 0x8007D28C CTGFileImpl::WriteString(char (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 31,3; mr 3,29; bl _s8007D28C_0; mr 30,3; cmpwi 30,254; bgt 0f; lwz 9,0x0(31); rlwinm 4,30,0,24,31; lha 3,0x60(9); lwz 0,0x64(9); b 1f; 0:; lwz 9,0x0(31); li 4,255; lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; lwz 9,0x0(31); mr 4,30; lha 3,0x70(9); lwz 0,0x74(9); 1:; add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 3f; 2:; li 3,0; b 4f; 3:; lwz 9,0x0(31); mr 4,29; mr 5,30; lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8007D28C_0();
extern "C" void f_8007D28C() {}
