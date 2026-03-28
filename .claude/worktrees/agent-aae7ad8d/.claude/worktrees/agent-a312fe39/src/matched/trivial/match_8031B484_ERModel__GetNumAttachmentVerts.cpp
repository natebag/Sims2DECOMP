// 0x8031B484 (8 bytes)
class ERModel {
public:
    int GetNumAttachmentVerts();
};

int ERModel::GetNumAttachmentVerts() {
    return *(int*)((char*)this + 0x138);
}
