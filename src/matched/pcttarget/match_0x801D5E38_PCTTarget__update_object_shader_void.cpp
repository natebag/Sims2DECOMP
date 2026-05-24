// 0x801D5E38 PCTTarget::update_object_shader(void) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; lwz 4,0xb8(31); bl _s801D5E38_0; lwz 0,0xc0(31); cmplw 3,0; bge 3f; mulli 3,3,24; lwz 9,0xbc(31); add. 5,9,3; beq 3f; lwzx 3,9,3; cmpwi 3,1; bne 0f; lwz 3,0x14(5); bl _s801D5E38_1; mr. 0,3; li 3,0; beq 4f; mr 3,0; addi 4,1,8; bl _s801D5E38_2; cmpwi 3,0; beq 3f; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18304; lwz 5,0x8(1); cmpwi 0,0; lwz 6,0xc(1); lwz 7,0x10(1); beq 1f; lwz 3,0x20(31); cmpwi 3,0; beq 1f; lwz 8,0x7c(31); li 9,0; bl _s801D5E38_3; b 2f; 0:; ble 3f; cmpwi 3,4; bgt 3f; lwz 5,0x8(5); cmpwi 5,0; beq 3f; lwz 0,0x0(31); lis 9,-32705; addi 4,9,18288; cmpwi 0,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lwz 6,0x7c(31); li 7,0; bl _s801D5E38_4; b 2f; 1:; li 3,0; 2:; cmpwi 3,0; li 3,0; beq 4f; li 3,1; b 4f; 3:; li 3,0; 4:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"

extern "C" void _s801D5E38_0();
extern "C" void _s801D5E38_1();
extern "C" void _s801D5E38_2();
extern "C" void _s801D5E38_3();
extern "C" void _s801D5E38_4();

struct PCTTarget {
    void update_object_shader();
};

void PCTTarget::update_object_shader() {
}
