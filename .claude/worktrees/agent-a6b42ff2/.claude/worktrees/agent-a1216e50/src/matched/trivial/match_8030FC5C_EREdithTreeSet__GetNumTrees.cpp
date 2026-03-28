// 0x8030FC5C (8 bytes)
class EREdithTreeSet {
public:
    int GetNumTrees();
};

int EREdithTreeSet::GetNumTrees() {
    return *(int*)((char*)this + 0x18);
}
