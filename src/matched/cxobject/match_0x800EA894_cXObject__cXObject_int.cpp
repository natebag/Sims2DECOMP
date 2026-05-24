// 0x800EA894 cXObject::cXObject(int) (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-192(1); mfspr 0,8; mfcr 12; stw 31,0xbc(1); stw 0,0xc4(1); stw 12,0xb8(1); mr 31,3; cmpwi 4,4,0; beq cr4,0f; addi 0,31,8; mr 3,0; stw 0,0x0(31); bl _s800EA894_0; 0:; lwz 11,0x0(31); lis 9,-32698; addi 9,9,5344; stw 9,0x18(11); bne cr4,2f; addi 8,1,8; mr 7,9; mr 6,8; li 0,168; 1:; lwz 10,0x0(7); addic. 0,0,-24; stw 10,0x0(8); lwz 10,0x4(7); stw 10,0x4(8); lwz 10,0x8(7); stw 10,0x8(8); lwz 10,0xc(7); stw 10,0xc(8); lwz 10,0x10(7); stw 10,0x10(8); lwz 10,0x14(7); addi 7,7,24; stw 10,0x14(8); addi 8,8,24; bne 1b; lwz 10,0x0(7); lis 9,-32698; lwz 11,0x0(31); stw 10,0x0(8); lwz 10,0x4(7); lhz 0,0x14e8(9); stw 10,0x4(8); stw 6,0x18(11); lwz 9,0x0(31); addi 9,9,-8; subf 9,9,31; add 0,0,9; sth 0,0x10(1); 2:; lis 9,-32698; mr 3,31; addi 9,9,4016; stw 9,0x4(31); lwz 0,0xc4(1); lwz 12,0xb8(1); mtspr 8,0; lwz 31,0xbc(1); mtcrf 8,12; addi 1,1,192"

extern "C" void _s800EA894_0();

struct cXObject {
    void cXObject();
};

void cXObject::cXObject() {
}
