// 0x80292B58 (76B) AptCIH::SetEventHandler(int)

struct AptCIH_EVH_Inner {
    char pad[0x10];
    int m_flags10;
};

struct AptCIH_EVH_NonVirt {
    int m_f0;
    int m_f4;
};

struct AptCIH_EVH_Virt : public AptCIH_EVH_NonVirt {
    virtual void evhFill0() = 0;
    virtual void evhFill1() = 0;
    virtual void evhFill2() = 0;
    virtual AptCIH_EVH_Inner* getEventTarget() = 0;
};

struct AptCIH_EVH : public AptCIH_EVH_Virt {
    void SetEventHandler(int handler);
};

void AptCIH_EVH::SetEventHandler(int handler) {
    AptCIH_EVH_Inner* target = this->getEventTarget();
    target->m_flags10 |= handler;
}
