// 0x801BC190 INGTarget::set_cell_enabled(unsigned (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 31,0x2c(1); stw 0,0x34(1); mr 9,4; mr 31,5; cmplwi 9,11; ble 0f; li 3,0; b 3f; 0:; lis 4,-32705; addi 5,9,1; addi 4,4,-8800; addi 3,1,8; crxor 6,6,6; bl _s801BC190_0; cmpwi 31,0; beq 1f; lis 9,-32705; addi 9,9,-5288; b 2f; 1:; lis 9,-32705; addi 9,9,-5284; 2:; lwz 3,-25136(13); lis 4,-32705; addi 4,4,6576; li 5,0; li 6,0; li 7,2; addi 8,1,8; crxor 6,6,6; bl _s801BC190_1; li 3,1; 3:; lwz 0,0x34(1); mtspr 8,0; lwz 31,0x2c(1); addi 1,1,48"

extern "C" void _s801BC190_0();
extern "C" void _s801BC190_1();

struct INGTarget {
    void set_cell_enabled();
};

void INGTarget::set_cell_enabled() {
}
