// 0x801D464C PCTTarget::Update(void) (856 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 27,0x4c(1); stw 0,0x64(1); mr 31,3; lwz 3,0xe4(31); cmpwi 3,0; beq 0f; bl _s801D464C_0; 0:; lwz 3,0x214(31); cmpwi 3,0; beq 1f; bl _s801D464C_1; cmpwi 3,0; beq 1f; lwz 3,0x214(31); bl _s801D464C_2; 1:; lwz 0,0x23c(31); cmpwi 0,0; bne 2f; lwz 0,0x234(31); cmpwi 0,0; bne 2f; lwz 0,0x238(31); cmpwi 0,0; beq 17f; 2:; li 27,0; lis 4,-32697; stw 27,0xf8(31); lis 5,-32705; addi 4,4,24012; addi 5,5,18168; addi 3,1,24; addi 30,31,288; crxor 6,6,6; bl _s801D464C_3; lis 29,-32697; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; mr 3,30; bl _s801D464C_4; lwz 28,0x23c(31); cmpwi 28,0; beq 5f; lis 5,-32705; addi 4,29,24012; addi 5,5,18192; addi 3,1,28; crxor 6,6,6; bl _s801D464C_5; addi 30,31,284; lwz 9,0x1c(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,30; bl _s801D464C_6; stw 27,0x23c(31); b 9f; 5:; lwz 27,0x234(31); cmpwi 27,0; beq 7f; lis 5,-32705; addi 4,29,24012; addi 5,5,18208; addi 3,1,32; crxor 6,6,6; bl _s801D464C_7; addi 30,31,284; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 6f; lwz 4,0x0(9); 6:; mr 3,30; bl _s801D464C_8; stw 28,0x234(31); b 9f; 7:; lwz 0,0x238(31); cmpwi 0,0; beq 9f; lis 5,-32705; addi 4,29,24012; addi 5,5,18224; addi 3,1,36; crxor 6,6,6; bl _s801D464C_9; addi 30,31,284; lwz 9,0x24(1); li 4,0; cmpwi 9,0; beq 8f; lwz 4,0x0(9); 8:; mr 3,30; bl _s801D464C_10; stw 27,0x238(31); 9:; li 0,1; lis 4,-32697; lis 5,-32705; addi 4,4,24012; stw 0,0xf4(31); addi 5,5,-1988; addi 3,1,40; addi 30,31,292; crxor 6,6,6; bl _s801D464C_11; lwz 9,0x28(1); li 4,0; cmpwi 9,0; beq 10f; lwz 4,0x0(9); 10:; mr 3,30; bl _s801D464C_12; lis 9,-32705; cmpwi 31,0; addi 9,9,18240; lis 10,-32708; lwz 11,0x0(9); lwz 12,0x4(9); mfcr 29; addi 4,1,48; addi 30,10,-26360; stw 31,0x10(1); stw 11,0x30(1); stw 12,0x34(1); beq 11f; addi 3,1,8; li 5,8; bl _s801D464C_13; b 12f; 11:; stw 31,0x8(1); 12:; stw 30,0x14(1); lis 9,-32705; addi 11,1,8; lwz 4,0x8(1); addi 9,9,18248; lwz 5,0x4(11); lwz 6,0x8(11); addi 10,31,324; lwz 0,0xc(11); mr 30,11; lwz 7,0x0(9); lwz 8,0x4(9); mtcrf 128,29; stw 4,0x144(31); lis 9,-32708; stw 0,0xc(10); addi 28,9,-26600; stw 5,0x4(10); addi 9,1,56; stw 6,0x8(10); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq 13f; mr 4,9; mr 3,30; li 5,8; bl _s801D464C_14; b 14f; 13:; stw 31,0x8(1); 14:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,18256; lwz 5,0x8(30); addi 11,31,340; lwz 10,0x4(30); addi 4,1,64; lwz 0,0xc(30); mtcrf 128,29; stw 6,0x154(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32708; stw 10,0x4(11); addi 28,9,-26600; stw 5,0x8(11); stw 7,0x40(1); stw 8,0x44(1); stw 31,0x10(1); beq 15f; mr 3,30; li 5,8; bl _s801D464C_15; b 16f; 15:; stw 31,0x8(1); 16:; stw 28,0x14(1); addi 9,31,356; lwz 8,0x8(1); lis 3,14340; lwz 0,0x4(30); ori 3,3,8607; lwz 10,0xc(30); lwz 11,0x8(30); stw 8,0x164(31); stw 0,0x4(9); stw 10,0xc(9); stw 11,0x8(9); bl _s801D464C_16; li 0,1; addi 3,31,244; stw 0,0xf0(31); bl _s801D464C_17; 17:; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x4c(1); addi 1,1,96"

extern "C" void _s801D464C_0();
extern "C" void _s801D464C_1();
extern "C" void _s801D464C_2();
extern "C" void _s801D464C_3();
extern "C" void _s801D464C_4();
extern "C" void _s801D464C_5();
extern "C" void _s801D464C_6();
extern "C" void _s801D464C_7();
extern "C" void _s801D464C_8();
extern "C" void _s801D464C_9();
extern "C" void _s801D464C_10();
extern "C" void _s801D464C_11();
extern "C" void _s801D464C_12();
extern "C" void _s801D464C_13();
extern "C" void _s801D464C_14();
extern "C" void _s801D464C_15();
extern "C" void _s801D464C_16();
extern "C" void _s801D464C_17();

struct PCTTarget {
    void Update();
};

void PCTTarget::Update() {
}
