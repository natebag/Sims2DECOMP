// 0x8022972C EInstance::ShouldInterestFade(bool) (20B)
// (b == 1) stored to field@108 via xori+subfic+adde

struct EInstance {
    char pad[108];
    int m_shouldInterestFade;
    void ShouldInterestFade(bool b);
};

void EInstance::ShouldInterestFade(bool b) {
    m_shouldInterestFade = (b == 1);
}
