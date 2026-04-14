// 0x802C5CF4 EBoundTreeNode::SafeDelete (64B)

struct EBoundTreeNode {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EBoundTreeNode();
    void SafeDelete();
};

void EBoundTreeNode::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
