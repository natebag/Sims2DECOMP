// 0x80284C2C AptAnimationPoolData::RegisterReferences(void) (684 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 29,3; lwz 4,0x64(29); cmpwi 4,0; beq 0f; lwz 9,-27024(13); lis 5,-32704; addi 5,5,12356; li 3,0; mtspr 8,9; blrl; 0:; lwz 4,0x94(29); cmpwi 4,0; beq 1f; lwz 9,-27024(13); lis 5,-32704; addi 5,5,12392; li 3,0; mtspr 8,9; blrl; 1:; lwz 0,0x4(29); li 31,0; addi 27,29,8; addi 26,29,24; cmpw 31,0; addi 25,29,32; bge 3f; lis 28,-32704; li 30,0; 2:; lwz 9,0x0(29); li 3,0; lwz 11,-27024(13); addi 5,28,12428; lwzx 4,30,9; addi 31,31,1; mtspr 8,11; addi 30,30,4; blrl; lwz 0,0x4(29); cmpw 31,0; blt 2b; 3:; lwz 0,0x10(29); li 30,0; cmpwi 0,0; ble 5f; lis 28,-32704; li 31,0; 4:; lwz 9,0x14(29); li 3,0; lwz 11,-27024(13); addi 5,28,12464; lwzx 4,31,9; addi 30,30,1; mtspr 8,11; addi 31,31,28; blrl; lwz 0,0x10(29); cmpw 30,0; blt 4b; 5:; lhz 31,0x2(27); cmpwi 31,0; beq 8f; lis 28,-32704; li 30,0; 6:; lwz 9,0xc(29); lwzx 4,30,9; cmpwi 4,0; beq 7f; lwz 9,-27024(13); li 3,0; addi 5,28,12516; mtspr 8,9; blrl; 7:; addi 30,30,4; addic. 31,31,-1; bne 6b; 8:; lhz 31,0x2(26); cmpwi 31,0; beq 11f; lis 28,-32704; li 30,0; 9:; lwz 9,0x1c(29); lwzx 4,30,9; cmpwi 4,0; beq 10f; lwz 9,-27024(13); li 3,0; addi 5,28,12560; mtspr 8,9; blrl; 10:; addi 30,30,4; addic. 31,31,-1; bne 9b; 11:; lhz 31,0x2(25); cmpwi 31,0; beq 14f; lis 28,-32704; li 30,0; 12:; lwz 9,0x24(29); lwzx 4,30,9; cmpwi 4,0; beq 13f; lwz 9,-27024(13); li 3,0; addi 5,28,12604; mtspr 8,9; blrl; 13:; addi 30,30,4; addic. 31,31,-1; bne 12b; 14:; lwz 3,0x28(29); cmpwi 3,0; beq 15f; li 4,0; bl _s80284C2C_0; 15:; lwz 3,0x98(29); bl _s80284C2C_1; lwz 0,0xa0(29); li 10,0; cmpw 10,0; bge 19f; lis 25,-32704; 16:; lwz 11,0x2c(29); rlwinm 9,10,5,0,26; addi 26,10,1; mr 28,9; lwzx 0,9,11; add 10,9,11; cmpwi 0,0; beq 18f; lwz 9,-27024(13); li 3,0; lwz 4,0x4(10); addi 5,25,12648; mtspr 8,9; li 30,0; blrl; lwz 9,0x2c(29); add 9,28,9; lwz 31,0x14(9); cmpw 30,31; bge 18f; lis 27,-32704; 17:; lwz 9,0x2c(29); li 3,0; lwz 10,-27024(13); addi 5,27,12704; add 9,28,9; lwzu 11,0x14(9); mtspr 8,10; subf 11,30,11; lwz 0,0x8(9); rlwinm 11,11,2,0,29; addi 30,30,1; add 11,11,0; lwz 4,-4(11); blrl; cmpw 30,31; blt 17b; 18:; lwz 0,0xa0(29); mr 10,26; cmpw 10,0; blt 16b; 19:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s80284C2C_0();
extern "C" void _s80284C2C_1();

struct AptAnimationPoolData {
    void RegisterReferences();
};

void AptAnimationPoolData::RegisterReferences() {
}
