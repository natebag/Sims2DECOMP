// MATCH: 0x801386DC Room::Rotate(Room::Sides,int) | Size: 40 bytes
// FLAGS: -O2 -g0

struct Room {
    enum Sides { SIDE_NORTH = 1, SIDE_EAST, SIDE_SOUTH, SIDE_WEST };
    static Sides Rotate(Sides side, int amount);
};

Room::Sides Room::Rotate(Sides side, int amount) {
    Sides s = side;
    return s ? (Sides)((((s + (((4 - amount) & 3) - 1)) & 3) + 1)) : (Sides)0;
}
