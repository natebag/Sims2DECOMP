// 0x8019025C (40B) RepTitleSupport::GetRepTableRawFriendTitle(int)

struct RepTitleSupport {
    void GetBase(int idx, int kind, ...);
    RepTitleSupport* GetRepTableRawFriendTitle(int idx);
};

RepTitleSupport* RepTitleSupport::GetRepTableRawFriendTitle(int idx) {
    GetBase(idx, 1);
    return this;
}
