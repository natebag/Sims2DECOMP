// 0x8036145C (68B) EStringRedBlackTreeNoCase::operator=(...)
// Sibling of ERedBlackTree::op= — Clear + InsertAll + return *this.

class EStringRedBlackTreeNoCase {
public:
    EStringRedBlackTreeNoCase& operator=(const EStringRedBlackTreeNoCase& other);
    void Clear();
    void InsertAll(const EStringRedBlackTreeNoCase& other, int unique);
};

EStringRedBlackTreeNoCase& EStringRedBlackTreeNoCase::operator=(const EStringRedBlackTreeNoCase& other) {
    Clear();
    InsertAll(other, 1);
    return *this;
}
