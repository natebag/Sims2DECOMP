struct EFile;
struct EMovie {
    int Load(EFile *, unsigned int, unsigned int, unsigned int);
};
int EMovie::Load(EFile *, unsigned int, unsigned int, unsigned int) { return 0; }
