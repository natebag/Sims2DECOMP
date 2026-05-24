// 0x8003B638 GameData::PrepareSimData(int, (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,5; mr. 4,4; bge 2f; lis 3,-32707; addi 3,3,7660; bl _s8003B638_0; cmpwi 3,0; bne 0f; lis 9,-32697; lwz 4,0x6214(9); cmpwi 4,0; bne 1f; li 4,1; b 1f; 0:; lis 9,-32697; lwz 4,0x6218(9); 1:; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); mr 4,31; lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; lwz 11,-21476(13); lwz 4,0x0(3); lwz 9,0x0(11); lha 3,0xc0(9); lwz 0,0xc4(9); add 3,11,3; mtspr 8,0; blrl; b 3f; 2:; lwz 3,-21476(13); lwz 9,0x0(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; 3:; cmpwi 3,0; beq 4f; lwz 9,0x78(30); rlwinm 11,31,2,0,29; lha 0,0x4(3); mulli 10,31,392; addi 9,9,1600; stwx 0,9,11; lwz 4,0x78(30); add 4,4,10; bl _s8003B638_1; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8003B638_0();
extern "C" void _s8003B638_1();

struct GameData {
    void PrepareSimData();
};

void GameData::PrepareSimData() {
}
