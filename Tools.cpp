#include "tools.h"

#include "stdio.h"

int saveData(char *filename, int _score)
{
	FILE *fp;
	int rank[RANKS_MAX] = { 0 }, info = 10;

	if (loadData(filename, rank) == 1)
	{
		for (int i = 0; i < RANKS_MAX; i++)
		{
			if (_score >= rank[i])
			{
				for (int j = RANKS_MAX - 1; j > i; j--)
				{
					rank[j] = rank[j - 1];
				}
				rank[i] = _score;
				info = i;
				break;
			}
		}
	}
	else
	{
		//return loadData(filename, _rank);
		rank[0] = _score;
		info = 0;
	}
	if (fopen_s(&fp,filename, "wb") != 0)
	{
		printf("file open error!\n");
		return -1;
	}
	if (fwrite(rank, sizeof(int), RANKS_MAX, fp) == 0)
	{
		if (ferror(fp))
		{
			printf("write error!\n");
			return -2;
		}
	}
	fclose(fp);

	return info;
}

int loadData(char *filename, int rank[])
{
	FILE *fp;

	if (fopen_s(&fp, filename, "rb") != 0)
	{
		printf("file open error!\n");
		return -1;
	}
	if (fread(rank, sizeof(int), RANKS_MAX, fp) == 0)
	{
		if (ferror(fp))
		{
			printf("read error!\n");
			return -3;
		}
	}
	fclose(fp);
	return 1;
}

