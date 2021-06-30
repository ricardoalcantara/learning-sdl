#include "physics/quadtree.h"
#include <queue>

int QuadTreeNode::maxDepth = 5;
int QuadTreeNode::maxObjectsPerNode = 15;

bool QuadTreeNode::isLeaf()
{
    return children.size() == 0;
}

int QuadTreeNode::numObjects()
{
    Reset();
    int objectCount = contents.size();
    for (auto content : contents)
    {
        content->flag = true;
    }

    std::queue<QuadTreeNode *> process;

    process.push(this);

    while (process.size() > 0)
    {
        auto processing = process.back();
        if (!processing->isLeaf())
        {
            for (auto child : processing->children)
            {
                process.push(&child);
            }
        }
        else
        {
            for (auto content : processing->contents)
            {
                if (!content->flag)
                {
                    objectCount++;
                    content->flag = true;
                }
            }
        }
    }

    Reset();
    return objectCount;
}

void QuadTreeNode::Insert(QuadTreeData &data)
{
    if (!RectangleOnRectangle(data.bounds, nodeBounds))
    {
        return;
    }

    if (isLeaf() && (contents.size() + 1) > maxObjectsPerNode)
    {
        Split();
    }

    if (isLeaf())
    {
        contents.push_back(&data);
    }
    else
    {
        for (auto child : children)
        {
            child.Insert(data);
        }
    }
}

void QuadTreeNode::Remove(QuadTreeData &data)
{
    if (isLeaf())
    {
        int removeIndex = -1;

        for (int i = 0, size = contents.size(); i < size; i++)
        {
            if (contents[i]->object == data.object)
            {
                removeIndex = i;
                break;
            }
        }

        if (removeIndex != -1)
        {
            // Todo: Is it removing right?
            contents.erase(contents.begin() + removeIndex);
        }
    }
    else
    {
        for (auto child : children)
        {
            child.Remove(data);
        }
    }

    Shake();
}

void QuadTreeNode::Update(QuadTreeData &data)
{
    if (isLeaf())
    {
        for (auto content : contents)
        {
            content->flag = false;
        }
    }
    else
    {
        for (auto child : children)
        {
            child.Reset();
        }
    }
}

void QuadTreeNode::Shake()
{
    if (!isLeaf())
    {
        int numObjects = this->numObjects();
        if (numObjects == 0)
        {
            children.clear();
        }
        else if (numObjects < maxObjectsPerNode)
        {
            std::queue<QuadTreeNode *> process;
            process.push(this);

            while (process.size() > 0)
            {
                auto processing = process.back();
                if (!processing->isLeaf())
                {
                    for (auto child : processing->children)
                    {
                        process.push(&child);
                    }
                }
                else
                {
                    contents.insert(contents.end(), processing->contents.begin(), processing->contents.end());
                }
            }
            process.pop();
        }
        children.clear();
    }
}

void QuadTreeNode::Split()
{
    if (currentDepht + 1 > maxDepth)
    {
        return;
    }

    Vec2 min = nodeBounds.position;
    Vec2 max = nodeBounds.position + nodeBounds.size;
    Vec2 center = min + ((max - min) * 0.5f);

    // childSplit
    // [1][2]
    // [3][4]
    Rectangle childAreas[] = {
        Rectangle(min, center - min),
        Rectangle(
            Vec2(center.x, min.y),
            Vec2(center.x, min.y) - Vec2(max.x, center.y)),
        Rectangle(
            Vec2(min.x, center.y),
            Vec2(min.x, center.y) - Vec2(center.x, max.y)),
        Rectangle(center, center - max),
    };

    for (int i = 0; i < 4; ++i)
    {
        children.push_back(QuadTreeNode(childAreas[i]));
        children[i].currentDepht = currentDepht + 1;
    }
    for (int i = 0, size = contents.size(); i < size; ++i)
    {
        children[i].Insert(*contents[i]);
    }

    contents.clear();
}

void QuadTreeNode::Reset()
{
    if (isLeaf())
    {
        for (auto content : contents)
        {
            content->flag = false;
        }
    }
    else
    {
        for (auto child : children)
        {
            child.Reset();
        }
    }
}

std::vector<QuadTreeData *> QuadTreeNode::Query(const Rectangle area)
{
    std::vector<QuadTreeData*> result;
    if (!RectangleOnRectangle(area, nodeBounds))
    {
        return result;
    }
    
    if (isLeaf())
    {
        for(auto content: contents)
        {
            if (RectangleOnRectangle(content->bounds, area))
            {
                result.push_back(content);
            }
        }
    }
    else
    {
        for(auto child: children)
        {
            std::vector<QuadTreeData*> recurse = child.Query(area);
            if (recurse.size() > 0)
            {
                result.insert(result.end(), recurse.begin(), recurse.end());
            }
        }
    }

    return result;
}
