// 0x8021F0B8 InteractorModule::SimInteractor::GetFadeSquare(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 4,4,28; addi 4,4,100; add 3,3,4"
extern "C" int f_8021F0B8() {}
