// 0x80015A2C IsUsingSocialModeInteractor (36B)

int IsUsingSpecifiedInteractor(int, int);

int IsUsingSocialModeInteractor(int playerIndex) {
    return IsUsingSpecifiedInteractor(playerIndex, 7);
}
