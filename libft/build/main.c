/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:27:06 by user42            #+#    #+#             */
/*   Updated: 2021/06/02 22:03:18 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <bsd/string.h>
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <ctype.h>

static void			ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void			ft_print_tabstr(char **tabstr)
{
	int		i;

	i = 0;
	while (tabstr[i] != NULL)
	{
        printf(" %d", i + 1);
		ft_print_result(tabstr[i]);
        printf("\n");
		free(tabstr[i]);
		i++;
	}
	free(tabstr);
}

static void			check_split(char *s, char c)
{
	char	**tabstr;

	if (!(tabstr = ft_split(s, c)))
		ft_print_result("NULL");
	else
		ft_print_tabstr(tabstr);
}

int main()
{
    char *str = "sao tenho";
    char *dest = "nao tenho";
    char *str2 = "sao tenho";
    char *dest2 = "nao tenho";
    char *spaces = "================================================================================";

    printf("\n%s\nMEMMOVE\n\nFunção Original:\nOrigem: ", spaces);
    puts(str);
    memmove(dest, str, 0);
    printf("Destino: ");
    puts(dest);

    printf("\nFunção Criada:\nOrigem: ");
    puts(str2);
    ft_memmove(dest2, str2, 0);
    printf("Destino: ");
    puts(dest2);
    printf("%s\n", spaces);

    //MEMCHR
    char *chr1 = "Zimbabue";
    char *chr2 = "Zimbabue";
    char *ptr;
    char *ptr2;

    ptr = memchr(chr1, 'f', strlen(chr1));
    printf("MEMCHR\n\nFunção Original:\nInput: %s\nOutput: %s", chr1, ptr);

    ptr2 = ft_memchr(chr2, 'f', strlen(chr2));
    printf("\n\nFunção Criada:\nInput: %s\nOutput: %s\n%s\n", chr2, ptr2, spaces);

    //MEMCMP
    char *cmp1 = "realizando um teste";
    char *cmp2 = "realizando novo teste";
    printf("MEMCMP\n\nFunção Original:\nInput: String 1: %s / String 2: %s\nOutput: %i", cmp1, cmp2, memcmp(cmp1, cmp2, 13));
    printf("\n\nFunção Criada:\nInput: String 1: %s / String 2: %s\nOutput: %i\n%s", cmp1, cmp2, ft_memcmp(cmp1, cmp2, 13), spaces);

    //STRLEN
    char *len1 = "Essa função retorna o tamanho de uma string!";
    printf("\nSTRLEN\n\nFunção Original:\nInput: %s\nOutput: %zu", len1, strlen(len1));
    printf("\n\nFunção Criada:\nInput: %s\nOutput: %zu\n%s", len1, ft_strlen(len1), spaces);

    //SRTLCPY
    char source[] = "Copy Soue"; //11
    char destn[] = "Destination0";

    char source2[] = "Copy Soue";
    char destn2[] = "Destination0";

    unsigned int n1 = 9;
    int n2 = 9;

    int tam1;
    int tam2;

    printf("\nSTRLCPY\n\n");
    tam2 = strlcpy(destn2, source2, n2);
    printf("Função Original:\nInput: Source = %s e Destination = %s\n", source2, destn2);
    printf("Output:  Return size Source = %d\n", tam2);

    printf("\nFunção Criada:\n");
    tam1 = ft_strlcpy(destn, source, n1);
    printf("Input: Source = %s e Destination = %s\n", source, destn);
    printf("Output:  Return size Source = %d\n%s\n", tam1, spaces);

    //SRTLCAT
    char scat[] = "Copy Source"; //11
    char dcat[] = "Destin";      //12

    char scat2[] = "Copy Source";
    char dcat2[] = "Destin";

    unsigned int ncat = 12;
    int ncat2 = 12;

    int lcat1;
    int lcat2;

    printf("STRLCAT\n\n");
    printf("Função Original:\nInput: Source = %s e Destination = %s\n", scat, dcat);
    lcat1 = strlcat(dcat, scat, ncat);
    printf("Output:  Return size Source = %d\n", lcat1);

    printf("\nFunção Criada:\n");
    printf("Input: Source = %s e Destination = %s\n", scat2, dcat2);
    lcat2 = ft_strlcat(dcat2, scat2, ncat2);
    printf("Output:  Return size Source = %d\n%s\n", lcat2, spaces);

    //STRCHR
    char *schr = "testando strchr";
    int c = 't';
    char *schr2 = "testando strchr";
    int c2 = 't';

    printf("STRCHR\n\nFunção Original:\nInput: %s\nOutput: %s", schr, strchr(schr, c));
    printf("\n\nFunção Criada:\nInput: %s\nOutput: %s\n%s\n", schr2, ft_strchr(schr2, c2), spaces);

    //STRRCHR
    char *srchr = "testando strrchr";
    int cr = 'e';
    char *srchr2 = "testando strrchr";
    int cr2 = 'e';

    printf("STRRCHR\n\nFunção Original:\nInput: %s\nOutput: %s", srchr, strrchr(srchr, cr));
    printf("\n\nFunção Criada:\nInput: %s\nOutput: %s\n%s\n", srchr2, ft_strrchr(srchr2, cr2), spaces);

    //STRNSTR
    char *strbig = "testando ovo cozido strnstr";
    char *strlittle = "str";
    size_t strsize = 13;
    char *strbig2 = "testando strnstr";
    char *strlittle2 = "str";
    size_t strsize2 = 13;

    printf("STRNSTR\n\nFunção Original:\nInput: String: %s  /  Substring: %s -- Tamanho: %zu\nOutput: %s", strbig, strlittle, strsize, strnstr(strbig, strlittle, strsize));
    printf("\n\nFunção Criada:\nInput: String: %s  /  Substring: %s -- Tamanho: %zu\nOutput: %s\n%s", strbig2, strlittle2, strsize2, ft_strnstr(strbig2, strlittle2, strsize2), spaces);

    //STRNCMP
    char *strcmp1 = "strnstr";
    char *strcmp2 = "str";
    size_t cmpsize = 8;
    char *strcmp3 = "strnstr";
    char *strcmp4 = "str";
    size_t cmpsize2 = 8;

    printf("\nSTRNCMP\n\nFunção Original:\nInput: String: %s  /  Substring: %s -- Tamanho: %zu\nOutput: %d", strcmp1, strcmp2, cmpsize, strncmp(strcmp1, strcmp2, cmpsize));
    printf("\n\nFunção Criada:\nInput: String: %s  /  Substring: %s -- Tamanho: %zu\nOutput: %d\n%s", strcmp3, strcmp4, cmpsize2, ft_strncmp(strcmp3, strcmp4, cmpsize2), spaces);

    //ATOI
    char *stratoi = "     -1123";
    char *ftstratoi = "1123";
    printf("\nATOI\n\nFunção Original:\nInput: %s\nOutput: %d", stratoi, atoi(stratoi));
    printf("\n\nFunção Criada:\nInput: %s\nOutput: %d\n%s", ftstratoi, ft_atoi(ftstratoi), spaces);

    //ISALPHA
    char calpha = 'a';
    printf("\nISALPHA\n\nFunção Original: \nInput: %c\nOutput: %i", calpha, isalpha(calpha));
    printf("\n\nFunção Criada:\nInput: %c\nOutput: %i\n%s", calpha, ft_isalpha(calpha), spaces);

    //ISDIGIT
    int cdigit = 'a';
    printf("\nISDIGIT\n\nFunção Original: \nInput: %c\nOutput: %i", cdigit, isdigit(cdigit));
    printf("\n\nFunção Criada:\nInput: %c\nOutput: %i\n%s", cdigit, ft_isdigit(cdigit), spaces);

    //ISALNUM
    int calnum = '3';
    printf("\nISALNUM\n\nFunção Original: \nInput: %c\nOutput: %i", calnum, isalnum(calnum));
    printf("\n\nFunção Criada:\nInput: %c\nOutput: %i\n%s", calnum, ft_isalnum(calnum), spaces);

    //ISASCII
    char cascii[6] = {'1', 128, '\n', '\\', 'a', 'd'};
    int i = 0;
    int j = 0;
    printf("\nISASCII\n\nFunção Original: \n");
    while (i < 6)
    {
        printf("In: %c", cascii[i]);
        printf(" -- Out: %i\n", isascii(cascii[i]));
        i++;
    }

    printf("\n\nFunção Criada: \n");
    while (j < 6)
    {
        printf("In: %c", cascii[j]);
        printf(" -- Out: %i\n", ft_isascii(cascii[j]));
        j++;
    }
    printf("%s\n", spaces);

    //ISPRINT
    char cprint[6] = {1, 127, '\n', '\\', 'a', 'd'};
    int iprint = 0;
    int jprint = 0;
    printf("ISPRINT\n\nFunção Original: \n");
    while (iprint < 6)
    {
        printf("In: %c", cprint[iprint]);
        printf(" -- Out: %i\n", isprint(cprint[iprint]));
        iprint++;
    }

    printf("\n\nFunção Criada: \n");
    while (jprint < 6)
    {
        printf("In: %c", cprint[jprint]);
        printf(" -- Out: %i\n", ft_isprint(cprint[jprint]));
        jprint++;
    }
    printf("%s\n", spaces);

    //TOUPPER
    char *cupper = "abacate";
    int iupper = 0;
    int iupper2 = 0;
    printf("TOUPPER\n\nFunção Original:\nInput: %s\nOutput: ", cupper);
    while (cupper[iupper] != '\0')
    {
        printf("%c", toupper(cupper[iupper]));
        iupper++;
    }
    printf("\n\nFunção Criada:\nInput: %s\nOutput: ", cupper);
    while (cupper[iupper2] != '\0')
    {
        printf("%c", ft_toupper(cupper[iupper2]));
        iupper2++;
    }
    printf("\n%s\n", spaces);

    //TOLOWER
    char *clower = "ABACATE";
    int ilower = 0;
    int ilower2 = 0;
    printf("TOLOWER\n\nFunção Original:\nInput: %s\nOutput: ", clower);
    while (clower[ilower] != '\0')
    {
        printf("%c", tolower(clower[ilower]));
        ilower++;
    }
    printf("\n\nFunção Criada:\nInput: %s\nOutput: ", clower);
    while (clower[ilower2] != '\0')
    {
        printf("%c", ft_tolower(clower[ilower2]));
        ilower2++;
    }
    printf("\n%s\n", spaces);
    
    //STRDUP
    char *dupstr = "testando a strdup";
    printf("STRDUP\n\nFunção Original:\nInput: %s\nOutput: %s", dupstr, strdup(dupstr));
    printf("\n\nFunção Criada:\nInput: %s\nOutput: %s", dupstr, ft_strdup(dupstr));
    printf("\n%s\n", spaces);

    //SUBSTR
    char *strsub = "Daqui saíra a substring";
    unsigned int inisub = 15;
    size_t lensub = 9;
    printf("SUBSTR\n\nFunção Criada:\nInput: %s\nOutput: %s", strsub, ft_substr(strsub, inisub, lensub));
    printf("\n%s\n", spaces);

    //STRJOIN
    char *prefix = "Essa String ";
    char *sufix = "se une a essa";
    printf("STRJOIN\n\nFunção Criada:\nInput:\nPrefixo: %s\nSufixo: %s\n\nOutput: %s", prefix, sufix, ft_strjoin(prefix, sufix));
    printf("\n%s\n", spaces);
    
    //STRTRIM
    char *str_src = "TrimrTimTrTmTrimTrimPassedTrimTrimTrimTrimTrim";
    char *trim = "Trim";
    printf("STRTRIM\n\nFunção Criada:\nInput:\nString: %s\nSet: %s\n\nOutput: %s", str_src, trim, ft_strtrim(str_src, trim));
    printf("\n%s\n", spaces);

    //ITOA
    int nmbtoa = 'a';
    printf("ITOA\n\nFunção Criada: \nInput: %d\nOutput: %s", nmbtoa, ft_itoa(nmbtoa));

    //PUTSTR
    printf("\n%s\nPUTSTR\n\n", spaces);
    ft_putstr_fd("lorem ipsum dolor sit amet\n", 2);
	ft_putstr_fd("  lorem\nipsum\rdolor\tsit amet  \n", 1);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("lorem ipsum do\0lor sit amet\n", 1);

    //PUTENDL
    printf("\n%s\nPUTENDL\n\n", spaces);
	ft_putendl_fd("lorem ipsum dolor sit amet\n", 2);
    printf("\n");
	ft_putendl_fd("  lorem\nipsum\rdolor\tsit amet  \n", 1);
    printf("\n");
	ft_putendl_fd("", 2);
    printf("\n");
	ft_putendl_fd("lorem ipsum do\0lor sit amet\n", 1);
	
    //PUTNBR
    printf("\n%s\nPUTNBR\n\n", spaces);    	
    ft_putnbr_fd(0, 2);
    printf("\n");
	ft_putnbr_fd(5, 1);
    printf("\n");
	ft_putnbr_fd(-5, 2);
    printf("\n");
	ft_putnbr_fd(42, 1);
    printf("\n");
	ft_putnbr_fd(-57, 2);
    printf("\n");
	ft_putnbr_fd(164189, 1);
    printf("\n");
	ft_putnbr_fd(-987441, 2);
    printf("\n");
	ft_putnbr_fd(2147483647, 1);
    printf("\n");
	ft_putnbr_fd(-2147483648LL, 2);
    
    //STRSPLIT
    printf("\n%s\nSTRSPLIT\n\n", spaces);
    printf("String 1:\n");
	check_split("          ", ' ');
    printf("\nString 2:\n");
	check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
    printf("\nString 3:\n");
	check_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
    printf("\nString 4:\n");
	check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
    printf("\nString 5:\n");
	check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
    
    return (0);
}