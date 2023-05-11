#pragma once
#include<iostream>
using namespace std;
struct Equivalence
{
    int parent, child;
    Equivalence* next;
    Equivalence(int p = 0, int c = 0)
    {
        this->next = nullptr;
        parent = p;
        child = c;
    }
};
int get_parent(Equivalence* ptr, int child)
{
    while (ptr)
    {
        if (ptr->child == child)
            return ptr->parent;
        ptr = ptr->next;
    }
    return -1;
}
bool search(Equivalence* head, int p, int c)
{
    while (head)
    {
        if (head->parent == p && head->child == c)
            return false;
        else
            head = head->next;
    }
    return true;
}
void add(Equivalence* head, int p, int c)
{
    if (search(head, p, c))
    {
        Equivalence* temp = head;
        while (head != nullptr)
            temp = head, head = head->next;

        if (temp != nullptr)
        {
            temp->parent = p;
            temp->child = c;
        }

        temp->next = new Equivalence();
    }
    else
        return;
}

void display(Equivalence* head)
{
    while (head)
    {
        cout << "Parent is " << head->parent << '\n'
            << "Child is " << head->child << '\n';
        head = head->next;
    }
}
// This function will return the children count of a parent index
int child_count(Equivalence* head, int p)
{
    int children = 0;
    while (head)
    {
        if (head->parent == p)
            children++;
        head = head->next;
    }
    return children;
}
int* get_all_children(Equivalence* head, int p)
{
    int size = child_count(head, p);
    int* all_children = new int[size + 1], index = 0;
    while (head)
    {
        if (head->parent == p)
            all_children[index++] = head->child;
        head = head->next;
    }
    return all_children;
}
// This function will update the list if a specific child is parent of other labels then 
// we need to replace the parent for the remaining children.
void update(Equivalence* head, int parent, int child)
{
    while (head)
    {
        if (head->parent == child)
            head->parent = parent;
        head = head->next;
    }
}
int ischild(Equivalence* head, int c)
{
    if (c != 0)
    {
        while (head)
        {
            if (head->child == c)
            {
                update(head, head->parent, c);
                return head->parent;
            }
            head = head->next;
        }
    }
    return -1;
}