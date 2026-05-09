// InLevelBaseState::Draw(ERC *) @ 0x8008B498 (56B)

struct ERC;

struct EGameStateMan_D {
    void Draw(ERC* erc);
};

extern char gLiveFlag[];
extern char gStateMan[];

struct InLevelBaseState_D {
    void Draw(ERC* erc);
};

void InLevelBaseState_D::Draw(ERC* erc) {
    if (*(int*)gLiveFlag) {
        EGameStateMan_D* mgr = *(EGameStateMan_D**)gStateMan;
        mgr->Draw(erc);
    }
}
