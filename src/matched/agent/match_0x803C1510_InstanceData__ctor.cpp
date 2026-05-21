// 0x803C1510 InstanceData::InstanceData(void) (52B)
//
// 4 empty 4-iter bdnz loops. GCC 2.95 actually emits empty `for (i = 0;
// i < 4; i++) ;` loops as `li r0,4; mtctr r0; bdnz self` — does NOT
// optimize them away.
//
// PURE source-only crack. No directives.

class InstanceData {
public:
    InstanceData();
};

InstanceData::InstanceData() {
    int i;
    for (i = 0; i < 4; i++) ;
    for (i = 0; i < 4; i++) ;
    for (i = 0; i < 4; i++) ;
    for (i = 0; i < 4; i++) ;
}
