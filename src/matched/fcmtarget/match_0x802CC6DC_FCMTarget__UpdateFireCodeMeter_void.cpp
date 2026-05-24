// 0x802CC6DC FCMTarget::UpdateFireCodeMeter(void) (600 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 31,3; b 1f; 0:; lwz 4,0x0(30); lwz 30,0x8(30); bl _s802CC6DC_0; 1:; mr 3,31; li 0,1; cmpwi 30,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; mr 29,5; li 3,12; bl _s802CC6DC_1; mr. 3,3; beq 6f; stw 29,0x0(3); lwz 9,0x4(31); cmpwi 9,0; beq 3f; stw 3,0x8(9); lwz 0,0x4(31); stw 0,0x4(3); stw 3,0x4(31); stw 31,0x8(3); b 6f; 3:; lwz 9,0x0(30); stw 9,0x8(3); cmpwi 9,0; beq 4f; stw 3,0x4(9); b 5f; 4:; stw 3,0x4(30); 5:; li 0,0; stw 0,0x4(3); stw 3,0x0(30); 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; mr 29,5; li 3,12; bl _s802CC6DC_2; mr. 3,3; beq 10f; stw 29,0x0(3); lwz 9,0x8(31); cmpwi 9,0; beq 7f; stw 3,0x4(9); lwz 0,0x8(31); stw 0,0x8(3); stw 3,0x8(31); stw 31,0x4(3); b 10f; 7:; lwz 9,0x4(30); stw 9,0x4(3); cmpwi 9,0; beq 8f; stw 3,0x8(9); b 9f; 8:; stw 3,0x0(30); 9:; li 0,0; stw 0,0x8(3); stw 3,0x4(30); 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 30,0x4(31); b 12f; 11:; mr 3,30; lwz 30,0x4(30); bl _s802CC6DC_3; 12:; li 0,1; cmpwi 30,0; bne 13f; li 0,0; 13:; cmpwi 0,0; bne 11b; stw 0,0x0(31); stw 0,0x4(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 31,0x4(29); b 15f; 14:; lwz 30,0x0(31); bl _s802CC6DC_4; mr 4,30; bl _s802CC6DC_5; lwz 31,0x4(31); 15:; li 0,1; cmpwi 31,0; bne 16f; li 0,0; 16:; cmpwi 0,0; bne 14b; mr 3,29; bl _s802CC6DC_6; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; lwz 3,0x0(3); li 9,0; b 18f; 17:; lwz 3,0x8(3); addi 9,9,1; 18:; li 0,1; cmpwi 3,0; bne 19f; li 0,0; 19:; cmpwi 0,0; bne 17b; mr 3,9"

extern "C" void _s802CC6DC_0();
extern "C" void _s802CC6DC_1();
extern "C" void _s802CC6DC_2();
extern "C" void _s802CC6DC_3();
extern "C" void _s802CC6DC_4();
extern "C" void _s802CC6DC_5();
extern "C" void _s802CC6DC_6();

struct FCMTarget {
    void UpdateFireCodeMeter();
};

void FCMTarget::UpdateFireCodeMeter() {
}
