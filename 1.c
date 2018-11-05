#include <stdio.h>
#include <jansson.h>



int main()
{
	json_t *json_obj = NULL;
	FILE *fp = NULL;
	json_error_t j_error;
	char buf[2000];
	int size;		

	fp = fopen("./json.txt", "r");
	
	while (fscanf(fp, "%d", &size) != EOF)
	{	
//		fread(buf, 1, size, fp);
		if (( json_obj = json_loadf(fp, 0, &j_error)) == NULL)
		{
			printf("Error: %s", j_error.text);	
		}
	}
	
	return 0; 
}
