// 0x80190224 (40B) RepTitleSupport::GetRepTableRawTitle(int)

struct RepTitleSupport {
    void GetBase(int idx, int kind, ...);
    RepTitleSupport* GetRepTableRawTitle(int idx);
};

RepTitleSupport* RepTitleSupport::GetRepTableRawTitle(int idx) {
    GetBase(idx, 0);
    return this;
}
