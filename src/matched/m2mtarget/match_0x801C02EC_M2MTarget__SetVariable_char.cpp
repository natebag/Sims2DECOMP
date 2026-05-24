// 0x801C02EC M2MTarget::SetVariable(char (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; lbz 3,0x0(30); extsb 3,3; bl _s801C02EC_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; lis 3,-32705; mr 4,30; addi 3,3,8620; bl _s801C02EC_1; cmpwi 3,0; bne 1f; lwz 4,0x18c(31); mr 3,31; bl _s801C02EC_2; cmpwi 3,0; beq 4f; lwz 0,0x184(31); cmpwi 0,0; beq 4f; lwz 0,0x168(31); cmpwi 0,2; bne 4f; lwz 4,0x18c(31); mr 3,31; addi 5,31,268; bl _s801C02EC_3; lis 3,-32705; lwz 4,0x10c(31); addi 3,3,8636; bl _s801C02EC_4; lwz 0,0x10c(31); lis 9,-32696; mr 3,31; stw 0,0x58d8(9); bl _s801C02EC_5; b 4f; 1:; lis 3,-32705; mr 4,30; addi 3,3,8656; bl _s801C02EC_6; cmpwi 3,0; bne 2f; lwz 0,0x168(31); cmpwi 0,2; bne 4f; mr 3,31; li 4,-1; bl _s801C02EC_7; b 4f; 2:; lis 3,-32705; mr 4,30; addi 3,3,8668; bl _s801C02EC_8; cmpwi 3,0; bne 3f; lwz 0,0x168(31); cmpwi 0,2; bne 4f; mr 3,31; li 4,1; bl _s801C02EC_9; b 4f; 3:; lis 3,-32705; mr 4,30; addi 3,3,8684; bl _s801C02EC_10; cmpwi 3,0; beq 4f; lis 3,-32705; mr 4,30; addi 3,3,8704; bl _s801C02EC_11; cmpwi 3,0; bne 4f; lwz 0,0x184(31); cmpwi 0,0; beq 4f; lwz 0,0x168(31); cmpwi 0,2; bne 4f; mr 3,31; bl _s801C02EC_12; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801C02EC_0();
extern "C" void _s801C02EC_1();
extern "C" void _s801C02EC_2();
extern "C" void _s801C02EC_3();
extern "C" void _s801C02EC_4();
extern "C" void _s801C02EC_5();
extern "C" void _s801C02EC_6();
extern "C" void _s801C02EC_7();
extern "C" void _s801C02EC_8();
extern "C" void _s801C02EC_9();
extern "C" void _s801C02EC_10();
extern "C" void _s801C02EC_11();
extern "C" void _s801C02EC_12();

struct M2MTarget {
    void SetVariable();
};

void M2MTarget::SetVariable() {
}
