// 0x80089D3C (60B) EGameStateMan::Draw(ERC *)

class ERC;

class EGameStateMan {
public:
    void Draw(ERC* erc);
};

void EGameStateMan::Draw(ERC* erc) {
    char* wrapper = *(char**)this;
    char* obj = *(char**)wrapper;
    char* vt = *(char**)(obj + 8);
    short adj = *(short*)(vt + 32);
    void* fn = *(void**)(vt + 36);
    ((void (*)(void*, ERC*))fn)(obj + adj, erc);
}
