// 0x8035BFC0 (68B) EFloatTree::operator=(const EFloatTree&)
// Sibling of ERedBlackTree::op= — Clear + InsertAll + return *this.

class EFloatTree {
public:
    EFloatTree& operator=(const EFloatTree& other);
    void Clear();
    void InsertAll(const EFloatTree& other, int unique);
};

EFloatTree& EFloatTree::operator=(const EFloatTree& other) {
    Clear();
    InsertAll(other, 1);
    return *this;
}
