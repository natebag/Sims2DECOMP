extern char gStaticVar[4];
extern "C" void BString2_dtor(char*, int);

void __tcf_2() {
    BString2_dtor(gStaticVar, 2);
}
