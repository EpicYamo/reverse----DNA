#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *my_join(char *str1, char *str2);

int main()
{
	char *newstr;
	char tmp[2];
	char *str = strdup("|/\\/\\/\\/\\/\\|\n");
	int speed;
	int lenstr = strlen(str);

	printf("Ne kadar hizli istersin ?:\n");
    printf("Bir secim yap (1, 2, 3): ");
    scanf("%d", &speed);
	if (speed == 1)
		speed = 50000;
	else if (speed == 2)
		speed = 40000;
	else if (speed == 3)
		speed = 30000;
	else
	{
		printf("Dogru bir secim yaptigindan emin ol :(\n 1, 2 veya 3 yazmalisin...)");
		return (0);
	}
	
	tmp[1] = '\0';
	while (1)
	{
		tmp[0] = str[lenstr - 1];
		
		newstr = my_join(tmp, str);
		
		free(str);
		str = newstr;
		printf("%s\n", newstr);
		newstr = NULL;
		usleep(speed);
	}
	free(str);
	return (0);
}
char *my_join(char *str1, char *str2)
{
	char *newstr;
	int totalen;
	int i = 0;
	int j = 0;

	totalen = strlen(str1) + strlen(str2);
	newstr = (char *)malloc((totalen + 1) * sizeof(char));
	if (str1)
	{
		while (str1[i])
			newstr[j++] = str1[i++];
	}
	i = 0;
	if (str2)
	{
		while (str2[i])
			newstr[j++] = str2[i++];
	}
	newstr[j - 1] = '\0';
	newstr[j] = '\0';
	return (newstr);
}