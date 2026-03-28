static int s_globNamespaceID;

class Behavior {
public:
    static int GetGlobNamespaceID(void);
};

int Behavior::GetGlobNamespaceID(void) {
    return s_globNamespaceID;
}
