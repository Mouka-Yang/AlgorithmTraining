#include "gtest/gtest.h"

#include <cstddef>
#include <vector>
#include <numeric>

// Disjoint set:
//  construct(n) : construct a disjoint set with n nodes
//      1. after initialized, all nodes are in its own group
//  find(x) : return root node of the group where x exists
//      1. if the group contains only one node, the node's parent is itself
//      2. path compression: after find finished, the parent of all subnodes before and including node x should points to the group root
//  union(x,y) : connect two group where x and y exist, if x and y are in one group then do nothing
//      1. tree balance: in connecting, the group with lower rank should be connected to(as a subtree) the other one
//  isConnected(x,y) : check if x and y are in the same group
//

class disjointSetImpl {
public:
    disjointSetImpl(size_t n) : parents(n), ranks(n,0)
    {
        std::iota(parents.begin(), parents.end(), 0);
    }

    size_t findNode(size_t index)
    {
        auto current{index};
        while(parents[current] != current){
            current = parents[current];
        }
        return current;
    }

    void unionNode(size_t nodeX, size_t nodeY) {
        auto rootX{findNode(nodeX)};
        auto rootY{findNode(nodeY)};
        if (ranks[rootX] <= ranks[rootY]) {
            parents[rootX] = rootY;
        } else {
            parents[rootY] = rootX;
        }

        if(ranks[rootX] == ranks[rootY]){
            ranks[rootY]++;
        }
    }

    bool isConnected(size_t nodeX, size_t nodeY){
        return findNode(nodeX) == findNode(nodeY);
    }

private:
    std::vector<size_t> parents;
    std::vector<size_t> ranks;
};

TEST(disjointSetImplTest, FindNodeAfterFirstInitilized)
{
    disjointSetImpl s{5};
    EXPECT_EQ(s.findNode(1), 1);
    EXPECT_EQ(s.findNode(2), 2);
}

TEST(disjointSetImplTest, UnionTwoNodeInTwoGroup)
{
    disjointSetImpl s{5};

    s.unionNode(1, 2);
    EXPECT_TRUE(s.isConnected(1, 2));
}

TEST(disjointSetImplTest, UnionTwoNodeInOneGroup){
    disjointSetImpl s{5};

    s.unionNode(1, 2);
    s.unionNode(2, 3);
    EXPECT_TRUE(s.isConnected(1, 3));
    EXPECT_EQ(s.findNode(1), 2);
    EXPECT_EQ(s.findNode(3), 2);

    s.unionNode(1, 3);
    EXPECT_TRUE(s.isConnected(1, 3));
}
