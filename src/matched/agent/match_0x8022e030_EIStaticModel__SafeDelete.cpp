/* EIStaticModel::SafeDelete(void) at 0x8022E030 (64B) */

struct EIStaticModel_SD {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual ~EIStaticModel_SD();
    void SafeDelete();
};

void EIStaticModel_SD::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
