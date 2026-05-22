// 0x802FA474 EShader::GetTexture(int) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); andis. 9,0,1024; beq 0f; addi 9,3,100; lbz 0,0x24(9); cmpwi 0,0; beq 1f; lwz 11,0x4(9); cmpwi 11,0; beq 1f; lbz 9,0xec(3); rlwinm 9,9,2,0,29; lwzx 3,9,11; blr; 0:; rlwinm 0,4,6,0,25; addi 9,3,100; lwzx 3,9,0; blr; 1:; li 3,0"
extern "C" int f_802FA474() {}
