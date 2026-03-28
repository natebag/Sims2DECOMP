struct AptValue;

void AptCharacterInst_gotoAndStopPlay(AptValue* args, int nArgs, int play);

struct AptCharacterInst {
    static void sMethod_gotoAndStop(AptValue* args, int nArgs);
};

void AptCharacterInst::sMethod_gotoAndStop(AptValue* args, int nArgs) {
    AptCharacterInst_gotoAndStopPlay(args, nArgs, 0);
}
