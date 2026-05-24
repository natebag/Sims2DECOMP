// 0x8001B524 CameraDirector::SetCameraCut(ENCamera (648 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 29,0x4c(1); stw 0,0x5c(1); mr 30,3; lwz 0,0x238(30); cmpwi 0,2; beq 4f; lwz 0,0x240(30); xori 0,0,1; andi. 9,0,1; beq 4f; lis 9,-32707; li 29,0; lfs f13,-6872(9); cmpwi 4,0; stw 29,0x230(30); stfs f13,0x22c(30); bne 0f; addi 3,30,128; bl _s8001B524_0; lis 11,-32707; lis 9,-32707; lfs f13,-6864(9); lfs f0,-6868(11); fmuls f0,f0,f13; stfs f0,0x1a0(30); b 4f; 0:; lwz 8,0x48(4); addi 31,30,128; lwz 11,0x10(8); lwz 12,0x14(8); addi 8,8,16; stw 11,0x80(30); stw 12,0x84(30); lwz 9,0x8(8); lwz 10,0xc(8); stw 9,0x8(31); stw 10,0xc(31); lwz 11,0x10(8); lwz 12,0x14(8); stw 11,0x10(31); stw 12,0x14(31); lwz 9,0x18(8); lwz 10,0x1c(8); stw 9,0x18(31); stw 10,0x1c(31); lwz 11,0x20(8); lwz 12,0x24(8); stw 11,0x20(31); stw 12,0x24(31); lwz 9,0x28(8); lwz 10,0x2c(8); stw 9,0x28(31); stw 10,0x2c(31); lwz 11,0x30(8); lwz 12,0x34(8); stw 11,0x30(31); stw 12,0x34(31); lwz 9,0x38(8); lwz 10,0x3c(8); stw 9,0x38(31); stw 10,0x3c(31); lwz 11,0x48(4); lfs f0,0x50(11); fcmpu 0,f0,f13; stfs f0,0x1a0(30); bne 1f; lis 11,-32707; lis 9,-32707; lfs f13,-6864(9); lfs f0,-6860(11); fmuls f0,f0,f13; stfs f0,0x1a0(30); 1:; lwz 5,0x118(30); cmpwi 5,0; beq 2f; addi 3,1,8; mr 4,31; bl _s8001B524_1; lwz 9,0x8(1); lwz 10,0xc(1); addi 8,1,8; lwz 11,0x8(8); lwz 12,0xc(8); stw 9,0x80(30); stw 10,0x84(30); stw 11,0x8(31); stw 12,0xc(31); lwz 9,0x10(8); lwz 10,0x14(8); stw 9,0x10(31); stw 10,0x14(31); lwz 11,0x18(8); lwz 12,0x1c(8); stw 11,0x18(31); stw 12,0x1c(31); lwz 9,0x20(8); lwz 10,0x24(8); stw 9,0x20(31); stw 10,0x24(31); lwz 11,0x28(8); lwz 12,0x2c(8); stw 11,0x28(31); stw 12,0x2c(31); lwz 9,0x30(8); lwz 10,0x34(8); stw 9,0x30(31); stw 10,0x34(31); lwz 11,0x38(8); lwz 12,0x3c(8); stw 11,0x38(31); stw 12,0x3c(31); 2:; lwz 5,0x11c(30); cmpwi 5,0; beq 3f; addi 3,1,8; mr 4,31; bl _s8001B524_2; lwz 9,0x8(1); lwz 10,0xc(1); addi 8,1,8; lwz 11,0x8(8); lwz 12,0xc(8); stw 9,0x80(30); stw 10,0x84(30); stw 11,0x8(31); stw 12,0xc(31); lwz 9,0x10(8); lwz 10,0x14(8); stw 9,0x10(31); stw 10,0x14(31); lwz 11,0x18(8); lwz 12,0x1c(8); stw 11,0x18(31); stw 12,0x1c(31); lwz 9,0x20(8); lwz 10,0x24(8); stw 9,0x20(31); stw 10,0x24(31); lwz 11,0x28(8); lwz 12,0x2c(8); stw 11,0x28(31); stw 12,0x2c(31); lwz 9,0x30(8); lwz 10,0x34(8); stw 9,0x30(31); stw 10,0x34(31); lwz 11,0x38(8); lwz 12,0x3c(8); stw 11,0x38(31); stw 12,0x3c(31); 3:; li 0,3; stw 29,0x220(30); stw 0,0x160(30); mr 3,30; bl _s8001B524_3; 4:; lwz 0,0x5c(1); mtspr 8,0; lmw 29,0x4c(1); addi 1,1,88"

extern "C" void _s8001B524_0();
extern "C" void _s8001B524_1();
extern "C" void _s8001B524_2();
extern "C" void _s8001B524_3();

struct CameraDirector {
    void SetCameraCut_ENCamera();
};

void CameraDirector::SetCameraCut_ENCamera() {
}
