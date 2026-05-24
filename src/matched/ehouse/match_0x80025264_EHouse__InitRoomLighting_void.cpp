// 0x80025264 EHouse::InitRoomLighting(void) (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-160(1); mfspr 0,8; stmw 21,0x74(1); stw 0,0xa4(1); mr 31,3; addi 24,1,8; li 29,0; bl _s80025264_0; lwz 3,0x2c(31); li 0,1; stw 0,0x10(31); rlwinm 3,3,2,0,29; bl _s80025264_1; lwz 0,0x2c(31); lwz 25,-21472(13); stw 3,0x28(31); cmpw 29,0; bge 3f; lis 9,-32697; lis 11,-32766; addi 26,9,-30368; addi 21,11,20988; addi 22,26,80; li 23,0; li 27,0; li 28,0; 0:; mr 3,25; rlwinm 4,29,0,16,31; bl _s80025264_2; lhz 0,0x2(3); cmplwi 0,0; ble 1f; li 3,172; bl _s80025264_3; mr 30,3; bl _s80025264_4; lwz 9,0x4(22); lha 3,0x50(26); mtspr 8,9; stw 26,0x0(30); add 3,30,3; blrl; lwz 9,0x28(31); mr 4,30; stwx 30,28,9; stw 29,0x28(30); lwz 3,0x1c(31); stw 21,0x1c(30); bl _s80025264_5; b 2f; 1:; lwz 9,0x28(31); stwx 23,27,9; 2:; lwz 0,0x2c(31); addi 29,29,1; addi 27,27,4; addi 28,28,4; cmpw 29,0; blt 0b; 3:; lwz 3,0x1c(31); cmpwi 3,0; beq 4f; lfs f1,0x48(31); mr 4,24; bl _s80025264_6; 4:; mr 3,31; mr 4,24; bl _s80025264_7; lwz 3,0x1c(31); cmpwi 3,0; beq 5f; bl _s80025264_8; lwz 3,0x1c(31); bl _s80025264_9; 5:; lwz 0,0xa4(1); mtspr 8,0; lmw 21,0x74(1); addi 1,1,160"

extern "C" void _s80025264_0();
extern "C" void _s80025264_1();
extern "C" void _s80025264_2();
extern "C" void _s80025264_3();
extern "C" void _s80025264_4();
extern "C" void _s80025264_5();
extern "C" void _s80025264_6();
extern "C" void _s80025264_7();
extern "C" void _s80025264_8();
extern "C" void _s80025264_9();

struct EHouse {
    void InitRoomLighting();
};

void EHouse::InitRoomLighting() {
}
