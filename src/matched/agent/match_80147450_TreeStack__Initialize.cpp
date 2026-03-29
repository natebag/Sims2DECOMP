// 0x80147450 (36 bytes)
// TreeStack::Initialize(int)
// addi r3, r3, 8; bl vector::reserve(r4)
// Calls reserve on the vector/array at offset 8

class TreeVec {
public:
    void reserve(int n);
};

class TreeStack {
public:
    char _pad[8];
    TreeVec m_vec;  // offset 8
    void Initialize(int capacity);
};

void TreeStack::Initialize(int capacity) {
    m_vec.reserve(capacity);
}
