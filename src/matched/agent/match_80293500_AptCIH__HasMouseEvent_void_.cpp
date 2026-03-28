struct AptCIH {
    int hasEvent(unsigned int mask);
    int HasMouseEvent();
};

int AptCIH::HasMouseEvent() {
    return hasEvent(0x0009FC38);
}
