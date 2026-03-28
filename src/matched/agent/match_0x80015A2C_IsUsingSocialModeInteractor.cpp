int IsUsingSpecifiedInteractor(int player, int type);

int IsUsingSocialModeInteractor(int player) {
    return IsUsingSpecifiedInteractor(player, 7);
}
