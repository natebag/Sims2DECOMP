// 0x801D4C54 PCTTarget::on_tab_changed_objects(void) (392 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; lwz 0,0xb0(30); lwz 9,0xa8(30); mulli 0,0,20; add. 27,9,0; bne 0f; li 3,0; b 13f; 0:; lwz 0,0xa0(30); li 31,0; cmplw 31,0; bge 3f; li 29,0; 1:; lwz 9,0xa4(30); mr 3,27; lwzx 4,29,9; bl _s801D4C54_0; cmpwi 3,0; beq 2f; lwz 9,0xc0(30); addi 9,9,1; stw 9,0xc0(30); 2:; lwz 0,0xa0(30); addi 31,31,1; addi 29,29,4; cmplw 31,0; blt 1b; 3:; lwz 31,0xc0(30); cmpwi 31,0; li 3,1; beq 13f; mulli 3,31,24; addi 29,31,-1; bl _s801D4C54_1; mr 28,3; cmpwi 31,0; mr 31,28; beq 5f; 4:; mr 3,31; bl _s801D4C54_2; addi 31,31,24; cmpwi 29,0; addi 29,29,-1; bne 4b; 5:; lwz 0,0xa0(30); li 31,0; stw 28,0xbc(30); cmplw 31,0; bge 8f; li 0,0; li 29,0; mulli 28,0,24; 6:; lwz 9,0xa4(30); mr 3,27; lwzx 4,29,9; bl _s801D4C54_3; cmpwi 3,0; beq 7f; lwz 9,0xa4(30); lwz 3,0xbc(30); lwzx 4,29,9; add 3,3,28; lwz 5,0x218(30); addi 28,28,24; bl _s801D4C54_4; 7:; lwz 0,0xa0(30); addi 31,31,1; addi 29,29,4; cmplw 31,0; blt 6b; 8:; lwz 0,0x9c(30); li 6,0; cmpwi 0,1; beq 9f; cmpwi 0,2; beq 10f; b 11f; 9:; lis 9,-32739; addi 6,9,7036; b 11f; 10:; lis 9,-32739; addi 6,9,7232; 11:; cmpwi 6,0; beq 12f; lwz 4,0xc0(30); li 5,24; lwz 3,0xbc(30); bl _s801D4C54_5; 12:; li 3,1; 13:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s801D4C54_0();
extern "C" void _s801D4C54_1();
extern "C" void _s801D4C54_2();
extern "C" void _s801D4C54_3();
extern "C" void _s801D4C54_4();
extern "C" void _s801D4C54_5();

struct PCTTarget {
    void on_tab_changed_objects();
};

void PCTTarget::on_tab_changed_objects() {
}
