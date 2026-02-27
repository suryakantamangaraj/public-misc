#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
FILE * fp;
fp = fopen("c:\\sita.txt", "w");
fputs ("This is an apple.",fp);
fseek(fp, 9, SEEK_SET);
fputs("  sam",fp);
fclose (fp);
return 0;

}
