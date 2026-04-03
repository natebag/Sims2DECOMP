// 0x801657D8 (8 bytes)
class CasScene {
public:
    void SetMediator(int p);
};

void CasScene::SetMediator(int p) {
    *(int*)((char*)this + 0x0) = p;
}
