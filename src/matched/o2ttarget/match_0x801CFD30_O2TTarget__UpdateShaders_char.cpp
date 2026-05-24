// 0x801CFD30 O2TTarget::UpdateShaders(char (532 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr 3,5; bl _s801CFD30_0; mr. 3,3; bne 2f; lwz 0,0x0(31); lis 9,-32705; addi 4,9,16152; cmpwi 0,0; beq 0f; lwz 3,0x1c(31); cmpwi 3,0; beq 0f; lis 5,-32449; lwz 6,0x7c(31); ori 5,5,28160; li 7,0; bl _s801CFD30_1; 0:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,16168; cmpwi 0,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lis 5,10675; lwz 6,0x7c(31); ori 5,5,44782; li 7,0; bl _s801CFD30_2; 1:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,16184; cmpwi 0,0; beq 9f; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lis 5,-16877; lwz 6,0x7c(31); ori 5,5,57255; b 5f; 2:; cmpwi 3,2; bne 6f; lwz 0,0x0(31); lis 9,-32705; addi 4,9,16168; cmpwi 0,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lis 5,28305; lwz 6,0x7c(31); ori 5,5,628; li 7,0; bl _s801CFD30_3; 3:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,16184; cmpwi 0,0; beq 4f; lwz 3,0x1c(31); cmpwi 3,0; beq 4f; lis 5,-16877; lwz 6,0x7c(31); ori 5,5,57255; li 7,0; bl _s801CFD30_4; 4:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,16152; cmpwi 0,0; beq 9f; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lis 5,-29864; lwz 6,0x7c(31); ori 5,5,63259; 5:; li 7,0; bl _s801CFD30_5; b 9f; 6:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,16168; cmpwi 0,0; beq 7f; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lis 5,10675; lwz 6,0x7c(31); ori 5,5,44782; li 7,0; bl _s801CFD30_6; 7:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,16184; cmpwi 0,0; beq 8f; lwz 3,0x1c(31); cmpwi 3,0; beq 8f; lis 5,-3800; lwz 6,0x7c(31); ori 5,5,24563; li 7,0; bl _s801CFD30_7; 8:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,16152; cmpwi 0,0; beq 9f; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lis 5,-29864; lwz 6,0x7c(31); ori 5,5,63259; li 7,0; bl _s801CFD30_8; 9:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801CFD30_0();
extern "C" void _s801CFD30_1();
extern "C" void _s801CFD30_2();
extern "C" void _s801CFD30_3();
extern "C" void _s801CFD30_4();
extern "C" void _s801CFD30_5();
extern "C" void _s801CFD30_6();
extern "C" void _s801CFD30_7();
extern "C" void _s801CFD30_8();

struct O2TTarget {
    void UpdateShaders();
};

void O2TTarget::UpdateShaders() {
}
