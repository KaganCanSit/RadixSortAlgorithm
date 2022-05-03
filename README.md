# Radix Sort Algorithm

# •  **Radix Sort Algoritması Nedir? Nasıl Çalışır?**

Radix kelimesi dilimizde “sayı tabanı” olarak çevrilmektedir ve eski zaman ararlığında bir dönem taban kelimesi yerine kullanılmıştır. 10’luk taban, 16’lık taban gibi. Bunun ilişkisi ise biraz mantığında yatmaktadır.

Radix Sıralama Algoritması, elimizde var olan sayı dizilerinin sağdan başlayarak sıralı olarak sıralanmasına dayanır. Bu sıralama birler, onlar, yüzler vb. şeklinde giderken sıralamanın temeli için bulunduğu radix/basamak kullanılır.

Basit bir örnek vermek gerekirse;

Elimizde 14.32, 16, 21.13, 14.48, 72, 85 değerlerine sahip bir dizi bulunsun. Bunları sıralamak istediğimizde en fazla basamak değerine sahip sayı baz alınır. (En büyük sayıya da bakabilirsiniz.)

Burada toplamda dört adet basamağımız bulunduğunu söyleyebiliriz.

---

Şimdi ilk olarak en sağdaki basamağa bakıyoruz;

14,32 → 2

16,00 → 0

21,13 → 3

14,48 → 8

72,85 → 5

Şimdi bu sayılar ışığında ilk sıralamamızı gerçekleştirelim. 

<aside>
⁉️ Bu sıralamanın en sağ basamağı ele alarak gerçeklendiğini unutmayın.

</aside>

16,00 / 14,32 / 21,13 / 72,85 / 14,48

Sanki doğru olmadı gibi değil mi? Çünkü henüz sadece en sağ basamağı gerçekleştirdik. Bunu tüm basamaklara uygulamalıyız.

---

16,00 → 0

14,32 → 3

21,13 → 1

72,85 → 8

14,48 → 4

İkinci sıralamamızı gerçekleştirelim.

16,00 / 21,13 / 14,32 / 14,48 / 72,85

---

16,00 → 6

21,13 → 1

14,32 → 4

14,48 → 4

72,85 → 2

Üçüncü sıralamamızı gerçekleştirelim.

21,13 / 72,85 / 14,32 / 14,48 / 16,00

<aside>
🚀 Burada iki adet 4 değeri ile karşılaştık böyle durumda dizi içerisindeki sıra, ilk karşılaştığımız değer baz alınır.

</aside>

---

21,13 → 2

72,85 → 7

14,32 → 1

14,48 → 1

16,00 → 1

Dördüncü ve son sıralamamızı gerçekleştirelim.

14,32 / 14,48 / 16,00 / 21,13 / 72,85

---

Radix Sort Sıralama algoritmasını kullanırken basamak değerlerini sıralamak için de farklı algoritmalar kullanılır. Çeşitli algortima seçenekleri olsa da en bilindik ikisi şunlardır;

- **Bucket Sort**
    
    Bucket Sort Algoritması genellikle liste ve kuyruk yapısı yardımıyla kullanarak sayıları sıralar.
    
    Yukarıdaki örneğimizi ele alırsak her eleman için liste içerisine atarak geri alır. Fakat yazının kısa olması adına ben sadece en sağ basağımızı göstereceğim.
    
    L0 → 16,00
    
    L2 → 14,32
    
    L3 → 21,13
    
    L5 → 72,85
    
    L8 → 14,48
    
    Bu şekilde değerleri liste veya kuyruk yapısına attıktan sonra küçükten büyüğe alarak ilk sıralamayı oluşturabiliriz.
    

- **Counting Sort**
    
    Counting Sort Sıralamasında ise ilk olarak 0,9’a tanımlı on elemanlı bir dizi içerisinde bulunan sayıları sırasıyla arttırak eklerseniz. Örneği iki değerinden iki adet varsa 2.indis değeri ikidir.
    
    Değerlerimizi yeniden hatırlayalım. { 14,32 | 16,00 | 21,13 | 14,48 | 72,85 }
    
    Fakat yazının kısa olması adına ben sadece en sağ basağımızı göstereceğim.
    
    0  |  1 |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  
    
    0     0    1    0     0     0     0     0     0     0
    
    1     0    1    0     0     0     0     0     0     0
    
    1     0    1    1     0     0     0     0     0     0
    
    1     0    1    1     0     0     0     0     1     0  
    
    1     0    1    1     0     1     0     0     1     0 
    
    Tüm değerler seçildikten sonra bu değerler soldan sağa toplanarak yazılır.
    
    1     1    2    3     3     4     4      4    5     5
    
    ---
    
    Şu an ilk dizimizden de yola çıkarak şöyle bir yol izlenir.
    
    14,32 → 2 / 2 → 2.indise git. 2. indise 2 yaz. 1 azalt.
    
    0  |  1 |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9
    
    1     1    1    3     3     4     4      4    5     5
    
    0     0    2    0     0     0     0     0     0     0
    
    ---
    
    16,00 → 0.indise git. 1. indise 0 yaz. 1 azalt.
    
    0  |  1 |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  
    
    0     1    1    3     3     4     4      4    5     5
    
    0     0    2    0     0     0     0     0     0     0
    
    ---
    
    21,13 → 3.indise git. 3. indise 3 yaz. 1 azalt.
    
    0  |  1 |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  
    
    0     1    1    2     3     4     4      4    5     5
    
    0     0    2    3     0     0     0     0     0     0
    
    ---
    
    14,48 → 8.indise git. 5. indise 8 yaz. 1 azalt.
    
    0  |  1 |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  
    
    0     1    1    2     3     4     4      4    4     5
    
    0     0    2    3     0     8     0     0     0     0
    
    ---
    
    72,85→ 5.indise git. 4. indise 5 yaz. 1 azalt.
    
    0  |  1 |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  
    
    0     1    1    2     3     3     4      4    4     5
    
    0     0    2    3     5     8     0     0     0     0
    
    <aside>
    🚀 Mavi noktadaki sıra ile yaz → 16,00 / 14,32 / 21,13 / 72,85 / 14,48  
    </aside>
    

Radix Sort’un sıralama algoritması taban sıralama olarak bu şekilde çalışmaktadır. Bu işlemlerin sıralı tekrarıyla dizi en sağdan en sağa değerler incelenerek sıralanır.

---

# 📜 Boyut - Zaman Grafikleri

Burada kıyaslama yapabilmek için ms noktasında ölçüm yapan bir sınıf kullandım. Fkat ondalık hassasiyeti nanosaniye desteği bulunmadığı için her listeyi 10 kez tekrarlayarak baz değerler oluşturdum ve kategorilendirdim.

- Bu test sırasında arkaplanda çalışan  herhangi bir uygulama olmadı ve laptop prize takılı durumdayıdı.
- Sistem Özelliklerim → I7 9750H İşlemci / 16GB RAM / PCI GEN4x0 Samsung SSD

Tabloda gösterilen değerler **milisaniye (ms**) olarak ölçülmüştür. Ölçüm için **time.h kütüphanesi altındaki clock_t fonksiyonu** kullanılmıştır.

<aside>
🚫 İşlemcinin çalışma süresinin nanosaniye zaman ölçümünü Kernel izin vermediği için alamadım.
</aside>

 Bu yüzden buradaki değerlerin min. ve max. değerlerini kabul ederek bir durum tablosu daha oluşturdum. Sıfır hassasiyeti **içerisinde yuvarlama bulunduğu için incelerken dikkate alınız.**

| Dosyadaki Eleman Sayısı | Dosyadan Okuma | Sıralama (Radix Sort) | Sıralanmış Listeye Ekrana Yazdırma | Dosya Seçiminden İtibaren (Menu Sonrası) Zaman |
| --- | --- | --- | --- | --- |
| 10 | 1 ms | 0 ms | 1 ms | 2 ms |
| 10 | 0 ms | 0 ms | 1 ms | 1 ms |
| 10 | 0 ms | 0 ms | 1 ms | 1 ms |
| 10 | 0 ms | 0 ms | 1 ms | 1 ms |
| 10 | 1 ms | 0 ms | 2 ms | 3 ms |
| 10 | 0 ms | 0 ms | 1 ms | 1 ms |
| 10 | 0 ms | 0 ms | 0 ms | 0 ms |
| 10 | 0 ms | 0 ms | 2 ms | 2 ms |
| 10 | 0 ms | 0 ms | 1 ms | 1 ms |
| 10 | 0 ms | 0 ms | 1 ms | 1 ms |
| 100 | 0 ms | 0 ms | 26 ms | 26 ms |
| 100 | 0 ms | 0 ms | 26 ms | 26 ms |
| 100 | 0 ms | 0 ms | 31 ms | 31 ms |
| 100 | 0 ms | 0 ms | 30 ms | 30 ms |
| 100 | 0 ms | 0 ms | 31 ms | 31 ms |
| 100 | 1 ms | 0 ms | 34 ms | 34 ms |
| 100 | 0 ms | 0 ms | 31 ms | 31 ms |
| 100 | 0 ms | 0 ms | 34 ms | 34 ms |
| 100 | 0 ms | 0 ms | 42 ms | 42 ms |
| 100 | 0 ms | 0 ms | 31 ms | 31 ms |
| 100.000 | 49 ms | 13 ms | 7810 ms | 7872 ms |
| 100.000 | 52 ms | 15 ms | 7856 ms | 7923 ms |
| 100.000 | 49 ms | 14 ms | 7793 ms | 7856 ms |
| 100.000 | 50 ms | 14 ms | 7278 ms | 7342 ms |
| 100.000 | 50 ms | 13 ms | 7843 ms | 7906 ms |
| 100.000 | 53 ms | 14 ms | 7803 ms | 7870 ms |
| 100.000 | 50 ms | 13 ms | 7770 ms | 7833 ms |
| 100.000 | 49 ms | 14 ms | 7406 ms | 7469 ms |
| 100.000 | 50 ms | 13 ms | 7824 ms | 7787 ms |
| 100.000 | 50 ms | 14 ms | 7734 ms | 7798 ms |

Tüm durumlar baz alınarak hazırlandığında n sayısını gerçekleşme zamanı baz alırsak çıkan aralıklar;

| Dosyadaki Eleman Sayısı | Dosyadan Okuma | Sıralama (Radix Sort) | Sıralanmış Listeye Ekrana Yazdırma | Dosya Seçiminden İtibaren (Menu Sonrası) Zaman |
| --- | --- | --- | --- | --- |
| 10 | 0 ms < n ≤1 ms | 0 ms < n <1 ms | 0 ms < n ≤2 ms | 0 ms < n ≤3 ms |
| 100 | 0 ms < n ≤1 ms | 0 ms < n <1 ms | 26 ms ≤ n ≤42 ms | 26 ms≤ n ≤42 ms |
| 100.000 | 49 ms ≤ n ≤53 ms | 13 ms ≤ n ≤15 ms | 7278 ms ≤ n ≤ 7856 ms | 7342 ms ≤ n ≤ 7924 ms |

<aside>
💡 Ek Not: C dili makine dilini yakın olduğu için işlem hesaplarında diğer dillerden kat kat hızlıyken ekrana değer yazdırma noktasında printf methodu satır satır yazdığı için yavaştır.

</aside>

Aşağıdaki tobla yukarıdaki metrik değerlerin en kötüleri ele alınarak hazırlanmıştır.

![Untitled](https://github.com/KaganCanSit/RadixSortAlgorithm/blob/main/Document/Pictures/Untitled.png)

# 🧠 Boyut - Zaman Grafiklerinin Yorumu

Grafiğe bakarak sadece “Sıralama (Radix Sort)” performansına bakacak olursak. Düşük dizilerdeki performansı diğer (Quick Sort) gibi algoritmalara göre aynı olarak kalmaktadır. Fakat yüksek dizi ve basamak sayısına sahip değerlerde ise bu durum tam tersidir. Tartışmasız mutlak hakimiyet Radix Sort algoritmasındadır. Örneğimizin üzerinden gidelim;

10 elemanlı bir veri 1ms, 100 elemanlı bir veri 1 ms, 100.000 elemanlı bir veri ise 15 ms saniye sürmüş. Buradaki zaman zarfı kesinlikle tatmin edici. Eleman artışımız kesinlikle çok hızlı bir artış göstermiş. İlk verinin karesi ve ilk verinin beşinci kuvveti. Burada biraz dışarıdan baktığımızda 15ms değerinin çok az olduğunu anlayabiliriz. 

Bu durum bizlere uzun ve fazla sayıda metriğe sahip verilerin sıralanması için “Radix Sort” algoritmasının ne kadar verimli olabileceğini gösteriyor. 

# 🏆 Radix Algoritmasının En İyi ve En Kötü Zaman Karmaşıkları Nedir?

Radix Sort Algoritmasının temel karmaşıklığı uzay karmaşıklığı Θ(d(n+b)) olarak kabul edilir. Bu durumda eleman sayısı(n), digit sayısı(d) ve basamak tabanı(b)’den oluşur.

En Kötü Zaman Karmaşıklığı : Θ(n^2)

En İyi Zaman Karmaşıklı: Θ(a*n)

Açıklamaları aşağıda bulunuyor.

# 😢 Radix Algoritmasının En İyi ve En Kötü Çalışma Zamanı Hangi Durumlarda Oluşur?

**En Kötü Durum Zaman Karmaşıklığı** 

“Tüm öğelerin biri dışında aynı sayıda basamağa sahip olmasıdır.” Bu durum ışığında oluşan basamak farkındaki değer n olarak kabul edilirse n^2 karmaşıklığına ulaşır.

**En İyi Durum Zaman Karmaşıklığı**

“Tüm öğeler aynı sayıda basamağa sahip olduğunda, en iyi durum senaryosu oluşur”. Yani tüm basamak sayıları eş ve düzeltme gerektirmeden atlama olmadan dönme durumu. Bu durumda b (taban), n (değer sayısına) eşitse direk olarak Θ(a*n) zaman karmaşıklığına ulaşır.

---

<aside>
📌 Kaynakça:
</aside>

Ders Notları

[Radix Sort - GeeksforGeeks](https://www.geeksforgeeks.org/radix-sort/)

 [Veri Yapısında Radix sıralama Algoritması: Genel Bakış, Zaman Karmaşıklığı ve Daha fazla | Basitleştirme (simplilearn.com)](https://www.simplilearn.com/tutorials/data-structure-tutorial/radix-sort#:~:text=Radix%20Sort%20is%20a%20linear,because%20it%20requires%20extra%20space.)

[Radix Sort Algorithm | Interview Cake](https://www.interviewcake.com/concept/java/radix-sort)

[Taban Sıralaması (Radix Sort) – Bilgisayar Kavramları (bilgisayarkavramlari.com)](https://bilgisayarkavramlari.com/2008/11/09/taban-siralamasi-radix-sort/)

[https://youtu.be/M1hABszC9gU](https://youtu.be/M1hABszC9gU)

[Radix Sort - Sıralama Algoritmaları - burakkose:blog (koseburak.net)](https://www.koseburak.net/blog/radix-sort/)

<aside>
📌 Hazırlayan: Kağan Can Şit  - 202802007 - Yazılım Mühendisliği
</aside>
