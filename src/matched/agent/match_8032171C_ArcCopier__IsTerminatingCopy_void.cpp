static int s_terminatingCopy;
class ArcCopier { public: int IsTerminatingCopy(); };
int ArcCopier::IsTerminatingCopy() { return s_terminatingCopy; }
