// 0x80320680 ERShader::SetSupportDecal(bool) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s80320680_0; cmpwi 3,0; beq 1f; cmpwi 30,0; beq 0f; lwz 9,0x18(31); lwz 0,0x58(9); ori 0,0,128; stw 0,0x58(9); b 4f; 0:; lwz 9,0x18(31); lwz 0,0x58(9); rlwinm 0,0,0,25,23; stw 0,0x58(9); b 4f; 1:; cmpwi 30,0; beq 2f; lwz 0,0x58(31); ori 0,0,128; b 3f; 2:; lwz 0,0x58(31); rlwinm 0,0,0,25,23; 3:; stw 0,0x58(31); 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80320680_0();
extern "C" void f_80320680() {}
