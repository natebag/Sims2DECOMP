// 0x8031B470 (8 bytes)
class ERModel {
public:
    int GetAttachmentColor();
};

int ERModel::GetAttachmentColor() {
    return *(unsigned char*)((char*)this + 0x134);
}
