// 0x80083338 MUWrapper::SetupInfoType(void) (1164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 28,0x50(1); stw 0,0x64(1); mr 31,3; li 30,1; lwz 0,0xbc(31); cmpwi 0,4; beq 8f; bgt 0f; cmpwi 0,1; beq 2f; ble 22f; cmpwi 0,2; beq 4f; cmpwi 0,3; beq 6f; b 22f; 0:; cmpwi 0,7; beq 18f; bgt 1f; cmpwi 0,5; beq 10f; cmpwi 0,6; beq 12f; b 22f; 1:; cmpwi 0,11; beq 14f; cmpwi 0,12; beq 16f; b 22f; 2:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,8; lis 28,-32697; crxor 6,6,6; bl _s80083338_0; lis 29,-32707; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80083338_1; addi 4,28,24012; addi 5,29,27740; addi 3,1,12; crxor 6,6,6; bl _s80083338_2; lwz 9,0xc(1); b 20f; 4:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,16; lis 28,-32697; crxor 6,6,6; bl _s80083338_3; lis 29,-32707; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80083338_4; addi 4,28,24012; addi 5,29,27740; addi 3,1,20; crxor 6,6,6; bl _s80083338_5; lwz 9,0x14(1); b 20f; 6:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,24; lis 28,-32697; crxor 6,6,6; bl _s80083338_6; lis 29,-32707; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80083338_7; addi 4,28,24012; addi 5,29,27740; addi 3,1,28; crxor 6,6,6; bl _s80083338_8; lwz 9,0x1c(1); b 20f; 8:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,32; lis 28,-32697; crxor 6,6,6; bl _s80083338_9; lis 29,-32707; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 9f; lwz 4,0x0(9); 9:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80083338_10; addi 4,28,24012; addi 5,29,27740; addi 3,1,36; crxor 6,6,6; bl _s80083338_11; lwz 9,0x24(1); b 20f; 10:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,40; lis 28,-32697; crxor 6,6,6; bl _s80083338_12; lis 29,-32707; lwz 9,0x28(1); li 4,0; cmpwi 9,0; beq 11f; lwz 4,0x0(9); 11:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80083338_13; addi 4,28,24012; addi 5,29,27740; addi 3,1,44; crxor 6,6,6; bl _s80083338_14; lwz 9,0x2c(1); b 20f; 12:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,48; lis 28,-32697; crxor 6,6,6; bl _s80083338_15; lis 29,-32707; lwz 9,0x30(1); li 4,0; cmpwi 9,0; beq 13f; lwz 4,0x0(9); 13:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80083338_16; addi 4,28,24012; addi 5,29,27740; addi 3,1,52; crxor 6,6,6; bl _s80083338_17; lwz 9,0x34(1); b 20f; 14:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,56; lis 28,-32697; crxor 6,6,6; bl _s80083338_18; lis 29,-32707; lwz 9,0x38(1); li 4,0; cmpwi 9,0; beq 15f; lwz 4,0x0(9); 15:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80083338_19; addi 4,28,24012; addi 5,29,27740; addi 3,1,60; crxor 6,6,6; bl _s80083338_20; lwz 9,0x3c(1); b 20f; 16:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,64; lis 28,-32697; crxor 6,6,6; bl _s80083338_21; lis 29,-32707; lwz 9,0x40(1); li 4,0; cmpwi 9,0; beq 17f; lwz 4,0x0(9); 17:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80083338_22; addi 4,28,24012; addi 5,29,27740; addi 3,1,68; crxor 6,6,6; bl _s80083338_23; lwz 9,0x44(1); b 20f; 18:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,72; lis 28,-32697; crxor 6,6,6; bl _s80083338_24; lis 29,-32707; lwz 9,0x48(1); li 4,0; cmpwi 9,0; beq 19f; lwz 4,0x0(9); 19:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80083338_25; addi 4,28,24012; addi 5,29,27740; addi 3,1,76; crxor 6,6,6; bl _s80083338_26; lwz 9,0x4c(1); 20:; li 4,0; cmpwi 9,0; beq 21f; lwz 4,0x0(9); 21:; lwz 9,0xa8(31); lwz 3,0x64(9); bl _s80083338_27; b 23f; 22:; li 30,0; 23:; cmpwi 30,0; beq 26f; lwz 9,0xb0(31); addi 9,9,-12; cmplwi 9,1; bgt 24f; lwz 9,0xa8(31); lwz 11,0x60(9); lwz 0,0x4(11); rlwinm 0,0,0,0,30; b 25f; 24:; lwz 9,0xa8(31); lwz 11,0x60(9); lwz 0,0x4(11); ori 0,0,1; 25:; stw 0,0x4(11); lwz 9,0xa8(31); lwz 11,0x64(9); lwz 0,0x4(11); ori 0,0,1; b 27f; 26:; lwz 9,0xa8(31); lwz 11,0x60(9); lwz 0,0x4(11); rlwinm 0,0,0,0,30; stw 0,0x4(11); lwz 9,0xa8(31); lwz 11,0x64(9); lwz 0,0x4(11); rlwinm 0,0,0,0,30; 27:; stw 0,0x4(11); lwz 0,0x64(1); mtspr 8,0; lmw 28,0x50(1); addi 1,1,96"

extern "C" void _s80083338_0();
extern "C" void _s80083338_1();
extern "C" void _s80083338_2();
extern "C" void _s80083338_3();
extern "C" void _s80083338_4();
extern "C" void _s80083338_5();
extern "C" void _s80083338_6();
extern "C" void _s80083338_7();
extern "C" void _s80083338_8();
extern "C" void _s80083338_9();
extern "C" void _s80083338_10();
extern "C" void _s80083338_11();
extern "C" void _s80083338_12();
extern "C" void _s80083338_13();
extern "C" void _s80083338_14();
extern "C" void _s80083338_15();
extern "C" void _s80083338_16();
extern "C" void _s80083338_17();
extern "C" void _s80083338_18();
extern "C" void _s80083338_19();
extern "C" void _s80083338_20();
extern "C" void _s80083338_21();
extern "C" void _s80083338_22();
extern "C" void _s80083338_23();
extern "C" void _s80083338_24();
extern "C" void _s80083338_25();
extern "C" void _s80083338_26();
extern "C" void _s80083338_27();

struct MUWrapper {
    void SetupInfoType();
};

void MUWrapper::SetupInfoType() {
}
