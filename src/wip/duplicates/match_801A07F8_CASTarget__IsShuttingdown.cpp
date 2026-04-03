// 0x801A07F8 (8 bytes)
class CASTarget {
public:
    int IsShuttingdown();
};

int CASTarget::IsShuttingdown() {
    return *(int*)((char*)this + 0x1630);
}
