// 0x8002B9A4 EIWallPart::GetPoint(CTilePt (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 29,4; addi 31,30,808; mr 3,29; mr 4,31; bl _s8002B9A4_0; lwz 0,0x320(30); li 9,1; andi. 11,0,48; bne 0f; li 9,0; 0:; cmpwi 9,0; beq 8f; lwz 3,0x324(30); cmpwi 3,2; beq 4f; bgt 1f; cmpwi 3,1; beq 2f; b 8f; 1:; cmpwi 3,3; beq 3f; cmpwi 3,4; beq 7f; b 8f; 2:; mr 3,31; bl _s8002B9A4_1; addi 30,3,1; b 5f; 3:; mr 3,31; bl _s8002B9A4_2; addi 30,3,-1; mr 3,31; bl _s8002B9A4_3; addi 5,3,1; b 6f; 4:; mr 3,31; bl _s8002B9A4_4; addi 30,3,-1; 5:; mr 3,31; bl _s8002B9A4_5; addi 5,3,-1; 6:; mr 4,30; li 6,1; addi 3,1,8; bl _s8002B9A4_6; addi 4,1,8; mr 3,29; bl _s8002B9A4_7; addi 3,1,8; li 4,2; bl _s8002B9A4_8; b 8f; 7:; mr 3,31; bl _s8002B9A4_9; addi 30,3,1; mr 3,31; bl _s8002B9A4_10; addi 5,3,1; mr 4,30; li 6,1; addi 3,1,8; bl _s8002B9A4_11; addi 4,1,8; mr 3,29; bl _s8002B9A4_12; addi 3,1,8; li 4,2; bl _s8002B9A4_13; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s8002B9A4_0();
extern "C" void _s8002B9A4_1();
extern "C" void _s8002B9A4_2();
extern "C" void _s8002B9A4_3();
extern "C" void _s8002B9A4_4();
extern "C" void _s8002B9A4_5();
extern "C" void _s8002B9A4_6();
extern "C" void _s8002B9A4_7();
extern "C" void _s8002B9A4_8();
extern "C" void _s8002B9A4_9();
extern "C" void _s8002B9A4_10();
extern "C" void _s8002B9A4_11();
extern "C" void _s8002B9A4_12();
extern "C" void _s8002B9A4_13();

struct EIWallPart {
    void GetPoint_CTilePt();
};

void EIWallPart::GetPoint_CTilePt() {
}
