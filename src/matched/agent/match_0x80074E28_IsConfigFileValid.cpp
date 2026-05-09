// 0x80074E28 IsConfigFileValid(int, OptionsRecon&) (56B)
// Logical-NOT of OptionsRecon::ReadIn — xori/subfic/adde idiom.

class OptionsRecon {
public:
    int ReadIn(int);
};

int IsConfigFileValid(int n, OptionsRecon& opts) {
    return opts.ReadIn(n) == 1;
}
