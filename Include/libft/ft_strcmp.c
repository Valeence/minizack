#include "libft.h"

int     ft_strcmp(const char *s1, const char *s2)
{
    int i;
    int j;

    if (!s1 || !s2)
        return (0);
    i = 0;
    j = 0;
    while (s1[i] != '\0')
    {
        j = 0;
        while (s2[j] != '\0' && s1[i + j] == s2[j])
            j++;
        if (s2[j] == '\0')
            return 1;
        i++;
    }
    return 0;
}
