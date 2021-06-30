#ifndef QUATTREE_H
#define QUATTREE_H

#include "physics/geometry2d.h"
#include <vector>

struct QuadTreeData
{
    void *object;
    Rectangle bounds;
    bool flag;
    inline QuadTreeData(void *o, const Rectangle &b)
        : object(o), bounds(b), flag(false) {}
};

class QuadTreeNode
{
protected:
    std::vector<QuadTreeNode> children;
    std::vector<QuadTreeData *> contents;
    int currentDepht;
    static int maxDepth;
    static int maxObjectsPerNode;
    Rectangle nodeBounds;

public:
    QuadTreeNode(const Rectangle &bounds)
        : nodeBounds(bounds), currentDepht(0) {}

    bool isLeaf();
    int numObjects();
    void Insert(QuadTreeData &data);
    void Remove(QuadTreeData &data);
    void Update(QuadTreeData &data);
    void Shake();
    void Split();
    void Reset();
    std::vector<QuadTreeData *> Query(const Rectangle area);
};

typedef QuadTreeNode QuadTree;
typedef QuadTree CollisionWorld;
typedef QuadTreeData CollisionData;

#endif