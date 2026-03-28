// 0x80011E58 (8 bytes)
class AptViewer {
public:
    int IsReadControllerActive();
};

int AptViewer::IsReadControllerActive() {
    return *(int*)((char*)this + 0x3A4);
}
