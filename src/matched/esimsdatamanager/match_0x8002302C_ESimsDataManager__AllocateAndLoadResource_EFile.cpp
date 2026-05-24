// 0x8002302C ESimsDataManager::AllocateAndLoadResource(EFile (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 30,4; lwz 0,0xd20(31); mr 29,5; cmpwi 0,1; beq 0f; cmpwi 0,2; beq 1f; b 5f; 0:; mr 4,29; mr 3,31; bl _s8002302C_0; li 0,0; stw 0,0xd20(31); b 5f; 1:; lwz 9,0x28(30); lha 3,0x30(9); lwz 0,0x34(9); add 3,30,3; mtspr 8,0; blrl; mr. 28,3; bne 3f; stw 29,0xd30(31); lwz 9,0xd30(31); lwz 0,0x9c(9); cmpwi 0,1; bne 2f; lwz 4,0xd30(31); mr 3,31; bl _s8002302C_1; 2:; stw 28,0xd30(31); b 4f; 3:; lwz 9,0x28(30); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; mr 30,3; mr 4,29; bl _s8002302C_2; stw 31,0x8(1); li 4,-1; lwz 9,0x0(31); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x43c(30); addi 9,9,-1; stw 9,0x43c(30); lwz 11,0x8(1); lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 4:; mr 3,31; bl _s8002302C_3; 5:; li 3,0; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s8002302C_0();
extern "C" void _s8002302C_1();
extern "C" void _s8002302C_2();
extern "C" void _s8002302C_3();

struct ESimsDataManager {
    void AllocateAndLoadResource_EFile();
};

void ESimsDataManager::AllocateAndLoadResource_EFile() {
}
