// 0x802769BC AptActionInterpreter::_FunctionAptActionReturn (12b)
typedef unsigned int uint;

struct LocalContextT {
    char _pad[20];
    uint m_returnFlag;
};

void AptActionInterpreter___FunctionAptActionReturn(void *interp, LocalContextT *ctx) {
    ctx->m_returnFlag = 1;
}
