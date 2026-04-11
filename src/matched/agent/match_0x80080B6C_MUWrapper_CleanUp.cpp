// 0x80080B6C (60b) — VERIFIED MATCH
// MUWrapper::CleanUp(void)

class MUWrapper {
public:
    void CleanUp();
    void SubCleanA();
    void SubCleanB();
    void SubCleanC();
};

void MUWrapper::CleanUp() {
    this->SubCleanA();
    this->SubCleanB();
    this->SubCleanC();
}
