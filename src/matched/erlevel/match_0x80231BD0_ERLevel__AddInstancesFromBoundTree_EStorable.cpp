// 0x80231BD0 ERLevel::AddInstancesFromBoundTree(EStorable (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr. 31,4; beq 1f; lis 4,-32688; mr 3,31; addi 4,4,-13040; bl _s80231BD0_0; mr. 3,3; beq 0f; lwz 4,0x20(31); mr 3,30; bl _s80231BD0_1; lwz 4,0x24(31); mr 3,30; bl _s80231BD0_2; lwz 9,0x0(31); lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; lwz 9,0x5c(31); addis 11,30,3; stw 3,0x38(31); addi 10,11,-23880; rlwinm 9,9,0,25,23; stw 9,0x5c(31); lwz 0,-15688(11); rlwinm 0,0,2,0,29; stwx 31,10,0; lwz 9,-15688(11); addi 9,9,1; stw 9,-15688(11); 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80231BD0_0();
extern "C" void _s80231BD0_1();
extern "C" void _s80231BD0_2();

struct ERLevel {
    void AddInstancesFromBoundTree();
};

void ERLevel::AddInstancesFromBoundTree() {
}
