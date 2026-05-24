// 0x801D597C PCTTarget::on_PCT_EnterPlaceMode(void) (772 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stmw 29,0x44(1); stw 0,0x54(1); stw 12,0x40(1); mr 31,3; lwz 4,0xb8(31); bl _s801D597C_0; mr. 3,3; beq 13f; lwz 0,0x0(3); lis 9,-32705; lfs f1,0x4790(9); cmpwi 0,0; beq 13f; blt 13f; cmpwi 0,4; bgt 13f; cmpwi 0,2; beq 0f; bgt 2f; cmpwi 0,1; bne 2f; li 3,1; bl _s801D597C_1; b 2f; 0:; lwz 0,0x4(3); cmpwi 0,-1; bne 1f; addi 3,1,24; bl _s801D597C_2; b 2f; 1:; bl _s801D597C_3; 2:; lis 9,-32705; lfs f0,0x4794(9); fcmpu 0,f1,f0; cror 3,2,1; bns 12f; li 0,0; lis 29,-32697; lis 5,-32705; addi 4,29,24012; stw 0,0xf8(31); addi 5,5,18168; addi 3,1,28; addi 30,31,288; crxor 6,6,6; bl _s801D597C_4; lwz 9,0x1c(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; mr 3,30; bl _s801D597C_5; addi 30,31,284; lis 5,-32705; lis 4,-32697; addi 4,4,24012; addi 5,5,18224; addi 3,1,32; crxor 6,6,6; bl _s801D597C_6; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,30; bl _s801D597C_7; addi 30,31,292; li 0,1; lis 5,-32705; addi 4,29,24012; stw 0,0xf4(31); addi 5,5,-1988; addi 3,1,36; crxor 6,6,6; bl _s801D597C_8; lwz 9,0x24(1); li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; mr 3,30; cmpwi 4,31,0; bl _s801D597C_9; lis 9,-32705; lis 10,-32708; addi 9,9,18240; addi 4,1,40; lwz 11,0x0(9); lwz 12,0x4(9); addi 30,10,-26360; stw 31,0x10(1); stw 11,0x28(1); stw 12,0x2c(1); beq cr4,6f; addi 3,1,8; li 5,8; bl _s801D597C_10; b 7f; 6:; stw 31,0x8(1); 7:; stw 30,0x14(1); lis 9,-32705; addi 11,1,8; lwz 4,0x8(1); addi 9,9,18248; lwz 5,0x4(11); lwz 6,0x8(11); addi 10,31,324; lwz 0,0xc(11); mr 30,11; lwz 7,0x0(9); lwz 8,0x4(9); stw 4,0x144(31); lis 9,-32708; stw 0,0xc(10); addi 29,9,-26600; stw 5,0x4(10); addi 9,1,48; stw 6,0x8(10); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq cr4,8f; mr 4,9; mr 3,30; li 5,8; bl _s801D597C_11; b 9f; 8:; stw 31,0x8(1); 9:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,18256; lwz 5,0x8(30); addi 11,31,340; lwz 10,0x4(30); addi 4,1,56; lwz 0,0xc(30); stw 6,0x154(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32708; stw 10,0x4(11); addi 29,9,-26600; stw 5,0x8(11); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq cr4,10f; mr 3,30; li 5,8; bl _s801D597C_12; b 11f; 10:; stw 31,0x8(1); 11:; stw 29,0x14(1); addi 9,31,356; lwz 8,0x8(1); li 7,0; lwz 10,0xc(30); lis 3,14340; lwz 11,0x4(30); ori 3,3,8607; lwz 0,0x8(30); stw 8,0x164(31); stw 0,0x8(9); stw 10,0xc(9); stw 11,0x4(9); stw 7,0x108(31); bl _s801D597C_13; li 0,1; addi 3,31,244; stw 0,0xf0(31); bl _s801D597C_14; b 13f; 12:; li 0,1; mr 3,31; stw 0,0xe8(31); li 4,0; bl _s801D597C_15; b 14f; 13:; li 3,0; 14:; lwz 0,0x54(1); lwz 12,0x40(1); mtspr 8,0; lmw 29,0x44(1); mtcrf 8,12; addi 1,1,80"

extern "C" void _s801D597C_0();
extern "C" void _s801D597C_1();
extern "C" void _s801D597C_2();
extern "C" void _s801D597C_3();
extern "C" void _s801D597C_4();
extern "C" void _s801D597C_5();
extern "C" void _s801D597C_6();
extern "C" void _s801D597C_7();
extern "C" void _s801D597C_8();
extern "C" void _s801D597C_9();
extern "C" void _s801D597C_10();
extern "C" void _s801D597C_11();
extern "C" void _s801D597C_12();
extern "C" void _s801D597C_13();
extern "C" void _s801D597C_14();
extern "C" void _s801D597C_15();

struct PCTTarget {
    void on_PCT_EnterPlaceMode();
};

void PCTTarget::on_PCT_EnterPlaceMode() {
}
