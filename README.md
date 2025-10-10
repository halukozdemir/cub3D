# 🎮 Cub3D

**Raycasting Engine** - Ecole42 projesi kapsamında geliştirilmiş, 3D grafik rendering ve oyun motoru teknolojilerini öğreten bir C projesi.

## 📖 Proje Hakkında / About the Project

Cub3D, klasik **Wolfenstein 3D** tarzında bir raycasting engine'dir. Bu proje, 2D haritalardan 3D perspektif görüntü oluşturma, texture mapping, sprite rendering ve oyun döngüsü gibi temel oyun geliştirme kavramlarını öğretir.

Cub3D is a raycasting engine in the style of classic **Wolfenstein 3D**. This project teaches fundamental game development concepts such as creating 3D perspective images from 2D maps, texture mapping, sprite rendering, and game loops.

### 🎯 Proje Amacı / Project Purpose

- **Raycasting Algoritması**: 2D haritadan 3D görüntü oluşturma
- **Texture Mapping**: Duvarlara texture uygulama
- **Sprite Rendering**: 2D sprite'ları 3D sahneye entegre etme
- **Oyun Döngüsü**: Gerçek zamanlı kullanıcı etkileşimi
- **Map Parsing**: .cub dosya formatından harita okuma

- **Raycasting Algorithm**: Creating 3D images from 2D maps
- **Texture Mapping**: Applying textures to walls
- **Sprite Rendering**: Integrating 2D sprites into 3D scenes
- **Game Loop**: Real-time user interaction
- **Map Parsing**: Reading maps from .cub file format

## 🏗️ Proje Yapısı / Project Structure

```
cub3D/
├── lib/                    # Kütüphaneler / Libraries
│   ├── cub3d.h            # Ana header dosyası / Main header file
│   ├── libft/             # 42 libft kütüphanesi / 42 libft library
│   └── gnl/               # Get Next Line kütüphanesi / Get Next Line library
├── src/                   # Kaynak kodlar / Source codes
│   ├── checker/           # Harita ve dosya doğrulama / Map and file validation
│   ├── cleanup/           # Bellek yönetimi / Memory management
│   ├── executor/          # Oyun döngüsü ve rendering / Game loop and rendering
│   ├── parser/            # Dosya parsing / File parsing
│   └── utils/             # Yardımcı fonksiyonlar / Helper functions
├── maps/                  # Örnek harita dosyaları / Example map files
├── textures/              # Texture dosyaları / Texture files
└── main.c                 # Ana program / Main program
```

## 🚀 Kullanım / Usage

### Derleme / Compilation
```bash
make
```

### Çalıştırma / Execution
```bash
./cub3D [map_file.cub]
```

### Örnek Kullanım / Example Usage
```bash
./cub3D maps/example.cub
```

## 🎮 Kontroller / Controls

| Tuş / Key | Açıklama / Description |
|-----------|----------------------|
| `W` | İleri git / Move forward |
| `S` | Geri git / Move backward |
| `A` | Sola dön / Turn left |
| `D` | Sağa dön / Turn right |
| `←` | Sola bak / Look left |
| `→` | Sağa bak / Look right |
| `ESC` | Çıkış / Exit |

## 📁 Map Format (.cub)

```cub
# Harita ayarları / Map settings
NO ./textures/north.xpm    # Kuzey duvar texture'ı / North wall texture
SO ./textures/south.xpm    # Güney duvar texture'ı / South wall texture
WE ./textures/west.xpm     # Batı duvar texture'ı / West wall texture
EA ./textures/east.xpm     # Doğu duvar texture'ı / East wall texture

F 220,100,0               # Zemin rengi (RGB) / Floor color (RGB)
C 225,30,0                 # Tavan rengi (RGB) / Ceiling color (RGB)

# Harita (1=duvar, 0=boş, N/S/E/W=oyuncu başlangıç pozisyonu)
# Map (1=wall, 0=empty, N/S/E/W=player starting position)
1111111111111111111111111
1000000000000000000000001
1000000000000000000000001
1000000000000000000000001
1000000000000000000000001
1111111111111111111111111
```

## 🔧 Teknik Özellikler / Technical Features

### Raycasting Algoritması / Raycasting Algorithm
- **DDA (Digital Differential Analyzer)**: Ray-marching algoritması / Ray-marching algorithm
- **Wall Detection**: Duvarların kesişim noktalarını bulma / Finding wall intersection points
- **Distance Calculation**: Kamera mesafesi hesaplama / Camera distance calculation
- **Texture Mapping**: UV koordinatları hesaplama / UV coordinate calculation

### Rendering Pipeline
1. **Ray Generation**: Her pixel için ray oluşturma / Creating rays for each pixel
2. **Intersection Testing**: Ray-harita kesişimi / Ray-map intersection
3. **Distance Calculation**: Mesafe hesaplama / Distance calculation
4. **Texture Sampling**: Texture'dan pixel alma / Sampling pixels from texture
5. **Screen Rendering**: Piksel çizme / Pixel drawing

### Memory Management
- **Dynamic Allocation**: Harita boyutuna göre bellek ayırma / Memory allocation based on map size
- **Texture Loading**: XPM dosyalarından texture yükleme / Loading textures from XPM files
- **Cleanup Functions**: Bellek sızıntısı önleme / Memory leak prevention

## 🎨 Görsel Özellikler / Visual Features

- ✅ **3D Perspective**: Gerçekçi 3D görünüm / Realistic 3D view
- ✅ **Texture Mapping**: Duvarlara texture uygulama / Applying textures to walls
- ✅ **Color Coding**: Zemin ve tavan renklendirme / Floor and ceiling coloring
- ✅ **Smooth Movement**: Akıcı hareket animasyonu / Smooth movement animation
- ✅ **Collision Detection**: Duvar çarpışma kontrolü / Wall collision detection

## 🔍 Test Senaryoları / Test Scenarios

```bash
# Temel test / Basic test
./cub3D maps/basic.cub

# Büyük harita testi / Large map test
./cub3D maps/large.cub

# Texture testi / Texture test
./cub3D maps/texture_test.cub
```

## 📊 Performans / Performance

- **FPS**: 60+ FPS (optimize edilmiş) / 60+ FPS (optimized)
- **Memory Usage**: Dinamik bellek yönetimi / Dynamic memory management
- **CPU Usage**: Efficient raycasting algoritması / Efficient raycasting algorithm
- **Rendering**: Real-time 3D rendering

## 🛠️ Geliştirme Ortamı / Development Environment

- **Dil / Language**: C
- **Kütüphaneler / Libraries**: mlx (MiniLibX), libft
- **Derleyici / Compiler**: gcc
- **Platform**: macOS/Linux
- **Graphics**: X11/OpenGL

## 📚 Öğrenilen Kavramlar / Learned Concepts

- **Computer Graphics**: 3D rendering temelleri / 3D rendering fundamentals
- **Raycasting**: 3D görüntü oluşturma / 3D image creation
- **Game Development**: Oyun döngüsü ve kontroller / Game loop and controls
- **File Parsing**: Dosya formatı işleme / File format processing
- **Memory Management**: Dinamik bellek yönetimi / Dynamic memory management
- **Mathematical Algorithms**: Trigonometri ve geometri / Trigonometry and geometry

## 🎯 Proje Hedefleri / Project Goals

Bu proje ile aşağıdaki konularda deneyim kazanılmıştır:

This project provides experience in the following areas:

1. **3D Graphics Programming**: Raycasting algoritması / Raycasting algorithm
2. **Game Engine Development**: Oyun motoru temelleri / Game engine fundamentals
3. **File Format Design**: .cub dosya formatı / .cub file format
4. **Real-time Rendering**: Gerçek zamanlı grafik / Real-time graphics
5. **User Input Handling**: Klavye kontrolleri / Keyboard controls
6. **Performance Optimization**: FPS optimizasyonu / FPS optimization

## 🔧 Geliştirme Notları / Development Notes

- **Raycasting**: DDA algoritması kullanılarak efficient ray-marching
- **Texture Mapping**: UV koordinatları ile texture sampling
- **Collision Detection**: Grid-based collision system
- **Memory Management**: Proper cleanup ve leak prevention
- **Error Handling**: Kapsamlı hata kontrolü / Comprehensive error control

## 📝 Lisans / License

Bu proje Ecole42 eğitim programı kapsamında geliştirilmiştir.

This project was developed within the scope of the Ecole42 education program.

## 👨‍💻 Geliştirici / Developer

**Haluk Özdemir**  
Ecole42 Istanbul - Graphics Programming

---

*Bu proje, 3D grafik programlama ve oyun geliştirme temellerini öğrenmek için tasarlanmıştır. Raycasting teknolojisini kullanarak 2D haritalardan 3D görüntü oluşturma sürecini modern C programlama teknikleri ile sunar.*

*This project is designed to learn 3D graphics programming and game development fundamentals. It presents the process of creating 3D images from 2D maps using raycasting technology with modern C programming techniques.*
