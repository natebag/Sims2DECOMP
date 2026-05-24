// 0x802B958C AptXml::AptXml(AptValue (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; li 4,33; li 5,0; bl _s802B958C_0; lis 9,-32703; li 11,0; addi 9,9,31032; stw 9,0x8(30); lwz 9,0x0(31); rlwinm 0,9,0,25,31; cmpwi 0,1; beq 0f; cmpwi 0,42; bne 1f; 0:; andis. 0,9,2048; beq 1f; li 11,1; 1:; cmpwi 11,0; beq 3f; lwz 10,-27576(13); mr 8,31; lwz 0,0x0(31); lwz 9,0x0(10); rlwinm 0,0,0,25,31; lha 11,0x8(9); addi 7,9,8; cmpwi 0,1; add 3,10,11; beq 2f; lwz 8,0x24(8); 2:; lwz 4,0xc(8); lwz 0,0x4(7); addi 4,4,8; mtspr 8,0; blrl; b 4f; 3:; lwz 3,-27576(13); li 4,0; lwz 9,0x0(3); lha 0,0x8(9); lwz 9,0xc(9); add 3,3,0; mtspr 8,9; blrl; 4:; cmpwi 3,0; beq 5f; stw 3,0x24(30); 5:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802B958C_0();

struct AptXml {
    void AptXml_AptValue();
};

void AptXml::AptXml_AptValue() {
}
