#include <cstdint>
#include <vector>

using namespace std;

class pipe {

  public:
    pipe() {
        regs.resize(4);
        pipes.resize(5);
    }

  private:
    vector<uint32_t> regs;
    vector<uint32_t> pipes;
};

int main() {
    pipe p;
    return 0;
}
