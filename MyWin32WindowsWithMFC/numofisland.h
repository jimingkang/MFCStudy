#pragma once
// C++ Program to count islands in boolean 2D matrix
//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define ROW 4
#define COL 4
#define space 50

// A function to check if a given
// cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col,
    bool visited[][COL])
{
    // row number is in range, column
    // number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}

// A utility function to do DFS for a
// 2D boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void DFS(int M[][COL], int row, int col,
    bool visited[][COL],CPaintDC* pDc,CRect * rect,int& max)
{
    // These arrays are used to get
    // row and column numbers of 8
    // neighbours of a given cell
    static int rowNbr[] = {  -1,   1, 0, 0 };
    static int colNbr[] = {  0,    0,-1, 1 };

    // Mark this cell as visited
    visited[row][col] = true;
    // Recur for all connected neighbours

    max++;
    for (int k = 0; k < 4; ++k)
    {
        if ((row + rowNbr[k]) < 0 || (row + rowNbr[k]) >= ROW || (col + colNbr[k]) < 0 || (col + colNbr[k]) >= COL)
            M[row + rowNbr[k]][(col + colNbr[k])] = -1;
        CString a;
        a.Format(_T("%d"), M[row + rowNbr[k]][col + colNbr[k]]);
        rect->top = 200 + (row + rowNbr[k]) * space - space;
        rect->left = 100 + (col + colNbr[k]) * space - space;

        rect->bottom = 200 + (row + rowNbr[k]) * space;
        rect->right = 100 + (col + colNbr[k]) * space;
        pDc->SetTextColor(RGB(255, 0, 0));
        pDc->DrawText(a, -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        // pDc->SetTextColor(RGB(0, 255, 0));
        //pDc->DrawText(a, -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        //::Sleep(1000);
       
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
        {
     
            DFS(M, row + rowNbr[k], col + colNbr[k], visited, pDc, rect,max);
        }
    }
}

// The main function that returns
// count of islands in a given boolean
// 2D matrix
int countIslands(int M[][COL], CPaintDC *pDc,CRect *rect)
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    // Initialize count as 0 and
    // traverse through the all cells of
    // given matrix
    int count = 0;
     int max = 0;
    int globalmax = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)

            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j]) {
                // visited yet, then new island found
                // Visit all cells in this island.
                CString a;
                a.Format(_T("%d"), M[i][j]);
                rect->top = 200 + (i) * space - space;
                rect->left = 100 + (j) * space - space;

                rect->bottom = 200 + (i) * space;
                rect->right = 100 + (j) * space;
                pDc->SetTextColor(RGB(255, 255, 0));
                pDc->DrawText(a, -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
                ::Sleep(1000);
                pDc->SetTextColor(RGB(0, 0, 0));

                pDc->DrawText(a, -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
                DFS(M, i, j, visited, pDc, rect,max);
              
                // and increment island count
                ++count;
               
               
            }

    return count;
}



int maxAreaOfIslands(int M[][COL], CPaintDC* pDc, CRect* rect)
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
    int globalmax=0;
    int max=0;
    // Initialize count as 0 and
    // traverse through the all cells of
    // given matrix
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)

            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j]) {
                // visited yet, then new island found
                // Visit all cells in this island.
                CString a;
                a.Format(_T("%d"), M[i][j]);
                rect->top = 200 + (i)*space - space;
                rect->left = 100 + (j)*space - space;

                rect->bottom = 200 + (i)*space;
                rect->right = 100 + (j)*space;
                pDc->SetTextColor(RGB(255, 255, 0));
                pDc->DrawText(a, -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
                ::Sleep(1000);
                pDc->SetTextColor(RGB(0, 0, 0));

                pDc->DrawText(a, -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
                DFS(M, i, j, visited, pDc, rect, max);
                globalmax = max(globalmax, max);
                max = 0;


            }

    return globalmax;
}
int isSafe2(int M[][COL], int row, int col,
    bool visited[][COL])
{
    // row number is in range, column
    // number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col]);
}

boolean  DFS(int M[][COL], int row, int col, bool visited[][COL], CPaintDC* pDc, CRect* rect)
{
    // These arrays are used to get
    // row and column numbers of 8
    // neighbours of a given cell
    static int rowNbr[] = { -1,   1, 0, 0 };
    static int colNbr[] = { 0,    0,-1, 1 };
    if ((row) < 0 || (row) >= ROW || (col) < 0 || (col) >= COL || M[row][col] == 0)
        return false;
    if (row== 0 || row == (ROW - 1) || col == 0 || col== (COL - 1))
        if(M[row][col] == 1)return false;
    // Mark this cell as visited
    //visited[row][col] = true;
    // Recur for all connected neighbours
    if (M[row][col] == 0)return true;

    M[row][col] = 0;
    /*
    CString a;
    a.Format(_T("%d"), M[row]][col]);
    rect->top = 200 + (row + rowNbr[k]) * space - space;
    rect->left = 100 + (col + colNbr[k]) * space - space;

    rect->bottom = 200 + (row + rowNbr[k]) * space;
    rect->right = 100 + (col + colNbr[k]) * space;
    pDc->SetTextColor(RGB(255, 0, 0));
    pDc->DrawText(a, -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    // pDc->SetTextColor(RGB(0, 255, 0));
    //pDc->DrawText(a, -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
    ::Sleep(1000);

   // boolean up=DFS(M, row + 1, col, visited, pDc, rect);
  //  boolean down = DFS(M, row - 1, col, visited, pDc, rect);
   // boolean left = DFS(M, row, col + 1, visited, pDc, rect);
   // boolean right = DFS(M, row, col - 1, visited, pDc, rect);
   */
    boolean flag = true;
    for (int k = 0; k < 4; ++k)
    {
        CString a;
        a.Format(_T("%d"), M[row + rowNbr[k]][col + colNbr[k]]);
        rect->top = 200 + (row + rowNbr[k]) * space - space;
        rect->left = 100 + (col + colNbr[k]) * space - space;

        rect->bottom = 200 + (row + rowNbr[k]) * space;
        rect->right = 100 + (col + colNbr[k]) * space;
        pDc->SetTextColor(RGB(255, 0, 0));
        pDc->DrawText(a, -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        // pDc->SetTextColor(RGB(0, 255, 0));
        //pDc->DrawText(a, -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        ::Sleep(1000);

       //if (isSafe2(M, row + rowNbr[k], col + colNbr[k], visited))
       // {

           flag= flag&& DFS(M, row + rowNbr[k], col + colNbr[k], visited, pDc, rect);
       // }

       
    }
   
    return flag;
}
//leetcode 1254
int numberOfIsolatedIslands(int M[][COL], CPaintDC* pDc, CRect* rect)
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    // Initialize count as 0 and
    // traverse through the all cells of
    // given matrix
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)

            // If a cell with value 1 is not
            if (M[i][j] ) {
                // visited yet, then new island found
                // Visit all cells in this island.
                CString a;
                a.Format(_T("%d"), M[i][j]);
                rect->top = 200 + (i)*space - space;
                rect->left = 100 + (j)*space - space;

                rect->bottom = 200 + (i)*space;
                rect->right = 100 + (j)*space;
                pDc->SetTextColor(RGB(255, 255, 0));
                pDc->DrawText(a, -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
                ::Sleep(1000);
                pDc->SetTextColor(RGB(0, 0, 0));

                pDc->DrawText(a, -1, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

                boolean flag=DFS(M, i, j, visited, pDc, rect);
                if (flag) count++;


            }

    return count;
}

// Driver code
int main()
{
    /*int M[][COL] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };

    cout << "Number of islands is: " << countIslands(M);*/

    return 0;
}

// This is code is contributed by rathbhupendra