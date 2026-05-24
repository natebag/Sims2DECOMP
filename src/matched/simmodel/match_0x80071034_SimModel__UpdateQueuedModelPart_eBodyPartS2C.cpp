// 0x80071034 SimModel::UpdateQueuedModelPart(eBodyPartS2C, (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 28,4; mr 30,3; rlwinm 31,28,2,0,29; mr 25,5; lwzx 0,31,30; mr 24,6; andi. 9,0,32; beq 2f; addi 29,30,208; lwzx 4,29,31; cmpwi 4,0; beq 3f; lis 27,-32692; addi 3,27,-27556; bl _s80071034_0; mr. 26,3; bne 0f; lwzx 4,29,31; addi 3,27,-27556; li 5,0; li 6,0; bl _s80071034_1; mr. 26,3; beq 3f; 0:; li 27,0; mr 5,25; stwx 27,29,31; mr 6,24; mr 3,30; mr 4,28; lwzx 0,31,30; rlwinm 0,0,0,27,25; ori 0,0,64; stwx 0,31,30; bl _s80071034_2; addi 11,30,104; mr 29,3; lwzx 9,11,31; lwz 9,0x120(9); cmpwi 9,0; beq 1f; lha 0,0xc(9); cmpwi 0,1; bgt 1f; stwx 27,11,31; li 3,0; lwzx 0,31,30; rlwinm 0,0,0,31,26; stwx 0,31,30; b 4f; 1:; mr 3,26; bl _s80071034_3; rlwinm 9,28,2,0,29; mr 3,29; lwzx 0,9,30; rlwinm 0,0,0,26,24; stwx 0,9,30; b 4f; 2:; mr 3,30; mr 4,28; mr 5,25; mr 6,24; bl _s80071034_4; b 4f; 3:; li 3,0; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s80071034_0();
extern "C" void _s80071034_1();
extern "C" void _s80071034_2();
extern "C" void _s80071034_3();
extern "C" void _s80071034_4();

struct SimModel {
    void UpdateQueuedModelPart_eBodyPartS2C();
};

void SimModel::UpdateQueuedModelPart_eBodyPartS2C() {
}
