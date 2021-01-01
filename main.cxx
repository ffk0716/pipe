#include <cstdint>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

class stage {
  public:
    vector<uint32_t> in;
    vector<uint32_t> out;
    uint32_t time;
    stage() { time = 1; }
};

class inst {
  public:
    vector<stage> stages;
    inst() { stages.resize(5); }
};
class pipe_sim {

  public:
    pipe_sim() {
        regs.resize(4);
        pipes.resize(5);
    }

    void print() const {
        cout << "regs:";
        for (auto &r : regs)
            cout << " " << r;
        cout << endl;
        //
        cout << "pipes:";
        for (auto &p : pipes)
            cout << " " << p;
        cout << endl;
    }

    void run(const inst &inst_in) {
        for (size_t i = 0; i < 5; i++) {
            auto &s = inst_in.stages.at(i);
            uint32_t start = pipes.at(i);
            if (i > 0)
                start = max(start, pipes.at(i - 1));
            for (uint32_t r : s.in)
                start = max(start, regs.at(r));
            uint32_t end = start + s.time;
            for (uint32_t r : s.out)
                regs.at(r) = end;
            pipes.at(i) = end;
        }
        print();
    }

  private:
    vector<uint32_t> regs;
    vector<uint32_t> pipes;
};

TEST(pipeline, simple) {
    EXPECT_TRUE(true);
    pipe_sim p;
    {
        inst i;
        p.run(i);
    }
    {
        inst i;
        i.stages.at(2).out.push_back(3);
        p.run(i);
    }
    {
        inst i;
        i.stages.at(1).in.push_back(3);
        p.run(i);
    }
}
