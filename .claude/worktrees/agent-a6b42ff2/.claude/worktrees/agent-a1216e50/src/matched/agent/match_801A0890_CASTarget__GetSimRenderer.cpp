class CASTarget {
public:
    void* GetSimRenderer(int simIndex);
};

void* CASTarget::GetSimRenderer(int simIndex) {
    return (void*)((char*)this + 0xA48 + simIndex * 576);
}
