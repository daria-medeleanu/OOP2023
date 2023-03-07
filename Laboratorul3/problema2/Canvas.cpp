#include "Canvas.h"
#include <iostream>
#include <cmath>
using namespace std;
Canvas::Canvas(int width, int height)
{
	this->w = width;
	this->h = height;
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++) {
            *(mat + i * this->h + j) = ' ';
        }
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int n = ray * ray + 1;
    int xr, yr;
    for (int i = 0; i < this->w; i++)
    {
        for (int j = 0; j < this->h; j++)
        {
            xr = i - ray;
            yr = j - ray;
            if (xr * xr + yr * yr <= ray * ray + 1)
                *(mat + i * this->h + j) = ch;
        }
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    int n = ray * ray + 1;
    int xr, yr;
    for (int i = 0; i < this->w; i++)
    {
        for (int j = 0; j < this->h; j++)
        {
            xr = i - ray;
            yr = j - ray;
            if (xr * xr + yr * yr < ray * ray + 1)
                *(mat + i * this->h + j) = ch;
        }
    }
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int j = left; j <= right; j++) {
        *(mat + top * this->h + j) = ch;
        *(mat + bottom * this->h + j) = ch;
    }
    for (int i = top; i <= bottom; i++) {
        *(mat + i * this->h + left) = ch;
        *(mat + i * this->h + right) = ch;
    }
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int j = left+1; j < right; j++)
        for (int i = top+1; i < bottom; i++)
            *(mat + i * this->h + j) = ch;
}
void Canvas::SetPoint(int x, int y, char ch)
{
    *(mat + x * this->h + y) = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int error = dx + dy;
    while (true)
    {
        *(mat + x1 *this->h + y1)= ch;
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * error;
        if (e2 >= dy)
        {
            if (x1 == x2)
                break;
            error = error + dy;
            x1 = x1 + sx;
        }
        if (e2 <= dx){
            if (y1 == y2)
                break;
            error = error + dx;
            y1 = y1 + sy;
        }
    }
}
void Canvas::Print()
{
    for (int i = 0; i < this->w; i++) {
        for (int j = 0; j < this->h; j++) {
            cout<<*(mat + i * this->h + j)<<" ";
        }
        cout << endl;
    }
}
void Canvas::Clear()
{
    for (int i = 0; i < this->w; i++) 
        for (int j = 0; j < this->h; j++) {
            *(mat + i * this->h + j) = '1';
        }
}