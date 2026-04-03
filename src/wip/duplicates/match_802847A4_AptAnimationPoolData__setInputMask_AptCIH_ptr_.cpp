struct AptCIH;

struct AptAnimationPoolData {
    char pad[0x94];
    AptCIH* m_inputMask;

    void setInputMask(AptCIH* mask);
};

void AptAnimationPoolData::setInputMask(AptCIH* mask) {
    m_inputMask = mask;
}
