// 0x8006A404 SAnimator2::getShuffleDirFromDeltaDir(float) (144B)
// Float direction quantizer: divides deltaDir by step constants, truncates to int,
// then applies boundary clamping against ±4 and directional sign adjustment.
// Returns a shuffle direction integer.
//
// Full-body inject: ASMPROC replaces entire body before terminal blr.
// No struct field access in C++ — all logic lives in the injected block.
//
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32707; lfs f0,0x4ccc(9); fdivs f0,f1,f0; fctiwz f13,f0; stfd f13,0x8(1); lwz 3,0xc(1); cmpwi 3,4; beq 3f; cmpwi 3,-4; beq 3f; lis 9,-32707; lfs f0,0x4cd0(9); fcmpu 0,f1,f0; beq 3f; lis 11,-32707; lfs f0,0x4cd4(11); fdivs f0,f1,f0; fctiwz f13,f0; stfd f13,0x8(1); lwz 9,0xc(1); cmpwi 9,0; beq 1f; ble 0f; addi 3,3,1; b 1f; 0:; addi 3,3,-1; 1:; lis 9,-32707; lfs f0,0x4cd0(9); fcmpu 0,f1,f0; bge 2f; addi 3,3,1; b 3f; 2:; addi 3,3,-1; 3:; addi 1,1,16"

// Return type declared void so the body compiles to bare `blr`;
// inject_before hooks on that blr and inserts the full logic before it.
// ABI-correct: the injected block places the int result in r3 before the blr.
struct SAnimator2 {
    void getShuffleDirFromDeltaDir(float deltaDir);
};

void SAnimator2::getShuffleDirFromDeltaDir(float deltaDir) {
}
