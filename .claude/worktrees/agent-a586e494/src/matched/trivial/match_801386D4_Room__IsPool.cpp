// 0x801386D4 (8 bytes)
class Room {
public:
    int IsPool();
};

int Room::IsPool() {
    return *(int*)((char*)this + 0x94);
}
