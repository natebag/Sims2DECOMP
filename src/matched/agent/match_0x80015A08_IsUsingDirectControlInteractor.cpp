/* {anonymous}::IsUsingDirectControlInteractor(int) at 0x80015A08 (36B) */

int IsUsingSpecifiedInteractor(int, int);

static int IsUsingDirectControlInteractor(int param) {
    return IsUsingSpecifiedInteractor(param, 0);
}
