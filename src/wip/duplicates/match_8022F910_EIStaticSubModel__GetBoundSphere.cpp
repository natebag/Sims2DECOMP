// 0x8022F910 (8 bytes)
class EIStaticSubModel {
public:
    int GetBoundSphere();
};

int EIStaticSubModel::GetBoundSphere() {
    return (int)((char*)this + 0x80);
}
