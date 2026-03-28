struct AptValue;

void AptCharacterInst_gotoAndStopPlay(AptValue* args, int nArgs, int play);

struct AptCharacterInst {
    static void sMethod_gotoAndPlay(AptValue* args, int nArgs);
};

void AptCharacterInst::sMethod_gotoAndPlay(AptValue* args, int nArgs) {
    AptCharacterInst_gotoAndStopPlay(args, nArgs, 1);
}
