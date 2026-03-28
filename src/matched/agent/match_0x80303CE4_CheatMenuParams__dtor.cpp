extern void __builtin_delete_fn(void*);

struct CheatMenuParams {
    ~CheatMenuParams();
};

CheatMenuParams::~CheatMenuParams() {
}
