// 0x80233368 ERLevel::InsertSkydomeInstance(EInstance (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s80233368_0; addis 31,30,3; stw 30,0x4(29); lwz 0,-25228(31); lwz 9,-15688(31); rlwinm 0,0,2,0,29; add 11,0,30; rlwinm 9,9,2,0,29; mr 3,11; add 9,9,30; addis 11,11,3; addis 9,9,3; addi 4,11,-23880; addi 5,9,-23880; addis 11,3,3; cmpw 5,4; addi 3,11,-23876; beq 0f; subf 5,4,5; bl _s80233368_1; 0:; lwz 0,-25228(31); addi 11,31,-23880; rlwinm 0,0,2,0,29; stwx 29,11,0; lwz 9,-25228(31); lwz 11,-15676(31); lwz 10,-15688(31); addi 9,9,1; addi 11,11,1; stw 9,-25228(31); addi 10,10,1; stw 11,-15676(31); stw 10,-15688(31); lwz 0,0x5c(29); andi. 9,0,256; beq 1f; lwz 9,0x0(29); lha 3,0xb0(9); lwz 0,0xb4(9); add 3,29,3; mtspr 8,0; blrl; mr 4,3; mr 5,29; addi 3,31,-23948; li 6,1; bl _s80233368_2; stw 3,0x34(29); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80233368_0();
extern "C" void _s80233368_1();
extern "C" void _s80233368_2();

struct ERLevel {
    void InsertSkydomeInstance_EInstance();
};

void ERLevel::InsertSkydomeInstance_EInstance() {
}
