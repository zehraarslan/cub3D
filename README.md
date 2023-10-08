# cub3D Projesi
Cub3D, birinci şahıs perspektifinden bir labirenti gezmenizi sağlayan bir grafik tasarım projesidir. Bu proje, meşhur video oyunu Wolfenstein 3D'nin basitleştirilmiş bir versiyonu olarak düşünülebilir. Projede, Ray-Casting teknikleri kullanılarak 3 boyutlu bir görüntü oluşturulur.

# Kurulum
Projeyi yerel makinenize klonlamak için aşağıdaki komutu kullanabilirsiniz: git clone https://github.com/zehraarslan/cub3D.git

# Kullanım
Projeyi derlemek ve çalıştırmak için aşağıdaki komutları kullanabilirsiniz:
  - make
  - ./cub3D map.cub

# Özellikler
- Projede bir labirent, farklı duvar dokuları ve bir sprite (nesne) kullanılmıştır.
- Kullanıcı, labirent içerisinde 'W', 'A', 'S', 'D' tuşları ile hareket edebilir ve sağ/sol yön tuşları ile görüş açısını değiştirebilir.
- Labirentin duvarları farklı dokulara sahip olabilir ve bu dokular, bir .cub dosyası ile tanımlanır.
- Projede, çarpışma algılama özelliği bulunmaktadır. Bu sayede, kullanıcı duvarlara çarpmaz.
- Ray-Casting tekniği kullanılarak 3D görüntü oluşturulur.

# Yapılandırma
- Oyunun ayarları ve harita, .cub dosyası içerisinde tanımlanır.
- .cub dosyası, oyunun başlangıç ayarlarını, duvar dokularını, sprite'ı, tavan ve zemin renklerini ve oyun haritasını içerir.
