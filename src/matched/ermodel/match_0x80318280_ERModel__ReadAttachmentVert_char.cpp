// 0x80318280 ERModel::ReadAttachmentVert(char (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 30,3; addi 3,30,312; li 5,4; mr 29,31; bl _s80318280_0; addi 31,31,4; lwz 4,0x13c(30); cmpwi 4,0; beq 0f; lis 3,-32692; addi 3,3,-27556; bl _s80318280_1; li 0,0; stw 0,0x13c(30); 0:; lwz 4,0x138(30); cmpwi 4,0; beq 1f; lis 3,-32692; rlwinm 4,4,6,0,25; li 5,16; addi 3,3,-27556; bl _s80318280_2; lwz 0,0x138(30); mr 9,3; mr 4,31; rlwinm 0,0,6,0,25; stw 9,0x13c(30); add 31,31,0; mr 5,0; bl _s80318280_3; 1:; subf 3,29,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80318280_0();
extern "C" void _s80318280_1();
extern "C" void _s80318280_2();
extern "C" void _s80318280_3();

struct ERModel {
    void ReadAttachmentVert();
};

void ERModel::ReadAttachmentVert() {
}
