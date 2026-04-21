// 0x80089A3C EGameStateMan::~EGameStateMan (68B)
// dtor: bl m_nodeList->RemoveAll(); if (free) delete this;

struct ENodeList {
    void RemoveAll();
};

struct EGameStateMan {
    void* m_unused;
    ENodeList m_nodeList;  // at +4
    ~EGameStateMan();
};

EGameStateMan::~EGameStateMan() {
    m_nodeList.RemoveAll();
}
