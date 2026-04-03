// 0x800C1D54 (8 bytes)
class Interaction {
public:
    short GetTreeID();
};

short Interaction::GetTreeID() {
    return *(short*)((char*)this + 0x2C);
}
