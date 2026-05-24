// 0x8013825C Room::PrintStats(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lis 4,-32706; addi 4,4,-11368; addi 3,13,-24588; bl _s8013825C_0; lhz 4,0x0(31); bl _s8013825C_1; lis 4,-32706; addi 4,4,-11360; bl _s8013825C_2; lwz 0,0x34(31); cmpwi 0,0; beq 0f; lis 9,-32706; addi 4,9,-11348; b 1f; 0:; lis 9,-32706; addi 4,9,-11340; 1:; bl _s8013825C_3; lis 4,-32706; addi 4,4,-11336; bl _s8013825C_4; lwz 9,0x4(31); lis 0,-21846; lwz 4,0x8(31); ori 0,0,43691; subf 4,9,4; mullw 4,4,0; bl _s8013825C_5; lis 4,-32706; addi 4,4,-11440; bl _s8013825C_6; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s8013825C_0();
extern "C" void _s8013825C_1();
extern "C" void _s8013825C_2();
extern "C" void _s8013825C_3();
extern "C" void _s8013825C_4();
extern "C" void _s8013825C_5();
extern "C" void _s8013825C_6();

struct Room {
    void PrintStats();
};

void Room::PrintStats() {
}
