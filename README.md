# FDF - Fil de Fer (Wireframe 3D Renderer)

<div align="center">

![42 School Project](https://img.shields.io/badge/42-Project-blue)
![Language](https://img.shields.io/badge/Language-C-brightgreen)
![Graphics](https://img.shields.io/badge/Graphics-MiniLibX-orange)
![Grade](https://img.shields.io/badge/Grade-Passing-success)

</div>

<div align="center">
  <h3><a href="#-türkçe">🇹🇷 Türkçe</a> | <a href="#-english">🇬🇧 English</a></h3>
</div>

---

## 🇹🇷 Türkçe

### 📖 Proje Hakkında

FDF (Fil de Fer - Fransızca "tel kafes" anlamına gelir), 42 School'un grafik programlama projeleridendir. Bu proje, 3D harita verilerini izometrik projeksiyon kullanarak 2D ekranda wireframe (tel kafes) görselleştirmesi yapar.

Proje, MiniLibX grafik kütüphanesini kullanarak matematiksel transformasyonları ve çizgi çizim algoritmalarını uygulamanızı gerektirir.

### ✨ Özellikler

#### 🎯 Zorunlu Özellikler (Mandatory)
- ✅ `.fdf` uzantılı harita dosyalarını okuma
- ✅ İzometrik projeksiyon ile 3D görselleştirme
- ✅ Bresenham algoritması ile çizgi çizimi
- ✅ Z ekseni (yükseklik) desteği
- ✅ Renk interpolasyonu
- ✅ Hata yönetimi
- ✅ ESC tuşu ile programdan çıkış
- ✅ Pencere kapatma tuşu (X) ile çıkış

#### 🌟 Bonus Özellikler
- ✅ **Çoklu Projeksiyon**: İzometrik ve paralel projeksiyon arası geçiş
- ✅ **Rotasyon**: Haritayı Z ekseni etrafında döndürme
- ✅ **Yakınlaştırma/Uzaklaştırma**: Dinamik ölçeklendirme
- ✅ **Hareket**: Haritayı ekranda kaydırma
- ✅ **Video Modu**: `.fdfs` dosyaları ile animasyonlu görselleştirme
- ✅ **Renk Desteği**: Hex renk kodları ile özel renklendirme
- ✅ **Akıcı Animasyon**: Frame tabanlı yumuşak geçişler

### 🎮 Kontroller (Bonus)

| Tuş | İşlev |
|-----|-------|
| `ESC` | Programdan çık |
| `↑` `↓` `←` `→` | Haritayı hareket ettir |
| `+` / `-` | Yakınlaştır / Uzaklaştır |
| `R` / `T` | Z ekseni etrafında döndür |
| `P` | Projeksiyon değiştir (İzometrik ↔ Paralel) |
| `SPACE` | Animasyonu duraklat/devam ettir |

### 🛠️ Kurulum

#### Gereksinimler
- GCC veya Clang derleyici
- Make
- Git
- X11 kütüphaneleri (Linux)
- MiniLibX kütüphanesi (otomatik indirilecek)

#### Linux/WSL için Kurulum

```bash
# Depoyu klonlayın
git clone https://github.com/CilginSinek/fdf.git
cd fdf

# X11 geliştirme kütüphanelerini yükleyin (Ubuntu/Debian)
sudo apt-get update
sudo apt-get install libx11-dev libxext-dev

# Zorunlu versiyonu derleyin
make

# Veya bonus versiyonu derleyin
make bonus
```

### 🚀 Kullanım

#### Zorunlu Versiyon
```bash
./fdf maps/42.fdf
```

#### Bonus Versiyon - Statik Harita
```bash
./fdf_bonus maps/42.fdf
```

#### Bonus Versiyon - Animasyonlu Video
```bash
./fdf_bonus maps/output.fdfs
```

#### Projeksiyon Seçeneği ile Başlatma
```bash
./fdf_bonus maps/pyramide.fdf 1  # 1: İzometrik (varsayılan)
./fdf_bonus maps/mars.fdf 0      # 0: Paralel projeksiyon
```

### 📁 Dosya Formatı

#### `.fdf` Format - Statik Harita
```
0  0  0  0  0
0 10 10 10  0
0 10 20 10  0
0 10 10 10  0
0  0  0  0  0
```

#### Renkli Harita (Hex Renk Kodları)
```
0,0xFF0000  0,0x00FF00  0,0x0000FF
0,0xFFFF00 10,0xFF00FF 10,0x00FFFF
```

#### `.fdfs` Format - Video/Animasyon
Video formatı, birden fazla frame içeren dosyalardır. Her frame, `---` ayırıcısı ile ayrılır:
```
0  0  0
0 10  0
0  0  0
---
0  0  0
0 20  0
0  0  0
---
```

### 📚 Proje Yapısı

```
fdf/
├── mandatory/          # Zorunlu versiyon dosyaları
│   ├── main.c         # Ana program
│   ├── drawmap.c      # Çizim algoritmaları
│   ├── filehandler.c  # Dosya okuma
│   ├── utils.c        # Yardımcı fonksiyonlar
│   ├── exit_utils.c   # Bellek temizleme
│   └── fdf.h          # Ana header dosyası
├── bonus/             # Bonus versiyon dosyaları
│   ├── main_bonus.c           # Ana program (bonus)
│   ├── handlevision_bonus.c   # Görüntüleme yönetimi
│   ├── imagehandler_bonus.c   # İmaj işleme
│   ├── video_handle_bonus.c   # Video/animasyon
│   ├── key_utils.c            # Klavye kontrolleri
│   └── fdf_bonus.h            # Bonus header dosyası
├── libft/             # Özel C kütüphanesi
├── get_next_line/     # Dosya okuma fonksiyonu
├── maps/              # Örnek harita dosyaları
├── Makefile           # Derleme yapılandırması
└── README.md          # Bu dosya
```

### 🧮 Algoritma ve Matematik

#### İzometrik Projeksiyon
Projenin çekirdeğinde izometrik projeksiyon formülü bulunur:
```c
x' = (x - y) * cos(30°)
y' = (x + y) * sin(30°) - z
```

#### Çizgi Çizim Algoritması
Özel bir çizgi çizim algoritması kullanılır:
- Her noktadan sağa ve aşağıya doğru çizgiler çizer
- En sağ ve en aşağı noktalarda ek çizgi çizmez
- Grid tabanlı wireframe yapısı oluşturur
- Basit ve verimli piksel bazlı çizim

### 🎨 Renk Sistemi

- **Varsayılan Renk**: Beyaz (`0xFFFFFF`)
- **Hex Renk Desteği**: `0xRRGGBB` formatında
- **Renk Interpolasyonu**: İki nokta arasında yumuşak geçişler
- **Z-bazlı Renklendirme**: Yükseklik haritaları için otomatik gradyan

### 🧪 Test Haritaları

Proje ile birlikte gelen örnek haritalar:

| Dosya | Açıklama |
|-------|----------|
| `42.fdf` | 42 logosu |
| `pyramide.fdf` | Piramit yapısı |
| `mars.fdf` | Mars yüzey haritası |
| `julia.fdf` | Julia kümesi fraktalı |
| `elem-col.fdf` | Renkli öğeler |
| `output.fdfs` | Animasyonlu video örneği |

### 📏 Norminette Uyumluluğu

Proje, 42 School'un Norminette kurallarına uygun olarak yazılmıştır:
```bash
# Tüm kodu kontrol et
make norm

# Sadece mandatory'yi kontrol et
make normmandatory

# Sadece bonus'u kontrol et
make normbonus
```

### 🛑 Hata Yönetimi

Program aşağıdaki durumlarda düzgün şekilde hata mesajı verir:
- ❌ Geçersiz dosya formatı
- ❌ Dosya bulunamadı
- ❌ Bellek ayırma hatası
- ❌ MLX başlatma hatası
- ❌ Geçersiz harita verisi

### 🔧 Makefile Komutları

```bash
make          # Zorunlu versiyonu derle
make bonus    # Bonus versiyonu derle
make clean    # Object dosyalarını temizle
make fclean   # Tüm derleme çıktılarını temizle
make re       # Yeniden derle
make norm     # Norminette kontrolü yap
```

### 🐛 Sorun Giderme

#### MiniLibX Hataları
```bash
# X11 kütüphanelerini yükleyin
sudo apt-get install libx11-dev libxext-dev libbsd-dev

# MiniLibX'i manuel olarak derleyin
cd minilibx-linux
make
```

#### Bellek Sızıntıları Kontrolü
```bash
valgrind --leak-check=full --show-leak-kinds=all ./fdf maps/42.fdf
```

### 🤝 Katkıda Bulunma

1. Fork yapın
2. Feature branch oluşturun (`git checkout -b feature/amazing-feature`)
3. Değişikliklerinizi commit edin (`git commit -m 'Add some amazing feature'`)
4. Branch'inizi push edin (`git push origin feature/amazing-feature`)
5. Pull Request açın

### 📄 Lisans

Bu proje 42 School müfredatının bir parçasıdır ve eğitim amaçlıdır.

### 👨‍💻 Yazar

**iduman** - [@CilginSinek](https://github.com/CilginSinek)

### 🙏 Teşekkürler

- 42 Istanbul
- MiniLibX geliştiricileri
- 42 topluluğu

### 🔗 İlgili Projeler

- **[FDF Video Maker](https://github.com/CilginSinek/fdf_videomaker)** - FDF için `.fdfs` animasyon dosyaları oluşturmak için Python aracı

---

## 🇬🇧 English

### 📖 About the Project

FDF (Fil de Fer - French for "wireframe") is a 42 School graphics programming project. This project visualizes 3D map data on a 2D screen using isometric projection in a wireframe format.

The project requires implementing mathematical transformations and line drawing algorithms using the MiniLibX graphics library.

### ✨ Features

#### 🎯 Mandatory Features
- ✅ Read map files with `.fdf` extension
- ✅ 3D visualization with isometric projection
- ✅ Line drawing using Bresenham's algorithm
- ✅ Z-axis (height) support
- ✅ Color interpolation
- ✅ Error handling
- ✅ Exit with ESC key
- ✅ Exit with window close button (X)

#### 🌟 Bonus Features
- ✅ **Multiple Projections**: Switch between isometric and parallel projection
- ✅ **Rotation**: Rotate the map around Z-axis
- ✅ **Zoom In/Out**: Dynamic scaling
- ✅ **Translation**: Move the map on screen
- ✅ **Video Mode**: Animated visualization with `.fdfs` files
- ✅ **Color Support**: Custom coloring with hex color codes
- ✅ **Smooth Animation**: Frame-based smooth transitions

### 🎮 Controls (Bonus)

| Key | Function |
|-----|----------|
| `ESC` | Exit program |
| `↑` `↓` `←` `→` | Move the map |
| `+` / `-` | Zoom in / Zoom out |
| `R` / `T` | Rotate around Z-axis |
| `P` | Change projection (Isometric ↔ Parallel) |
| `SPACE` | Pause/Resume animation |

### 🛠️ Installation

#### Requirements
- GCC or Clang compiler
- Make
- Git
- X11 libraries (Linux)
- MiniLibX library (will be downloaded automatically)

#### Installation for Linux/WSL

```bash
# Clone the repository
git clone https://github.com/CilginSinek/fdf.git
cd fdf

# Install X11 development libraries (Ubuntu/Debian)
sudo apt-get update
sudo apt-get install libx11-dev libxext-dev

# Compile mandatory version
make

# Or compile bonus version
make bonus
```

### 🚀 Usage

#### Mandatory Version
```bash
./fdf maps/42.fdf
```

#### Bonus Version - Static Map
```bash
./fdf_bonus maps/42.fdf
```

#### Bonus Version - Animated Video
```bash
./fdf_bonus maps/output.fdfs
```

#### Launch with Projection Option
```bash
./fdf_bonus maps/pyramide.fdf 1  # 1: Isometric (default)
./fdf_bonus maps/mars.fdf 0      # 0: Parallel projection
```

### 📁 File Format

#### `.fdf` Format - Static Map
```
0  0  0  0  0
0 10 10 10  0
0 10 20 10  0
0 10 10 10  0
0  0  0  0  0
```

#### Colored Map (Hex Color Codes)
```
0,0xFF0000  0,0x00FF00  0,0x0000FF
0,0xFFFF00 10,0xFF00FF 10,0x00FFFF
```

#### `.fdfs` Format - Video/Animation
Video format contains multiple frames separated by `---`:
```
0  0  0
0 10  0
0  0  0
---
0  0  0
0 20  0
0  0  0
---
```

### 📚 Project Structure

```
fdf/
├── mandatory/          # Mandatory version files
│   ├── main.c         # Main program
│   ├── drawmap.c      # Drawing algorithms
│   ├── filehandler.c  # File reading
│   ├── utils.c        # Utility functions
│   ├── exit_utils.c   # Memory cleanup
│   └── fdf.h          # Main header file
├── bonus/             # Bonus version files
│   ├── main_bonus.c           # Main program (bonus)
│   ├── handlevision_bonus.c   # Vision management
│   ├── imagehandler_bonus.c   # Image processing
│   ├── video_handle_bonus.c   # Video/animation
│   ├── key_utils.c            # Keyboard controls
│   └── fdf_bonus.h            # Bonus header file
├── libft/             # Custom C library
├── get_next_line/     # File reading function
├── maps/              # Sample map files
├── Makefile           # Build configuration
└── README.md          # This file
```

### 🧮 Algorithms and Mathematics

#### Isometric Projection
The core of the project uses isometric projection formula:
```c
x' = (x - y) * cos(30°)
y' = (x + y) * sin(30°) - z
```

#### Line Drawing Algorithm
A custom line drawing algorithm is used:
- Draws lines to the right and downward from each point
- No additional lines are drawn at rightmost and bottommost points
- Creates a grid-based wireframe structure
- Simple and efficient pixel-based drawing

### 🎨 Color System

- **Default Color**: White (`0xFFFFFF`)
- **Hex Color Support**: In `0xRRGGBB` format
- **Color Interpolation**: Smooth transitions between two points
- **Z-based Coloring**: Automatic gradient for height maps

### 🧪 Test Maps

Sample maps included with the project:

| File | Description |
|------|-------------|
| `42.fdf` | 42 logo |
| `pyramide.fdf` | Pyramid structure |
| `mars.fdf` | Mars surface map |
| `julia.fdf` | Julia set fractal |
| `elem-col.fdf` | Colored elements |
| `output.fdfs` | Animated video example |

### 📏 Norminette Compliance

The project is written in compliance with 42 School's Norminette rules:
```bash
# Check all code
make norm

# Check only mandatory
make normmandatory

# Check only bonus
make normbonus
```

### 🛑 Error Handling

The program properly handles errors in the following cases:
- ❌ Invalid file format
- ❌ File not found
- ❌ Memory allocation failure
- ❌ MLX initialization failure
- ❌ Invalid map data

### 🔧 Makefile Commands

```bash
make          # Compile mandatory version
make bonus    # Compile bonus version
make clean    # Clean object files
make fclean   # Clean all build outputs
make re       # Recompile
make norm     # Run Norminette check
```

### 🐛 Troubleshooting

#### MiniLibX Errors
```bash
# Install X11 libraries
sudo apt-get install libx11-dev libxext-dev libbsd-dev

# Manually compile MiniLibX
cd minilibx-linux
make
```

#### Memory Leak Check
```bash
valgrind --leak-check=full --show-leak-kinds=all ./fdf maps/42.fdf
```

### 🤝 Contributing

1. Fork it
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### 📄 License

This project is part of the 42 School curriculum and is for educational purposes.

### 👨‍💻 Author

**iduman** - [@CilginSinek](https://github.com/CilginSinek)

### 🙏 Acknowledgments

- 42 Istanbul
- MiniLibX developers
- 42 community

### 🔗 Related Projects

- **[FDF Video Maker](https://github.com/CilginSinek/fdf_videomaker)** - Python tool to create `.fdfs` animation files for FDF

---

<div align="center">
  <p>Made with ❤️ at 42 Istanbul</p>
  <p>⭐ Star this repo if you found it helpful!</p>
</div>
