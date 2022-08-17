#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


unsigned int LilEndianToBigEndian(unsigned int x)
{
	return x = (x & 0xFF) << 8 | (x & 0xFF00) >>  8;

}


int main(int argc, char** argv)
{
	if (argc != 6)
    	{
        	printf("Недостаточно аргументов\n");
        	return -1;
    	}
	int K =atoi(argv[5]);
	unsigned int D = 0;
	unsigned long sum = 0;
	char sep[10]=".";
	unsigned long sumDate = 0;
	unsigned long long finalSum = 0;



	for(int j = 1; j<4;j++)
	{
		uint16_t* symbol = (uint16_t*)argv[j];
		for (int i = 0; i < (strlen(argv[j])) / 2; i++)
		{

			D = *symbol;
        		D= LilEndianToBigEndian(D);
			sum+=D*D;
			printf(" %x\n",D);
			symbol +=1;

		}
		printf("\n");
	}

	printf("\n");
	printf("SumName: %lu\n",sum);



	char *istr;
	istr = strtok(argv[4],sep);
	sumDate = atoi(istr);
	istr = strtok(NULL,sep);
	sumDate+= atoi(istr)*30;
	istr = strtok(NULL,sep);
	sumDate += atoi(istr)*365;

	printf("SumDate %lu\n",sumDate);
	finalSum = sum * sumDate;
	printf("Final  %llu\n", finalSum);


	int length = 0;
	unsigned long long param = finalSum;
	do
	{
		length++;
		param /= 10;
	}while(param>0);
//	printf("%d\n",length);

	length = length / 2;

	int finalNumber = 0;
	char* buffer;
	sprintf(buffer, "%llu\n", finalSum );
	for(int i = 0; i<strlen(buffer)-1; i++)
	{
		printf("%d - %d",i+1,buffer[i]-'0');
		printf("\n");

	}

	int numbers = 0;
	printf("\n\n");
	printf("1 - %d\n",buffer[length-1]-'0');
	printf("2 - %d\n",buffer[length]-'0');
	printf("3 - %d\n",buffer[length+1]-'0');

	numbers = (buffer[length-1]-'0')*100+(buffer[length]-'0')*10 + buffer[length+1]-'0';





	printf("%d\n",numbers);

	printf("K = %d\n", K);
	int Variant = numbers % K + 1;

	printf("Variant - %d\n", Variant);

	return 0;
}
