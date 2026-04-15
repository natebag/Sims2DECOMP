/* UIObjectBase::pushAptButtonFilterALL(int, char *) - 0x80177B44 (96B) */

class UIObjectBase {
public:
    int pushAptButtonFilter(int player, char* name);
    int addCmdToAptButtonFilter(int handle, unsigned int cmd);
    int pushAptButtonFilterALL(int player, char* name);
};

int UIObjectBase::pushAptButtonFilterALL(int player, char* name) {
    int handle = pushAptButtonFilter(player, name);
    if (handle == 0) return 0;
    for (unsigned int i = 1; i <= 49; i++) {
        addCmdToAptButtonFilter(handle, i);
    }
    return handle;
}
