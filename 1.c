#include <stdio.h>
#include <jansson.h>



int main()
{
	json_t *json_obj = NULL;
	FILE *fp = NULL;
	json_error_t j_error;
	char buf[2000];
	int size;		
	int hb, hb2;

	fp = fopen("./json.txt", "r");
	
	while (fscanf(fp, "%d\n", &size) != EOF)
	{	
		fread(buf, 1, size, fp);
		if (( json_obj = json_loadb(buf, size, 0, &j_error)) == NULL)
		{
			printf("line: %d, column: %d, position: %d, source: %s, Error: %s"
				,j_error.line, j_error.column, j_error.position, j_error.source, j_error.text);	
		}
		
		json_unpack(json_obj, "{s:{s:i, s:i}}", "first", "heartbeat", &hb, "heartbeat2", &hb2);
		
		printf("size = %d, Heartbeat = %d, heartbeat2 = %d\n", size, hb, hb2);
	}
	
	return 0; 
}
