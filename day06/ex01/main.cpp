#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#define A "65 - A, 90 - Z, 97 - a, 122 - z, 48 - 0, 57 - 9"

struct Data {
	std::string	s1;
	int			n;
	std::string	s2;
};

int		getRandomAlphanum()
{
	int	randn = rand() % 62;
	if (randn < 26)
		return (65 + randn);
	else if (randn >= 26 && randn < 52)
		return (97 + randn - 26);
	else
		return (48 + randn - 52);
}


void	*serialize(void)
{
	char	*seria = NULL;
	try
	{
		seria = new char[16 + sizeof(int)];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	for (int i = 0; i < 16 + sizeof(int); i++)
		seria[i] = getRandomAlphanum();
	return (reinterpret_cast<void *>(seria));
}

Data	*deserialize(void *raw)
{
	if (!raw)
		return (NULL);
	struct Data *deserializeData = NULL;
	try
	{
		deserializeData = new struct Data;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	char	*ptrToStartSeia = reinterpret_cast<char *>(raw);
	deserializeData->s1 = std::string(ptrToStartSeia, 8);
	deserializeData->n = *(reinterpret_cast<int *>(ptrToStartSeia + 8));
	deserializeData->s2 = std::string(ptrToStartSeia + 8 + sizeof(int), 8);
	return (deserializeData);
}

int main()
{
	srand(time(0));
	struct Data data;
	void *s = serialize();
	std::cout << "Raw data representation:\n";
	if (s)
	{
		std::cout <<"S1: ";
		for (int i = 0; i < 16 + sizeof(4); i++)
		{
			if (i == 8)
			{
				std::cout << *(reinterpret_cast<int *>(reinterpret_cast<char *>(s) + 8));
				i += sizeof(int) - 1;
			}
			else
				std::cout << reinterpret_cast<char *>(s)[i];
			if (i == 7)
				std::cout << "\nInt N: ";
			else if (i == sizeof(int) + 8 - 1)
				std::cout << "\nS2: ";
		}
	}

	struct Data *ds = deserialize(s);
	std::cout << "\n\nDeserialize data representation:\n";
	if (ds)
	{
		std::cout << "String1: " << ds->s1 << std::endl;
		std::cout << "N: " << ds->n << std::endl;
		std::cout << "String1: " << ds->s2 << std::endl;
	}
	delete reinterpret_cast<char *>(s);
	delete ds;
	return (0);
}