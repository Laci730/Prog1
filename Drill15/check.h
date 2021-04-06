using namespace std;

bool check(char *list, string name)
{
	for (int i = 0; i < name.length(); i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (name[i] == list[j])
				return false;
		}
	}
	return true;
}