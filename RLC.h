#pragma once
#include<iostream>
#include <opencv2/core.hpp>
#include "check_neighbours.h"

using namespace std;
struct node
{
    int data = -1000;
    node* next = nullptr;
};
void append(node* head, int value)
{
    if (head->data == -1000)
        head->data = value;
    else
    {
        node* temp = new node;
        temp->data = value;
        while (head->next)
            head = head->next;
        head->next = temp;
    }
}
void display(node* head)
{
    while (head)
    {
        cout << head->data << "  ";
        if (head->data == -1)
            cout << '\n';
        head = head->next;
    }
}
void calc_rlc(const Mat& img)
{
    bool exit = false;
    node* head = new node;
    const int rows = img.rows, cols = img.cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (get_value(img, i, j) == 255)
            {
                append(head, j);
                for (; get_value(img, i, j) == 255 && j < cols; j++)
                    exit = true;
                if (exit)
                    exit = false, j--;
                append(head, j);
            }
        }
        append(head, -1);
    }
    cout << rows << "  " << cols << '\n';
    display(head);
}