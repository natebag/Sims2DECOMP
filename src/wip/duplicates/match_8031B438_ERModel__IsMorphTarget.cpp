// 0x8031B438 (8 bytes)
class ERModel {
public:
    int IsMorphTarget();
};

int ERModel::IsMorphTarget() {
    return *(int*)((char*)this + 0x38);
}
