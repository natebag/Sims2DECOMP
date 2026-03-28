// 0x80363408 (8 bytes)
class EDL {
public:
    int GetVertCount();
};

int EDL::GetVertCount() {
    return *(int*)((char*)this + 0x54);
}
