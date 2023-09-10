# So_Long

## Projede Ne Yapmamız Gerekiyor

- Projede bize 42 ye ait özel yapılandırılmış bir minilibx kütüphanesi eklenmiş ve bunu kullanarak bizden 2D bir oyun yapmamız isteniyor.

## Projenin İşleyişi

- Projede bir karakterimiz bulunuyor ve player anlamına gelen P ile simgeleniyor. Bu karakterle toplanabilir eşyaların hepsini toplayıp çıkışa ulaşılması gerekiyor. Burada toplanabilir eşyalar Collectable anlamına gelen C ile, çıkış ise exit anlamına gelen E ile simgelenmektedir. Bunun dışında duvarlar 1 ve oyuncunun yürüyebileceği boşluklar 0 ile simgelenmektedir.

## Projenin Zorlayıcı Kısımları

- Projede kullanılacak olan minilibx daha önce hiç görmediğimiz bir kütüphane ve bir kaynak. Bu yüzden tüm fonksiyonları araştırıp aralarından işimize yaraycak olanları kullanacak olmamız.

- Projede dosya ve klasör kısıtlaması olmasa da her dosyada kullanılacak maksimum fonksiyon sayısının 5 olması, her fonksiyonun maksimum 5 parametre alabilmesi ve her fonksiyonun maksimum 25 satır olmasıdır. Bu sayede daha clean bir kodun ortaya çıkarılması hedeflenmektedir.

## Projenin hata kontrolleri

- İlk hata kontrolü haritanın var olup olmama durumunu kontrol eder. Dosya olarak bulunup açılabiliyorsa bu harita vardır.

- Harita dosyaları .ber uzantısında olmalıdır ve .ber uzantısında olmayan hiçbir harita açılmayıp hata vermelidir. Tabiki direkt olarak adı .ber olan bir dosya var ise burada da uzantısı olmadığı için bu dosyanın da kullanılmaması gerekmektedir.

- Haritanın çevresinin duvarlar ile çevrili olup olmadığı kontrol edilmelidir. Aksi takdirde oyuncu haritanın dışına çıkabilir. Bu yüzden de bu durumda oyunun başlatılamayıp hata vermesi gerekiyor.

- Haritada oyunun oynanabilmesi için bir oyuncu, bir çıkış ve en az bir toplanabilir eşya olması gerekmektedir. Bunlardan herhangi birisi eksikse oyun hatalı çalışacağından oyun çalıştırılmadan hata vermesi gerekiyor.