struct RBTSentinel {
    int data[4];
};
static RBTSentinel s_sentinel_rbt;

struct ERedBlackTree_RBT {
    int m_count;
    int m_size;
    RBTSentinel* m_sent;
    ERedBlackTree_RBT();
};

ERedBlackTree_RBT::ERedBlackTree_RBT() {
    m_count = 0;
    m_sent = &s_sentinel_rbt;
    m_size = 0;
}
