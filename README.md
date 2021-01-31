T.C. kimlik numarası doğrulama ve ilişkili (akraba) kimlik numaralarını bulma algoritması.
> :beginner: 1.sınıf C arşivinden

*(Olduğu gibi arşivden alınmıştır.)*

# Algoritma
Program, girilen TC No'nun doğruluğunu kontrol eder.
Girilen TC No'nun, TC No oluşturma algoritmasıyla sistemde kayıtlı veya henüz kaydedilmemiş küçük veya büyük bir yakınının TC No'sunu oluşturur.

- **TC No Doğrulama:**	11 haneli TC No'nun 1., 3., 5., 7., 9. rakamları toplanıp 7 ile çarpılır.
					Çıkan sonuçtan TC No'nun 2., 4., 6., 8. rakamlarının toplamı çıkarılır.
					Çıkan sonucun mod 10 'u, 10. basamağı verir.
					10 hanesi oluşan TC No'nun 1'den 10'a tüm hanelerinin toplamının mod 10 'u, 11. basamağı verir.
					Şöyle ki:	((1*3*5*7*9)*7 - (2*4*6*8)) %10 = 10.hane
								(1+2+3+4+5+6+7+8+9+10) %10 = 11.hane

- **TC No Oluşturma:**	11 haneli TC No'nun son iki hanesi 10. ve 11. haneler, ilk 9 hane yardımıyla hesaplanır.
					Bu yüzden bir küçüğün veya bir büyüğün TC No'sunu oluşturmak için ilk 9 hanede işlem yapmak yeterlidir.
					9 hanenin ilk 5 hanesi diğer son 4 hanesinden ayrılarak işlemler yapılır.

- **Bir küçüğün TC No'su:**	ilk beş hanenin birler basamağından 6 çıkarılır.
						Son dört hanenin birler basamağına 2 eklenir.

- **Bir büyüğün TC No'su:**	ilk beş hanenin birler basamağına 6 eklenir.
						Son dört hanenin birler basamağından 2 çıkarılır.


# Kullanım (gcc)
```sh
gcc .\TCKN.c -o TCKN.exe
.\TCKN.exe
```
