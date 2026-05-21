// 0x8004575C ConvertRoomSideToWallSide(Room::Sides) (84B)

class Room {
public:
    enum Sides { kNone = 0, kSide1 = 1, kSide2 = 2, kSide3 = 3, kSide4 = 4 };
};

extern int ConvertRoomSideToWallSide(Room::Sides side);

int ConvertRoomSideToWallSide(Room::Sides side) {
    switch (side) {
        case 1: return 1;
        case 3: return 3;
        case 4: return 2;
        case 2: return 4;
    }
    return 0;
}
