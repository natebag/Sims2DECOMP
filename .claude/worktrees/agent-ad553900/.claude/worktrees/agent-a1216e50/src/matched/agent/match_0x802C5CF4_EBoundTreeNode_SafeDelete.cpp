/* EBoundTreeNode::SafeDelete(void) - 0x802C5CF4 (64 bytes) */

struct EBoundTreeNode {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EBoundTreeNode();
    static void SafeDelete(EBoundTreeNode *p);
};

void EBoundTreeNode::SafeDelete(EBoundTreeNode *p)
{
    if (p) {
        delete p;
    }
}
