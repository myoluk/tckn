## TCKN (T.C. Kimlik Numarası)

![stars](https://img.shields.io/github/stars/myoluk/tckn)
![forks](https://img.shields.io/github/forks/myoluk/tckn)
![licence](https://img.shields.io/github/license/myoluk/tckn)
![last-commit](https://img.shields.io/github/last-commit/myoluk/tckn)

T.C. kimlik numarası doğrulama ve ilişkili (akraba) kimlik numaralarını bulma algoritması.

:beginner: Üniversite 1. dönem C programlama arşivinden (_Olduğu gibi arşivden alınmıştır_)

### Algoritma
Algoritma, girilen TCKN'nin doğruluğunu kontrol eder.
Girilen TCKN'nin, TCKN oluşturma algoritmasıyla sistemde kayıtlı veya henüz kaydedilmemiş küçük veya büyük bir yakınının TCKN'sini oluşturur.

- **TCKN Doğrulama:**
  - 11 haneli TCKN'nin 1., 3., 5., 7. ve 9. rakamları toplanıp 7 ile çarpılır.
  - Çıkan sonuçtan TCKN'nin 2., 4., 6. ve 8. rakamlarının toplamı çıkarılır.
  - Çıkan sonucun mod 10'u, 10. basamağı verir.
  - 10 hanesi oluşan TCKN'nin 1'den 10'a tüm hanelerinin toplamının mod 10'u, 11. basamağı verir.
  - **Örneğin;**	_TCKN, `123456789` ile başlasın. Bu TCKN'nin 10. ve 11. basamaklarının hesaplanması için:_
    - `10.hane` -> ((1\+3\+5\+7\+9)\*7 - (2\+4\+6\+8)) %10
    - `11.hane` -> (1+2+3+4+5+6+7+8+9+10) %10

- **TCKN Oluşturma:**
  - 11 haneli TCKN'nin son iki hanesi (10. ve 11. haneler), ilk 9 hane yardımıyla hesaplanır.
  - Bu yüzden bir küçüğün veya bir büyüğün TCKN'sini oluşturmak için ilk 9 hanede işlem yapmak yeterlidir.
  - 9 hanenin ilk 5 hanesi diğer son 4 hanesinden ayrılarak işlemler yapılır.

- **Bir küçüğün TCKN'si:**
  - ilk beş hanenin birler basamağından 6 çıkarılır.
  - Son dört hanenin birler basamağına 2 eklenir.

- **Bir büyüğün TCKN'si:**
  - ilk beş hanenin birler basamağına 6 eklenir.
  - Son dört hanenin birler basamağından 2 çıkarılır.


### Kullanım (gcc)
```sh
gcc .\TCKN.c -o TCKN.exe
.\TCKN.exe
```
