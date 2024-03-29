#include<iostream>
using namespace std;

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;
	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);

	int pathLength = 0;
	for(int row=0;row<rows;row++)
		for (int col = 0; col < cols; col++)
		{
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
				return true;
		}
}

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
	if (str[pathLength] == '\0')
		return true;

	bool answer = false;
	if (row >= 0 && row < rows&&col >= 0 && col < cols&&matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col])
	{
		pathLength++;
		visited[row*cols + col] = true;

		answer = hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited);

		if (!answer)
		{
			--pathLength;
			visited[row*cols + col] = false;
		}
	}
	return answer;
}

int main()
{
	return 0;
}