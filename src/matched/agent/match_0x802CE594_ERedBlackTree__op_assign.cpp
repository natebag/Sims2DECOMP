// 0x802CE594 (68B) ERedBlackTree::operator=(const ERedBlackTree&)
// Clear + InsertAll(other, 1) + return *this — sibling-template family.

class ERedBlackTree {
public:
    ERedBlackTree& operator=(const ERedBlackTree& other);
    void Clear();
    void InsertAll(const ERedBlackTree& other, int unique);
};

ERedBlackTree& ERedBlackTree::operator=(const ERedBlackTree& other) {
    Clear();
    InsertAll(other, 1);
    return *this;
}
