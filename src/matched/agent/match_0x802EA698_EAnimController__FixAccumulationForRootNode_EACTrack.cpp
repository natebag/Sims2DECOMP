// 0x802EA698 EAnimController::FixAccumulationForRootNode(EACTrack (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,3; addi 4,4,20; mtspr 9,0; li 10,0; li 8,1; addi 11,3,128; 0:; lwz 9,0x8(3); slw 0,8,10; addi 10,10,1; and. 7,9,0; beq 1f; lfs f0,0x0(11); stfs f0,0x0(4); 1:; addi 4,4,4; addi 11,11,4; bdnz 0b"
extern "C" void f_802EA698() {}
