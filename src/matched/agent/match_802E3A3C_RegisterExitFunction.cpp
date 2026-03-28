typedef void (*ExitFunction)();
static ExitFunction s_exitFunction;
void RegisterExitFunction(ExitFunction func) {
    s_exitFunction = func;
}
