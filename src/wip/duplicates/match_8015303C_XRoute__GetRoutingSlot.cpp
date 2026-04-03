// 0x8015303C (8 bytes)
class XRoute {
public:
    int GetRoutingSlot();
};

int XRoute::GetRoutingSlot() {
    return (int)((char*)this + 0x10);
}
