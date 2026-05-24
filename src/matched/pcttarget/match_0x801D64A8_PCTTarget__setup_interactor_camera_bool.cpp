// 0x801D64A8 PCTTarget::setup_interactor_camera(bool) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lis 11,-32697; lwz 3,0x84(29); addi 11,11,23428; cmpwi 4,0; rlwinm 9,3,4,0,27; add 9,9,11; lwz 31,0x100(9); beq 1f; cmpwi 31,0; beq 0f; mr 3,31; li 4,2; bl _s801D64A8_0; 0:; lis 9,-32697; li 0,9; b 4f; 1:; cmpwi 31,0; lis 30,-32697; beq 3f; bl _s801D64A8_1; cmpwi 3,0; beq 2f; lwz 0,0x84(29); addi 9,30,24012; addi 9,9,280; rlwinm 0,0,2,0,29; lwzx 3,9,0; cmpwi 3,0; beq 2f; bl _s801D64A8_2; 2:; mr 3,31; li 4,0; bl _s801D64A8_3; 3:; lis 9,-32697; li 0,8; 4:; stw 0,0x6254(9); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801D64A8_0();
extern "C" void _s801D64A8_1();
extern "C" void _s801D64A8_2();
extern "C" void _s801D64A8_3();

struct PCTTarget {
    void setup_interactor_camera();
};

void PCTTarget::setup_interactor_camera() {
}
