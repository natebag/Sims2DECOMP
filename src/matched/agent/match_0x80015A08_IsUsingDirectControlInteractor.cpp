int IsUsingSpecifiedInteractor(int player, int type);

int IsUsingDirectControlInteractor(int player) {
    return IsUsingSpecifiedInteractor(player, 0);
}
