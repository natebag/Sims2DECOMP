// 0x8022D88C EIStaticModel::Clone(void) (544 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 31,3; bl _s8022D88C_0; li 6,0; li 7,0; li 4,800; li 5,16; bl _s8022D88C_1; bl _s8022D88C_2; lwz 9,0x80(31); lwz 10,0x84(31); mr 23,3; addi 7,31,128; addi 6,23,128; stw 9,0x80(23); stw 10,0x84(23); addi 3,31,256; addi 24,23,256; lwz 9,0x8(7); lwz 10,0xc(7); stw 9,0x8(6); stw 10,0xc(6); lwz 11,0x10(7); lwz 12,0x14(7); stw 11,0x10(6); stw 12,0x14(6); lwz 9,0x18(7); lwz 10,0x1c(7); stw 9,0x18(6); stw 10,0x1c(6); lwz 11,0x20(7); lwz 12,0x24(7); stw 11,0x20(6); stw 12,0x24(6); lwz 9,0x28(7); lwz 10,0x2c(7); stw 9,0x28(6); stw 10,0x2c(6); lwz 11,0x30(7); lwz 12,0x34(7); stw 11,0x30(6); stw 12,0x34(6); lwz 9,0x38(7); lwz 10,0x3c(7); stw 9,0x38(6); stw 10,0x3c(6); lwz 0,0x318(31); stw 0,0x318(23); lwz 9,0x7c(31); stw 9,0x7c(23); lwz 0,0x100(31); lwz 9,0x4(3); lwz 11,0x8(3); stw 0,0x100(23); stw 9,0x4(24); stw 11,0x8(24); lfs f0,0xc(3); stfs f0,0xc(24); lwz 0,0x110(31); stw 0,0x110(23); lwz 9,0x114(31); stw 9,0x114(23); lwz 0,0x11c(31); stw 0,0x11c(23); lwz 3,0x120(31); stw 3,0x120(23); cmpwi 3,0; beq 0f; bl _s8022D88C_3; 0:; lwz 0,0x124(31); lwz 9,0x110(23); stw 0,0x124(23); cmpwi 9,0; lwz 0,0x14(31); stw 0,0x14(23); lwz 9,0x18(31); stw 9,0x18(23); beq 1f; mr 3,23; bl _s8022D88C_4; 1:; addi 8,31,544; addi 11,23,296; addi 3,31,296; li 9,240; addi 10,23,544; 2:; lwz 0,0x0(3); addic. 9,9,-24; stw 0,0x0(11); lwz 0,0x4(3); stw 0,0x4(11); lwz 0,0x8(3); stw 0,0x8(11); lwz 0,0xc(3); stw 0,0xc(11); lwz 0,0x10(3); stw 0,0x10(11); lwz 0,0x14(3); addi 3,3,24; stw 0,0x14(11); addi 11,11,24; bne 2b; lwz 0,0x0(3); mr 9,8; li 8,240; stw 0,0x0(11); lwz 0,0x4(3); stw 0,0x4(11); 3:; lwz 0,0x0(9); addic. 8,8,-24; stw 0,0x0(10); lwz 0,0x4(9); stw 0,0x4(10); lwz 0,0x8(9); stw 0,0x8(10); lwz 0,0xc(9); stw 0,0xc(10); lwz 0,0x10(9); stw 0,0x10(10); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(10); addi 10,10,24; bne 3b; lwz 0,0x0(9); mr 3,23; stw 0,0x0(10); lwz 0,0x4(9); stw 0,0x4(10); lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"

extern "C" void _s8022D88C_0();
extern "C" void _s8022D88C_1();
extern "C" void _s8022D88C_2();
extern "C" void _s8022D88C_3();
extern "C" void _s8022D88C_4();

struct EIStaticModel {
    void Clone();
};

void EIStaticModel::Clone() {
}
