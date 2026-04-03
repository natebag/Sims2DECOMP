// 0x801B5A0C (8 bytes)
class G2DTarget {
public:
    int IsG2DSpawned();
};

int G2DTarget::IsG2DSpawned() {
    return *(int*)((char*)this + 0x84);
}
