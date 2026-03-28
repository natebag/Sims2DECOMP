// 0x802B4D3C (8 bytes)
class EAStringC {
public:
    int c_str();
};

int EAStringC::c_str() {
    return (int)((char*)(*(int*)((char*)this + 0x0)) + 0x8);
}
