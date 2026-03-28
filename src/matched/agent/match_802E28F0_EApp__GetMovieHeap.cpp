class EAHeap;
EAHeap *MainHeap();
class EApp {
public:
    EAHeap *GetMovieHeap();
};
EAHeap *EApp::GetMovieHeap() { return MainHeap(); }
