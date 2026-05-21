// 0x8013836C Room::AbsorbNewRoomList(vector<CTilePt>&) (72B)

class CTilePt;

namespace std {
    template<typename T, typename A>
    class vector { /* opaque */ };
    template<typename T>
    class allocator { /* opaque */ };
}

class Room {
public:
    void Clear();
    void AbsorbNewRoomList(std::vector<CTilePt, std::allocator<CTilePt> >& v);
};

extern "C" void* __as__t6vector2Z7CTilePtt9allocator1Z7CTilePtFRCt6vector2Z7CTilePtt9allocator1Z7CTilePt(void* dst, void* src);

void Room::AbsorbNewRoomList(std::vector<CTilePt, std::allocator<CTilePt> >& v) {
    Clear();
    __as__t6vector2Z7CTilePtt9allocator1Z7CTilePtFRCt6vector2Z7CTilePtt9allocator1Z7CTilePt((char*)this + 4, &v);
    *(int*)((char*)this + 52) = 1;
    *(int*)((char*)this + 132) = 1;
}
