#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Global Degiskenler
int counter=0, i=0;				//Genel Sayac - Tekrardan Kacinmak Icin Kullaniyoruz
double temp;					//Geçici Degiskenler

/* 	Menu Fonksiyonu
	Bu fonksiyonun amaci kullaniciya islem yapmak istedigi dosyayi sectirmek. Ve dosya ismini proje geneline hazir hale getirerek, islemleri hazirlamak.
	Ornegin 1 girildigin 10 adet degere sahip liste isleme alinacaktir.
*/
char* menu()
{
	int choise=0;
	char *fileName;
	
	printf("*****************************************  MENU  *****************************************\n\n");
	printf("Select the File You Want Sorted. (Please enter the line number. Simple; 1)\n");
	printf("Note: Your choise and start the time!\n\n");
	printf("1-10.txt\n2-100.txt\n3-100.000.txt\nSelect:");
	scanf("%d",&choise);
	
	
	switch(choise)
	{
		case 1: 	fileName="10lukliste.txt"; 		return fileName;	break;
		case 2: 	fileName="100lükliste.txt"; 	return fileName;	break;
		case 3: 	fileName="100000likliste.txt";	return fileName;	break;
		default:	
			system("cls"); //Console Ekrani Temizleme
			printf("***************************  Incorrect Entry! Please Try Again.  ***************************\n\n");
			menu();
	}
	
}


/*  readFileItemSize Fonksiyonu
	Dosya icerisindeki deger sayisini saydirarak geriye int deger donduruyoruz. Amacimiz tanimlayacagimiz dizi için buyukluk belirlemek.
*/
int readFileItemSize(char* fileName)
{
	FILE *filePointer;	//Dosyayi gosteren pointer tanimliyoruz. Bu sayede dosya uzerinde acma/kapatma vb. islemler icin adres gosterebilecegiz.
	
	if((filePointer=fopen(fileName,"r"))==NULL)	//Burada tanimli olan fileName parametresini fileNameOperation methodu icerisinden aliyoruz.
	{
		printf("The File Could Not Be Opened Or Not Found File");
		exit(1);
	}	
	while(fscanf(filePointer, "%lf",&temp) != EOF)	//EOF liste sonuna geldiginde 0 harici bir deger doner. Dosya sonuna kadar kontrol bu sekilde sagliyoruz. Farkli dosyalar icin yazilimin genisletilbilecegini varsayiyoruz.
		counter++;
		
	fclose(filePointer);
	return counter;
}


/* 	fileItemGetArray Fonksiyonu
	readFileItemSize fonksiyonu icerisinde aldigimiz dizi buyuklugune gore olusturan dizi icerisine txt dosyalari icerisinde yer alan degerleri tip donusumu yaparak int degisken olarak atiyoruz.
*/
void fileItemGetArray(int fileArray[], char *fileName)
{	
	FILE *filePointer;
	filePointer=fopen(fileName,"r");
	
	counter = 0;
	while(fscanf(filePointer, "%lf",&temp) != EOF)
	{	
		fileArray[counter]=(int)(temp * 1000); //Tip Donusumu
		counter++;
	}
	
	fclose(filePointer);	
}


/* 	radixSort Fonksiyonu
	Maksimum degeri bularak basamak sayisa gore for dongusu donduruyoruz. Her basamagin elemanina bakabiliyoruz. 
	Bu dongu icerisinde de "counting sort" algortimasi ise sayimlari gerceklestiriyoruz.
*/
void radixsort(int fileArray[], int itemNum)
{
    int maxValue = findMaxValue(fileArray, itemNum);
 
    int digit = 0;
	for (digit = 1; maxValue / digit > 0; digit *= 10)
        countSort(fileArray, itemNum, digit);
}


//Maksimum deðer bulma -> Kaç basamak ile ugrasicagimizzi bilmemiz icin gerekli.
int findMaxValue(int fileArray[], int fileItem)
{
    int maxValue = fileArray[0];
    for (i = 1; i < fileItem; i++)
        if (fileArray[i] > maxValue)
            maxValue = fileArray[i];
    return maxValue;
}
 
/*	countSourt Fonksiyonu
	Digitlere gore sirali olarak bir sayac tutuyoruz. Daha sonra bu sayac degerlerini  indis sirasiyla toplayarak hazirliyoruz.
	Bunun sonucunda olusan count aarray yardimiyla siralama islemi yaparak parametre olarak aldigimiz gercek array ile degistiyoruz.
	- Digit de buldugumuz her sayiyi count dizisi yardimiyla arttiriyor. Hangi sayidan kaç adet var?
	- Daha sonra bulunan dizide sirali olarak toplayarak indisleri dolasiyoruz.
	- Son olarak diziyi siraliyorak diziye yaziyoruz.
	- Siralanmis diziyi parametre olarak verdigimiz dizinin uzerine yaziyoruz.
*/ 
void countSort(int fileArray[], int itemNum, int digit)
{
    int output[itemNum];
    int i, count[10] = { 0 };
 
    for (i = 0; i < itemNum; i++)
        count[(fileArray[i] / digit) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = itemNum - 1; i >= 0; i--) 
	{
        output[count[(fileArray[i] / digit) % 10] - 1] = fileArray[i];
        count[(fileArray[i] / digit) % 10]--;
    }
 
    for (i = 0; i < itemNum; i++)
        fileArray[i] = output[i];
}


void printList(int fileArray[], int itemNum)
{
	printf("\n");
	for(i=0;i<itemNum;i++)
	{
		double temp2 = (double)fileArray[i];
		double temp = (double)(temp2/1000);
		printf("%lf\n",temp);
	}
	
}


//Milisaniye olarak dosya secim isleminden sonra milisaniyeyi hesapliyoruz.
void timeCalculate(clock_t start, clock_t end, clock_t fileReadEnd, clock_t radixSortTime)
{
	printf("\n\nFile Read CPU Time(MiliSecond): %lf\n",(double)(fileReadEnd-start));
	printf("Radix Sort Time CPU (MiliSecond): %lf\n",(double)(radixSortTime-fileReadEnd));	
	printf("Sort List Print Time(MiliSecond): %lf\n",(double)(end-radixSortTime));
	printf("File Choise After Operation CPU Time(MiliSecond): %lf\n",(double)(end-start));

}



int main(int argc, char *argv[]) 
{	
	clock_t  fileReadEnd, radixSortTime, start, end;

	//Dosyadan okuma ve dizi islemleri
	char *fileName = menu();
	
	start = clock();
	
	int itemNum = readFileItemSize(fileName);
	int fileArray[itemNum];
	fileItemGetArray(fileArray,fileName);
	
	fileReadEnd = clock();
	
	//Radix Sort Ile Siralama Ve Yazdirma
    radixsort(fileArray, itemNum);
    
    radixSortTime = clock();
	
	printList(fileArray, itemNum);
	end = clock();
	timeCalculate(start,end,fileReadEnd,radixSortTime);
	return 0;
}
