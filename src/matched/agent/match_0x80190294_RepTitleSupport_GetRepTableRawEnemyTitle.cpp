// 0x80190294 (56B) RepTitleSupport::GetRepTableRawEnemyTitle(int)

struct RepTitleSupport {
    void GetBase(int idx, int kind, ...);
    RepTitleSupport* GetRepTableRawEnemyTitle(int idx);
};

RepTitleSupport* RepTitleSupport::GetRepTableRawEnemyTitle(int idx) {
    GetBase(idx, 2);
    return this;
}
