// 0x80290B58 AptCIH::deallocAssetStringRecursive(void) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 29,0; li 30,0; bl _s80290B58_0; cmpwi 3,13; bne 0f; mr 3,31; bl _s80290B58_1; subfic 0,3,0; adde 30,0,3; 0:; cmpwi 30,0; bne 2f; mr 3,31; li 30,0; bl _s80290B58_2; cmpwi 3,18; bne 1f; mr 3,31; bl _s80290B58_3; subfic 0,3,0; adde 30,0,3; 1:; cmpwi 30,0; beq 3f; 2:; li 29,1; 3:; cmpwi 29,0; beq 4f; lwz 3,0x4c(31); addi 3,3,36; bl _s80290B58_4; b 7f; 4:; mr 3,31; li 30,0; bl _s80290B58_5; cmpwi 3,15; bne 5f; mr 3,31; bl _s80290B58_6; subfic 0,3,0; adde 30,0,3; 5:; cmpwi 30,0; beq 7f; lwz 31,0x4c(31); lwz 3,0x20(31); cmpwi 3,0; beq 6f; addi 0,13,-27404; cmpw 3,0; beq 6f; li 0,6; lis 9,-32694; stw 0,0x6c(31); li 4,2; lwz 0,-16212(9); mtspr 8,0; blrl; 6:; li 0,0; stw 0,0x20(31); 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80290B58_0();
extern "C" void _s80290B58_1();
extern "C" void _s80290B58_2();
extern "C" void _s80290B58_3();
extern "C" void _s80290B58_4();
extern "C" void _s80290B58_5();
extern "C" void _s80290B58_6();

struct AptCIH {
    void deallocAssetStringRecursive();
};

void AptCIH::deallocAssetStringRecursive() {
}
