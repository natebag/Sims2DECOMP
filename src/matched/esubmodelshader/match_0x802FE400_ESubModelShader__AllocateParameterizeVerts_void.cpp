// 0x802FE400 ESubModelShader::AllocateParameterizeVerts(void) (460 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; li 11,0; lwz 0,0x18(31); cmpw 11,0; bge 6f; 0:; mulli 10,11,52; lwz 9,0x14(31); addi 27,11,1; mr 7,9; addi 28,31,20; add 9,9,10; lwz 0,0xc(9); cmpwi 0,0; beq 5f; lwz 0,0x18(9); li 8,0; cmpw 8,0; bge 5f; mr 30,10; mr 29,30; 1:; add 9,7,30; rlwinm 10,8,2,0,29; lwz 11,0xc(9); addi 12,8,1; lbzx 0,10,11; cmpwi 0,0; beq 4f; lwz 0,0x6c(31); li 6,0; cmpw 6,0; bge 4f; add 3,7,29; mr 4,10; mr 5,0; li 7,0; 2:; lwz 9,0x68(31); lwz 10,0xc(3); lwzx 11,7,9; add 8,7,9; lbzx 0,4,10; lbz 9,0x83(11); add 0,0,0; cmpw 0,9; bne 3f; lwz 9,0x4(8); addi 9,9,1; stw 9,0x4(8); b 4f; 3:; addi 6,6,1; addi 7,7,12; cmpw 6,5; blt 2b; 4:; lwz 0,0x14(31); mr 8,12; add 11,0,30; mr 7,0; lwz 9,0x18(11); cmpw 8,9; blt 1b; 5:; lwz 0,0x4(28); mr 11,27; cmpw 11,0; blt 0b; 6:; lwz 0,0x6c(31); li 29,0; cmpw 29,0; bge 10f; li 28,0; li 30,0; 7:; lwz 9,0x68(31); add 9,30,9; lwz 4,0x8(9); cmpwi 4,0; beq 8f; mr 3,31; bl _s802FE400_0; lwz 9,0x68(31); add 9,30,9; stw 28,0x8(9); 8:; lwz 9,0x68(31); add 9,30,9; lwz 4,0x4(9); cmpwi 4,0; beq 9f; mulli 4,4,20; li 5,16; mr 3,31; bl _s802FE400_1; lwz 11,0x68(31); li 4,0; add 11,30,11; stw 3,0x8(11); lwz 9,0x68(31); add 9,30,9; lwz 5,0x4(9); lwz 3,0x8(9); mulli 5,5,20; bl _s802FE400_2; lwz 9,0x68(31); add 9,30,9; stw 28,0x4(9); 9:; lwz 0,0x6c(31); addi 29,29,1; addi 30,30,12; cmpw 29,0; blt 7b; 10:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s802FE400_0();
extern "C" void _s802FE400_1();
extern "C" void _s802FE400_2();

struct ESubModelShader {
    void AllocateParameterizeVerts();
};

void ESubModelShader::AllocateParameterizeVerts() {
}
