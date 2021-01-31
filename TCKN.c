#include<stdio.h>

/*
Program, girilen TC No'nun dogrulugunu kontrol eder.
Girilen TC No'nun, TC No olusturma algoritmasiyla sistemde kayitli veya henuz kaydedilmemis kucuk veya buyuk bir yakininin TC No'sunu olusturur.

TC No Dogrulama:	11 haneli TC No'nun 1., 3., 5., 7., 9. rakamlari toplanip 7 ile carpilir.
					Cikan sonuctan TC No'nun 2., 4., 6., 8. rakamlarinin toplami cikarilir.
					Cikan sonucun mod 10 'u, 10. basamagi verir.
					10 hanesi olusan TC No'nun 1'den 10'a tum hanelerinin toplaminin mod 10 'u, 11. basamagi verir.
					Soyle ki:	((1*3*5*7*9)*7 - (2*4*6*8)) %10 = 10.hane
								(1+2+3+4+5+6+7+8+9+10) %10 = 11.hane

TC No Olusturma:	11 haneli TC No'nun son iki hanesi 10. ve 11. haneler, ilk 9 hane yardimiyla hesaplanir.
					Bu yuzden bir kucugun veya bir buyugun TC No'sunu olusturmak icin ilk 9 hanede islem yapmak yeterlidir.
					9 hanenin ilk 5 hanesi diger son 4 hanesinden ayrilarak islemler yapilir.

Bir kucugun TC No'su:	ilk bes hanenin birler basamagindan 6 cikarilir.
						Son dort hanenin birler basamagina 2 eklenir.

Bir buyugun TC No'su:	ilk bes hanenin birler basamagina 6 eklenir.
						Son dort hanenin birler basamagindan 2 cikarilir.
*/

void toint(int, int);
int tc_kontrol(void);
void bir_kucuk_tc(void);
void bir_buyuk_tc(void);

int r[11];
int sira;

int main(){
	int i, to_r;
	int r[11]={0,0,0,0,0,0,0,0,0,0,0};
	sira=0;
	char tc[11];
	
	do{
		printf("TC NO: ");
		scanf("%s", tc);
		
		// karakterleri r[11] 'e atama
		for(i=0; i<=10; i++){
			to_r=tc[i];
			toint(i, to_r);
		}
		
		// tc no kontrol
		if(tc_kontrol()==1){
			printf("[%d] Gecerli bir TC No girildi..\n\n", sira);
		}
		else{
			printf("Lutfen gecerli bir TC No giriniz.\n\n");
		}
	}while(tc_kontrol()!=1);
	
	printf("## Akrabalarinizdan, girilen TC No'ya sahip kisinin bir buyugunun TC No'su icin 'b', bir kucugunki icin 'k'; yeni TC No icin 'y', cikmak icin 'c' yaziniz.' ##\n\n");
	char kbc;
	do{
		printf("Sec (k/b/y/c): ");
		scanf(" %c", &kbc);
		
		if(kbc=='k' || kbc=='K'){
			bir_kucuk_tc();
		}
		else if(kbc=='b' || kbc=='B'){
			bir_buyuk_tc();
		}
		else if(kbc=='y' || kbc=='Y'){
			printf("\n");
			main();
			break;
		}
		else if(kbc=='c' || kbc=='C'){
			break;
		}
		else{
			printf("\nLutfen k, b, y veya c giriniz.\n");
		}
		
	}while(kbc!='c' || kbc!='C');
	
	
	return 0;
}

void bir_kucuk_tc(void){
	int dokuzda5=r[0]*10000+r[1]*1000+r[2]*100+r[3]*10+r[4], dokuzda4=r[5]*1000+r[6]*100+r[7]*10+r[8];
	int i, kalan;
	
	dokuzda5-=6;
	dokuzda4+=2;
	
	for(i=4; i>=0; i--){
		kalan=dokuzda5%10;
		r[i]=kalan;
		dokuzda5=(dokuzda5-kalan)/10;
	}
	for(i=8; i>=5; i--){
		kalan=dokuzda4%10;
		r[i]=kalan;
		dokuzda4=(dokuzda4-kalan)/10;
	}
	
	r[9] = ((r[0]+r[2]+r[4]+r[6]+r[8])*7 - (r[1]+r[3]+r[5]+r[7])) %10;
	r[10] = (r[0]+r[1]+r[2]+r[3]+r[4]+r[5]+r[6]+r[7]+r[8]+r[9])%10;

	printf("[%d] Bir kucugun TC No'su: %d%d%d%d%d%d%d%d%d%d%d \n\n", ++sira, r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8], r[9], r[10]);
}


void bir_buyuk_tc(void){
	int dokuzda5=r[0]*10000+r[1]*1000+r[2]*100+r[3]*10+r[4], dokuzda4=r[5]*1000+r[6]*100+r[7]*10+r[8];
	int i, kalan;
	
	dokuzda5+=6;
	dokuzda4-=2;
	
	for(i=4; i>=0; i--){
		kalan=dokuzda5%10;
		r[i]=kalan;
		dokuzda5=(dokuzda5-kalan)/10;
	}
	for(i=8; i>=5; i--){
		kalan=dokuzda4%10;
		r[i]=kalan;
		dokuzda4=(dokuzda4-kalan)/10;
	}
	
	r[9] = ((r[0]+r[2]+r[4]+r[6]+r[8])*7 - (r[1]+r[3]+r[5]+r[7])) %10;
	r[10] = (r[0]+r[1]+r[2]+r[3]+r[4]+r[5]+r[6]+r[7]+r[8]+r[9])%10;
	
	printf("[%d] Bir buyugun TC No'su: %d%d%d%d%d%d%d%d%d%d%d \n\n", --sira, r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8], r[9], r[10]);
}


int tc_kontrol(void){
	if( r[0]!=0 && ((r[0]+r[2]+r[4]+r[6]+r[8])*7 - (r[1]+r[3]+r[5]+r[7])) %10 == r[9] && (r[0]+r[1]+r[2]+r[3]+r[4]+r[5]+r[6]+r[7]+r[8]+r[9])%10==r[10]){
		return 1;
	}
	else{
		return 0;
	}
}

void toint(int i, int tci){
	// ASCII: 48-57
	if(tci==48){
		r[i]=0;
	}
	else if(tci==49){
		r[i]=1;
	}
	else if(tci==50){
		r[i]=2;
	}
	else if(tci==51){
		r[i]=3;
	}
	else if(tci==52){
		r[i]=4;
	}
	else if(tci==53){
		r[i]=5;
	}
	else if(tci==54){
		r[i]=6;
	}
	else if(tci==55){
		r[i]=7;
	}
	else if(tci==56){
		r[i]=8;
	}
	else if(tci==57){
		r[i]=9;
	}
}


