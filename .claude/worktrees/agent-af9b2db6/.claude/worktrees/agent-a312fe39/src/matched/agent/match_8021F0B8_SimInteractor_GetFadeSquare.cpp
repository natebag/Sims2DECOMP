// 0x8021F0B8 (16 bytes) - InteractorModule::SimInteractor::GetFadeSquare(int)
// mulli r4, r4, 28; addi r4, r4, 100; add r3, r3, r4; blr  =>  return &m_fadeSquares[index];

struct FadeSquare { char data[28]; };

struct SimInteractor_FS {
    char pad[100];
    FadeSquare m_fadeSquares[1];

    FadeSquare* GetFadeSquare(int index);
};

FadeSquare* SimInteractor_FS::GetFadeSquare(int index) {
    return &m_fadeSquares[index];
}
