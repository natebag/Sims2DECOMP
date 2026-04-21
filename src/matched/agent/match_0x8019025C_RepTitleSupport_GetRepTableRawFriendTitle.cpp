// 0x8019025C (56B) RepTitleSupport::GetRepTableRawFriendTitle(int)

struct RepTitleSupport {
    void GetBase(int idx, int kind, ...);
    RepTitleSupport* GetRepTableRawFriendTitle(int idx);
};

RepTitleSupport* RepTitleSupport::GetRepTableRawFriendTitle(int idx) {
    GetBase(idx, 1);
    return this;
}
