// 0x801178AC cTrack::HandleTimerCallback(void) (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; lwz 0,0x34(31); cmpwi 0,0; beq 15f; lwz 0,0x38(31); cmpwi 0,0; bne 15f; lwz 0,0x80(31); cmpwi 0,0; beq 9f; lwz 4,0x88(31); bl _s801178AC_0; lwz 0,0x90(31); cmpwi 0,0; bne 0f; stw 0,0x80(31); 0:; lwz 0,0x90(31); li 9,1; cmpwi 0,0; bgt 1f; li 9,0; 1:; lwz 0,0x8c(31); cmpw 3,0; bge 2f; cmpwi 9,0; beq 3f; b 4f; 2:; cmpwi 9,0; beq 4f; 3:; lwz 0,0x90(31); neg 0,0; stw 0,0x90(31); 4:; lwz 0,0x90(31); li 9,0; cmpwi 7,0,0; add 3,3,0; ble cr7,5f; lwz 0,0x8c(31); cmpw 3,0; bgt 6f; 5:; bge cr7,7f; lwz 0,0x8c(31); cmpw 3,0; bge 7f; 6:; li 9,1; 7:; cmpwi 9,0; beq 8f; li 0,0; lwz 3,0x8c(31); stw 0,0x80(31); 8:; mr 5,3; lwz 4,0x88(31); mr 3,31; bl _s801178AC_1; 9:; lwz 0,0x84(31); cmpwi 0,0; beq 10f; lwz 0,0x80(31); cmpwi 0,0; beq 10f; mr 3,31; bl _s801178AC_2; li 0,0; stw 0,0x84(31); b 15f; 10:; lwz 9,-24136(13); lwz 30,0x14(9); cmpwi 30,0; bge 11f; lis 4,-32706; mr 3,31; addi 4,4,-15076; bl _s801178AC_3; 11:; lwz 0,0x18(31); li 29,0; cmpwi 0,0; beq 15f; cmplw 30,0; blt 15f; lis 27,-32706; lis 28,-32706; 12:; cmpwi 0,0; bge 13f; mr 3,31; addi 4,27,-15032; bl _s801178AC_4; 13:; mr 3,31; bl _s801178AC_5; mr 0,29; cmpwi 0,100; addi 29,29,1; ble 14f; mr 3,31; addi 4,28,-14980; bl _s801178AC_6; 14:; lwz 0,0x18(31); cmpwi 0,0; beq 15f; cmplw 30,0; bge 12b; 15:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s801178AC_0();
extern "C" void _s801178AC_1();
extern "C" void _s801178AC_2();
extern "C" void _s801178AC_3();
extern "C" void _s801178AC_4();
extern "C" void _s801178AC_5();
extern "C" void _s801178AC_6();

struct cTrack {
    void HandleTimerCallback();
};

void cTrack::HandleTimerCallback() {
}
