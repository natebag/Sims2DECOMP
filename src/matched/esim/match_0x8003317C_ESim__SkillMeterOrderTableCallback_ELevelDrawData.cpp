// 0x8003317C ESim::SkillMeterOrderTableCallback(ELevelDrawData (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,0x24(4); mr 31,3; lwz 0,0x3ec(9); cmplwi 0,4; bgt 0f; cmplwi 0,3; bge 1f; cmpwi 0,0; beq 1f; b 2f; 0:; cmpwi 0,7; beq 1f; cmplwi 0,7; blt 2f; cmplwi 0,9; bgt 3f; b 2f; 1:; lwz 4,0x98(31); mr 3,9; bl _s8003317C_0; b 3f; 2:; lwz 4,0x98(31); mr 3,9; bl _s8003317C_1; 3:; li 0,0; stw 0,0xb8(31); stw 0,0xa8(31); stw 0,0xac(31); stw 0,0xb4(31); stw 0,0xb0(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s8003317C_0();
extern "C" void _s8003317C_1();

struct ESim {
    void SkillMeterOrderTableCallback_ELevelDrawData();
};

void ESim::SkillMeterOrderTableCallback_ELevelDrawData() {
}
