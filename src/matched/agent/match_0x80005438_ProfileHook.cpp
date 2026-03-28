extern int gProfileCount;

void ProfileHook() {
    gProfileCount = gProfileCount + 1;
}
