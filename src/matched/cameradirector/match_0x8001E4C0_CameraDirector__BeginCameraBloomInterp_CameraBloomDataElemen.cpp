// 0x8001E4C0 CameraDirector::BeginCameraBloomInterp(CameraBloomDataElement (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 3,-26392(13); addi 7,30,744; addi 4,30,732; addi 5,30,736; addi 6,30,740; bl _s8001E4C0_0; lwz 8,0x0(29); addi 9,30,748; lwz 0,0x4(29); lis 7,-32707; lwz 10,0xc(29); lwz 11,0x8(29); stw 8,0x2ec(30); stw 10,0xc(9); stw 0,0x4(9); stw 11,0x8(9); lfs f0,-6688(7); lwz 0,0x31c(30); stfs f0,0x2d4(30); ori 0,0,1; stw 0,0x31c(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8001E4C0_0();

struct CameraDirector {
    void BeginCameraBloomInterp_CameraBloomDataElemen();
};

void CameraDirector::BeginCameraBloomInterp_CameraBloomDataElemen() {
}
