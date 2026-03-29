void Printf(char *, ...);
extern char sBaseTestStr[];

struct ETexture {
    void Test1(int, int, int, int);
};

void ETexture::Test1(int, int, int, int) {
    Printf(sBaseTestStr);
}
