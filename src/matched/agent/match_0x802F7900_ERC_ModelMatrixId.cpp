// FLAGS: -fno-elide-constructors
// 0x802F7900 ERC::ModelMatrixId (60b)
    char pad[112];
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void V24(); virtual void V25(); virtual void V26();
    virtual void V27(int, int);
};
void ModelMatrixId_test(ERCBase* self) { self->V27(0, 254); }
