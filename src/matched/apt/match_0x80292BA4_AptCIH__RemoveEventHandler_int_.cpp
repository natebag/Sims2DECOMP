// 0x80292BA4 (76B) AptCIH::RemoveEventHandler(int)

struct AptCIH_REVH_Inner {
    char pad[0x10];
    int m_flags10;
};

struct AptCIH_REVH_NonVirt {
    int m_f0;
    int m_f4;
};

struct AptCIH_REVH_Virt : public AptCIH_REVH_NonVirt {
    virtual void revhFill0() = 0;
    virtual void revhFill1() = 0;
    virtual void revhFill2() = 0;
    virtual AptCIH_REVH_Inner* getEventTarget() = 0;
};

struct AptCIH_REVH : public AptCIH_REVH_Virt {
    void RemoveEventHandler(int handler);
};

void AptCIH_REVH::RemoveEventHandler(int handler) {
    AptCIH_REVH_Inner* target = this->getEventTarget();
    target->m_flags10 &= ~handler;
}
